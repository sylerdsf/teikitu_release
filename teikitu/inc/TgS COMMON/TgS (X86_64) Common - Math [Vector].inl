/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (X86_64) Common - Math [Vector].inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_X86_64_COMMON_MATH_VECTOR_INL)
#define TGS_X86_64_COMMON_MATH_VECTOR_INL
#pragma once

#ifdef TGS_COMMON_MATH_API_VECTOR_SPECIALIZATION_INL
#error("Previous Platform Specialization loaded");
#endif

#define TGS_COMMON_MATH_API_VECTOR_SPECIALIZATION_INL


/* == Common ===================================================================================================================================================================== */

#define MM_PERM(fp0,fp1,fp2,fp3) (((fp3) << 6) | ((fp2) << 4) | ((fp1) << 2) | ((fp0)))

#include "TgS COMMON/TgS (X86_64) Common - Math [Vector] [N] [F32_04].inl"
#include "TgS COMMON/TgS (X86_64) Common - Math [Vector] [N] [F32].inl"
#include "TgS COMMON/TgS (X86_64) Common - Math [Vector] [N] [U08].inl"
#include "TgS COMMON/TgS (X86_64) Common - Math [Vector] [N] [U16].inl"
#include "TgS COMMON/TgS (X86_64) Common - Math [Vector] [N] [U32].inl"
#include "TgS COMMON/TgS (X86_64) Common - Math [Vector] [N] [S08].inl"
#include "TgS COMMON/TgS (X86_64) Common - Math [Vector] [N] [S16].inl"
#include "TgS COMMON/TgS (X86_64) Common - Math [Vector] [N] [S32].inl"


/* =============================================================================================================================================================================== */
#endif
