/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Collision - F - Sphere.c
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

/*   Sphere Definition: |S(v) - C0| < R0                                                                                                                                           */
/*     Line Definition: L1(α) = P1 + α•D1 | α ε [ 0, 1]                                                                                                                            */
/*                                                                                                                                                                                 */
/* Derivation: Let C0 be the centre of sphere S0 with radius R0                                                                                                                    */
/*             Let L1 = P1 + α•D1 | α ε [ 0, 1]                                                                                                                                    */
/*             Let Q1 = P1 + γ•D1 by the closest point of contact                                                                                                                  */
/*             Let V = C0 - Q1, the vector connecting the closest points of contact ( the minimal distance vector )                                                               */
/*                                                                                                                                                                                 */
/* Minimal distance vector, by definition must be perpendicular to the line.                                                                                                       */
/* Therefore, D1•v=0, DS=C0-P1, v=DS-γ•D1                                                                                                                                          */
/*                                                                                                                                                                                 */
/*      0 = D1_(DS-γ•D1,DIM)                                                                                                                                                       */
/*      0 = DS•D1-γ•D1•D1                                                                                                                                                          */
/*      γ = DS•D1 / D1•D1                                                                                                                                                          */
/*                                                                                                                                                                                 */
/* However, we know that γ ε [ 0, 1], generating three cases:                                                                                                                      */
/*                                                                                                                                                                                 */
/* [1] γ ε (-∞, 0) || γ = 0                                                                                                                                                        */
/*    Distance: The distance between P1 and C0                                                                                                                                     */
/*       = (C0-P1)T_(C0-P1,DIM)                                                                                                                                                    */
/*       = DS•DS                                                                                                                                                                   */
/*                                                                                                                                                                                 */
/* [2] γ ε [ 0, 1] || γ = (DS•D1) / (D1•D1)                                                                                                                                        */
/*    Distance: The distance value would be || v ||.                                                                                                                               */
/*       = || v || = v•v = (DS-γ•D1)T_(DS-γ•D1,DIM)                                                                                                                                */
/*       = DS•DS + γ•γ•D1•D1 - 2•γ•DS•D1                                                                                                                                           */
/*       = DS•DS + γ_(γ•D1•D1 - 2•DS•D1,DIM)                                                                                                                                       */
/*       = DS•DS + γ_((DS•D1 / D1•D1,DIM)•D1•D1 - 2•DS•D1)                                                                                                                         */
/*       = DS•DS + γ_(DS•D1 - 2•DS•D1,DIM)                                                                                                                                         */
/*       = DS•DS - γ_(DS•D1,DIM)                                                                                                                                                   */
/*                                                                                                                                                                                 */
/* [3] γ ε ( 1, ∞) || γ = 1                                                                                                                                                        */
/*    Distance: The distance between P1+D1 and C0                                                                                                                                  */
/*       = (C0-P1-D1)T_(C0-P1-D1,DIM)                                                                                                                                              */
/*       = (DS-D1)T_(DS-D1,DIM)                                                                                                                                                    */
/*       = DS•DS - 2•DS•D1 + D1•D1                                                                                                                                                 */
/*                                                                                                                                                                                 */
/*    Form a right-sided triangle.                                                                                                                                                 */
/*      (a) The hypotenuse is the sphere radius.                                                                                                                                   */
/*      (b) The known edge is the segment from the centre of the sphere to the closest point on the line.                                                                          */
/*      (c) The length of the remaining side (along L1) is the distance from the point of closest proximity and the                                                                */
/*          points of contact between the sphere and the line.                                                                                                                     */
/*                                                                                                                                                                                 */
/*                              .(C0)                                                      .(C0)                                                                                   */
/*                             /|\                                                        /|\                                                                                      */
/*                            / | \                                                      / | \                                                                                     */
/*                           /  |  \                                                    /  |  \                                                                                    */
/*                          /   |   \                                                  /   |   \                                                                                   */
/*                         /    |    \                                                /    |    \                                                                                  */
/*                        /(R0) |     \(R0)                                 (R0)     /     |     \      (R0)                                                                       */
/*                              |                                       .----.------/------.------\------.----> (D1)                                                               */
/*                              |                                      (P1) (Q2)   /      (Q1)     \    (Q3)                                                                       */
/*           .------------.-----.--------------> (D1)                             /        |        \                                                                              */
/*          (P1)         (Q2)  (Q1)                                              /(R0)     |         \(R0)                                                                         */
/*                                                                                                                                                                                 */
/*   Contact can not occur under the following conditions:                                                                                                                         */
/*    Given that the point on the line closest to the sphere centre is at γ = DS•D1 / D1•D1                                                                                        */
/*    The squared distance of Q1-C0 is φ = DS•DS - γ•γ•D1•D1 = DS•DS - γ_(DS•D1,DIM)                                                                                               */
/*    Thus, if DS•DS - γ_(DS•D1,DIM) > R0•R0, intersection can not occur.                                                                                                          */
/*   Otherwise: Intersection has definitely occurred.                                                                                                                              */
/*     By definition (sphere) it is known that                                                                                                                                     */
/*         R0•R0 = ||C0 - P1 - β•D1||, for β ε (-∞, ∞)                                                                                                                             */
/*               = ||DS - β•D1||                                                                                                                                                   */
/*             0 = β•β•D1•D1 - β•2•DS•D1 + DS•DS - R0•R0                                                                                                                           */
/*         Solving using the quadratic formula                                                                                                                                     */
/*             β = (2_(DS•D1,DIM) ± √(4_(DS•D1,DIM)T_(DS•D1,DIM) - 4_(D1•D1,DIM)(DS•DS - R0•R0))) / (2_(D1•D1,DIM))                                                                */
/*             β = ((DS•D1) ± √((DS•D1)T_(DS•D1,DIM) - (D1•D1)(DS•DS - R0•R0))) / (D1•D1)                                                                                          */
/*          If the discriminant ((DS•D1)T_(DS•D1,DIM) - (D1•D1)(DS•DS - R0•R0)) is zero, there is only                                                                             */
/*         one point of intersection                                                                                                                                               */
/*                                                                                                                                                                                 */
/*                                                                                                                                                                                 */
/*                                                                                                                                                                                 */
/* Derivation: Let C0 be the centre of sphere S0 with radius R0                                                                                                                    */
/*             Let L1 = P1 + α•D1 | α ε [ 0, 1]                                                                                                                                    */
/*                                                                                                                                                                                 */
/* R0² = |(P1 + α•D1) - C0|²                                                                                                                                                       */
/*     = ((P1-C0) + α•D1) • ((P1-C0) + α•D1)                                                                                                                                       */
/*     = (DS + α•D1)T_(DS + α•D1,DIM)                                                                                                                                              */
/*     = DS•DS + 2•α•D1•DS + α•α•D1•D1                                                                                                                                             */
/*                                                                                                                                                                                 */
/* Solve for α                                                                                                                                                                     */
/*     = (-2•D1•DS ± √(4_(D1•DS,DIM)T_(D1•DS,DIM) - 4•D1•D1•DS•DS)) / 2•D1•D1                                                                                                      */
/*     = (-D1•DS ± √((D1•DS)T_(D1•DS,DIM) - D1•D1•DS•DS)) / D1•D1                                                                                                                  */


