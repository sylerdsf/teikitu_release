/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Collision - F - Capsule.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/* == Collision ================================================================================================================================================================== */

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Capsule-Capsule.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Capsule-Plane.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Capsule-Point.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Capsule-Sphere.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Capsule-Triangle.c_inc"

#define LN_CAP_0 0
#define LN_CAP_1 0
#define VI(A) FCN_VO(A##00)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Capsule-Linear.c_inc"
#undef VI
#undef LN_CAP_0
#undef LN_CAP_1

#define LN_CAP_0 1
#define LN_CAP_1 0
#define VI(A) FCN_VO(A##10)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Capsule-Linear.c_inc"
#undef VI
#undef LN_CAP_0
#undef LN_CAP_1

#define LN_CAP_0 1
#define LN_CAP_1 1
#define VI(A) FCN_VO(A##11)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Capsule-Linear.c_inc"
#undef VI
#undef LN_CAP_0
#undef LN_CAP_1

#define PRIM_CPC VEC_OBJ_T(TgTUBE,CPC)
#define VGM(A) FCN_VO(tgGM_CP_##A)
#define VCO_F(A) FCN_VO(tgCO_F_CP_##A)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Clip [Template].c_inc"
#undef VCO_F
#undef VGM
#undef PRIM_CPC
