/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Collision - F - Triangle.c
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


/*                                                                                                                                                                                 */
/* Triangle Definition: T0(α,β) = P0 + α•E0 + β•E1 | α ε [ 0, 1], β ε [ 0, 1], (α + β) ε [0, 1]                                                                                    */
/*  Segment Definition:   G1(γ) = P3 + γ•D1 | γ ε [ 0, 1]                                                                                                                          */
/*                                                                                                                                                                                 */
/* Derivation:                                                                                                                                                                     */
/*                                                                                                                                                                                 */
/*                                                                                                                                                                                 */
/*         .    .              .    .                                                                                                                                              */
/*          . G .               . G .   NOTE: Keep in mind that in regions C, E and G, an obtuse angle can lead                                                                    */
/*           .  .                .  .            to having significant projections along the other edge.                                                                           */
/*            . .                 . .      E0                                                                                                                                      */
/*             ..                  ..     .                                                                                                                                        */
/*              .2                  .  F .                                                                                                                                         */
/*              |\                  |\  .                                                                                                                                          */
/*              | \                 | \.                                                                                                                                           */
/*          B   |  \   F         B  | /.  E                                                                                                                                        */
/*              | A \               |/  .                                                                                                                                          */
/*         .....|____\..... E0      .O   .                                                                                                                                         */
/*             O.     .1           ..     .                                                                                                                                        */
/*              .      .          . .  D   .                                                                                                                                       */
/*          C   .   D   .   E    .  .                                                                                                                                              */
/*              .        .      . C .                                                                                                                                              */
/*              .                   .                                                                                                                                              */
/*             E1                  E1                                                                                                                                              */
/*                                                                                                                                                                                 */
/*                                                                                                                                                                                 */
/*  Let P0,P1,P2 be the three defining vertices of a triangle with E0 = P1 - P0 and E1 = P2 - P0.                                                                                  */
/*  Let P3, D1 by the origin and the vector of a line segment respectively.                                                                                                        */
/*                                                                                                                                                                                 */
/*  Let DS = P3 - P0                                                                                                                                                               */
/*                                                                                                                                                                                 */
/*  Let TG1, TE0, TE1 represent the co-ordinates in their respective reference frames of the extrapolated point                                                                    */
/*   of contact between the line(segment) and the plane(triangle).                                                                                                                 */
/*                                                                                                                                                                                 */
/*      [D1•D1  D1•E0  D1•E1] [TG1]     [DS•D1]                                                                                                                                    */
/*      [D1•E0  E0•E0  E0•E1] [TE0]  =  [DS•E0]                                                                                                                                    */
/*      [D1•E1  E0•E1  E1•E1] [TE1]     [DS•E1]                                                                                                                                    */
/*                                                                                                                                                                                 */
/*      Let C(ij) be the cofactor matrix of row i and column j We know that the determinant can be computed by                                                                     */
/*       adding: det = (D1•E0)•C01 + (E0•E0)•C11 + (E0•E1)•C12                                                                                                                     */
/*                                                                                                                                                                                 */
/*      Let K = 1.0/det                                                                                                                                                            */
/*                                                                                                                                                                                 */
/*      [TG1]     [C00  C01  C02] [K_(DS•D1,DIM)]                                                                                                                                  */
/*      [TE0]  =  [C01  C11  C12] [K_(DS•E0,DIM)]                                                                                                                                  */
/*      [TE1]     [C02  C12  C22] [K_(DS•E1,DIM)]                                                                                                                                  */
/*                                                                                                                                                                                 */
/*  However, it is known that TG1 ε [ 0, 1], TE0 ε [ 0, 1], TE1 ε [ 0, 1], and (TE0 + TE1) ε [ 0, 1]                                                                               */
/*  These limitations present us with these possible cases.                                                                                                                        */
/*                                                                                                                                                                                 */
/*  [1] TG1 ε (-∞, 0)                                                                                                                                                              */
/*      If the given condition is met, then the line segment is tested against the specified triangle edge.                                                                        */
/*          Triangle Edge 2 • (TE0 + TE1) ε ( 1, ∞)                                                                                                                                */
/*          Triangle Edge 0 • TE0 ε (-∞, 0)                                                                                                                                        */
/*          Triangle Edge 1 • TE1 ε (-∞, 0)                                                                                                                                        */
/*  [2] TG1 ε [ 0, 1]                                                                                                                                                              */
/*     [A] (TE0 + TE1) ε (-∞, 1]                                                                                                                                                   */
/*          Triangle Edge 0 • TE0 ε (-∞, 0)                                                                                                                                        */
/*          Triangle Edge 1 • TE1 ε (-∞, 0)                                                                                                                                        */
/*          Intersection • TE0 ε [ 0, 1], TE1 ε [ 0, 1]                                                                                                                            */
/*     [B] (TE0 + TE1) ε ( 1, ∞)                                                                                                                                                   */
/*          Triangle Edge 2                                                                                                                                                        */
/*          Triangle Edge 0 • TE0 ε (-∞, 0)                                                                                                                                        */
/*          Triangle Edge 1 • TE1 ε (-∞, 0)                                                                                                                                        */
/*  [3] TG1 ε ( 1, ∞)                                                                                                                                                              */
/*      If the given condition is met, then the line segment is tested against the specified triangle edge.                                                                        */
/*          Triangle Edge 2 • (TE0 + TE1) ε ( 1, ∞)                                                                                                                                */
/*          Triangle Edge 0 • TE0 ε (-∞, 0)                                                                                                                                        */
/*          Triangle Edge 1 • TE1 ε (-∞, 0)                                                                                                                                        */
/*                                                                                                                                                                                 */
/*  If the triangle and the segment happen to be parallel then,                                                                                                                    */
/*    The distance between the line segment and the triangle can be found by checking the distance of the segment                                                                  */
/*     against the three triangle edges (line segments) and the triangle against the two end points of the line                                                                    */
/*     segment.  The resulting minimal value (with any corresponding extra information) will be the desired result.                                                                */
/*                                                                                                                                                                                 */


