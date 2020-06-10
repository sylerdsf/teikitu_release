/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Set] - Math.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <math.h>

#include "TgS Common [Unit Test] [Test] - Math [Constants].c_inc"
#include "TgS Common [Unit Test] [Test] - Math [Scalar] [F].c_inc"


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Data                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

static Test_Set                             s_sSET__MATH;
static Test_Case                            s_sCASE__Math_Constant;
static Test_Case                            s_sCASE__Math;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCM_Unit_Test_Register_MATH --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCM_Unit_Test_Register_MATH( TgVOID )
{
    /* Initialize the unit test structures */

    Unit_Test__Set_Init( &s_sSET__MATH );

    Unit_Test__Case_Init( &s_sCASE__Math_Constant );
    Unit_Test__Case_Init( &s_sCASE__Math );



    /* Configure the test set */

    s_sSET__MATH.m_szSet = "Common: Math";



    /* Configure the test cases */

    s_sCASE__Math_Constant.m_pszSet = s_sSET__MATH.m_szSet;
    s_sCASE__Math_Constant.m_pszCase = "Math Constant";
    s_sCASE__Math_Constant.m_pfnTest[0] = UNIT_TEST__TEST__Math_Constant;
    s_sCASE__Math_Constant.m_apszTest[0] = "UNIT_TEST__TEST__Math_Constant";

    s_sCASE__Math.m_pszSet = s_sSET__MATH.m_szSet;
    s_sCASE__Math.m_pszCase = "Math Utility";
    s_sCASE__Math.m_pfnTest[0] = UNIT_TEST__TEST__MATH_Vector_F_Algorithm_F32;
    s_sCASE__Math.m_apszTest[0] = "Algorithm 32";
    s_sCASE__Math.m_pfnTest[1] = UNIT_TEST__TEST__MATH_Vector_F_Polynomial_F32;
    s_sCASE__Math.m_apszTest[1] = "Polynomial 32";
    s_sCASE__Math.m_pfnTest[3] = UNIT_TEST__TEST__MATH_Vector_F_Algorithm_F64;
    s_sCASE__Math.m_apszTest[3] = "Algorithm 64";
    s_sCASE__Math.m_pfnTest[4] = UNIT_TEST__TEST__MATH_Vector_F_Polynomial_F64;
    s_sCASE__Math.m_apszTest[4] = "Polynomial 64";



    /* Register all of the test cases with the test set */

    Unit_Test__Set_Register_Case( &s_sSET__MATH, &s_sCASE__Math_Constant );
    Unit_Test__Set_Register_Case( &s_sSET__MATH, &s_sCASE__Math );
    tgCM_Unit_Test_Register_Math_Vector( &s_sSET__MATH );
    tgCM_Unit_Test_Register_Math_Matrix( &s_sSET__MATH );



    /* Register the test set with the unit test system */

    Unit_Test__Register( &s_sSET__MATH );
}
