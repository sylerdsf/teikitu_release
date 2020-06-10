/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Case] - Base - API.c
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
/*  File Local Tests                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_S08 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_U08 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_S16 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_U16 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_S32 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_U32 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_S64 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_U64 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_SPTR );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_UPTR );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_SMAX );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_UMAX );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_F32 );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__BASE_API_MATH_F64 );

EXTN_METHOD_DECLARE( UNIT_TEST__TEST__Base_API_PM_Thread );

EXTN_METHOD_DECLARE( UNIT_TEST__TEST__Base_API );

EXTN_METHOD_DECLARE( UNIT_TEST__TEST__NCZ_Base_API_String );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__WCZ_Base_API_String );
EXTN_METHOD_DECLARE( UNIT_TEST__TEST__MBZ_Base_API_String );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Data                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

static Test_Case                            s_sTEST__Base_API_MATH;
static Test_Case                            s_sTEST__Base_API_PLATFORM;
static Test_Case                            s_sTEST__Base_API_STRING;
static Test_Case                            s_sTEST__Base_API;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCM_Unit_Test_Register_Base_API ----------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCM_Unit_Test_Register_Base_API( Test_Set * psSET__BASE )
{
    /* Initialize the unit test structures */

    Unit_Test__Case_Init( &s_sTEST__Base_API_MATH );
    Unit_Test__Case_Init( &s_sTEST__Base_API_PLATFORM );
    Unit_Test__Case_Init( &s_sTEST__Base_API_STRING );
    Unit_Test__Case_Init( &s_sTEST__Base_API );


    /* Configure the test cases */

    s_sTEST__Base_API_MATH.m_pszSet = psSET__BASE->m_szSet;
    s_sTEST__Base_API_MATH.m_pszCase = "Math API";

    s_sTEST__Base_API_MATH.m_apszTest[ 0] = "S08";
    s_sTEST__Base_API_MATH.m_pfnTest[  0] = UNIT_TEST__TEST__BASE_API_MATH_S08;
    s_sTEST__Base_API_MATH.m_apszTest[ 1] = "U08";
    s_sTEST__Base_API_MATH.m_pfnTest[  1] = UNIT_TEST__TEST__BASE_API_MATH_U08;
    s_sTEST__Base_API_MATH.m_apszTest[ 2] = "S16";
    s_sTEST__Base_API_MATH.m_pfnTest[  2] = UNIT_TEST__TEST__BASE_API_MATH_S16;
    s_sTEST__Base_API_MATH.m_apszTest[ 3] = "U16";
    s_sTEST__Base_API_MATH.m_pfnTest[  3] = UNIT_TEST__TEST__BASE_API_MATH_U16;
    s_sTEST__Base_API_MATH.m_apszTest[ 4] = "S32";
    s_sTEST__Base_API_MATH.m_pfnTest[  4] = UNIT_TEST__TEST__BASE_API_MATH_S32;
    s_sTEST__Base_API_MATH.m_apszTest[ 5] = "U32";
    s_sTEST__Base_API_MATH.m_pfnTest[  5] = UNIT_TEST__TEST__BASE_API_MATH_U32;
    s_sTEST__Base_API_MATH.m_apszTest[ 6] = "S64";
    s_sTEST__Base_API_MATH.m_pfnTest[  6] = UNIT_TEST__TEST__BASE_API_MATH_S64;
    s_sTEST__Base_API_MATH.m_apszTest[ 7] = "U64";
    s_sTEST__Base_API_MATH.m_pfnTest[  7] = UNIT_TEST__TEST__BASE_API_MATH_U64;
    s_sTEST__Base_API_MATH.m_apszTest[ 8] = "SPTR";
    s_sTEST__Base_API_MATH.m_pfnTest[  8] = UNIT_TEST__TEST__BASE_API_MATH_SPTR;
    s_sTEST__Base_API_MATH.m_apszTest[ 9] = "UPTR";
    s_sTEST__Base_API_MATH.m_pfnTest[  9] = UNIT_TEST__TEST__BASE_API_MATH_UPTR;
    s_sTEST__Base_API_MATH.m_apszTest[10] = "SMAX";
    s_sTEST__Base_API_MATH.m_pfnTest[ 10] = UNIT_TEST__TEST__BASE_API_MATH_SMAX;
    s_sTEST__Base_API_MATH.m_apszTest[11] = "UMAX";
    s_sTEST__Base_API_MATH.m_pfnTest[ 11] = UNIT_TEST__TEST__BASE_API_MATH_UMAX;
    s_sTEST__Base_API_MATH.m_apszTest[12] = "F32";
    s_sTEST__Base_API_MATH.m_pfnTest[ 12] = UNIT_TEST__TEST__BASE_API_MATH_F32;
    s_sTEST__Base_API_MATH.m_apszTest[13] = "F64";
    s_sTEST__Base_API_MATH.m_pfnTest[ 13] = UNIT_TEST__TEST__BASE_API_MATH_F64;

    s_sTEST__Base_API_PLATFORM.m_pszSet = psSET__BASE->m_szSet;
    s_sTEST__Base_API_PLATFORM.m_pszCase = "API";
    s_sTEST__Base_API_PLATFORM.m_apszTest[0] = "Platform: Thread";
    s_sTEST__Base_API_PLATFORM.m_pfnTest[0] = UNIT_TEST__TEST__Base_API_PM_Thread;

    s_sTEST__Base_API_STRING.m_pszSet = psSET__BASE->m_szSet;
    s_sTEST__Base_API_STRING.m_pszCase = "API";
    s_sTEST__Base_API_STRING.m_apszTest[0] = "Narrow Character Null-Terminated String";
    s_sTEST__Base_API_STRING.m_pfnTest[0] = UNIT_TEST__TEST__NCZ_Base_API_String;
    s_sTEST__Base_API_STRING.m_apszTest[1] = "Wide Character Null-Terminated String";
    s_sTEST__Base_API_STRING.m_pfnTest[1] = UNIT_TEST__TEST__WCZ_Base_API_String;
    s_sTEST__Base_API_STRING.m_apszTest[2] = "Multibyte Character Null-Terminated String";
    s_sTEST__Base_API_STRING.m_pfnTest[2] = UNIT_TEST__TEST__MBZ_Base_API_String;

    s_sTEST__Base_API.m_pszSet = psSET__BASE->m_szSet;
    s_sTEST__Base_API.m_pszCase = "API";
    s_sTEST__Base_API.m_apszTest[0] = "-";
    s_sTEST__Base_API.m_pfnTest[0] = UNIT_TEST__TEST__Base_API;

    /* Register all of the test cases with the test set */

    Unit_Test__Set_Register_Case( psSET__BASE, &s_sTEST__Base_API_MATH );
    Unit_Test__Set_Register_Case( psSET__BASE, &s_sTEST__Base_API_PLATFORM );
    Unit_Test__Set_Register_Case( psSET__BASE, &s_sTEST__Base_API_STRING );
    Unit_Test__Set_Register_Case( psSET__BASE, &s_sTEST__Base_API );
}
