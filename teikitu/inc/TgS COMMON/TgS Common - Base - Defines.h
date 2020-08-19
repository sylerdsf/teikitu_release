/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - Defines.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_DEFINES_H)
#define TGS_COMMON_BASE_DEFINES_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Early Compilation Validations                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if __STDC_VERSION__ < 201112L
    #error Codebase developed and tested against C11
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Include Concatenation Macros                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgMACRO_SZ(A)                       #A

#define TgMACRO_CONCATA_(A,B,C,D,E,F,G,H,I,J) A##B##C##D##E##F##G##H##I##J
#define TgMACRO_CONCATA(A,B,C,D,E,F,G,H,I,J) TgMACRO_CONCATA_(A,B,C,D,E,F,G,H,I,J)
#define TgMACRO_CONCAT9_(A,B,C,D,E,F,G,H,I) A##B##C##D##E##F##G##H##I
#define TgMACRO_CONCAT9(A,B,C,D,E,F,G,H,I)  TgMACRO_CONCAT9_(A,B,C,D,E,F,G,H,I)
#define TgMACRO_CONCAT8_(A,B,C,D,E,F,G,H)   A##B##C##D##E##F##G##H
#define TgMACRO_CONCAT8(A,B,C,D,E,F,G,H)    TgMACRO_CONCAT8_(A,B,C,D,E,F,G,H)
#define TgMACRO_CONCAT7_(A,B,C,D,E,F,G)     A##B##C##D##E##F##G
#define TgMACRO_CONCAT7(A,B,C,D,E,F,G)      TgMACRO_CONCAT7_(A,B,C,D,E,F,G)
#define TgMACRO_CONCAT6_(A,B,C,D,E,F)       A##B##C##D##E##F
#define TgMACRO_CONCAT6(A,B,C,D,E,F)        TgMACRO_CONCAT6_(A,B,C,D,E,F)
#define TgMACRO_CONCAT5_(A,B,C,D,E)         A##B##C##D##E
#define TgMACRO_CONCAT5(A,B,C,D,E)          TgMACRO_CONCAT5_(A,B,C,D,E)
#define TgMACRO_CONCAT4_(A,B,C,D)           A##B##C##D
#define TgMACRO_CONCAT4(A,B,C,D)            TgMACRO_CONCAT4_(A,B,C,D)
#define TgMACRO_CONCAT3_(A,B,C)             A##B##C
#define TgMACRO_CONCAT3(A,B,C)              TgMACRO_CONCAT3_(A,B,C)
#define TgMACRO_CONCAT2_(A,B)               A##B
#define TgMACRO_CONCAT2(A,B)                TgMACRO_CONCAT2_(A,B)

#define TgMACRO_CONCAT6_SZ_(A,B,C,D,E,F)    TgMACRO_SZ( A##B##C##D )
#define TgMACRO_CONCAT6_SZ(A,B,C,D,E,F)     TgMACRO_CONCAT6_SZ_(A,B,C,D,E,F)
#define TgMACRO_CONCAT5_SZ_(A,B,C,D,E)      TgMACRO_SZ( A##B##C##D )
#define TgMACRO_CONCAT5_SZ(A,B,C,D,E)       TgMACRO_CONCAT5_SZ_(A,B,C,D,E)
#define TgMACRO_CONCAT4_SZ_(A,B,C,D)        TgMACRO_SZ( A##B##C##D )
#define TgMACRO_CONCAT4_SZ(A,B,C,D)         TgMACRO_CONCAT4_SZ_(A,B,C,D)
#define TgMACRO_CONCAT3_SZ_(A,B,C)          TgMACRO_SZ( A##B##C )
#define TgMACRO_CONCAT3_SZ(A,B,C)           TgMACRO_CONCAT3_SZ_(A,B,C)
#define TgMACRO_CONCAT2_SZ_(A,B)            TgMACRO_SZ( A##B )
#define TgMACRO_CONCAT2_SZ(A,B)             TgMACRO_CONCAT2_SZ_(A,B)

#define TgHEADER_(A,B,C)                    TgMACRO_SZ(A (B) C )
#define TgHEADER_COMPILER(A,B)              TgHEADER_(A,TgBUILD_COMPILER,B)
#define TgHEADER_HARDWARE(A,B)              TgHEADER_(A,TgBUILD_HARDWARE,B)
#define TgHEADER_THREAD_SUPPORT(A,B)        TgHEADER_(A,TgCOMPILE_THREAD_SUPPORT,B)