/* Let S0 and S1 represent two spheres, with radius R0, R1, centers C0,C1 and velocities V0, V1 respectively.                                                                      */
/* W.O.L.O.G. Perform the following calculations within S0 frame of reference.                                                                                                     */
/* Assume the frame of reference in non-rotational (only translation).                                                                                                             */
/*                                                                                                                                                                                 */
/* SWEEP TEST                                                                                                                                                                      */
/*                                                                                                                                                                                 */
/* As with all sweep tests, an arbitrary body is chosen as the principal reference frame so that only the relative                                                                 */
/* motion of one of the bodies is relevant.  The solution is as follows,                                                                                                           */
/*  (1) Create a line (RV) using the centre of the second sphere and the vector of relative motion.                                                                                */
/*  (2) Form a right-sided triangle.                                                                                                                                               */
/*      (a) The hypotenuse is the sum of the sphere radii.                                                                                                                         */
/*      (b) The known side is the line from the centre of the first sphere to the closest point on line RV.                                                                        */
/*      (c) The length of the remaining side (along RV) is the distance from the point of closest proximity and the                                                                */
/*          point of first contact between the two spheres.                                                                                                                        */
/*                                                                                                                                                                                 */
/*                              .(C0)                                                                                                                                              */
/*                             /|\                                                                                                                                                 */
/*                            / | \                                                                                                                                                */
/*                           /  |  \                                                                                                                                               */
/*                          /   |   \                                                                                                                                              */
/*                         /    |    \                                                                                                                                             */
/*                        /(R0) |     \(R0)                                                                                                                                        */
/*          (R1)/    (R1)/      |                                                                                                                                                  */
/*             /        /       |                                                                                                                                                  */
/*            /        /        |                                                                                                                                                  */
/*           .--------.---------.--------------> (RV)                                                                                                                              */
/*          (C1)     (P1)      (P0)                                                                                                                                                */
/*                                                                                                                                                                                 */
/* Let RV = V1 - V0, the relative velocity of S1 in the frame of reference of S0                                                                                                   */
/* Let RV_N be the normalized RV vector, and RV_L the length of the original RV vector                                                                                             */
/* Let DS = C1 - C0, the vector joining the two sphere centers                                                                                                                     */
/* Let RS = R0+R1, the sum of the radii of the two spheres                                                                                                                         */
/*                                                                                                                                                                                 */
/* Test 1: Pre penetration - The spheres are in contact if DS•DS < RS•RS                                                                                                           */
/* Test 2: Movement - RV_L ~= 0, no contact takes place                                                                                                                            */
/* Test 3: Parallel - ψ = DS•RV_N                                                                                                                                                  */
/*   Contact can not occur under the following conditions:                                                                                                                         */
/*     [ψ > 0]          - Second sphere is moving away from the first sphere                                                                                                       */
/*     [ψ < -(RV_L+RS)] - Motion is insufficient for them to come within proximity                                                                                                 */
/* Test 4: Perpendicular - φ = DS - ψ•RV_N                                                                                                                                         */
/*   Contact can not occur under the following conditions:                                                                                                                         */
/*     [φ•φ > RS•RS] - The sphere path does not bring them within proximity                                                                                                        */
/* Result: Υ = RS•RS - φ•φ, ζ = ψ + √Υ                                                                                                                                             */
/*   [ζ < RV_L] - The two sphere's contact at (ζ / RV_L) of the complete path of motion.                                                                                           */




