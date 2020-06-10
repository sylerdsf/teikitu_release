/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - Defines [Code].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_DEFINES_CODE_H)
#define TGS_COMMON_BASE_DEFINES_CODE_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

CLANG_PRAGMA( system_header )

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Language Flags                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define __STDC_WANT_LIB_EXT1__              1
#define __DARWIN_C_LEVEL                    __DARWIN_C_FULL


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Code Constants                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgCOMPILE_MEM_MALLOC_PATTERN        0xEB
#define TgCOMPILE_MEM_FREE_PATTERN          0xFA

#define KTgID__INVALID_VALUE                UINT64_C(-1)


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Memory Tracking                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if defined(TgCOMPILE__FORCE_C_MEMORY_ALLOCATION) && (TgCOMPILE__FORCE_C_MEMORY_ALLOCATION >= 1)
    #define TgMALLOC_EXACT(A)                   malloc( A )
    #define TgFREE__EXACT(A)                    free( A )
    #define TgMALLOC_POOL(A)                    malloc( A )
    #define TgFREE_POOL(A)                      free( A )
    #define TgREALLOC_POOL(A,B)                 realloc( A, B )
    #define TgRESERVE_VIRTUAL(A)                malloc( A )
    #define TgCOMMIT_VIRTUAL(A,B)               A
    #define TgFREE_VIRTUAL(A)                   free( A )
    #define TgMALLOC_TEMP(A)                    malloc( A )
    #define TgFREE_TEMP(A)                      free( A )

#elif defined(TgCOMPILE__MEM_TRACK) && (TgCOMPILE__MEM_TRACK >= 1)
    #define TgMALLOC_EXACT(A)                   tgMM_Malloc_With_Trace( ETgMM_ALLOCATOR_OS, A, __FILE__, __LINE__ )
    #define TgFREE__EXACT(A)                    tgMM_Free_With_Trace( ETgMM_ALLOCATOR_OS, A, __FILE__, __LINE__ )
    #define TgMALLOC_POOL(A)                    tgMM_Malloc_With_Trace( ETgMM_ALLOCATOR_POOL, A, __FILE__, __LINE__ )
    #define TgFREE_POOL(A)                      tgMM_Free_With_Trace( ETgMM_ALLOCATOR_POOL, A, __FILE__, __LINE__ )
    #define TgREALLOC_POOL(A,B)                 tgMM_Realloc_With_Trace( ETgMM_ALLOCATOR_POOL, A, B, __FILE__, __LINE__ )
    #define TgMALLOC_TEMP(A)                    tgMM_Malloc( ETgMM_ALLOCATOR_POOL, A )
    #define TgFREE_TEMP(A)                      tgMM_Free( ETgMM_ALLOCATOR_POOL, A )

    #define TgRESERVE_VIRTUAL(A)                tgMM_Reserve_With_Trace( ETgMM_ALLOCATOR_OS, A, __FILE__, __LINE__ )
    #define TgCOMMIT_VIRTUAL(A,B)               tgMM_Commit_With_Trace( ETgMM_ALLOCATOR_OS, A, B, __FILE__, __LINE__ )
    #define TgFREE_VIRTUAL(A)                   tgMM_Free_With_Trace( ETgMM_ALLOCATOR_OS, A, __FILE__, __LINE__ )
