/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (X86_64) Common - Math [Matrix] [N] [F] [44].inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_MATH_API_MATRIX_N_F_44_INL)
#define TGS_COMMON_MATH_API_MATRIX_N_F_44_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* ---- tgMH_CLR_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_CLR_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0 )
{
    tgMM_Set_U08_0x00( pxM0, sizeof( TgVEC_N_F32_04_4 ) );
}


/* ---- tgMH_INIT_T_N_F32_04_4 --------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_INIT_T_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_1_C v0 )
{
    tgMH_INIT_T_F32_04_4( (TgVEC_F32_04_4_PCU)pxM0, (TgVEC_F32_04_1_CP)&v0 );
}


/* ---- tgMH_Init_Quat_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_Init_Quat_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_1_C qR0 )
{
    TgUN_PTR_V128                       uM0;
    TgUN_CONST_PTR_V128                 uV0;

    uM0.m_pN_F32_04_4 = pxM0;
    uV0.m_pN_F32_04_1 = &qR0;
    tgMH_Init_Quat_F32_04_4( uM0.m_pF32_04_4, uV0.m_pF32_04_1 );
}


/* ---- tgMH_CLI_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_CLI_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0 )
{
    pxM0->m_avRow[0] = KTgUNIT_X_V128.m_N_F32_04_1;
    pxM0->m_avRow[1] = KTgUNIT_Y_V128.m_N_F32_04_1;
    pxM0->m_avRow[2] = KTgUNIT_Z_V128.m_N_F32_04_1;
    pxM0->m_avRow[3] = KTgUNIT_W_V128.m_N_F32_04_1;
}


/* ---- tgMH_Set_Quat_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_Set_Quat_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_1_C qR0 )
{
    TgUN_PTR_V128                       uM0;
    TgUN_CONST_PTR_V128                 uV0;

    uM0.m_pN_F32_04_4 = pxM0;
    uV0.m_pN_F32_04_1 = &qR0;
    tgMH_Set_Quat_F32_04_4( uM0.m_pF32_04_4, uV0.m_pF32_04_1 );
}


/* ---- tgMH_SET_T_N_F32_04_4 ---------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_SET_T_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_1_C v0 )
{
    tgMH_SET_T_F32_04_4( (TgVEC_F32_04_4_PCU)pxM0, (TgVEC_F32_04_1_CP)&v0 );
}


/* ---- tgMH_MAX_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_MAX_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_MAX_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_MAX_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_MAX_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_MAX_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- tgMH_MIN_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_MIN_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_MIN_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_MIN_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_MIN_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_MIN_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- tgMH_AND_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_AND_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_AND_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_AND_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_AND_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_AND_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- tgMH_OR_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_OR_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_OR_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_OR_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_OR_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_OR_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- tgMH_XOR_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_XOR_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_XOR_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_XOR_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_XOR_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_XOR_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- PER-VECTOR ARITHMETIC OPERATIONS ----------------------------------------------------------------------------------------------------------------------------------------- */

