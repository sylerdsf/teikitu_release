/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util MT - LA Ring Buffer SRSW.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UTIL_MT_LA_RING_BUFFER_SRSW_INL)
#define TGS_COMMON_UTIL_MT_LA_RING_BUFFER_SRSW_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCM_UT_LF__LA_RB_SRSW__Init --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgCM_UT_LF__LA_RB_SRSW__Init( STg2_UT_LF__LA_RB_SRSW_PCU NONULL psLA_RB_SRSW, TgRSIZE_C uiMaxSize )
{
    atomic_store( &psLA_RB_SRSW->m_nuiPushed, 0 );
    atomic_store( &psLA_RB_SRSW->m_nuiPopped, 0 );
    psLA_RB_SRSW->m_uiMaxSize = uiMaxSize;
}


/* ---- tgCM_UT_LF__LA_RB_SRSW__Query_Used_Size ---------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRSIZE tgCM_UT_LF__LA_RB_SRSW__Query_Used_Size( STg2_UT_LF__LA_RB_SRSW_PCU NONULL psLA_RB_SRSW )
{
    return (atomic_load( &psLA_RB_SRSW->m_nuiPushed ) - atomic_load( &psLA_RB_SRSW->m_nuiPopped ));
}


/* ---- tgCM_UT_LF__LA_RB_SRSW__Query_Free_Size ---------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRSIZE tgCM_UT_LF__LA_RB_SRSW__Query_Free_Size( STg2_UT_LF__LA_RB_SRSW_PCU NONULL psLA_RB_SRSW )
{
    return (tgCM_UT_LF__LA_RB_SRSW__Query_Max_Size( psLA_RB_SRSW ) - tgCM_UT_LF__LA_RB_SRSW__Query_Used_Size( psLA_RB_SRSW ));
}


/* ---- tgCM_UT_LF__LA_RB_SRSW__Query_Max_Size ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRSIZE tgCM_UT_LF__LA_RB_SRSW__Query_Max_Size( STg2_UT_LF__LA_RB_SRSW_PCU NONULL psLA_RB_SRSW )
{
    return ((TgUINT_F32)psLA_RB_SRSW->m_uiMaxSize);
}


/* ---- tgCM_UT_LF__LA_RB_SRSW__Push_Next_Index ---------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRSIZE tgCM_UT_LF__LA_RB_SRSW__Push_Next_Index( STg2_UT_LF__LA_RB_SRSW_PCU NONULL psLA_RB_SRSW )
{
    return (atomic_load( &psLA_RB_SRSW->m_nuiPushed ) % tgCM_UT_LF__LA_RB_SRSW__Query_Max_Size( psLA_RB_SRSW ));
}


/* ---- tgCM_UT_LF__LA_RB_SRSW__Push_Commit -------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgCM_UT_LF__LA_RB_SRSW__Push_Commit( STg2_UT_LF__LA_RB_SRSW_PCU NONULL psLA_RB_SRSW )
{
    atomic_thread_fence( memory_order_seq_cst );
    atomic_fetch_add( &psLA_RB_SRSW->m_nuiPushed, 1 );
}


/* ---- tgCM_UT_LF__LA_RB_SRSW__Pop_Next_Index ----------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRSIZE tgCM_UT_LF__LA_RB_SRSW__Pop_Next_Index( STg2_UT_LF__LA_RB_SRSW_PCU NONULL psLA_RB_SRSW )
{
    return (atomic_load( &psLA_RB_SRSW->m_nuiPopped ) % tgCM_UT_LF__LA_RB_SRSW__Query_Max_Size( psLA_RB_SRSW ) );
}


/* ---- tgCM_UT_LF__LA_RB_SRSW__Pop_Commit --------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgCM_UT_LF__LA_RB_SRSW__Pop_Commit( STg2_UT_LF__LA_RB_SRSW_PCU NONULL psLA_RB_SRSW )
{
    atomic_thread_fence( memory_order_seq_cst );
    atomic_fetch_add( &psLA_RB_SRSW->m_nuiPopped, 1 );
}


/* =============================================================================================================================================================================== */
#endif
