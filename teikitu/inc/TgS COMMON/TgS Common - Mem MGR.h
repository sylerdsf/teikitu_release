/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Mem MGR.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_MEMMGR_H)
#define TGS_COMMON_MEMMGR_H
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_MEMORY_MGR Memory Manager
    @ingroup TGS_COMMON_COMMON
*/

    /** @defgroup TGS_COMMON_MEMORY_MGR_MODULE Module Functions
        @ingroup TGS_COMMON_MEMORY_MGR
    */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Constants                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgTYPE_ENUM( ETgMM_ALLOCATOR, TgSINT_F32,
    ETgMM_ALLOCATOR_BEGIN = 0,
    ETgMM_ALLOCATOR_OS = ETgMM_ALLOCATOR_BEGIN,
    ETgMM_ALLOCATOR_POOL,
    ETgMM_ALLOCATOR_USER_0,
    ETgMM_ALLOCATOR_USER_1,
    ETgMM_ALLOCATOR_USER_2,
    ETgMM_ALLOCATOR_USER_3,
    ETgMM_ALLOCATOR_END,
    ETgMM_ALLOCATOR_COUNT = ETgMM_ALLOCATOR_END - ETgMM_ALLOCATOR_BEGIN
);


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#pragma pack(push,1)
TgTYPE_STRUCT(TgMEM_INFO_HEADER,)
{
    TgUINT_E32                                  m_uiSize;                                   /*  4 Bytes */
    union
    {
        TgUINT_E16                                  m_uiFlags;                                  /*  2 Bytes */
        struct
        {
            TgUINT_E16                                  m_bReserved : 1;
            TgUINT_E16                                  m_bPad : 15;
        };
    };
};
#pragma pack(pop)

TgTYPE_STRUCT(STg2_MM_MGR,)
{
    TgRESULT                                    (*m_pfnInit_MGR)( TgVOID );
    TgRESULT                                    (*m_pfnFree_MGR)( TgVOID );

#if TgS_STAT__COMMON
    TgVOID                                      (*m_pfnStats)( STg2_Output_PC );
#endif

                                                /** @brief Return the size of the memory region starting at ARG2
                                                    @param[out] OUT0 Pointer to hold the amount of reserved memory
                                                    @param[out] OUT1 Pointer to hold the amount of allocated memory
                                                    @param[in] ARG2 Pointer to the start of a reserved or allocated region of memory
                                                    @return KTgS_OK on success, and an error code otherwise */
    TgRESULT                                    (*m_pfnSize)( TgUINT_F32_P OUT0, TgUINT_F32_P OUT1, TgVOID_CPC ARG2 );

                                                /** @brief Allocate a region of memory (size ARG2)
                                                    @param[out] OUT0 Pointer to a memory information header
                                                    @param[out] OUT1 Returned pointer to the beginning of the requested allocated region of memory
                                                    @param[in] ARG2 Size of the region to allocate
                                                    @return KTgS_OK on success, and an error code otherwise */
    TgRESULT                                    (*m_pfnMalloc)( TgMEM_INFO_HEADER_P OUT0, TgVOID_PP OUT1, TgRSIZE_C ARG2 );

                                                /** @brief Allocate a region of memory (size ARG2)
                                                    @param[out] OUT0 Pointer to a memory information header
                                                    @param[out] OUT1 Returned pointer to the beginning of the requested reserved region of memory
                                                    @param[in] ARG2 Size of the region to reserve
                                                    @return KTgS_OK on success, and an error code otherwise */
    TgRESULT                                    (*m_pfnReserve)( TgMEM_INFO_HEADER_P ARG0, TgVOID_PP ARG1, TgRSIZE_C ARG2 );

                                                /** @brief Allocate a region of memory (size ARG2)
                                                    @param[out] OUT0 Pointer to a memory information header
                                                    @param[out] OUT1 Pointer to the start of the region to commit
                                                    @param[in] ARG2 Size of the region to commit
                                                    @return KTgS_OK on success, and an error code otherwise */
    TgRESULT                                    (*m_pfnCommit)( TgMEM_INFO_HEADER_P ARG0, TgVOID_PP ARG1, TgRSIZE_C ARG2 );

                                                /** @brief Allocate a region of memory (size ARG2)
                                                    @param[out] OUT0 Pointer to a memory information header
                                                    @param[in] ARG1 Pointer to a region of memory to free (deallocate)
                                                    @return KTgS_OK on success, and an error code otherwise */
    TgRESULT                                    (*m_pfnFree)( TgMEM_INFO_HEADER_P ARG0, TgVOID_PC ARG1 );

                                                /** @brief Allocate a region of memory (size ARG2)
                                                    @param[out] OUT0 Pointer to a memory information header for the new region of memory
                                                    @param[out] OUT1 Returned pointer to the beginning of the requested allocated region of memory
                                                    @param[out] OUT2 Pointer to a memory information header for the original region of memory
                                                    @param[in] ARG3 Pointer to the original region of memory
                                                    @param[in] ARG4 Size of the region to allocate
                                                    @return KTgS_OK on success, and an error code otherwise */
    TgRESULT                                    (*m_pfnRealloc)( TgMEM_INFO_HEADER_P OUT0, TgVOID_PP OUT1, TgMEM_INFO_HEADER_P OUT2, TgVOID_PC ARG3, TgRSIZE_C ARG4 );

    TgVOID                                      (*m_pfnClear_Thread_Local_Cache)( TgVOID );
};


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* #REVIEW: Do we need a way to segment | heap the allocations - maybe include the FAC code with each allocation request? */

