/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - API [Math].inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_API_MATH_INL)
#define TGS_COMMON_BASE_API_MATH_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TEMPLATE__ENABLE_INTEGER
#define TEMPLATE__ENABLE_INT_FAST

#define TEMPLATE__TYPE_SIZE 8
#include "TgS COMMON/TgS Common - Base - API [Math].i_inc"
#define TEMPLATE__TYPE_SIZE 16
#include "TgS COMMON/TgS Common - Base - API [Math].i_inc"
#define TEMPLATE__TYPE_SIZE 32
#include "TgS COMMON/TgS Common - Base - API [Math].i_inc"
#define TEMPLATE__TYPE_SIZE 64
#include "TgS COMMON/TgS Common - Base - API [Math].i_inc"
#define TEMPLATE__OVERRIDE_INT_TYPE PTR
#include "TgS COMMON/TgS Common - Base - API [Math].i_inc"
#define TEMPLATE__OVERRIDE_INT_TYPE MAX
#include "TgS COMMON/TgS Common - Base - API [Math].i_inc"

#undef TEMPLATE__ENABLE_INT_FAST
#undef TEMPLATE__ENABLE_INTEGER

#include "TgS COMMON/TgS Common - Base - API [Math].i_inc"


#define TGS_COMMON_BASE_API_MATH_IINC


/* ---- tgCM_RAND_F32 ------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgFLOAT32 tgCM_RAND_F32( TgVOID )
{
    TgUINT_E32_C                            uiMantissa = tgCM_RAND_MT_U32(); /* 24 bits - 1 sign bit, and 23 bits for mantissa */
    TgUINT_E32_C                            uiExponent = tgCM_RAND_MT_U32(); /* 8 bits for the exponent */

    TgSINT_F32_C    iMantissa_Numerator = *(TgSINT_E32_CP)&uiMantissa;
    TgFLOAT32_C                             fMantissa_Numerator = (TgFLOAT32)iMantissa_Numerator;
    TgUINT_F32_C    uiMantissa_Denominator = (TgUINT_F32)KTgMAX_S32 + 1;
    TgFLOAT32_C                             fMantissa_Denominator = (TgFLOAT32)uiMantissa_Denominator;

    TgFLOAT32_C                             fMantissa = fMantissa_Numerator / fMantissa_Denominator;

    TgSINT_F32_C    iExponent_Numerator = *(TgSINT_E32_CP)&uiExponent;
    TgFLOAT32_C                             fExponent_Numerator = (TgFLOAT32)iExponent_Numerator;
    TgUINT_F32_C    uiExponent_Denominator = (KTgMAX_S32 >> 4) + 1;
    TgFLOAT32_C                             fExponent_Denominator = (TgFLOAT32)uiExponent_Denominator;

    TgFLOAT32_C                             fExponent = fExponent_Numerator / fExponent_Denominator;

    TgERROR((fMantissa > -1.0F) && (fMantissa < 1.0F));
    TgERROR((fExponent > -32.0F) && (fExponent < 32.0F));

    return (fMantissa * fExponent);
}


/* ---- tgCM_RAND_F64 ------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgFLOAT64 tgCM_RAND_F64( TgVOID )
{
    TgUINT_E64_C                            uiMantissa_0 = tgCM_RAND_MT_U32();
    TgUINT_E64_C                            uiMantissa_1 = tgCM_RAND_MT_U32();
    TgUINT_E64_C                            uiMantissa = uiMantissa_0 + (uiMantissa_1 << 32); /* 53 bits - 1 sign bit, and 52 bits for mantissa */
    TgUINT_E64_C                            uiExponent = (TgUINT_E64)tgCM_RAND_MT_U32() << 32; /* 11 bits for the exponent, bit shift for sign bit */

    TgSINT_F64_C                            iMantissa_Numerator = *(TgSINT_E64_CP)&uiMantissa;
    TgFLOAT64_C                             fMantissa_Numerator = (TgFLOAT64)iMantissa_Numerator;
    TgUINT_F64_C                            uiMantissa_Denominator = (TgUINT_F64)KTgMAX_S64 + 1;
    TgFLOAT64_C                             fMantissa_Denominator = (TgFLOAT64)uiMantissa_Denominator;

    TgFLOAT64_C                             fMantissa = fMantissa_Numerator / fMantissa_Denominator;

    TgSINT_F64_C                            iExponent_Numerator = *(TgSINT_E64_CP)&uiExponent;
    TgFLOAT64_C                             fExponent_Numerator = (TgFLOAT64)iExponent_Numerator;
    TgUINT_F64_C                            uiExponent_Denominator = (KTgMAX_S64 >> 7) + 1;
    TgFLOAT64_C                             fExponent_Denominator = (TgFLOAT64)uiExponent_Denominator;

    TgFLOAT64_C                             fExponent = fExponent_Numerator / fExponent_Denominator;

    TgERROR((fMantissa > -1.0) && (fMantissa < 1.0));
    TgERROR((fExponent > -256.0) && (fExponent < 256.0));

    return (fMantissa * fExponent);}


/* =============================================================================================================================================================================== */
#endif
