/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Event MGR.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_EVENT_MGR_INL)
#define TGS_COMMON_EVENT_MGR_INL
#pragma once


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Inline Functions */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgEM_TB_Set_Paused ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgEM_TB_Set_Paused( STg2_EM_TB_PCU psTB, TgBOOL_C bFlag )
{
    tgBF_Set_Flag_U32( &psTB->m_bfFlags, 0, bFlag );
}


/* ---- tgEM_TB_Set_Active ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgEM_TB_Set_Active( STg2_EM_TB_PCU psTB, TgBOOL_C bFlag )
{
    tgBF_Set_Flag_U32( &psTB->m_bfFlags, 1, bFlag );
}


/* ---- tgEM_TB_Is_Paused -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgBOOL tgEM_TB_Is_Paused( STg2_EM_TB_CPCU psTB )
{
    return (tgBF_Test_Flag_U32( &psTB->m_bfFlags, 0 ) );
}


/* ---- tgEM_TB_Is_Paused -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgBOOL tgEM_TB_Is_Active( STg2_EM_TB_CPCU psTB )
{
    return (tgBF_Test_Flag_U32( &psTB->m_bfFlags, 1 ) );
}


/* ---- tgEM_TE_FRM_Lock --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRESULT tgEM_TE_FRM_Lock( TgEM_TE_FRM_ID tiTE, TgUINT_F32_C uiPool, TgUINT_F32_C uiIndex )
{
    TgPARAM_CHECK(uiIndex < KTgEM_NUM_TE_IN_POOL);
    TgPARAM_CHECK(uiPool < KTgEM_MAX_TE_FRM_POOL);

    tgCM_UT_LF__SN__Lock_Spin( &g_asEM_TE_FRM_Data_Lock[uiPool].m_sLock );

    /* Time lines are only valid for the period for which they have a valid id */

    if ((nullptr == g_apsEM_TE_FRM[uiPool]) || (tiTE.m_uiKI !=  g_apsEM_TE_FRM[uiPool]->m_atiEM_TE_FRM_NoSingleton[uiIndex].m_uiKI ))
    {
        tgCM_UT_LF__SN__Signal( &g_asEM_TE_FRM_Data_Lock[uiPool].m_sLock );
        return (KTgE_FAIL);
    };

    return (KTgS_OK);
}


/* ---- tgEM_TE_SEC_Lock --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRESULT tgEM_TE_SEC_Lock( TgEM_TE_SEC_ID tiTE, TgUINT_F32_C uiPool, TgUINT_F32_C uiIndex )
{
    TgPARAM_CHECK(uiIndex < KTgEM_NUM_TE_IN_POOL);
    TgPARAM_CHECK(uiPool < KTgEM_MAX_TE_SEC_POOL);

    tgCM_UT_LF__SN__Lock_Spin( &g_asEM_TE_SEC_Data_Lock[uiPool].m_sLock );

    /* Time lines are only valid for the period for which they have a valid id */
    if ((nullptr == g_apsEM_TE_SEC[uiPool]) || (tiTE.m_uiKI !=  g_apsEM_TE_SEC[uiPool]->m_atiEM_TE_SEC_NoSingleton[uiIndex].m_uiKI ))
    {
        tgCM_UT_LF__SN__Signal( &g_asEM_TE_SEC_Data_Lock[uiPool].m_sLock );
        return (KTgE_FAIL);
    };

    return (KTgS_OK);
}


/* =============================================================================================================================================================================== */
#endif
