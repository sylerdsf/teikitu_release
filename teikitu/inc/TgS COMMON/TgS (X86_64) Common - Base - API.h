/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (X86_64) Common - Base - API.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_X86_64_COMMON_BASE_TYPE_H)
#define TGS_X86_64_COMMON_BASE_TYPE_H
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_BASE_API_BITFIELD Bitfields
    @ingroup TGS_COMMON_BASE
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/** @addtogroup TGS_COMMON_BASE_API_BITFIELD */
/** @{ */

/* ---- Bitfields -------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                @brief Set the state of the bit at ARG1 in integer object at ARG0 according to the value in ARG2 (0 for false, and 1 otherwise)*/
                                            /** @param[out] OUT0 Pointer to an exact integer type */
                                            /** @param[in] ARG1 The bit index to modify where bit 0 is the least significant */
                                            /** @param[in] ARG2 boolean flag to indicate set or reset state for bit */
TgINLINE TgVOID                             tgBF_Set_Flag_U32( TgUINT_E32_PCU OUT0, TgUINT_F08_C ARG1, TgBOOL_C ARG2 );

                                            /** @brief Set the state of the bit at ARG1 in integer object at ARG0 according to the value in ARG2 (0 for false, and 1 otherwise)*/
                                            /** @param[out] OUT0 Pointer to an exact integer type */
                                            /** @param[in] ARG1 The bit index to modify where bit 0 is the least significant */
                                            /** @param[in] ARG2 boolean flag to indicate set or reset state for bit */
TgINLINE TgVOID                             tgBF_Set_Flag_U64( TgUINT_E64_PCU OUT0, TgUINT_F08_C ARG1, TgBOOL_C ARG2 );

                                            /** @brief Toggle (xor) the state of the bit at ARG1 in integer object at ARG0 */
                                            /** @param[out] OUT0 Pointer to an exact integer type */
                                            /** @param[in] ARG1 The bit index to modify where bit 0 is the least significant */
TgINLINE TgVOID                             tgBF_Toggle_Flag_U32( TgUINT_E32_PCU OUT0, TgUINT_F08_C ARG1 );

                                            /** @brief Toggle (xor) the state of the bit at ARG1 in integer object at ARG0 */
                                            /** @param[out] OUT0 Pointer to an exact integer type */
                                            /** @param[in] ARG1 The bit index to modify where bit 0 is the least significant */
TgINLINE TgVOID                             tgBF_Toggle_Flag_U64( TgUINT_E64_PCU OUT0, TgUINT_F08_C ARG1 );

                                            /** @brief Reset the state of all bits in integer object at ARG0 */
                                            /** @param[out] OUT0 Pointer to an exact integer type */
TgINLINE TgVOID                             tgBF_Reset_U32( TgUINT_E32_PCU OUT0 );

                                            /** @brief Reset the state of all bits in integer object at ARG0 */
                                            /** @param[out] OUT0 Pointer to an exact integer type */
TgINLINE TgVOID                             tgBF_Reset_U64( TgUINT_E64_PCU OUT0 );

                                            /** @@brief Return the value of the bit at ARG1 in integer object at ARG0*/
                                            /** @param[in] ARG0 Pointer to an exact integer type */
                                            /** @param[in] ARG1 The bit index to read where bit 0 is the least significant */
                                            /** @return False if the bit is zero and true otherwise */
TgINLINE TgBOOL                             tgBF_Test_Flag_U32( TgUINT_E32_CPCU ARG0, TgUINT_F08_C ARG1 );

                                            /** @@brief Return the value of the bit at ARG1 in integer object at ARG0*/
                                            /** @param[in] ARG0 Pointer to an exact integer type */
                                            /** @param[in] ARG1 The bit index to read where bit 0 is the least significant */
                                            /** @return False if the bit is zero and true otherwise */
TgINLINE TgBOOL                             tgBF_Test_Flag_U64( TgUINT_E64_CPCU ARG0, TgUINT_F08_C ARG1 );

/** @} */


/* =============================================================================================================================================================================== */
#endif