#else
    #define TgMALLOC_EXACT(A)                   tgMM_Malloc( ETgMM_ALLOCATOR_OS, A )
    #define TgFREE__EXACT(A)                    tgMM_Free( ETgMM_ALLOCATOR_OS, A )
    #define TgMALLOC_POOL(A)                    tgMM_Malloc( ETgMM_ALLOCATOR_POOL, A )
    #define TgFREE_POOL(A)                      tgMM_Free( ETgMM_ALLOCATOR_POOL, A )
    #define TgREALLOC_POOL(A,B)                 tgMM_Realloc( ETgMM_ALLOCATOR_POOL, A, B )
    #define TgMALLOC_TEMP(A)                    tgMM_Malloc( ETgMM_ALLOCATOR_POOL, A )
    #define TgFREE_TEMP(A)                      tgMM_Free( ETgMM_ALLOCATOR_POOL, A )

    #define TgRESERVE_VIRTUAL(A)                tgMM_Reserve( ETgMM_ALLOCATOR_OS, A )
    #define TgCOMMIT_VIRTUAL(A,B)               tgMM_Commit( ETgMM_ALLOCATOR_OS, A, B )
    #define TgFREE_VIRTUAL(A)                   tgMM_Free( ETgMM_ALLOCATOR_OS, A )
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Unique Identifiers                                                                                                                                                             */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgKI_DECLARE(A)                                                                                                                                                             \
                                                                                                                                                                                    \
    typedef union                                                                                                                                                                   \
    {                                                                                                                                                                               \
        TgUINT_E64 TgALIGN(8)                   m_uiKI;                                                                                                                             \
        struct {                                                                                                                                                                    \
            TgUINT_E32                                  m_uiK;                                                                                                                      \
            TgUINT_E32                                  m_uiI;                                                                                                                      \
        };                                                                                                                                                                          \
    } Tg##A;                                                                                                                                                                        \
    TgTYPE_MODIFIER_ALL( Tg##A );                                                                                                                                                   \
                                                                                                                                                                                    \
    typedef struct                                                                                                                                                                  \
    {                                                                                                                                                                               \
        TgUINT_E64_A TgALIGN(8)                 m_uiKI;                                                                                                                             \
    } Tg##A##_SINGLETON;                                                                                                                                                            \
    TgTYPE_MODIFIER_DEFAULT( Tg##A##_SINGLETON );                                                                                                                                   \
                                                                                                                                                                                    \
    TgEXTN Tg##A##_C KTg##A##__INVALID;                                                                                                                                             \
    TgEXTN TgUINT_F32_A tgKI_NUI_##A;                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE Tg##A tg##A##_Init( Tg##A##_SINGLETON_PCU psKI, TgUINT_F32_C uiI )                                                                                                \
    {                                                                                                                                                                               \
        Tg##A                                sInit;                                                                                                                                 \
        sInit.m_uiK = atomic_fetch_add( &(tgKI_NUI_##A), 1 );                                                                                                                       \
        sInit.m_uiI = uiI;                                                                                                                                                          \
        atomic_store( &(psKI->m_uiKI), sInit.m_uiKI );                                                                                                                              \
        return (sInit);                                                                                                                                                             \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE TgVOID tg##A##_Store( Tg##A##_SINGLETON_PCU psK0, Tg##A##_C sK1 )                                                                                                 \
    {                                                                                                                                                                               \
        atomic_store( &(psK0->m_uiKI), sK1.m_uiKI );                                                                                                                                \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE TgVOID tg##A##_Invalidate( Tg##A##_SINGLETON_PCU psK0 )                                                                                                           \
    {                                                                                                                                                                               \
        atomic_store( &(psK0->m_uiKI), KTgID__INVALID_VALUE );                                                                                                                      \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE TgVOID tg##A##_Load( Tg##A##_PCU psK0, Tg##A##_SINGLETON_PCU psK1 )                                                                                               \
    {                                                                                                                                                                               \
        psK0->m_uiKI = atomic_load( &(psK1->m_uiKI) );                                                                                                                              \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE Tg##A tg##A##_Query_Unsafe( Tg##A##_SINGLETON_CPCU psK1 )                                                                                                         \
    {                                                                                                                                                                               \
        Tg##A                                sInit;                                                                                                                                 \
        sInit.m_uiKI = atomic_load( &(psK1->m_uiKI) );                                                                                                                              \
        return (sInit);                                                                                                                                                             \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE TgVOID tg##A##_Load_U64( TgUINT_F64_PCU puiKI, Tg##A##_SINGLETON_PCU psK1 )                                                                                       \
    {                                                                                                                                                                               \
        *puiKI = atomic_load( &(psK1->m_uiKI) );                                                                                                                                    \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE TgBOOL tg##A##_Fetch_And_Is_Valid( Tg##A##_P psK1, Tg##A##_SINGLETON_PCU psK0 )                                                                                   \
    {                                                                                                                                                                               \
        Tg##A                                sInit;                                                                                                                                 \
                                                                                                                                                                                    \
        if (nullptr == psK1)                                                                                                                                                        \
        {                                                                                                                                                                           \
            psK1 = &sInit;                                                                                                                                                          \
        };                                                                                                                                                                          \
                                                                                                                                                                                    \
        psK1->m_uiKI = KTg##A##__INVALID.m_uiKI;                                                                                                                                    \
                                                                                                                                                                                    \
        return (atomic_compare_exchange_strong( &(psK0->m_uiKI), &psK1->m_uiKI, psK1->m_uiKI) ? false : true);                                                                      \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE TgBOOL tg##A##_Is_Equal_Test( Tg##A##_SINGLETON_PCU psK0, Tg##A##_SINGLETON_PCU psK1 )                                                                            \
    {                                                                                                                                                                               \
        Tg##A                                sInit;                                                                                                                                 \
        sInit.m_uiKI = atomic_load( &(psK1->m_uiKI) );                                                                                                                              \
        return (atomic_compare_exchange_strong( &(psK0->m_uiKI), &sInit.m_uiKI, sInit.m_uiKI));                                                                                     \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE TgBOOL tg##A##_Is_Equal_U64( Tg##A##_SINGLETON_PCU psK0, TgUINT_E64 uiKI )                                                                                        \
    {                                                                                                                                                                               \
        return (atomic_compare_exchange_strong( &(psK0->m_uiKI), &uiKI, uiKI));                                                                                                     \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    TgFORCEINLINE TgBOOL tg##A##_Is_Equal( Tg##A##_SINGLETON_PCU psK0, Tg##A sK1 )                                                                                                  \
    {                                                                                                                                                                               \
        return (atomic_compare_exchange_strong( &(psK0->m_uiKI), &sK1.m_uiKI, sK1.m_uiKI));                                                                                         \
    }

#define TgKI_DEFINE(A)                                                                                                                                                              \
    TgUINT_F32_A tgKI_NUI_##A;                                                                                                                                                      \
    Tg##A##_C KTg##A##__INVALID = { KTgID__INVALID_VALUE }


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Utility macro to allow for default arguments                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @see <a href="https://stackoverflow.com/questions/3046889/optional-parameters-with-c-macros">Original Source</a> */
#define FUNC_CHOOSER(_f0, _f1, _f2, _f3, _f4, _f5, _f6, _f7, _f8, _f9, _f10, _f11, _f12, _f13, _f14, _f15, _f16, ...) _f16
#define FUNC_RECOMPOSER(argsWithParentheses) FUNC_CHOOSER argsWithParentheses
#define CHOOSE_FROM_ARG_COUNT(F, ...) FUNC_RECOMPOSER((__VA_ARGS__, \
            F##_16, F##_15, F##_14, F##_13, F##_12, F##_11, F##_10, F##_9, F##_8,\
            F##_7, F##_6, F##_5, F##_4, F##_3, F##_2, F##_1, ))
#define NO_ARG_EXPANDER(FUNC) ,,,,,,,,,,,,,,,,FUNC ## _0
#define MACRO_CHOOSER(FUNC, ...) CHOOSE_FROM_ARG_COUNT(FUNC, NO_ARG_EXPANDER __VA_ARGS__ (FUNC))
#define MULTI_MACRO(FUNC, ...) MACRO_CHOOSER(FUNC, __VA_ARGS__)(__VA_ARGS__)



/* =============================================================================================================================================================================== */
#endif
