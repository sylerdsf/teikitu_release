/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - API [Platform].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_API_PLATFORM_H)
#define TGS_COMMON_BASE_API_PLATFORM_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_BASE_API_PLATFORM_THREAD Thread Functions
    @ingroup TGS_COMMON
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

                                            /** @brief Compiler specific implementation to cause a break point in execution */
TgINLINE TgVOID                             tgPM_Break( TgVOID );

                                            /** @brief Compiler specific implementation to cause the program to terminate */
TgINLINE TgVOID                             tgPM_Abort( TgVOID );


/* ---- Thread ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_BASE_API_PLATFORM_THREAD */
/** @{ */

#if TgCOMPILE__THREAD
                                            /** @brief Used to create and execute the main thread for the system*/
                                            /** @param[in] ARG Name for the thread given to the operating system */
TgEXTN TgTHREAD_ID                          tgTR_Register_Main_Thread( TgOSCHAR_CPC ARG );

                                            /** @brief Platform agnostic method to create a new thread
                                                @param[in] ARG0 Platform specific thread function
                                                @param[in] ARG1 Thread function parameter
                                                @param[in] ARG2 Stack Size
                                                @param[in] ARG3 Thread priority.  By default this should be normal
                                                @param[in] ARG4 Thread name - used for debugging purposes. */
TgEXTN TgTHREAD_ID                          tgTR_Create( TgPLATFORM_THREAD_FCN ARG0, TgUINT_PTR_C ARG1, TgUINT_F32_C ARG2, ETgTHREAD_PRIORITY_C ARG3, TgOSCHAR_CPC ARG4 );

                                            /** @return The unique thread identifier for the current executing thread */
TgEXTN TgTHREAD_ID                          tgTR_Query_Id( TgVOID );

                                            /** @brief Joins the thread indicated by ARG and waits for it to terminate
                                                @param[in] ARG Unique identifier for a specific thread */
TgEXTN TgVOID                               tgTR_Close( TgTHREAD_ID ARG );

                                            /** @return The status of the thread
                                                @param[in] ARG Unique identifier for a specific thread */
TgEXTN ETgTHREAD_STATUS                     tgTR_Status( TgTHREAD_ID ARG );


                                            /** @return The size of the thread stack. MAX is uninitialized and MAX-1 is used during initialization of the thread */
TgEXTN TgRSIZE                              tgTR_Stack_Size( TgVOID );

/*# TgCOMPILE__THREAD */
#endif
                                            /** @brief Yields the remaining time slice back to the scheduler but does not guarantee that a new thread will execute next. */
TgINLINE TgVOID                             tgTR_Yield( TgVOID );

                                            /** @brief Cpu instruction meant to be used for spin loops */
TgINLINE TgVOID                             tgTR_Pause( TgVOID );

                                            /** @brief Place the thread to sleep for ARG number of nanoseconds*/
                                            /** @param[in] ARG Nanoseconds */
TgINLINE TgVOID                             tgTR_Sleep( TgUINT_F32_C ARG );

/** @} TGS_COMMON_BASE_API_PLATFORM_THREAD */


/* =============================================================================================================================================================================== */
#endif
