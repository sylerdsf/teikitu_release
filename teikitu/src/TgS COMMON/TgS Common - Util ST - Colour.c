/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util ST - Colour.c
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
/*  Public Data                                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgALIGN(16) TgVEC_F32_04_1_C         KTg_BLACK_709_F32_04       = { 0.0F, 0.0F, 0.0F, 1.0F };
TgALIGN(16) TgVEC_F32_04_1_C         KTg_WHITE_709_F32_04       = { 1.0F, 1.0F, 1.0F, 1.0F };
TgALIGN(16) TgVEC_F32_04_1_C         KTg_RED_709_F32_04         = { 1.0F, 0.0F, 0.0F, 1.0F };
TgALIGN(16) TgVEC_F32_04_1_C         KTg_GREEN_709_F32_04       = { 0.0F, 1.0F, 0.0F, 1.0F };
TgALIGN(16) TgVEC_F32_04_1_C         KTg_BLUE_709_F32_04        = { 0.0F, 0.0F, 1.0F, 1.0F };
TgALIGN(16) TgVEC_F32_04_1_C         KTg_YELLOW_709_F32_04      = { 1.0F, 1.0F, 0.0F, 1.0F };
TgALIGN(16) TgVEC_F32_04_1_C         KTg_MAGENTA_709_F32_04     = { 1.0F, 0.0F, 1.0F, 1.0F };
TgALIGN(16) TgVEC_F32_04_1_C         KTg_CYAN_709_F32_04        = { 0.0F, 1.0F, 1.0F, 1.0F };

TgALIGN(16) TgCOLOUR32_C             KTg_BLACK_709_U32           = { TgCOLOUR_FROM_RGBA( 0x00u, 0x00u, 0x00u, 0xFFu ) };
TgALIGN(16) TgCOLOUR32_C             KTg_WHITE_709_U32           = { TgCOLOUR_FROM_RGBA( 0xFFu, 0xFFu, 0xFFu, 0xFFu ) };
TgALIGN(16) TgCOLOUR32_C             KTg_RED_709_U32             = { TgCOLOUR_FROM_RGBA( 0xFFu, 0x00u, 0x00u, 0xFFu ) };
TgALIGN(16) TgCOLOUR32_C             KTg_GREEN_709_U32           = { TgCOLOUR_FROM_RGBA( 0x00u, 0xFFu, 0x00u, 0xFFu ) };
TgALIGN(16) TgCOLOUR32_C             KTg_BLUE_709_U32            = { TgCOLOUR_FROM_RGBA( 0x00u, 0x00u, 0xFFu, 0xFFu ) };
TgALIGN(16) TgCOLOUR32_C             KTg_YELLOW_709_U32          = { TgCOLOUR_FROM_RGBA( 0xFFu, 0xFFu, 0x00u, 0xFFu ) };
TgALIGN(16) TgCOLOUR32_C             KTg_MAGENTA_709_U32         = { TgCOLOUR_FROM_RGBA( 0xFFu, 0x00u, 0xFFu, 0xFFu ) };
TgALIGN(16) TgCOLOUR32_C             KTg_CYAN_709_U32            = { TgCOLOUR_FROM_RGBA( 0x00u, 0xFFu, 0xFFu, 0xFFu ) };
