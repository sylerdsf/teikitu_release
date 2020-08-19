/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Cylinder.c_inc
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

/* ---- FCN_VO(tgGM_CY_Support_Point) -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
VEC_T(1) FCN_VO(tgGM_CY_Support_Point)( VEC_OBJ_T(TgTUBE,CPCU) psCY0, VEC_T(1,C) vDN )
{
    VEC_T(1)                            vResult;

    TgERROR(FCN_V(tgMH_Is_Valid_Unit_Vector)( vDN ));

    VEC_T(1,C)      vN0 = FCN_V(tgMH_Query_Axis_1,3)( &psCY0->m_mReference_Frame );
    VEC_UN_T(1,C)   uDN_N0 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT)( vDN, vN0 ) };
    VEC_T(1,C)      vC0 = FCN_V(tgMH_Query_Axis_3,3)( &psCY0->m_mReference_Frame );

    if (VEC_S_UN_1_MEMBER(uDN_N0).x > VAR_K(KTgEPS))
    {
        vResult = FCN_V(tgMH_ADD)( vC0, psCY0->m_vHAX );
    }
    else if (VEC_S_UN_1_MEMBER(uDN_N0).x < -VAR_K(KTgEPS))
    {
        vResult = FCN_V(tgMH_SUB)( vC0, psCY0->m_vHAX );
    }
    else
    {
        vResult = vC0;
    }

    VEC_T(1,C)      vX0 = FCN_V(tgMH_MUL)( VEC_UN_1_MEMBER(uDN_N0), vN0 );
    VEC_T(1,C)      vX1 = FCN_V(tgMH_SUB)( vDN, vX0 );
    VEC_UN_T(1,C)   uU0 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_LEN)( vX1 ) };

    if (VEC_S_UN_1_MEMBER(uU0).x > VAR_K(KTgEPS))
    {
        VEC_T(1,C)      vRadial = FCN_V(tgMH_NORM)( vX1 );

        vResult = FCN_V(tgMH_MAD)( FCN_V(tgMH_SET1)( psCY0->m_fRadius ), vRadial, vResult );
    };

    return (vResult);
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
