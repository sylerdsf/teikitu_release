/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Util MT - Profile Sample.c
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

TEST_METHOD( UNIT_TEST__TEST__Profile_Sample_Reset );
TEST_METHOD( UNIT_TEST__TEST__Profile_Sample_Start );
TEST_METHOD( UNIT_TEST__TEST__Profile_Sample_Stop );
TEST_METHOD( UNIT_TEST__TEST__Profile_Sample_Report );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/* Public Functions                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__UTIL_MT_Profile_Sample ---------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_Profile_Sample )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__Profile_Sample_Reset());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__Profile_Sample_Start());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__Profile_Sample_Stop());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__Profile_Sample_Report());

    TEST_END_METHOD( KTgS_OK );
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__Profile_Sample_Reset ------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__Profile_Sample_Reset )
{
    STg2_Profile_Record                 sRecord;

    tgProfile_Sample_Reset( &sRecord );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__Profile_Sample_Start ------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__Profile_Sample_Start )
{
    STg2_Profile_Record                 sRecord;
    TgSINT_F64                          iStart;

    tgProfile_Sample_Reset( &sRecord );
    iStart = tgProfile_Sample_Start( &sRecord );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__Profile_Sample_Stop ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__Profile_Sample_Stop )
{
    STg2_Profile_Record                 sRecord;
    TgSINT_F64                          iStart;
    TgSINT_F64                          iEnd;

    tgProfile_Sample_Reset( &sRecord );
    iStart = tgProfile_Sample_Start( &sRecord );
    Unit_Test__Sleep( 1000000 );
    iEnd = tgProfile_Sample_Stop( &sRecord );
    Test__Expect_EQ(true, iEnd > iStart);

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__Profile_Sample_Report ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__Profile_Sample_Report )
{
    STg2_Profile_Record                 sRecord;
    TgSINT_F64                          iStart;
    TgSINT_F64                          iEnd;

    tgProfile_Sample_Reset( &sRecord );
    iStart = tgProfile_Sample_Start( &sRecord );
    Unit_Test__Sleep( 1000000 );
    iEnd = tgProfile_Sample_Stop( &sRecord );
    Test__Expect_EQ(true, iEnd > iStart);
    tgProfile_Sample_Report( &sRecord );
    Test__Expect_EQ(true, sRecord.m_fReport_Total > 0.0F);
    Test__Expect_EQ(true, sRecord.m_fReport_Idle > 0.0F);
    Test__Expect_EQ(true, sRecord.m_fReport_Sample > 0.0F);

    TEST_END_METHOD( KTgS_OK );
}
