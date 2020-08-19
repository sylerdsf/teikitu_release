/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - Type [MT].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_TYPE_MT_H)
#define TGS_COMMON_BASE_TYPE_MT_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_BASE_TYPE_MT Multi-thread Synchronization
    @ingroup TGS_COMMON_BASE_API_PLATFORM_THREAD
*/

    /** @defgroup TGS_COMMON_BASE_TYPE_MT_MX Mutex
        @ingroup TGS_COMMON_BASE_TYPE_MT
    */

    /** @defgroup TGS_COMMON_BASE_TYPE_MT_SM Semaphore
        @ingroup TGS_COMMON_BASE_TYPE_MT
    */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Private Constants                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

enum { KTgMAX_SEMAPHORE_NAME                = 16 };


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgTYPE_FORWARD_STRUCT( STg1_MT_MX );
TgTYPE_FORWARD_STRUCT( STg1_MT_SM );

#include TgHEADER_THREAD_SUPPORT(TgS COMMON/TgS,Common - Base - Type [MT].h)  /**< Synchronization can be used in Structures and Templates. */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- STg1_MT_MX --------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_BASE_TYPE_MT_MX Mutex */
/** @{ */

                                            /** @brief Initialize a mutex synchronization object
                                                @param[out] OUT0 Pointer to a mutex synchronization object
                                                @param[in] ARG1 Name for the object given to the OS (can be null)
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgPM_MT_MX_Init( STg1_MT_MX_PCU OUT0, TgCHAR_NC_CPCU ARG1 );

                                            /** @brief Free the mutex synchronization object
                                                @param[in,out] ARG Pointer to a mutex synchronization object */
TgINLINE TgVOID                             tgPM_MT_MX_Free( STg1_MT_MX_PCU ARG );

                                            /** @brief Acquire the mutex object, blocking the thread until the operation has completed*/
                                            /** @param[in,out] ARG Pointer to a mutex synchronization object */
TgINLINE TgVOID                             tgPM_MT_MX_Wait_Block( STg1_MT_MX_PCU ARG );

                                            /** @brief Attempt to acquire the mutex object, return a fail condition unable to do it.*/
                                            /** @param[in,out] ARG Pointer to a mutex synchronization object */
TgINLINE TgRESULT                           tgPM_MT_MX_Wait( STg1_MT_MX_PCU ARG );

                                            /** @brief Release the mutex object
                                                @param[in,out] ARG Pointer to a mutex synchronization object */
TgINLINE TgVOID                             tgPM_MT_MX_Release( STg1_MT_MX_PCU ARG );

/** @} TGS_COMMON_BASE_TYPE_MT_MX */


/* ---- STg1_MT_SM --------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_BASE_TYPE_MT_SM Semaphore */
/** @{ */

                                            /** @brief Initialize a semaphore synchronization object
                                                @param[out] OUT0 Pointer to a semaphore object
                                                @param[in] ARG1 Name for the semaphore (can be null)
                                                @param[in] ARG2 Initial count for the semaphore
                                                @param[in] ARG3 Maximum count for the semaphore 
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgPM_MT_SM_Init( STg1_MT_SM_PCU OUT0, TgCHAR_NC_CPCU ARG1, TgUINT_F32_C ARG2, TgUINT_F32_C ARG3 );

                                            /** @brief Free a semaphore synchronization object
                                                @param[in,out] ARG Pointer to a semaphore object */
TgINLINE TgVOID                             tgPM_MT_SM_Free( STg1_MT_SM_PCU ARG );

                                            /** @brief Decrement the semaphore and block the thread until count >= 0
                                                @param[in,out] ARG Pointer to a semaphore object */
TgINLINE TgVOID                             tgPM_MT_SM_Wait_Block( STg1_MT_SM_PCU ARG );

                                            /** @brief If the count >= 0, decrement the counter and return a KTgS_OK
                                                @param[in,out] ARG Pointer to a semaphore object */
TgINLINE TgRESULT                           tgPM_MT_SM_Wait( STg1_MT_SM_PCU ARG );

                                            /** @brief Initialize a semaphore synchronization object
                                                @param[in,out] ARG0 Pointer to a semaphore object
                                                @param[in] ARG1 The number to increment the counter */
TgINLINE TgVOID                             tgPM_MT_SM_Signal( STg1_MT_SM_PCU ARG0, TgUINT_F32_C ARG1 );

/** @} TGS_COMMON_BASE_TYPE_MT_SM */


/* =============================================================================================================================================================================== */
#endif

