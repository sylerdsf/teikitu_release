/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - Defines - Configuration.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_DEFINES_CONFIGURATION_H)
#define TGS_COMMON_BASE_DEFINES_CONFIGURATION_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

#define TgS_COPYRIGHT                       "Copyright (C) 2002-2020 Andrew Aye.  All Rights Reserved."

#define TGS_VERSION__MAJOR                  5
#define TGS_VERSION__MINOR                  11
#define TGS_VERSION__PATCH                  0
#define TGS_VERSION__TWEAK                  0

#define TGS_VERSION__API__NET               0
#define TGS_VERSION__API__CORE              0
#define TGS_VERSION__API                    0

#define TGS_VERSION__BUILD                  0

#define TgCOMPILE__SLOW_UNIT_TEST           1

#if defined(TGS_RELEASE)

    #define TgCOMPILE_ASSERT                    1
    #define TgCOMPILE_ASSERT__CRITICAL          1
    #define TgCOMPILE_ASSERT__ERROR             1
    #define TgCOMPILE_ASSERT__PARAM_CHECK       1
    #define TgCOMPILE_ASSERT__DIAG              1
    #define TgCOMPILE_ASSERT__VERIFY            1
    #define TgCOMPILE_ASSERT__WARNING           1
    #define TgCOMPILE_ASSERT__MESSAGE           1

    #define TgCOMPILE__MEM_TRACK                1
    #define TgCOMPILE__MEM_MALLOC_CLEAR         0
    #define TgCOMPILE__MEM_FREE_CLEAR           0

    #define TgCOMPILE_ASSERT__GEOM_PARAM_CHECK  0

    #define TgCOMPILE__STR_LENGTH_CHECK         1

    #define TgCOMPILE__CONSOLE                  1
    #define TgCOMPILE__CONSOLE_VAR_DEV          1
    #define TgCOMPILE__CONSOLE_DEBUG_OUTPUT     1
    #define TgCOMPILE__PROFILE                  1
    #define TgCOMPILE__THREAD_INFO              1
    #define TgCOMPILE__RENDER_DEBUG_OUTPUT      1

    #define TgCOMPILE__JOB_THREAD               (1 && TgCOMPILE__THREAD)
    #define TgCOMPILE__THREAD_RENDER            (1 && TgCOMPILE__JOB_THREAD)

    #define TgS_DEBUG__STATIC_MEMORY            1
    #define TgS_DEBUG__MEMORY                   1
    #define TgS_DEBUG__ENGINE                   1

    #define TgS_DEBUG__COMMON                   1
    #define TgS_DEBUG__COLLISION                1
    #define TgS_DEBUG__PARTITION                1
    #define TgS_DEBUG__PATH_AI                  1
    #define TgS_DEBUG__KERNEL                   1
    #define TgS_DEBUG__ANIMATION                1
    #define TgS_DEBUG__INPUT                    1
    #define TgS_DEBUG__PHYSICS                  1
    #define TgS_DEBUG__RENDER                   1
    #define TgS_DEBUG__SOUND                    1
    #define TgS_DEBUG__EFFECT                   1
    #define TgS_DEBUG__SET                      1
    #define TgS_DEBUG__SCRIPT                   1
    #define TgS_DEBUG__OBJECT                   1
    #define TgS_DEBUG__EXECUTE                  1
    #define TgS_DEBUG__UTILITY                  1

    #define TgS_STAT__COMMON                    1
    #define TgS_STAT__COLLISION                 1
    #define TgS_STAT__PARTITION                 1
    #define TgS_STAT__PATH_AI                   1
    #define TgS_STAT__KERNEL                    1
    #define TgS_STAT__ANIMATION                 1
    #define TgS_STAT__INPUT                     1
    #define TgS_STAT__PHYSICS                   1
    #define TgS_STAT__RENDER                    1
    #define TgS_STAT__SOUND                     1
    #define TgS_STAT__EFFECT                    1
    #define TgS_STAT__SET                       1
    #define TgS_STAT__SCRIPT                    1
    #define TgS_STAT__OBJECT                    1
    #define TgS_STAT__EXECUTE                   1

