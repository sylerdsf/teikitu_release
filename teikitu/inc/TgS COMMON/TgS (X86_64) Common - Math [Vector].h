/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (X86_64) Common - Math [Vector].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_X86_64_COMMON_MATH_VECTOR_H)
#define TGS_X86_64_COMMON_MATH_VECTOR_H
#pragma once

#ifdef TGS_COMMON_MATH_VECTOR_SPECIALIZATION
    #error "Previous Math Specialization Already Exists"
#endif

#define TGS_COMMON_MATH_VECTOR_SPECIALIZATION


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgVEC_U08_16_1_C                __m128i const
#define TgVEC_U08_16_1_P                __m128i *
#define TgVEC_U08_16_1_PC               __m128i * const
#define TgVEC_U08_16_1_PCU              __m128i * const __restrict
#define TgVEC_U08_16_1_PU               __m128i * __restrict
#define TgVEC_U08_16_1_CP               __m128i const *
#define TgVEC_U08_16_1_CPU              __m128i const * __restrict
#define TgVEC_U08_16_1_CPC              __m128i const * const
#define TgVEC_U08_16_1_CPCU             __m128i const * const __restrict
#define TgVEC_U08_16_1_PP               __m128i**
#define TgVEC_U08_16_1_PPU              __m128i ** __restrict
#define TgVEC_U08_16_1_CPCPU            __m128i const *const * __restrict
#define TgVEC_U08_16_1_CPPU             __m128i const ** __restrict
#define TgVEC_U08_16_1_PPCU             __m128i ** const __restrict
#define TgVEC_U08_16_1                  __m128i

#define TgVEC_U16_08_1_C                __m128i const
#define TgVEC_U16_08_1_P                __m128i *
#define TgVEC_U16_08_1_PC               __m128i * const
#define TgVEC_U16_08_1_PCU              __m128i * const __restrict
#define TgVEC_U16_08_1_PU               __m128i * __restrict
#define TgVEC_U16_08_1_CP               __m128i const *
#define TgVEC_U16_08_1_CPU              __m128i const * __restrict
#define TgVEC_U16_08_1_CPC              __m128i const * const
#define TgVEC_U16_08_1_CPCU             __m128i const * const __restrict
#define TgVEC_U16_08_1_PP               __m128i**
#define TgVEC_U16_08_1_PPU              __m128i ** __restrict
#define TgVEC_U16_08_1_CPCPU            __m128i const *const * __restrict
#define TgVEC_U16_08_1_CPPU             __m128i const ** __restrict
#define TgVEC_U16_08_1_PPCU             __m128i ** const __restrict
#define TgVEC_U16_08_1                  __m128i

#define TgVEC_U32_04_1_C                __m128i const
#define TgVEC_U32_04_1_P                __m128i *
#define TgVEC_U32_04_1_PC               __m128i * const
#define TgVEC_U32_04_1_PCU              __m128i * const __restrict
#define TgVEC_U32_04_1_PU               __m128i * __restrict
#define TgVEC_U32_04_1_CP               __m128i const *
#define TgVEC_U32_04_1_CPU              __m128i const * __restrict
#define TgVEC_U32_04_1_CPC              __m128i const * const
#define TgVEC_U32_04_1_CPCU             __m128i const * const __restrict
#define TgVEC_U32_04_1_PP               __m128i**
#define TgVEC_U32_04_1_PPU              __m128i ** __restrict
#define TgVEC_U32_04_1_CPCPU            __m128i const *const * __restrict
#define TgVEC_U32_04_1_CPPU             __m128i const ** __restrict
#define TgVEC_U32_04_1_PPCU             __m128i ** const __restrict
#define TgVEC_U32_04_1                  __m128i