#if defined(TgBUILD_UNIVERSAL)
#define TgHEADER_UNIVERSAL(A,B)             TgHEADER_(A,TgBUILD_UNIVERSAL,B)
#else
#define TgHEADER_UNIVERSAL(A,B)             TgERROR_NOT_IMPLEMENTED
#endif

#if defined(TgBUILD_OS)
#define TgHEADER_OPERATING_SYSTEM(A,B)      TgHEADER_(A,TgBUILD_OS,B)
#else
#define TgHEADER_OPERATING_SYSTEM(A,B)      TgERROR_NOT_IMPLEMENTED
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Include Define Specializations and Configurations                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#include "TgS COMMON/TgS Common - Base - Defines [Configuration].h"
#include TgHEADER_COMPILER(TgS COMMON/TgS,Common - Base - Defines [Compiler].h)
#include "TgS COMMON/TgS Common - Base - Defines [Hardware].h"
#include TgHEADER_THREAD_SUPPORT(TgS COMMON/TgS,Common - Base - Defines [Platform].h)
#include "TgS COMMON/TgS Common - Base - Defines [Code].h"
#include "TgS COMMON/TgS Common - Base - Defines [Text].h"


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Code Macros                                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgERROR_NOT_IMPLEMENTED             TgCOMPILER_ASSERT_MSG(false, "Not Implemented")
#define TgCOMPILE_PRINT_SIZE(A)             static char( *__kaboom )[sizeof( A )] = 1

#define TgMAKE_4CC(A,B,C,D)                 (TgUINT_E32)(((D & 0XFF) << 24) | ((C & 0XFF) << 16) | ((B & 0XFF) << 8) | ((A & 0XFF) << 0))
#define TgCOLOUR_FROM_RGBA(R,G,B,A)         (TgUINT_E32)(((A & 0XFF) << 24) | ((B & 0XFF) << 16) | ((G & 0XFF) << 8) | ((R & 0XFF) << 0))
#define TgCOLOUR_A(COL_U32)                 ((COL_U32 >> 24) & 0xFF)
#define TgCOLOUR_B(COL_U32)                 ((COL_U32 >> 16) & 0xFF)
#define TgCOLOUR_G(COL_U32)                 ((COL_U32 >>  8) & 0xFF)
#define TgCOLOUR_R(COL_U32)                 ((COL_U32      ) & 0xFF)


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Basic DEFINE routines                                                                                                                                                          */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgSAFE_RELEASE(p)                   { if ((p)) { (p)->Release(); (p)=nullptr; } };
#define TgSAFE_ASSIGN_REF( a, b )           { TgSAFE_RELEASE(a); if ( nullptr != (b) ) { (a) = (b); (a)->AddRef(); } };

#define TgPERM(A,B,C,D)                     ((D<<6) | (C<<4) | (B<<2) | A)

#define TgARRAY_COUNT(A)                    (sizeof(A) / sizeof(A[0]))

#if defined(__cplusplus)
    #define TgEXTN                              extern "C"
#else
    #define TgEXTN                              extern
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  ASSERTS                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if defined(_MSC_VER) && (_MSC_VER >= 1600) && defined(__cplusplus)
    #define TgCOMPILER_ASSERT(x,c)              static_assert(x,"")
#elif defined(TgBUILD_COMPILER__CLANG) && __has_extension(c_static_assert)
    #define TgCOMPILER_ASSERT(x,c)              _Static_assert(x,"")
#else
    #ifdef __COUNTER__
        #define TgCOMPILER_ASSERT(e,c)          typedef UNUSED_TYPE char TgMACRO_CONCAT3(COMPILER_ASSERT_,0,__COUNTER__)[(e) != 0]
    #else
        #define TgCOMPILER_ASSERT(e,c)          typedef UNUSED_TYPE char TgMACRO_CONCAT3(COMPILER_ASSERT_,c,__LINE__)[(e) != 0]
    #endif
#endif

