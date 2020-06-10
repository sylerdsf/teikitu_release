/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Event MGR.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_EVENT_MGR_H)
#define TGS_COMMON_EVENT_MGR_H
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_EVENT_MGR Event Manager
    @ingroup TGS_COMMON_COMMON
*/

    /** @defgroup TGS_COMMON_EVENT_MGR_MODULE Module Functions
        @ingroup TGS_COMMON_EVENT_MGR
    */

    /** @defgroup TGS_COMMON_EVENT_MGR_FRAME Frame Based Events
        @ingroup TGS_COMMON_EVENT_MGR
    */

    /** @defgroup TGS_COMMON_EVENT_MGR_TIME Time Based Events
        @ingroup TGS_COMMON_EVENT_MGR
    */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

typedef TgVOID( *TgFCN_EM_CALLBACK )(TgUINT_PTR_C);


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @addtogroup TGS_COMMON_EVENT_MGR_MODULE */
/** @{ */

TgEXTN TgRESULT                             tgEM_Init_MGR( TgVOID );
TgEXTN TgRESULT                             tgEM_Boot_MGR( TgVOID );
TgEXTN TgRESULT                             tgEM_Stop_MGR( TgVOID );
TgEXTN TgRESULT                             tgEM_Free_MGR( TgVOID );
TgEXTN TgRESULT                             tgEM_Update_MGR( TgFLOAT32_C );
TgEXTN TgBOOL                               tgEM_Update_MGR_Is_Complete( TgVOID );

TgEXTN TgRSIZE                              tgEM_Query_Fixed_Memory( TgVOID );

TgEXTN TgBOOL                               tgEM_Query_Init( TgVOID );
TgEXTN TgBOOL                               tgEM_Query_Boot( TgVOID );

#if TgS_STAT__COMMON
TgEXTN TgVOID                               tgEM_Stats( STg2_Output_P );
#endif

/** @} TGS_COMMON_EVENT_MGR_MODULE */


/** @addtogroup TGS_COMMON_EVENT_MGR */
/** @{ */
                                            /** @brief Set the pause state for the Event Manager
                                                @param[in] ARG Boolean Flag */
TgEXTN TgVOID                               tgEM_Set_Pause( TgBOOL_C ARG );

                                            /** @brief Return the pause state for the Event Manager
                                                @return True if the Event Manager is currently paused, and false otherwise */
TgEXTN TgBOOL                               tgEM_Query_Pause( TgVOID );

/** @} TGS_COMMON_EVENT_MGR */


/* ---- Time Event - Frame ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_EVENT_MGR_FRAME */
/** @{ */
                                            /** @brief Create a new event based on frame counts with the given parameters
                                                @param[in] ARG0 The function to call when event is triggered
                                                @param[in] ARG1 Function parameter to use when called
                                                @param[in] ARG2 Start Frame for the Event
                                                @param[in] ARG3 End Frame for the Event
                                                @return Event identifier on success, and false otherwise */
TgEXTN TgEM_TE_FRM_ID                       tgEM_TE_FRM_NEW( TgFCN_EM_CALLBACK ARG0, TgUINT_PTR_C ARG1, TgSINT_F32_C ARG2, TgSINT_F32_C ARG3 );

                                            /** @brief Delete the given Event
                                                @param[in] ARG Event Identifier */
TgEXTN TgRESULT                             tgEM_TE_FRM_DEL( TgEM_TE_FRM_ID ARG );

                                            /** @brief Set the pause state for the given event
                                                @param[in] ARG0 Event Identifier
                                                @param[in] ARG1 Boolean Flag
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_FRM_Set_Pause( TgEM_TE_FRM_ID ARG0, TgBOOL_C ARG1 );

                                            /** @brief Set the start frame for the given event
                                                @param[in] ARG0 Event Identifier
                                                @param[in] ARG1 Start Frame
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_FRM_Set_Start_Frame( TgEM_TE_FRM_ID ARG0, TgSINT_F32_C ARG1 );

                                            /** @brief Set the end frame for the given event
                                                @param[in] ARG0 Event Identifier
                                                @param[in] ARG1 End Frame
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_FRM_Set_End_Frame( TgEM_TE_FRM_ID ARG0, TgSINT_F32_C ARG1 );

                                            /** @brief Alternative to setting the end frame for the Event, where it is set to be ARG1 frames from the current total
                                                @param[in] ARG0 Event Identifier
                                                @param[in] ARG1 Number of Frames from now before terminating the Event
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_FRM_Set_Frame_To_Live( TgEM_TE_FRM_ID ARG0, TgSINT_F32_C ARG1 );


                                            /** @brief Return true if the ARG Event Identifier is valid and associated with a valid Event
                                                @param[in] ARG Event Identifier
                                                @return True if the identifier and Event are valid, and false otherwise */
