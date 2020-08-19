/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (C11_64) Common - Math [Vector].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_C11_64_COMMON_MATH_VECTOR_H)
#define TGS_C11_64_COMMON_MATH_VECTOR_H
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

typedef __attribute__((__ext_vector_type__(16))) uint8_t TgVEC_U08_16_1;
TgTYPE_MODIFIER_ALL(TgVEC_U08_16_1);
typedef __attribute__((__ext_vector_type__(16),__aligned__(1))) uint8_t TgVEC_N1_U08_16_1;
TgTYPE_MODIFIER_ALL(TgVEC_N1_U08_16_1);

typedef __attribute__((__ext_vector_type__(8))) uint16_t TgVEC_U16_08_1;
TgTYPE_MODIFIER_ALL(TgVEC_U16_08_1);
typedef __attribute__((__ext_vector_type__(8),__aligned__(1))) uint16_t TgVEC_N1_U16_08_1;
TgTYPE_MODIFIER_ALL(TgVEC_N1_U16_08_1);

typedef __attribute__((__ext_vector_type__(4))) uint32_t TgVEC_U32_04_1;
TgTYPE_MODIFIER_ALL(TgVEC_U32_04_1);
typedef __attribute__((__ext_vector_type__(4),__aligned__(1))) uint32_t TgVEC_N1_U32_04_1;
TgTYPE_MODIFIER_ALL(TgVEC_N1_U32_04_1);

typedef __attribute__((__ext_vector_type__(16))) int8_t TgVEC_S08_16_1;
TgTYPE_MODIFIER_ALL(TgVEC_S08_16_1);
typedef __attribute__((__ext_vector_type__(16),__aligned__(1))) int8_t TgVEC_N1_S08_16_1;
TgTYPE_MODIFIER_ALL(TgVEC_N1_S08_16_1);

typedef __attribute__((__ext_vector_type__(8))) int16_t TgVEC_S16_08_1;
TgTYPE_MODIFIER_ALL(TgVEC_S16_08_1);
typedef __attribute__((__ext_vector_type__(8),__aligned__(1))) int16_t TgVEC_N1_S16_08_1;
TgTYPE_MODIFIER_ALL(TgVEC_N1_S16_08_1);

typedef __attribute__((__ext_vector_type__(4))) int32_t TgVEC_S32_04_1;
TgTYPE_MODIFIER_ALL(TgVEC_S32_04_1);
typedef __attribute__((__ext_vector_type__(4),__aligned__(1))) int32_t TgVEC_N1_S32_04_1;
TgTYPE_MODIFIER_ALL(TgVEC_N1_S32_04_1);

typedef __attribute__((__ext_vector_type__(4))) float TgVEC_F32_04_1;
TgTYPE_MODIFIER_ALL(TgVEC_F32_04_1);
typedef __attribute__((__ext_vector_type__(4),__aligned__(1))) float TgVEC_N1_F32_04_1;
TgTYPE_MODIFIER_ALL(TgVEC_N1_F32_04_1);


/* =============================================================================================================================================================================== */
#endif