/* ---- tgMH_ADD_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_ADD_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_ADD_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_ADD_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_ADD_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_ADD_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- tgMH_MUL_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_MUL_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_MUL_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_MUL_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_MUL_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_MUL_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- tgMH_MUL_SM_N_F32_04_4 --------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_MUL_SM_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_1_C vS, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_MUL_N_F32_04_1( vS, pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_MUL_N_F32_04_1( vS, pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_MUL_N_F32_04_1( vS, pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_MUL_N_F32_04_1( vS, pxM1->m_avRow[3] );
}


/* ---- tgMH_MUL_MS_N_F32_04_4 --------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_MUL_MS_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_1_C vS )
{
    pxRet->m_avRow[0] = tgMH_MUL_N_F32_04_1( pxM0->m_avRow[0], vS );
    pxRet->m_avRow[1] = tgMH_MUL_N_F32_04_1( pxM0->m_avRow[1], vS );
    pxRet->m_avRow[2] = tgMH_MUL_N_F32_04_1( pxM0->m_avRow[2], vS );
    pxRet->m_avRow[3] = tgMH_MUL_N_F32_04_1( pxM0->m_avRow[3], vS );
}


/* ---- tgMH_DIV_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_DIV_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_DIV_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_DIV_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_DIV_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_DIV_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- tgMH_DIV_SM_N_F32_04_4 --------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_DIV_SM_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_1_C vS, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_DIV_N_F32_04_1( vS, pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_DIV_N_F32_04_1( vS, pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_DIV_N_F32_04_1( vS, pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_DIV_N_F32_04_1( vS, pxM1->m_avRow[3] );
}


/* ---- tgMH_DIV_MS_N_F32_04_4 --------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_DIV_MS_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_1_C vS )
{
    pxRet->m_avRow[0] = tgMH_DIV_N_F32_04_1( pxM0->m_avRow[0], vS );
    pxRet->m_avRow[1] = tgMH_DIV_N_F32_04_1( pxM0->m_avRow[1], vS );
    pxRet->m_avRow[2] = tgMH_DIV_N_F32_04_1( pxM0->m_avRow[2], vS );
    pxRet->m_avRow[3] = tgMH_DIV_N_F32_04_1( pxM0->m_avRow[3], vS );
}


/* ---- tgMH_SUB_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_SUB_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    pxRet->m_avRow[0] = tgMH_SUB_N_F32_04_1( pxM0->m_avRow[0], pxM1->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_SUB_N_F32_04_1( pxM0->m_avRow[1], pxM1->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_SUB_N_F32_04_1( pxM0->m_avRow[2], pxM1->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_SUB_N_F32_04_1( pxM0->m_avRow[3], pxM1->m_avRow[3] );
}


/* ---- tgMH_NEG_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_NEG_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxRet, TgVEC_N_F32_04_4_CPCU pxM0 )
{
    pxRet->m_avRow[0] = tgMH_NEG_N_F32_04_1( pxM0->m_avRow[0] );
    pxRet->m_avRow[1] = tgMH_NEG_N_F32_04_1( pxM0->m_avRow[1] );
    pxRet->m_avRow[2] = tgMH_NEG_N_F32_04_1( pxM0->m_avRow[2] );
    pxRet->m_avRow[3] = tgMH_NEG_N_F32_04_1( pxM0->m_avRow[3] );
}


/* ---- tgMH_CAT_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
TgEXTN TgVOID tgMH_CAT_N_F32_04_4_IMPL( TgVEC_N_F32_04_4_PCU, TgVEC_N_F32_04_4_CPCU, TgVEC_N_F32_04_4_CPCU );
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_CAT_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1, TgVEC_N_F32_04_4_CPCU pxM2 )
{
    tgMH_CAT_N_F32_04_4_IMPL( pxM0, pxM1, pxM2 );
}


/* ---- tgMH_INV_DET_N_F32_04_4 -------------------------------------------------------------------------------------------------------------------------------------------------- */
TgEXTN TgVOID tgMH_INV_DET_N_F32_04_4_IMPL( TgVEC_N_F32_04_4_PCU, TgVEC_N_F32_04_1_C, TgVEC_N_F32_04_4_CPCU );
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_INV_DET_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_1_C v0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    tgMH_INV_DET_N_F32_04_4_IMPL( pxM0, v0, pxM1 );
}


/* ---- tgMH_INV_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_INV_N_F32_04_4( TgVEC_N_F32_04_4_PCU ptmRet, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    tgMH_INV_DET_N_F32_04_4( ptmRet, tgMH_DET_N_F32_04_4( pxM1 ), pxM1 );
}


/* ---- tgMH_DET_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------ */
TgEXTN TgVEC_N_F32_04_1 tgMH_DET_N_F32_04_4_IMPL( TgVEC_N_F32_04_4_CPCU );
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVEC_N_F32_04_1 tgMH_DET_N_F32_04_4( TgVEC_N_F32_04_4_CPCU pxM0 )
{
    return (tgMH_DET_N_F32_04_4_IMPL( pxM0 ));
}


