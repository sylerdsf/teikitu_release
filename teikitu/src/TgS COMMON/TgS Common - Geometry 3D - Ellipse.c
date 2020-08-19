/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Ellipse.c_inc
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

/* ---- FCN_VO(tgGM_EL_Is_Valid) ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_EL_Is_Valid)( VEC_OBJ_T(TgELLIPSE,CPCU) psEL0 )
{
    if (!FCN_V(tgMH_Is_Valid_Reference_Frame,3)( &psEL0->m_mReference_Frame ))
    {
        return (false);
    };

    if (!(psEL0->m_fMajor > TYPE_K(0)) || !(psEL0->m_fMinor > TYPE_K(0)))
    {
        return (false);
    };

    return (true);
}


/* ---- FCN_VO(tgGM_EL_Support_Point) -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
VEC_T(1) FCN_VO(tgGM_EL_Support_Point)( VEC_OBJ_T(TgELLIPSE,CPCU) psEL0, VEC_T(1,C) vDN )
{
    VEC_T(1)                            vA0, vA1, vA2, vC0;

    TgGEOM_ASSERT_PARAM(FCN_VO(tgGM_EL_Is_Valid)( psEL0 ) && FCN_V(tgMH_Is_Valid_Unit_Vector)( vDN ));

    FCN_V(tgMH_Query_Reference_Frame,3)( &vA0, &vA1, &vA2, &vC0, &psEL0->m_mReference_Frame );

    VEC_UN_T(1,C)   uDN_A0 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT)( vDN, vA0 ) };
    VEC_UN_T(1,C)   uDN_A2 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT)( vDN, vA2 ) };

    if (FCN_F(tgCM_NR0)( VEC_S_UN_1_MEMBER(uDN_A0).x ) && FCN_F(tgCM_NR0)( VEC_S_UN_1_MEMBER(uDN_A2).x ))
    {
        return (vC0);
    }
    else
    {
        VAR_T(C)        fInvMajorSq = VEC_S_UN_1_MEMBER(uDN_A0).x / (psEL0->m_fMajor * psEL0->m_fMajor);
        VAR_T(C)        fInvMinorSq = VEC_S_UN_1_MEMBER(uDN_A2).x / (psEL0->m_fMinor * psEL0->m_fMinor);
        VAR_T(C)        fRHS = TYPE_K(1) / (fInvMajorSq + fInvMinorSq);
        VAR_T(C)        fPoint = FCN_F(tgPM_SQRT)( FCN_F(tgPM_ABS)( fRHS ) );

        VEC_T(1,C)      vX0 = FCN_V(tgMH_MUL)( FCN_V(tgMH_SET1)( fPoint ), FCN_V(tgMH_SET1)( psEL0->m_fMajor ) );
        VEC_T(1,C)      vX1 = FCN_V(tgMH_CP_SGN)( vX0, VEC_UN_1_MEMBER(uDN_A0) );
        VEC_T(1,C)      vX2 = FCN_V(tgMH_MUL)( vX1, vA0 );

        VEC_T(1,C)      vX3 = FCN_V(tgMH_MUL)( FCN_V(tgMH_SET1)( fPoint ), FCN_V(tgMH_SET1)( psEL0->m_fMinor ) );
        VEC_T(1,C)      vX4 = FCN_V(tgMH_CP_SGN)( vX3, VEC_UN_1_MEMBER(uDN_A2) );
        VEC_T(1,C)      vX5 = FCN_V(tgMH_MUL)( vX4, vA2 );

        VEC_T(1,C)      vX6 = FCN_V(tgMH_ADD)( vX2, vX5 );

        return (FCN_V(tgMH_ADD)( vC0, vX6 ));
    };
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