TgEXTN TgBOOL                               tgEM_TE_FRM_Query_Valid( TgEM_TE_FRM_ID ARG );

                                            /** @brief Store the pause state of the Event
                                                @param[out] OUT0 Destination to hold the pause state of the
                                                @param[in] ARG1 Event Identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_FRM_Query_Paused( TgBOOL_PCU OUT0, TgEM_TE_FRM_ID ARG1 );

                                            /** @brief Store the frame number to start the Event
                                                @param[out] OUT0 Destination to hold the start frame for the Event
                                                @param[in] ARG1 Event Identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_FRM_Query_Start_Frame( TgSINT_F32_PCU OUT0, TgEM_TE_FRM_ID ARG1 );

                                            /** @brief Store the frame number to end the Event
                                                @param[out] OUT0 Destination to hold the end frame of the Event
                                                @param[in] ARG1 Event Identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_FRM_Query_End_Frame( TgSINT_F32_PCU OUT0, TgEM_TE_FRM_ID ARG1 );

                                            /** @brief Store the number of frames until the Event ends
                                                @param[out] OUT0 Destination to hold the number of frames until the Event ends
                                                @param[in] ARG1 Event Identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_FRM_Query_Frame_To_Live( TgSINT_F32_PCU OUT0, TgEM_TE_FRM_ID ARG1 );

/** @} TGS_COMMON_EVENT_MGR_FRAME */


/* ---- Time Event - Time -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_EVENT_MGR_TIME */
/** @{ */
                                            /** @brief Create a new event based on time with the given parameters
                                                @param[in] ARG0 The function to call when event is triggered
                                                @param[in] ARG1 Function parameter to use when called
                                                @param[in] ARG2 Starting time for the Event
                                                @param[in] ARG3 End time for the Event
                                                @return Event identifier on success, and false otherwise */
TgEXTN TgEM_TE_SEC_ID                       tgEM_TE_SEC_NEW( TgFCN_EM_CALLBACK ARG0, TgUINT_PTR_C ARG1, TgFLOAT32_C ARG2, TgFLOAT32_C ARG3 );

                                            /** @brief Delete the given Event
                                                @param[in] ARG Event Identifier */
TgEXTN TgRESULT                             tgEM_TE_SEC_DEL( TgEM_TE_SEC_ID ARG );


                                            /** @brief Set the pause state for the given event
                                                @param[in] ARG0 Event Identifier
                                                @param[in] ARG1 Boolean Flag
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_SEC_Set_Pause( TgEM_TE_SEC_ID ARG0, TgBOOL_C ARG1 );

                                            /** @brief Set the starting time for the given event
                                                @param[in] ARG0 Event Identifier
                                                @param[in] ARG1 Start time (time in milliseconds)
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_SEC_Set_Start_Time( TgEM_TE_SEC_ID ARG0, TgFLOAT32_C ARG1 );

                                            /** @brief Set the end time for the given event
                                                @param[in] ARG0 Event Identifier
                                                @param[in] ARG1 End time (time in milliseconds)
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_SEC_Set_End_Time( TgEM_TE_SEC_ID ARG0, TgFLOAT32_C ARG1 );

                                            /** @brief Alternative to setting the end time for the Event, where it is set to be ARG1 milliseconds from the current time
                                                @param[in] ARG0 Event Identifier
                                                @param[in] ARG1 Number of milliseconds from now before ending the Event
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_SEC_Set_Time_To_Live( TgEM_TE_SEC_ID ARG0, TgFLOAT32_C ARG1 );


                                            /** @brief Return true if the ARG Event Identifier is valid and associated with a valid Event
                                                @param[in] ARG Event Identifier
                                                @return True if the identifier and Event are valid, and false otherwise */
TgEXTN TgBOOL                               tgEM_TE_SEC_Query_Valid( TgEM_TE_SEC_ID ARG );

                                            /** @brief Store the pause state for the Event
                                                @param[out] OUT0 Destination to hold the pause state for the Event
                                                @param[in] ARG1 Event Identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_SEC_Query_Paused( TgBOOL_PCU OUT0, TgEM_TE_SEC_ID ARG1 );

                                            /** @brief Store the start time of the Event
                                                @param[out] OUT0 Destination to hold the start time of the Event
                                                @param[in] ARG1 Event Identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_SEC_Query_Start_Time( TgFLOAT32_PCU OUT0, TgEM_TE_SEC_ID ARG1 );

                                            /** @brief Store the end time of the Event
                                                @param[out] OUT0 Destination to hold the end time of the Event
                                                @param[in] ARG1 Event Identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_SEC_Query_End_Time( TgFLOAT32_PCU OUT0, TgEM_TE_SEC_ID ARG1 );

                                            /** @brief Store the number of milliseconds until the Event ends
                                                @param[out] OUT0 Destination to hold the number of milliseconds until the Event ends
                                                @param[in] ARG1 Event Identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgEM_TE_SEC_Query_Time_To_Live( TgFLOAT32_PCU OUT0, TgEM_TE_SEC_ID ARG1 );

/** @} TGS_COMMON_EVENT_MGR_TIME */


/* =============================================================================================================================================================================== */
#endif
