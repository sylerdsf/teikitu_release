/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Util ST - Queue.c
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

TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Init );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Free );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Enqueue );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Merge );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Dequeue );
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Is_Empty );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/* Public Functions                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__UTIL_ST_Queue ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_ST_Queue )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_ST__QU__Init());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_ST__QU__Free());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_ST__QU__Enqueue());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_ST__QU__Merge());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_ST__QU__Dequeue());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_ST__QU__Is_Empty());
    
    TEST_END_METHOD( KTgS_OK );
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__CM_UT_ST__QU__Init -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Init )
{
    STg2_UT_ST__QU                      sQU;

    Test__Expect_EQ(KTgS_OK, tgCM_UT_ST__QU__Init( &sQU ));
    tgCM_UT_ST__QU__Free( &sQU );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_ST__QU__Free -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Free )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_ST__QU__Init());
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_ST__QU__Enqueue ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Enqueue )
{
    STg2_UT_ST__QU                      sQU;
    STg2_UT_ST__QU_Node                 sData[4];

    Test__Expect_EQ(KTgS_OK, tgCM_UT_ST__QU__Init( &sQU ));

    sData[0].m_pNext_Node = (TgVOID_P)nullptr;
    tgCM_UT_ST__QU__Enqueue( &sQU, sData );
    Test__Expect_EQ(false, tgCM_UT_ST__QU__Is_Empty( &sQU ));
    Test__Expect_EQ(true, sData == tgCM_UT_ST__QU__Dequeue( &sQU ));
    Test__Expect_EQ(true, tgCM_UT_ST__QU__Is_Empty( &sQU ));
    Test__Expect_EQ(true, nullptr == tgCM_UT_ST__QU__Dequeue( &sQU ));

    sData[1].m_pNext_Node = (TgVOID_P)nullptr;
    tgCM_UT_ST__QU__Enqueue( &sQU, sData + 1 );
    sData[2].m_pNext_Node = (TgVOID_P)nullptr;
    tgCM_UT_ST__QU__Enqueue( &sQU, sData + 2 );
    sData[3].m_pNext_Node = (TgVOID_P)nullptr;
    tgCM_UT_ST__QU__Enqueue( &sQU, sData + 3 );
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_ST__QU__Dequeue( &sQU ));
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_ST__QU__Dequeue( &sQU ));
    Test__Expect_EQ(true, sData + 3 == tgCM_UT_ST__QU__Dequeue( &sQU ));

    sData[1].m_pNext_Node = sData + 2;
    sData[2].m_pNext_Node = sData + 3;
    sData[3].m_pNext_Node = (TgVOID_P)nullptr;
    tgCM_UT_ST__QU__Enqueue( &sQU, sData + 1 );
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_ST__QU__Dequeue( &sQU ));
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_ST__QU__Dequeue( &sQU ));
    Test__Expect_EQ(true, sData + 3 == tgCM_UT_ST__QU__Dequeue( &sQU ));

    tgCM_UT_ST__QU__Free( &sQU );
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_ST__QU__Merge ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Merge )
{
    STg2_UT_ST__QU                      sQU0, sQU1;
    STg2_UT_ST__QU_Node                 sData[7];

    Test__Expect_EQ(KTgS_OK, tgCM_UT_ST__QU__Init( &sQU0 ));
    Test__Expect_EQ(KTgS_OK, tgCM_UT_ST__QU__Init( &sQU1 ));

    sData[0].m_pNext_Node = sData + 1;
    sData[1].m_pNext_Node = sData + 2;
    sData[2].m_pNext_Node = (TgVOID_P)nullptr;
    tgCM_UT_ST__QU__Enqueue( &sQU0, sData + 0 );

    sData[3].m_pNext_Node = sData + 5;
    sData[4].m_pNext_Node = sData + 6;
    sData[5].m_pNext_Node = sData + 4;
    sData[6].m_pNext_Node = (TgVOID_P)nullptr;
    tgCM_UT_ST__QU__Enqueue( &sQU1, sData + 3 );
    
    tgCM_UT_ST__QU__Merge( &sQU0, &sQU1 );

    Test__Expect_EQ(true, tgCM_UT_ST__QU__Is_Empty( &sQU1 ));
    Test__Expect_EQ(true, sData + 0 == tgCM_UT_ST__QU__Dequeue( &sQU0 ));
    Test__Expect_EQ(true, sData + 1 == tgCM_UT_ST__QU__Dequeue( &sQU0 ));
    Test__Expect_EQ(true, sData + 2 == tgCM_UT_ST__QU__Dequeue( &sQU0 ));
    Test__Expect_EQ(true, sData + 3 == tgCM_UT_ST__QU__Dequeue( &sQU0 ));
    Test__Expect_EQ(true, sData + 5 == tgCM_UT_ST__QU__Dequeue( &sQU0 ));
    Test__Expect_EQ(true, sData + 4 == tgCM_UT_ST__QU__Dequeue( &sQU0 ));
    Test__Expect_EQ(true, sData + 6 == tgCM_UT_ST__QU__Dequeue( &sQU0 ));
    Test__Expect_EQ(true, tgCM_UT_ST__QU__Is_Empty( &sQU0 ));

    tgCM_UT_ST__QU__Free( &sQU0 );
    tgCM_UT_ST__QU__Free( &sQU1 );

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_ST__QU__Dequeue ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Dequeue )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__CM_UT_ST__QU__Enqueue());
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_UT_ST__QU__Is_Empty ---------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__CM_UT_ST__QU__Is_Empty )
{
    STg2_UT_ST__QU                      sQU;
    STg2_UT_ST__QU_Node                 sData[4];

    Test__Expect_EQ(KTgS_OK, tgCM_UT_ST__QU__Init( &sQU ));

    sData[0].m_pNext_Node = (TgVOID_P)nullptr;
    tgCM_UT_ST__QU__Enqueue( &sQU, sData );
    Test__Expect_EQ(false, tgCM_UT_ST__QU__Is_Empty( &sQU ));
    Test__Expect_EQ(true, sData == tgCM_UT_ST__QU__Dequeue( &sQU ));
    Test__Expect_EQ(true, tgCM_UT_ST__QU__Is_Empty( &sQU ));
    Test__Expect_EQ(true, nullptr == tgCM_UT_ST__QU__Dequeue( &sQU ));

    tgCM_UT_ST__QU__Free( &sQU );
    TEST_END_METHOD( KTgS_OK );
}
