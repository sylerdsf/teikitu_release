/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Util MT - LA Ring Buffer SRSW.c
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

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Init );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Used_Size );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Free_Size );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Max_Size );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Push_Next_Index );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Push_Commit );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Pop_Next_Index );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Pop_Commit );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/* Public Functions                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__UTIL_MT_LA_Ring_Buffer_SRSW ----------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_LA_Ring_Buffer_SRSW )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Init());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Used_Size());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Free_Size());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Max_Size());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Push_Next_Index());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Push_Commit());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Pop_Next_Index());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Pop_Commit());

    TEST_END_METHOD( KTgS_OK );
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Init ------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Init )
{
    STg2_UT_LF__LA_RB_SRSW              sSRSW;

    tgCM_UT_LF__LA_RB_SRSW__Init( &sSRSW, 10 );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Used_Size ------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Used_Size )
{
    STg2_UT_LF__LA_RB_SRSW              sSRSW;

    tgCM_UT_LF__LA_RB_SRSW__Init( &sSRSW, 10 );

    Test__Expect_EQ(0,tgCM_UT_LF__LA_RB_SRSW__Query_Used_Size( &sSRSW ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Free_Size ------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Free_Size )
{
    STg2_UT_LF__LA_RB_SRSW              sSRSW;

    tgCM_UT_LF__LA_RB_SRSW__Init( &sSRSW, 10 );

    Test__Expect_EQ(10,tgCM_UT_LF__LA_RB_SRSW__Query_Free_Size( &sSRSW ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Max_Size -------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Query_Max_Size )
{
    STg2_UT_LF__LA_RB_SRSW              sSRSW;

    tgCM_UT_LF__LA_RB_SRSW__Init( &sSRSW, 10 );

    Test__Expect_EQ(10,tgCM_UT_LF__LA_RB_SRSW__Query_Max_Size( &sSRSW ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Push_Next_Index ------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Push_Next_Index )
{
    STg2_UT_LF__LA_RB_SRSW              sSRSW;

    tgCM_UT_LF__LA_RB_SRSW__Init( &sSRSW, 10 );

    Test__Expect_EQ(0,tgCM_UT_LF__LA_RB_SRSW__Push_Next_Index( &sSRSW ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Push_Commit ----------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Push_Commit )
{
    STg2_UT_LF__LA_RB_SRSW              sSRSW;

    tgCM_UT_LF__LA_RB_SRSW__Init( &sSRSW, 10 );

    tgCM_UT_LF__LA_RB_SRSW__Push_Commit( &sSRSW );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Pop_Next_Index -------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Pop_Next_Index )
{
    STg2_UT_LF__LA_RB_SRSW              sSRSW;

    tgCM_UT_LF__LA_RB_SRSW__Init( &sSRSW, 10 );

    tgCM_UT_LF__LA_RB_SRSW__Push_Commit( &sSRSW );
    Test__Expect_EQ(0,tgCM_UT_LF__LA_RB_SRSW__Pop_Next_Index( &sSRSW ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Pop_Commit ------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__LA_RB_SRSW__Pop_Commit )
{
    STg2_UT_LF__LA_RB_SRSW              sSRSW;

    tgCM_UT_LF__LA_RB_SRSW__Init( &sSRSW, 10 );

    tgCM_UT_LF__LA_RB_SRSW__Push_Commit( &sSRSW );
    Test__Expect_EQ(0,tgCM_UT_LF__LA_RB_SRSW__Pop_Next_Index( &sSRSW ));
    tgCM_UT_LF__LA_RB_SRSW__Pop_Commit( &sSRSW );

    TEST_END_METHOD( KTgS_OK );
}