#if TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__CRITICAL
    /* Critical validation is for things that would put the executable in an unstable and usable state.  These are important enough that they are left in the compilation
    even during a final build (one used for certification).  This will cause a break in a shipping product. */
    #define TgCRITICAL_MSG( A, ... )            TgANALYSIS_ASSUME(A);                                                                                                               \
                                                if (!(A))                                                                                                                           \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_CRITICAL|1, __VA_ARGS__ );                                                                            \
                                                    tgPM_Abort();                                                                                                                   \
                                                };

    #define TgCRITICAL_MSGF( A, ... )           TgANALYSIS_ASSUME(A);                                                                                                               \
                                                if (!(A))                                                                                                                           \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_CRITICAL|1, __VA_ARGS__ );                                                                            \
                                                    tgPM_Abort();                                                                                                                   \
                                                };

    #define TgCRITICAL( A )                     TgANALYSIS_ASSUME(A);                                                                                                               \
                                                if (!(A))                                                                                                                           \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_CRITICAL|1, #A "\n" );                                                                                \
                                                    tgPM_Abort();                                                                                                                   \
                                                };
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__CRITICAL */
#else
    #define TgCRITICAL_MSGF( A, ... )           TgANALYSIS_ASSUME(A); ((void)0)
    #define TgCRITICAL_MSG( A, ... )            TgANALYSIS_ASSUME(A); ((void)0)
    #define TgCRITICAL( A )                     TgANALYSIS_ASSUME(A); ((void)0)
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__CRITICAL */
#endif

#if TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__ERROR
    /* Asserts are used in release and debug executables when continuing execution is undesirable.  Most often this is the case similar to above, where the executable would be in
    an illegal state.  These are often used for bounds checking.  The difference is that asserts can be used to validate values and quantities during development that are "assumed"
    to be valid in a final build. */
    #define TgERROR_MSG( A, ... )               TgANALYSIS_ASSUME(A);                                                                                                               \
                                                if (!(A))                                                                                                                           \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_ERROR|1, __VA_ARGS__ );                                                                               \
                                                };

    #define TgERROR_MSGF( A, ... )              TgANALYSIS_ASSUME(A);                                                                                                               \
                                                if (!(A))                                                                                                                           \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_ERROR|1, __VA_ARGS__ );                                                                               \
                                                };

    #define TgERROR( A )                        TgANALYSIS_ASSUME(A);                                                                                                               \
                                                if (!(A))                                                                                                                           \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_ERROR|1, "%-16.16s(%-32.32s): %-64.64s\n", "SYSTEM", "ERROR", #A );                                   \
                                                };

    #define TgERROR_INDEX( A, B )               MSVC_ATTRIBUTE(__analysis_assume((A) < ( sizeof(B) / sizeof((B)[0]) )));                                                            \
                                                if ( ((TgRSIZE)(A)) >= ( sizeof(B) / sizeof((B)[0]) ) )                                                                             \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_ERROR|1, "%-16.16s(%-32.32s): %-64.64s\n", "SYSTEM", "ERROR", "Exceeded array length - " #A );        \
                                                };

/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__ERROR */
#else
    #define TgERROR_MSGF( A, ... )              TgANALYSIS_ASSUME(A); ((void)0)
    #define TgERROR_MSG( A, ... )               TgANALYSIS_ASSUME(A); ((void)0)
    #define TgERROR( A )                        TgANALYSIS_ASSUME(A); ((void)0)
    #define TgERROR_INDEX( A, B )               MSVC_ATTRIBUTE(__analysis_assume((A) < ( sizeof(B) / sizeof((B)[0]) )))
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__ERROR */
#endif

#if TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__PARAM_CHECK
    #define TgPARAM_CHECK_MSGF( A, ... )        TgERROR_MSGF( A, __VA_ARGS__ )
    #define TgPARAM_CHECK_MSG( A, ... )         TgERROR_MSG( A, __VA_ARGS__ )
    #define TgPARAM_CHECK( A )                  TgERROR( A )
    #define TgPARAM_CHECK_INDEX( A, B )         TgERROR_INDEX( A, B )
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__PARAM_CHECK */
#else
    #define TgPARAM_CHECK_MSGF( A, ... )        TgANALYSIS_ASSUME(A); ((void)0)
    #define TgPARAM_CHECK_MSG( A, ... )         TgANALYSIS_ASSUME(A); ((void)0)
    #define TgPARAM_CHECK( A )                  TgANALYSIS_ASSUME(A); ((void)0)
    #define TgPARAM_CHECK_INDEX( A, B )         MSVC_ATTRIBUTE(__analysis_assume((A) < ( sizeof(B) / sizeof((B)[0]) )))
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__PARAM_CHECK */
#endif

