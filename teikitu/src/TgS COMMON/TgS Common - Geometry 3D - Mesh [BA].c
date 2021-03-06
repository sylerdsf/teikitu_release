/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Mesh [BA].c_inc
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.17 / »GUID« 3ED3C595-046B-47FB-8785-5C167178CD24 */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if defined (TGS_COMMON_GEOMETRY_H)

#if !defined (ENABLE_RELOAD_GUARD)
    #define TEMPLATE__VECTOR_DIM 4
    #define ENABLE_RELOAD_GUARD
    #if !defined(TEMPLATE__TYPE_SIZE)
        #if TgCOMPILE__NON_NATIVE_VECTOR_AS_NATIVE
            #define TEMPLATE__TYPE_SIZE 64
            #include __FILE__
            #undef TEMPLATE__TYPE_SIZE
        #endif
        #define TEMPLATE__TYPE_SIZE 32
    #endif
    #undef ENABLE_RELOAD_GUARD
#endif

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/* == Common ===================================================================================================================================================================== */

/* ---- FCN_VO(tgGM_MA_Is_Valid) ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_MA_Is_Valid)( VEC_OBJ_T(TgMESH_BA,CPCU) psMA1 )
{
    TgRSIZE_C       nuiFace = psMA1->m_nuiFace;

    if (!FCN_VO(tgGM_MS_Is_Valid)( &psMA1->m_sMS ))
    {
        return (false);
    };

    if (ETgSWEEP_ROTATIONAL == psMA1->m_enSweep || ETgSWEEP_LINEAR == psMA1->m_enSweep)
    {
        if (ETgSWEEP_ROTATIONAL == psMA1->m_enSweep)
        {
            if ((nullptr == psMA1->m_pvVert_DT) || (nullptr == psMA1->m_psBA) || (nullptr == psMA1->m_puiFlags))
            {
                return (false);
            };

            if (!FCN_V(tgMH_Is_Valid_Point)( psMA1->m_vCG[0] ) )
            {
                return (false);
            };

            if (!FCN_V(tgMH_Is_Valid_Point)( psMA1->m_vCG[1] ))
            {
                return (false);
            };

            for (TgRSIZE uiIndex = 0; uiIndex < psMA1->m_sMS.m_nuiVert; ++uiIndex)
            {
                if (!FCN_V(tgMH_Is_Valid_Vector)( psMA1->m_pvVert_DT[uiIndex] ))
                {
                    return (false);
                };
            };
        }
        else if (ETgSWEEP_LINEAR == psMA1->m_enSweep)
        {
            if ((nullptr != psMA1->m_pvVert_DT) || !FCN_VO(tgGM_DT_Is_Valid)( &psMA1->m_sDT ) )
            {
                return (false);
            };

            if ((nullptr == psMA1->m_psBA) || (nullptr == psMA1->m_puiFlags))
            {
                return (false);
            };

            if (!FCN_VO(tgGM_DT_Is_Valid)( &psMA1->m_sDT ))
            {
                return (false);
            };
        };

        for (TgRSIZE uiIndex = 0; uiIndex < nuiFace; ++uiIndex)
        {
            if (!FCN_VO(tgGM_BA_Is_Valid)( psMA1->m_psBA + uiIndex ) )
            {
                return (false);
            };
        };
    }
    else
    {
        if (nullptr != psMA1->m_pvVert_DT)
        {
            return (false);
        };
    };

    return (true);
}


/* ---- FCN_VO(tgGM_MA_TX) ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FCN_VO(tgGM_MA_TX)( VEC_OBJ_T(TgMESH_BA,PCU) psMA0, VEC_T(3,CPCU) pmM0 )
{
    FCN_VO(tgGM_MS_TX)( &psMA0->m_sMS, pmM0 );

    psMA0->m_vCG[0] = FCN_V(tgMH_TX_P,3)( psMA0->m_vCG[0], pmM0 );

    if (ETgSWEEP_ROTATIONAL == psMA0->m_enSweep)
    {
        TgERROR((nullptr != psMA0->m_psBA) && (nullptr != psMA0->m_puiFlags));

        for (TgRSIZE uiIndex = 0; uiIndex < psMA0->m_sMS.m_nuiVert; ++uiIndex)
        {
            psMA0->m_pvVert_DT[uiIndex] = FCN_V(tgMH_TX_V,3)( psMA0->m_pvVert_DT[uiIndex], pmM0);
        };

        psMA0->m_vCG[1] = FCN_V(tgMH_TX_P,3)( psMA0->m_vCG[1], pmM0 );

        FCN_VO(tgGM_MA_Update_Face_BA)( psMA0 );
    }
    else if (ETgSWEEP_LINEAR == psMA0->m_enSweep)
    {
        FCN_VO(tgGM_DT_TX)( &psMA0->m_sDT, pmM0 );

        psMA0->m_vCG[1] = FCN_V(tgMH_TX_P,3)( psMA0->m_vCG[1], pmM0 );

        FCN_VO(tgGM_MA_Update_Face_BA)( psMA0 );
    };
}


/* ---- FCN_VO(tgGM_MA_Copy_TX) -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FCN_VO(tgGM_MA_Copy_TX)( VEC_OBJ_T(TgMESH_BA,PCU) psMA0, VEC_OBJ_T(TgMESH_BA,CPCU) psMA1, VEC_T(3,CPCU) pmM0 )
{
    TgRSIZE_C       nuiVert = psMA1->m_sMS.m_nuiVert;
    TgRSIZE_C       nuiIndx = psMA1->m_sMS.m_nuiIndx;
    TgRSIZE_C       nuiFace = psMA1->m_nuiFace;

    FCN_VO(tgGM_MA_Init)( psMA0, nuiVert, nuiIndx, psMA1->m_enSweep );
    FCN_VO(tgGM_MS_Copy_TX)( &psMA0->m_sMS, &psMA1->m_sMS, pmM0 );

    psMA0->m_vCG[0] = FCN_V(tgMH_TX_P,3)( psMA1->m_vCG[0], pmM0 );

    if (ETgSWEEP_ROTATIONAL == psMA1->m_enSweep)
    {
        TgERROR((nullptr != psMA1->m_psBA) && (nullptr != psMA1->m_puiFlags));

        for (TgRSIZE uiIndex = 0; uiIndex < psMA1->m_sMS.m_nuiVert; ++uiIndex)
        {
            psMA0->m_pvVert_DT[uiIndex] = FCN_V(tgMH_TX_V,3)( psMA1->m_pvVert_DT[uiIndex], pmM0 );
        };

        psMA0->m_vCG[1] = FCN_V(tgMH_TX_P,3)( psMA1->m_vCG[1], pmM0 );

        FCN_VO(tgGM_MA_Update_Face_BA)( psMA0 );
    }
    else if (ETgSWEEP_LINEAR == psMA1->m_enSweep)
    {
        FCN_VO(tgGM_DT_Copy_TX)( &psMA0->m_sDT, &psMA1->m_sDT, pmM0 );

        psMA0->m_vCG[1] = FCN_V(tgMH_TX_P,3)( psMA1->m_vCG[1], pmM0 );

        FCN_VO(tgGM_MA_Update_Face_BA)( psMA0 );
    };

    tgMM_Copy( psMA0->m_puiFlags, nuiFace*sizeof( psMA0->m_puiFlags[0] ), psMA1->m_puiFlags, nuiFace*sizeof( psMA1->m_puiFlags[0] ) );

    psMA0->m_enSweep = psMA1->m_enSweep;
}


/* ---- FCN_VO(tgGM_MA_Init) ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FCN_VO(tgGM_MA_Init)( VEC_OBJ_T(TgMESH_BA,PCU) psMA0, TgRSIZE_C nuiVert, TgRSIZE_C nuiIndx, ETgSWEEP_TYPE_C enSweep )
{
    TgRSIZE_C       nuiVert_Old = psMA0->m_sMS.m_nuiVert;
    TgRSIZE_C       nuiIndx_Old = psMA0->m_sMS.m_nuiIndx;
    TgRSIZE_C       nuiFace_Old = (0 == psMA0->m_sMS.m_puiIndx_List ? nuiVert_Old : nuiIndx_Old) / 3;
    TgRSIZE_C       nuiFace = (0 == nuiIndx ? nuiVert : nuiIndx) / 3;

    TgERROR(nuiVert < KTgMAX_U32);
    TgERROR(nuiIndx < KTgMAX_U32);

    FCN_VO(tgGM_MS_Init)( &psMA0->m_sMS, nuiVert, nuiIndx );

    if ((nuiFace_Old == nuiFace) && (enSweep == psMA0->m_enSweep))
    {
        return;
    };

    FCN_VO(tgGM_MA_Free_Internal)( psMA0 );

    psMA0->m_enSweep = enSweep;
    psMA0->m_nuiFace = (TgUINT_E32)nuiFace;

    if (0 == nuiFace)
    {
        return;
    };

    switch (psMA0->m_enSweep)
    {
        case ETgSWEEP_ROTATIONAL:
            psMA0->m_pvVert_DT = (VEC_T(1,P))(TgMALLOC_POOL( nuiFace*sizeof( VEC_T(1) ) ));
        case ETgSWEEP_LINEAR:
        case ETgSWEEP_STATIC:
            psMA0->m_psBA = (VEC_OBJ_T(TgBOXAA,P))(TgMALLOC_POOL( nuiFace*sizeof( VEC_OBJ_T(TgBOXAA) ) ));
            psMA0->m_puiFlags = (TgUINT_F32_P)(TgMALLOC_POOL( nuiFace*sizeof( TgUINT_F32  ) ));
            break;
    };
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
