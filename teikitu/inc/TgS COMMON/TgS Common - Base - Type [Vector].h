/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - Type [Vector].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_TYPE_VECTOR_H)
#define TGS_COMMON_BASE_TYPE_VECTOR_H
#pragma once

#include TgHEADER_HARDWARE(TgS COMMON/TgS,Common - Math [Vector].h)


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TEMPLATE__ENABLE_INTEGER

#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#define TEMPLATE__TYPE_SIZE 8
#define TEMPLATE__VECTOR_DIM 16
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#define TEMPLATE__TYPE_SIZE 16
#define TEMPLATE__VECTOR_DIM 8
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#define TEMPLATE__TYPE_SIZE 32
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#define TEMPLATE__TYPE_SIZE 8
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#define TEMPLATE__TYPE_SIZE 16
#define TEMPLATE__VECTOR_DIM 2
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#define TEMPLATE__TYPE_SIZE 64
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#undef TEMPLATE__ENABLE_INTEGER

#define TEMPLATE__VECTOR_DIM 2
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#define TEMPLATE__VECTOR_DIM 3
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Base - Type [Vector].h_inc"

#define TGS_COMMON_BASE_TYPE_VECTOR_HINC

/** @brief Native (scalar) vector with 3 rows (a DIMx3 matrix) */
TgTYPE_UNION( TgVEC_N_F32_04_3, )
{
    struct { TgVEC_N_F32_04_1                   m_r0,m_r1,m_r2; };
    TgVEC_N_F32_04_1                            m_avRow[3];
};

/** @brief Native (scalar) vector with 4 rows (a DIMx4 matrix) */
TgTYPE_UNION( TgVEC_N_F32_04_4, )
{
    struct { TgVEC_N_F32_04_1                   m_r0,m_r1,m_r2,m_r3; };
    TgVEC_N_F32_04_1                            m_avRow[4];
};


/* NOTE: From a memory alignment point of view, it is reasonable to cast a native vector down to a scalar vector, but not the other way around. */
TgTYPE_UNION(TgUN_V128,)
{
    TgVEC_N_F32_04_1                            m_N_F32_04_1;
    TgVEC_N_U32_04_1                            m_N_U32_04_1;
    TgVEC_N_U16_08_1                            m_N_U16_08_1;
    TgVEC_N_U08_16_1                            m_N_U08_16_1;
    TgVEC_N_S32_04_1                            m_N_S32_04_1;
    TgVEC_N_S16_08_1                            m_N_S16_08_1;
    TgVEC_N_S08_16_1                            m_N_S08_16_1;

    TgVEC_F32_04_1                              m_F32_04_1;
    TgVEC_U32_04_1                              m_U32_04_1;
    TgVEC_U16_08_1                              m_U16_08_1;
    TgVEC_U08_16_1                              m_U08_16_1;
    TgVEC_S32_04_1                              m_S32_04_1;
    TgVEC_S16_08_1                              m_S16_08_1;
    TgVEC_S08_16_1                              m_S08_16_1;
};
TgCOMPILER_ASSERT(16 == sizeof(TgUN_V128),);

TgTYPE_UNION(TgUN_PTR_V128,)
{
    TgVEC_N_F32_04_1_P                          m_pN_F32_04_1;
    TgVEC_N_U32_04_1_P                          m_pN_U32_04_1;
    TgVEC_N_U16_08_1_P                          m_pN_U16_08_1;
    TgVEC_N_U08_16_1_P                          m_pN_U08_16_1;
    TgVEC_N_S32_04_1_P                          m_pN_S32_04_1;
    TgVEC_N_S16_08_1_P                          m_pN_S16_08_1;
    TgVEC_N_S08_16_1_P                          m_pN_S08_16_1;

    TgVEC_N_F32_04_3_P                          m_pN_F32_04_3;
    TgVEC_N_F32_04_4_P                          m_pN_F32_04_4;

    TgVEC_F32_04_1_P                            m_pF32_04_1;
    TgVEC_U32_04_1_P                            m_pU32_04_1;
    TgVEC_U16_08_1_P                            m_pU16_08_1;
    TgVEC_U08_16_1_P                            m_pU08_16_1;
    TgVEC_S32_04_1_P                            m_pS32_04_1;
    TgVEC_S16_08_1_P                            m_pS16_08_1;
    TgVEC_S08_16_1_P                            m_pS08_16_1;

    TgVEC_F32_04_3_P                            m_pF32_04_3;
    TgVEC_F32_04_4_P                            m_pF32_04_4;
};

TgTYPE_UNION(TgUN_CONST_PTR_V128,)
{
    TgVEC_N_F32_04_1_CP                         m_pN_F32_04_1;
    TgVEC_N_U32_04_1_CP                         m_pN_U32_04_1;
    TgVEC_N_U16_08_1_CP                         m_pN_U16_08_1;
    TgVEC_N_U08_16_1_CP                         m_pN_U08_16_1;
    TgVEC_N_S32_04_1_CP                         m_pN_S32_04_1;
    TgVEC_N_S16_08_1_CP                         m_pN_S16_08_1;
    TgVEC_N_S08_16_1_CP                         m_pN_S08_16_1;

    TgVEC_N_F32_04_3_CP                         m_pN_F32_04_3;
    TgVEC_N_F32_04_4_CP                         m_pN_F32_04_4;

    TgVEC_F32_04_1_CP                           m_pF32_04_1;
    TgVEC_U32_04_1_CP                           m_pU32_04_1;
    TgVEC_U16_08_1_CP                           m_pU16_08_1;
    TgVEC_U08_16_1_CP                           m_pU08_16_1;
    TgVEC_S32_04_1_CP                           m_pS32_04_1;
    TgVEC_S16_08_1_CP                           m_pS16_08_1;
    TgVEC_S08_16_1_CP                           m_pS08_16_1;

    TgVEC_F32_04_3_CP                           m_pF32_04_3;
    TgVEC_F32_04_4_CP                           m_pF32_04_4;
};


/* =============================================================================================================================================================================== */
#endif
