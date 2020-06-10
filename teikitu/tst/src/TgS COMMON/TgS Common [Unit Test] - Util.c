/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] - Util.c
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

TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_Hash_Table );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_LA_Ring_Buffer_SRSW );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_Profile_Sample );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_Reader_Writer_Lock );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_Spin_Lock );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_MT_Stack );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_ST_Array );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_ST_Colour );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_ST_List );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_ST_Queue );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__UTIL_ST_String );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Unit Test Data                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

static Test_Set                             s_sSET__UTILITY;

static Test_Case                            s_sCASE__UTILITY;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgEXTN TgVOID                               tgCM_Unit_Test_Register_UTILITY(TgVOID);

/* ---- tgCM_Unit_Test_Register_UTILITY ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCM_Unit_Test_Register_UTILITY( TgVOID )
{
    /* Initialize the unit test structures */

    Unit_Test__Set_Init( &s_sSET__UTILITY );

    Unit_Test__Case_Init( &s_sCASE__UTILITY );



    /* Configure the test set */

    s_sSET__UTILITY.m_szSet = "Common: Utility";



    /* Configure the test cases */

    s_sCASE__UTILITY.m_pszSet = s_sSET__UTILITY.m_szSet;
    s_sCASE__UTILITY.m_pszCase = "Utility";

    s_sCASE__UTILITY.m_apszTest[0] = "MT Hash Table";
    s_sCASE__UTILITY.m_pfnTest[0] = UNIT_TEST__TEST__UTIL_MT_Hash_Table;
    s_sCASE__UTILITY.m_apszTest[1] = "MT LA Ring Buffer SRSW";
    s_sCASE__UTILITY.m_pfnTest[1] = UNIT_TEST__TEST__UTIL_MT_LA_Ring_Buffer_SRSW;
    s_sCASE__UTILITY.m_apszTest[2] = "MT Profile Sample";
    s_sCASE__UTILITY.m_pfnTest[2] = UNIT_TEST__TEST__UTIL_MT_Profile_Sample;
    s_sCASE__UTILITY.m_apszTest[3] = "MT Reader Writer Lock";
    s_sCASE__UTILITY.m_pfnTest[3] = UNIT_TEST__TEST__UTIL_MT_Reader_Writer_Lock;
    s_sCASE__UTILITY.m_apszTest[4] = "MT Spin Lock";
    s_sCASE__UTILITY.m_pfnTest[4] = UNIT_TEST__TEST__UTIL_MT_Spin_Lock;
    s_sCASE__UTILITY.m_apszTest[5] = "MT Stack";
    s_sCASE__UTILITY.m_pfnTest[5] = UNIT_TEST__TEST__UTIL_MT_Stack;
    s_sCASE__UTILITY.m_apszTest[6] = "ST Array";
    s_sCASE__UTILITY.m_pfnTest[6] = UNIT_TEST__TEST__UTIL_ST_Array;
    s_sCASE__UTILITY.m_apszTest[7] = "ST Colour";
    s_sCASE__UTILITY.m_pfnTest[7] = UNIT_TEST__TEST__UTIL_ST_Colour;
    s_sCASE__UTILITY.m_apszTest[8] = "ST List";
    s_sCASE__UTILITY.m_pfnTest[8] = UNIT_TEST__TEST__UTIL_ST_List;
    s_sCASE__UTILITY.m_apszTest[9] = "ST Queue";
    s_sCASE__UTILITY.m_pfnTest[9] = UNIT_TEST__TEST__UTIL_ST_Queue;
    s_sCASE__UTILITY.m_apszTest[10] = "ST String";
    s_sCASE__UTILITY.m_pfnTest[10] = UNIT_TEST__TEST__UTIL_ST_String;



    /* Register all of the test cases with the test set */

    Unit_Test__Set_Register_Case( &s_sSET__UTILITY, &s_sCASE__UTILITY );

    /* Register the test set with the unit test system */

    Unit_Test__Register( &s_sSET__UTILITY );
}
