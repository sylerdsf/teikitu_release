/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Mesh [Utility].c_inc
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

#if !defined(ENABLE_RELOAD_GUARD_FILE)

    #define ENABLE_RELOAD_GUARD_FILE

    #define FI(A) FCN_VO(A##_VL)
    #include __FILE__
    #undef FI

    #define FI(A) FCN_VO(A##_IL)
    #include __FILE__
    #undef FI

#else

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

/* ---- FI(tgGM_Volume_MS) ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
VAR_T() FI(tgGM_Volume_MS)( VEC_OBJ_T(TgMESH_SIMPLE,CPCU) psMS1 )
{
    VAR_T()                             fVolume = TYPE_K(0);
    TgMESH_ITER                         itMS;

    FI(tgGM_Iterator_Init_MS)( &itMS, psMS1 );

    for (TgRSIZE uiIndex = 0; uiIndex < itMS.m_nuiFace; ++uiIndex)
    {
        VAR_T()                             fTriD, fDA, fDB, fAA, fBB, fC1, fCA, fCB, fP1, fPA, fPB;
        TgSINT_F32                          i0, i1, i2;

        VEC_UN_T(1,C)   uS0 = { psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )] };
        VEC_UN_T(1,C)   uS1 = { psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )] };
        VEC_UN_T(1,C)   uS2 = { psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )] };

        VEC_UN_T(1,C)   uE0 = { FCN_V(tgMH_SUB)( VEC_UN_1_MEMBER(uS1), VEC_UN_1_MEMBER(uS0) ) };
        VEC_UN_T(1,C)   uE2 = { FCN_V(tgMH_SUB)( VEC_UN_1_MEMBER(uS2), VEC_UN_1_MEMBER(uS0) ) };

        VEC_UN_T(1,C)   uN0 = { FCN_V(tgMH_CX)( VEC_UN_1_MEMBER(uE0), VEC_UN_1_MEMBER(uE2) ) };

        fTriD = VEC_S_UN_1_MEMBER(uN0).x*VEC_S_UN_1_MEMBER(uS0).x + VEC_S_UN_1_MEMBER(uN0).y*VEC_S_UN_1_MEMBER(uS0).y + VEC_S_UN_1_MEMBER(uN0).z*VEC_S_UN_1_MEMBER(uS0).z;

        if (VEC_S_UN_1_MEMBER(uN0).x > VEC_S_UN_1_MEMBER(uN0).y && VEC_S_UN_1_MEMBER(uN0).x > VEC_S_UN_1_MEMBER(uN0).z)
        {
            i2 = 0;
        }
        else
        {
            i2 = (VEC_S_UN_1_MEMBER(uN0).y > VEC_S_UN_1_MEMBER(uN0).z) ? 1 : 2;
        };

        i0 = (i2 + 1) % 3;
        i1 = (i2 + 2) % 3;

        fDA = VEC_S_UN_1_MEMBER(uS1).x - VEC_S_UN_1_MEMBER(uS0).x;
        fDB = VEC_S_UN_1_MEMBER(uS1).y - VEC_S_UN_1_MEMBER(uS0).y;
        fAA = VEC_S_UN_1_MEMBER(uS0).x * VEC_S_UN_1_MEMBER(uS0).x;
        fBB = VEC_S_UN_1_MEMBER(uS0).y * VEC_S_UN_1_MEMBER(uS0).y;

        fC1 = VEC_S_UN_1_MEMBER(uS1).x + VEC_S_UN_1_MEMBER(uS0).x;
        fCA = VEC_S_UN_1_MEMBER(uS1).x * fC1 + fAA;
        fCB = VEC_S_UN_1_MEMBER(uS1).y * (VEC_S_UN_1_MEMBER(uS1).y + VEC_S_UN_1_MEMBER(uS0).y) + fBB;

        fP1 = fDB * fC1;
        fPA = fDB * fCA;
        fPB = fDA * fCB;

        fDA = VEC_S_UN_1_MEMBER(uS2).x - VEC_S_UN_1_MEMBER(uS1).x;
        fDB = VEC_S_UN_1_MEMBER(uS2).y - VEC_S_UN_1_MEMBER(uS1).y;
        fAA = VEC_S_UN_1_MEMBER(uS1).x * VEC_S_UN_1_MEMBER(uS1).x;
        fBB = VEC_S_UN_1_MEMBER(uS1).y * VEC_S_UN_1_MEMBER(uS1).y;

        fC1 = VEC_S_UN_1_MEMBER(uS2).x + VEC_S_UN_1_MEMBER(uS1).x;
        fCA = VEC_S_UN_1_MEMBER(uS2).x * fC1 + fAA;
        fCB = VEC_S_UN_1_MEMBER(uS2).y * (VEC_S_UN_1_MEMBER(uS2).y + VEC_S_UN_1_MEMBER(uS1).y) + fBB;

        fP1 += fDB * fC1;
        fPA += fDB * fCA;
        fPB += fDA * fCB;

        fDA = VEC_S_UN_1_MEMBER(uS0).x - VEC_S_UN_1_MEMBER(uS2).x;
        fDB = VEC_S_UN_1_MEMBER(uS0).y - VEC_S_UN_1_MEMBER(uS2).y;
        fAA = VEC_S_UN_1_MEMBER(uS2).x * VEC_S_UN_1_MEMBER(uS2).x;
        fBB = VEC_S_UN_1_MEMBER(uS2).y * VEC_S_UN_1_MEMBER(uS2).y;

        fC1 = VEC_S_UN_1_MEMBER(uS0).x + VEC_S_UN_1_MEMBER(uS2).x;
        fCA = VEC_S_UN_1_MEMBER(uS0).x * fC1 + fAA;
        fCB = VEC_S_UN_1_MEMBER(uS0).y * (VEC_S_UN_1_MEMBER(uS0).y + VEC_S_UN_1_MEMBER(uS2).y) + fBB;

        fP1 += fDB * fC1;
        fPA += fDB * fCA;
        fPB += fDA * fCB;

        fP1 /= TYPE_K(2,0);
        fPA /= TYPE_K(6,0);
        fPB /= TYPE_K(-6,0);

        if (i0 == 0) /* 0,1,2 */
        {
            fVolume += VEC_S_UN_1_MEMBER(uN0).x * fPA / VEC_S_UN_1_MEMBER(uN0).z;
        }
        else if (i1 == 0) /* 2,0,1 */
        {
            fVolume += VEC_S_UN_1_MEMBER(uN0).z * fPB / VEC_S_UN_1_MEMBER(uN0).y;
        }
        else /* 1,2,0 */
        {
            fVolume += (VEC_S_UN_1_MEMBER(uN0).y / -(VEC_S_UN_1_MEMBER(uN0).x * VEC_S_UN_1_MEMBER(uN0).x)) * (VEC_S_UN_1_MEMBER(uN0).y * fPA + VEC_S_UN_1_MEMBER(uN0).z * fPB - fTriD * fP1);
        };
    };

    return (fVolume);
}