#define TgVEC_S08_16_1_C                __m128i const
#define TgVEC_S08_16_1_P                __m128i *
#define TgVEC_S08_16_1_PC               __m128i * const
#define TgVEC_S08_16_1_PCU              __m128i * const __restrict
#define TgVEC_S08_16_1_PU               __m128i * __restrict
#define TgVEC_S08_16_1_CP               __m128i const *
#define TgVEC_S08_16_1_CPU              __m128i const * __restrict
#define TgVEC_S08_16_1_CPC              __m128i const * const
#define TgVEC_S08_16_1_CPCU             __m128i const * const __restrict
#define TgVEC_S08_16_1_PP               __m128i**
#define TgVEC_S08_16_1_PPU              __m128i ** __restrict
#define TgVEC_S08_16_1_CPCPU            __m128i const *const * __restrict
#define TgVEC_S08_16_1_CPPU             __m128i const ** __restrict
#define TgVEC_S08_16_1_PPCU             __m128i ** const __restrict
#define TgVEC_S08_16_1                  __m128i

#define TgVEC_S16_08_1_C                __m128i const
#define TgVEC_S16_08_1_P                __m128i *
#define TgVEC_S16_08_1_PC               __m128i * const
#define TgVEC_S16_08_1_PCU              __m128i * const __restrict
#define TgVEC_S16_08_1_PU               __m128i * __restrict
#define TgVEC_S16_08_1_CP               __m128i const *
#define TgVEC_S16_08_1_CPU              __m128i const * __restrict
#define TgVEC_S16_08_1_CPC              __m128i const * const
#define TgVEC_S16_08_1_CPCU             __m128i const * const __restrict
#define TgVEC_S16_08_1_PP               __m128i**
#define TgVEC_S16_08_1_PPU              __m128i ** __restrict
#define TgVEC_S16_08_1_CPCPU            __m128i const *const * __restrict
#define TgVEC_S16_08_1_CPPU             __m128i const ** __restrict
#define TgVEC_S16_08_1_PPCU             __m128i ** const __restrict
#define TgVEC_S16_08_1                  __m128i

#define TgVEC_S32_04_1_C                __m128i const
#define TgVEC_S32_04_1_P                __m128i *
#define TgVEC_S32_04_1_PC               __m128i * const
#define TgVEC_S32_04_1_PCU              __m128i * const __restrict
#define TgVEC_S32_04_1_PU               __m128i * __restrict
#define TgVEC_S32_04_1_CP               __m128i const *
#define TgVEC_S32_04_1_CPU              __m128i const * __restrict
#define TgVEC_S32_04_1_CPC              __m128i const * const
#define TgVEC_S32_04_1_CPCU             __m128i const * const __restrict
#define TgVEC_S32_04_1_PP               __m128i**
#define TgVEC_S32_04_1_PPU              __m128i ** __restrict
#define TgVEC_S32_04_1_CPCPU            __m128i const *const * __restrict
#define TgVEC_S32_04_1_CPPU             __m128i const ** __restrict
#define TgVEC_S32_04_1_PPCU             __m128i ** const __restrict
#define TgVEC_S32_04_1                  __m128i

#define TgVEC_F32_04_1_C                __m128 const
#define TgVEC_F32_04_1_P                __m128 *
#define TgVEC_F32_04_1_PC               __m128 * const
#define TgVEC_F32_04_1_PCU              __m128 * const __restrict
#define TgVEC_F32_04_1_PU               __m128 * __restrict
#define TgVEC_F32_04_1_CP               __m128 const *
#define TgVEC_F32_04_1_CPU              __m128 const * __restrict
#define TgVEC_F32_04_1_CPC              __m128 const * const
#define TgVEC_F32_04_1_CPCU             __m128 const * const __restrict
#define TgVEC_F32_04_1_PP               __m128**
#define TgVEC_F32_04_1_PPU              __m128 ** __restrict
#define TgVEC_F32_04_1_CPCPU            __m128 const *const * __restrict
#define TgVEC_F32_04_1_CPPU             __m128 const ** __restrict
#define TgVEC_F32_04_1_PPCU             __m128 ** const __restrict
#define TgVEC_F32_04_1                  __m128


/* =============================================================================================================================================================================== */
#endif
