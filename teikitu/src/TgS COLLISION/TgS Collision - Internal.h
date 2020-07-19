/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Collision - Internal.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COLLISION_INTERNAL_H)
#define TGS_COLLISION_INTERNAL_H

/* #TODO tgCO_F_Sweep_LR11_CP */
/* #TODO: tgCO_F_Sweep_VT_CP */
/* #TODO: tgCO_F_Sweep_ET_CP */
/* #TODO: tgCO_F_Test_BA_VT */
/* #TODO: tgCO_F_Penetrate_BX_BX */
/* #TODO: tgCO_F_Penetrate_BX_BX */

#include "TgS COMMON/TgS Common -- INCLUDE.h"
#include "TgS Ring 0 - Type.h"

#include "TgS Collision.h"


/* == Collision ================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */
/*  Private Macros                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */
#if TgCOMPILE__CONSOLE

#define TgERROR_CO( ... ) tgCN_PrintF( KTgCN_CHANEL_ERROR, "%-16.16s(%-32.32s): ", "Collision", __FUNCTION__ );  tgCN_PrintF( KTgCN_CHANEL_ERROR, __VA_ARGS__ )
#define TgWARN_CO( ... ) tgCN_PrintF( KTgCN_CHANEL_WARNING, "%-16.16s(%-32.32s): ", "Collision", __FUNCTION__ );  tgCN_PrintF( KTgCN_CHANEL_WARNING, __VA_ARGS__ )
#define TgLOG_CO( ... ) tgCN_PrintF( KTgCN_CHANEL_LOG, "%-16.16s(%-32.32s): ", "Collision", __FUNCTION__ );  tgCN_PrintF( KTgCN_CHANEL_LOG, __VA_ARGS__ )

/*# TgCOMPILE__CONSOLE */
#else

#define TgERROR_CO( ... )
#define TgWARN_CO( ... )
#define TgLOG_CO(  ... )

/*# TgS_COMPILE_CONSOLE */
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgEXTN TgCHAR_MB_P                          tgGM_Primitive_To_String( ETgPRIMITIVE_C );

#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - Internal.h_inc"
#define TGS_COLLISION_INTERNAL_HINC


/* =============================================================================================================================================================================== */
#endif