/* ---- FI(tgGM_Area_MS) --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
VAR_T() FI(tgGM_Area_MS)( VEC_OBJ_T(TgMESH_SIMPLE,CPCU ) psMS1)
{
    VAR_T()                             fArea = TYPE_K(0);
    TgMESH_ITER                         itMS;
    TgUINT_F32                          uiIndex;

    FI(tgGM_Iterator_Init_MS)( &itMS, psMS1 );

    for (uiIndex = 0; uiIndex < itMS.m_nuiFace; ++uiIndex)
    {
        VEC_T(1,C)      vS0 = psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )];
        VEC_T(1,C)      vS1 = psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )];
        VEC_T(1,C)      vS2 = psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )];
        VEC_T(1,C)      vE0 = FCN_V(tgMH_SUB)( vS1, vS0 );
        VEC_T(1,C)      vE2 = FCN_V(tgMH_SUB)( vS2, vS0 );
        VEC_T(1,C)      vNM = FCN_V(tgMH_CX)( vE0, vE2 );
        VEC_UN_T(1,C)   uX0 = { FCN_V(tgMH_LEN)( vNM ) };

        fArea += TYPE_K(0,5)*VEC_S_UN_1_MEMBER(uX0).x;
    };

    return (fArea);
}


/* ---- FI(tgGM_Is_Contained_MS) ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FI(tgGM_Is_Contained_MS)( VEC_OBJ_T(TgMESH_SIMPLE,CPCU ) psMS1, VEC_T(1,C) vS3)
{
    TgMESH_ITER                         itMS;
    TgUINT_F32                          uiIndex;

    FI(tgGM_Iterator_Init_MS)( &itMS, psMS1 );

    for (uiIndex = 0; uiIndex < itMS.m_nuiFace; ++uiIndex)
    {
        VEC_T(1,C)      vS0 = psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )];
        VEC_T(1,C)      vS1 = psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )];
        VEC_T(1,C)      vS2 = psMS1->m_pvVert_List[FI(tgGM_Iterator_Incr_MS)( &itMS, psMS1 )];
        VEC_T(1,C)      vE0 = FCN_V(tgMH_SUB)( vS1, vS0 );
        VEC_T(1,C)      vE2 = FCN_V(tgMH_SUB)( vS2, vS0 );
        VEC_T(1,C)      vNM = FCN_V(tgMH_CX)( vE0, vE2 );
        VEC_T(1,C)      vX0 = FCN_V(tgMH_SUB)( vS3, vS0 );
        VEC_UN_T(1,C)   uX0 = { FCN_V(tgMH_DOT3)( vNM, vX0 ) };

        if (TYPE_K(0) >= VEC_S_UN_1_MEMBER(uX0).x)
        {
            return (false);
        };
    };

    return (true);
}


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions - Mesh BA */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- FI(tgGM_MA_Update_Face_BA) ----------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FI(tgGM_MA_Update_Face_BA)(VEC_OBJ_T(TgMESH_BA,PCU) psMA0)
{
    TgMESH_ITER                         itMS;
    TgUINT_F32                          uiFace;

    FI(tgGM_Iterator_Init_MS)( &itMS, &psMA0->m_sMS );

    psMA0->m_vCG[0] = FCN_V(tgMH_SET1)( TYPE_K(0) );
    psMA0->m_vCG[1] = FCN_V(tgMH_SET1)( TYPE_K(0) );

    if (ETgSWEEP_ROTATIONAL == psMA0->m_enSweep)
    {
        for (uiFace = 0; uiFace < itMS.m_nuiFace; ++uiFace)
        {
            TgUINT_F32_C    uiI0 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI1 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI2 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );

            VEC_T(1,C)      vX0 = psMA0->m_sMS.m_pvVert_List[uiI0];
            VEC_T(1,C)      vX1 = psMA0->m_sMS.m_pvVert_List[uiI1];
            VEC_T(1,C)      vX2 = psMA0->m_sMS.m_pvVert_List[uiI2];

            VEC_T(1,C)      vX3 = FCN_V(tgMH_ADD)( vX0, psMA0->m_pvVert_DT[uiI0] );
            VEC_T(1,C)      vX4 = FCN_V(tgMH_ADD)( vX1, psMA0->m_pvVert_DT[uiI1] );
            VEC_T(1,C)      vX5 = FCN_V(tgMH_ADD)( vX2, psMA0->m_pvVert_DT[uiI2] );

            FCN_VO(tgGM_BA_Init_PT)( psMA0->m_psBA + uiFace, vX0 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX1 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX2 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX3 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX4 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX5 );
        };
    }
    else if (ETgSWEEP_LINEAR == psMA0->m_enSweep)
    {
        for (uiFace = 0; uiFace < itMS.m_nuiFace; ++uiFace)
        {
            TgUINT_F32_C    uiI0 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI1 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI2 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );

            VEC_T(1,C)      vX0 = psMA0->m_sMS.m_pvVert_List[uiI0];
            VEC_T(1,C)      vX1 = psMA0->m_sMS.m_pvVert_List[uiI1];
            VEC_T(1,C)      vX2 = psMA0->m_sMS.m_pvVert_List[uiI2];

            FCN_VO(tgGM_BA_Init_PT)( psMA0->m_psBA + uiFace, vX0 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX1 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX2 );
            FCN_VO(tgGM_BA_Sweep)( psMA0->m_psBA + uiFace, psMA0->m_sDT.m_vDT );
        };
    }
    else if (ETgSWEEP_STATIC == psMA0->m_enSweep)
    {
        for (uiFace = 0; uiFace < itMS.m_nuiFace; ++uiFace)
        {
            TgUINT_F32_C    uiI0 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI1 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI2 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );

            VEC_T(1,C)      vX0 = psMA0->m_sMS.m_pvVert_List[uiI0];
            VEC_T(1,C)      vX1 = psMA0->m_sMS.m_pvVert_List[uiI1];
            VEC_T(1,C)      vX2 = psMA0->m_sMS.m_pvVert_List[uiI2];

            FCN_VO(tgGM_BA_Init_PT)( psMA0->m_psBA + uiFace, vX0 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX1 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX2 );
        };
    };
}