#if TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__DIAG
    #define TgDIAG_MSG( A, ... )                TgANALYSIS_ASSUME(A);                                                                                                               \
                                                {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if ((!bSkip) && !(A))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_ERROR|3, __VA_ARGS__ );                                                                           \
                                                    };                                                                                                                              \
                                                };

    #define TgDIAG_MSGF( A, ... )               TgANALYSIS_ASSUME(A);                                                                                                               \
                                                {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if ((!bSkip) && !(A))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_ERROR|3, __VA_ARGS__ );                                                                           \
                                                    };                                                                                                                              \
                                                };

    #define TgDIAG( A )                         TgANALYSIS_ASSUME(A);                                                                                                               \
                                                {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if ((!bSkip) && !(A))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_ERROR|3, "%-16.16s(%-32.32s): %-64.64s\n", "SYSTEM", "DIAG ASSERT", #A );                         \
                                                    };                                                                                                                              \
                                                };
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__DIAG */
#else
    #define TgDIAG_MSGF( A, ... )               TgANALYSIS_ASSUME(A); ((void)0)
    #define TgDIAG_MSG( A, ... )                TgANALYSIS_ASSUME(A); ((void)0)
    #define TgDIAG( A )                         TgANALYSIS_ASSUME(A); ((void)0)
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__DIAG */
#endif

#if TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__VERIFY
    #define TgVERIFY_MSG( A, ... )              TgANALYSIS_ASSUME(A);                                                                                                               \
                                                {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if (!(A) && (!bSkip))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_ERROR|4, __VA_ARGS__ );                                                                           \
                                                    };                                                                                                                              \
                                                };

    #define TgVERIFY_MSGF( A, ... )             TgANALYSIS_ASSUME(A);                                                                                                               \
                                                {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if (!(A) && (!bSkip))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_ERROR|4, __VA_ARGS__ );                                                                           \
                                                    };                                                                                                                              \
                                                };

    #define TgVERIFY( A )                       TgANALYSIS_ASSUME(A);                                                                                                               \
                                                {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if (!(A) && (!bSkip))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_ERROR|4, "%-16.16s(%-32.32s): Failed Validation: %-32.32s (File:% 5d) |\n",                       \
                                                            "SYSTEM", "ERROR", __FUNCTION__, __LINE__ );                                                                            \
                                                    };                                                                                                                              \
                                                };
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__VERIFY */
#else
    #define TgVERIFY_MSGF( A, ... )             TgANALYSIS_ASSUME(A); ((void)(A))
    #define TgVERIFY_MSG( A, ... )              TgANALYSIS_ASSUME(A); ((void)(A))
    #define TgVERIFY( A )                       TgANALYSIS_ASSUME(A); ((void)(A))
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__VERIFY */
#endif

#if TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__WARNING
    /* Warnings are used to communicate potential development issues to the console. */
    #define TgWARNING_MSG( A, ... )             {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if ((!bSkip) && !(A))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_WARNING, __VA_ARGS__ );                                                                           \
                                                    };                                                                                                                              \
                                                };

    #define TgWARNING_MSGF( A, ... )            {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if ((!bSkip) && !(A))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_WARNING, __VA_ARGS__ );                                                                           \
                                                    };                                                                                                                              \
                                                };

    #define TgWARNING( A )                      {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if ((!bSkip) && !(A))                                                                                                           \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_WARNING, "%-16.16s(%-32.32s): %-64.64s\n", "SYSTEM", "WARNING", #A );                             \
                                                    };                                                                                                                              \
                                                };
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__WARNING */
#else
    #define TgWARNING_MSGF( A, ... )            ((void)0)
    #define TgWARNING_MSG( A, ... )             ((void)0)
    #define TgWARNING( A )                      ((void)0)
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__WARNING */
#endif

#if TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__MESSAGE
    /* Messages are used to communicate general development information to the console */
    #define TgMSG( L, ... )                     {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if (!bSkip)                                                                                                                     \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_MESSAGE|L, __VA_ARGS__ );                                                                         \
                                                    };                                                                                                                              \
                                                };

    #define TgMSGF( L, ... )                    {                                                                                                                                   \
                                                    static TgBOOL bSkip = false;                                                                                                    \
                                                    if (!bSkip)                                                                                                                     \
                                                    {                                                                                                                               \
                                                        tgCN_PrintF( KTgCN_CHANEL_MESSAGE|L, __VA_ARGS__ );                                                                         \
                                                    };                                                                                                                              \
                                                };
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__MESSAGE */
#else
    #define TgMSGF( A, ... )                    ((void)0)
    #define TgMSG( A, ... )                     ((void)0)
/*# TgCOMPILE_ASSERT && TgCOMPILE_ASSERT__MESSAGE */
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Base TgS RESULT Values                                                                                                                                                         */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define MAKE_TgRESULT(fac,code)             ((TgSINT_F32) (((TgRESULT)(fac)<<16) | ((TgRESULT)(code))))
#define MAKE_ERROR(A,B)                     CTgERROR( __FILE__, __LINE__, A, B )

