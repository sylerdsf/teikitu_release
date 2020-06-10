/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Global.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_GLOBAL_H)
#define TGS_COMMON_GLOBAL_H
#pragma once

#include TgHEADER_PLATFORM(TgS COMMON/TgS,Common - Global.h)


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_GLOBAL Global
    @ingroup TGS_COMMON_COMMON
*/

    /** @defgroup TGS_COMMON_GLOBAL_MODULE Module Functions
        @ingroup TGS_COMMON_GLOBAL
    */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Constants                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

enum { KTgMAX_CMD_LINE_COUNT                = 64 };
enum { KTgMAX_CMD_LINE_SIZE                 = 512 };


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @addtogroup TGS_COMMON_GLOBAL_MODULE */
/** @{ */

TgEXTN TgRESULT                             tgGB_Init( TgVOID );
TgEXTN TgRESULT                             tgGB_Boot( TgVOID );
TgEXTN TgVOID                               tgGB_Stop( TgVOID );
TgEXTN TgVOID                               tgGB_Free( TgVOID );
TgEXTN TgRESULT                             tgGB_Update( TgFLOAT32_C );

TgEXTN TgRSIZE                              tgGB_Query_Fixed_Memory( TgVOID );

TgEXTN TgBOOL                               tgGB_Query_Init( TgVOID );
TgEXTN TgBOOL                               tgGB_Query_Boot( TgVOID );

TgEXTN TgRESULT                             tgGB_Init_OS( TgVOID );
TgEXTN TgRESULT                             tgGB_Boot_OS( TgVOID );
TgEXTN TgVOID                               tgGB_Stop_OS( TgVOID );
TgEXTN TgVOID                               tgGB_Free_OS( TgVOID );

#if TgS_STAT__COMMON
TgEXTN TgVOID                               tgGB_Stats( STg2_Output_P );
#endif

/** @} TGS_COMMON_GLOBAL_MODULE */


/** @addtogroup TGS_COMMON_GLOBAL */
/** @{ */
                                            /** @brief Output an unique name into ARG0
                                                @param[out] OUT0 Destination String
                                                @param[in] ARG1 Maximum size in bytes of the string at ARG0
                                                @return True if the function was successful and false otherwise */
TgEXTN TgBOOL                               tgGB_Get_Unique_Name( TgCHAR_MB_PCU OUT0, TgUINT_F32_C ARG1 );


                                            /** @brief Parse the provided string as if it was the command line
                                                @param[out] OUT0 Destination for the argument list
                                                @param[in] ARG1 Maximum number of arguments that ARG0 can contain
                                                @param[in] ARG2 Source string for processing */
TgEXTN TgUINT_F32                           tgGB_Parse_Command_Line( TgCHAR_MB_CPP OUT0, TgRSIZE_C ARG1, TgCHAR_MB_PC ARG2 );

                                            /** @brief Copy the command line from the OS to the module for processing and use
                                                @param[in] ARG String containing the command line */
TgEXTN TgVOID                               tgGB_CMD_Set_Command_Line( TgCHAR_MB_CPCU ARG );

                                            /** @brief Return the number of arguments on the command line
                                                @return The number of arguments on the command line */
TgEXTN TgSINT_F32                           tgGB_CMD_Query_Argument_Count( TgVOID );

                                            /** @brief Return the argument at the given index
                                                @param[in] ARG Argument Index
                                                @return The argument at the given index */
TgEXTN TgCHAR_MB_CP                         tgGB_CMD_Query_Argument( TgSINT_F32_C ARG );

                                            /** @brief Return index of the given argument (returning the first occurrence)
                                                @param[in] ARG String containing the argument to search for in the command line
                                                @return The index of the given argument (returning the first occurrence) */
TgEXTN TgSINT_F32                           tgGB_CMD_Query_Argument_Index( TgCHAR_MB_CPC ARG );

                                            /** @brief Add new arguments to the internal copy of the command line
                                                @param[in] ARG String containing the new argument(s) to be added to the internal command line */
TgEXTN TgVOID                               tgGB_CMD_Push_Argument( TgCHAR_MB_CPC ARG );


                                            /** @brief Reset the accumulated reported time since execution start or last reset */
TgEXTN TgVOID                               tgGB_Reset_Frame_Time( TgVOID );

                                            /** @brief Force the internal  time tracker to a specific value
                                                @param[in] ARG Time Value */
TgEXTN TgVOID                               tgGB_Set_Frame_Time( TgFLOAT32_C ARG );

                                            /** @brief Increment the internal time tracker by a specific amount
                                                @param[in] ARG Time Value */
TgEXTN TgVOID                               tgGB_Inc_Frame_Time( TgFLOAT32_C ARG );

                                            /** @brief Validate if the version of the argument matches the version at compile time
                                                @param[in] ARG Version
                                                @return true if the argument version matches the compile time version and false otherwise */
TgEXTN TgBOOL                               tgGB_Verify_Version( TgUINT_F32_C ARG );


                                            /** @brief Return the current time associated with the current frame
                                                @return The current time associated with the current frame */
TgEXTN TgFLOAT32                            tgGB_Query_Frame_Time( TgVOID );

                                            /** @brief Return the total time spent in active frames
                                                @return Total time spent in active frames */
TgEXTN TgSINT_F32                           tgGB_Query_Total_Frame( TgVOID );

                                            /** @brief Return the total time spent since application start
                                                @return Total time spent since application start */
TgEXTN TgFLOAT32                            tgGB_Query_Total_Time( TgVOID );

                                            /** @brief Determine if the current application is running as a client
                                                @return True if the current application is considered to be a client and false otherwise */
TgEXTN TgBOOL                               tgGB_Query_Client( TgVOID );

                                            /** @brief Determine if the current application is running as a server
                                                @return True if the current application is considered to be a server and false otherwise */
TgEXTN TgBOOL                               tgGB_Query_Server( TgVOID );

                                            /** @brief Determine if the current hardware platform is considered to be a console (embedded device)
                                                @return True if the current hardware platform is considered to be a console (embedded device) and false otherwise */
TgEXTN TgBOOL                               tgGB_Query_Console_HW( TgVOID );

                                            /** @brief Determine how allocated resources will be treated on application exit
                                                @return True when all resources reserved by the platform will be freed on application exit and false otherwise */
TgEXTN TgBOOL                               tgGB_Query_Free_On_Quit( TgVOID );

/** @} TGS_COMMON_GLOBAL */

/* Flag functions - the set version should only be used by the internal engine code.  Calling these within the game code will most likely break the engine processes and */
/* cause catastrophic failure. */

                                            /** @brief Used to set the intended application usage as a client
                                                @param[in] ARG Boolean Flag */
TgEXTN TgVOID                               tgGB_Set_Client( TgBOOL_C ARG );

                                            /** @brief Used to set the intended application usage as a server
                                                @param[in] ARG Boolean Flag */
TgEXTN TgVOID                               tgGB_Set_Server( TgBOOL_C ARG );

                                            /** @brief Used to set the current hardware as being a console (embedded device)
                                                @param[in] ARG Boolean Flag */
TgEXTN TgVOID                               tgGB_Set_Console_HW( TgBOOL_C ARG );

                                            /** @brief Used to tell the platform to free all reserved resources on application exist
                                                @param[in] ARG Boolean Flag */
TgEXTN TgVOID                               tgGB_Set_Free_On_Quit( TgBOOL_C ARG );


/* =============================================================================================================================================================================== */
#endif
