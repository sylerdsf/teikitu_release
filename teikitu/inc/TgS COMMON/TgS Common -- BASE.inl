/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common -- BASE.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON__BASE_INL)
#define TGS_COMMON__BASE_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* TgS Common - Inline Implementation */
#include "TgS COMMON/TgS Common - Base - Type.inl"

#include "TgS COMMON/TgS Common - Base - API.inl"
#include "TgS COMMON/TgS Common - Base - API [Math].inl"
#include "TgS COMMON/TgS Common - Base - API [Text].inl"

/* Compiler and Hardware - Inline Implementation */
#include TgHEADER_THREAD_SUPPORT(TgS COMMON/TgS,Common - STg1_MT_SM.inl)
#include TgHEADER_THREAD_SUPPORT(TgS COMMON/TgS,Common - STg1_MT_MX.inl)

#include TgHEADER_COMPILER(TgS COMMON/TgS,Common - Base - API [Platform].inl)
#include TgHEADER_THREAD_SUPPORT(TgS COMMON/TgS,Common - Base - API [Platform].inl)


/* =============================================================================================================================================================================== */
#endif