#elif defined(TGS_FINAL)

    #define TgCOMPILE_ASSERT                    0
    #define TgCOMPILE_ASSERT__CRITICAL          1
    #define TgCOMPILE_ASSERT__ERROR             1
    #define TgCOMPILE_ASSERT__PARAM_CHECK       1
    #define TgCOMPILE_ASSERT__DIAG              1
    #define TgCOMPILE_ASSERT__VERIFY            1
    #define TgCOMPILE_ASSERT__WARNING           1
    #define TgCOMPILE_ASSERT__MESSAGE           1
 
    #define TgCOMPILE__MEM_TRACK                0
    #define TgCOMPILE__MEM_MALLOC_CLEAR         0
    #define TgCOMPILE__MEM_FREE_CLEAR           0

    #define TgCOMPILE_ASSERT__GEOM_PARAM_CHECK  0

    #define TgCOMPILE__STR_LENGTH_CHECK         0

    #define TgCOMPILE__CONSOLE                  0
    #define TgCOMPILE__CONSOLE_VAR_DEV          0
    #define TgCOMPILE__CONSOLE_DEBUG_OUTPUT     0
    #define TgCOMPILE__PROFILE                  0
    #define TgCOMPILE__THREAD_INFO              0
    #define TgCOMPILE__RENDER_DEBUG_OUTPUT      0

    #define TgCOMPILE__JOB_THREAD               (1 && TgCOMPILE__THREAD)
    #define TgCOMPILE__THREAD_RENDER            (1 && TgCOMPILE__JOB_THREAD)

    #define TgS_DEBUG__STATIC_MEMORY            0
    #define TgS_DEBUG__MEMORY                   0
    #define TgS_DEBUG__ENGINE                   0

    #define TgS_DEBUG__COMMON                   0
    #define TgS_DEBUG__COLLISION                0
    #define TgS_DEBUG__PARTITION                0
    #define TgS_DEBUG__PATH_AI                  0
    #define TgS_DEBUG__KERNEL                   0
    #define TgS_DEBUG__ANIMATION                0
    #define TgS_DEBUG__INPUT                    0
    #define TgS_DEBUG__PHYSICS                  0
    #define TgS_DEBUG__RENDER                   0
    #define TgS_DEBUG__SOUND                    0
    #define TgS_DEBUG__EFFECT                   0
    #define TgS_DEBUG__SET                      0
    #define TgS_DEBUG__SCRIPT                   0
    #define TgS_DEBUG__OBJECT                   0
    #define TgS_DEBUG__EXECUTE                  0
    #define TgS_DEBUG__UTILITY                  0

    #define TgS_STAT__COMMON                    0
    #define TgS_STAT__COLLISION                 0
    #define TgS_STAT__PARTITION                 0
    #define TgS_STAT__PATH_AI                   0
    #define TgS_STAT__KERNEL                    0
    #define TgS_STAT__ANIMATION                 0
    #define TgS_STAT__INPUT                     0
    #define TgS_STAT__PHYSICS                   0
    #define TgS_STAT__RENDER                    0
    #define TgS_STAT__SOUND                     0
    #define TgS_STAT__EFFECT                    0
    #define TgS_STAT__SET                       0
    #define TgS_STAT__SCRIPT                    0
    #define TgS_STAT__OBJECT                    0
    #define TgS_STAT__EXECUTE                   0

#elif defined(TGS_DEBUG)

    #define TgCOMPILE_ASSERT                    1
    #define TgCOMPILE_ASSERT__CRITICAL          1
    #define TgCOMPILE_ASSERT__ERROR             1
    #define TgCOMPILE_ASSERT__PARAM_CHECK       1
    #define TgCOMPILE_ASSERT__DIAG              1
    #define TgCOMPILE_ASSERT__VERIFY            1
    #define TgCOMPILE_ASSERT__WARNING           1
    #define TgCOMPILE_ASSERT__MESSAGE           1

    #define TgCOMPILE__MEM_TRACK                1
    #define TgCOMPILE__MEM_MALLOC_CLEAR         1
    #define TgCOMPILE__MEM_FREE_CLEAR           1

    #define TgS_COMPILE__MEMORY_TRACE           1
    #define TgS_COMPILE__LOCK_TRACE             1

    #define TgCOMPILE_ASSERT__GEOM_PARAM_CHECK  1

    #define TgCOMPILE__STR_LENGTH_CHECK         1

    #define TgCOMPILE__CONSOLE                  1
    #define TgCOMPILE__CONSOLE_VAR_DEV          1
    #define TgCOMPILE__CONSOLE_DEBUG_OUTPUT     1
    #define TgCOMPILE__PROFILE                  1
    #define TgCOMPILE__THREAD_INFO              1
    #define TgCOMPILE__RENDER_DEBUG_OUTPUT      1

    #define TgCOMPILE__JOB_THREAD               (1 && TgCOMPILE__THREAD)
    #define TgCOMPILE__THREAD_RENDER            (1 && TgCOMPILE__JOB_THREAD)

    #define TgS_DEBUG__STATIC_MEMORY            1
    #define TgS_DEBUG__MEMORY                   1
    #define TgS_DEBUG__ENGINE                   1

    #define TgS_DEBUG__COMMON                   1
    #define TgS_DEBUG__COLLISION                1
    #define TgS_DEBUG__PARTITION                1
    #define TgS_DEBUG__PATH_AI                  1
    #define TgS_DEBUG__KERNEL                   1
    #define TgS_DEBUG__ANIMATION                1
    #define TgS_DEBUG__INPUT                    1
    #define TgS_DEBUG__PHYSICS                  1
    #define TgS_DEBUG__RENDER                   1
    #define TgS_DEBUG__SOUND                    1
    #define TgS_DEBUG__EFFECT                   1
    #define TgS_DEBUG__SET                      1
    #define TgS_DEBUG__SCRIPT                   1
    #define TgS_DEBUG__OBJECT                   1
    #define TgS_DEBUG__EXECUTE                  1
    #define TgS_DEBUG__UTILITY                  1

    #define TgS_STAT__COMMON                    1
    #define TgS_STAT__COLLISION                 1
    #define TgS_STAT__PARTITION                 1
    #define TgS_STAT__PATH_AI                   1
    #define TgS_STAT__KERNEL                    1
    #define TgS_STAT__ANIMATION                 1
    #define TgS_STAT__INPUT                     1
    #define TgS_STAT__PHYSICS                   1
    #define TgS_STAT__RENDER                    1
    #define TgS_STAT__SOUND                     1
    #define TgS_STAT__EFFECT                    1
    #define TgS_STAT__SET                       1
    #define TgS_STAT__SCRIPT                    1
    #define TgS_STAT__OBJECT                    1
    #define TgS_STAT__EXECUTE                   1