/* 64 Libraries, 256 Classes per Library, 262144 Functions per Class - 32 bits to describe overloads/parameters */
#define MAKE_CODE(lib,cls,fcn,pm)           ((TgUINT_E64) (((TgUINT_E64)(lib)) | ((TgUINT_E64)(cls) >> 6) | ((TgUINT_E64)(fcn) >> 14) | ((TgUINT_E64)(pm) >> 32) ))

#define TM_TIMER                            1L
#define TIME_MAXITERATIONS                  7


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Code Helpers                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgSUCCEEDED(Status)                 ((TgSINT_F32)(Status) >= 0)
#define TgFAILED(Status)                    ((TgSINT_F32)(Status) <  0)

#define TgFOURCC(ch0, ch1, ch2, ch3)        (((TgUINT_E32)(TgUINT_E08)(ch0)      ) | ((TgUINT_E32)(TgUINT_E08)(ch1) << 8  ) | \
                                             ((TgUINT_E32)(TgUINT_E08)(ch2) << 16) | ((TgUINT_E32)(TgUINT_E08)(ch3) << 24 ))

#if defined(TgCOMPILE_PLATFORM_TEXT__WIDE)
    #define TgOS_TEXT( A )                      L##A
#else
    #define TgOS_TEXT( A )                      A
#endif
#define TgOS_WIDEN( A )                     TgOS_TEXT(A)

