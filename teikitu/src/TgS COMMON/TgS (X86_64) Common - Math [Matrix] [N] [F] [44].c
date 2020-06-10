/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (X86_64) Common - Math [Matrix] [N] [F] [44].c
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
#if defined(TGS_COMMON_MATH_API_MATRIX_SPECIALIZATION_INL)

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgMH_CAT_N_F32_04_4_IMPL ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgMH_CAT_N_F32_04_4_IMPL( TgVEC_N_F32_04_4_PCU ptmRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    const __m128                        mi00 = _mm_shuffle_ps( pxM0->m_avRow[0], pxM0->m_avRow[0], 0x00 );
    const __m128                        mi01 = _mm_shuffle_ps( pxM0->m_avRow[0], pxM0->m_avRow[0], 0x55 );
    const __m128                        mi02 = _mm_shuffle_ps( pxM0->m_avRow[0], pxM0->m_avRow[0], 0xAA );
    const __m128                        mi03 = _mm_shuffle_ps( pxM0->m_avRow[0], pxM0->m_avRow[0], 0xFF );
    const __m128                        mi04 = _mm_shuffle_ps( pxM0->m_avRow[1], pxM0->m_avRow[1], 0x00 );
    const __m128                        mi05 = _mm_shuffle_ps( pxM0->m_avRow[1], pxM0->m_avRow[1], 0x55 );
    const __m128                        mi06 = _mm_shuffle_ps( pxM0->m_avRow[1], pxM0->m_avRow[1], 0xAA );
    const __m128                        mi07 = _mm_shuffle_ps( pxM0->m_avRow[1], pxM0->m_avRow[1], 0xFF );
    const __m128                        mi08 = _mm_shuffle_ps( pxM0->m_avRow[2], pxM0->m_avRow[2], 0x00 );
    const __m128                        mi09 = _mm_shuffle_ps( pxM0->m_avRow[2], pxM0->m_avRow[2], 0x55 );
    const __m128                        mi10 = _mm_shuffle_ps( pxM0->m_avRow[2], pxM0->m_avRow[2], 0xAA );
    const __m128                        mi11 = _mm_shuffle_ps( pxM0->m_avRow[2], pxM0->m_avRow[2], 0xFF );
    const __m128                        mi12 = _mm_shuffle_ps( pxM0->m_avRow[3], pxM0->m_avRow[3], 0x00 );
    const __m128                        mi13 = _mm_shuffle_ps( pxM0->m_avRow[3], pxM0->m_avRow[3], 0x55 );
    const __m128                        mi14 = _mm_shuffle_ps( pxM0->m_avRow[3], pxM0->m_avRow[3], 0xAA );
    const __m128                        mi15 = _mm_shuffle_ps( pxM0->m_avRow[3], pxM0->m_avRow[3], 0xFF );

    const __m128                        mi16 = _mm_mul_ps( mi00, pxM1->m_avRow[0] );
    const __m128                        mi17 = _mm_mul_ps( mi04, pxM1->m_avRow[0] );
    const __m128                        mi18 = _mm_mul_ps( mi08, pxM1->m_avRow[0] );
    const __m128                        mi19 = _mm_mul_ps( mi12, pxM1->m_avRow[0] );
    const __m128                        mi20 = _mm_mul_ps( mi01, pxM1->m_avRow[1] );
    const __m128                        mi21 = _mm_mul_ps( mi05, pxM1->m_avRow[1] );
    const __m128                        mi22 = _mm_mul_ps( mi09, pxM1->m_avRow[1] );
    const __m128                        mi23 = _mm_mul_ps( mi13, pxM1->m_avRow[1] );
    const __m128                        mi24 = _mm_mul_ps( mi02, pxM1->m_avRow[2] );
    const __m128                        mi25 = _mm_mul_ps( mi06, pxM1->m_avRow[2] );
    const __m128                        mi26 = _mm_mul_ps( mi10, pxM1->m_avRow[2] );
    const __m128                        mi27 = _mm_mul_ps( mi14, pxM1->m_avRow[2] );
    const __m128                        mi28 = _mm_mul_ps( mi03, pxM1->m_avRow[3] );
    const __m128                        mi29 = _mm_mul_ps( mi07, pxM1->m_avRow[3] );
    const __m128                        mi30 = _mm_mul_ps( mi11, pxM1->m_avRow[3] );
    const __m128                        mi31 = _mm_mul_ps( mi15, pxM1->m_avRow[3] );

    ptmRet->m_avRow[0] = _mm_add_ps( _mm_add_ps( mi16, mi20 ), _mm_add_ps( mi24, mi28 ) );
    ptmRet->m_avRow[1] = _mm_add_ps( _mm_add_ps( mi17, mi21 ), _mm_add_ps( mi25, mi29 ) );
    ptmRet->m_avRow[2] = _mm_add_ps( _mm_add_ps( mi18, mi22 ), _mm_add_ps( mi26, mi30 ) );
    ptmRet->m_avRow[3] = _mm_add_ps( _mm_add_ps( mi19, mi23 ), _mm_add_ps( mi27, mi31 ) );
}