#elif defined(TGS_TOOLS)

    #define TgCOMPILE_ASSERT                    1
    #define TgCOMPILE_ASSERT__CRITICAL          1
    #define TgCOMPILE_ASSERT__ERROR             1
    #define TgCOMPILE_ASSERT__PARAM_CHECK       1
    #define TgCOMPILE_ASSERT__DIAG              1
    #define TgCOMPILE_ASSERT__VERIFY            1
    #define TgCOMPILE_ASSERT__WARNING           1
    #define TgCOMPILE_ASSERT__MESSAGE           1

    #define TgCOMPILE__MEM_TRACK                1
    #define TgCOMPILE__MEM_MALLOC_CLEAR         1
    #define TgCOMPILE__MEM_FREE_CLEAR           1

    #define TgCOMPILE_ASSERT__GEOM_PARAM_CHECK  1

    #define TgCOMPILE__STR_LENGTH_CHECK         1

    #define TgCOMPILE__CONSOLE                  1
    #define TgCOMPILE__CONSOLE_VAR_DEV          1
    #define TgCOMPILE__CONSOLE_DEBUG_OUTPUT     1
    #define TgCOMPILE__PROFILE                  1
    #define TgCOMPILE__THREAD_INFO              1
    #define TgCOMPILE__RENDER_DEBUG_OUTPUT      1

    #define TgCOMPILE__JOB_THREAD              (1 && TgCOMPILE__THREAD)
    #define TgCOMPILE__THREAD_RENDER           (1 && TgCOMPILE__JOB_THREAD)

    #define TgS_DEBUG__STATIC_MEMORY            1
    #define TgS_DEBUG__MEMORY                   1
    #define TgS_DEBUG__ENGINE                   1

    #define TgS_DEBUG__COMMON                   1
    #define TgS_DEBUG__COLLISION                1
    #define TgS_DEBUG__PARTITION                1
    #define TgS_DEBUG__PATH_AI                  1
    #define TgS_DEBUG__KERNEL                   1
    #define TgS_DEBUG__ANIMATION                1
    #define TgS_DEBUG__INPUT                    1
    #define TgS_DEBUG__PHYSICS                  1
    #define TgS_DEBUG__RENDER                   1
    #define TgS_DEBUG__SOUND                    1
    #define TgS_DEBUG__EFFECT                   1
    #define TgS_DEBUG__SET                      1
    #define TgS_DEBUG__SCRIPT                   1
    #define TgS_DEBUG__OBJECT                   1
    #define TgS_DEBUG__EXECUTE                  1
    #define TgS_DEBUG__UTILITY                  1

    #define TgS_STAT__COMMON                    1
    #define TgS_STAT__COLLISION                 1
    #define TgS_STAT__PARTITION                 1
    #define TgS_STAT__PATH_AI                   1
    #define TgS_STAT__KERNEL                    1
    #define TgS_STAT__ANIMATION                 1
    #define TgS_STAT__INPUT                     1
    #define TgS_STAT__PHYSICS                   1
    #define TgS_STAT__RENDER                    1
    #define TgS_STAT__SOUND                     1
    #define TgS_STAT__EFFECT                    1
    #define TgS_STAT__SET                       1
    #define TgS_STAT__SCRIPT                    1
    #define TgS_STAT__OBJECT                    1
    #define TgS_STAT__EXECUTE                   1

#else

    #error Unknown Configuration

#endif


/* Special Build Flags */
#define TgCOMPILE_VIEWER_BUILD                  0
#define TgCOMPILE_TOOL_BUILD                    0
#define TgCOMPILE__NON_NATIVE_VECTOR_AS_NATIVE  1


/* =============================================================================================================================================================================== */
#endif
