/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Console.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include "TgS Common - Console - Internal.h"
#include "TgS Common - Console.inl"


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Private Data                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

STg2_UT_LF__RW                              g_sCN_Command_Name_Lock;
STg2_CN_Command_Common_P                    g_apsCN_Command_Hash_Set[KTgCN_MAX_COMMAND_HASH_SET];
STg2_CN_Command_Common_P                    g_apsCommand_Lexical_Set[KTgCN_MAX_COMMAND_LEXICAL_LIST];




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Constants                                                                                                                                                           */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if TgCOMPILE__CONSOLE

enum { KTgCN_OSCON_LINE_LENGTH             = 512 }; /**< Maximum length of a console command | buffer | display line */
enum { KTgCN_OSCON_MAX_LINE                = 256 }; /**< Number of console lines retained in the buffer */
enum { KTgCN_OSLOG_LINE_LENGTH             = 128 }; /**< Maximum length of an on screen log line */
enum { KTgCN_OSLOG_MAX_LINE                = 52  }; /**< Number of on screen log lines */

enum { KTgCN_MAX_CHANNEL                   = KTgCN_CHANEL_BITS }; /**< Maximum number of channels in the system */
enum { KTgCN_MAX_CHANNEL_OUTPUT            = 8 }; /**< Maximum number of output devices that can be attached to a single channel */

/*# TgCOMPILE__CONSOLE */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Types                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if TgCOMPILE__CONSOLE

TgTYPE_STRUCT(STg2_CN_OnScreen_Line,)
{
    TgCHAR_MB                                   m_szLog[KTgCN_OSLOG_LINE_LENGTH];
    TgUINT_F32                                  m_uiSeverity;
    TgUINT_F32                                  m_uiUID;
    TgFLOAT32                                   m_fLife_Time;
    TgUINT_F32                                  m_uiPad0;
    STg2_CN_OnScreen_Line_P                     m_psNext;
};


TgTYPE_STRUCT(STg2_CN_Command_Function,)
{
    STg2_CN_Command_Common                      m_sCommon;
    TgFCN_CONSOLE                               m_pfnExecute;
};

/*# TgCOMPILE__CONSOLE */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions and Data                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

static ETgMODULE_STATE                      s_enConsole_State = ETgMODULE_STATE__FREED;

#if TgCOMPILE__CONSOLE

static TgVOID                               tgCN_UID_Print_Internal( TgUINT_F32_C , TgUINT_F32_C , TgCHAR_MB_CP, TgRSIZE_C );
static TgVOID                               tgCN_Scroll_Display( TgSINT_F32_C , TgSINT_F32_C  );

static TgRSIZE                              tgCN_Default_Break_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgCN_Default_Abort_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );

static TgRSIZE                              tgLOG_CON_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_LOG_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_FCN_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_MEM_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_MSG_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_WRN_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_ERR_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_CRT_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_INT_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );
static TgRSIZE                              tgLOG_LDN_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );

static TgRSIZE                              tgLOG_STD_File_Write( STg2_Output_PC, TgRSIZE_C, TgVOID_CP, TgRSIZE_C );

                                            /* System state and Configuration */
static STg1_MT_MX                           s_sSystem_Lock;

                                            /* On Screen Console */
static STg1_MT_MX                           s_sOS_Lock; /* Lock for the On Screen Buffers */
static TgCHAR_MB                            s_szOS_Console_Buffer[KTgCN_OSCON_MAX_LINE][KTgCN_OSCON_LINE_LENGTH];
static TgSINT_F32                           s_iOS_Console_Buffer_Index;
static TgSINT_F32                           s_iOS_Console_Cmd_Index;
static TgSINT_F32                           s_iOS_Console_Display_Index;
static TgSINT_F32                           s_iOS_Console_Cmd_History_Index;
static TgBOOL                               s_bOS_Console_Render;
static TgSINT_F32                           s_iOS_Console_Render_Page_Height;
static TgSINT_F32                           s_iOS_Console_Render_Font_Height;
static STg2_CN_OnScreen_Line                s_asOS_Log_Data[KTgCN_OSLOG_MAX_LINE];
static STg2_CN_OnScreen_Line_P              s_psOS_Log_Display;
static STg2_CN_OnScreen_Line_P              s_psOS_Log_Free;
static TgFLOAT32                            s_fOS_Log_Default_Life_Time;

                                            /* Console Command List */
static STg2_CN_Command_Function             s_asCommand_Function[KTgCN_MAX_COMMAND_FCN]; /* This is the key for the group */
static STg2_UT_LF_ISO__ST                   s_sCommand_Function_Stack;
static TgSINT_F32                           s_niCommand_Function_Used;

                                            /* Channel Descriptors and Information */
static TgCHAR_MB_CP                         s_pzOutput_Prefix[KTgCN_MAX_CHANNEL];
static TgRSIZE                              s_nbyOutput_Prefix[KTgCN_MAX_CHANNEL];
static TgBOOL                               s_abOutput_Prefix[KTgCN_MAX_CHANNEL]; /* Tracks whether we are at the start of a line */
static STg2_Output_P                        s_apsOutput[KTgCN_MAX_CHANNEL][KTgCN_MAX_CHANNEL_OUTPUT];
static TgUINT_F32                           s_auiUID_Filter[KTgCN_MAX_CHANNEL];
static TgUINT_F32                           s_auiSeverity_Filter[KTgCN_MAX_CHANNEL];

                                            /* Default Output Functions */
static STg2_Output                          s_sDefault_Output_Break;
static STg2_Output                          s_sDefault_Output_Abort;
static TgSINT_PTR                           s_iLOG_Output_File;
static STg2_Output                          s_sOuput_Std = { tgLOG_STD_File_Write, nullptr };

                                            /* Default Prefixes for channel output */
