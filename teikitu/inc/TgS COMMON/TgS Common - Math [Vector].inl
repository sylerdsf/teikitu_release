/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Math [Vector].inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_MATH_API_VECTOR_INL)
#define TGS_COMMON_MATH_API_VECTOR_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Code Macros                                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define VEC_02_1_ASSIGN_EQN                                                                                                                                                         \
    VEC_T(1)                            vResult;                                                                                                                                    \
    vResult.m_aData[ 0] = EQN( 0);                                                                                                                                                  \
    vResult.m_aData[ 1] = EQN( 1);                                                                                                                                                  \
    return (vResult);

#define VEC_03_1_ASSIGN_EQN                                                                                                                                                         \
    VEC_T(1)                            vResult;                                                                                                                                    \
    vResult.m_aData[ 0] = EQN( 0);                                                                                                                                                  \
    vResult.m_aData[ 1] = EQN( 1);                                                                                                                                                  \
    vResult.m_aData[ 2] = EQN( 2);                                                                                                                                                  \
    return (vResult);

#define VEC_04_1_ASSIGN_EQN                                                                                                                                                         \
    VEC_T(1)                            vResult;                                                                                                                                    \
    vResult.m_aData[ 0] = EQN( 0);                                                                                                                                                  \
    vResult.m_aData[ 1] = EQN( 1);                                                                                                                                                  \
    vResult.m_aData[ 2] = EQN( 2);                                                                                                                                                  \
    vResult.m_aData[ 3] = EQN( 3);                                                                                                                                                  \
    return (vResult);

#define VEC_08_1_ASSIGN_EQN                                                                                                                                                         \
    VEC_T(1)                            vResult;                                                                                                                                    \
    vResult.m_aData[ 0] = EQN( 0);                                                                                                                                                  \
    vResult.m_aData[ 1] = EQN( 1);                                                                                                                                                  \
    vResult.m_aData[ 2] = EQN( 2);                                                                                                                                                  \
    vResult.m_aData[ 3] = EQN( 3);                                                                                                                                                  \
    vResult.m_aData[ 4] = EQN( 4);                                                                                                                                                  \
    vResult.m_aData[ 5] = EQN( 5);                                                                                                                                                  \
    vResult.m_aData[ 6] = EQN( 6);                                                                                                                                                  \
    vResult.m_aData[ 7] = EQN( 7);                                                                                                                                                  \
    return (vResult);

#define VEC_16_1_ASSIGN_EQN                                                                                                                                                         \
    VEC_T(1)                            vResult;                                                                                                                                    \
    vResult.m_aData[ 0] = EQN( 0);                                                                                                                                                  \
    vResult.m_aData[ 1] = EQN( 1);                                                                                                                                                  \
    vResult.m_aData[ 2] = EQN( 2);                                                                                                                                                  \
    vResult.m_aData[ 3] = EQN( 3);                                                                                                                                                  \
    vResult.m_aData[ 4] = EQN( 4);                                                                                                                                                  \
    vResult.m_aData[ 5] = EQN( 5);                                                                                                                                                  \
    vResult.m_aData[ 6] = EQN( 6);                                                                                                                                                  \
    vResult.m_aData[ 7] = EQN( 7);                                                                                                                                                  \
    vResult.m_aData[ 8] = EQN( 8);                                                                                                                                                  \
    vResult.m_aData[ 9] = EQN( 9);                                                                                                                                                  \
    vResult.m_aData[10] = EQN(10);                                                                                                                                                  \
    vResult.m_aData[11] = EQN(11);                                                                                                                                                  \
    vResult.m_aData[12] = EQN(12);                                                                                                                                                  \
    vResult.m_aData[13] = EQN(13);                                                                                                                                                  \
    vResult.m_aData[14] = EQN(14);                                                                                                                                                  \
    vResult.m_aData[15] = EQN(15);                                                                                                                                                  \
    return (vResult);


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TEMPLATE__ENABLE_INTEGER

#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS

#define TEMPLATE__TYPE_SIZE 8
#define TEMPLATE__VECTOR_DIM 16
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"

#define TEMPLATE__TYPE_SIZE 16
#define TEMPLATE__VECTOR_DIM 8
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"

#define TEMPLATE__TYPE_SIZE 32
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"

#define TEMPLATE__TYPE_SIZE 8
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"

#define TEMPLATE__TYPE_SIZE 16
#define TEMPLATE__VECTOR_DIM 2
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"

#define TEMPLATE__TYPE_SIZE 64
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"

#undef TEMPLATE__ENABLE_INTEGER

#define TEMPLATE__VECTOR_DIM 2
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"

#define TEMPLATE__VECTOR_DIM 3
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Math [Vector] [API].i_inc"


#define TGS_COMMON_MATH_API_VECTOR_IINC


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

#undef VEC_12_ASSIGN_EQN
#undef VEC_13_ASSIGN_EQN
#undef VEC_14_ASSIGN_EQN
#undef VEC_08_ASSIGN_EQN
#undef VEC_16_ASSIGN_EQN


/* =============================================================================================================================================================================== */
#endif
