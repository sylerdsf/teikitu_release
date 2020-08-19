/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Torus.c_inc
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

/* ---- FCN_VO(tgGM_TS_Is_Valid) ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_TS_Is_Valid)( VEC_OBJ_T(TgTORUS,CPCU) psTS0 )
{
    if (!FCN_VO(tgGM_CI_Is_Valid)( &psTS0->m_sCI ))
    {
        return (false);
    };

    if (!(psTS0-> m_fRI >= TYPE_K(0)))
    {
        return (false);
    };

    return (true);
}


/* ---- FCN_VO(tgGM_TS_Support_Point) -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
VEC_T(1) FCN_VO(tgGM_TS_Support_Point)( VEC_OBJ_T(TgTORUS,CPCU) psTS0, VEC_T(1,C) vDN )
{
    VEC_T(1,C)      vX0 = FCN_VO(tgGM_CI_Support_Point)( &psTS0->m_sCI, vDN );
    VEC_T(1,C)      vX1 = FCN_V(tgMH_MAD)( vDN, FCN_V(tgMH_SET1)( psTS0->m_fRI ), vX0 );

    return (vX1);
}


/* ---- FCN_VO(tgGM_TS_BA) ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FCN_VO(tgGM_TS_BA)( VEC_OBJ_T(TgBOXAA,PCU) psBA0, VEC_OBJ_T(TgTORUS,CPCU) psTS0 )
{
    FCN_VO(tgGM_CI_BA)( psBA0, &psTS0->m_sCI );
    FCN_VO(tgGM_BA_Expand)( psBA0, psTS0->m_fRI );
}


/* ---- FCN_VO(tgGM_TS_Project) -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FCN_VO(tgGM_TS_Project)( VEC_T(1,PCU) pvMin, VEC_T(1,PCU) pvMax, VEC_OBJ_T(TgTORUS,CPCU) psTS0, VEC_T(1,C) vDN )
{
    FCN_VO(tgGM_CI_Project)( pvMin, pvMax, &psTS0->m_sCI, vDN );
    *pvMin = FCN_V(tgMH_SUB)( *pvMin, FCN_V(tgMH_SET1)( psTS0->m_fRI ) );
    *pvMax = FCN_V(tgMH_ADD)( *pvMax, FCN_V(tgMH_SET1)( psTS0->m_fRI ) );
}


/* ---- FCN_VO(tgGM_TS_Is_Contained) --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_TS_Is_Contained)( VEC_OBJ_T(TgTORUS,CPCU) psTS0, VEC_T(1,C) vS0 )
{
    VEC_T(1)                            vA0, vA1, vA2, vC0;
 
    TgGEOM_ASSERT_PARAM(FCN_VO(tgGM_TS_Is_Valid)( psTS0 ) && FCN_V(tgMH_Is_Valid_Point)( vS0 ));

    FCN_V(tgMH_Query_Reference_Frame,3)( &vA0, &vA1, &vA2, &vC0, &psTS0->m_sCI.m_mReference_Frame );

    VEC_UN_T(1,C)   uDS = { VEC_UN_1_MEMBER() = FCN_V(tgMH_SUB)( vS0, vC0 ) };
    VEC_UN_T(1,C)   uDS_A1 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT)( VEC_UN_1_MEMBER(uDS), vA1 ) };

    if (FCN_F(tgPM_ABS)( VEC_S_UN_1_MEMBER(uDS_A1).x ) > psTS0->m_fRI)
    {
        return (false);
    };

    VEC_T(1,C)      vX0 = FCN_V(tgMH_MUL)( VEC_UN_1_MEMBER(uDS_A1), vA1 ) ;
    if (FCN_V(tgMH_PRX_CMP_EQ)( vX0, VEC_UN_1_MEMBER(uDS) ))
    {
        return (false);
    };

    VEC_T(1,C)      vX1 = FCN_V(tgMH_SUB)( VEC_UN_1_MEMBER(uDS), vX0 );
    VEC_UN_T(1,C)   uU0 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_LEN)( vX1 ) };
    VEC_T(1,C)      vX2 = FCN_V(tgMH_NORM)( vX1 );
    if (VEC_S_UN_1_MEMBER(uU0).x < psTS0->m_sCI.m_fRadius - psTS0->m_fRI || VEC_S_UN_1_MEMBER(uU0).x > psTS0->m_sCI.m_fRadius + psTS0->m_fRI)
    {
        return (false);
    };

    VEC_T(1,C)      vX3 = FCN_V(tgMH_MAD)( FCN_V(tgMH_SET1)( psTS0->m_sCI.m_fRadius ), vX2, vC0 );
    VEC_T(1,C)      vX4 = FCN_V(tgMH_SUB)( vS0, vX3 );
    VEC_UN_T(1,C)   uU1 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_LEN)( vX4 ) };

    return (VEC_S_UN_1_MEMBER(uU1).x <= psTS0->m_fRI);
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