/*                                                                                                                                                                                 */
/* Triangle Definition: T0(α,β) = P0 + α•E0 + β•E1 | α ε [ 0, 1], β ε [ 0, 1], (α + β) ε [0, 1]                                                                                    */
/*                                                                                                                                                                                 */
/* Derivation:                                                                                                                                                                     */
/*                                                                                                                                                                                 */
/*                                                                                                                                                                                 */
/*         .    .              .    .                                                                                                                                              */
/*          . G .               . G .   NOTE: Keep in mind that in regions C, E and G, an obtuse angle can lead                                                                    */
/*           .  .                .  .            to having significant projections along the other edge.                                                                           */
/*            . .                 . .      E0                                                                                                                                      */
/*             ..                  ..     .                                                                                                                                        */
/*              .2                  .  F .                                                                                                                                         */
/*              |\                  |\  .                                                                                                                                          */
/*              | \                 | \.                                                                                                                                           */
/*          B   |  \   F         B  | /.  E                                                                                                                                        */
/*              | A \               |/  .                                                                                                                                          */
/*         .....|____\..... E0      .O   .                                                                                                                                         */
/*             O.     .1           ..     .                                                                                                                                        */
/*              .      .          . .  D   .                                                                                                                                       */
/*          C   .   D   .   E    .  .                                                                                                                                              */
/*              .        .      . C .                                                                                                                                              */
/*              .                   .                                                                                                                                              */
/*             E1                  E1                                                                                                                                              */
/*                                                                                                                                                                                 */
/*     These regions define the closest feature of the triangle when contained in their area.  The point is projected onto the                                                     */
/*    triangle plane, and the region that contains the point is determined.  It is then a simple matter to calculate the resulting                                                 */
/*    distance to the triangle for the point.                                                                                                                                      */
/*                                                                                                                                                                                 */




#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Triangle [Axis Separation].c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Triangle [Util].c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Triangle-Particle.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Triangle-Point.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Triangle-Triangle.c_inc"

#define LN_CAP_0 0
#define LN_CAP_1 0
#define VI(A) FCN_VO(A##00)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Triangle-Linear.c_inc"
#undef VI
#undef LN_CAP_0
#undef LN_CAP_1

#define LN_CAP_0 1
#define LN_CAP_1 0
#define VI(A) FCN_VO(A##10)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Triangle-Linear.c_inc"
#undef VI
#undef LN_CAP_0
#undef LN_CAP_1

#define LN_CAP_0 1
#define LN_CAP_1 1
#define VI(A) FCN_VO(A##11)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Triangle-Linear.c_inc"
#undef VI
#undef LN_CAP_0
#undef LN_CAP_1

#define PRIM_CPC VEC_OBJ_T(TgSTRI,CPC)
#define VGM(A) FCN_VO(tgGM_ST_##A)
#define VCO_F(A) FCN_VO(tgCO_F_ST_##A)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Clip [Template].c_inc"
#undef VCO_F
#undef VGM
#undef PRIM_CPC
