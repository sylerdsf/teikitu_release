/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util MT - Reader Writer Lock.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UTIL_MP_RW_H)
#define TGS_COMMON_UTIL_MP_RW_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_UTIL_MT_MRSW_LOCK_LOCKFREE Reader Writer Lock, using atomic operations to manage lock operations
    @ingroup TGS_COMMON_UTILITY_MT_LOCK
*/

/** @defgroup TGS_COMMON_UTIL_MT_MRSW_LOCK_SPIN_GUARD Reader Write Lock, using a spin lock guard for lock operations
    @ingroup TGS_COMMON_UTILITY_MT_LOCK
*/

/** @defgroup TGS_COMMON_UTIL_MT_MRSW_LOCK_MUTEX Reader Writer Lock, using a mutex as a guard for lock operations
    @ingroup TGS_COMMON_UTILITY_MT_LOCK
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Constants                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgCOMPILER_ASSERT( 4 == sizeof( TgSINT_E32 ), 0 );

typedef enum
{
    ETgUTM_RW_STATE__Waiting,
    ETgUTM_RW_STATE__Reading,
    ETgUTM_RW_STATE__Writing,
} ETgUTM_RW_STATE;
TgTYPE_MODIFIER_DEFAULT( ETgUTM_RW_STATE );

enum { KTgMP_MAX_READ_WRITER_LOCK           = 32 };


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- STg2_UT_LF__RW ----------------------------------------------------------------------------------------------------------------------------------------------------------- */

TgTYPE_UNION(STg2_UT_ST__RW_REQ,)
{
    TgUINT_E64                                  m_uiRW_REQ;
    struct
    {
        TgUINT_E16                                  m_uiWrite;
        TgUINT_E16                                  m_uiRead;
        TgUINT_E16                                  m_uiRequest;
        TgUINT_E16                                  m_uiUnused;
    };
};

TgTYPE_STRUCT(STg2_UT_LF__RW,)
{
    TgUINT_E64_A                                m_uiRW_REQ;
};

TgTYPE_STRUCT(STg2_UT_LF_ISO__RW,)
{
    STg2_UT_LF__RW TgALIGN(TgCCL)               m_sLock;
    TgUINT_E08                                  m_uiPad[TgCCL - (8 % TgCCL)];
};

TgCOMPILER_ASSERT( 8 == sizeof( STg2_UT_LF__RW ), 0 );
TgCOMPILER_ASSERT( 0 == sizeof( STg2_UT_LF_ISO__RW ) % TgCCL, 0 );


/* ---- STg2_UT_LF_ISO__RW_SN / STg2_UT_MT__RW_MX -------------------------------------------------------------------------------------------------------------------------------- */

TgTYPE_STRUCT(STg2_UT_ST__RW_DATA,)
{
    ETgUTM_RW_STATE                             m_enState;
    TgUINT_E32                                  m_nuiReader;
    TgUINT_E32                                  m_uiIndex;
    TgUINT_E32                                  m_nuiThread;
    TgTHREAD_ID                                 m_asThread[KTgMP_MAX_READ_WRITER_LOCK];
    TgBOOL                                      m_abReader[KTgMP_MAX_READ_WRITER_LOCK];
    STg1_MT_SM_P                                m_psExecute[KTgMP_MAX_READ_WRITER_LOCK];
};

TgTYPE_STRUCT(STg2_UT_LF_ISO__RW_SN,)
{
    STg2_UT_LF_ISO__SN                          m_sLock;
    STg2_UT_ST__RW_DATA                         m_sData;
    TgUINT_E08                                  m_uiPad[TgCCL - (560 % TgCCL)];
};

TgTYPE_STRUCT(STg2_UT_MT__RW_MX,)
{
    STg1_MT_MX                                  m_sLock;
    STg2_UT_ST__RW_DATA                         m_sData;
};

