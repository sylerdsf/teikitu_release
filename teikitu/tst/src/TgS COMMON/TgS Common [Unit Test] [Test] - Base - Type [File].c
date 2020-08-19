/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Base - Type [File].c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Macros                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define ROOT                                    TEST__ROOT_DIRECTORY
#define PSEP                                    TgPLATFORM__U8_PATH_SEPARATOR
#define P01                                     u8"Test01"
#define P02                                     KTgMB_LIT_TEST__BURMESE
#define P03                                     KTgMB_LIT_TEST__RUSSIAN
#define P04                                     KTgMB_LIT_TEST__KOREAN

#define FSEP                                    TgPLATFORM__U8_FILE_SEPARATOR
#define NAME                                    KTgMB_LIT_TEST__CHINESE_SIMPLIFIED
#define EXT_01                                  KTgMB_LIT_TEST__JAPANESE
#define EXT_02                                  KTgMB_LIT_TEST__KOREAN




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TEST_METHOD( UNIT_TEST__TEST__CM_Path_Add_Separator );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Add_Extension );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Copy );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Append );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Common_Prefix_Size_U08 );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Common_Prefix_Size_Count );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Common_Prefix );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Remove_Separator );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Remove_Extension );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Remove_File_Name );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Rename_Extension );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Remove_Directory );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Init );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Find_Extension );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_Find_File_Name );
TEST_METHOD( UNIT_TEST__TEST__CM_Path_IsAbsolute );
TEST_METHOD( UNIT_TEST__TEST__CM_File_Output_Header );
TEST_METHOD( UNIT_TEST__TEST__CM_File_Output_Data_Headers );
TEST_METHOD( UNIT_TEST__TEST__CM_File_Query_Data );
TEST_METHOD( UNIT_TEST__TEST__CM_File_Query_Data_Size );
TEST_METHOD( UNIT_TEST__TEST__CM_File_Query_Data_Count );
TEST_METHOD( UNIT_TEST__TEST__CM_File_Check_Block );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions and Data                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TEST_LOCAL TgUINT_E08_P                     tgUNIT_TEST_INTERNAL__File_Data_Setup( TgVOID );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__Base_Type_File_Path ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__Base_Type_File_Path )
{
    tgCN_Set_Severity_Filter( KTgCN_CHANEL_MESSAGE, 0xC );

    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Add_Separator() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Add_Extension() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Copy() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Append() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Common_Prefix_Size_U08() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Common_Prefix_Size_Count() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Common_Prefix() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Remove_Separator() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Remove_Extension() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Remove_File_Name() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Rename_Extension() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Remove_Directory() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Init() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Find_Extension() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_Find_File_Name() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Path_IsAbsolute() );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__Base_Type_File_File ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__Base_Type_File_File )
{
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_File_Output_Header() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_File_Output_Data_Headers() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_File_Query_Data() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_File_Query_Data_Size() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_File_Query_Data_Count() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_File_Check_Block() );

    TEST_END_METHOD( KTgS_OK );
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__CM_Path_Add_Separator ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Add_Separator )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Add_Separator( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Add_Separator", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Add_Separator( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Add_Separator", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Add_Extension ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Add_Extension )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Add_Extension( mbzPath_Test, KTgMAX_FILE_PATH, EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Add_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Add_Extension( mbzPath_Test, KTgMAX_FILE_PATH, EXT_02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Add_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01 FSEP EXT_02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Add_Extension( mbzPath_Test, KTgMAX_FILE_PATH, EXT_02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Add_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP FSEP EXT_02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Add_Extension( mbzPath_Test, KTgMAX_FILE_PATH, EXT_02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Add_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME PSEP FSEP EXT_02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Copy -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Copy )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Copy", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Copy", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Copy", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Append ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Append )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Append( mbzPath_Test, KTgMAX_FILE_PATH, P02 PSEP, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Append", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Append( mbzPath_Test, KTgMAX_FILE_PATH, PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Append", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Append( mbzPath_Test, KTgMAX_FILE_PATH, P02 PSEP, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Append", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Append( mbzPath_Test, KTgMAX_FILE_PATH, PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Append", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Append( mbzPath_Test, KTgMAX_FILE_PATH, NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Append", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Append( mbzPath_Test, KTgMAX_FILE_PATH, PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Append", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Append( mbzPath_Test, KTgMAX_FILE_PATH, NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Append", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Append( mbzPath_Test, KTgMAX_FILE_PATH, PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Append", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Common_Prefix_Size_U08 -------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Common_Prefix_Size_U08 )
{
    TgCHAR_MB                           mbzPath_ARG[KTgMAX_FILE_PATH] = { 0 };
    TgRSIZE                             nbyPath_ARG;

    tgMM_Set_U08_0x00( mbzPath_ARG, sizeof mbzPath_ARG );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    nbyPath_ARG = tgMBZ_Length_U08( mbzPath_ARG, KTgMAX_FILE_PATH );
    Test__Expect_EQ( nbyPath_ARG, tgCM_Path_Common_Prefix_Size_U08( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));

    tgMM_Set_U08_0x00( mbzPath_ARG, sizeof mbzPath_ARG );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P03, KTgMAX_SIZE_ALL ));
    nbyPath_ARG = tgMBZ_Length_U08( mbzPath_ARG, KTgMAX_FILE_PATH ); /* Last code point in P03 is two bytes */
    mbzPath_ARG[nbyPath_ARG-1] ^= 3;
    Test__Expect_EQ(nbyPath_ARG - 2, tgCM_Path_Common_Prefix_Size_U08( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P03 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));

    tgMM_Set_U08_0x00( mbzPath_ARG, sizeof mbzPath_ARG );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    nbyPath_ARG = tgMBZ_Length_U08( mbzPath_ARG, KTgMAX_FILE_PATH );
    Test__Expect_EQ(nbyPath_ARG, tgCM_Path_Common_Prefix_Size_U08( mbzPath_ARG, KTgMAX_FILE_PATH,  ROOT P01 PSEP P02 PSEP P03, KTgMAX_SIZE_ALL ));

    tgMM_Set_U08_0x00( mbzPath_ARG, sizeof mbzPath_ARG );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));
    nbyPath_ARG = tgMBZ_Length_U08( mbzPath_ARG, KTgMAX_FILE_PATH );
    Test__Expect_EQ(nbyPath_ARG, tgCM_Path_Common_Prefix_Size_U08( ROOT P01 PSEP P02 PSEP P03 PSEP P04 PSEP, KTgMAX_SIZE_ALL, mbzPath_ARG, KTgMAX_FILE_PATH ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Common_Prefix_Size_Count ------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Common_Prefix_Size_Count )
{
    TgCHAR_MB                           mbzPath_ARG[KTgMAX_FILE_PATH] = { 0 };
    TgRSIZE                             nbyPath_ARG;
    TgRSIZE                             nuiPath_ARG;

    tgMM_Set_U08_0x00( mbzPath_ARG, sizeof mbzPath_ARG );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgMBZ_Length_Count( &nuiPath_ARG, mbzPath_ARG, KTgMAX_FILE_PATH ));
    Test__Expect_EQ(nuiPath_ARG, tgCM_Path_Common_Prefix_Size_Count( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));

    tgMM_Set_U08_0x00( mbzPath_ARG, sizeof mbzPath_ARG );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P03, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgMBZ_Length_Count( &nuiPath_ARG, mbzPath_ARG, KTgMAX_FILE_PATH ));
    nbyPath_ARG = tgMBZ_Length_U08( mbzPath_ARG, KTgMAX_FILE_PATH ); /* Last code point in P03 is two bytes */
    mbzPath_ARG[nbyPath_ARG-1] ^= 3;
    Test__Expect_EQ(nuiPath_ARG - 1, tgCM_Path_Common_Prefix_Size_Count( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P03 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));

    tgMM_Set_U08_0x00( mbzPath_ARG, sizeof mbzPath_ARG );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgMBZ_Length_Count( &nuiPath_ARG, mbzPath_ARG, KTgMAX_FILE_PATH ));
    Test__Expect_EQ(nuiPath_ARG, tgCM_Path_Common_Prefix_Size_Count( mbzPath_ARG, KTgMAX_FILE_PATH,  ROOT P01 PSEP P02 PSEP P03, KTgMAX_SIZE_ALL ));

    tgMM_Set_U08_0x00( mbzPath_ARG, sizeof mbzPath_ARG );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgMBZ_Length_Count( &nuiPath_ARG, mbzPath_ARG, KTgMAX_FILE_PATH ));
    Test__Expect_EQ(nuiPath_ARG, tgCM_Path_Common_Prefix_Size_Count( ROOT P01 PSEP P02 PSEP P03 PSEP P04 PSEP, KTgMAX_SIZE_ALL, mbzPath_ARG, KTgMAX_FILE_PATH ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Common_Prefix ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Common_Prefix )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgCHAR_MB                           mbzPath_ARG[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P03, KTgMAX_SIZE_ALL ));
    mbzPath_ARG[tgMBZ_Length_U08( mbzPath_ARG, KTgMAX_FILE_PATH)-1] ^= 3;
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, mbzPath_ARG, KTgMAX_FILE_PATH, ROOT P01 PSEP P03 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP u8"тестовое задани", KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02 PSEP P03, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 FSEP EXT_01, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, ROOT P01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, ROOT, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02 FSEP EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01, KTgMAX_SIZE_ALL, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT, KTgMAX_SIZE_ALL, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03 PSEP P04 PSEP, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, "%-16.16s %-31.31s    %-48.48s %-48.48s %-48.48s %s\n", "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, "%-16.16s %-31.31s    %-48.48s %-48.48s %-48.48s %s\n", "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Common_Prefix( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP P03 PSEP P04 FSEP P03, KTgMAX_SIZE_ALL, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, "%-16.16s %-31.31s    %-48.48s %-48.48s %-48.48s %s\n", "TEST:", "", "", "", "tgCM_Path_Common_Prefix", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP P03 PSEP P04, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Remove_Separator -------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Remove_Separator )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_Separator( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Separator", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_Separator( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Separator", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_Separator( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Separator", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Remove_Extension -------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Remove_Extension )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgE_FAIL, tgCM_Path_Remove_Extension( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_Extension( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01 FSEP EXT_02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_Extension( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgE_FAIL, tgCM_Path_Remove_Extension( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Remove_File_Name -------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Remove_File_Name )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_File_Name( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_File_Name", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_NE(KTgS_OK, tgCM_Path_Remove_File_Name( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_File_Name", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_File_Name( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_File_Name", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_File_Name( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_File_Name", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01 FSEP EXT_02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_File_Name( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_File_Name", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Rename_Extension -------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Rename_Extension )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgE_FAIL, tgCM_Path_Rename_Extension( mbzPath_Test, KTgMAX_FILE_PATH, EXT_02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Rename_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Rename_Extension( mbzPath_Test, KTgMAX_FILE_PATH, EXT_02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Rename_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP NAME FSEP EXT_02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgE_FAIL, tgCM_Path_Rename_Extension( mbzPath_Test, KTgMAX_FILE_PATH, EXT_02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Rename_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Rename_Extension( mbzPath_Test, KTgMAX_FILE_PATH, EXT_02, KTgMAX_SIZE_ALL ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Rename_Extension", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, FSEP EXT_02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgE_FAIL, tgCM_Path_Rename_Extension( mbzPath_Test, 5, EXT_02 EXT_02, KTgMAX_SIZE_ALL ) );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Remove_Directory -------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Remove_Directory )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_Directory( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Directory", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_Directory( mbzPath_Test, KTgMAX_FILE_PATH  ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Directory", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Remove_Directory( mbzPath_Test, KTgMAX_FILE_PATH ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Remove_Directory", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, "", KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Init -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Init )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Init( mbzPath_Test, KTgMAX_FILE_PATH, ROOT, "" ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Init", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Init( mbzPath_Test, KTgMAX_FILE_PATH, ROOT, "" ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Init", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Init( mbzPath_Test, KTgMAX_FILE_PATH, P01, "" ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Init", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, P01 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Init( mbzPath_Test, KTgMAX_FILE_PATH, ROOT, P01, "" ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Init", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, ROOT P01 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Init( mbzPath_Test, KTgMAX_FILE_PATH, P01, P02, "" ));
    TgMSGF( 0xC, UNIT_TEST__MSG_LITERAL_4, "TEST:", "", "", "", "tgCM_Path_Init", mbzPath_Test );
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test, KTgMAX_SIZE_ALL, 0, P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Find_Extension ---------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Find_Extension )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgRSIZE                             nbyOffset;
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_NE(KTgS_OK, tgCM_Path_Find_Extension( &nbyOffset, mbzPath_Test, KTgMAX_FILE_PATH ));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_NE(KTgS_OK, tgCM_Path_Find_Extension( &nbyOffset, mbzPath_Test, KTgMAX_FILE_PATH ));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Find_Extension( &nbyOffset, mbzPath_Test, KTgMAX_FILE_PATH ));
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test + nbyOffset, KTgMAX_SIZE_ALL, 0, FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_Find_File_Name ---------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_Find_File_Name )
{
    TgCHAR_MB                           mbzPath_Test[KTgMAX_FILE_PATH] = { 0 };
    TgRSIZE                             nbyOffset;
    TgSINT_F08                          iRet;

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02 PSEP, KTgMAX_SIZE_ALL ));
    Test__Expect_NE(KTgS_OK, tgCM_Path_Find_File_Name( &nbyOffset, mbzPath_Test, KTgMAX_FILE_PATH ));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP P02, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Find_File_Name( &nbyOffset, mbzPath_Test, KTgMAX_FILE_PATH ));
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test + nbyOffset, KTgMAX_SIZE_ALL, 0, P02, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    tgMM_Set_U08_0x00( mbzPath_Test, sizeof mbzPath_Test );
    Test__Expect_EQ(KTgS_OK, tgMBZ_Copy( mbzPath_Test, KTgMAX_FILE_PATH, ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgCM_Path_Find_File_Name( &nbyOffset, mbzPath_Test, KTgMAX_FILE_PATH ));
    Test__Expect_EQ(true, TgSUCCEEDED(tgMBZ_Compare( &iRet, mbzPath_Test + nbyOffset, KTgMAX_SIZE_ALL, 0, NAME FSEP EXT_01, KTgMAX_SIZE_ALL, 0 )) && (0 == iRet));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Path_IsAbsolute -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Path_IsAbsolute )
{
#if defined(TgCOMPILE_PLATFORM_WIN)
    Test__Expect_NE(false, tgCM_Path_IsAbsolute( ROOT P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
#endif
    Test__Expect_NE(false, tgCM_Path_IsAbsolute( PSEP P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgCM_Path_IsAbsolute( P01 PSEP NAME FSEP EXT_01, KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}



/* ---- tgUNIT_TEST_INTERNAL__File_Data_Setup ------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_LOCAL TgUINT_E08_P tgUNIT_TEST_INTERNAL__File_Data_Setup( TgVOID )
{
    TgUINT_E08_P                        puiData;
    TgRSIZE                             nuiData;
    union
    {
        STg2_File_Block_P                   ps;
        TgUINT_F08_P                        pui;
    }                                   sFileBlock;
    union
    {
        STg2_File_Data_P                    ps;
        TgUINT_F08_P                        pui;
    }                                   sFileData;
    union
    {
        STg2_File_Data__TEST_P              ps;
        TgUINT_F08_P                        pui;
    }                                   sFileTest;

    nuiData  = sizeof( STg2_File_Block ) + 4 * sizeof( STg2_File_Section );
    nuiData += 4 * (sizeof( STg2_File_Data ) + sizeof( STg2_File_Data__TEST ) );
    puiData = malloc( nuiData );
    if (nullptr == puiData)
        return (nullptr);

    sFileBlock.pui = puiData;
    sFileBlock.ps->m_uiFourCC_Tool = TgMAKE_4CC( 'T', 'G', 'S', 'F' );
    sFileBlock.ps->m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileBlock.ps->m_uiSize = sizeof( STg2_File_Block );
    sFileBlock.ps->m_uiVersion = 1;
    sFileBlock.ps->m_uiMachine = ETgFILE_PLATFORM_W64;
    sFileBlock.ps->m_uiFlags = 0;
    sFileBlock.ps->m_uiTool_Version = 1;
    sFileBlock.ps->m_uiTool_ID = 1;
    sFileBlock.ps->m_uiSection_Version = 1;
    sFileBlock.ps->m_uiSection_Count = 4;
    sFileBlock.ps->m_uiSection_Size = sizeof( STg2_File_Section );
    sFileBlock.ps->m_asSection[0].m_uiFourCC_Tool = TgMAKE_4CC( 'T', 'G', 'S', 'F' );
    sFileBlock.ps->m_asSection[0].m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileBlock.ps->m_asSection[0].m_uiOffset = sizeof( STg2_File_Block ) + 4 * sizeof( STg2_File_Section );
    sFileBlock.ps->m_asSection[1].m_uiFourCC_Tool = TgMAKE_4CC( 'T', 'G', 'S', 'F' );
    sFileBlock.ps->m_asSection[1].m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileBlock.ps->m_asSection[1].m_uiOffset = sFileBlock.ps->m_asSection[0].m_uiOffset + sizeof( STg2_File_Data ) + sizeof( STg2_File_Data__TEST );
    sFileBlock.ps->m_asSection[2].m_uiFourCC_Tool = TgMAKE_4CC( 'T', 'G', 'S', 'F' );
    sFileBlock.ps->m_asSection[2].m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileBlock.ps->m_asSection[2].m_uiOffset = sFileBlock.ps->m_asSection[1].m_uiOffset + sizeof( STg2_File_Data ) + sizeof( STg2_File_Data__TEST );
    sFileBlock.ps->m_asSection[3].m_uiFourCC_Tool = TgMAKE_4CC( 'T', 'G', 'S', 'F' );
    sFileBlock.ps->m_asSection[3].m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileBlock.ps->m_asSection[3].m_uiOffset = sFileBlock.ps->m_asSection[2].m_uiOffset + sizeof( STg2_File_Data ) + sizeof( STg2_File_Data__TEST );

    sFileData.pui = puiData + sizeof( STg2_File_Block ) + 4 * sizeof( STg2_File_Section );
    sFileData.ps->m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileData.ps->m_iOffset = (TgSINT_F32 )sizeof( STg2_File_Data );
    sFileData.ps->m_uiSize = (TgUINT_F32)sizeof( STg2_File_Data__TEST );
    sFileData.ps->m_uiVersion = 1;
    sFileTest.pui = sFileData.pui + sFileData.ps->m_iOffset;
    sFileTest.ps->m_uiTest = 0;
    sFileTest.ps->m_nuiData = 0;

    sFileData.pui = sFileData.pui + sizeof( STg2_File_Data ) + sizeof( STg2_File_Data__TEST );
    sFileData.ps->m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileData.ps->m_iOffset = (TgSINT_F32 )sizeof( STg2_File_Data );
    sFileData.ps->m_uiSize = (TgUINT_F32)sizeof( STg2_File_Data__TEST );
    sFileData.ps->m_uiVersion = 1;
    sFileTest.pui = sFileData.pui + sFileData.ps->m_iOffset;
    sFileTest.ps->m_uiTest = 1;
    sFileTest.ps->m_nuiData = 0;

    sFileData.pui = sFileData.pui + sizeof( STg2_File_Data ) + sizeof( STg2_File_Data__TEST );
    sFileData.ps->m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileData.ps->m_iOffset = (TgSINT_F32 )sizeof( STg2_File_Data );
    sFileData.ps->m_uiSize = (TgUINT_F32)sizeof( STg2_File_Data__TEST );
    sFileData.ps->m_uiVersion = 1;
    sFileTest.pui = sFileData.pui + sFileData.ps->m_iOffset;
    sFileTest.ps->m_uiTest = 2;
    sFileTest.ps->m_nuiData = 0;

    sFileData.pui = sFileData.pui + sizeof( STg2_File_Data ) + sizeof( STg2_File_Data__TEST );
    sFileData.ps->m_uiFourCC_Data = TgMAKE_4CC( 'T', 'E', 'S', 'T' );
    sFileData.ps->m_iOffset = (TgSINT_F32 )sizeof( STg2_File_Data );
    sFileData.ps->m_uiSize = (TgUINT_F32)sizeof( STg2_File_Data__TEST );
    sFileData.ps->m_uiVersion = 1;
    sFileTest.pui = sFileData.pui + sFileData.ps->m_iOffset;
    sFileTest.ps->m_uiTest = 3;
    sFileTest.ps->m_nuiData = 0;

    TgCRITICAL( nuiData >= ((TgUINT_PTR)(sFileData.pui - puiData)) + sizeof( STg2_File_Data ) + sizeof( STg2_File_Data__TEST ) );
    return (puiData);
}


/* ---- UNIT_TEST__TEST__CM_File_Output_Header ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_File_Output_Header )
{
    TgUINT_F08_P                        puiData;
    TgCHAR_MB                           sOutput_Buffer[8192];
    STg2_Output_MEM                     sOutput;
    union
    {
        STg2_File_Block_P                   ps;
        TgUINT_F08_P                        pui;
    }                                   sFileBlock;
    TgCHAR_MB_C                         aResult[] = "File Header\n"
                                                    " - FourCC Tool: 1179862868\n"
                                                    " - FourCC Data: 1414743380\n"
                                                    " - Version: 1\n"
                                                    " - Machine: 2\n"
                                                    " - Flags: 0\n"
                                                    " - Tools Version: 1\n"
                                                    " - Tool Id: 1\n"
                                                    " - Section Version: 1\n"
                                                    " - Section Count: 4\n"
                                                    " - Section Size: 16\n"
                                                    " - Section (   0) FourCC Tool: 1179862868\n"
                                                    " - Section (   0) FourCC Data: 1414743380\n"
                                                    " - Section (   0) Offset: 96\n"
                                                    " - Section (   1) FourCC Tool: 1179862868\n"
                                                    " - Section (   1) FourCC Data: 1414743380\n"
                                                    " - Section (   1) Offset: 128\n"
                                                    " - Section (   2) FourCC Tool: 1179862868\n"
                                                    " - Section (   2) FourCC Data: 1414743380\n"
                                                    " - Section (   2) Offset: 160\n"
                                                    " - Section (   3) FourCC Tool: 1179862868\n"
                                                    " - Section (   3) FourCC Data: 1414743380\n"
                                                    " - Section (   3) Offset: 192\n";

    puiData = tgUNIT_TEST_INTERNAL__File_Data_Setup();
    if (nullptr == puiData)
    {
        TEST_END_METHOD( KTgE_FAIL );
    };
    sFileBlock.pui = puiData;

    /* Create a memory base output object to be used when testing the console output systems */
    tgIO_OM__Open( &sOutput, (TgUINT_E08_P)sOutput_Buffer, sizeof( sOutput_Buffer ), nullptr );
    tgMM_Set_U08_0x00( sOutput_Buffer, sizeof sOutput_Buffer );

    tgCM_File_Output_Header( &sOutput.m_sOutput, sFileBlock.ps );
    Test__Expect_EQ(0, memcmp( aResult, sOutput_Buffer, sizeof( aResult ) - 1 ));

    free( puiData );
    tgIO_OM__Close( &sOutput.m_sOutput );
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_File_Output_Data_Headers ----------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_File_Output_Data_Headers )
{
    TgUINT_F08_P                        puiData;
    TgCHAR_MB                           sOutput_Buffer[8192];
    STg2_Output_MEM                     sOutput;
    union
    {
        STg2_File_Block_P                   ps;
        TgUINT_F08_P                        pui;
    }                                   sFileBlock;
    TgCHAR_MB_C                         aResult[] = " - Section Data (   0) FourCC Data: 1414743380\n"
                                                    " - Section Data (   0) Offset: 16\n"
                                                    " - Section Data (   0) Size: 16\n"
                                                    " - Section Data (   0) Version: 1\n"
                                                    " - Section Data (   1) FourCC Data: 1414743380\n"
                                                    " - Section Data (   1) Offset: 16\n"
                                                    " - Section Data (   1) Size: 16\n"
                                                    " - Section Data (   1) Version: 1\n"
                                                    " - Section Data (   2) FourCC Data: 1414743380\n"
                                                    " - Section Data (   2) Offset: 16\n"
                                                    " - Section Data (   2) Size: 16\n"
                                                    " - Section Data (   2) Version: 1\n"
                                                    " - Section Data (   3) FourCC Data: 1414743380\n"
                                                    " - Section Data (   3) Offset: 16\n"
                                                    " - Section Data (   3) Size: 16\n"
                                                    " - Section Data (   3) Version: 1\n";

    puiData = tgUNIT_TEST_INTERNAL__File_Data_Setup();
    if (nullptr == puiData)
    {
        TEST_END_METHOD( KTgE_FAIL );
    };
    sFileBlock.pui = puiData;

    /* Create a memory base output object to be used when testing the console output systems */
    tgIO_OM__Open( &sOutput, (TgUINT_E08_P)sOutput_Buffer, sizeof( sOutput_Buffer ), nullptr );
    sOutput_Buffer[0] = 0;

    tgCM_File_Output_Data_Headers( &sOutput.m_sOutput, sFileBlock.ps );
    Test__Expect_EQ(0, memcmp( aResult, sOutput_Buffer, sizeof( aResult ) - 1 ));

    free( puiData );
    tgIO_OM__Close( &sOutput.m_sOutput );
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_File_Query_Data -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_File_Query_Data )
{
    TgUINT_F08_P                        puiData;
    union
    {
        STg2_File_Block_P                   ps;
        TgUINT_F08_P                        pui;
    }                                   sFileBlock;
    TgVOID_CP                           pTest;

    puiData = tgUNIT_TEST_INTERNAL__File_Data_Setup();
    if (nullptr == puiData)
    {
        TEST_END_METHOD( KTgE_FAIL );
    };
    sFileBlock.pui = puiData;

    Test__Expect_EQ(true, tgCM_File_Query_Data( &pTest, sFileBlock.ps, 0 ));
    Test__Expect_EQ((TgUINT_PTR)pTest, (TgUINT_PTR)sFileBlock.pui + sizeof( STg2_File_Block ) + 4 * sizeof( STg2_File_Section ) + sizeof( STg2_File_Data ) );
    Test__Expect_EQ(false, tgCM_File_Query_Data( &pTest, sFileBlock.ps, 5 ));

    free( puiData );
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_File_Query_Data_Size --------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_File_Query_Data_Size )
{
    TgUINT_F08_P                        puiData;
    union
    {
        STg2_File_Block_P                   ps;
        TgUINT_F08_P                        pui;
    }                                   sFileBlock;
    TgRSIZE                             nbyData;

    puiData = tgUNIT_TEST_INTERNAL__File_Data_Setup();
    if (nullptr == puiData)
    {
        TEST_END_METHOD( KTgE_FAIL );
    };
    sFileBlock.pui = puiData;

    Test__Expect_EQ(true, tgCM_File_Query_Data_Size( &nbyData, sFileBlock.ps, 0 ));
    Test__Expect_EQ(nbyData, sizeof( STg2_File_Data__TEST ));
    Test__Expect_EQ(false, tgCM_File_Query_Data_Size( &nbyData, sFileBlock.ps, 5 ));

    free( puiData );
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_File_Query_Data_Count -------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_File_Query_Data_Count )
{
    TgUINT_F08_P                        puiData;
    union
    {
        STg2_File_Block_P                   ps;
        TgUINT_F08_P                        pui;
    }                                   sFileBlock;

    puiData = tgUNIT_TEST_INTERNAL__File_Data_Setup();
    if (nullptr == puiData)
    {
        TEST_END_METHOD( KTgE_FAIL );
    };
    sFileBlock.pui = puiData;

    Test__Expect_EQ(4, tgCM_File_Query_Data_Count( sFileBlock.ps ));

    free( puiData );
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_File_Check_Block ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_File_Check_Block )
{
    TgUINT_F08_P                        puiData;
    union
    {
        STg2_File_Block_P                   ps;
        TgUINT_F08_P                        pui;
    }                                   sFileBlock;

    puiData = tgUNIT_TEST_INTERNAL__File_Data_Setup();
    if (nullptr == puiData)
    {
        TEST_END_METHOD( KTgE_FAIL );
    };
    sFileBlock.pui = puiData;

    Test__Expect_EQ(KTgS_OK, tgCM_File_Check_Block( sFileBlock.ps ));

    free( puiData );
    TEST_END_METHOD( KTgS_OK );
}

