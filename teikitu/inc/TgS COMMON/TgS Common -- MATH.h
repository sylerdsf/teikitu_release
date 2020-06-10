/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common -- MATH.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_MATH_H)
#define TGS_COMMON_MATH_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_MATH Math Functions
    @ingroup TGS_COMMON
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */


#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#include "TgS COMMON/TgS Common - Math [Scalar] [F].h_inc"
#define TGS_COMMON_MATH_API_HINC


#define TEMPLATE__ENABLE_INTEGER

#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#define TEMPLATE__TYPE_SIZE 8
#define TEMPLATE__VECTOR_DIM 16
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"

#define TEMPLATE__TYPE_SIZE 16
#define TEMPLATE__VECTOR_DIM 8
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"

#define TEMPLATE__TYPE_SIZE 32
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"

#define TEMPLATE__TYPE_SIZE 8
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"

#define TEMPLATE__TYPE_SIZE 16
#define TEMPLATE__VECTOR_DIM 2
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"

#define TEMPLATE__TYPE_SIZE 64
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"

#undef TEMPLATE__ENABLE_INTEGER

#define TEMPLATE__VECTOR_DIM 2
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"

#define TEMPLATE__VECTOR_DIM 3
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS COMMON/TgS Common - Math [Vector] [API].h_inc"


#define TGS_COMMON_MATH_VECTOR_HINC


#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#define TEMPLATE__VECTOR_DIM 4
#define TEMPLATE__VECTOR_ROW 3
#include "TgS COMMON/TgS Common - Math [Matrix] [API].h_inc"

#define TEMPLATE__VECTOR_DIM 4
#define TEMPLATE__VECTOR_ROW 4
#include "TgS COMMON/TgS Common - Math [Matrix] [API].h_inc"

#define TGS_COMMON_MATH_MATRIX_HINC


/* =============================================================================================================================================================================== */
#endif