#define TgTEST_MSG( A, ... )                {                                                                                                                                       \
                                                if (!(A))                                                                                                                           \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_ERROR, "FAILED: " (#A) "\n" );                                                                        \
                                                    tgPM_Break();                                                                                                                   \
                                                }                                                                                                                                   \
                                                else                                                                                                                                \
                                                {                                                                                                                                   \
                                                    tgCN_PrintF( KTgCN_CHANEL_MESSAGE, "PASSED: " (#A) "\n" );                                                                      \
                                                };                                                                                                                                  \
                                            };

#if defined(TgCOMPILE__GENERATE_LIST_OF_LITERALS)

    #define PRAGMA_MESSAGE__(A)                 _Pragma (#A)
    #define PRAGMA_MESSAGE_(A)                  PRAGMA_MESSAGE__(message ("TODO - " #A))
    #define PRAGMA_MESSAGE(A)                   PRAGMA_MESSAGE_(A)

#else

    #define PRAGMA_MESSAGE(A)

#endif

#define STRUCT_PAD(C,D)                       (TEMPLATE__TYPE_SIZE == 32) * (TEMPLATE__VECTOR_DIM == 4) * C                                                                         \
                                            + (TEMPLATE__TYPE_SIZE == 64) * (TEMPLATE__VECTOR_DIM == 4) * D



/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Type Declerations                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgTYPE_MODIFIER_PTR_DEFAULT(B)      typedef B *                                     B##_P;                                                                                  \
                                            typedef B const *                               B##_CP;                                                                                 \
                                            typedef B * const                               B##_PC;                                                                                 \
                                            typedef B const * const                         B##_CPC;                                                                                \
                                            typedef B **                                    B##_PP;                                                                                 \
                                            typedef B const **                              B##_CPP;                                                                                \
                                            typedef B ** const                              B##_PPC;                                                                                \
                                            typedef B const * const *                       B##_CPCP;                                                                               \
                                                                                                                                                                                    \
                                            typedef B * __restrict                          B##_PU;                                                                                 \
                                            typedef B const * __restrict                    B##_CPU;                                                                                \
                                            typedef B * __restrict const                    B##_PCU;                                                                                \
                                            typedef B const * __restrict const              B##_CPCU;                                                                               \
                                            typedef B ** __restrict                         B##_PPU;                                                                                \
                                            typedef B const ** __restrict                   B##_CPPU;                                                                               \
                                            typedef B ** __restrict const                   B##_PPCU;                                                                               \
                                            typedef B const * __restrict const *            B##_CPCPU

#define TgTYPE_MODIFIER_DEFAULT(B)          typedef B const                                 B##_C;                                                                                  \
                                            TgTYPE_MODIFIER_PTR_DEFAULT( B )

#define TgTYPE_MODIFIER_ATOMIC(B)           typedef B _Atomic volatile                      B##_A;                                                                                  \
                                            typedef B _Atomic volatile *                    B##_AP;                                                                                 \
                                            typedef B _Atomic volatile * __restrict         B##_APU;                                                                                \
                                            typedef B _Atomic volatile * __restrict const   B##_APCU

#define TgTYPE_MODIFIER_ALL(A)              TgTYPE_MODIFIER_DEFAULT( A );                                                                                                           \
                                            TgTYPE_MODIFIER_ATOMIC( A )

#define TgTYPE_DECLARE(A,B)                 typedef A                                       B;                                                                                      \
                                            TgTYPE_MODIFIER_ALL( B )

#define TgTYPE_FORWARD_STRUCT(A)            typedef struct A                                A;                                                                                      \
                                            TgTYPE_MODIFIER_DEFAULT( A )

#define TgTYPE_STRUCT( A, ...)              TgTYPE_STRUCT_( A, __VA_ARGS__ )
#define TgTYPE_STRUCT_(A, ...)              typedef struct A                                A;                                                                                      \
                                            TgTYPE_MODIFIER_DEFAULT( A );                                                                                                           \
                                            PRAGMA_MESSAGE(A) \
                                            __VA_ARGS__ struct A

#define TgTYPE_UNION( A, ...)               TgTYPE_UNION_( A, __VA_ARGS__ )
#define TgTYPE_UNION_(A, ...)               typedef union A                                 A;                                                                                      \
                                            TgTYPE_MODIFIER_DEFAULT( A );                                                                                                           \
                                            PRAGMA_MESSAGE(A)                                                                                                                       \
                                            __VA_ARGS__ union A

#define TgTYPE_ENUM(A,B,...)                typedef enum __attribute__((enum_extensibility(closed)))                                                                                \
                                            {                                                                                                                                       \
                                                __VA_ARGS__                                                                                                                         \
                                            } A##_ENUM;                                                                                                                             \
                                            TgTYPE_DECLARE( B, A )

#define TgTYPE_ENUM_FLAG(A,B,...)                typedef enum __attribute__((enum_extensibility(closed),flag_enum))                                                                 \
                                            {                                                                                                                                       \
                                                __VA_ARGS__                                                                                                                         \
                                            } A##_ENUM;                                                                                                                             \
                                            TgTYPE_DECLARE( B, A )


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Optimization Macros                                                                                                                                                            */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* Optimizer Hints */
#if !defined(TgS_NO_DEFAULT)
#if TgCOMPILE_ASSERT
    #define TgS_NO_DEFAULT(...) TgCRITICAL(0); __VA_ARGS__
#else
    #define TgS_NO_DEFAULT(...) __VA_ARGS__
#endif
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Macro Existence Check                                                                                                                                                          */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

//#if !defined(TgCOMPILE_LITTLE_ENDIAN)
//#error Token Undefined
//#endif

#if !defined(TgCOMPILE_FLOAT64)
#error Token Undefined
#endif

#if !defined(TgCOMPILE__SYSTEM_INFORMATION)
#error Token Undefined
#endif

#if !defined(TgCOMPILE__THREAD)
#error Token Undefined
#endif

#if !defined(TgCOMPILE__THREAD_LOCAL)
#error Token Undefined
#endif

#if !defined(TgCOMPILE__THREAD_INFO)
#error Token Undefined
#endif

#if !defined(TgCOMPILE__MEM_TRACK)
#error Token Undefined
#endif

#if !defined(TgCOMPILE_ASSERT)
#error Token Undefined
#endif

#if !defined(TgCOMPILE_ASSERT__CRITICAL)
#error Token Undefined
#endif

#if !defined(TgCOMPILE_ASSERT__ERROR)
#error Token Undefined
#endif

#if !defined(TgCOMPILE_ASSERT__PARAM_CHECK)
#error Token Undefined
#endif

#if !defined(TgCOMPILE_ASSERT__DIAG)
#error Token Undefined
#endif

#if !defined(TgCOMPILE_ASSERT__VERIFY)
#error Token Undefined
#endif

#if !defined(TgCOMPILE_ASSERT__WARNING)
#error Token Undefined
#endif

#if !defined(TgCOMPILE_ASSERT__MESSAGE)
#error Token Undefined
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Compilation Validations                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgCOMPILER_ASSERT( sizeof( void* ) == TgBUILD_HARDWARE__POINTER_SIZE, 0 );
TgCOMPILER_ASSERT( TgBUILD_HARDWARE__CPU_CACHE_LINE_SIZE >= TgBUILD_HARDWARE__POINTER_SIZE * 6, 0 );


/* =============================================================================================================================================================================== */
#endif
