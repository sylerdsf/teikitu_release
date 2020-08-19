/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Mesh [Simple].c_inc
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

/* ---- FCN_VO(tgGM_MS_Is_Valid) ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_MS_Is_Valid)( VEC_OBJ_T(TgMESH_SIMPLE,CPCU) psMS1 )
{
    if (psMS1->m_nuiVert >= KTgMAX_U16)
    {
        return (false);
    };

    if (nullptr != psMS1->m_puiIndx_List)
    {
        if (0 != (psMS1->m_nuiIndx % 3))
        {
            return (false);
        };

        for (TgRSIZE uiIndex = 0; uiIndex < psMS1->m_nuiIndx; ++uiIndex)
        {
            if (psMS1->m_puiIndx_List[uiIndex] >= psMS1->m_nuiVert)
            {
                return (false);
            };
        };
    }
    else
    {
        if (0 != (psMS1->m_nuiVert % 3))
        {
            return (false);
        };
    };

    for (TgRSIZE uiIndex = 0; uiIndex < psMS1->m_nuiVert; ++uiIndex)
    {
        if (!FCN_V(tgMH_Is_Valid_Point)( psMS1->m_pvVert_List[uiIndex] ))
        {
            return (false);
        };
    };

    return (true);
}


/* ---- FCN_VO(tgGM_MS_Support_Point) -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
VEC_T(1) FCN_VO(tgGM_MS_Support_Point)( VEC_OBJ_T(TgMESH_SIMPLE,CPCU) psMS1, VEC_T(1,C) vDN )
{
    VEC_UN_T(1)                         uU0, uMax;
    VAR_T()                             fMaxL;
    TgRSIZE                             uiPoint;

    VEC_UN_1_MEMBER(uMax) = FCN_V(tgMH_SET1)( -VAR_K(KTgMAX) );
    fMaxL = -VAR_K(KTgMAX);
    uiPoint = KTgMAX_RSIZE;

    for (TgRSIZE uiIndex = 0; uiIndex < psMS1->m_nuiVert; ++uiIndex)
    {
        VEC_UN_1_MEMBER(uU0) = FCN_V(tgMH_DOT3)( psMS1->m_pvVert_List[uiIndex], vDN );

        if (fMaxL < VEC_S_UN_1_MEMBER(uU0).x)
        {
            uiPoint = uiIndex;
            fMaxL = VEC_S_UN_1_MEMBER(uU0).x;
        };
    };

    if (~0u != uiPoint)
    {
        return (psMS1->m_pvVert_List[uiPoint]);
    }
    else
    {
        return (FCN_V(tgMH_SET1)( VAR_K(KTgMAX) ));
    };
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
