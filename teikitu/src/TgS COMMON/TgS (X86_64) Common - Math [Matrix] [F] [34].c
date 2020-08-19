/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (X86_64) Common - Math [Matrix] [F] [34].c
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

/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgMH_CAT_F32_04_3_IMPL ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgMH_CAT_F32_04_3_IMPL( TgVEC_F32_04_3_PCU ptmRet, TgVEC_F32_04_3_CPCU pmM0, TgVEC_F32_04_3_CPCU pmM1 )
{
    const __m128                        mi00 = _mm_shuffle_ps( pmM0->m_avCol[0], pmM0->m_avCol[0], 0x00 );
    const __m128                        mi01 = _mm_shuffle_ps( pmM0->m_avCol[0], pmM0->m_avCol[0], 0x55 );
    const __m128                        mi02 = _mm_shuffle_ps( pmM0->m_avCol[0], pmM0->m_avCol[0], 0xAA );
    const __m128                        mi03 = _mm_shuffle_ps( pmM0->m_avCol[0], pmM0->m_avCol[0], 0xFF );
    const __m128                        mi04 = _mm_shuffle_ps( pmM0->m_avCol[1], pmM0->m_avCol[1], 0x00 );
    const __m128                        mi05 = _mm_shuffle_ps( pmM0->m_avCol[1], pmM0->m_avCol[1], 0x55 );
    const __m128                        mi06 = _mm_shuffle_ps( pmM0->m_avCol[1], pmM0->m_avCol[1], 0xAA );
    const __m128                        mi07 = _mm_shuffle_ps( pmM0->m_avCol[1], pmM0->m_avCol[1], 0xFF );
    const __m128                        mi08 = _mm_shuffle_ps( pmM0->m_avCol[2], pmM0->m_avCol[2], 0x00 );
    const __m128                        mi09 = _mm_shuffle_ps( pmM0->m_avCol[2], pmM0->m_avCol[2], 0x55 );
    const __m128                        mi10 = _mm_shuffle_ps( pmM0->m_avCol[2], pmM0->m_avCol[2], 0xAA );
    const __m128                        mi11 = _mm_shuffle_ps( pmM0->m_avCol[2], pmM0->m_avCol[2], 0xFF );

    const __m128                        mi16 = _mm_mul_ps( mi00, pmM1->m_avCol[0] );
    const __m128                        mi17 = _mm_mul_ps( mi04, pmM1->m_avCol[0] );
    const __m128                        mi18 = _mm_mul_ps( mi08, pmM1->m_avCol[0] );
    const __m128                        mi20 = _mm_mul_ps( mi01, pmM1->m_avCol[1] );
    const __m128                        mi21 = _mm_mul_ps( mi05, pmM1->m_avCol[1] );
    const __m128                        mi22 = _mm_mul_ps( mi09, pmM1->m_avCol[1] );
    const __m128                        mi24 = _mm_mul_ps( mi02, pmM1->m_avCol[2] );
    const __m128                        mi25 = _mm_mul_ps( mi06, pmM1->m_avCol[2] );
    const __m128                        mi26 = _mm_mul_ps( mi10, pmM1->m_avCol[2] );
    const __m128                        mi28 = _mm_and_ps( mi03, KTg000F_V128.m_vF32_04_1 );
    const __m128                        mi29 = _mm_and_ps( mi07, KTg000F_V128.m_vF32_04_1 );
    const __m128                        mi30 = _mm_and_ps( mi11, KTg000F_V128.m_vF32_04_1 );

    ptmRet->m_avCol[0] = _mm_add_ps( _mm_add_ps( mi16, mi20 ), _mm_add_ps( mi24, mi28 ) );
    ptmRet->m_avCol[1] = _mm_add_ps( _mm_add_ps( mi17, mi21 ), _mm_add_ps( mi25, mi29 ) );
    ptmRet->m_avCol[2] = _mm_add_ps( _mm_add_ps( mi18, mi22 ), _mm_add_ps( mi26, mi30 ) );
}


