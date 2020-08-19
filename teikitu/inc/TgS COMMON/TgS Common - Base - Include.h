/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - Include.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_INCLUDE_H)
#define TGS_COMMON_BASE_INCLUDE_H
#pragma once

#include TgHEADER_THREAD_SUPPORT(TgS COMMON/TgS,Common - Base - Include.h)
#include TgHEADER_HARDWARE(TgS COMMON/TgS,Common - Base - Include.h)


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

#if !defined(TgCOMPILE__NO_SYSTEM_HEADERS) || defined(TgCOMPILE__DOXYGEN_BUILD)

MSVC_PRAGMA(warning( push, 3 ))
CLANG_PRAGMA( system_header )
#define __STDC_WANT_LIB_EXT1__      1
#define __DARWIN_C_LEVEL            __DARWIN_C_FULL

#include <stdint.h>                 /* intXX_t, int_leastXX_t, INT_C, MIN, MAX */
#include <stddef.h>                 /* ptrdiff_t, size_t, rsize_t, wchar_t */
#include <stdatomic.h>              /* atomic_XXX - C11 atomic type and functions */
#include <stdbool.h>                /* true, false */
#include <stdarg.h>                 /* va_XXX - variable argument support */
#include <float.h>                  /* [FLT,DBL,LDBL] MIN, MAX, DIG, EPSILON - Floating point constants */

MSVC_PRAGMA(warning( pop ))

#undef NULL                         /* stddef.h */

#if !defined(__cplusplus)
    #define nullptr 0
#endif

#if !defined(__STDC_LIB_EXT1__)
    #warning Annex K extensions not available
#endif

/*# !defined(TgCOMPILE__NO_SYSTEM_HEADERS) || defined(TgCOMPILE__DOXYGEN_BUILD) */
#endif


/* =============================================================================================================================================================================== */
#endif
