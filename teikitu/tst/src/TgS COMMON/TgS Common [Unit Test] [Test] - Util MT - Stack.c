/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Util MT - Stack.c
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

TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Init );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Init );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Init_PreLoad );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Free );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Push );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Pop );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Pop_Wait_Yield );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Pop_Wait_Spin );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Is_Empty );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Release );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Merge );


#if TgCOMPILE__THREAD
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Init );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Free );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Push );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Pop );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Pop_Wait_Block );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Is_Empty );

/*# TgCOMPILE__THREAD */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/* Public Functions                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__UTIL_MT_Stack ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_Stack )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Init());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Init());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Init_PreLoad());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Free());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Push());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Pop());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Pop_Wait_Yield());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Pop_Wait_Spin());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Is_Empty());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Release());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Merge());


    #if TgCOMPILE__THREAD
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Init());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Free());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Push());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Pop());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Pop_Wait_Block());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Is_Empty());

    /*# TgCOMPILE__THREAD */
    #endif
    TEST_END_METHOD( KTgS_OK );
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Init -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Init )
{
    STg2_UT_LF__ST                      sAMST;

    tgCM_UT_LF__ST__Init( &sAMST );
    tgCM_UT_LF__ST__Free( &sAMST );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Init_PreLoad ------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Init_PreLoad )
{
    STg2_UT_LF__ST                      sAMST;
    STg2_UT_ST__ST_Node                 sData[4];

    tgCM_UT_LF__ST__Init_PreLoad( &sAMST, sData, sizeof( sData[0] ), 4 );

    Test__Expect_EQ(false, tgCM_UT_LF__ST__Is_Empty( &sAMST ));
    Test__Expect_EQ(true, sData + 0 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, sData + 3 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, nullptr == tgCM_UT_LF__ST__Pop( &sAMST ));

    tgCM_UT_LF__ST__Free( &sAMST );
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Free -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Free )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Init());
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Push -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Push )
{
    STg2_UT_LF__ST                      sAMST;
    STg2_UT_ST__ST_Node                 sData[4];

    tgCM_UT_LF__ST__Init( &sAMST );

    tgCM_UT_LF__ST__Push( &sAMST, sData );
    Test__Expect_EQ(true, sData == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, tgCM_UT_LF__ST__Is_Empty( &sAMST ));
    Test__Expect_EQ(true, nullptr == tgCM_UT_LF__ST__Pop( &sAMST ));
    tgCM_UT_LF__ST__Push( &sAMST, sData + 0 );
    tgCM_UT_LF__ST__Push( &sAMST, sData + 1 );
    tgCM_UT_LF__ST__Push( &sAMST, sData + 2 );
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, sData + 0 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, tgCM_UT_LF__ST__Is_Empty( &sAMST ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Pop --------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Pop )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Push());
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Pop_Wait_Yield ---------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Pop_Wait_Yield )
{
    STg2_UT_LF__ST                      sAMST;
    STg2_UT_ST__ST_Node                 sData[4];

    tgCM_UT_LF__ST__Init( &sAMST );

    tgCM_UT_LF__ST__Push( &sAMST, sData );
    Test__Expect_EQ(false, tgCM_UT_LF__ST__Is_Empty( &sAMST ));
    Test__Expect_EQ(true, sData == tgCM_UT_LF__ST__Pop_Wait_Yield( &sAMST ));
    Test__Expect_EQ(true, tgCM_UT_LF__ST__Is_Empty( &sAMST ));
    tgCM_UT_LF__ST__Push( &sAMST, sData + 0 );
    tgCM_UT_LF__ST__Push( &sAMST, sData + 1 );
    tgCM_UT_LF__ST__Push( &sAMST, sData + 2 );
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_LF__ST__Pop_Wait_Yield( &sAMST ));
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_LF__ST__Pop_Wait_Yield( &sAMST ));
    Test__Expect_EQ(true, sData + 0 == tgCM_UT_LF__ST__Pop_Wait_Yield( &sAMST ));
    Test__Expect_EQ(true, tgCM_UT_LF__ST__Is_Empty( &sAMST ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Pop_Wait_Spin ----------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Pop_Wait_Spin )
{
    STg2_UT_LF__ST                      sAMST;
    STg2_UT_ST__ST_Node                 sData[4];

    tgCM_UT_LF__ST__Init( &sAMST );

    tgCM_UT_LF__ST__Push( &sAMST, sData );
    Test__Expect_EQ(true, sData == tgCM_UT_LF__ST__Pop_Wait_Spin( &sAMST ));
    Test__Expect_EQ(true, tgCM_UT_LF__ST__Is_Empty( &sAMST ));
    tgCM_UT_LF__ST__Push( &sAMST, sData + 0 );
    tgCM_UT_LF__ST__Push( &sAMST, sData + 1 );
    tgCM_UT_LF__ST__Push( &sAMST, sData + 2 );
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_LF__ST__Pop_Wait_Spin( &sAMST ));
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_LF__ST__Pop_Wait_Spin( &sAMST ));
    Test__Expect_EQ(true, sData + 0 == tgCM_UT_LF__ST__Pop_Wait_Spin( &sAMST ));
    Test__Expect_EQ(true, tgCM_UT_LF__ST__Is_Empty( &sAMST ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Is_Empty ---------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Is_Empty )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_LF__ST__Release());
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Release ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Release )
{
    STg2_UT_LF__ST                      sAMST;
    STg2_UT_ST__ST_Node                 sData[4];

    tgCM_UT_LF__ST__Init( &sAMST );

    tgCM_UT_LF__ST__Push( &sAMST, sData );
    Test__Expect_EQ(false, tgCM_UT_LF__ST__Is_Empty( &sAMST ));
    Test__Expect_EQ(true, sData == tgCM_UT_LF__ST__Release( &sAMST ));
    Test__Expect_EQ(true, tgCM_UT_LF__ST__Is_Empty( &sAMST ));

    tgCM_UT_LF__ST__Free( &sAMST );
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_LF__ST__Merge ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_LF__ST__Merge )
{
    STg2_UT_LF__ST                      sAMST;
    STg2_UT_ST__ST_Node                 sData[4];

    tgCM_UT_LF__ST__Init( &sAMST );

    sData[0].m_pNext_Node = sData + 1;
    sData[1].m_pNext_Node = sData + 2;
    sData[2].m_pNext_Node = sData + 3;
    sData[3].m_pNext_Node = (TgVOID_P)nullptr;

    tgCM_UT_LF__ST__Merge( &sAMST, sData + 0, sData + 3 );
    Test__Expect_EQ(false, tgCM_UT_LF__ST__Is_Empty( &sAMST ));
    Test__Expect_EQ(true, sData + 0 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, sData + 3 == tgCM_UT_LF__ST__Pop( &sAMST ));
    Test__Expect_EQ(true, nullptr == tgCM_UT_LF__ST__Pop( &sAMST ));

    tgCM_UT_LF__ST__Free( &sAMST );
    TEST_END_METHOD( KTgS_OK );
}