static TgCHAR_MB_C                          s_szPrefix_Console[] = "CON: ";
static STg2_Output                          s_sOuput_Console = { tgLOG_CON_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Console_File;
static TgCHAR_MB_C                          s_szPrefix_Log_Screen[] = "SCN: ";
static TgCHAR_MB_C                          s_szPrefix_Log[] = "LOG: ";
static STg2_Output                          s_sOuput_Log = { tgLOG_LOG_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Log_File;
static TgCHAR_MB_C                          s_szPrefix_Log_FCN[] = "FCN: ";
static STg2_Output                          s_sOuput_Log_FCN = { tgLOG_FCN_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Log_FCN_File;
static TgCHAR_MB_C                          s_szPrefix_Log_MEM[] = "MEM: ";
static STg2_Output                          s_sOuput_Log_Mem = { tgLOG_MEM_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Log_Mem_File;
static TgCHAR_MB_C                          s_szPrefix_Message[] = "MSG: ";
static STg2_Output                          s_sOuput_Msg = { tgLOG_MSG_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Msg_File;
static TgCHAR_MB_C                          s_szPrefix_Warning[] = "WRN: ";
static STg2_Output                          s_sOuput_Wrn = { tgLOG_WRN_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Wrn_File;
static TgCHAR_MB_C                          s_szPrefix_Error[] = "ERR: ";
static STg2_Output                          s_sOuput_Err = { tgLOG_ERR_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Err_File;
static TgCHAR_MB_C                          s_szPrefix_Critical[] = "CRT: ";
static STg2_Output                          s_sOuput_Crt = { tgLOG_CRT_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Crt_File;
static TgCHAR_MB_C                          s_szPrefix_Initialize[] = "INT: ";
static STg2_Output                          s_sOuput_Int = { tgLOG_INT_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Int_File;
static TgCHAR_MB_C                          s_szPrefix_Loading[] = "LDN: ";
static STg2_Output                          s_sOuput_Ldn = { tgLOG_LDN_File_Write, nullptr };
static TgSINT_PTR                           s_iOuput_Ldn_File;

/*# TgCOMPILE__CONSOLE */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCN_Init ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* NOTE: Called prior to MM and SM Init */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgCN_Init( TgVOID )
{
    TgSINT_F32                          iIndex, iIndex2;

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__FREED == s_enConsole_State);
    s_enConsole_State = ETgMODULE_STATE__INITIALIZING;
    (void)iIndex;
    (void)iIndex2;

    /* Initialize Console Command Common Data - Console Variables are always compiled */
    TgVERIFY( KTgS_OK == tgCM_UT_LF__RW__Init( &g_sCN_Command_Name_Lock ) );
    tgMM_Set_U08_0x00( (TgVOID_P)g_apsCN_Command_Hash_Set, sizeof( g_apsCN_Command_Hash_Set ) );
    tgMM_Set_U08_0x00( (TgVOID_P)g_apsCommand_Lexical_Set, sizeof( g_apsCommand_Lexical_Set ) );

#if TgCOMPILE__CONSOLE

    TgCOMPILER_ASSERT( (1 << KTgCN_SEVERITY_BITS) > 3, 0 );

    /* Initialize system variables */
#if TgCOMPILE__THREAD
    TgVERIFY( KTgS_OK == tgPM_MT_MX_Init( &s_sSystem_Lock, nullptr ) );
/*# TgCOMPILE__THREAD */
#endif

    /* Initialize On Screen Console and Logging */
    tgPM_MT_MX_Init( &s_sOS_Lock, nullptr );
    tgMM_Set_U08_0x00( s_szOS_Console_Buffer, sizeof( s_szOS_Console_Buffer ) );
    s_iOS_Console_Buffer_Index = 0;
    s_iOS_Console_Cmd_Index = 0;
    s_iOS_Console_Display_Index = 0;
    s_iOS_Console_Cmd_History_Index = 0;
    s_bOS_Console_Render = false;
    s_iOS_Console_Render_Page_Height = 0;
    s_iOS_Console_Render_Font_Height = 0;
    tgMM_Set_U08_0x00( s_asOS_Log_Data, sizeof( s_asOS_Log_Data ) );
    s_psOS_Log_Display = nullptr;
    s_psOS_Log_Free = s_asOS_Log_Data;
    s_fOS_Log_Default_Life_Time = 10.0F;

    /* Attach sequential elements of the on screen log link list */
    for (iIndex = 0; iIndex + 1 < KTgCN_OSLOG_MAX_LINE; ++iIndex)
    {
        s_asOS_Log_Data[iIndex].m_psNext = s_asOS_Log_Data + iIndex + 1;
    };

    /* Initialize Console Command Function Data */
    tgMM_Set_U08_0x00( s_asCommand_Function, sizeof( s_asCommand_Function ) );
    s_niCommand_Function_Used = 0;
    tgCM_UT_LF__ST__Init_PreLoad( &s_sCommand_Function_Stack.m_sStack, s_asCommand_Function, sizeof( STg2_CN_Command_Function ), KTgCN_MAX_COMMAND_FCN );

    /* Initialize Channel Descriptors and Information */
    tgMM_Set_U08_0x00( s_nbyOutput_Prefix, sizeof( s_nbyOutput_Prefix ) );
    for (iIndex = 0; iIndex < KTgCN_MAX_CHANNEL; ++iIndex)
    {
        s_pzOutput_Prefix[iIndex] = nullptr;
        s_abOutput_Prefix[iIndex] = true;
        s_auiUID_Filter[iIndex] = KTgUID_NONE;
        s_auiSeverity_Filter[iIndex] = KTgCN_MAX_SEVERITY;
        for (iIndex2 = 0; iIndex2 < KTgCN_MAX_CHANNEL_OUTPUT; ++iIndex2)
            s_apsOutput[iIndex][iIndex2] = nullptr;
    };

    /* Create the two default output objects */
    s_sDefault_Output_Break.m_pfnWrite = tgCN_Default_Break_Write;
    s_sDefault_Output_Break.m_pfnClose = nullptr;
    s_sDefault_Output_Abort.m_pfnWrite = tgCN_Default_Abort_Write;
    s_sDefault_Output_Abort.m_pfnClose = nullptr;

    /* Preset some of the variables */
    s_pzOutput_Prefix[0] = s_szPrefix_Console;
    s_nbyOutput_Prefix[0] = tgMBZ_Length_U08( s_pzOutput_Prefix[0], KTgMAX_RSIZE );
    s_iOuput_Console_File = -1;
    s_pzOutput_Prefix[1] = s_szPrefix_Log_Screen;
    s_nbyOutput_Prefix[1] = tgMBZ_Length_U08( s_pzOutput_Prefix[1], KTgMAX_RSIZE );
    s_pzOutput_Prefix[2] = s_szPrefix_Log;
    s_nbyOutput_Prefix[2] = tgMBZ_Length_U08( s_pzOutput_Prefix[2], KTgMAX_RSIZE );
    s_iOuput_Log_File = -1;
    s_pzOutput_Prefix[3] = s_szPrefix_Log_FCN;
    s_nbyOutput_Prefix[3] = tgMBZ_Length_U08( s_pzOutput_Prefix[3], KTgMAX_RSIZE );
    s_iOuput_Log_FCN_File = -1;
    s_pzOutput_Prefix[4] = s_szPrefix_Log_MEM;
    s_nbyOutput_Prefix[4] = tgMBZ_Length_U08( s_pzOutput_Prefix[4], KTgMAX_RSIZE );
    s_iOuput_Log_Mem_File = -1;
    s_pzOutput_Prefix[5] = s_szPrefix_Message;
    s_nbyOutput_Prefix[5] = tgMBZ_Length_U08( s_pzOutput_Prefix[5], KTgMAX_RSIZE );
    s_iOuput_Msg_File = -1;
    s_pzOutput_Prefix[6] = s_szPrefix_Warning;
    s_nbyOutput_Prefix[6] = tgMBZ_Length_U08( s_pzOutput_Prefix[6], KTgMAX_RSIZE );
    s_iOuput_Wrn_File = -1;
    s_pzOutput_Prefix[7] = s_szPrefix_Error;
    s_nbyOutput_Prefix[7] = tgMBZ_Length_U08( s_pzOutput_Prefix[7], KTgMAX_RSIZE );
    s_iOuput_Err_File = -1;
    s_pzOutput_Prefix[8] = s_szPrefix_Critical;
    s_nbyOutput_Prefix[8] = tgMBZ_Length_U08( s_pzOutput_Prefix[8], KTgMAX_RSIZE );
    s_iOuput_Crt_File = -1;
    s_pzOutput_Prefix[9] = s_szPrefix_Initialize;
    s_nbyOutput_Prefix[9] = tgMBZ_Length_U08( s_pzOutput_Prefix[9], KTgMAX_RSIZE );
    s_iOuput_Int_File = -1;
    s_pzOutput_Prefix[10] = s_szPrefix_Loading;
    s_nbyOutput_Prefix[10] = tgMBZ_Length_U08( s_pzOutput_Prefix[10], KTgMAX_RSIZE );
    s_iOuput_Ldn_File = -1;

/*# TgCOMPILE__CONSOLE */
#endif

    s_enConsole_State = ETgMODULE_STATE__INITIALIZED;

    tgCN_Var_Init();
    return (KTgS_OK);
}


/* ---- tgCN_Boot ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* NOTE: Called prior to MM and SM Init */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgCN_Boot( TgVOID )
{
    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__INITIALIZED == s_enConsole_State);

#if TgCOMPILE__CONSOLE

    if (TgSUCCEEDED( s_iOuput_Console_File = tgIO_File_Open( "teikitu_console.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_CONSOLE, &s_sOuput_Console );
    if (TgSUCCEEDED( s_iOuput_Log_File = tgIO_File_Open( "teikitu_log.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_LOG, &s_sOuput_Log );
    if (TgSUCCEEDED( s_iOuput_Log_FCN_File = tgIO_File_Open( "teikitu_log_fcn.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_LOG_FCN, &s_sOuput_Log_FCN );
    if (TgSUCCEEDED( s_iOuput_Log_Mem_File = tgIO_File_Open( "teikitu_memory.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_LOG_MEM, &s_sOuput_Log_Mem );
    if (TgSUCCEEDED( s_iOuput_Msg_File = tgIO_File_Open( "teikitu_message.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_MESSAGE, &s_sOuput_Msg );
    if (TgSUCCEEDED( s_iOuput_Wrn_File = tgIO_File_Open( "teikitu_warning.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_WARNING, &s_sOuput_Wrn );
    if (TgSUCCEEDED( s_iOuput_Err_File = tgIO_File_Open( "teikitu_error.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_ERROR, &s_sOuput_Err );
    if (TgSUCCEEDED( s_iOuput_Crt_File = tgIO_File_Open( "teikitu_critical.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_CRITICAL, &s_sOuput_Crt );
    if (TgSUCCEEDED( s_iOuput_Int_File = tgIO_File_Open( "teikitu_init.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
    {
        tgCN_Attach_Output( KTgCN_CHANEL_INITIALIZE, &s_sOuput_Int );
        tgCN_Attach_Output( KTgCN_CHANEL_INITIALIZE_MEMORY, &s_sOuput_Int );
    };
    if (TgSUCCEEDED( s_iOuput_Ldn_File = tgIO_File_Open( "teikitu_loading.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
        tgCN_Attach_Output( KTgCN_CHANEL_LOADING, &s_sOuput_Ldn );

    if (TgSUCCEEDED( s_iLOG_Output_File = tgIO_File_Open( "teikitu_output.log", KTgMAX_RSIZE, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE | ETgFILE_IO_ACCESS__SHARED ) ))
    {
        tgCN_Attach_Output( KTgCN_CHANEL_LOG, &s_sOuput_Std );
        tgCN_Attach_Output( KTgCN_CHANEL_LOG_FCN, &s_sOuput_Std );
        tgCN_Attach_Output( KTgCN_CHANEL_MESSAGE, &s_sOuput_Std );
        tgCN_Attach_Output( KTgCN_CHANEL_WARNING, &s_sOuput_Std );
        tgCN_Attach_Output( KTgCN_CHANEL_ERROR, &s_sOuput_Std );
        tgCN_Attach_Output( KTgCN_CHANEL_CRITICAL, &s_sOuput_Std );
        tgCN_Attach_Output( KTgCN_CHANEL_INITIALIZE, &s_sOuput_Std );
        tgCN_Attach_Output( KTgCN_CHANEL_INITIALIZE_MEMORY, &s_sOuput_Std );
        tgCN_Attach_Output( KTgCN_CHANEL_LOADING, &s_sOuput_Std );
    };

/*# TgCOMPILE__CONSOLE */
#endif

    s_enConsole_State = ETgMODULE_STATE__BOOTED;

    tgCN_Var_Boot();
    return (KTgS_OK);
}


/* ---- tgCN_Stop ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCN_Stop( TgVOID )
{
    if (ETgMODULE_STATE__FREED == s_enConsole_State || ETgMODULE_STATE__INITIALIZED == s_enConsole_State)
    {
        return;
    };

    tgCN_Var_Stop();

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__BOOTED == s_enConsole_State);

#if TgCOMPILE__CONSOLE
    if (tgIO_File_Valid( s_iLOG_Output_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_LOADING, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_INITIALIZE_MEMORY, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_INITIALIZE, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_CRITICAL, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_ERROR, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_WARNING, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_MESSAGE, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_LOG_MEM, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_LOG_FCN, &s_sOuput_Std );
        tgCN_Remove_Output( KTgCN_CHANEL_LOG, &s_sOuput_Std );

        tgIO_File_Close( s_iLOG_Output_File );
        s_iLOG_Output_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Ldn_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_LOADING, &s_sOuput_Ldn );
        tgIO_File_Close( s_iOuput_Ldn_File );
        s_iOuput_Ldn_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Int_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_INITIALIZE_MEMORY, &s_sOuput_Int );
        tgCN_Remove_Output( KTgCN_CHANEL_INITIALIZE, &s_sOuput_Int );
        tgIO_File_Close( s_iOuput_Int_File );
        s_iOuput_Int_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Crt_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_CRITICAL, &s_sOuput_Crt );
        tgIO_File_Close( s_iOuput_Crt_File );
        s_iOuput_Crt_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Err_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_ERROR, &s_sOuput_Err );
        tgIO_File_Close( s_iOuput_Err_File );
        s_iOuput_Err_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Wrn_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_WARNING, &s_sOuput_Wrn );
        tgIO_File_Close( s_iOuput_Wrn_File );
        s_iOuput_Wrn_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Msg_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_MESSAGE, &s_sOuput_Msg );
        tgIO_File_Close( s_iOuput_Msg_File );
        s_iOuput_Msg_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Log_Mem_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_LOG_MEM, &s_sOuput_Log_Mem );
        tgIO_File_Close( s_iOuput_Log_Mem_File );
        s_iOuput_Log_Mem_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Log_FCN_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_LOG_FCN, &s_sOuput_Log_FCN );
        tgIO_File_Close( s_iOuput_Log_FCN_File );
        s_iOuput_Log_FCN_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Log_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_LOG, &s_sOuput_Log );
        tgIO_File_Close( s_iOuput_Log_File );
        s_iOuput_Log_File = -1;
    };

    if (tgIO_File_Valid( s_iOuput_Console_File ))
    {
        tgCN_Remove_Output( KTgCN_CHANEL_CONSOLE, &s_sOuput_Console );
        tgIO_File_Close( s_iOuput_Console_File );
        s_iOuput_Console_File = -1;
    };
/*# TgCOMPILE__CONSOLE */
#endif

    s_enConsole_State = ETgMODULE_STATE__STOPPED;
}


/* ---- tgCN_Free ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCN_Free( TgVOID )
{
    TgSINT_F32                          iIndex;

    if (ETgMODULE_STATE__FREED == s_enConsole_State)
    {
        return;
    };

    (TgVOID)iIndex;

    tgCN_Var_Free();

#if TgCOMPILE__CONSOLE

    tgPM_MT_MX_Wait_Block( &s_sSystem_Lock );

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__STOPPED == s_enConsole_State || ETgMODULE_STATE__INITIALIZED == s_enConsole_State);
    s_enConsole_State = ETgMODULE_STATE__FREEING;

    /* Clear out all of the console functions registered with the system.  Entities that install console functions are expected to remove them when no longer needed. */
    /* Thus, by the time this module is freed all functions should have been removed. */
    for (iIndex = 0; iIndex < KTgCN_MAX_COMMAND_FCN; ++iIndex)
    {
        STg2_CN_Command_Function_P          psCmd_Fcn;

        psCmd_Fcn = s_asCommand_Function + iIndex;
        if (nullptr == psCmd_Fcn->m_pfnExecute)
            continue;

        TgWARNING_MSGF( 0, "%-16.16s(%-32.32s): Console command (%s) was not removed.\n", "Console", "Free_Module", psCmd_Fcn->m_sCommon.m_mbzName );
        tgCN_Remove_Command_Function( psCmd_Fcn->m_sCommon.m_mbzName, KTgMAX_SIZE_ALL );
    }

    /* Remove all output objects from the system.  Similar to above, proper life time management requires the installing entity to remove the object from the console when */
    /* it is no longer needed or used.  At this point, they should have all been removed. */
    for (iIndex = 0; iIndex < KTgCN_MAX_CHANNEL; ++iIndex)
    {
        while (0 != s_apsOutput[iIndex][0])
        {
            TgWARNING_MSGF( 0, "%-16.16s(%-32.32s): Output was not removed.\n", "Console", "Free_Module" );
            tgCN_Remove_Output( 1 << (iIndex + KTgCN_SEVERITY_BITS), s_apsOutput[iIndex][0] );
        };
    };

    /* Clear out all the prefix headers */
    tgMM_Set_U08_0x00( s_abOutput_Prefix, sizeof( s_abOutput_Prefix ) );

    /* Clear out on screen displays */
    s_iOS_Console_Cmd_Index = 0;
    s_iOS_Console_Buffer_Index = 0;
    s_iOS_Console_Display_Index = 0;

    s_psOS_Log_Display = nullptr;
    s_psOS_Log_Free = s_asOS_Log_Data;
    for (iIndex = 0; iIndex + 1 < KTgCN_OSLOG_MAX_LINE; ++iIndex)
    {
        s_asOS_Log_Data[iIndex].m_psNext = s_asOS_Log_Data + iIndex + 1;
    };

    /* Destroy the critical section */
    tgPM_MT_MX_Release( &s_sSystem_Lock );
    tgPM_MT_MX_Free( &s_sOS_Lock );
    tgPM_MT_MX_Free( &s_sSystem_Lock );

/*# TgCOMPILE__CONSOLE */
#endif

    s_enConsole_State = ETgMODULE_STATE__FREED;
}


/* ---- tgCN_Update -------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @note This should be called on the primary render thread so that messages will have at least one frame to render */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgCN_Update( TgFLOAT32_C fDT )
{
#if TgCOMPILE__CONSOLE

    STg2_CN_OnScreen_Line_P             psOS_Log_Display, psOS_Log_Display_Prev;

    tgPM_MT_MX_Wait_Block( &s_sOS_Lock );

    /* Verify the state of the system (technically should have the system lock for comparison but its validation only) */
    TgERROR(ETgMODULE_STATE__BOOTED == s_enConsole_State);

    psOS_Log_Display = s_psOS_Log_Display;
    psOS_Log_Display_Prev = nullptr;

    /* Update all messages, removing those whose life is now negative and updating the time for active messages */
    while (nullptr != psOS_Log_Display)
    {
        STg2_CN_OnScreen_Line_PC            psOS_Log_Display_Next = psOS_Log_Display->m_psNext;

        /* If the life time of this message is no longer non-negative move it from the display list to the free list.  Otherwise */
        /* decrement the life time of the message by the time delta. */
        if (0.0F >= psOS_Log_Display->m_fLife_Time)
        {
            if (nullptr != psOS_Log_Display_Prev)
            {
                psOS_Log_Display_Prev->m_psNext = psOS_Log_Display_Next;
            }
            else
            {
                s_psOS_Log_Display = psOS_Log_Display_Next;
            };
            psOS_Log_Display->m_psNext = s_psOS_Log_Free;
            s_psOS_Log_Free = psOS_Log_Display;
        }
        else
        {
            psOS_Log_Display->m_fLife_Time -= fDT;
        };

        psOS_Log_Display = psOS_Log_Display_Next;
    };

    tgPM_MT_MX_Release( &s_sOS_Lock );

/*# TgCOMPILE__CONSOLE */
#endif

    return (KTgS_OK);
}


/* ---- tgCN_Query_Init ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgEXTN TgBOOL tgCN_Query_Init( TgVOID )
{
    return (ETgMODULE_STATE__INITIALIZED <= s_enConsole_State && s_enConsole_State <= ETgMODULE_STATE__STOPPED);
}


/* ---- tgCN_Query_Boot ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgEXTN TgBOOL tgCN_Query_Boot( TgVOID )
{
    return (ETgMODULE_STATE__BOOTED == s_enConsole_State);
}


/* ---- tgCN_Query_Fixed_Memory -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgEXTN TgRSIZE tgCN_Query_Fixed_Memory( TgVOID )
{
    return (0
             + sizeof( g_sCN_Command_Name_Lock )
             + sizeof( g_apsCN_Command_Hash_Set )
             + sizeof( s_enConsole_State )
             + sizeof( g_apsCommand_Lexical_Set )
         #if TgCOMPILE__CONSOLE
             + sizeof( s_sSystem_Lock )
             + sizeof( s_sOS_Lock )
             + sizeof( s_szOS_Console_Buffer )
             + sizeof( s_iOS_Console_Buffer_Index )
             + sizeof( s_iOS_Console_Cmd_Index )
             + sizeof( s_iOS_Console_Display_Index )
             + sizeof( s_iOS_Console_Cmd_History_Index )
             + sizeof( s_bOS_Console_Render )
             + sizeof( s_iOS_Console_Render_Page_Height )
             + sizeof( s_iOS_Console_Render_Font_Height )
             + sizeof( s_asOS_Log_Data )
             + sizeof( s_psOS_Log_Display )
             + sizeof( s_psOS_Log_Free )
             + sizeof( s_fOS_Log_Default_Life_Time )
             + sizeof( s_asCommand_Function )
             + sizeof( s_sCommand_Function_Stack )
             + sizeof( s_niCommand_Function_Used )
             + sizeof( s_pzOutput_Prefix )
             + sizeof( s_nbyOutput_Prefix )
             + sizeof( s_abOutput_Prefix )
             + sizeof( s_apsOutput )
             + sizeof( s_auiUID_Filter )
             + sizeof( s_auiSeverity_Filter )
             + sizeof( s_sDefault_Output_Break )
             + sizeof( s_sDefault_Output_Abort )
             + sizeof( s_iLOG_Output_File )
             + sizeof( s_sOuput_Std )
             + sizeof( s_szPrefix_Console )
             + sizeof( s_sOuput_Console )
             + sizeof( s_iOuput_Console_File )
             + sizeof( s_szPrefix_Log_Screen )
             + sizeof( s_szPrefix_Log )
             + sizeof( s_sOuput_Log )
             + sizeof( s_iOuput_Log_File )
             + sizeof( s_szPrefix_Log_FCN )
             + sizeof( s_sOuput_Log_FCN )
             + sizeof( s_iOuput_Log_FCN_File )
             + sizeof( s_szPrefix_Log_MEM )
             + sizeof( s_sOuput_Log_Mem )
             + sizeof( s_iOuput_Log_Mem_File )
             + sizeof( s_szPrefix_Message )
             + sizeof( s_sOuput_Msg )
             + sizeof( s_iOuput_Msg_File )
             + sizeof( s_szPrefix_Warning )
             + sizeof( s_sOuput_Wrn )
             + sizeof( s_iOuput_Wrn_File )
             + sizeof( s_szPrefix_Error )
             + sizeof( s_sOuput_Err )
             + sizeof( s_iOuput_Err_File )
             + sizeof( s_szPrefix_Critical )
             + sizeof( s_sOuput_Crt )
             + sizeof( s_iOuput_Crt_File )
             + sizeof( s_szPrefix_Initialize )
             + sizeof( s_sOuput_Int )
             + sizeof( s_iOuput_Int_File )
             + sizeof( s_szPrefix_Loading )
             + sizeof( s_sOuput_Ldn )
             + sizeof( s_iOuput_Ldn_File )
         /*# TgCOMPILE__CONSOLE */
         #endif
    );
}


/* ---- tgCN_Print_Commands ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCN_Print_Commands( STg2_Output_P psOUT )
{
#if TgCOMPILE__CONSOLE
    tgCN_Print_Command_Functions( psOUT );
#endif
    tgCN_Print_Command_Variables( psOUT );
}


/* ---- tgCN_Execute_Command ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL tgCN_Execute_Command( TgCHAR_MB_CPC mbzCmdLN, TgRSIZE_C nbyMaxCmdLN )
{
    TgRSIZE                             uiLength;
    TgCHAR_MB_P                         szCmdLN;
    TgUINT_F32                          nuiArg;
    TgCHAR_MB_CP                        mbzArg[KTgMAX_CMD_LINE_COUNT];
    TgUINT_MAX                          uiHash;
    STg2_CN_Command_Common_P            psCmd;
    TgBOOL                              bRet;
    TgCN_VAR_ID                         tiCN_Var;
#if TgCOMPILE__CONSOLE
    STg2_CN_Command_Function_P          psCmd_Fcn;
/*# TgCOMPILE__CONSOLE */
#endif

    uiLength = tgMBZ_Length_U08( mbzCmdLN, nbyMaxCmdLN ) + 1;

    /* Create a copy of the command line on the local stack (parsing modifies the string) */
    TgALLOCA( TgCHAR_MB, uiLength, szCmdLN );
    tgMBZ_Copy( szCmdLN, uiLength, mbzCmdLN, nbyMaxCmdLN );

    /* Parse the command line (use the global function used to parse the executable command line) */
    nuiArg = tgGB_Parse_Command_Line( mbzArg, KTgMAX_CMD_LINE_COUNT, szCmdLN );

    /* Make sure we have a command to execute before taking the critical section */
    if (nuiArg <= 0 || !mbzArg[0] || !mbzArg[0][0])
    {
        TgFREEA( szCmdLN );
        return (false);
    };

    if (TgFAILED(tgMBZ_Hash( &uiHash, mbzArg[0], KTgMAX_SIZE_ALL )))
    {
        TgFREEA( szCmdLN );
        return (false);
    };

    tgCM_UT_LF__RW__Enter_Read_Wait_Yield( &g_sCN_Command_Name_Lock );

    do
    {
        bRet = false;

        /* Check to see if it exists in the hash set */
        psCmd = tgCN_Find_Command_In_Hash( mbzArg[0], uiHash );
        if (nullptr == psCmd)
        {
            break;
        };

    #if TgCOMPILE__CONSOLE
        if (ETgCN_COMMAND__FCN == psCmd->m_uiType)
        {
            psCmd_Fcn = (STg2_CN_Command_Function_P)psCmd;
            if (nullptr != psCmd_Fcn->m_pfnExecute)
            {
                /* This function call must be within the critical section so that removals can be guaranteed that there are no in-flight executions of their functions. */
                /* This means it is safe for a system to remove a console function and then tear down all support for it - without having to worry about possible delay */
                /* execution of the function. */
                psCmd_Fcn->m_pfnExecute( nuiArg, mbzArg );
            };

            bRet = true;
            break;
        }
    /*# TgCOMPILE__CONSOLE */
    #endif

        tiCN_Var = tgCN_Var_Query_Id_Internal( psCmd );

        if (ETgCN_COMMAND__VAR_F32_04 == psCmd->m_uiType)
        {
            TgVEC_F32_04_1                      vValue;

            if (nuiArg == 1)
            {
                bRet = tgCtgMH_Var_Query_N_F32_04_1( &vValue, tiCN_Var );
                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: [%f, %f, %f, %f]",
                                psCmd->m_mbzName, (TgFLOAT64)vValue.x, (TgFLOAT64)vValue.y, (TgFLOAT64)vValue.z, (TgFLOAT64)vValue.w );
                };
            }
            else if (nuiArg == 5)
            {
                vValue.x = tgMBZ_To_F32( mbzArg[1], KTgMAX_SIZE_ALL );
                vValue.y = tgMBZ_To_F32( mbzArg[2], KTgMAX_SIZE_ALL );
                vValue.z = tgMBZ_To_F32( mbzArg[3], KTgMAX_SIZE_ALL );
                vValue.w = tgMBZ_To_F32( mbzArg[4], KTgMAX_SIZE_ALL );
                bRet = tgCtgMH_Var_Set_N_F32_04_1( tiCN_Var, vValue );
                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: [%f, %f, %f, %f]",
                                psCmd->m_mbzName, (TgFLOAT64)vValue.x, (TgFLOAT64)vValue.y, (TgFLOAT64)vValue.z, (TgFLOAT64)vValue.w );
                };
            };
            break;
        };

        if (nuiArg > 2)
        {
            break;
        };

        switch (psCmd->m_uiType)
        {
            case ETgCN_COMMAND__VAR_BOOL:
            {
                TgBOOL                              bValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_Bool( &bValue, tiCN_Var );
                }
                else
                {
                    bValue = tgMBZ_To_Bool( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_Bool( tiCN_Var, bValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %d", psCmd->m_mbzName, bValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_S08:
            {
                TgSINT_F08                          iValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_S08( &iValue, tiCN_Var );
                }
                else
                {
                    iValue = tgMBZ_To_S08( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_S08( tiCN_Var, iValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %d", psCmd->m_mbzName, iValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_S16:
            {
                TgSINT_F16                          iValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_S16( &iValue, tiCN_Var );
                }
                else
                {
                    iValue = tgMBZ_To_S16( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_S16( tiCN_Var, iValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %d", psCmd->m_mbzName, iValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_S32:
            {
                TgSINT_F32                          iValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_S32( &iValue, tiCN_Var );
                }
                else
                {
                    iValue = tgMBZ_To_S32( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_S32( tiCN_Var, iValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %d", psCmd->m_mbzName, iValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_S64:
            {
                TgSINT_F64                          iValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_S64( &iValue, tiCN_Var );
                }
                else
                {
                    iValue = tgMBZ_To_S64( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_S64( tiCN_Var, iValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %I64d", psCmd->m_mbzName, iValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_U08:
            {
                TgUINT_F08                          uiValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_U08( &uiValue, tiCN_Var );
                }
                else
                {
                    uiValue = tgMBZ_To_U08( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_U08( tiCN_Var, uiValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %d", psCmd->m_mbzName, uiValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_U16:
            {
                TgUINT_F16                          uiValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_U16( &uiValue, tiCN_Var );
                }
                else
                {
                    uiValue = tgMBZ_To_U16( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_U16( tiCN_Var, uiValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %d", psCmd->m_mbzName, uiValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_U32:
            {
                TgUINT_F32                          uiValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_U32( &uiValue, tiCN_Var );
                }
                else
                {
                    uiValue = tgMBZ_To_U32( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_U32( tiCN_Var, uiValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %d", psCmd->m_mbzName, uiValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_U64:
            {
                TgUINT_F64                          uiValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_U64( &uiValue, tiCN_Var );
                }
                else
                {
                    uiValue = tgMBZ_To_U64( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_U64( tiCN_Var, uiValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %I64d", psCmd->m_mbzName, uiValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_F32:
            {
                TgFLOAT32                           fValue;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_F32( &fValue, tiCN_Var );
                }
                else
                {
                    fValue = tgMBZ_To_F32( mbzArg[1], KTgMAX_SIZE_ALL );
                    bRet = tgCN_Var_Set_F32( tiCN_Var, fValue );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %f", psCmd->m_mbzName, (TgFLOAT64)fValue );
                };
                break;
            };

            case ETgCN_COMMAND__VAR_STRING:
            {
                TgCHAR_MB_CP                        mbzString;

                if (nuiArg == 1)
                {
                    bRet = tgCN_Var_Query_String( &mbzString, tiCN_Var );
                }
                else
                {
                    mbzString = mbzArg[1];
                    bRet = tgCN_Var_Set_String( tiCN_Var, mbzString, KTgMAX_SIZE_ALL );
                };

                if (bRet)
                {
                    tgCN_PrintF( KTgCN_CHANEL_CONSOLE, "CN VAR %s: %s", psCmd->m_mbzName, mbzString );
                };
                break;
            };

            default:
                TgS_NO_DEFAULT( break );
        };

    } while (0);

    tgCM_UT_LF__RW__Exit_Read( &g_sCN_Command_Name_Lock );
    TgFREEA( szCmdLN );
    return (bRet);
}



/* ---- tgCN_Attach_Output ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** Add the output object to the top of the stack of each of the channel's selected in the mask.  Return the value of all the channels that the object was successfully added. */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgUINT_F32 tgCN_Attach_Output( TgUINT_F32_C uiChannel_Mask, STg2_Output_PC psOutput )
{
    TgUINT_F32                          uiChannel, uiAttached;

    /* Verify function parameters */
    if ((nullptr == psOutput) || (nullptr == psOutput->m_pfnWrite))
    {
        TgCRITICAL_MSG( false, "Invalid Arguments" );
        return (0);
    };

    tgPM_MT_MX_Wait_Block( &s_sSystem_Lock );

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__INITIALIZED == s_enConsole_State || ETgMODULE_STATE__BOOTED == s_enConsole_State);

    /* Primary implementation of the function */
    for (uiChannel = 0, uiAttached = 0; uiChannel < KTgCN_MAX_CHANNEL; ++uiChannel)
    {
        /* Check to see if this channel is in the mask */
        if (0 == (uiChannel_Mask & (1 << (uiChannel + KTgCN_SEVERITY_BITS))))
        {
            continue;
        };

        /* If there is an available slot for the output object, add it to the head of the list */
        if (0 == s_apsOutput[uiChannel][KTgCN_MAX_CHANNEL_OUTPUT - 1])
        {
            tgMM_Move( &(s_apsOutput[uiChannel][1]), KTgMAX_RSIZE, &(s_apsOutput[uiChannel][0]), sizeof( s_apsOutput[uiChannel][0] )*(KTgCN_MAX_CHANNEL_OUTPUT - 1) );

            s_apsOutput[uiChannel][0] = psOutput;
            uiAttached |= 1 << (uiChannel + KTgCN_SEVERITY_BITS);
        };
    };

    tgPM_MT_MX_Release( &s_sSystem_Lock );
    return (uiAttached);
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Attach_Default_Break ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgUINT_F32 tgCN_Attach_Default_Break( TgUINT_F32_C uiChannel_Mask )
{
    return (tgCN_Attach_Output( uiChannel_Mask, &s_sDefault_Output_Break ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Attach_Default_Abort ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgUINT_F32 tgCN_Attach_Default_Abort( TgUINT_F32_C uiChannel_Mask )
{
    return (tgCN_Attach_Output( uiChannel_Mask, &s_sDefault_Output_Abort ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Remove_Output ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** Remove the output object from each of the channel's selected in the mask.  Return the value of all the channels that the functor was successfully removed. */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgUINT_F32 tgCN_Remove_Output( TgUINT_F32_C uiChannel_Mask, STg2_Output_PC psOutput )
{
    TgUINT_F32                          uiChannel, uiOutput, uiRemoved;

    /* Verify function parameters */
    if (nullptr == psOutput)
    {
        return (0);
    };

    tgPM_MT_MX_Wait_Block( &s_sSystem_Lock );

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__BOOTED == s_enConsole_State || ETgMODULE_STATE__FREEING == s_enConsole_State);

    /* Primary implementation of the function */
    for (uiChannel = 0, uiRemoved = 0; uiChannel < KTgCN_MAX_CHANNEL; ++uiChannel)
    {
        /* Check to see if this channel is in the mask */
        if (0 == (uiChannel_Mask & (1 << (uiChannel + KTgCN_SEVERITY_BITS))))
        {
            continue;
        };

        /* Iterate through all of the output objects for the channel - if found, remove and compact the list. */
        for (uiOutput = 0; uiOutput < KTgCN_MAX_CHANNEL_OUTPUT; ++uiOutput)
        {
            if (0 == s_apsOutput[uiChannel][uiOutput])
            {
                break;
            };

            if (psOutput == s_apsOutput[uiChannel][uiOutput])
            {
                for (++uiOutput; uiOutput < KTgCN_MAX_CHANNEL_OUTPUT; ++uiOutput)
                {
                    s_apsOutput[uiChannel][uiOutput - 1] = s_apsOutput[uiChannel][uiOutput];
                };

                s_apsOutput[uiChannel][uiOutput - 1] = 0;

                uiRemoved |= 1 << (uiChannel + KTgCN_SEVERITY_BITS);
                break;
            };
        };
    };

    tgPM_MT_MX_Release( &s_sSystem_Lock );
    return (uiRemoved);
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Remove_Default_Break ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgUINT_F32 tgCN_Remove_Default_Break( TgUINT_F32_C uiChannel_Mask )
{
    return (tgCN_Remove_Output( uiChannel_Mask, &s_sDefault_Output_Break ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Remove_Default_Abort ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgUINT_F32 tgCN_Remove_Default_Abort( TgUINT_F32_C uiChannel_Mask )
{
    return (tgCN_Remove_Output( uiChannel_Mask, &s_sDefault_Output_Abort ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Set_Prefix ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_Set_Prefix( TgUINT_F32_C uiChannel_Mask, TgCHAR_MB_CPC mbzPrefix, TgRSIZE_C nbyMaxPrefix )
{
    TgUINT_F32                          uiChannel;

    tgPM_MT_MX_Wait_Block( &s_sSystem_Lock );

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__BOOTED == s_enConsole_State);

    for (uiChannel = 0; uiChannel < KTgCN_MAX_CHANNEL; ++uiChannel)
    {
        /* Check to see if this channel is in the mask */
        if (0 == (uiChannel_Mask & (1 << (uiChannel + KTgCN_SEVERITY_BITS))))
        {
            continue;
        };

        s_pzOutput_Prefix[uiChannel] = mbzPrefix;
        s_nbyOutput_Prefix[uiChannel] = nullptr == mbzPrefix ? 0 : tgMBZ_Length_U08( mbzPrefix, nbyMaxPrefix );
    };

    tgPM_MT_MX_Release( &s_sSystem_Lock );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Set_UID_Filter ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_Set_UID_Filter( TgUINT_F32_C uiChannel_Mask, TgUINT_F32_C uiUID )
{
    TgUINT_F32                          uiChannel;

    tgPM_MT_MX_Wait_Block( &s_sSystem_Lock );

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__BOOTED == s_enConsole_State);

    for (uiChannel = 0; uiChannel < KTgCN_MAX_CHANNEL; ++uiChannel)
    {
        /* Check to see if this channel is in the mask */
        if (0 == (uiChannel_Mask & (1 << (uiChannel + KTgCN_SEVERITY_BITS))))
        {
            continue;
        };

        s_auiUID_Filter[uiChannel] = uiUID;
    };

    tgPM_MT_MX_Release( &s_sSystem_Lock );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Set_Severity_Filter ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_Set_Severity_Filter( TgUINT_F32_C uiChannel_Mask, TgUINT_F32_C uiSeverity )
{
    TgUINT_F32                          uiChannel;

    tgPM_MT_MX_Wait_Block( &s_sSystem_Lock );

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__BOOTED == s_enConsole_State);

    for (uiChannel = 0; uiChannel < KTgCN_MAX_CHANNEL; ++uiChannel)
    {
        /* Check to see if this channel is in the mask */
        if (0 == (uiChannel_Mask & (1 << (uiChannel + KTgCN_SEVERITY_BITS))))
        {
            continue;
        };

        s_auiSeverity_Filter[uiChannel] = tgCM_MIN_U32( uiSeverity, KTgCN_MAX_SEVERITY );
    };

    tgPM_MT_MX_Release( &s_sSystem_Lock );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Print --------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_Print( TgUINT_F32_C uiChannel_Mask, TgCHAR_MB_CP mbzText, TgRSIZE_C nbyMaxText )
{
    /* Execute the standard print function */
    tgCN_UID_Print_Internal( KTgUID_NONE, uiChannel_Mask, mbzText, nbyMaxText );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_PrintF -------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_PrintF( TgUINT_F32_C uiChannel_Mask, TgCHAR_MB_CP mbzText, ... )
{
    TgCHAR_MB                           szBuffer[KTgCN_OSCON_LINE_LENGTH + 1];
    va_list                             argptr;

    /* Create the text string from the printf format */
    va_start( argptr, mbzText );
    TgVERIFY(TgSUCCEEDED(tgMBZ_PrintVF( szBuffer, KTgCN_OSCON_LINE_LENGTH, mbzText, argptr )));
    va_end( argptr );

    /* Execute the standard print function */
    tgCN_UID_Print_Internal( KTgUID_NONE, uiChannel_Mask, szBuffer, sizeof szBuffer );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_UID_Print ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_UID_Print( TgUINT_F32_C uiUID, TgUINT_F32_C uiChannel_Mask, TgCHAR_MB_CP mbzText, TgRSIZE_C nbyMaxText )
{
    /* Execute the standard print function */
    tgCN_UID_Print_Internal( uiUID, uiChannel_Mask, mbzText, nbyMaxText );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_UID_PrintF ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_UID_PrintF( TgUINT_F32_C uiUID, TgUINT_F32_C uiChannel_Mask, TgCHAR_MB_CP mbzText, ... )
{
    TgCHAR_MB                           szBuffer[KTgCN_OSCON_LINE_LENGTH + 1];
    va_list                             argptr;

    /* Create the text string from the printf format */
    va_start( argptr, mbzText );
    tgMBZ_PrintVF( szBuffer, KTgCN_OSCON_LINE_LENGTH, mbzText, argptr );
    va_end( argptr );

    /* Execute the standard print function */
    tgCN_UID_Print_Internal( uiUID, uiChannel_Mask, szBuffer, sizeof szBuffer );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Process_Input ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* This can only be called by a single thread (the input system).  It is not globally multi-thread safe */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_Process_Input( TgCHAR_WC tgKey, TgBOOL bCtrl )
{
    /* Enforce the string length limits of the buffer. */
    if (s_iOS_Console_Cmd_Index + 4 > KTgCN_OSCON_LINE_LENGTH)
    {
        return;
    };

    tgPM_MT_MX_Wait_Block( &s_sOS_Lock );

    switch (tgKey)
    {
        case 0x08: /**< Backspace */
            s_iOS_Console_Cmd_Index = tgCM_MAX_S32( s_iOS_Console_Cmd_Index - 1, 2 );
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][s_iOS_Console_Cmd_Index] = 0;
            break;
        case 0x09: /**< Tab */
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][s_iOS_Console_Cmd_Index++] = ' ';
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][s_iOS_Console_Cmd_Index++] = ' ';
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][s_iOS_Console_Cmd_Index++] = ' ';
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][s_iOS_Console_Cmd_Index++] = ' ';
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][s_iOS_Console_Cmd_Index] = 0;
            break;
        case 0x0D: /**< Enter */
            tgCN_Execute_Command( s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index] + 2, KTgMAX_RSIZE );
            s_iOS_Console_Display_Index = s_iOS_Console_Buffer_Index;
            s_iOS_Console_Buffer_Index = (s_iOS_Console_Buffer_Index + 1) % KTgCN_OSCON_MAX_LINE;
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][0] = '>';
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][1] = ' ';
            s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][2] = 0;
            s_iOS_Console_Cmd_Index = 2;
            s_iOS_Console_Cmd_History_Index = 0;
            break;
        case '`':
            s_bOS_Console_Render = !s_bOS_Console_Render;
            break;

        case 0x21:
            if (bCtrl)
            {
                tgCN_Scroll_Display( 0, -1 );
            }
            else
            {
            };
            break;
        case 0x22:
            if (bCtrl)
            {
                tgCN_Scroll_Display( 0, 1 );
            }
            else
            {
            };
            break;
        case 0x23:
            if (bCtrl)
            {
                s_iOS_Console_Display_Index = s_iOS_Console_Buffer_Index;
            }
            else
            {
            };
            break;
        case 0x24:
            if (bCtrl)
            {
            }
            else
            {
            };
            break;
        case 0x25: /**< Left */
            break;
        case 0x26:
            if (bCtrl)
            {
                tgCN_Scroll_Display( -1, 0 );
            }
            else if (s_iOS_Console_Cmd_History_Index < KTgCN_OSCON_MAX_LINE - 1)
            {
                TgSINT_F32                          iIndex;

                ++s_iOS_Console_Cmd_History_Index;
                iIndex = (KTgCN_OSCON_MAX_LINE + s_iOS_Console_Buffer_Index - s_iOS_Console_Cmd_History_Index) % KTgCN_OSCON_MAX_LINE;
                tgMBZ_Copy( s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index], KTgCN_OSCON_LINE_LENGTH, s_szOS_Console_Buffer[iIndex], KTgMAX_SIZE_ALL );
            };
            break;
        case 0x27: /**< Right */
            break;
        case 0x28:
            if (bCtrl)
            {
                tgCN_Scroll_Display( 1, 0 );
            }
            else if (s_iOS_Console_Cmd_History_Index > 0)
            {
                if (0 == --s_iOS_Console_Cmd_History_Index)
                {
                    s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][0] = 0;
                }
                else
                {
                    TgSINT_F32                          iIndex;

                    iIndex = (KTgCN_OSCON_MAX_LINE + s_iOS_Console_Buffer_Index - s_iOS_Console_Cmd_History_Index) % KTgCN_OSCON_MAX_LINE;
                    tgMBZ_Copy( s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index], KTgCN_OSCON_LINE_LENGTH, s_szOS_Console_Buffer[iIndex], KTgMAX_SIZE_ALL );
                };
            };
            break;

        default:
            if (tgKey >= 0x20)
            {
                /* FIXME: Need to rethink this for MB */
                s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][s_iOS_Console_Cmd_Index++] = (TgCHAR_MB)tgKey;
                s_szOS_Console_Buffer[s_iOS_Console_Buffer_Index][s_iOS_Console_Cmd_Index] = 0;
            };
            break;
    };

    tgPM_MT_MX_Release( &s_sOS_Lock );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Insert_Command_Function --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgBOOL tgCN_Insert_Command_Function( TgCHAR_MB_CPC mbzName, TgRSIZE nbyMaxName, TgFCN_CONSOLE pfnExecute, TgCHAR_MB_CPC mbzDesc, TgRSIZE_C nbyMaxDesc )
{
    STg2_CN_Command_Function_P          psCmd_Fcn;
    TgSTRING_DICT_ID                    tiString;
    STg2_CN_Command_Common_P            psCmd_Ret;
    TgRESULT                            iRet;

    TgPARAM_CHECK(nullptr != mbzName && mbzName[0]);
    TgPARAM_CHECK(nullptr != pfnExecute);
    TgPARAM_CHECK((nbyMaxName <= KTgMAX_RSIZE) || (KTgMAX_SIZE_ALL == nbyMaxName))

    psCmd_Fcn = (STg2_CN_Command_Function_P)tgCM_UT_LF__ST__Pop( &s_sCommand_Function_Stack.m_sStack );
    if (nullptr == psCmd_Fcn)
    {
        TgERROR_MSGF( 0, "%-16.16s(%-32.32s): Exceeded number of console command functions.\n", "Console", "tgCN_Insert_Command_Function" );
        return (false);
    };

    tgMM_Set_U08_0x00( psCmd_Fcn, sizeof( STg2_CN_Command_Function ) );

    if (TgFAILED(tgMBZ_Hash( &psCmd_Fcn->m_sCommon.m_uiHash, mbzName, nbyMaxName )))
    {
        return (false);
    };

    tiString = tgSM_Dict_Insert_String_Hash( mbzName, nbyMaxName, psCmd_Fcn->m_sCommon.m_uiHash );
    if (tiString.m_uiKI == KTgID__INVALID_VALUE)
    {
        tgCM_UT_LF__ST__Push( &s_sCommand_Function_Stack.m_sStack, (STg2_UT_ST__ST_Node_P)(psCmd_Fcn) );
        return (false);
    };
    tgSM_Dict_Query_String( &psCmd_Fcn->m_sCommon.m_mbzName, &psCmd_Fcn->m_sCommon.m_nbyName, tiString );
    psCmd_Fcn->m_sCommon.m_nbyName += 1;
    if (nullptr != mbzDesc)
    {
        TgUINT_MAX                          uiHashDesc;

        if (TgFAILED(tgMBZ_Hash( &uiHashDesc, mbzDesc, nbyMaxDesc )))
        {
            return (false);
        };

        tiString = tgSM_Dict_Insert_String_Hash( mbzDesc, tgMBZ_Length_U08( mbzDesc, nbyMaxDesc ), uiHashDesc );
        if (tiString.m_uiKI != KTgID__INVALID_VALUE)
        {
            tgSM_Dict_Query_String( &psCmd_Fcn->m_sCommon.m_mbzDesc, &psCmd_Fcn->m_sCommon.m_nbyDesc, tiString );
            psCmd_Fcn->m_sCommon.m_nbyDesc += 1;
        };
    }
    else
    {
        psCmd_Fcn->m_sCommon.m_mbzDesc = nullptr;
        psCmd_Fcn->m_sCommon.m_nbyDesc = 0;
    };

    psCmd_Fcn->m_sCommon.m_uiType = ETgCN_COMMAND__FCN;
    psCmd_Fcn->m_pfnExecute = pfnExecute;

    tgCM_UT_LF__RW__Enter_Write_Wait_Yield( &g_sCN_Command_Name_Lock );

    iRet = tgCN_Insert_Command( &psCmd_Ret, &psCmd_Fcn->m_sCommon );
    if (TgSUCCEEDED( iRet ))
    {
        psCmd_Fcn->m_sCommon.m_uiFlags |= KTgCN_CMD_FLAG_USED;
        tgCM_UT_LF__RW__Exit_Write( &g_sCN_Command_Name_Lock );
        return (true);
    }
    else if (KTgW_DUPLICATE == iRet)
    {
        if (((STg2_CN_Command_Function_P)psCmd_Ret)->m_pfnExecute == pfnExecute)
        {
            tgCM_UT_LF__RW__Exit_Write( &g_sCN_Command_Name_Lock );
            TgWARNING_MSGF( 0, "%-16.16s(%-32.32s): Duplicate insert of console function.\n", "Console", "tgCN_Insert_Command_Function" );

            tgMM_Set_U08_0x00( psCmd_Fcn, sizeof( STg2_CN_Command_Function ) );
            tgCM_UT_LF__ST__Push( &s_sCommand_Function_Stack.m_sStack, (STg2_UT_ST__ST_Node_P)(psCmd_Fcn) );
            return (true);
        };
    };

    tgCM_UT_LF__RW__Exit_Write( &g_sCN_Command_Name_Lock );

    TgWARNING_MSGF( 0, "%-16.16s(%-32.32s): Console command name already used.\n", "Console", "tgCN_Insert_Command_Function" );
    tgMM_Set_U08_0x00( psCmd_Fcn, sizeof( STg2_CN_Command_Function ) );
    tgCM_UT_LF__ST__Push( &s_sCommand_Function_Stack.m_sStack, (STg2_UT_ST__ST_Node_P)(psCmd_Fcn) );

    return (false);
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Remove_Command_Function --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgBOOL tgCN_Remove_Command_Function( TgCHAR_MB_CPC mbzCmd, TgRSIZE nbyMaxCmd )
{
    TgUINT_MAX                          uiHash;
    TgSINT_F32                          iHash_Index;
    STg2_CN_Command_Common_P            psHash_Cmd;
    STg2_CN_Command_Common_P            psLexical_Cmd;
    STg2_CN_Command_Common_P            psPrev_Cmd;
    TgSINT_F32                          iLexical_Index;
    TgSINT_F08                          iRet;

    TgPARAM_CHECK(nullptr != mbzCmd && 0 != mbzCmd[0]);
    TgPARAM_CHECK((nbyMaxCmd <= KTgMAX_RSIZE) || (KTgMAX_SIZE_ALL == nbyMaxCmd))

    if (KTgMAX_SIZE_ALL == nbyMaxCmd)
    {
        nbyMaxCmd = tgMBZ_Length_U08( mbzCmd, KTgMAX_SIZE_ALL ) + 1;
    };

    if (TgFAILED(tgMBZ_Hash( &uiHash, mbzCmd, nbyMaxCmd )))
    {
        return (false);
    };
    iHash_Index = uiHash % KTgCN_MAX_COMMAND_HASH_SET;
    TgERROR_INDEX( iHash_Index, g_apsCN_Command_Hash_Set );

    tgCM_UT_LF__RW__Enter_Write_Wait_Yield( &g_sCN_Command_Name_Lock );

    /* Remove the item from the hash set */
    psHash_Cmd = g_apsCN_Command_Hash_Set[iHash_Index];
    psPrev_Cmd = nullptr;
    while (nullptr != psHash_Cmd)
    {
        if (TgSUCCEEDED(tgMBZ_Compare_NoCase( &iRet, mbzCmd, nbyMaxCmd, 0, psHash_Cmd->m_mbzName, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet))
        {
            break;
        };

        psPrev_Cmd = psHash_Cmd;
        psHash_Cmd = psHash_Cmd->m_psNext_Hash;
    };

    if (nullptr == psHash_Cmd || psHash_Cmd->m_uiType != ETgCN_COMMAND__FCN)
    {
        tgCM_UT_LF__RW__Exit_Write( &g_sCN_Command_Name_Lock );
        return (false);
    };

    if (nullptr == psPrev_Cmd)
    {
        g_apsCN_Command_Hash_Set[iHash_Index] = psHash_Cmd->m_psNext_Hash;
    }
    else
    {
        psPrev_Cmd->m_psNext_Hash = psHash_Cmd->m_psNext_Hash;
    };


    /* Calculate the lexical index */
    iLexical_Index = tgCN_Calc_Command_Lexical_Index( mbzCmd, nbyMaxCmd );
    TgERROR_INDEX( iLexical_Index, g_apsCommand_Lexical_Set );

    /* Remove it into the lexical list */
    psLexical_Cmd = g_apsCommand_Lexical_Set[iLexical_Index];
    psPrev_Cmd = nullptr;
    while (nullptr != psLexical_Cmd)
    {
        if (TgSUCCEEDED(tgMBZ_Compare_NoCase( &iRet, mbzCmd, nbyMaxCmd, 0, psLexical_Cmd->m_mbzName, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet))
        {
            break;
        };

        psPrev_Cmd = psLexical_Cmd;
        psLexical_Cmd = psLexical_Cmd->m_psNext_Lexical;
    };

    TgCRITICAL( nullptr != psLexical_Cmd && psHash_Cmd == psLexical_Cmd );

    if (nullptr == psPrev_Cmd)
    {
        g_apsCommand_Lexical_Set[iLexical_Index] = psLexical_Cmd->m_psNext_Lexical;
    }
    else
    {
        psPrev_Cmd->m_psNext_Lexical = psLexical_Cmd->m_psNext_Lexical;
    };

    tgCM_UT_LF__RW__Exit_Write( &g_sCN_Command_Name_Lock );

    TgWARNING_MSGF( 0, "%-16.16s(%-32.32s): Console command name already used.\n", "Console", "tgCN_Insert_Command_Function" );
    tgMM_Set_U08_0x00( psLexical_Cmd, sizeof( STg2_CN_Command_Function ) );
    tgCM_UT_LF__ST__Push( &s_sCommand_Function_Stack.m_sStack, (STg2_UT_ST__ST_Node_P)(psLexical_Cmd) );

    return (true);
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Print_Command_Functions --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
TgVOID tgCN_Print_Command_Functions( STg2_Output_P psOutput )
{
    TgSINT_F32                          iIndex;
    STg2_CN_Command_Common_P            psCmd;

    tgCM_UT_LF__RW__Enter_Read_Wait_Yield( &g_sCN_Command_Name_Lock );

    for (iIndex = 0; iIndex < KTgCN_MAX_COMMAND_FCN; ++iIndex)
    {
        psCmd = &s_asCommand_Function[iIndex].m_sCommon;
        if (0 == (psCmd->m_uiFlags & KTgCN_CMD_FLAG_USED))
        {
            continue;
        };

        tgIO_PrintF_NCZ( psOutput, "%-16.16s(%-32.32s): %s\n", "Con Function", psCmd->m_mbzName, psCmd->m_mbzDesc );
    };

    tgCM_UT_LF__RW__Exit_Read( &g_sCN_Command_Name_Lock );
}
/*# TgCOMPILE__CONSOLE */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Private Functions                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCN_Insert_Command ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgCN_Insert_Command( STg2_CN_Command_Common_PP psCmd_Ret, STg2_CN_Command_Common_P psCmd )
{
    STg2_CN_Command_Common_P            psIter_Cmd;
    TgSINT_F32                          iLexical_Index;
    STg2_CN_Command_Common_P            psPrev_Cmd;
    TgSINT_F32                          iHash_Index;

    TgPARAM_CHECK(nullptr != psCmd && nullptr != psCmd->m_mbzName && 0 != psCmd->m_mbzName[0]);

    /* Check to see if it exists in the hash set */
    psIter_Cmd = tgCN_Find_Command_In_Hash( psCmd->m_mbzName, psCmd->m_uiHash );
    if (nullptr != psIter_Cmd)
    {
        if (psCmd->m_uiType == psIter_Cmd->m_uiType)
        {
            if (nullptr != psCmd_Ret)
            {
                *psCmd_Ret = psIter_Cmd;
            };
            return (KTgW_DUPLICATE);
        }
        else
        {
            return (KTgE_FAIL);
        };
    };

    /* Calculate the lexical index */
    iLexical_Index = tgCN_Calc_Command_Lexical_Index( psCmd->m_mbzName, psCmd->m_nbyName );
    TgERROR_INDEX( iLexical_Index, g_apsCommand_Lexical_Set );

    /* Insert it into the lexical list */
    psIter_Cmd = g_apsCommand_Lexical_Set[iLexical_Index];
    psPrev_Cmd = nullptr;
    while (nullptr != psIter_Cmd)
    {
        TgSINT_F08                          niCompare;

        if (TgSUCCEEDED(tgMBZ_Compare_NoCase( &niCompare, psCmd->m_mbzName, KTgMAX_SIZE_ALL, 0, psIter_Cmd->m_mbzName, KTgMAX_SIZE_ALL, 0 )) && (niCompare > 0))
        {
            break;
        };

        TgERROR(0 != niCompare);

        psPrev_Cmd = psIter_Cmd;
        psIter_Cmd = psIter_Cmd->m_psNext_Lexical;
    };

    if (nullptr == psPrev_Cmd)
    {
        psCmd->m_psNext_Lexical = psIter_Cmd;
        g_apsCommand_Lexical_Set[iLexical_Index] = psCmd;
    }
    else
    {
        psCmd->m_psNext_Lexical = psPrev_Cmd->m_psNext_Lexical;
        psPrev_Cmd->m_psNext_Lexical = psCmd;
    };

    /* Insert it into the hash set */
    iHash_Index = psCmd->m_uiHash % KTgCN_MAX_COMMAND_HASH_SET;
    TgERROR_INDEX( iHash_Index, g_apsCN_Command_Hash_Set );

    psCmd->m_psNext_Hash = g_apsCN_Command_Hash_Set[iHash_Index];
    g_apsCN_Command_Hash_Set[iHash_Index] = psCmd;

    return (KTgS_OK);
}


/* ---- tgCN_Init_Unit_Test ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCN_Init_Unit_Test( TgVOID_PP ppOutput, TgRSIZE_P puiSize )
{
#if TgCOMPILE__CONSOLE
    *ppOutput = s_apsOutput;
    *puiSize = sizeof( s_apsOutput );
#else
    *ppOutput = nullptr;
    *puiSize = 0;
#endif
}


/* ---- tgCN_Start_Unit_Test ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCN_Start_Unit_Test( TgVOID )
{
#if TgCOMPILE__CONSOLE
    tgMM_Set_U08_0x00( s_apsOutput, sizeof( s_apsOutput ) );
#endif
}


/* ---- tgCN_Stop_Unit_Test ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCN_Stop_Unit_Test( TgVOID_P pOutput )
{
#if TgCOMPILE__CONSOLE
    tgMM_Copy( s_apsOutput, sizeof( s_apsOutput ), pOutput, sizeof( s_apsOutput ) );
#endif
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions                                                                                                                                                           */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCN_UID_Print_Internal -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgVOID tgCN_UID_Print_Internal( TgUINT_F32_C uiUID, TgUINT_F32_C uiChannel_Mask, TgCHAR_MB_CP mbzText, TgRSIZE_C nbyMaxText )
{
    TgUINT_F32_C                        uiSeverity = uiChannel_Mask & KTgCN_SEVERITY_MASK;
    TgUINT_F32                          uiChannel, uiOutput, uiLength;
    TgCHAR_MB_CP                        mbzStart;
    TgBOOL                              bEmitPrefix;

    if (ETgMODULE_STATE__BOOTED != s_enConsole_State)
    {
        tgPM_DBG_ERR_Write( nullptr, KTgMAX_RSIZE, (TgUINT_F08_CP )mbzText, tgMBZ_Length_U08( mbzText, nbyMaxText ) );
        return;
    };

    /* Enter the critical sections for the system and output system (if required) */
    if (0 != (uiChannel_Mask & KTgCN_CHANEL_LOG_SCREEN))
    {
        tgPM_MT_MX_Wait_Block( &s_sOS_Lock );
    };
    tgPM_MT_MX_Wait_Block( &s_sSystem_Lock );

    for (mbzStart = mbzText; '\0' != *mbzText; mbzStart = mbzText)
    {
        /* Calculate the byte size of the first string up to the end or the first new line character */
        for (uiLength = 1; '\0' != *mbzText && '\n' != *mbzText; ++uiLength, ++mbzText);

        /* Include the nullptr terminator for the string and determine if we should emit a prefix on the next token */
        if ('\0' != *mbzText)
        {
            bEmitPrefix = true;
            ++mbzText;
        }
        else
        {
            bEmitPrefix = false;
            --uiLength;
        };

        for (uiChannel = 0; uiChannel < KTgCN_MAX_CHANNEL; ++uiChannel)
        {
            /* Continue if this channel is not part of the output request */
            TgUINT_F32_C                        uiChannel_ID = 1 << (uiChannel + KTgCN_SEVERITY_BITS);

            /* Skip if the message is not included for this channel */
            if (0 == (uiChannel_Mask & uiChannel_ID))
            {
                continue;
            };

            /* Check to see if the message passes the UID filter */
            if ((KTgUID_NONE != s_auiUID_Filter[uiChannel]) && (uiUID != s_auiUID_Filter[uiChannel]))
            {
                continue;
            };

            /* Check to see if the message passes the severity filter */
            if (s_auiSeverity_Filter[uiChannel] <= uiSeverity)
            {
                continue;
            };

            /* Screen output is kept within a ring buffer log for display purposes as well sent to the output functions */
            if (KTgCN_CHANEL_LOG_SCREEN == uiChannel_ID && nullptr != s_psOS_Log_Free)
            {
                STg2_CN_OnScreen_Line_PC            psOS_Log_Display = s_psOS_Log_Free;

                s_psOS_Log_Free = psOS_Log_Display->m_psNext;

                tgMBZ_CopyN( psOS_Log_Display->m_szLog, KTgCN_OSCON_LINE_LENGTH, mbzStart, KTgMAX_SIZE_ALL, uiLength );
                psOS_Log_Display->m_uiSeverity = uiSeverity;
                psOS_Log_Display->m_uiUID = uiUID;
                psOS_Log_Display->m_fLife_Time = s_fOS_Log_Default_Life_Time;
                psOS_Log_Display->m_psNext = s_psOS_Log_Display;

                s_psOS_Log_Display = psOS_Log_Display;
            };

            /* Iterate through all of the output objects for this channel */
            for (uiOutput = 0; uiOutput < KTgCN_MAX_CHANNEL_OUTPUT; ++uiOutput)
            {
                if (0 == s_apsOutput[uiChannel][uiOutput])
                {
                    break;
                };

                if ((s_abOutput_Prefix[uiChannel]) && 0 != s_pzOutput_Prefix[uiChannel])
                {
                    s_apsOutput[uiChannel][uiOutput]->m_pfnWrite( s_apsOutput[uiChannel][uiOutput], KTgMAX_RSIZE, (TgUINT_F08_CP)s_pzOutput_Prefix[uiChannel],
                                                                  s_nbyOutput_Prefix[uiChannel] );
                };

                s_apsOutput[uiChannel][uiOutput]->m_pfnWrite( s_apsOutput[uiChannel][uiOutput], KTgMAX_RSIZE, (TgUINT_F08_CP )mbzStart, uiLength*sizeof( TgCHAR_MB ) );
            };

            s_abOutput_Prefix[uiChannel] = bEmitPrefix;
        };
    };

    /* Exit the critical sections for the system and output system (if required) */
    if (0 != (uiChannel_Mask & KTgCN_CHANEL_LOG_SCREEN))
    {
        tgPM_MT_MX_Release( &s_sOS_Lock );
    };
    tgPM_MT_MX_Release( &s_sSystem_Lock );
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Scroll_Display ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* NOTE: This should only be called by tgCN_Process_Input due to synchronization on internal variables */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgVOID tgCN_Scroll_Display( TgSINT_F32_C niLN, TgSINT_F32_C niPG )
{
    TgSINT_F32_C                        iPageAmount = (s_iOS_Console_Render_Page_Height / s_iOS_Console_Render_Font_Height - 1);
    TgSINT_F32_C                        iNew_Disp = (s_iOS_Console_Display_Index + (niLN + niPG*iPageAmount)) % KTgCN_OSCON_MAX_LINE;

    s_iOS_Console_Display_Index = iNew_Disp;
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Default_Break_Write ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgCN_Default_Break_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP UNUSED_PARAM mbzText, TgRSIZE_C UNUSED_PARAM niText )
{
    tgPM_Break();
    return (0);
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgCN_Default_Abort_Write ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgCN_Default_Abort_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP UNUSED_PARAM mbzText, TgRSIZE_C UNUSED_PARAM niText )
{
    tgPM_Abort();
    CLANG_COMMAND( return 0;)
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_CON_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_CON_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Console_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_LOG_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_LOG_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iLOG_Output_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_FCN_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_FCN_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Log_FCN_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_MEM_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_MEM_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Log_Mem_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_MSG_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_MSG_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Msg_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_WRN_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_WRN_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Wrn_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_ERR_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_ERR_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Err_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_CRT_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_CRT_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Crt_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_INT_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_INT_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Int_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_LDN_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_LDN_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iOuput_Ldn_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif


/* ---- tgLOG_STD_File_Write ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__CONSOLE
static TgRSIZE tgLOG_STD_File_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _nuiText )
{
    return (tgIO_File_Write( s_iLOG_Output_File, (TgVOID_CPC)mbzText, _nuiText ));
}
/*# TgCOMPILE__CONSOLE */
#endif




