/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Case] - Math API [Vector].c
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

TEST_LOCAL TgFLOAT32 tgMH_ERR_S_F32_02_1( TgVEC_S_F32_02_1_C v0 ) { return (tgCM_MAX_F32( 10.0F*tgMH_LEN_S_F32_02_1( v0 ), 1.0F )); }
TEST_LOCAL TgFLOAT32 tgMH_ERR_S_F32_03_1( TgVEC_S_F32_03_1_C v0 ) { return (tgCM_MAX_F32( 10.0F*tgMH_LEN_S_F32_03_1( v0 ), 1.0F )); }
TEST_LOCAL TgFLOAT32 tgMH_ERR_S_F32_04_1( TgVEC_S_F32_04_1_C v0 ) { return (tgCM_MAX_F32( 10.0F*tgMH_LEN_S_F32_04_1( v0 ), 1.0F )); }
TEST_LOCAL TgFLOAT64 tgMH_ERR_S_F64_02_1( TgVEC_S_F64_02_1_C v0 ) { return (tgCM_MAX_F64(  10.0*tgMH_LEN_S_F64_02_1( v0 ), 1.0 )); }
TEST_LOCAL TgFLOAT64 tgMH_ERR_S_F64_03_1( TgVEC_S_F64_03_1_C v0 ) { return (tgCM_MAX_F64(  10.0*tgMH_LEN_S_F64_03_1( v0 ), 1.0 )); }
TEST_LOCAL TgFLOAT64 tgMH_ERR_S_F64_04_1( TgVEC_S_F64_04_1_C v0 ) { return (tgCM_MAX_F64(  10.0*tgMH_LEN_S_F64_04_1( v0 ), 1.0 )); }


#define TEMPLATE__ENABLE_INTEGER

#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#define TEMPLATE__TYPE_SIZE 8
#define TEMPLATE__VECTOR_DIM 16
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"

#define TEMPLATE__TYPE_SIZE 16
#define TEMPLATE__VECTOR_DIM 8
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"

#define TEMPLATE__TYPE_SIZE 32
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"

#define TEMPLATE__TYPE_SIZE 8
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"

#define TEMPLATE__TYPE_SIZE 16
#define TEMPLATE__VECTOR_DIM 2
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"

#define TEMPLATE__TYPE_SIZE 64
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"

#undef TEMPLATE__ENABLE_INTEGER

#define TEMPLATE__VECTOR_DIM 2
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"

#define TEMPLATE__VECTOR_DIM 3
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc"




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Macros                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define SETUP_VEC_INT_TEST(A, B)                            s_sCASE__VEC.m_apszTest[ uiIndex] = "S" #A "_" #B;                                                                      \
                                                            s_sCASE__VEC.m_pfnTest[uiIndex++] = UNIT_TEST__TEST__MATH_VECTOR_S##A##_##B##_1;                                        \
                                                            s_sCASE__VEC.m_apszTest[ uiIndex] = "U" #A "_" #B;                                                                      \
                                                            s_sCASE__VEC.m_pfnTest[uiIndex++] = UNIT_TEST__TEST__MATH_VECTOR_U##A##_##B##_1

#define SETUP_VEC_FLT_TEST(A)                               s_sCASE__VEC.m_apszTest[ uiIndex] = "F32_" #A;                                                                          \
                                                            s_sCASE__VEC.m_pfnTest[uiIndex++] = UNIT_TEST__TEST__MATH_VECTOR_F32_##A##_1;                                           \
                                                            s_sCASE__VEC.m_apszTest[ uiIndex] = "F64_" #A;                                                                          \
                                                            s_sCASE__VEC.m_pfnTest[uiIndex++] = UNIT_TEST__TEST__MATH_VECTOR_F64_##A##_1




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Data                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

static Test_Case                                            s_sCASE__VEC;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCM_Unit_Test_Register_Math_Vector -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCM_Unit_Test_Register_Math_Vector( Test_Set * psSET__BASE )
{
    TgSINT_F32                          uiIndex;

    /* Initialize the unit test structures */

    Unit_Test__Case_Init( &s_sCASE__VEC );



    /* Configure the test set */

    s_sCASE__VEC.m_pszSet = psSET__BASE->m_szSet;
    s_sCASE__VEC.m_pszCase = "Vector";
    uiIndex = 0;

    SETUP_VEC_INT_TEST(08,16);
    SETUP_VEC_INT_TEST(16,08);
    SETUP_VEC_INT_TEST(32,04);
    SETUP_VEC_INT_TEST(08,04);
    SETUP_VEC_INT_TEST(16,02);
    SETUP_VEC_INT_TEST(64,04);

    SETUP_VEC_FLT_TEST(02);
    SETUP_VEC_FLT_TEST(03);
    SETUP_VEC_FLT_TEST(04);

    TgCRITICAL(uiIndex < KTgNUM_TEST_PER_CASE);



    /* Register all of the test cases with the test set */

    Unit_Test__Set_Register_Case( psSET__BASE, &s_sCASE__VEC );
}