TgCOMPILER_ASSERT( 560 == sizeof( STg2_UT_ST__RW_DATA ), 0 );
TgCOMPILER_ASSERT( 0 == sizeof( STg2_UT_LF_ISO__RW_SN ) % TgCCL, 0 );


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- FIFO Atomic Reader-Writer Lock ------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_UTIL_MT_MRSW_LOCK_LOCKFREE
    @{ */

                                            /** @brief Initialize a lock free reader writer lock
                                                @param[out] OUT Pointer to a reader writer lock, using atomic operations to manage the lock
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_LF__RW__Init( STg2_UT_LF__RW_PCU OUT );

                                            /** @brief Free all resources used by the object and perform some sanity checks
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock */
TgINLINE TgVOID                             tgCM_UT_LF__RW__Free( STg2_UT_LF__RW_PCU ARG );


                                            /** @brief Acquire a read lock using a spin wait with a thread yield
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock */
TgINLINE TgVOID                             tgCM_UT_LF__RW__Enter_Read_Wait_Yield( STg2_UT_LF__RW_PCU ARG );

                                            /** @brief Acquire a read lock using a spin wait with a thread pause
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock */
TgINLINE TgVOID                             tgCM_UT_LF__RW__Enter_Read_Wait_Spin( STg2_UT_LF__RW_PCU ARG );

                                            /** @brief Attempt to acquire a read lock, and fail if unable to do it immediately
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_LF__RW__Enter_Read( STg2_UT_LF__RW_PCU ARG );


                                            /** @brief Release a read lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock */
TgINLINE TgVOID                             tgCM_UT_LF__RW__Exit_Read( STg2_UT_LF__RW_PCU ARG );


                                            /** @brief Acquire a write lock using a spin wait with a thread yield
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock */
TgINLINE TgVOID                             tgCM_UT_LF__RW__Enter_Write_Wait_Yield( STg2_UT_LF__RW_PCU ARG );

                                            /** @brief Acquire a write lock using a spin wait with a thread pause
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock */
TgINLINE TgVOID                             tgCM_UT_LF__RW__Enter_Write_Wait_Spin( STg2_UT_LF__RW_PCU ARG );

                                            /** @brief Attempt to acquire the write lock, and fail if unable to do it immediately
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_LF__RW__Enter_Write( STg2_UT_LF__RW_PCU ARG );


                                            /** @brief Release the write lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using atomic operations to manage the lock */
TgINLINE TgVOID                             tgCM_UT_LF__RW__Exit_Write( STg2_UT_LF__RW_PCU ARG );

/** @} TGS_COMMON_UTIL_MT_MRSW_LOCK_LOCKFREE */


/* ---- FIFO Spin Lock Reader Writer Queuing Lock -------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__THREAD
/** @addtogroup TGS_COMMON_UTIL_MT_MRSW_LOCK_SPIN_GUARD
    @{ */

                                            /** @brief Initialize a reader writer lock using a lock-free spin lock to guard the lock object
                                                @param[out] OUT Pointer to a reader writer lock, using a spin lock guard
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_LF__RW_SN__Init( STg2_UT_LF_ISO__RW_SN_PCU OUT );

                                            /** @brief Free all resources used by the object and perform some sanity checks
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Free( STg2_UT_LF_ISO__RW_SN_PCU ARG );


                                            /** @brief Acquire the spin lock guard using a thread yield, and acquire a read lock (blocking the thread as necessary)
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Enter_Read_Yield_Block( STg2_UT_LF_ISO__RW_SN_PCU ARG );

                                            /** @brief Acquire the spin lock guard using a thread pause, and acquire a read lock (blocking the thread as necessary)
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Enter_Read_Spin_Block( STg2_UT_LF_ISO__RW_SN_PCU ARG );

                                            /** @brief Acquire the spin lock guard using a thread yield, and acquire a read lock if allowed
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_LF__RW_SN__Enter_Read_Yield( STg2_UT_LF_ISO__RW_SN_PCU ARG );

                                            /** @brief Acquire the spin lock guard using a thread pause, and acquire a read lock if allowed
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_LF__RW_SN__Enter_Read_Spin( STg2_UT_LF_ISO__RW_SN_PCU ARG );


                                            /** @brief Acquire the spin lock guard using a thread yield, and release a read lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Exit_Read_Yield( STg2_UT_LF_ISO__RW_SN_PCU ARG );

                                            /** @brief Acquire the spin lock guard using a thread pause, and release a read lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Exit_Read_Spin( STg2_UT_LF_ISO__RW_SN_PCU ARG );


                                            /** @brief Acquire the spin lock guard using a thread yield, and acquire the write lock (blocking the thread as necessary)
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Enter_Write_Yield_Block( STg2_UT_LF_ISO__RW_SN_PCU ARG );

                                            /** @brief Acquire the spin lock guard using a thread pause, and acquire the write lock (blocking the thread as necessary)
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Enter_Write_Spin_Block( STg2_UT_LF_ISO__RW_SN_PCU ARG );

                                            /** @brief Acquire the spin lock guard using a thread yield, and acquire the write lock if allowed
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_LF__RW_SN__Enter_Write_Yield( STg2_UT_LF_ISO__RW_SN_PCU ARG );

                                            /** @brief Acquire the spin lock guard using a thread pause, and acquire the write lock if allowed
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_LF__RW_SN__Enter_Write_Spin( STg2_UT_LF_ISO__RW_SN_PCU ARG );


                                            /** @brief Acquire the spin lock guard using a thread yield, and release the write lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Exit_Write_Yield( STg2_UT_LF_ISO__RW_SN_PCU ARG );

                                            /** @brief Acquire the spin lock guard using a thread pause, and release the write lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using a spin lock guard */
TgINLINE TgVOID                             tgCM_UT_LF__RW_SN__Exit_Write_Spin( STg2_UT_LF_ISO__RW_SN_PCU ARG );

/** @} TGS_COMMON_UTIL_MT_MRSW_LOCK_SPIN_GUARD */

/*# TgCOMPILE__THREAD */
#endif


/* ---- FIFO Critical Section Reader Writer Queuing Lock ------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__THREAD
/** @addtogroup TGS_COMMON_UTIL_MT_MRSW_LOCK_MUTEX
    @{ */

                                            /** @brief Initialize a reader writer lock using a mutex guard
                                                @param[out] OUT Pointer to a reader writer lock, using a mutex guard
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_MT__RW_MX__Init( STg2_UT_MT__RW_MX_PCU OUT );

                                            /** @brief Free all resources used by the object and perform some sanity checks
                                                @param[in,out] ARG Pointer to a reader writer lock, using a mutex guard */
TgINLINE TgVOID                             tgCM_UT_MT__RW_MX__Free( STg2_UT_MT__RW_MX_PCU ARG );


                                            /** @brief Acquire a read lock, blocking the thread as necessary
                                                @param[in,out] ARG Pointer to a reader writer lock, using a mutex guard */
TgINLINE TgVOID                             tgCM_UT_MT__RW_MX__Enter_Read_Block( STg2_UT_MT__RW_MX_PCU ARG );

                                            /** @brief Attempt to acquire a read lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using a mutex guard
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_MT__RW_MX__Enter_Read( STg2_UT_MT__RW_MX_PCU ARG );


                                            /** @brief Release a read lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using a mutex guard */
TgINLINE TgVOID                             tgCM_UT_MT__RW_MX__Exit_Read( STg2_UT_MT__RW_MX_PCU ARG );


                                            /** @brief Acquire the write lock, blocking the thread as necessary
                                                @param[in,out] ARG Pointer to a reader writer lock, using a mutex guard */
TgINLINE TgVOID                             tgCM_UT_MT__RW_MX__Enter_Write_Block( STg2_UT_MT__RW_MX_PCU ARG );

                                            /** @brief Attempt to acquire the write lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using a mutex guard
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_MT__RW_MX__Enter_Write( STg2_UT_MT__RW_MX_PCU ARG );


                                            /** @brief Release the write lock
                                                @param[in,out] ARG Pointer to a reader writer lock, using a mutex guard */
TgINLINE TgVOID                             tgCM_UT_MT__RW_MX__Exit_Write( STg2_UT_MT__RW_MX_PCU ARG );

/** @} TGS_COMMON_UTIL_MT_MRSW_LOCK_MUTEX */

/*# TgCOMPILE__THREAD */
#endif


/* =============================================================================================================================================================================== */
#endif
