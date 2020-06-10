/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] - Common.c
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

TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_Console );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_Event_MGR );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_Global );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_Job_MGR );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_Mem_MGR );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_Profile );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_String_MGR );
TEST_METHOD_DEFINE( UNIT_TEST__TEST__COMMON_SysInfo );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Unit Test Data                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

static Test_Set                             s_sSET__COMMON;

static Test_Case                            s_sCASE__COMMON;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgEXTN TgVOID                               tgCM_Unit_Test_Register_COMMON(TgVOID);

TgVOID tgCM_Unit_Test_Register_COMMON( TgVOID )
{
    /* Initialize the unit test structures */

    Unit_Test__Set_Init( &s_sSET__COMMON );
    
    Unit_Test__Case_Init( &s_sCASE__COMMON );



    /* Configure the test set */

    s_sSET__COMMON.m_szSet = "Common: Common";



    /* Register all of the test cases with the test set */

    s_sCASE__COMMON.m_pszSet = s_sSET__COMMON.m_szSet;
    s_sCASE__COMMON.m_pszCase = "Common";

    s_sCASE__COMMON.m_apszTest[0] = "Console";
    s_sCASE__COMMON.m_pfnTest[0] = UNIT_TEST__TEST__COMMON_Console;
    s_sCASE__COMMON.m_apszTest[1] = "Event MGR";
    s_sCASE__COMMON.m_pfnTest[1] = UNIT_TEST__TEST__COMMON_Event_MGR;
    s_sCASE__COMMON.m_apszTest[2] = "Global";
    s_sCASE__COMMON.m_pfnTest[2] = UNIT_TEST__TEST__COMMON_Global;
    s_sCASE__COMMON.m_apszTest[3] = "Job MGR";
    s_sCASE__COMMON.m_pfnTest[3] = UNIT_TEST__TEST__COMMON_Job_MGR;
    s_sCASE__COMMON.m_apszTest[4] = "Mem MGR";
    s_sCASE__COMMON.m_pfnTest[4] = UNIT_TEST__TEST__COMMON_Mem_MGR;
    s_sCASE__COMMON.m_apszTest[5] = "Profile";
    s_sCASE__COMMON.m_pfnTest[5] = UNIT_TEST__TEST__COMMON_Profile;
    s_sCASE__COMMON.m_apszTest[6] = "String MGR";
    s_sCASE__COMMON.m_pfnTest[6] = UNIT_TEST__TEST__COMMON_String_MGR;
    s_sCASE__COMMON.m_apszTest[7] = "SysInfo";
    s_sCASE__COMMON.m_pfnTest[7] = UNIT_TEST__TEST__COMMON_SysInfo;




    /* Register all of the test cases with the test set */

    Unit_Test__Set_Register_Case( &s_sSET__COMMON, &s_sCASE__COMMON );

    /* Register the test set with the unit test system */

    Unit_Test__Register( &s_sSET__COMMON );
}