/* ---- tgMH_INV_DET_N_F32_04_4_IMPL -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgMH_INV_DET_N_F32_04_4_IMPL( TgVEC_N_F32_04_4_PCU ptmRet, TgVEC_N_F32_04_1_C vDet, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    /*  Construct the four corner matrices of the 4x4.  Note: this is probably an inefficient method to take the inverse of a standard linear transform matrix since it
    cant take into account the known information of the row or column of zeros that normally exists in the matrix.  However, since inverse operations should not be
    terribly time sensitive this may not be a problem. */

    const __m128                        miR0 = pxM1->m_avRow[0];
    const __m128                        miR1 = pxM1->m_avRow[1];
    const __m128                        miR2 = pxM1->m_avRow[2];
    const __m128                        miR3 = pxM1->m_avRow[3];

    const __m128                        mi01 = _mm_shuffle_ps( miR0, miR1, MM_PERM( 0, 1, 0, 1 ) ); /* 00, 01, 10, 11 */
    const __m128                        mi02 = _mm_shuffle_ps( miR0, miR1, MM_PERM( 2, 3, 2, 3 ) ); /* 02, 03, 12, 13 */
    const __m128                        mi03 = _mm_shuffle_ps( miR2, miR3, MM_PERM( 0, 1, 0, 1 ) ); /* 20, 21, 30, 31 */
    const __m128                        mi04 = _mm_shuffle_ps( miR2, miR3, MM_PERM( 2, 3, 2, 3 ) ); /* 22, 23, 32, 33 */

    const __m128                        mi05 = _mm_shuffle_ps( miR0, miR1, MM_PERM( 0, 1, 2, 3 ) ); /* 00, 01, 12, 13 */
    const __m128                        mi06 = _mm_shuffle_ps( miR1, miR0, MM_PERM( 0, 1, 2, 3 ) ); /* 10, 11, 02, 03 */
    const __m128                        mi07 = _mm_shuffle_ps( miR2, miR3, MM_PERM( 0, 1, 2, 3 ) ); /* 20, 21, 32, 33 */
    const __m128                        mi08 = _mm_shuffle_ps( miR3, miR2, MM_PERM( 0, 1, 2, 3 ) ); /* 30, 31, 22, 23 */

    const __m128                        miC0 = _mm_shuffle_ps( mi01, mi03, MM_PERM( 0, 2, 0, 2 ) ); /* 00, 10, 20, 30 */
    const __m128                        miC1 = _mm_shuffle_ps( mi01, mi03, MM_PERM( 1, 3, 1, 3 ) ); /* 01, 11, 21, 31 */

    const __m128                        mi011 = _mm_shuffle_ps( miC1, miC1, MM_PERM( 1, 0, 0, 0 ) ); /* 11 01 01 01 */
    const __m128                        mi013 = _mm_shuffle_ps( miR3, mi04, MM_PERM( 3, 2, 3, 0 ) ); /* 33 32 33 22 */
    const __m128                        mi015 = _mm_shuffle_ps( miR3, mi04, MM_PERM( 2, 3, 2, 1 ) ); /* 32 33 32 23 */
    const __m128                        mi012 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 2, 3, 2, 3 ) ); /* 22 23 12 13 */
    const __m128                        mi014 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 3, 2, 3, 2 ) ); /* 23 22 13 12 */
    const __m128                        mi016 = _mm_mul_ps( mi012, mi013 );
    const __m128                        mi017 = _mm_mul_ps( mi014, mi015 );
    const __m128                        mi018 = _mm_sub_ps( mi016, mi017 );
    const __m128                        mi019 = _mm_mul_ps( mi011, mi018 );
    const __m128                        mi020 = _mm_div_ps( mi019, vDet );
    const __m128                        mi021 = _mm_shuffle_ps( miC1, miC1, MM_PERM( 2, 2, 1, 1 ) ); /* 21 21 11 11 */
    const __m128                        mi023 = _mm_shuffle_ps( miR3, mi04, MM_PERM( 2, 3, 2, 1 ) ); /* 32 33 32 23 */
    const __m128                        mi025 = _mm_shuffle_ps( miR3, mi04, MM_PERM( 3, 2, 3, 0 ) ); /* 33 32 33 22 */
    const __m128                        mi022 = _mm_shuffle_ps( mi02, miR0, MM_PERM( 3, 0, 3, 2 ) ); /* 13 02 03 02 */
    const __m128                        mi024 = _mm_shuffle_ps( mi02, miR0, MM_PERM( 2, 1, 2, 3 ) ); /* 12 03 02 03 */
    const __m128                        mi026 = _mm_mul_ps( mi022, mi023 );
    const __m128                        mi027 = _mm_mul_ps( mi024, mi025 );
    const __m128                        mi028 = _mm_sub_ps( mi026, mi027 );
    const __m128                        mi029 = _mm_mul_ps( mi021, mi028 );
    const __m128                        mi030 = _mm_div_ps( mi029, vDet );
    const __m128                        mi031 = _mm_shuffle_ps( miC1, miC1, MM_PERM( 3, 3, 3, 2 ) ); /* 31 31 31 21 */
    const __m128                        mi032 = _mm_shuffle_ps( mi02, miR0, MM_PERM( 2, 1, 2, 3 ) ); /* 12 03 02 03 */
    const __m128                        mi034 = _mm_shuffle_ps( mi02, miR0, MM_PERM( 3, 0, 3, 2 ) ); /* 13 02 03 02 */
    const __m128                        mi033 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 3, 2, 3, 2 ) ); /* 23 22 13 12 */
    const __m128                        mi035 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 2, 3, 2, 3 ) ); /* 22 23 12 13 */
    const __m128                        mi036 = _mm_mul_ps( mi032, mi033 );
    const __m128                        mi037 = _mm_mul_ps( mi034, mi035 );
    const __m128                        mi038 = _mm_sub_ps( mi036, mi037 );
    const __m128                        mi039 = _mm_mul_ps( mi031, mi038 );
    const __m128                        mi040 = _mm_div_ps( mi039, vDet );

    const __m128                        mi041 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 1, 0, 0, 0 ) ); /* 10 00 00 00 */
    const __m128                        mi043 = _mm_shuffle_ps( miR3, mi04, MM_PERM( 2, 3, 2, 1 ) ); /* 32 33 32 23 */
    const __m128                        mi045 = _mm_shuffle_ps( miR3, mi04, MM_PERM( 3, 2, 3, 0 ) ); /* 33 32 33 22 */
    const __m128                        mi042 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 3, 2, 3, 2 ) ); /* 23 22 13 12 */
    const __m128                        mi044 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 2, 3, 2, 3 ) ); /* 22 23 12 13 */
    const __m128                        mi046 = _mm_mul_ps( mi042, mi043 );
    const __m128                        mi047 = _mm_mul_ps( mi044, mi045 );
    const __m128                        mi048 = _mm_sub_ps( mi046, mi047 );
    const __m128                        mi049 = _mm_mul_ps( mi041, mi048 );
    const __m128                        mi050 = _mm_div_ps( mi049, vDet );
    const __m128                        mi051 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 2, 2, 1, 1 ) ); /* 20 20 10 10 */
    const __m128                        mi053 = _mm_shuffle_ps( miR3, mi04, MM_PERM( 3, 2, 3, 0 ) ); /* 33 32 33 22 */
    const __m128                        mi055 = _mm_shuffle_ps( miR3, mi04, MM_PERM( 2, 3, 2, 1 ) ); /* 32 33 32 23 */
    const __m128                        mi052 = _mm_shuffle_ps( mi02, miR0, MM_PERM( 2, 1, 2, 3 ) ); /* 12 03 02 03 */
    const __m128                        mi054 = _mm_shuffle_ps( mi02, miR0, MM_PERM( 3, 0, 3, 2 ) ); /* 13 02 03 02 */
    const __m128                        mi056 = _mm_mul_ps( mi052, mi053 );
    const __m128                        mi057 = _mm_mul_ps( mi054, mi055 );
    const __m128                        mi058 = _mm_sub_ps( mi056, mi057 );
    const __m128                        mi059 = _mm_mul_ps( mi051, mi058 );
    const __m128                        mi060 = _mm_div_ps( mi059, vDet );
    const __m128                        mi061 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 3, 3, 3, 2 ) ); /* 30 30 30 20 */
    const __m128                        mi063 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 2, 3, 2, 3 ) ); /* 22 23 12 13 */
    const __m128                        mi065 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 3, 2, 3, 2 ) ); /* 23 22 13 12 */
    const __m128                        mi062 = _mm_shuffle_ps( mi02, miR0, MM_PERM( 3, 0, 3, 2 ) ); /* 13 02 03 02 */
    const __m128                        mi064 = _mm_shuffle_ps( mi02, miR0, MM_PERM( 2, 1, 2, 3 ) ); /* 12 03 02 03 */
    const __m128                        mi066 = _mm_mul_ps( mi062, mi063 );
    const __m128                        mi067 = _mm_mul_ps( mi064, mi065 );
    const __m128                        mi068 = _mm_sub_ps( mi066, mi067 );
    const __m128                        mi069 = _mm_mul_ps( mi061, mi068 );
    const __m128                        mi070 = _mm_div_ps( mi069, vDet );

    const __m128                        mi071 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 1, 0, 0, 0 ) ); /* 10 00 00 00 */
    const __m128                        mi073 = _mm_shuffle_ps( miR3, mi07, MM_PERM( 3, 1, 3, 1 ) ); /* 33 31 33 21 */
    const __m128                        mi075 = _mm_shuffle_ps( miR3, mi08, MM_PERM( 1, 3, 1, 3 ) ); /* 31 33 31 23 */
    const __m128                        mi072 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 1, 3, 1, 3 ) ); /* 21 23 11 13 */
    const __m128                        mi074 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 3, 1, 3, 1 ) ); /* 23 21 13 11 */
    const __m128                        mi076 = _mm_mul_ps( mi072, mi073 );
    const __m128                        mi077 = _mm_mul_ps( mi074, mi075 );
    const __m128                        mi078 = _mm_sub_ps( mi076, mi077 );
    const __m128                        mi079 = _mm_mul_ps( mi071, mi078 );
    const __m128                        mi080 = _mm_div_ps( mi079, vDet );
    const __m128                        mi081 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 2, 2, 1, 1 ) ); /* 20 20 10 10 */
    const __m128                        mi083 = _mm_shuffle_ps( miR3, mi08, MM_PERM( 1, 3, 1, 3 ) ); /* 31 33 31 23 */
    const __m128                        mi085 = _mm_shuffle_ps( miR3, mi07, MM_PERM( 3, 1, 3, 1 ) ); /* 33 31 33 21 */
    const __m128                        mi082 = _mm_shuffle_ps( mi05, miR0, MM_PERM( 3, 1, 3, 1 ) ); /* 13 01 03 01 */
    const __m128                        mi084 = _mm_shuffle_ps( mi06, miR0, MM_PERM( 1, 3, 1, 3 ) ); /* 11 03 01 03 */
    const __m128                        mi086 = _mm_mul_ps( mi082, mi083 );
    const __m128                        mi087 = _mm_mul_ps( mi084, mi085 );
    const __m128                        mi088 = _mm_sub_ps( mi086, mi087 );
    const __m128                        mi089 = _mm_mul_ps( mi081, mi088 );
    const __m128                        mi090 = _mm_div_ps( mi089, vDet );
    const __m128                        mi091 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 3, 3, 3, 2 ) ); /* 30 30 30 20 */
    const __m128                        mi093 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 3, 1, 3, 1 ) ); /* 23 21 13 11 */
    const __m128                        mi095 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 1, 3, 1, 3 ) ); /* 21 23 11 13 */
    const __m128                        mi092 = _mm_shuffle_ps( mi06, miR0, MM_PERM( 1, 3, 1, 3 ) ); /* 11 03 01 03 */
    const __m128                        mi094 = _mm_shuffle_ps( mi05, miR0, MM_PERM( 3, 1, 3, 1 ) ); /* 13 01 03 01 */
    const __m128                        mi096 = _mm_mul_ps( mi092, mi093 );
    const __m128                        mi097 = _mm_mul_ps( mi094, mi095 );
    const __m128                        mi098 = _mm_sub_ps( mi096, mi097 );
    const __m128                        mi099 = _mm_mul_ps( mi091, mi098 );
    const __m128                        mi100 = _mm_div_ps( mi099, vDet );

    const __m128                        mi101 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 1, 0, 0, 0 ) ); /* 10 00 00 00 */
    const __m128                        mi103 = _mm_shuffle_ps( miR3, mi08, MM_PERM( 1, 2, 1, 2 ) ); /* 31 32 31 22 */
    const __m128                        mi105 = _mm_shuffle_ps( miR3, mi07, MM_PERM( 2, 1, 2, 1 ) ); /* 32 31 32 21 */
    const __m128                        mi102 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 2, 1, 2, 1 ) ); /* 22 21 12 11 */
    const __m128                        mi104 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 1, 2, 1, 2 ) ); /* 21 22 11 12 */
    const __m128                        mi106 = _mm_mul_ps( mi102, mi103 );
    const __m128                        mi107 = _mm_mul_ps( mi104, mi105 );
    const __m128                        mi108 = _mm_sub_ps( mi106, mi107 );
    const __m128                        mi109 = _mm_mul_ps( mi101, mi108 );
    const __m128                        mi110 = _mm_div_ps( mi109, vDet );
    const __m128                        mi111 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 2, 2, 1, 1 ) ); /* 20 20 10 10 */
    const __m128                        mi113 = _mm_shuffle_ps( miR3, mi07, MM_PERM( 2, 1, 2, 1 ) ); /* 32 31 32 21 */
    const __m128                        mi115 = _mm_shuffle_ps( miR3, mi08, MM_PERM( 1, 2, 1, 2 ) ); /* 31 32 31 22 */
    const __m128                        mi112 = _mm_shuffle_ps( mi06, miR0, MM_PERM( 1, 2, 1, 2 ) ); /* 11 02 01 02 */
    const __m128                        mi114 = _mm_shuffle_ps( mi05, miR0, MM_PERM( 2, 1, 2, 1 ) ); /* 12 01 02 01 */
    const __m128                        mi116 = _mm_mul_ps( mi112, mi113 );
    const __m128                        mi117 = _mm_mul_ps( mi114, mi115 );
    const __m128                        mi118 = _mm_sub_ps( mi116, mi117 );
    const __m128                        mi119 = _mm_mul_ps( mi111, mi118 );
    const __m128                        mi120 = _mm_div_ps( mi119, vDet );
    const __m128                        mi121 = _mm_shuffle_ps( miC0, miC0, MM_PERM( 3, 3, 3, 2 ) ); /* 30 30 30 20 */
    const __m128                        mi123 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 1, 2, 1, 2 ) ); /* 21 22 11 12 */
    const __m128                        mi125 = _mm_shuffle_ps( miR2, miR1, MM_PERM( 2, 1, 2, 1 ) ); /* 22 21 12 11 */
    const __m128                        mi122 = _mm_shuffle_ps( mi05, miR0, MM_PERM( 2, 1, 2, 1 ) ); /* 12 01 02 01 */
    const __m128                        mi124 = _mm_shuffle_ps( mi06, miR0, MM_PERM( 1, 2, 1, 2 ) ); /* 11 02 01 02 */
    const __m128                        mi126 = _mm_mul_ps( mi122, mi123 );
    const __m128                        mi127 = _mm_mul_ps( mi124, mi125 );
    const __m128                        mi128 = _mm_sub_ps( mi126, mi127 );
    const __m128                        mi129 = _mm_mul_ps( mi121, mi128 );
    const __m128                        mi130 = _mm_div_ps( mi129, vDet );

    ptmRet->m_avRow[0] = _mm_add_ps( mi020, _mm_add_ps( mi030, mi040 ) );
    ptmRet->m_avRow[1] = _mm_add_ps( mi050, _mm_add_ps( mi060, mi070 ) );
    ptmRet->m_avRow[2] = _mm_add_ps( mi080, _mm_add_ps( mi090, mi100 ) );
    ptmRet->m_avRow[3] = _mm_add_ps( mi110, _mm_add_ps( mi120, mi130 ) );
}


