/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (CLANG) Common - Base - Defines [Compiler].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_DEFINES_COMPILER_CLANG_H)
#define TGS_COMMON_BASE_DEFINES_COMPILER_CLANG_H
#pragma once

#if !defined(TgBUILD_COMPILER__CLANG)
    #error Build arguments do not indicate this compiler
#endif


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Warnings and Messages                                                                                                                                                          */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#pragma clang diagnostic ignored "-W#pragma-messages"               /* Build and Compiler (and Data, Time) are injected as part of the compile */
#pragma clang diagnostic ignored "-W#warnings"                      /* Build and Compiler (and Data, Time) are injected as part of the compile */
#pragma clang diagnostic ignored "-Wextra-semi-stmt"                /* Disable warnings about extra semi-colons */
#pragma clang diagnostic ignored "-Wunused-parameter"               /* use of old-style cast - triggers on CXX compilation */
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"          /* Triggers because of variadic macros */
#pragma clang diagnostic ignored "-Wc99-compat"                     /* Triggers because of unicode literals */
#pragma clang diagnostic ignored "-Wnullability-extension"          /* Allows for marking pointers (normally function parameters) as being non null to help static analysis */
#pragma clang diagnostic ignored "-Wnullability-completeness"       /* Prevents warning on incomplete labeling of pointers */
#pragma clang diagnostic ignored "-Wdocumentation-unknown-command"  /* Xcode lacks support for some of the doxygen commands */
//#pragma clang diagnostic ignored "-Wundefined-internal"

#if defined(__cplusplus)
    #pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Validations                                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if defined(__cplusplus) && __has_feature(cxx_unicode_literals)
#error Require unicode literals for multibyte support (default for the platform)
#endif

#if !defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_16)
#error 128bit Compare and Swap is assumed for some of the lock free utility objects
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Configuration                                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgCOMPILE__BOUNDS_CHECKING_FCNS     0
#define TgCOMPILE__THREAD                   1

#if __has_feature(c_thread_local)
    #define TgCOMPILE__THREAD_LOCAL             1
#else
    #define TgCOMPILE__THREAD_LOCAL             0
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Macros                                                                                                                                                                         */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define DIAG_STR(s) #s
#define DIAG_JOINSTR(x,y) DIAG_STR(x ## y)
#define DIAG_DO_PRAGMA(x) _Pragma (#x)
#define DIAG_PRAGMA(x) DIAG_DO_PRAGMA(clang diagnostic x)

#define CLANG_ATTRIBUTE(...) __attribute__((__VA_ARGS__))
#define CLANG_COMMAND(...) __VA_ARGS__
#define CLANG_PRAGMA(x) DIAG_DO_PRAGMA(clang x)

#define UNUSED_PARAM __attribute__((unused))
#define UNUSED_FUNC __attribute__((unused))
#define UNUSED_TYPE __attribute__((unused))

#define MSVC_ATTRIBUTE(...)
#define MSVC_PRAGMA(...)

#define MSVC_WARN_SUPPRESS(msvc_unused)
#define MSVC_WARN_DISABLE_PUSH(msvc_unused)
#define MSVC_WARN_DISABLE_POP(msvc_unused)

#define CLANG_WARN_SUPPRESS(clang_option) DIAG_PRAGMA(ignored DIAG_JOINSTR(-W,clang_option))
#define CLANG_WARN_DISABLE_PUSH(clang_option) DIAG_PRAGMA(push) DIAG_PRAGMA(ignored DIAG_JOINSTR(-W,clang_option))
#define CLANG_WARN_DISABLE_POP(...) DIAG_PRAGMA(pop)

#define WARN_SUPPRESS(msvc_unused,clang_option) CLANG_WARN_SUPPRESS(clang_option)
#define WARN_DISABLE_PUSH(msvc_unused,clang_option) CLANG_WARN_DISABLE_PUSH(clang_option)
#define WARN_DISABLE_POP(...) CLANG_WARN_DISABLE_POP()

#define TgANALYSIS_ASSUME(...)

#if defined(__cplusplus)
    #define SWITCH_FALLTHROUGH CLANG_COMMAND([[clang::fallthrough]];)
#else
    #define SWITCH_FALLTHROUGH
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Keyword Replacements                                                                                                                                                           */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if __has_declspec_attribute(dllimport)
    #define DLL_IMPORT                          __declspec(dllimport) /* Import function from DLL */
#else
    #define DLL_IMPORT
#endif

#if __has_declspec_attribute(dllexport)
    #define DLL_EXPORT                          __declspec(dllexport) /* Export function to DLL */
#else
    #define DLL_EXPORT
#endif

#define CDECL                               __attribute__((__cdecl__)) /* Standard C function */
#define STDCALL                             __attribute__((__stdcall__)) /* Standard calling convention */
#define TgTLS                               _Thread_local
#define TgALIAS                             __attribute__((__may_alias__))

#if __has_builtin(__builtin_expect)
    #define TgEXPECT_TRUE(...)                  __builtin_expect( (__VA_ARGS__), 1 )
    #define TgEXPECT_FALSE(...)                 __builtin_expect( (__VA_ARGS__), 0 )
#else
    #define TgEXPECT_TRUE(...)                  (__VA_ARGS__)
    #define TgEXPECT_FALSE(...)                 (__VA_ARGS__)
#endif

#define TgPASSINREG                         
#define TgALIGN(A)                          _Alignas(A)

#if __has_attribute(always_inline)
    #define TgFORCEINLINE                       static __inline __attribute__((always_inline)) /* Force code to be inline */
#else
    #define TgFORCEINLINE                       static __inline
#endif
#define TgINLINE                            static __inline

#if TgCOMPILE_ASSERT
    #define TgS_NO_DEFAULT(...)                 TgCRITICAL(0); __VA_ARGS__
#else
    #if __has_builtin(__builtin_unreachable)
        #define TgS_NO_DEFAULT(...)                 __VA_ARGS__
    #else
        #define TgS_NO_DEFAULT(...)                 __builtin_unreachable(); __VA_ARGS__
    #endif
#endif

#if __has_builtin(__builtin_trap)
    #define TgBREAK_INLINE                      __builtin_trap()
#else
    #define TgBREAK_INLINE                      abort()
#endif

#define NONULL                              _Nonnull
#define OKNULL                              _Nullable


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Code Macros                                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgFREEA( VAR )
#define TgALLOCA( TYPE, COUNT, VAR )                                                                                                                                                \
{                                                                                                                                                                                   \
    VAR =  (TYPE *)__builtin_alloca( (COUNT) * sizeof(TYPE) );                                                                                                                      \
}


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Intrinsics                                                                                                                                                                     */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgCOMPILE__HARDWARE__BSF
#define tgPM__HARDWARE__BSF_U32 __builtin_ctz
#define tgPM__HARDWARE__BSF_U64 __builtin_ctzll


/* =============================================================================================================================================================================== */
#endif
