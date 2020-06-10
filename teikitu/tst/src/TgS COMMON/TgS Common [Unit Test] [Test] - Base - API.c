/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Base - API.c
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

TEST_METHOD( UNIT_TEST__TEST__CM_Init_Random_MT );
TEST_METHOD( UNIT_TEST__TEST__CM_Init_Random_MT__Key_List );
TEST_METHOD( UNIT_TEST__TEST__CM_RAND_MT_U32 );
TEST_METHOD( UNIT_TEST__TEST__CM_RAND_NRM_F32 );
TEST_METHOD( UNIT_TEST__TEST__MM_Copy );
TEST_METHOD( UNIT_TEST__TEST__MM_Move );
TEST_METHOD( UNIT_TEST__TEST__MM_Set_U08 );
TEST_METHOD( UNIT_TEST__TEST__MM_Set_U08_0x00 );
TEST_METHOD( UNIT_TEST__TEST__MM_Set_U08_0xFF );
TEST_METHOD( UNIT_TEST__TEST__MM_Compare );
TEST_METHOD( UNIT_TEST__TEST__TM_Init );
TEST_METHOD( UNIT_TEST__TEST__TM_Query_Counter_Tick );
TEST_METHOD( UNIT_TEST__TEST__TM_Counter_Tick_To_MilliSeconds );
TEST_METHOD( UNIT_TEST__TEST__TM_Query_Time );
TEST_METHOD( UNIT_TEST__TEST__TM_Channel_Query_Time );
TEST_METHOD( UNIT_TEST__TEST__TM_Channel_Elapsed_Time );
TEST_METHOD( UNIT_TEST__TEST__TM_Channel_Reset );
TEST_METHOD( UNIT_TEST__TEST__TM_Channel_Start );
TEST_METHOD( UNIT_TEST__TEST__TM_Channel_Stop );
TEST_METHOD( UNIT_TEST__TEST__TM_Channel_Update );
TEST_METHOD( UNIT_TEST__TEST__TM_Channel_Step );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Open );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Read );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Write );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Flush );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Close );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Valid );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Seek );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Size );
TEST_METHOD( UNIT_TEST__TEST__IO_Directory_Make );
TEST_METHOD( UNIT_TEST__TEST__IO_Directory_Remove );
TEST_METHOD( UNIT_TEST__TEST__IO_Directory_Exists );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Delete );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Copy );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Move );
TEST_METHOD( UNIT_TEST__TEST__IO_File_Exists );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/* Public Functions                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__Base_API ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__Base_API )
{
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Init_Random_MT() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_Init_Random_MT__Key_List() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_RAND_MT_U32() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__CM_RAND_NRM_F32() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__MM_Copy() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__MM_Move() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__MM_Set_U08() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__MM_Set_U08_0x00() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__MM_Set_U08_0xFF() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__MM_Compare() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Init() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Query_Counter_Tick() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Counter_Tick_To_MilliSeconds() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Query_Time() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Channel_Query_Time() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Channel_Elapsed_Time() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Channel_Reset() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Channel_Start() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Channel_Stop() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Channel_Update() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__TM_Channel_Step() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Open() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Read() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Write() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Flush() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Close() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Valid() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Seek() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Size() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_Directory_Make() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_Directory_Remove() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_Directory_Exists() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Delete() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Copy() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Move() );
    Test__Expect_EQ( KTgS_OK, UNIT_TEST__TEST__IO_File_Exists() );

    TEST_END_METHOD( KTgS_OK );
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__CM_Init_Random_MT --------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Init_Random_MT )
{
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_Init_Random_MT__Key_List ----------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_Init_Random_MT__Key_List )
{
    TgUINT_F32                          uiKeyList[512];
    TgUINT_F32                          uiRndList[512];
    TgUINT_F32                          uiIndex, uiCheck, uiCheck2;

    for (uiIndex = 0; uiIndex < 512; ++uiIndex)
    {
        uiKeyList[uiIndex] = uiIndex;
    };

    tgCM_Init_Random_MT__Key_List( uiKeyList, 512 );

    for (uiIndex = 0; uiIndex < 512; ++uiIndex)
    {
        uiRndList[uiIndex] = tgCM_RAND_MT_U32();
    };

    for (uiCheck = 0; uiCheck < 512; ++uiCheck)
    {
        for (uiCheck2 = 0; uiCheck2 < 512; ++uiCheck2)
        {
            if (uiCheck2 == uiCheck)
            {
                continue;
            };

            Test__Expect_NE(uiRndList[uiCheck], uiRndList[uiCheck2]);
        };
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_RAND_MT_U32 ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_RAND_MT_U32 )
{
    for (TgRSIZE uiIndex = 0; uiIndex < 128; ++uiIndex)
    {
        Test__Expect_NE(tgCM_RAND_MT_U32(), tgCM_RAND_MT_U32());
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__CM_RAND_NRM_F32 ----------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__CM_RAND_NRM_F32 )
{
    for (TgRSIZE uiIndex = 0; uiIndex < 128; ++uiIndex)
    {
        Test__Expect_NE(tgCM_RAND_NRM_F32( 1.0F, 1.0F ), tgCM_RAND_NRM_F32( 1.0F, 1.0F ));
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Copy ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__MM_Copy )
{


    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Move ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__MM_Move )
{


    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Set_U08 ---------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__MM_Set_U08 )
{


    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Set_U08_0x00 ----------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__MM_Set_U08_0x00 )
{


    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Set_U08_0xFF ----------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__MM_Set_U08_0xFF )
{


    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__MM_Compare ---------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__MM_Compare )
{


    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Init ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Init )
{
    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Query_Counter_Tick ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Query_Counter_Tick )
{
    Test__Expect_EQ(true, tgTM_Query_Counter_Tick() > 0);

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Counter_Tick_To_MilliSeconds ------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Counter_Tick_To_MilliSeconds )
{
    Test__Expect_EQ(true, tgTM_Counter_Tick_To_MilliSeconds( tgTM_Query_Counter_Tick() ) > 0.0f);

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Query_Time ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Query_Time )
{
    TgFLOAT32                           fTime1, fTime2;

    Test__Expect_EQ(true, tgTM_Query_Time() > 0.0f);

    fTime1 = tgTM_Query_Time();
    Unit_Test__Sleep( 50000000 );
    fTime2 = tgTM_Query_Time();
    Test__Expect_EQ(true, fTime1 < fTime2);
    Test__Expect_EQ(true, fTime2 >= fTime1 + 50.0f);

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Channel_Query_Time ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Channel_Query_Time )
{
    for (TgSINT_F32 iIndex = 0; iIndex < ETgTIME_CHANNEL__COUNT - 1; ++iIndex)
    {
        TgFLOAT32                           fTime1;

        fTime1 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, fTime1 > 0.0f);
        Unit_Test__Sleep( 1000000 );
        Test__Expect_EQ(true, tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex ) > fTime1);
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Channel_Elapsed_Time --------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Channel_Elapsed_Time )
{
    for (TgSINT_F32 iIndex = 0; iIndex < ETgTIME_CHANNEL__COUNT - 1; ++iIndex)
    {
        TgFLOAT32                           fTime1, fTime2, fTime4;


        fTime1 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        tgTM_Channel_Update( (ETgTIMER_CHANNEL)iIndex );
        Unit_Test__Sleep( 100000 );
        tgTM_Channel_Update( (ETgTIMER_CHANNEL)iIndex );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        
        fTime4 = tgTM_Channel_Elapsed_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, fTime2 >= fTime1 + fTime4);
        Test__Expect_EQ(true, fTime4 > 0.1F);
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Channel_Reset ---------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Channel_Reset )
{
    for (TgSINT_F32 iIndex = 0; iIndex < ETgTIME_CHANNEL__COUNT - 1; ++iIndex)
    {
        TgFLOAT32                           fTime1, fTime2;

        fTime1 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Unit_Test__Sleep( 100000 );

        tgTM_Channel_Update( (ETgTIMER_CHANNEL)iIndex );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );

        Test__Expect_EQ(true, fTime2 > 0.0f);
        Test__Expect_EQ(true, fTime1 != fTime2);
        Test__Expect_EQ(true, fTime2 > fTime1);

        Test__Expect_EQ(true, tgTM_Channel_Elapsed_Time( (ETgTIMER_CHANNEL)iIndex ) > 0.0f);

        tgTM_Channel_Reset( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, tgTM_Channel_Elapsed_Time( (ETgTIMER_CHANNEL)iIndex ) == 0.0f);
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Channel_Start ---------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Channel_Start )
{
    for (TgSINT_F32 iIndex = 0; iIndex < ETgTIME_CHANNEL__COUNT - 1; ++iIndex)
    {
        TgFLOAT32                           fTime1, fTime2;

        tgTM_Channel_Stop( (ETgTIMER_CHANNEL)iIndex );
        fTime1 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Unit_Test__Sleep( 100000 );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, tgCM_NR0_F32( fTime1 - fTime2 ));

        tgTM_Channel_Update( (ETgTIMER_CHANNEL)iIndex );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, tgCM_NR0_F32( fTime1 - fTime2 ));

        tgTM_Channel_Start( (ETgTIMER_CHANNEL)iIndex );
        fTime1 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Unit_Test__Sleep( 100000 );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, fTime2 - fTime1 > 0.1F );

        tgTM_Channel_Update( (ETgTIMER_CHANNEL)iIndex );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, fTime1 < fTime2);
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Channel_Stop ----------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Channel_Stop )
{
    for (TgSINT_F32 iIndex = 0; iIndex < ETgTIME_CHANNEL__COUNT - 1; ++iIndex)
    {
        TgFLOAT32                           fTime1, fTime2;

        tgTM_Channel_Stop( (ETgTIMER_CHANNEL)iIndex );
        fTime1 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Unit_Test__Sleep( 100000 );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, tgCM_NR0_F32( fTime1 - fTime2 ));

        tgTM_Channel_Update( (ETgTIMER_CHANNEL)iIndex );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, tgCM_NR0_F32( fTime1 - fTime2 ));
        
        tgTM_Channel_Start( (ETgTIMER_CHANNEL)iIndex );
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Channel_Update --------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Channel_Update )
{
    for (TgSINT_F32 iIndex = 0; iIndex < ETgTIME_CHANNEL__COUNT - 1; ++iIndex)
    {
        tgTM_Channel_Update( (ETgTIMER_CHANNEL)iIndex );
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__TM_Channel_Step ----------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__TM_Channel_Step )
{
    for (TgSINT_F32 iIndex = 0; iIndex < ETgTIME_CHANNEL__COUNT - 1; ++iIndex)
    {
        TgFLOAT32                           fTime1, fTime2;

        tgTM_Channel_Stop( (ETgTIMER_CHANNEL)iIndex );
        fTime1 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Unit_Test__Sleep( 100000 );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, tgCM_NR0_F32( fTime1 - fTime2 ));

        tgTM_Channel_Update( (ETgTIMER_CHANNEL)iIndex );
        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, tgCM_NR0_F32( fTime1 - fTime2 ));

        tgTM_Channel_Step( (ETgTIMER_CHANNEL)iIndex, 10.0f );

        fTime2 = tgTM_Channel_Query_Time( (ETgTIMER_CHANNEL)iIndex );
        Test__Expect_EQ(true, tgCM_NR0_F32( fTime2 - fTime1 - 10.0f ));
    };

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Open -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Open )
{
    TgSINT_PTR                          iFile;

    tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL );
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__INVALID ));

    Test__Expect_EQ(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__READ ));

    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__READ ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__SHARED | ETgFILE_IO_ACCESS__READ ));

    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__SHARED | ETgFILE_IO_ACCESS__WRITE ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__SHARED | ETgFILE_IO_ACCESS__READ ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__SHARED | ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Read -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Read )
{
    TgCHAR_MB_C                         szAnsi_Test_0[] = u8"Test: Happy New Year!\nС новым годом!\n新年好！\n賀正！\n¡Feliz año nuevo!\nHyvää uutta vuotta!\n";
    TgCHAR_MB                           szAnsi_0[sizeof(szAnsi_Test_0)] = { 0 };
    TgSINT_PTR                          iFile;
    TgRSIZE                             nbyWrite, nbyRead;
    
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    nbyWrite = tgIO_File_Write( iFile, szAnsi_Test_0, sizeof szAnsi_Test_0 );
    Test__Expect_EQ(sizeof szAnsi_Test_0, nbyWrite);
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));

    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__READ ));
    nbyRead = tgIO_File_Read( szAnsi_0, iFile, sizeof szAnsi_0 );
    Test__Expect_EQ(nbyRead, nbyWrite);
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(0, memcmp( szAnsi_Test_0, szAnsi_0, sizeof( szAnsi_Test_0 )));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Write ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Write )
{
    TgCHAR_MB_C                         szAnsi_Test_0[] = u8"Test: Happy New Year!\nС новым годом!\n新年好！\n賀正！\n¡Feliz año nuevo!\nHyvää uutta vuotta!\n";
    TgCHAR_MB                           szAnsi_0[sizeof(szAnsi_Test_0)] = { 0 };
    TgSINT_PTR                          iFile;
    TgRSIZE                             nbyWrite, nbyRead;
    
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    nbyWrite = tgIO_File_Write( iFile, szAnsi_Test_0, sizeof szAnsi_Test_0 );
    Test__Expect_EQ(sizeof szAnsi_Test_0, nbyWrite);
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));

    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__READ ));
    nbyRead = tgIO_File_Read( szAnsi_0, iFile, sizeof szAnsi_0 );
    Test__Expect_EQ(nbyRead, nbyWrite);
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(0, memcmp( szAnsi_Test_0, szAnsi_0, sizeof( szAnsi_Test_0 )));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Flush ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Flush )
{
    TgSINT_PTR                          iFile;
    
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Close ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Close )
{
    TgSINT_PTR                          iFile;

    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Valid ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Valid )
{
    TgCHAR_MB_C                         szAnsi_Test_0[] = u8"Test: Happy New Year!\nС новым годом!\n新年好！\n賀正！\n¡Feliz año nuevo!\nHyvää uutta vuotta!\n";
    TgSINT_PTR                          iFile;
    TgRSIZE                             nbyWrite;
    
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    nbyWrite = tgIO_File_Write( iFile, szAnsi_Test_0, sizeof szAnsi_Test_0 );
    Test__Expect_EQ(sizeof szAnsi_Test_0, nbyWrite);
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(true, tgIO_File_Valid( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Seek -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Seek )
{
    TgSINT_PTR                          iFile;
    TgSINT_MAX                          iPos;

    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));

    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__BEGIN, 0 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__BEGIN, -1 ));
    Test__Expect_EQ(1000, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__BEGIN, 1000 ));
    Test__Expect_EQ(99, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__BEGIN, 99 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__END, 0 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__END, -1 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__END, -99 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__END, -1000 ));
    Test__Expect_EQ(1, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__END, 1 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__BEGIN, 0 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__CURRENT, 0 ));
    Test__Expect_EQ(1000, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__CURRENT, 1000 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__BEGIN, 0 ));
    Test__Expect_EQ(99, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__CURRENT, 99 ));
    Test__Expect_EQ(98, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__CURRENT, -1 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__BEGIN, 0 ));
    Test__Expect_EQ(0, iPos = tgIO_File_Seek( iFile, ETgIO_SEEK__CURRENT, -1 ));

    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Size -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Size )
{
    TgCHAR_MB_C                         szAnsi_Test_0[] = u8"Test: Happy New Year!\nС новым годом!\n新年好！\n賀正！\n¡Feliz año nuevo!\nHyvää uutta vuotta!\n";
    TgSINT_PTR                          iFile;
    TgRSIZE                             nbyWrite;
    
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    nbyWrite = tgIO_File_Write( iFile, szAnsi_Test_0, sizeof szAnsi_Test_0 );
    Test__Expect_EQ(sizeof szAnsi_Test_0, nbyWrite);
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(true, tgIO_File_Valid( iFile ));
    Test__Expect_EQ(nbyWrite, tgIO_File_Size( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_Directory_Make --------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_Directory_Make )
{
    Test__Expect_EQ(false, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_Directory_Make( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(true, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_Directory_Remove( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_Directory_Remove ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_Directory_Remove )
{
    Test__Expect_EQ(false, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_Directory_Make( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(true, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_Directory_Remove( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_Directory_Exists ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_Directory_Exists )
{
    Test__Expect_EQ(false, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_Directory_Make( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(true, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_Directory_Remove( "unit.test.directory", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_Directory_Exists( "unit.test.directory", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Delete ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Delete )
{
    TgCHAR_MB_C                         szAnsi_Test_0[] = u8"Test: Happy New Year!\nС новым годом!\n新年好！\n賀正！\n¡Feliz año nuevo!\nHyvää uutta vuotta!\n";
    TgSINT_PTR                          iFile;
    TgRSIZE                             nbyWrite;
    
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    nbyWrite = tgIO_File_Write( iFile, szAnsi_Test_0, sizeof szAnsi_Test_0 );
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(true, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Copy -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Copy )
{
    TgCHAR_MB_C                         szAnsi_Test_0[] = u8"Test: Happy New Year!\nС новым годом!\n新年好！\n賀正！\n¡Feliz año nuevo!\nHyvää uutta vuotta!\n";
    TgSINT_PTR                          iFile;
    TgRSIZE                             nbyWrite;

    tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL );
    tgIO_File_Delete( "copy.test.file.txt", KTgMAX_SIZE_ALL );
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "copy.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    nbyWrite = tgIO_File_Write( iFile, szAnsi_Test_0, sizeof szAnsi_Test_0 );
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(true, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(false, tgIO_File_Exists( "copy.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Copy( "copy.test.file.txt", KTgMAX_SIZE_ALL, "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(true, tgIO_File_Exists( "copy.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "copy.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "copy.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Move -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Move )
{
    TgCHAR_MB_C                         szAnsi_Test_0[] = u8"Test: Happy New Year!\nС новым годом!\n新年好！\n賀正！\n¡Feliz año nuevo!\nHyvää uutta vuotta!\n";
    TgSINT_PTR                          iFile;
    TgRSIZE                             nbyWrite;

    tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL );
    tgIO_File_Delete( "move.test.file.txt", KTgMAX_SIZE_ALL );
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "move.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    nbyWrite = tgIO_File_Write( iFile, szAnsi_Test_0, sizeof szAnsi_Test_0 );
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(true, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(false, tgIO_File_Exists( "move.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Move( "move.test.file.txt", KTgMAX_SIZE_ALL, "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(true, tgIO_File_Exists( "move.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "move.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "move.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}


/* ---- UNIT_TEST__TEST__IO_File_Exists ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__IO_File_Exists )
{
    TgCHAR_MB_C                         szAnsi_Test_0[] = u8"Test: Happy New Year!\nС новым годом!\n新年好！\n賀正！\n¡Feliz año nuevo!\nHyvää uutta vuotta!\n";
    TgSINT_PTR                          iFile;
    TgRSIZE                             nbyWrite;
    
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_NE(nullptr, iFile = tgIO_File_Open( "unit.test.file.txt", KTgMAX_SIZE_ALL, ETgFILE_IO_ACCESS__WRITE ));
    nbyWrite = tgIO_File_Write( iFile, szAnsi_Test_0, sizeof szAnsi_Test_0 );
    Test__Expect_EQ(KTgS_OK, tgIO_File_Flush( iFile ));
    Test__Expect_EQ(KTgS_OK, tgIO_File_Close( iFile ));
    Test__Expect_EQ(true, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    Test__Expect_EQ(KTgS_OK, tgIO_File_Delete( "unit.test.file.txt", KTgMAX_SIZE_ALL ));
    Test__Expect_EQ(false, tgIO_File_Exists( "unit.test.file.txt", KTgMAX_SIZE_ALL ));

    TEST_END_METHOD( KTgS_OK );
}
