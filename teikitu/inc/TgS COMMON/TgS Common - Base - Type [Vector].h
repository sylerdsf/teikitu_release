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

#if defined(TgBUILD_UNIVERSAL) && !defined (TGS_COMMON_MATH_VECTOR_SPECIALIZATION)
    #include TgHEADER_UNIVERSAL(TgS COMMON/TgS,Common - Math [Vector].h)
#endif
#if defined(TgBUILD_HARDWARE) && !defined(TgBUILD_HARDWARE__C11_32) && !defined(TgBUILD_HARDWARE__C11_64) && !defined (TGS_COMMON_MATH_VECTOR_SPECIALIZATION)
    #include TgHEADER_HARDWARE(TgS COMMON/TgS,Common - Math [Vector].h)
#endif
#if defined(TgBUILD_COMPILER) && defined(TgBUILD_VECTOR__COMPILER) && !defined (TGS_COMMON_MATH_VECTOR_SPECIALIZATION)
    #include TgHEADER_COMPILER(TgS COMMON/TgS,Common - Math [Vector].h)
#endif


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


/* NOTE: From a memory alignment point of view, it is reasonable to cast a native vector down to a scalar vector, but not the other way around. */
TgTYPE_UNION(TgUN_V128,)
{
    TgVEC_F32_04_1                              m_vF32_04_1;
    TgVEC_U32_04_1                              m_vU32_04_1;
    TgVEC_U16_08_1                              m_vU16_08_1;
    TgVEC_U08_16_1                              m_vU08_16_1;
    TgVEC_S32_04_1                              m_vS32_04_1;
    TgVEC_S16_08_1                              m_vS16_08_1;
    TgVEC_S08_16_1                              m_vS08_16_1;

    TgVEC_S_F32_04_1                            m_vS_F32_04_1;
    TgVEC_S_U32_04_1                            m_vS_U32_04_1;
    TgVEC_S_U16_08_1                            m_vS_U16_08_1;
    TgVEC_S_U08_16_1                            m_vS_U08_16_1;
    TgVEC_S_S32_04_1                            m_vS_S32_04_1;
    TgVEC_S_S16_08_1                            m_vS_S16_08_1;
    TgVEC_S_S08_16_1                            m_vS_S08_16_1;
};
TgCOMPILER_ASSERT(16 == sizeof(TgUN_V128),);

TgTYPE_UNION(TgUN_PTR_V128,)
{
    TgVEC_F32_04_1_P                            m_pvF32_04_1;
    TgVEC_U32_04_1_P                            m_pvU32_04_1;
    TgVEC_U16_08_1_P                            m_pvU16_08_1;
    TgVEC_U08_16_1_P                            m_pvU08_16_1;
    TgVEC_S32_04_1_P                            m_pvS32_04_1;
    TgVEC_S16_08_1_P                            m_pvS16_08_1;
    TgVEC_S08_16_1_P                            m_pvS08_16_1;

    TgVEC_F32_04_3_P                            m_pvF32_04_3;
    TgVEC_F32_04_4_P                            m_pvF32_04_4;

    TgVEC_S_F32_04_1_P                          m_pvS_F32_04_1;
    TgVEC_S_U32_04_1_P                          m_pvS_U32_04_1;
    TgVEC_S_U16_08_1_P                          m_pvS_U16_08_1;
    TgVEC_S_U08_16_1_P                          m_pvS_U08_16_1;
    TgVEC_S_S32_04_1_P                          m_pvS_S32_04_1;
    TgVEC_S_S16_08_1_P                          m_pvS_S16_08_1;
    TgVEC_S_S08_16_1_P                          m_pvS_S08_16_1;

    TgVEC_S_F32_04_3_P                          m_pvS_F32_04_3;
    TgVEC_S_F32_04_4_P                          m_pvS_F32_04_4;
};

TgTYPE_UNION(TgUN_CONST_PTR_V128,)
{
    TgVEC_F32_04_1_CP                           m_pvF32_04_1;
    TgVEC_U32_04_1_CP                           m_pvU32_04_1;
    TgVEC_U16_08_1_CP                           m_pvU16_08_1;
    TgVEC_U08_16_1_CP                           m_pvU08_16_1;
    TgVEC_S32_04_1_CP                           m_pvS32_04_1;
    TgVEC_S16_08_1_CP                           m_pvS16_08_1;
    TgVEC_S08_16_1_CP                           m_pvS08_16_1;

    TgVEC_F32_04_3_CP                           m_pvF32_04_3;
    TgVEC_F32_04_4_CP                           m_pvF32_04_4;

    TgVEC_S_F32_04_1_CP                         m_pvS_F32_04_1;
    TgVEC_S_U32_04_1_CP                         m_pvS_U32_04_1;
    TgVEC_S_U16_08_1_CP                         m_pvS_U16_08_1;
    TgVEC_S_U08_16_1_CP                         m_pvS_U08_16_1;
    TgVEC_S_S32_04_1_CP                         m_pvS_S32_04_1;
    TgVEC_S_S16_08_1_CP                         m_pvS_S16_08_1;
    TgVEC_S_S08_16_1_CP                         m_pvS_S08_16_1;

    TgVEC_S_F32_04_3_CP                         m_pvS_F32_04_3;
    TgVEC_S_F32_04_4_CP                         m_pvS_F32_04_4;
};


/* =============================================================================================================================================================================== */
#endif