#if TgCOMPILE__THREAD
/* ---- UNIT_TEST__TEST__CM_UT_MT__ST_MX__Init ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Init )
{
    STg2_UT_MT__ST_MX                   sST;

    tgCM_UT_MT__ST_MX__Init( &sST, "UTM_ST_Test_000" );
    tgCM_UT_MT__ST_MX__Free( &sST );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_MT__ST_MX__Free ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Free )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Init());
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_MT__ST_MX__Push ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Push )
{
    STg2_UT_ST__ST_Node                 sData[4];
    STg2_UT_MT__ST_MX                   sST;

    tgCM_UT_MT__ST_MX__Init( &sST, "UTM_ST_Test_001" );

    tgCM_UT_MT__ST_MX__Push( &sST, sData );
    Test__Expect_EQ(false, tgCM_UT_MT__ST_MX__Is_Empty( &sST ));
    Test__Expect_EQ(true, sData == tgCM_UT_MT__ST_MX__Pop( &sST ));
    Test__Expect_EQ(true, tgCM_UT_MT__ST_MX__Is_Empty( &sST ));
    Test__Expect_EQ(true, nullptr == tgCM_UT_MT__ST_MX__Pop( &sST ));
    tgCM_UT_MT__ST_MX__Push( &sST, sData + 0 );
    tgCM_UT_MT__ST_MX__Push( &sST, sData + 1 );
    tgCM_UT_MT__ST_MX__Push( &sST, sData + 2 );
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_MT__ST_MX__Pop( &sST ));
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_MT__ST_MX__Pop( &sST ));
    Test__Expect_EQ(true, sData + 0 == tgCM_UT_MT__ST_MX__Pop( &sST ));
    Test__Expect_EQ(true, tgCM_UT_MT__ST_MX__Is_Empty( &sST ));

    tgCM_UT_MT__ST_MX__Free( &sST );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_MT__ST_MX__Pop ------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Pop )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Push());
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_MT__ST_MX__Pop_Wait_Block ------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Pop_Wait_Block )
{
    STg2_UT_ST__ST_Node                 sData[4];
    STg2_UT_MT__ST_MX                   sST;

    tgCM_UT_MT__ST_MX__Init( &sST, "UTM_ST_Test_000" );
    tgCM_UT_MT__ST_MX__Free( &sST );
    tgCM_UT_MT__ST_MX__Init( &sST, "UTM_ST_Test_001" );

    tgCM_UT_MT__ST_MX__Push( &sST, sData );
    Test__Expect_EQ(false, tgCM_UT_MT__ST_MX__Is_Empty( &sST ));
    Test__Expect_EQ(true, sData == tgCM_UT_MT__ST_MX__Pop_Wait_Block( &sST ));
    Test__Expect_EQ(true, tgCM_UT_MT__ST_MX__Is_Empty( &sST ));
    tgCM_UT_MT__ST_MX__Push( &sST, sData + 0 );
    tgCM_UT_MT__ST_MX__Push( &sST, sData + 1 );
    tgCM_UT_MT__ST_MX__Push( &sST, sData + 2 );
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_MT__ST_MX__Pop_Wait_Block( &sST ));
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_MT__ST_MX__Pop_Wait_Block( &sST ));
    Test__Expect_EQ(true, sData + 0 == tgCM_UT_MT__ST_MX__Pop_Wait_Block( &sST ));
    Test__Expect_EQ(true, tgCM_UT_MT__ST_MX__Is_Empty( &sST ));

    tgCM_UT_MT__ST_MX__Free( &sST );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_MT__ST_MX__Is_Empty ------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_MT__ST_MX__Is_Empty )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_MT__ST_MX__Push());
    TEST_END_METHOD( KTgS_OK );
}


/*# TgCOMPILE__THREAD */
#endif