/** @addtogroup TGS_COMMON_MEMORY_MGR_MODULE */
/** @{ */

TgEXTN TgRESULT                             tgMM_Init_MGR( TgVOID );
TgEXTN TgRESULT                             tgMM_Boot_MGR( TgVOID );
TgEXTN TgRESULT                             tgMM_Stop_MGR( TgVOID );
TgEXTN TgRESULT                             tgMM_Free_MGR( TgVOID );
TgEXTN TgRESULT                             tgMM_Update_MGR( TgFLOAT32_C );

TgEXTN TgSIZE_ALL                           tgMM_Query_Fixed_Memory( TgVOID );

TgEXTN TgBOOL                               tgMM_Query_Init( TgVOID );
TgEXTN TgBOOL                               tgMM_Query_Boot( TgVOID );

/** @} TGS_COMMON_MEMORY_MGR_MODULE */


/** @addtogroup TGS_COMMON_MEMORY_MGR */
/** @{ */
                                            /** @brief Return the memory page size used by the manager
                                                @return The memory page size used by the manager */
TgEXTN TgUINT_F32                           tgMM_Page_Size( TgVOID );

                                            /** @brief Register an allocator for use through the memory manager
                                                @param[in] ARG0 The allocator enumeration to be associated with the allocator
                                                @param[in] ARG1 Definition of a memory allocator */
TgEXTN TgVOID                               tgMM_Register_Allocator( ETgMM_ALLOCATOR_C ARG0, STg2_MM_MGR_P ARG1 );

                                            /** @brief Return all thread local resources back to global management */
TgEXTN TgVOID                               tgMM_Clear_Thread_Local_Cache( TgVOID );

#if TgS_STAT__COMMON
                                            /** @brief Output the stats for the memory manager
                                                @param[in,out] ARG Pointer to an output object */
TgEXTN TgVOID                               tgMM_Stats( STg2_Output_PC ARG );
/*# TgS_STAT__COMMON */
#endif


                                            /** @brief Return the size of the memory region that was allocated beginning at ARG1
                                                @param[in] ARG0 Memory allocator to be used for the function call
                                                @param[in] ARG1 Pointer to the start of a region of memory that was allocated
                                                @return The size of the memory region that was allocated beginning at ARG */
TgEXTN TgSIZE_ALL                           tgMM_Size( ETgMM_ALLOCATOR_C ARG0, TgVOID_CPC ARG1 );

                                            /** @brief Allocate a region of memory (size ARG1)
                                                @param[in] ARG0 Memory allocator to be used for the function call
                                                @param[in] ARG1 Size of the region to allocate
                                                @return Pointer to the allocated memory region on success and nullptr otherwise */
