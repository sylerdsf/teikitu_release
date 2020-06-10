/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Mem MGR.c
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

TEST_METHOD( UNIT_TEST__TEST__MM_Init_MGR );
TEST_METHOD( UNIT_TEST__TEST__MM_Boot_MGR );
TEST_METHOD( UNIT_TEST__TEST__MM_Stop_MGR );
TEST_METHOD( UNIT_TEST__TEST__MM_Free_MGR );
TEST_METHOD( UNIT_TEST__TEST__MM_Update_MGR );
TEST_METHOD( UNIT_TEST__TEST__MM_Query_Fixed_Memory );
TEST_METHOD( UNIT_TEST__TEST__MM_Query_Init );
TEST_METHOD( UNIT_TEST__TEST__MM_Query_Boot );

TEST_METHOD( UNIT_TEST__TEST__MM_Page_Size );
TEST_METHOD( UNIT_TEST__TEST__MM_Register_Allocator );
TEST_METHOD( UNIT_TEST__TEST__MM_Stats );

TEST_METHOD( UNIT_TEST__TEST__MM_Size );
TEST_METHOD( UNIT_TEST__TEST__MM_Malloc );
TEST_METHOD( UNIT_TEST__TEST__MM_Reserve );
TEST_METHOD( UNIT_TEST__TEST__MM_Commit );
TEST_METHOD( UNIT_TEST__TEST__MM_Free );
TEST_METHOD( UNIT_TEST__TEST__MM_Realloc );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/* Public Functions                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__COMMON_Mem_MGR ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_Mem_MGR )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Init_MGR());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Boot_MGR());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Stop_MGR());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Free_MGR());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Update_MGR());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Query_Fixed_Memory());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Query_Init());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Query_Boot());

    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Page_Size());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Register_Allocator());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Stats());

    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Size());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Malloc());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Reserve());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Commit());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Free());
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__TEST__MM_Realloc());

    TEST_END_METHOD( KTgS_OK );
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__MM_Init_MGR --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Init_MGR )
{
    /* Due to their nature, module management functions can not be unit tested */

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Boot_MGR --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Boot_MGR )
{
    /* Due to their nature, module management functions can not be unit tested */

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Stop_MGR --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Stop_MGR )
{
    /* Due to their nature, module management functions can not be unit tested */

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Free_MGR --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Free_MGR )
{
    /* Due to their nature, module management functions can not be unit tested */

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Update_MGR ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Update_MGR )
{
    /* Due to their nature, module management functions can not be unit tested */

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Query_Fixed_Memory ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Query_Fixed_Memory )
{
    tgMM_Query_Fixed_Memory();

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Query_Init ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Query_Init )
{
    Test__Expect_EQ(true, tgMM_Query_Init());

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Query_Boot ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Query_Boot )
{
    Test__Expect_EQ(true, tgMM_Query_Boot());

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Page_Size -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Page_Size )
{
    Test__Expect_NE(0, tgMM_Page_Size());

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Register_Allocator ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Register_Allocator )
{
    /* Due to their nature, module management functions can not be unit tested */
    /* Since the base two allocators use this function in Init_MGR it is tested as a regular part of the manager */
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Stats ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Stats )
{
#if TgS_STAT__COMMON
    TgCHAR_MB                           mbzBuffer[256];
    STg2_Output_MEM                     sOutput;
    TgUN_POINTER                        sBuffer;

    sBuffer.m_mbz = mbzBuffer;

    /* Create a memory base output object to be used when testing the console output systems */
    tgIO_OM__Open( &sOutput, sBuffer.m_puiE08, sizeof( mbzBuffer ), nullptr );
    mbzBuffer[0] = 0;

    tgMM_Stats( &sOutput.m_sOutput );

/*# TgS_STAT__COMMON */
#endif

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Size ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Size )
{
    TgUINT_F32                          uiPage_Size;

    uiPage_Size = tgMM_Page_Size();

    for (ETgMM_ALLOCATOR uiAllocator = ETgMM_ALLOCATOR_BEGIN; uiAllocator < ETgMM_ALLOCATOR_USER_0; ++uiAllocator)
    {
        TgUN_PTR                            uMem;

        Test__Expect_EQ(0, tgMM_Size( uiAllocator, nullptr ));

        uMem.m_pVoid = tgMM_Malloc( uiAllocator, 1 );
        Test__Expect_NE(nullptr, uMem.m_pVoid);
        Test__Expect_EQ(true, tgMM_Size( uiAllocator, uMem.m_pVoid ) >= 1);
        tgMM_Free( uiAllocator, uMem.m_pVoid );

        for (TgRSIZE nuiTest = 0; nuiTest < 1000; ++nuiTest)
        {
            TgRSIZE                             uiSize;

            uiSize = tgCM_RAND_MT_U32() % (10 * uiPage_Size);

            uMem.m_pVoid = tgMM_Malloc( uiAllocator, uiSize );
            Test__Expect_NE(nullptr, uMem.m_pVoid);
            Test__Expect_EQ(true, tgMM_Size( uiAllocator, uMem.m_pVoid ) >= uiSize);
            tgMM_Free( uiAllocator, uMem.m_pVoid );
        };
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Malloc ----------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Malloc )
{
    TgUINT_F32                          uiPage_Size;

    uiPage_Size = tgMM_Page_Size();

    for (ETgMM_ALLOCATOR uiAllocator = ETgMM_ALLOCATOR_BEGIN; uiAllocator < ETgMM_ALLOCATOR_USER_0; ++uiAllocator)
    {
        TgUN_PTR                            uMem;

        Test__Expect_EQ(0, tgMM_Size( uiAllocator, nullptr ));

        uMem.m_pVoid = tgMM_Malloc( uiAllocator, 1 );
        Test__Expect_NE(nullptr, uMem.m_pVoid);
        tgMM_Free( uiAllocator, uMem.m_pVoid );

        for (TgRSIZE nuiTest = 0; nuiTest < 1000; ++nuiTest)
        {
            TgRSIZE                             uiSize;

            uiSize = tgCM_RAND_MT_U32() % (10 * uiPage_Size);

            uMem.m_pVoid = tgMM_Malloc( uiAllocator, uiSize );
            Test__Expect_NE(nullptr, uMem.m_pVoid);
            tgMM_Free( uiAllocator, uMem.m_pVoid );
        };
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Reserve ---------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Reserve )
{
    TgUINT_F32                          uiPage_Size;

    uiPage_Size = tgMM_Page_Size();

    for (ETgMM_ALLOCATOR uiAllocator = ETgMM_ALLOCATOR_BEGIN; uiAllocator < ETgMM_ALLOCATOR_USER_0; ++uiAllocator)
    {
        TgUN_PTR                            uReserve;

        uReserve.m_pVoid = tgMM_Reserve( uiAllocator, 1 );
        if (nullptr == uReserve.m_pVoid)
        {
            continue;
        };
        tgMM_Free( uiAllocator, uReserve.m_pVoid );

        for (TgRSIZE nuiTest = 0; nuiTest < 1000; ++nuiTest)
        {
            TgRSIZE                             uiSize;

            uiSize = 8 * uiPage_Size + tgCM_RAND_MT_U32() % (10 * uiPage_Size);

            /* Virtual Memory - Reserve a range of pages (no good way to test for non-committed pages due to page fault) */
            uReserve.m_pVoid = tgMM_Reserve( uiAllocator, uiSize );
            Test__Expect_NE(nullptr, uReserve.m_pVoid);

            /* Virtual Memory - Free all pages associated with this allocation */
            tgMM_Free( uiAllocator, uReserve.m_pVoid );
        };
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Commit ----------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Commit )
{
    TgUINT_F32                          uiPage_Size;

    uiPage_Size = tgMM_Page_Size();

    for (ETgMM_ALLOCATOR uiAllocator = ETgMM_ALLOCATOR_BEGIN; uiAllocator < ETgMM_ALLOCATOR_USER_0; ++uiAllocator)
    {
        TgUN_PTR                            uCommit;

        uCommit.m_pVoid = tgMM_Commit( uiAllocator, nullptr, 1 );
        if (nullptr == uCommit.m_pVoid)
        {
            continue;
        };
        tgMM_Free( uiAllocator, uCommit.m_pVoid );

        for (TgRSIZE nuiTest = 0; nuiTest < 1000; ++nuiTest)
        {
            TgRSIZE                             uiSize;
            TgUN_PTR                            uReserve;

            uiSize = 8 * uiPage_Size + tgCM_RAND_MT_U32() % (10 * uiPage_Size);

            /* Virtual Memory - Reserve a range of pages (no good way to test for non-committed pages due to page fault) */
            uReserve.m_pVoid = tgMM_Reserve( uiAllocator, uiSize );
            Test__Expect_NE(nullptr, uReserve.m_pVoid);

            /* Virtual Memory - Standard commit */
            Test__Expect_EQ(uReserve.m_pVoid, tgMM_Commit( uiAllocator, uReserve.m_pVoid, 2 * uiPage_Size ));

            /* Virtual Memory - Commit pages non-contiguous from reserve start */
            uCommit.m_pVoid = uReserve.m_pVoid;
            uCommit.m_uiPTR += 4 * uiPage_Size;
            Test__Expect_EQ(uCommit.m_pVoid, tgMM_Commit( uiAllocator, uCommit.m_pVoid, 4 * uiPage_Size ));

            /* Virtual Memory - Recommitting pages */
            Test__Expect_EQ(uCommit.m_pVoid, tgMM_Commit( uiAllocator, uCommit.m_pVoid, 4 * uiPage_Size ));

            /* Virtual Memory - Failure for over commit */
            /* Test__Expect_EQ(nullptr, tgMM_Commit( uiAllocator, uCommit.m_uiPTR, 10 * uiPage_Size )); */

            /* Virtual Memory - Free all pages associated with this allocation */
            tgMM_Free( uiAllocator, uReserve.m_pVoid );
        };
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Free ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Free )
{
    /* Tested as part of the Malloc, Reserve and Commit */
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Realloc ---------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD( UNIT_TEST__TEST__MM_Realloc )
{
    TgUINT_F32                          uiPage_Size;

    uiPage_Size = tgMM_Page_Size();

    for (ETgMM_ALLOCATOR uiAllocator = ETgMM_ALLOCATOR_BEGIN; uiAllocator < ETgMM_ALLOCATOR_USER_0; ++uiAllocator)
    {
        TgUN_PTR                            uMem_0, uMem_1;

        Test__Expect_EQ(0, tgMM_Size( uiAllocator, nullptr ));

        uMem_0.m_pVoid = tgMM_Malloc( uiAllocator, 1 );
        Test__Expect_NE(nullptr, uMem_0.m_pVoid);
        uMem_1.m_pVoid = tgMM_Realloc( uiAllocator, uMem_0.m_pVoid, 1 );
        if (nullptr == uMem_1.m_pVoid)
        {
            tgMM_Free( uiAllocator, uMem_0.m_pVoid );
            continue;
        };
        tgMM_Free( uiAllocator, uMem_1.m_pVoid );

        for (TgRSIZE nuiTest = 0; nuiTest < 1000; ++nuiTest)
        {
            TgRSIZE                             uiSize;

            uiSize = tgCM_RAND_MT_U32() % (10 * uiPage_Size);
            uMem_0.m_pVoid = tgMM_Malloc( uiAllocator, uiSize );
            Test__Expect_NE(nullptr, uMem_0.m_pVoid);

            uiSize = tgCM_RAND_MT_U32() % (10 * uiPage_Size);
            uMem_1.m_pVoid = tgMM_Realloc( uiAllocator, uMem_0.m_pVoid, uiSize );
            Test__Expect_NE(nullptr, uMem_1.m_pVoid);
            tgMM_Free( uiAllocator, uMem_1.m_pVoid );
        };
    };

    TEST_END_METHOD( KTgS_OK );
}
