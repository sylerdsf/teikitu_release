/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common -- UTIL.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UTIL_INL)
#define TGS_COMMON_UTIL_INL
#pragma once

/* Make sure the header has been included */
#include "TgS COMMON/TgS Common -- UTIL.h"

/* Single threaded containers */
#include "TgS COMMON/TgS Common - Util ST - Array.inl"
#include "TgS COMMON/TgS Common - Util ST - Colour.inl"
#include "TgS COMMON/TgS Common - Util ST - List.inl"
#include "TgS COMMON/TgS Common - Util ST - Queue.inl"
#include "TgS COMMON/TgS Common - Util ST - String.inl"

/* Single thread types */
#include "TgS COMMON/TgS Common - Util ST - Colour.h"

/* Multithreaded locks (gates) */
#include "TgS COMMON/TgS Common - Util MT - Spin Lock.inl"
#include "TgS COMMON/TgS Common - Util MT - Reader Writer Lock.inl"

/* Multithreaded containers */
#include "TgS COMMON/TgS Common - Util MT - Hash Table.inl"
#include "TgS COMMON/TgS Common - Util MT - LA Ring Buffer SRSW.inl"
#include "TgS COMMON/TgS Common - Util MT - Stack.inl"

/* Multithreaded types */
#include "TgS COMMON/TgS Common - Util MT - Profile Sample.inl"


/* =============================================================================================================================================================================== */
#endif
