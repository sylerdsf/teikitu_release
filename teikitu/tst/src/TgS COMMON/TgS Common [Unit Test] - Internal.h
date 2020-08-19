/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] - Internal.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UNIT_TEST_INTERNAL_H)
#define TGS_COMMON_UNIT_TEST_INTERNAL_H

#include "TgS Common.h"
#include "TgS COMMON/TgS Common [Unit Test] - Unit Test.h"
#include <string.h> /** memcmp, used for low level test comparisons */
#include <stdlib.h>


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgEXTN TgVOID                               tgCM_Unit_Test_Register_BASE( TgVOID );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Base_API( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Base_Type( Test_Set * );

TgEXTN TgVOID                               tgCM_Unit_Test_Register_MATH( TgVOID );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Math_Vector( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Math_Matrix( Test_Set * );

TgEXTN TgVOID                               tgCM_Unit_Test_Register_GEOM( TgVOID );

TgEXTN TgVOID                               tgCM_Unit_Test_Register_UTILITY( TgVOID );

TgEXTN TgVOID                               tgCM_Unit_Test_Register_COMMON( TgVOID );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Console( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Event_MGR( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Global( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Job_MGR( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Mem_MGR( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_Profile( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_String_MGR( Test_Set * );
TgEXTN TgVOID                               tgCM_Unit_Test_Register_SysInfo( Test_Set * );


/* =============================================================================================================================================================================== */
#endif
