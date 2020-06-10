/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] - Geometry.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include "TgS COMMON/TgS Common [Unit Test] - Unit Test.h"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Common [Unit Test] [Set] - Geometry.c_inc"


/* == Common ======================================================================================================================================================================*/

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.*/
/*  File Local Data */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.*/

static Test_Set                                             s_sSET__GEOM;

static Test_Case                                            s_sTEST__GEOM_F32_04_1;
static Test_Case                                            s_sTEST__GEOM_F64_04_1;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.*/
/*  File Local Macros */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.*/

#define SETUP_GEOM_TEST(A)                                                                                                                                                          \
    s_sTEST__GEOM_##A.m_pszSet = s_sSET__GEOM.m_szSet;                                                                                                                              \
    s_sTEST__GEOM_##A.m_pszCase = "Geom " #A;                                                                                                                                       \
    uiIndex = 0;                                                                                                                                                                    \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_RT2D_##A;                                                                                                          \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "RECTANGLE2D";                                                                                                                          \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_BA_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "BOXAA";                                                                                                                                \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_BX_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "BOX";                                                                                                                                  \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_CP_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "CAPSULE";                                                                                                                              \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_CI_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "CIRCLE";                                                                                                                               \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_CY_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "CYLINDER";                                                                                                                             \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_DK_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "DISK";                                                                                                                                 \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_EL_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "ELLIPSE";                                                                                                                              \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_LN_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "LINE";                                                                                                                                 \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_BA_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "MESH_BA";                                                                                                                              \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_MB_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "MESH_BVT";                                                                                                                             \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_MS_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "MESH_SIMPLE";                                                                                                                          \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_PE_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "PARALLELOGRAM";                                                                                                                        \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_PC_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "PARTICLE";                                                                                                                             \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_PN_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "PLANE";                                                                                                                                \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_RY_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "RAY";                                                                                                                                  \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_RT_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "RECTANGLE";                                                                                                                            \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_SG_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "SEGMENT";                                                                                                                              \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_SP_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "SPHERE";                                                                                                                               \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_TS_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "TORUS";                                                                                                                                \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_CT_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "CTRI";                                                                                                                                 \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_ET_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "ETRI";                                                                                                                                 \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_PT_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "PTRI";                                                                                                                                 \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_ST_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "STRI";                                                                                                                                 \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_TB_##A;                                                                                                            \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "TUBE";                                                                                                                                 \
    ++uiIndex;                                                                                                                                                                      \
    s_sTEST__GEOM_##A.m_pfnTest[uiIndex] = UNIT_TEST__TEST__GEOM_TYPE_##A;                                                                                                          \
    s_sTEST__GEOM_##A.m_apszTest[uiIndex] = "DELTA";                                                                                                                                \
    ++uiIndex;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */

TgEXTN TgVOID                               tgCM_Unit_Test_Register_GEOM(TgVOID);

TgVOID tgCM_Unit_Test_Register_GEOM( TgVOID )
{
    TgSINT_F32                          uiIndex;

    /* Initialize the unit test structures */

    Unit_Test__Set_Init( &s_sSET__GEOM );

    Unit_Test__Case_Init( &s_sTEST__GEOM_F32_04_1 );
    Unit_Test__Case_Init( &s_sTEST__GEOM_F64_04_1 );



    /* Configure the test set */

    s_sSET__GEOM.m_szSet = "Common: Geom";



    /* Configure the test cases */

    SETUP_GEOM_TEST(F32_04_1);
    SETUP_GEOM_TEST(F64_04_1);



    /* Register all of the test cases with the test set */

    Unit_Test__Set_Register_Case( &s_sSET__GEOM, &s_sTEST__GEOM_F32_04_1 );
    Unit_Test__Set_Register_Case( &s_sSET__GEOM, &s_sTEST__GEOM_F64_04_1 );



    /* Register the test set with the unit test system */

    Unit_Test__Register( &s_sSET__GEOM );
}