/* ---- tgMH_INV_DET_F32_04_3_IMPL -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgMH_INV_DET_F32_04_3_IMPL( TgVEC_F32_04_4_PCU ptmRet, TgFLOAT32_C fDet, TgVEC_F32_04_3_CPCU pmM1 )
{
    /*  Construct the four corner matrices of the 4x4.  Note: this is probably an inefficient method to take the inverse of a standard linear transform matrix since it 
    cant take into account the known information of the row or column of zeros that normally exists in the matrix.  However, since inverse operations should not be
    terribly time sensitive this may not be a problem. */

    const __m128                        vDet = _mm_set1_ps( fDet );

    const __m128                        miR0 = pmM1->m_avCol[0];
    const __m128                        miR1 = pmM1->m_avCol[1];
    const __m128                        miR2 = pmM1->m_avCol[2];
    const __m128                        mi00 = _mm_and_ps( KTgFFF0_V128.m_vF32_04_1, vDet );
    const __m128                        miDet = _mm_add_ps( KTgUNIT_W_V128.m_vF32_04_1, mi00 );

    const __m128                        mi01 = _mm_shuffle_ps( miR0, miR1, MM_PERM( 1, 2, 1, 2 ) );
    const __m128                        mi02 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 1, 2, 1, 2 ) );
    const __m128                        mi03 = _mm_shuffle_ps( mi01, mi01, MM_PERM( 2, 1, 0, 3 ) );
    const __m128                        mi04 = _mm_shuffle_ps( mi02, mi01, MM_PERM( 1, 0, 3, 3 ) );
    const __m128                        mi05 = _mm_shuffle_ps( mi01, mi01, MM_PERM( 3, 0, 1, 3 ) );
    const __m128                        mi06 = _mm_shuffle_ps( mi02, mi01, MM_PERM( 0, 1, 2, 3 ) );
    const __m128                        mi07 = _mm_mul_ps( mi03, mi04 );
    const __m128                        mi08 = _mm_mul_ps( mi05, mi06 );
    const __m128                        mi09 = _mm_sub_ps( mi07, mi08 );
    const __m128                        mi10 = _mm_and_ps( KTgFFF0_V128.m_vF32_04_1, _mm_div_ps( mi09, miDet ) );

    const __m128                        mi11 = _mm_shuffle_ps( miR0, miR1, MM_PERM( 0, 2, 0, 2 ) );
    const __m128                        mi12 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 0, 2, 0, 2 ) );
    const __m128                        mi13 = _mm_shuffle_ps( mi11, mi11, MM_PERM( 3, 0, 1, 3 ) );
    const __m128                        mi14 = _mm_shuffle_ps( mi12, mi11, MM_PERM( 0, 1, 2, 3 ) );
    const __m128                        mi15 = _mm_shuffle_ps( mi11, mi11, MM_PERM( 2, 1, 0, 3 ) );
    const __m128                        mi16 = _mm_shuffle_ps( mi12, mi11, MM_PERM( 1, 0, 3, 3 ) );
    const __m128                        mi17 = _mm_mul_ps( mi13, mi14 );
    const __m128                        mi18 = _mm_mul_ps( mi15, mi16 );
    const __m128                        mi19 = _mm_sub_ps( mi17, mi18 );
    const __m128                        mi20 = _mm_and_ps( KTgFFF0_V128.m_vF32_04_1, _mm_div_ps( mi19, miDet ) );

    const __m128                        mi21 = _mm_shuffle_ps( miR0, miR1, MM_PERM( 0, 1, 0, 1 ) );
    const __m128                        mi22 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 0, 1, 0, 1 ) );
    const __m128                        mi23 = _mm_shuffle_ps( mi21, mi21, MM_PERM( 2, 1, 0, 3 ) );
    const __m128                        mi24 = _mm_shuffle_ps( mi22, mi21, MM_PERM( 1, 0, 3, 3 ) );
    const __m128                        mi25 = _mm_shuffle_ps( mi21, mi21, MM_PERM( 3, 0, 1, 3 ) );
    const __m128                        mi26 = _mm_shuffle_ps( mi22, mi21, MM_PERM( 0, 1, 2, 3 ) );
    const __m128                        mi27 = _mm_mul_ps( mi23, mi24 );
    const __m128                        mi28 = _mm_mul_ps( mi25, mi26 );
    const __m128                        mi29 = _mm_sub_ps( mi27, mi28 );
    const __m128                        mi30 = _mm_and_ps( KTgFFF0_V128.m_vF32_04_1, _mm_div_ps( mi29, miDet ) );

    const __m128                        mi31 = _mm_shuffle_ps( mi10, mi20, MM_PERM( 0, 1, 0, 1 ) ); /* 00, 01, 10, 11 */
    const __m128                        mi32 = _mm_shuffle_ps( mi10, mi20, MM_PERM( 2, 3, 2, 3 ) ); /* 02, 03, 12, 13 */
    const __m128                        mi34 = _mm_shuffle_ps( mi31, mi30, MM_PERM( 0, 2, 0, 0 ) ); /* 00, 10, 20, 20 */
    const __m128                        mi35 = _mm_shuffle_ps( mi31, mi30, MM_PERM( 1, 3, 1, 1 ) ); /* 01, 11, 21, 21 */
    const __m128                        mi36 = _mm_shuffle_ps( mi32, mi30, MM_PERM( 0, 2, 2, 2 ) ); /* 02, 12, 22, 22 */

    const __m128                        mi37 = _mm_shuffle_ps( miR0, miR0, MM_PERM( 3, 3, 3, 3 ) );
    const __m128                        mi38 = _mm_shuffle_ps( miR1, miR1, MM_PERM( 3, 3, 3, 3 ) );
    const __m128                        mi39 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 3, 3, 3, 3 ) );

    const __m128                        mi40 = _mm_mul_ps( mi37, mi34 );
    const __m128                        mi41 = _mm_mul_ps( mi38, mi35 );
    const __m128                        mi42 = _mm_mul_ps( mi39, mi36 );

    const __m128                        mi43 = _mm_sub_ps( KTgZERO_V128.m_vF32_04_1, mi40 );
    const __m128                        mi44 = _mm_add_ps( mi41, mi42 );
    const __m128                        mi45 = _mm_and_ps( KTgFFF0_V128.m_vF32_04_1, _mm_sub_ps( mi43, mi44 ) );

    const __m128                        mi46 = _mm_shuffle_ps( mi45, mi45, MM_PERM( 3, 3, 3, 0 ) );
    const __m128                        mi47 = _mm_shuffle_ps( mi45, mi45, MM_PERM( 3, 3, 3, 1 ) );
    const __m128                        mi48 = _mm_shuffle_ps( mi45, mi45, MM_PERM( 3, 3, 3, 2 ) );

    ptmRet->m_avCol[0] = _mm_add_ps( mi46, mi10 );
    ptmRet->m_avCol[1] = _mm_add_ps( mi47, mi20 );
    ptmRet->m_avCol[2] = _mm_add_ps( mi48, mi30 );
}