/* ---- tgMH_TX_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVEC_N_F32_04_1 tgMH_TX_N_F32_04_4( TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_1_C vX0 )
{
    /* Probably a much better/faster way to do this, but I got bored. */

    const __m128                        miXMM0 = _mm_unpacklo_ps( pxM0->m_avRow[0], pxM0->m_avRow[1] );
    const __m128                        miXMM1 = _mm_unpacklo_ps( pxM0->m_avRow[2], pxM0->m_avRow[3] );
    const __m128                        miXMM2 = _mm_unpackhi_ps( pxM0->m_avRow[0], pxM0->m_avRow[1] );
    const __m128                        miXMM3 = _mm_unpackhi_ps( pxM0->m_avRow[2], pxM0->m_avRow[3] );
    const __m128                        miXMM4 = _mm_movelh_ps( miXMM0, miXMM1 );
    const __m128                        miXMM5 = _mm_movehl_ps( miXMM1, miXMM0 );
    const __m128                        miXMM6 = _mm_movelh_ps( miXMM2, miXMM3 );
    const __m128                        miXMM7 = _mm_movehl_ps( miXMM3, miXMM2 );
    const __m128                        miXMM8 = _mm_mul_ps( _mm_shuffle_ps( vX0, vX0, 0x00 ), miXMM4 );
    const __m128                        miXMM9 = _mm_mul_ps( _mm_shuffle_ps( vX0, vX0, 0x55 ), miXMM5 );
    const __m128                        miXMMA = _mm_mul_ps( _mm_shuffle_ps( vX0, vX0, 0xAA ), miXMM6 );
    const __m128                        miXMMB = _mm_mul_ps( _mm_shuffle_ps( vX0, vX0, 0xFF ), miXMM7 );

    return (_mm_add_ps( _mm_add_ps( miXMM8, miXMM9 ), _mm_add_ps( miXMMA, miXMMB ) ));
}