#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Sphere-Plane.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Sphere-Point.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Sphere-Sphere.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Sphere-Triangle.c_inc"

#define LN_CAP_0 0
#define LN_CAP_1 0
#define VI2(A,B) FCN_VO(A##00_##B)
#define VI(A) FCN_VO(A##00)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Sphere-Linear.c_inc"
#undef VI
#undef VI2
#undef LN_CAP_0
#undef LN_CAP_1

#define LN_CAP_0 1
#define LN_CAP_1 0
#define VI2(A,B) FCN_VO(A##10_##B)
#define VI(A) FCN_VO(A##10)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Sphere-Linear.c_inc"
#undef VI
#undef VI2
#undef LN_CAP_0
#undef LN_CAP_1

#define LN_CAP_0 1
#define LN_CAP_1 1
#define VI2(A,B) FCN_VO(A##11_##B)
#define VI(A) FCN_VO(A##11)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Sphere-Linear.c_inc"
#undef VI
#undef VI2
#undef LN_CAP_0
#undef LN_CAP_1

#define PRIM_CPC VEC_OBJ_T(TgSPHERE,CPC)
#define VGM(A) FCN_VO(tgGM_SP_##A)
#define VCO_F(A) FCN_VO(tgCO_F_SP_##A)
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Clip [Template].c_inc"
#undef VCO_F
#undef VGM
#undef PRIM_CPC
