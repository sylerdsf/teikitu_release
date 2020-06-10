/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Console.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_CONSOLE_H)
#define TGS_COMMON_CONSOLE_H
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_CONSOLE Console
    @ingroup TGS_COMMON_COMMON
*/

    /** @defgroup TGS_COMMON_CONSOLE_MODULE Module Functions
        @ingroup TGS_COMMON_CONSOLE
    */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Constants                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if TgCOMPILE__CONSOLE

/* There are twenty-eight (28) console channels.  The first twelve (12) are system reserved (the below enumeration).  The remaining sixteen (16) are available to the user and can
   be assigned arbitrarily.  The first four bits are used to indicate the severity of the output (may only be valid for certain channels). */

enum { KTgCN_SEVERITY_BITS                  = 4 }; /**< Number of bits used to describe message severity (0-15) */
enum { KTgCN_CHANEL_BITS                    = 32 - KTgCN_SEVERITY_BITS }; /**< The remaining bits are used for the channel */

enum { KTgCN_SEVERITY_0                     = 0x0 }; /**< Highest severity (last to be filtered) */
enum { KTgCN_SEVERITY_1                     = 0x1 };
enum { KTgCN_SEVERITY_2                     = 0x2 };
enum { KTgCN_SEVERITY_3                     = 0x3 };
enum { KTgCN_SEVERITY_4                     = 0x4 };
enum { KTgCN_SEVERITY_5                     = 0x5 };
enum { KTgCN_SEVERITY_6                     = 0x6 };
enum { KTgCN_SEVERITY_7                     = 0x7 };
enum { KTgCN_SEVERITY_8                     = 0x8 };
enum { KTgCN_SEVERITY_9                     = 0x9 };
enum { KTgCN_SEVERITY_A                     = 0xA };
enum { KTgCN_SEVERITY_B                     = 0xB };
enum { KTgCN_SEVERITY_C                     = 0xC };
enum { KTgCN_SEVERITY_D                     = 0xD };
enum { KTgCN_SEVERITY_E                     = 0xE };
enum { KTgCN_SEVERITY_F                     = 0xF };
enum { KTgCN_MAX_SEVERITY                   = 0xF }; /**< (1 << KTgCN_SEVERITY_BITS) - 3 */
enum { KTgCN_SEVERITY_MASK                  = 0xF }; /**< (1 << KTgCN_SEVERITY_BITS) - 1 */

enum { KTgCN_CHANEL_CONSOLE                 = 1 <<  4 };
enum { KTgCN_CHANEL_LOG_SCREEN              = 1 <<  5 };
enum { KTgCN_CHANEL_LOG                     = 1 <<  6 };
enum { KTgCN_CHANEL_LOG_FCN                 = 1 <<  7 };
enum { KTgCN_CHANEL_LOG_MEM                 = 1 <<  8 };
enum { KTgCN_CHANEL_MESSAGE                 = 1 <<  9 };
enum { KTgCN_CHANEL_WARNING                 = 1 << 10 };
enum { KTgCN_CHANEL_ERROR                   = 1 << 11 };
enum { KTgCN_CHANEL_CRITICAL                = 1 << 12 };
enum { KTgCN_CHANEL_INITIALIZE              = 1 << 13 };
enum { KTgCN_CHANEL_INITIALIZE_MEMORY       = 1 << 14 };
enum { KTgCN_CHANEL_LOADING                 = 1 << 15 };
enum { KTgCN_CHANEL_USER                    = 1 << 16 };

/*# TgCOMPILE__CONSOLE */
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if TgCOMPILE__CONSOLE

typedef TgVOID( *TgFCN_CONSOLE )(TgUINT_F32_C nuiArg, TgCHAR_MB_CP pArgV[KTgMAX_CMD_LINE_COUNT]);
TgTYPE_MODIFIER_DEFAULT( TgFCN_CONSOLE );

/*# TgCOMPILE__CONSOLE */
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Macro Definitions                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
#if TgCOMPILE__CONSOLE

#define TgLOG_MEM( A, ... )                                                                 \
if (tgCN_Query_Boot())                                                                      \
{                                                                                           \
    tgCN_PrintF( KTgCN_CHANEL_LOG_MEM, "%-16.16s(%-32.32s): ", A, __FUNCTION__ );           \
    tgCN_PrintF( KTgCN_CHANEL_LOG_MEM, __VA_ARGS__ );                                       \
}