/* ---- tgMH_TX_P_N_F32_04_4 ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVEC_N_F32_04_1 tgMH_TX_P_N_F32_04_4( TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_1_C vX0 )
{
    return (tgMH_TX_N_F32_04_4( pxM0, tgMH_SETP_N_F32_04_1( vX0 ) ));
}


/* ---- tgMH_TX_V_N_F32_04_4 ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVEC_N_F32_04_1 tgMH_TX_V_N_F32_04_4( TgVEC_N_F32_04_4_CPCU pxM0, TgVEC_N_F32_04_1_C vX0 )
{
    return (tgMH_TX_N_F32_04_4( pxM0, tgMH_SETV_N_F32_04_1( vX0 ) ));
}


/* ---- tgMH_GET_COL_0_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVEC_N_F32_04_1 tgMH_Get_Col_0_N_F32_04_4( TgVEC_N_F32_04_4_CPCU pxM0 )
{
    __m128                              miXMM0 = _mm_shuffle_ps( pxM0->m_avRow[0], pxM0->m_avRow[1], 0x44 );
    __m128                              miXMM1 = _mm_shuffle_ps( pxM0->m_avRow[2], pxM0->m_avRow[3], 0x44 );

    return (_mm_shuffle_ps( miXMM0, miXMM1, 0x88 ));
}


/* ---- tgMH_GET_COL_1_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVEC_N_F32_04_1 tgMH_Get_Col_1_N_F32_04_4( TgVEC_N_F32_04_4_CPCU pxM0 )
{
    __m128                              miXMM0 = _mm_shuffle_ps( pxM0->m_avRow[0], pxM0->m_avRow[1], 0x44 );
    __m128                              miXMM1 = _mm_shuffle_ps( pxM0->m_avRow[2], pxM0->m_avRow[3], 0x44 );

    return (_mm_shuffle_ps( miXMM0, miXMM1, 0xDD ));
}


/* ---- tgMH_GET_COL_2_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVEC_N_F32_04_1 tgMH_Get_Col_2_N_F32_04_4( TgVEC_N_F32_04_4_CPCU pxM0 )
{
    __m128                              miXMM2 = _mm_shuffle_ps( pxM0->m_avRow[0], pxM0->m_avRow[1], 0xEE );
    __m128                              miXMM3 = _mm_shuffle_ps( pxM0->m_avRow[2], pxM0->m_avRow[3], 0xEE );

    return (_mm_shuffle_ps( miXMM2, miXMM3, 0x88 ));
}


/* ---- tgMH_GET_COL_3_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVEC_N_F32_04_1 tgMH_Get_Col_3_N_F32_04_4( TgVEC_N_F32_04_4_CPCU pxM0 )
{
    __m128                              miXMM2 = _mm_shuffle_ps( pxM0->m_avRow[0], pxM0->m_avRow[1], 0xEE );
    __m128                              miXMM3 = _mm_shuffle_ps( pxM0->m_avRow[2], pxM0->m_avRow[3], 0xEE );

    return (_mm_shuffle_ps( miXMM2, miXMM3, 0xDD ));
}


/* ---- tgMH_CAT_34_44_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_CAT_34_44_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_3_CPCU pxM1, TgVEC_N_F32_04_4_CPCU pxM2 )
{
    const __m128                        mi00 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[0], 0x00 );
    const __m128                        mi01 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[0], 0x55 );
    const __m128                        mi02 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[0], 0xAA );
    const __m128                        mi03 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[0], 0xFF );
    const __m128                        mi04 = _mm_shuffle_ps( pxM1->m_avRow[1], pxM1->m_avRow[1], 0x00 );
    const __m128                        mi05 = _mm_shuffle_ps( pxM1->m_avRow[1], pxM1->m_avRow[1], 0x55 );
    const __m128                        mi06 = _mm_shuffle_ps( pxM1->m_avRow[1], pxM1->m_avRow[1], 0xAA );
    const __m128                        mi07 = _mm_shuffle_ps( pxM1->m_avRow[1], pxM1->m_avRow[1], 0xFF );
    const __m128                        mi08 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[2], 0x00 );
    const __m128                        mi09 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[2], 0x55 );
    const __m128                        mi10 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[2], 0xAA );
    const __m128                        mi11 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[2], 0xFF );

    const __m128                        mi16 = _mm_mul_ps( mi00, pxM2->m_avRow[0] );
    const __m128                        mi17 = _mm_mul_ps( mi04, pxM2->m_avRow[0] );
    const __m128                        mi18 = _mm_mul_ps( mi08, pxM2->m_avRow[0] );
    const __m128                        mi20 = _mm_mul_ps( mi01, pxM2->m_avRow[1] );
    const __m128                        mi21 = _mm_mul_ps( mi05, pxM2->m_avRow[1] );
    const __m128                        mi22 = _mm_mul_ps( mi09, pxM2->m_avRow[1] );
    const __m128                        mi24 = _mm_mul_ps( mi02, pxM2->m_avRow[2] );
    const __m128                        mi25 = _mm_mul_ps( mi06, pxM2->m_avRow[2] );
    const __m128                        mi26 = _mm_mul_ps( mi10, pxM2->m_avRow[2] );
    const __m128                        mi28 = _mm_mul_ps( mi03, pxM2->m_avRow[3] );
    const __m128                        mi29 = _mm_mul_ps( mi07, pxM2->m_avRow[3] );
    const __m128                        mi30 = _mm_mul_ps( mi11, pxM2->m_avRow[3] );

    pxM0->m_avRow[0] = _mm_add_ps( _mm_add_ps( mi16, mi20 ), _mm_add_ps( mi24, mi28 ) );
    pxM0->m_avRow[1] = _mm_add_ps( _mm_add_ps( mi17, mi21 ), _mm_add_ps( mi25, mi29 ) );
    pxM0->m_avRow[2] = _mm_add_ps( _mm_add_ps( mi18, mi22 ), _mm_add_ps( mi26, mi30 ) );
    pxM0->m_avRow[3] = pxM2->m_avRow[3];
}


/* ---- tgMH_CAT_44_34_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_CAT_44_34_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1, TgVEC_N_F32_04_3_CPCU pxM2 )
{
    const __m128                        mi00 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[0], 0x00 );
    const __m128                        mi01 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[0], 0x55 );
    const __m128                        mi02 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[0], 0xAA );
    const __m128                        mi03 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[0], 0xFF );
    const __m128                        mi04 = _mm_shuffle_ps( pxM1->m_avRow[1], pxM1->m_avRow[1], 0x00 );
    const __m128                        mi05 = _mm_shuffle_ps( pxM1->m_avRow[1], pxM1->m_avRow[1], 0x55 );
    const __m128                        mi06 = _mm_shuffle_ps( pxM1->m_avRow[1], pxM1->m_avRow[1], 0xAA );
    const __m128                        mi07 = _mm_shuffle_ps( pxM1->m_avRow[1], pxM1->m_avRow[1], 0xFF );
    const __m128                        mi08 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[2], 0x00 );
    const __m128                        mi09 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[2], 0x55 );
    const __m128                        mi10 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[2], 0xAA );
    const __m128                        mi11 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[2], 0xFF );
    const __m128                        mi12 = _mm_shuffle_ps( pxM1->m_avRow[3], pxM1->m_avRow[3], 0x00 );
    const __m128                        mi13 = _mm_shuffle_ps( pxM1->m_avRow[3], pxM1->m_avRow[3], 0x55 );
    const __m128                        mi14 = _mm_shuffle_ps( pxM1->m_avRow[3], pxM1->m_avRow[3], 0xAA );
    const __m128                        mi15 = _mm_shuffle_ps( pxM1->m_avRow[3], pxM1->m_avRow[3], 0xFF );

    const __m128                        mi16 = _mm_mul_ps( mi00, pxM2->m_avRow[0] );
    const __m128                        mi17 = _mm_mul_ps( mi04, pxM2->m_avRow[0] );
    const __m128                        mi18 = _mm_mul_ps( mi08, pxM2->m_avRow[0] );
    const __m128                        mi19 = _mm_mul_ps( mi12, pxM2->m_avRow[0] );
    const __m128                        mi20 = _mm_mul_ps( mi01, pxM2->m_avRow[1] );
    const __m128                        mi21 = _mm_mul_ps( mi05, pxM2->m_avRow[1] );
    const __m128                        mi22 = _mm_mul_ps( mi09, pxM2->m_avRow[1] );
    const __m128                        mi23 = _mm_mul_ps( mi13, pxM2->m_avRow[1] );
    const __m128                        mi24 = _mm_mul_ps( mi02, pxM2->m_avRow[2] );
    const __m128                        mi25 = _mm_mul_ps( mi06, pxM2->m_avRow[2] );
    const __m128                        mi26 = _mm_mul_ps( mi10, pxM2->m_avRow[2] );
    const __m128                        mi27 = _mm_mul_ps( mi14, pxM2->m_avRow[2] );
    const __m128                        mi28 = _mm_and_ps( mi03, KTg000F_V128.m_N_F32_04_1 );
    const __m128                        mi29 = _mm_and_ps( mi07, KTg000F_V128.m_N_F32_04_1 );
    const __m128                        mi30 = _mm_and_ps( mi11, KTg000F_V128.m_N_F32_04_1 );
    const __m128                        mi31 = _mm_and_ps( mi15, KTg000F_V128.m_N_F32_04_1 );

    pxM0->m_avRow[0] = _mm_add_ps( _mm_add_ps( mi16, mi20 ), _mm_add_ps( mi24, mi28 ) );
    pxM0->m_avRow[1] = _mm_add_ps( _mm_add_ps( mi17, mi21 ), _mm_add_ps( mi25, mi29 ) );
    pxM0->m_avRow[2] = _mm_add_ps( _mm_add_ps( mi18, mi22 ), _mm_add_ps( mi26, mi30 ) );
    pxM0->m_avRow[3] = _mm_add_ps( _mm_add_ps( mi19, mi23 ), _mm_add_ps( mi27, mi31 ) );
}


/* ---- tgMH_TR_N_F32_04_4 ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgMH_TR_N_F32_04_4( TgVEC_N_F32_04_4_PCU pxM0, TgVEC_N_F32_04_4_CPCU pxM1 )
{
    __m128                              miXMM0 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[1], 0x44 );
    __m128                              miXMM2 = _mm_shuffle_ps( pxM1->m_avRow[0], pxM1->m_avRow[1], 0xEE );
    __m128                              miXMM1 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[3], 0x44 );
    __m128                              miXMM3 = _mm_shuffle_ps( pxM1->m_avRow[2], pxM1->m_avRow[3], 0xEE );

    pxM0->m_avRow[0] = _mm_shuffle_ps( miXMM0, miXMM1, 0x88 );
    pxM0->m_avRow[1] = _mm_shuffle_ps( miXMM0, miXMM1, 0xDD );
    pxM0->m_avRow[2] = _mm_shuffle_ps( miXMM2, miXMM3, 0x88 );
    pxM0->m_avRow[3] = _mm_shuffle_ps( miXMM2, miXMM3, 0xDD );
}


/* =============================================================================================================================================================================== */
#endif
