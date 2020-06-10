/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util.c
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
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgUTM_Check_C11_Lock_Free_Status ----------------------------------------------------------------------------------------------------------------------------------------- */
#define LOCK_FREE_TEST(A)  { A##_A TEST_VAR; TgERROR_MSG( atomic_is_lock_free(&TEST_VAR), #A " failed the lock free test." ); }
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgUTM_Check_C11_Lock_Free_Status( TgVOID )
{
    LOCK_FREE_TEST(TgSINT_E08);
    LOCK_FREE_TEST(TgSINT_E16);
    LOCK_FREE_TEST(TgSINT_E32);
    LOCK_FREE_TEST(TgSINT_E64);
    LOCK_FREE_TEST(TgSINT_F08);
    LOCK_FREE_TEST(TgSINT_F16);
    LOCK_FREE_TEST(TgSINT_F32);
    LOCK_FREE_TEST(TgSINT_F64);
    LOCK_FREE_TEST(TgSINT_PTR);
    LOCK_FREE_TEST(TgSINT_MAX);
    LOCK_FREE_TEST(TgSINT_PTR_DIFF);

    LOCK_FREE_TEST(TgUINT_E08);
    LOCK_FREE_TEST(TgUINT_E16);
    LOCK_FREE_TEST(TgUINT_E32);
    LOCK_FREE_TEST(TgUINT_E64);
    LOCK_FREE_TEST(TgUINT_F08);
    LOCK_FREE_TEST(TgUINT_F16);
    LOCK_FREE_TEST(TgUINT_F32);
    LOCK_FREE_TEST(TgUINT_F64);
    LOCK_FREE_TEST(TgUINT_PTR);
    LOCK_FREE_TEST(TgUINT_MAX);

    LOCK_FREE_TEST(TgRSIZE);
    LOCK_FREE_TEST(TgSIZE_ALL);
    LOCK_FREE_TEST(TgRSIZE);

    LOCK_FREE_TEST(TgCHAR_NC);
    LOCK_FREE_TEST(TgCHAR_WC);
    LOCK_FREE_TEST(TgCHAR_MB);
    LOCK_FREE_TEST(TgFLOAT32);
    LOCK_FREE_TEST(TgFLOAT64);
    LOCK_FREE_TEST(TgSINT_PTR);
    LOCK_FREE_TEST(TgUINT_PTR);
    LOCK_FREE_TEST(TgOSCHAR);
    LOCK_FREE_TEST(TgCHAR_NC);
    LOCK_FREE_TEST(TgCHAR_WC);
    LOCK_FREE_TEST(TgCHAR_MB);
    LOCK_FREE_TEST(TgSINT_E128);
    LOCK_FREE_TEST(TgUINT_E128);
    LOCK_FREE_TEST(TgBOOL);

    LOCK_FREE_TEST(STg2_UT_ST__PTR_TKT);
}