/*# TgCOMPILE__CONSOLE */
#else

#define TgLOG_MEM( A, ... )
#define tgCN_PrintF(...)
#define tgCN_Print(...)
#define tgCN_UID_PrintF(...)
#define tgCN_UID_Print(...)

/*# TgCOMPILE__CONSOLE */
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @addtogroup TGS_COMMON_CONSOLE_MODULE */
/** @{ */
                                            /* Standard Module functions for lifetime and update control */
TgEXTN TgRESULT                             tgCN_Init( TgVOID );
TgEXTN TgRESULT                             tgCN_Boot( TgVOID );
TgEXTN TgVOID                               tgCN_Stop( TgVOID );
TgEXTN TgVOID                               tgCN_Free( TgVOID );
TgEXTN TgRESULT                             tgCN_Update( TgFLOAT32_C ARG );

TgEXTN TgRSIZE                              tgCN_Query_Fixed_Memory( TgVOID );

TgEXTN TgBOOL                               tgCN_Query_Init( TgVOID );
TgEXTN TgBOOL                               tgCN_Query_Boot( TgVOID );

/** @} TGS_COMMON_CONSOLE_MODULE */


/** @addtogroup TGS_COMMON_CONSOLE */
/** @{ */

                                            /** @brief Print all command functions and console variables through the output object at ARG
                                                @param[in] ARG Pointer to an output object */
TgEXTN TgVOID                               tgCN_Print_Commands( STg2_Output_P ARG );

                                            /** @brief Execute the given command
                                                @param[in] ARG0 Command line to execute (command and associated parameters)
                                                @param[in] ARG1 Size in bytes of the buffer at ARG0 */
TgEXTN TgBOOL                               tgCN_Execute_Command( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1 );

#if TgCOMPILE__CONSOLE

                                            /** @brief Add the output object at ARG1 to the channels with a set bit in ARG0
                                                @note Console output works like a stack. The last output object attached to a channel is the first one to receive the data stream.
                                                      No output object should filter data to the next object in the stack. Thus, order does not matter when adding stream objects.
                                                @param[in] ARG0 Channel mask
                                                @param[in] ARG1 Pointer to output object
                                                @return Value is channel mask of succeeded attaches */
TgEXTN TgUINT_F32                           tgCN_Attach_Output( TgUINT_F32_C ARG0, STg2_Output_PC ARG1 );

                                            /** @brief Add a function that will cause an execution "break" when called to the channels with a set bit in ARG0.
                                                @param[in] ARG0 Channel mask
                                                @return Value is channel mask of succeeded attaches */
TgEXTN TgUINT_F32                           tgCN_Attach_Default_Break( TgUINT_F32_C ARG0 );

                                            /** @brief Add a function that will cause an execution "abort" when called to the channels with a set bit in ARG0.
                                                @param[in] ARG0 Channel mask
                                                @return Value is channel mask of succeeded attaches */
TgEXTN TgUINT_F32                           tgCN_Attach_Default_Abort( TgUINT_F32_C ARG0 );

                                            /** @brief Remove the output object at ARG1 from the channels with a set bit in ARG0
                                                @param[in] ARG0 Channel mask
                                                @param[in] ARG1 Pointer to output object
                                                @return Value is channel mask of succeeded removes */
TgEXTN TgUINT_F32                           tgCN_Remove_Output( TgUINT_F32_C ARG0, STg2_Output_PC ARG1 );

                                            /** @brief Remove a function that causes an execution "break" from the channels with a set bit in ARG0.
                                                @param[in] ARG0 Channel mask
                                                @return Value is channel mask of succeeded removes */
TgEXTN TgUINT_F32                           tgCN_Remove_Default_Break( TgUINT_F32_C ARG0 );

                                            /** @brief Remove a function that causes an execution "abort" from the channels with a set bit in ARG0.
                                                @param[in] ARG0 Channel mask
                                                @return Value is channel mask of succeeded removes */
TgEXTN TgUINT_F32                           tgCN_Remove_Default_Abort( TgUINT_F32_C ARG0 );


                                            /** @brief The string must remain valid for as long as the channel is being used.
                                                @param[in] ARG0 Channel index
                                                @param[in] ARG1 Pointer to a string to be used as a prefix for all output on the given index
                                                @param[in] ARG2 Size in bytes of the buffer at ARG1 */