/* ---- tgMH_DET_F32_04_3_IMPL ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgFLOAT32 tgMH_DET_F32_04_3_IMPL( TgVEC_F32_04_3_CPCU pmM1 )
{
    const __m128                        miR0 = pmM1->m_avCol[0];
    const __m128                        miR1 = pmM1->m_avCol[1];
    const __m128                        miR2 = pmM1->m_avCol[2];

    const __m128                        mi01 = _mm_shuffle_ps( miR1, miR1, MM_PERM( 1, 2, 0, 3 ) );
    const __m128                        mi02 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 2, 0, 1, 3 ) );
    const __m128                        mi03 = _mm_shuffle_ps( miR1, miR1, MM_PERM( 2, 0, 1, 3 ) );
    const __m128                        mi04 = _mm_shuffle_ps( miR2, miR2, MM_PERM( 1, 2, 0, 3 ) );

    const __m128                        mi05 = _mm_mul_ps( mi01, mi02 );
    const __m128                        mi06 = _mm_mul_ps( mi03, mi04 );
    const __m128                        mi07 = _mm_sub_ps( mi05, mi06 );
    const __m128                        mi08 = _mm_mul_ps( miR0, mi07 );

    const __m128                        mi09 = _mm_shuffle_ps( mi08, mi08, MM_PERM( 1, 1, 1, 1 ) );
    const __m128                        mi10 = _mm_shuffle_ps( mi08, mi08, MM_PERM( 2, 2, 2, 2 ) );
    const __m128                        mi11 = _mm_add_ss( mi08, mi09 );
    const __m128                        mi12 = _mm_add_ss( mi10, mi11 );
    
    const __m128                        mi13 = _mm_shuffle_ps( mi12, mi12, 0x00 );

    return (*(TgFLOAT32_CP)&mi13);
}


/*# defined(TGS_COMMON_MATH_API_MATRIX_SPECIALIZATION_INL) */
#endif