TgEXTN TgVOID_P                             tgMM_Malloc( ETgMM_ALLOCATOR_C ARG0, TgRSIZE_C ARG1 );

                                            /** @copydoc tgMM_Malloc
                                                @param[in] ARG2 Filename of the source file of the caller
                                                @param[in] ARG3 Line number in the file of the call */
TgEXTN TgVOID_P                             tgMM_Malloc_With_Trace( ETgMM_ALLOCATOR_C ARG0, TgRSIZE_C ARG1, TgCHAR_MB_CPC ARG2, TgUINT_E32_C ARG3 );

                                            /** @brief Reserves a memory address range (of size ARG1)
                                                @param[in] ARG0 Memory allocator to be used for the function call
                                                @param[in] ARG1 Size of the region to reserve
                                                @return Pointer to the reserved memory region on success and nullptr otherwise */
TgEXTN TgVOID_P                             tgMM_Reserve( ETgMM_ALLOCATOR_C ARG0, TgRSIZE_C ARG1 );

                                            /** @copydoc tgMM_Reserve
                                                @param[in] ARG2 Filename of the source file of the caller
                                                @param[in] ARG3 Line number in the file of the call */
TgEXTN TgVOID_P                             tgMM_Reserve_With_Trace( ETgMM_ALLOCATOR_C ARG0, TgRSIZE_C ARG1, TgCHAR_MB_CPC ARG2, TgUINT_E32_C ARG3 );

                                            /** @brief Commits ARG2 amount of memory from a reserved range
                                                @param[in] ARG0 Memory allocator to be used for the function call
                                                @param[in] ARG1 Pointer to the start of the region to commit
                                                @param[in] ARG2 Size of the region to commit
                                                @return Pointer to the start of the region committed and nullptr otherwise */
TgEXTN TgVOID_P                             tgMM_Commit( ETgMM_ALLOCATOR_C ARG0, TgVOID_P ARG1, TgRSIZE_C ARG2 );

                                            /** @copydoc tgMM_Commit
                                                @param[in] ARG3 Filename of the source file of the caller
                                                @param[in] ARG4 Line number in the file of the call */
TgEXTN TgVOID_P                             tgMM_Commit_With_Trace( ETgMM_ALLOCATOR_C ARG0, TgVOID_PC ARG1, TgRSIZE_C ARG2, TgCHAR_MB_CPC ARG3, TgUINT_E32_C ARG4 );

                                            /** @brief Frees all resources used by the allocation starting at ARG1
                                                @param[in] ARG0 Memory allocator to be used for the function call
                                                @param[in] ARG1 Pointer to the start of a region of memory that was reserved */
TgEXTN TgVOID                               tgMM_Free( ETgMM_ALLOCATOR_C ARG0, TgVOID_PC ARG1 );

                                            /** @copydoc tgMM_Free
                                                @param[in] ARG2 Filename of the source file of the caller
                                                @param[in] ARG3 Line number in the file of the call */
TgEXTN TgVOID                               tgMM_Free_With_Trace( ETgMM_ALLOCATOR_C ARG0, TgVOID_PC ARG1, TgCHAR_MB_CPC ARG2, TgUINT_E32_C ARG3 );

                                            /** @brief Reallocate the memory at ARG1 to a size of ARG2
                                                @param[in] ARG0 Memory allocator to be used for the function call
                                                @param[in] ARG1 Pointer to the start of the original region of memory
                                                @param[in] ARG2 Size of the new memory region
                                                @return Pointer to the start of the region allocated and nullptr otherwise  */
TgEXTN TgVOID_P                             tgMM_Realloc( ETgMM_ALLOCATOR_C ARG0, TgVOID_PC ARG1, TgRSIZE_C ARG2 );

                                            /** @copydoc tgMM_Realloc
                                                @param[in] ARG3 Filename of the source file of the caller
                                                @param[in] ARG4 Line number in the file of the call */
TgEXTN TgVOID_P                             tgMM_Realloc_With_Trace( ETgMM_ALLOCATOR_C ARG0, TgVOID_PC ARG1, TgRSIZE_C ARG2, TgCHAR_MB_CPC ARG3, TgUINT_E32_C ARG4 );

/** @} TGS_COMMON_MEMORY_MGR */


/* =============================================================================================================================================================================== */
#endif