/* ---- FI(tgGM_MA_Update_Face_CG_BA) -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FI(tgGM_MA_Update_Face_CG_BA)(VEC_OBJ_T(TgMESH_BA,PCU) psMA0)
{
    TgMESH_ITER                         itMS;
    TgUINT_F32                          uiFace;

    FI(tgGM_Iterator_Init_MS)( &itMS, &psMA0->m_sMS );

    psMA0->m_vCG[0] = FCN_V(tgMH_SET1)( TYPE_K(0) );
    psMA0->m_vCG[1] = FCN_V(tgMH_SET1)( TYPE_K(0) );

    if (ETgSWEEP_ROTATIONAL == psMA0->m_enSweep)
    {
        for (uiFace = 0; uiFace < itMS.m_nuiFace; ++uiFace)
        {
            TgUINT_F32_C    uiI0 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI1 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI2 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );

            VEC_T(1,C)      vX0 = psMA0->m_sMS.m_pvVert_List[uiI0];
            VEC_T(1,C)      vX1 = psMA0->m_sMS.m_pvVert_List[uiI1];
            VEC_T(1,C)      vX2 = psMA0->m_sMS.m_pvVert_List[uiI2];

            VEC_T(1,C)      vX3 = FCN_V(tgMH_ADD)( vX0, psMA0->m_pvVert_DT[uiI0] );
            VEC_T(1,C)      vX4 = FCN_V(tgMH_ADD)( vX1, psMA0->m_pvVert_DT[uiI1] );
            VEC_T(1,C)      vX5 = FCN_V(tgMH_ADD)( vX2, psMA0->m_pvVert_DT[uiI2] );

            VEC_T(1,C)      vX6 = FCN_V(tgMH_ADD)( vX1, vX2 );
            VEC_T(1,C)      vX7 = FCN_V(tgMH_ADD)( vX4, vX5 );
            VEC_T(1,C)      vX8 = FCN_V(tgMH_ADD)( vX0, vX6 );
            VEC_T(1,C)      vX9 = FCN_V(tgMH_ADD)( vX3, vX7 );

            psMA0->m_vCG[0] = FCN_V(tgMH_ADD)( psMA0->m_vCG[0], vX8 );
            psMA0->m_vCG[1] = FCN_V(tgMH_ADD)( psMA0->m_vCG[1], vX9 );

            FCN_VO(tgGM_BA_Init_PT)( psMA0->m_psBA + uiFace, vX0 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX1 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX2 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX3 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX4 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX5 );
        };

        psMA0->m_vCG[0] = FCN_V(tgMH_DIV)( psMA0->m_vCG[0], FCN_V(tgMH_SET1)((VAR_T())(itMS.m_nuiFace * TYPE_K(3))));
        psMA0->m_vCG[1] = FCN_V(tgMH_DIV)( psMA0->m_vCG[1], FCN_V(tgMH_SET1)((VAR_T())(itMS.m_nuiFace * TYPE_K(3))));
    }
    else if (ETgSWEEP_LINEAR == psMA0->m_enSweep)
    {
        for (uiFace = 0; uiFace < itMS.m_nuiFace; ++uiFace)
        {
            TgUINT_F32_C    uiI0 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI1 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI2 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );

            VEC_T(1,C)      vX0 = psMA0->m_sMS.m_pvVert_List[uiI0];
            VEC_T(1,C)      vX1 = psMA0->m_sMS.m_pvVert_List[uiI1];
            VEC_T(1,C)      vX2 = psMA0->m_sMS.m_pvVert_List[uiI2];
            VEC_T(1,C)      vX3 = FCN_V(tgMH_ADD)( vX1, vX2 );
            VEC_T(1,C)      vX4 = FCN_V(tgMH_ADD)( vX0, vX3 );

            psMA0->m_vCG[0] = FCN_V(tgMH_ADD)( psMA0->m_vCG[0], vX4 );

            FCN_VO(tgGM_BA_Init_PT)( psMA0->m_psBA + uiFace, vX0 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX1 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX2 );
            FCN_VO(tgGM_BA_Sweep)( psMA0->m_psBA + uiFace, psMA0->m_sDT.m_vDT );
        };

        psMA0->m_vCG[0] = FCN_V(tgMH_DIV)( psMA0->m_vCG[0], FCN_V(tgMH_SET1)((VAR_T())(itMS.m_nuiFace * TYPE_K(3))));
        psMA0->m_vCG[1] = FCN_V(tgMH_ADD)( psMA0->m_vCG[0], psMA0->m_sDT.m_vDT );
    }
    else if (ETgSWEEP_STATIC == psMA0->m_enSweep)
    {
        for (uiFace = 0; uiFace < itMS.m_nuiFace; ++uiFace)
        {
            TgUINT_F32_C    uiI0 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI1 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );
            TgUINT_F32_C    uiI2 = FI(tgGM_Iterator_Incr_MS)( &itMS, &psMA0->m_sMS );

            VEC_T(1,C)      vX0 = psMA0->m_sMS.m_pvVert_List[uiI0];
            VEC_T(1,C)      vX1 = psMA0->m_sMS.m_pvVert_List[uiI1];
            VEC_T(1,C)      vX2 = psMA0->m_sMS.m_pvVert_List[uiI2];
            VEC_T(1,C)      vX3 = FCN_V(tgMH_ADD)( vX1, vX2 );
            VEC_T(1,C)      vX4 = FCN_V(tgMH_ADD)( vX0, vX3 );

            psMA0->m_vCG[0] = FCN_V(tgMH_ADD)( psMA0->m_vCG[0], vX4 );

            FCN_VO(tgGM_BA_Init_PT)( psMA0->m_psBA + uiFace, vX0 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX1 );
            FCN_VO(tgGM_BA_Union_PT)( psMA0->m_psBA + uiFace, vX2 );
        }

        psMA0->m_vCG[0] = FCN_V(tgMH_DIV)( psMA0->m_vCG[0], FCN_V(tgMH_SET1)((VAR_T())(itMS.m_nuiFace * TYPE_K(3))));
        psMA0->m_vCG[1] = FCN_V(tgMH_SET1)( TYPE_K(0) );
    }
    else
    {
        TgERROR( false );
    };
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# !defined(ENABLE_RELOAD_GUARD_FILE) */
#endif

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
