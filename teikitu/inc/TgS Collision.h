/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Collision.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* DEFINITION: PENETRATION TEST
    Returns the first point of contact, the normal of separation and the depth of the contact.
        Point of Contact - A point on the surface of object 1 that is suspected of being first point of contact.
        Normal of Separation - The minimal direction which will separate the two bodies.
        Depth - The minimal distance that will separate the two bodies.
        Concept: The values are such that if the point of contact is moved along the normal by the depth it will cause object 1 to be completely separated from object 0.
                 The resultant axis of separation would be the normal of penetration.  The object being moved to separate the two bodies is object 1.

   F_Sweep == First point and time of contact
   F_Intersect == All possible points of contact/interface (ie non-volume interactions)
   F_Penetrate == All possible points of contact with normal and depths ( ie. dual volume interactions )                                                                           */

#if !defined(TGS_COLLISION_H)
#define TGS_COLLISION_H
#pragma once

#include "TgS COLLISION/TgS Collision - Constants.h"

#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COLLISION/TgS Collision - Type.h_inc"
#define TGS_COLLISION_TYPE_HINC


/* == Collision ================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Module Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgEXTN TgRESULT                             tgCO_Module_Init( TgVOID ); /* #IMPLEMENT */
TgEXTN TgRESULT                             tgCO_Module_Boot( TgVOID ); /* #IMPLEMENT */
TgEXTN TgVOID                               tgCO_Module_Stop( TgVOID ); /* #IMPLEMENT */
TgEXTN TgVOID                               tgCO_Module_Free( TgVOID ); /* #IMPLEMENT */
TgEXTN TgRESULT                             tgCO_Module_Update( TgFLOAT32_C ); /* #IMPLEMENT */

TgEXTN TgVOID                               tgCO_Load_Config( TgVOID ); /* #IMPLEMENT */
TgEXTN TgVOID                               tgCO_Save_Config( TgVOID ); /* #IMPLEMENT */

TgEXTN TgBOOL                               tgCO_Query_Init( TgVOID ); /* #IMPLEMENT */
TgEXTN TgBOOL                               tgCO_Query_Boot( TgVOID ); /* #IMPLEMENT */
TgEXTN TgRSIZE                              tgCO_Query_Fixed_Memory( TgVOID ); /* #IMPLEMENT */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Collision Functions                                                                                                                                                            */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#define TEMPLATE__VECTOR_DIM 4
#include "TgS COLLISION/TgS Collision.h_inc"
#define TGS_COMMON_GEOMETRY_API_HINC

#define TEMPLATE__VECTOR_DIM 4
#include "TgS COLLISION/TgS Collision.i_inc"
#define TGS_COMMON_GEOMETRY_API_IINC


/* =============================================================================================================================================================================== */
#endif