/* ---- tgMH_DET_N_F32_04_4_IMPL ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVEC_N_F32_04_1 tgMH_DET_N_F32_04_4_IMPL( TgVEC_N_F32_04_4_CPCU pxM1 )
{
    const __m128                        miR0 = pxM1->m_avRow[0];
    const __m128                        miR1 = pxM1->m_avRow[1];
    const __m128                        miR2 = pxM1->m_avRow[2];
    const __m128                        miR3 = pxM1->m_avRow[3];

    const __m128                        mi01 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 2, 3, 1, 3 ) );
    const __m128                        mi02 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 2, 3, 0, 3 ) );
    const __m128                        mi03 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 1, 3, 0, 3 ) );
    const __m128                        mi04 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 1, 2, 0, 3 ) );
    const __m128                        mi05 = _mm_shuffle_ps( miR3, miR3, MM_PERM( 3, 1, 2, 3 ) );
    const __m128                        mi06 = _mm_shuffle_ps( miR3, miR3, MM_PERM( 3, 0, 2, 3 ) );
    const __m128                        mi07 = _mm_shuffle_ps( miR3, miR3, MM_PERM( 3, 0, 1, 3 ) );
    const __m128                        mi08 = _mm_shuffle_ps( miR3, miR3, MM_PERM( 2, 0, 1, 3 ) );
    const __m128                        mi17 = _mm_mul_ps( mi01, mi05 );
    const __m128                        mi18 = _mm_mul_ps( mi02, mi06 );
    const __m128                        mi19 = _mm_mul_ps( mi03, mi07 );
    const __m128                        mi20 = _mm_mul_ps( mi04, mi08 );

    const __m128                        mi09 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 3, 1, 2, 3 ) );
    const __m128                        mi10 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 3, 0, 2, 3 ) );
    const __m128                        mi11 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 3, 0, 1, 3 ) );
    const __m128                        mi12 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 2, 0, 1, 3 ) );
    const __m128                        mi13 = _mm_shuffle_ps( miR3, miR3, MM_PERM( 2, 3, 1, 3 ) );
    const __m128                        mi14 = _mm_shuffle_ps( miR3, miR3, MM_PERM( 2, 3, 0, 3 ) );
    const __m128                        mi15 = _mm_shuffle_ps( miR3, miR3, MM_PERM( 1, 3, 0, 3 ) );
    const __m128                        mi16 = _mm_shuffle_ps( miR3, miR3, MM_PERM( 1, 2, 0, 3 ) );
    const __m128                        mi21 = _mm_mul_ps( mi09, mi13 );
    const __m128                        mi22 = _mm_mul_ps( mi10, mi14 );
    const __m128                        mi23 = _mm_mul_ps( mi11, mi15 );
    const __m128                        mi24 = _mm_mul_ps( mi12, mi16 );

    const __m128                        mi25 = _mm_sub_ps( mi17, mi21 );
    const __m128                        mi26 = _mm_sub_ps( mi18, mi22 );
    const __m128                        mi27 = _mm_sub_ps( mi19, mi23 );
    const __m128                        mi28 = _mm_sub_ps( mi20, mi24 );

    const __m128                        mi29 = _mm_shuffle_ps( miR1, miR1, MM_PERM( 1, 2, 3, 3 ) );
    const __m128                        mi30 = _mm_shuffle_ps( miR1, miR1, MM_PERM( 0, 2, 3, 3 ) );
    const __m128                        mi31 = _mm_shuffle_ps( miR1, miR1, MM_PERM( 0, 1, 3, 3 ) );
    const __m128                        mi32 = _mm_shuffle_ps( miR1, miR1, MM_PERM( 0, 1, 2, 3 ) );
    const __m128                        mi33 = _mm_mul_ps( mi29, mi25 );
    const __m128                        mi34 = _mm_mul_ps( mi30, mi26 );
    const __m128                        mi35 = _mm_mul_ps( mi31, mi27 );
    const __m128                        mi36 = _mm_mul_ps( mi32, mi28 );

    const __m128                        mi37 = _mm_shuffle_ps( miR0, miR0, MM_PERM( 0, 0, 0, 0 ) );
    const __m128                        mi38 = _mm_shuffle_ps( miR0, miR0, MM_PERM( 1, 1, 1, 1 ) );
    const __m128                        mi39 = _mm_shuffle_ps( miR0, miR0, MM_PERM( 2, 2, 2, 2 ) );
    const __m128                        mi40 = _mm_shuffle_ps( miR0, miR0, MM_PERM( 3, 3, 3, 3 ) );
    const __m128                        mi41 = _mm_mul_ps( mi37, mi33 );
    const __m128                        mi42 = _mm_mul_ps( mi38, mi34 );
    const __m128                        mi43 = _mm_mul_ps( mi39, mi35 );
    const __m128                        mi44 = _mm_mul_ps( mi40, mi36 );

    const __m128                        mi45 = _mm_sub_ps( mi41, mi42 );
    const __m128                        mi46 = _mm_sub_ps( mi43, mi44 );
    const __m128                        mi47 = _mm_add_ps( mi45, mi46 );

    const __m128                        mi48 = _mm_shuffle_ps( mi47, mi47, MM_PERM( 1, 1, 1, 1 ) );
    const __m128                        mi49 = _mm_shuffle_ps( mi47, mi47, MM_PERM( 2, 2, 2, 2 ) );
    const __m128                        mi50 = _mm_add_ss( mi47, mi48 );
    const __m128                        mi51 = _mm_add_ss( mi50, mi49 );

    return ((_mm_shuffle_ps( mi51, mi51, 0x00 )));
}


/*# defined(TGS_COMMON_MATH_API_MATRIX_SPECIALIZATION_INL) */
#endif
