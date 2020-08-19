/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Base - Type [Constants].c
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
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__Base_Type_Constants ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__Base_Type_Constants )
{
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_R_F32(KTg_BLACK_709_F32_04));
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_G_F32(KTg_BLACK_709_F32_04));
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_B_F32(KTg_BLACK_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_A_F32(KTg_BLACK_709_F32_04));

    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_R_F32(KTg_WHITE_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_G_F32(KTg_WHITE_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_B_F32(KTg_WHITE_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_A_F32(KTg_WHITE_709_F32_04));

    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_R_F32(KTg_RED_709_F32_04));
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_G_F32(KTg_RED_709_F32_04));
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_B_F32(KTg_RED_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_A_F32(KTg_RED_709_F32_04));

    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_R_F32(KTg_GREEN_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_G_F32(KTg_GREEN_709_F32_04));
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_B_F32(KTg_GREEN_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_A_F32(KTg_GREEN_709_F32_04));

    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_R_F32(KTg_BLUE_709_F32_04));
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_G_F32(KTg_BLUE_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_B_F32(KTg_BLUE_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_A_F32(KTg_BLUE_709_F32_04));

    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_R_F32(KTg_YELLOW_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_G_F32(KTg_YELLOW_709_F32_04));
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_B_F32(KTg_YELLOW_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_A_F32(KTg_YELLOW_709_F32_04));

    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_R_F32(KTg_MAGENTA_709_F32_04));
    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_G_F32(KTg_MAGENTA_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_B_F32(KTg_MAGENTA_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_A_F32(KTg_MAGENTA_709_F32_04));

    Test__Expect_EQ(0.0F, tgCM_CL_F32_Query_R_F32(KTg_CYAN_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_G_F32(KTg_CYAN_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_B_F32(KTg_CYAN_709_F32_04));
    Test__Expect_EQ(1.0F, tgCM_CL_F32_Query_A_F32(KTg_CYAN_709_F32_04));


    Test__Expect_EQ(0x00u, KTg_BLACK_709_U32.m_uiRed);
    Test__Expect_EQ(0x00u, KTg_BLACK_709_U32.m_uiGreen);
    Test__Expect_EQ(0x00u, KTg_BLACK_709_U32.m_uiBlue);
    Test__Expect_EQ(0xFFu, KTg_BLACK_709_U32.m_uiAlpha);

    Test__Expect_EQ(0xFFu, KTg_WHITE_709_U32.m_uiRed);
    Test__Expect_EQ(0xFFu, KTg_WHITE_709_U32.m_uiGreen);
    Test__Expect_EQ(0xFFu, KTg_WHITE_709_U32.m_uiBlue);
    Test__Expect_EQ(0xFFu, KTg_WHITE_709_U32.m_uiAlpha);

    Test__Expect_EQ(0xFFu, KTg_RED_709_U32.m_uiRed);
    Test__Expect_EQ(0x00u, KTg_RED_709_U32.m_uiGreen);
    Test__Expect_EQ(0x00u, KTg_RED_709_U32.m_uiBlue);
    Test__Expect_EQ(0xFFu, KTg_RED_709_U32.m_uiAlpha);

    Test__Expect_EQ(0x00u, KTg_GREEN_709_U32.m_uiRed);
    Test__Expect_EQ(0xFFu, KTg_GREEN_709_U32.m_uiGreen);
    Test__Expect_EQ(0x00u, KTg_GREEN_709_U32.m_uiBlue);
    Test__Expect_EQ(0xFFu, KTg_GREEN_709_U32.m_uiAlpha);

    Test__Expect_EQ(0x00u, KTg_BLUE_709_U32.m_uiRed);
    Test__Expect_EQ(0x00u, KTg_BLUE_709_U32.m_uiGreen);
    Test__Expect_EQ(0xFFu, KTg_BLUE_709_U32.m_uiBlue);
    Test__Expect_EQ(0xFFu, KTg_BLUE_709_U32.m_uiAlpha);

    Test__Expect_EQ(0xFFu, KTg_YELLOW_709_U32.m_uiRed);
    Test__Expect_EQ(0xFFu, KTg_YELLOW_709_U32.m_uiGreen);
    Test__Expect_EQ(0x00u, KTg_YELLOW_709_U32.m_uiBlue);
    Test__Expect_EQ(0xFFu, KTg_YELLOW_709_U32.m_uiAlpha);

    Test__Expect_EQ(0xFFu, KTg_MAGENTA_709_U32.m_uiRed);
    Test__Expect_EQ(0x00u, KTg_MAGENTA_709_U32.m_uiGreen);
    Test__Expect_EQ(0xFFu, KTg_MAGENTA_709_U32.m_uiBlue);
    Test__Expect_EQ(0xFFu, KTg_MAGENTA_709_U32.m_uiAlpha);

    Test__Expect_EQ(0x00u, KTg_CYAN_709_U32.m_uiRed);
    Test__Expect_EQ(0xFFu, KTg_CYAN_709_U32.m_uiGreen);
    Test__Expect_EQ(0xFFu, KTg_CYAN_709_U32.m_uiBlue);
    Test__Expect_EQ(0xFFu, KTg_CYAN_709_U32.m_uiAlpha);

    TEST_END_METHOD( KTgS_OK );
}
