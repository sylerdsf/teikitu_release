/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Console.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_CONSOLE_INL)
#define TGS_COMMON_CONSOLE_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */
/*  File Local Functions and Private Data */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */

/* ---- tgCN_Find_Command_In_Hash ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE STg2_CN_Command_Common_P tgCN_Find_Command_In_Hash( TgCHAR_MB_CPC mbzCmd, TgUINT_MAX_C uiHash )
{
    STg2_CN_Command_Common_P            psIter_Cmd;
    TgSINT_F32                          iHash_Index;
    TgSINT_F08                          iRet;

    iHash_Index = uiHash % KTgCN_MAX_COMMAND_HASH_SET;
    TgERROR_INDEX( iHash_Index, g_apsCN_Command_Hash_Set );

    psIter_Cmd = g_apsCN_Command_Hash_Set[iHash_Index];
    while (nullptr != psIter_Cmd)
    {
        if (TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzCmd, KTgMAX_SIZE_ALL, 0, psIter_Cmd->m_mbzName, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet))
        {
            return (psIter_Cmd);
        };

        psIter_Cmd = psIter_Cmd->m_psNext_Hash;
    };

    return (nullptr);
}


/* ---- tgCN_Calc_Command_Lexical_Index ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgSINT_F32 tgCN_Calc_Command_Lexical_Index( TgCHAR_MB_CPC mbzCmd, TgRSIZE_C nbyMaxCmd )
{
    TgSINT_F32                          iLexical_Index;
    TgCHAR_MB                           mbLower[KTgMAX_MB_LEN+1];

    tgMB_To_Lower( mbLower, mbzCmd );
    iLexical_Index = tgCM_CLP_S32( 1 + (TgSINT_F32)mbLower[0] - 'a', 0, 27 );
    iLexical_Index *= 29;
    if (0 == mbzCmd[1])
    {
        iLexical_Index += 28;
    }
    else
    {
        tgMB_To_Lower( mbLower, tgMBZ_Query_At( mbzCmd, nbyMaxCmd, 1 ) );
        iLexical_Index += tgCM_CLP_S32( 1 + (TgSINT_F32)mbLower[0] - 'a', 0, 27 );
    };
    iLexical_Index *= 29;
    if ((0 == mbzCmd[1]) || (0 == mbzCmd[2]))
    {
        iLexical_Index += 28;
    }
    else
    {
        tgMB_To_Lower( mbLower, tgMBZ_Query_At( mbzCmd, nbyMaxCmd, 2 ) );
        iLexical_Index += tgCM_CLP_S32( 1 + (TgSINT_F32 )mbLower[0] - 'a', 0, 27 );
    };

    return (iLexical_Index);
}


/* ---- tgCN_Is_Command_Function ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgBOOL tgCN_Is_Command_Function( STg2_CN_Command_Common_CPCU psCmd )
{
    return (psCmd->m_uiType >= ETgCN_COMMAND__FCN_START && psCmd->m_uiType < ETgCN_COMMAND__FCN_END);
}


/* ---- tgCN_Is_Command_Variable ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgBOOL tgCN_Is_Command_Variable( STg2_CN_Command_Common_CPCU psCmd )
{
    return (psCmd->m_uiType >= ETgCN_COMMAND__VAR_START && psCmd->m_uiType < ETgCN_COMMAND__VAR_END);
}


/* =============================================================================================================================================================================== */
#endif