TgEXTN TgVOID                               tgCN_Set_Prefix( TgUINT_F32_C ARG0, TgCHAR_MB_CPC ARG1, TgRSIZE_C ARG2 );

                                            /** @brief Limit output to a specific literal (class | system)
                                                @param[in] ARG0 Channel mask */
TgEXTN TgVOID                               tgCN_Set_UID_Filter( TgUINT_F32_C ARG0, TgUINT_F32_C ARG1 );

                                            /** @brief Limit the output of a specific literal (class | system)
                                                @param[in] ARG0 Channel mask */
TgEXTN TgVOID                               tgCN_Set_Severity_Filter( TgUINT_F32_C ARG0, TgUINT_F32_C ARG1 );


                                            /** @brief Output the argument string to the given channel */
                                            /** @param[in] ARG0 A severity-channel(s) value */
                                            /** @param[in] ARG1 String literal to output */
                                            /** @param[in] ARG2 Maximum number of bytes in ARG1 */
TgEXTN TgVOID                               tgCN_Print( TgUINT_F32_C ARG0, TgCHAR_MB_CP ARG1, TgRSIZE_C ARG2 );

                                            /** @brief Output the printf formatted string to the given channel */
                                            /** @param[in] ARG0 A severity-channel(s) value */
                                            /** @param[in] ARG1 String literal to output */
                                            /** @param[in] ... Optional list of arguments for use in ARG1 printf processing */
TgEXTN TgVOID                               tgCN_PrintF( TgUINT_F32_C ARG0, TgCHAR_MB_CP ARG1, ... );


                                            /** @brief Output the argument string for the given UID to the given channel */
                                            /** @param[in] ARG0 UID to associate with this function call */
                                            /** @param[in] ARG1 Channel mask */
                                            /** @param[in] ARG2 String literal to output */
                                            /** @param[in] ARG3 Maximum number of bytes in ARG1 */
TgEXTN TgVOID                               tgCN_UID_Print( TgUINT_F32_C ARG0, TgUINT_F32_C ARG1, TgCHAR_MB_CP ARG2, TgRSIZE_C ARG3 );

                                            /** @brief Output the printf formatted string for the given to the given channel */
                                            /** @param[in] ARG0 UID to associate with this function call */
                                            /** @param[in] ARG1 Channel mask */
                                            /** @param[in] ARG2 String literal to output */
                                            /** @param[in] ... Optional list of arguments for use in ARG1 printf processing */
TgEXTN TgVOID                               tgCN_UID_PrintF( TgUINT_F32_C ARG0, TgUINT_F32_C ARG1, TgCHAR_MB_CP ARG2, ... );


                                            /** @brief This will process input for the console display
                                                @param[in] ARG0 Character to be processed
                                                @param[in] ARG1 True if ctrl is being held down */
TgEXTN TgVOID                               tgCN_Process_Input( TgCHAR_WC ARG0, TgBOOL ARG1 );


                                            /** @brief Add a new console command (function)
                                                @param[in] ARG0 String with the command keyword to be associated with this function
                                                @param[in] ARG1 Maximum number of bytes at ARG0
                                                @param[in] ARG2 Console command function
                                                @param[in] ARG3 String with a description of the command (used in help text)
                                                @param[in] ARG4 Maximum number of bytes at ARG3
                                                @return True on success and false otherwise */
TgEXTN TgBOOL                               tgCN_Insert_Command_Function( TgCHAR_MB_CPC ARG0, TgRSIZE ARG1, TgFCN_CONSOLE ARG2, TgCHAR_MB_CPC ARG3, TgRSIZE_C ARG4 );

                                            /** @brief Remove a console command (function)
                                                @param[in] ARG0 String with the command keyword to remove
                                                @param[in] ARG1 Maximum number of bytes at ARG0
                                                @return True on success and false otherwise */
TgEXTN TgBOOL                               tgCN_Remove_Command_Function( TgCHAR_MB_CPC ARG0, TgRSIZE ARG1 );

                                            /** @brief Print all registered command keywords
                                                @param[in,out] ARG Pointer to an output object */
TgEXTN TgVOID                               tgCN_Print_Command_Functions( STg2_Output_P ARG );

/*# TgCOMPILE__CONSOLE */
#endif

/** @} TGS_COMMON_CONSOLE */


/* =============================================================================================================================================================================== */
#endif
