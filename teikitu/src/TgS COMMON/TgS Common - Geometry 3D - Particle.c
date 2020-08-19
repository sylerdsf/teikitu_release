/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Particle.c_inc
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

/* ---- FCN_VO(tgGM_PC_BA) ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FCN_VO(tgGM_PC_BA)( VEC_OBJ_T(TgBOXAA,PCU) psBA0, VEC_OBJ_T(TgPARTICLE,CPCU) psPC1, VAR_T(C) fT )
{
    TgGEOM_ASSERT_PARAM(FCN_VO(tgGM_PC_Is_Valid)( psPC1 ) && fT >= TYPE_K(0));

    VEC_T(1,C)      vC0 = FCN_VO(tgGM_PC_Query_Position)( psPC1 );
    VEC_T(1,C)      vC1 = FCN_VO(tgGM_PC_Query_Position_Time)( psPC1, fT );

    FCN_VO(tgGM_BA_Init_PT)( psBA0, vC0 );
    FCN_VO(tgGM_BA_Union_PT)( psBA0, vC1 );

    VEC_T(1,C)      vBA_Min = FCN_VO(tgGM_BA_Query_Min)( psBA0 );
    VEC_T(1,C)      vBA_Max = FCN_VO(tgGM_BA_Query_Max)( psBA0 );

    VEC_T(1,C)      vNeg_Vel = FCN_V(tgMH_NEG)( psPC1->m_vVel );
    VEC_T(1,C)      vToI = FCN_V(tgMH_DIV)( vNeg_Vel, psPC1->m_vAccel );
    VEC_T(1,C)      vToI_Sat = FCN_V(tgMH_CLP)( vToI, FCN_V(tgMH_SET1)( TYPE_K(0) ), FCN_V(tgMH_SET1)( fT ) );
    VEC_T(1,C)      vX0 = FCN_V(tgMH_MAD)( vToI_Sat, psPC1->m_vVel, psPC1->m_vPos );
    VEC_T(1,C)      vX1 = FCN_V(tgMH_MUL)( FCN_V(tgMH_SET1)( TYPE_K(0,5) ), FCN_V(tgMH_MUL)( vToI_Sat, vToI_Sat ) );
    VEC_T(1,C)      vInflection = FCN_V(tgMH_MAD)( vX1, psPC1->m_vAccel, vX0 );

    VEC_T(1,C)      vX2 = FCN_V(tgMH_Init_Vector)( FCN_V(tgMH_MIN)( vBA_Min, vInflection ) );
    VEC_T(1,C)      vX3 = FCN_V(tgMH_Init_Vector)( FCN_V(tgMH_MAX)( vBA_Max, vInflection ) );

    FCN_VO(tgGM_BA_Set_Min)( psBA0, vX2 );
    FCN_VO(tgGM_BA_Set_Max)( psBA0, vX3 );
}


/* ---- FCN_VO(tgGM_PC_Project) -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID FCN_VO(tgGM_PC_Project)( VEC_T(1,PCU) pvMin, VEC_T(1,PCU) pvMax, VEC_OBJ_T(TgPARTICLE,CPCU) psPC1, VEC_T(1,C) vDN, VAR_T(C) fT )
{
    TgGEOM_ASSERT_PARAM(FCN_VO(tgGM_PC_Is_Valid)( psPC1 ) && fT >= TYPE_K(0));

    VEC_T(1,C)      vC0 = FCN_VO(tgGM_PC_Query_Position)( psPC1 );
    VEC_T(1,C)      vC0_DN = FCN_V(tgMH_DOT)( vC0, vDN );
    VEC_T(1,C)      vC1 = FCN_VO(tgGM_PC_Query_Position_Time)( psPC1, fT );
    VEC_T(1,C)      vC1_DN = FCN_V(tgMH_DOT)( vC1, vDN );

    VEC_T(1,C)      vV0_DN = FCN_V(tgMH_DOT)( psPC1->m_vVel, vDN );
    VEC_T(1,C)      vA0_DN = FCN_V(tgMH_DOT)( psPC1->m_vAccel, vDN );
    VEC_T(1,C)      vToI = FCN_V(tgMH_DIV)( FCN_V(tgMH_NEG)( vV0_DN ), vA0_DN );
    VEC_T(1,C)      vToI_Sat = FCN_V(tgMH_CLP)( vToI, FCN_V(tgMH_SET1)( TYPE_K(0) ), FCN_V(tgMH_SET1)( fT ) );
    VEC_T(1,C)      vX0 = FCN_V(tgMH_MAD)( vToI_Sat, psPC1->m_vVel, psPC1->m_vPos );
    VEC_T(1,C)      vX1 = FCN_V(tgMH_MUL)( FCN_V(tgMH_SET1)( TYPE_K(0,5) ), FCN_V(tgMH_MUL)( vToI_Sat, vToI_Sat ) );
    VEC_T(1,C)      vPoint_Of_Inflection = FCN_V(tgMH_MAD)( vX1, psPC1->m_vAccel, vX0 );
    VEC_T(1,C)      vPoI_DN = FCN_V(tgMH_DOT)( vPoint_Of_Inflection, vDN );

    *pvMin = FCN_V(tgMH_MIN)( vC0_DN, FCN_V(tgMH_MIN)( vC1_DN, vPoI_DN ) );
    *pvMax = FCN_V(tgMH_MAX)( vC0_DN, FCN_V(tgMH_MAX)( vC1_DN, vPoI_DN ) );
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
