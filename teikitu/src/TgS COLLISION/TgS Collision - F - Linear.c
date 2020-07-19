/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Collision - F - Linear.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* ==== Linear - Point =========================================================================================================================================================== */
/**
    Segment Definition: G0(α) = P0 + α•D0 | α ε [ 0, 1]

   Derivation:
    Let the points of closest contact be Q0 = P0+γ•D0, and v = P1-Q0
    Geometrically we know that the vector connecting the two closest points of contact ( or the minimal distance vector ) must be perpendicular to the line.
    Thus, D0•v=0, D1•v=0, DS=P1-P0, v=P1-(P0+γ•D0)

        0 = D0_(P1-P0-γ•D0,DIM)
        0 = D0_(DS-γ•D0,DIM)
        0 = D0•DS-γ•D0•D0
        γ = D0•DS / D0•D0

   However, we know that γ ε [ 0, 1], generating three cases:
  
   [1] γ ε (-∞, 0) || γ = 0
      Distance: The distance between P0 and P1
         = (P1-P0)T_(P1-P0,DIM)
         = DS•DS

   [2] γ ε [ 0, 1] || γ = (DS•D0) / (D0•D0)
      Distance: The distance value would be || v ||.
         = || v || = v•v = (DS-γ•D0)T_(DS-γ•D0,DIM)
         = DS•DS + γ•γ•D0•D0 - 2•γ•DS•D0
         = DS•DS + γ_(γ•D0•D0 - 2•DS•D0,DIM)
         = DS•DS + γ_((DS•D0 / D0•D0,DIM)•D0•D0 - 2•DS•D0)
         = DS•DS + γ_(DS•D0 - 2•DS•D0,DIM)
         = DS•DS - γ_(DS•D0,DIM)

   [3] γ ε ( 1, ∞) || γ = 1
      Distance: The distance between P0+D0 and P1
         = (P1-P0-D0)T_(P1-P0-D0,DIM)
         = (DS-D0)T_(DS-D0,DIM)
         = DS•DS - 2•DS•D0 + D0•D0
*/


/* ==== Linear - Linear ========================================================================================================================================================== */
/**
    Segment Definition: G0(α) = P0 + α•D0 | α ε [ 0, 1]
    Segment Definition: G1(β) = P1 + β•D1 | β ε [ 0, 1]

   Derivation:
    Let the points of closest contact be Q0 = P0+γ•D0 and Q1 = P1+Φ•D1, and v = Q1-Q0
    Geometrically we know that the vector connecting the two closest points of contact ( or the minimal distance
      vector ) must be perpendicular to both lines.  Thus, D0•v=0, D1•v=0, DS=P1-P0, v=(P1+Φ•D1)-(P0+γ•D0)

        v = (P1+Φ•D1) - (P0+γ•D0)
          = P1 + Φ•D1 - P0 - γ•D0
          = P1 - P0 + Φ•D1 - γ•D0
          = DS + Φ•D1 - γ•D0

        0 = D0_(DS + Φ•D1 - γ•D0,DIM)               and     0 = D1_(DS + Φ•D1 - γ•D0,DIM)
        0 = (DS•D0) + Φ_(D0•D1,DIM) - γ_(D0•D0,DIM)     and     0 = (DS•D1) + Φ_(D1•D1,DIM) - γ_(D0•D1,DIM)
        γ = (DS•D0)/(D0•D0) + Φ_(D0•D1,DIM)/(D0•D0)     and     γ = (DS•D1)/(D0•D1) + Φ_(D1•D1,DIM)/(D0•D1)
        Φ = γ_(D0•D0,DIM)/(D0•D1) - (DS•D0)/(D0•D1)     and     Φ = γ_(D0•D1,DIM)/(D1•D1) - (DS•D1)/(D1•D1)

   Two equations, two unknowns - solving for the gamma and theta yields:

        0 = γ_(D0•D0,DIM)T_(D1•D1,DIM) - (DS•D0)T_(D1•D1,DIM) - γ_(D0•D1,DIM)T_(D0•D1,DIM) + (DS•D1)T_(D0•D1,DIM)
        0 = γ_((D0•D0,DIM)T_(D1•D1,DIM) - (D0•D1)T_(D0•D1,DIM)) + (DS•D1)T_(D0•D1,DIM) - (DS•D0)T_(D1•D1,DIM)
        γ = ((DS•D0)T_(D1•D1,DIM) - (DS•D1)T_(D0•D1,DIM)) / ((D0•D0)T_(D1•D1,DIM) - (D0•D1)T_(D0•D1,DIM))

        0 = Φ_(D1•D1,DIM)T_(D0•D0,DIM) + (DS•D1)T_(D0•D0,DIM) - Φ_(D0•D1,DIM)T_(D0•D1,DIM) - (DS•D0)T_(D0•D1,DIM)
        0 = Φ_((D1•D1,DIM)T_(D0•D0,DIM) - (D0•D1)T_(D0•D1,DIM)) + (DS•D1)T_(D0•D0,DIM) - (DS•D0)T_(D0•D1,DIM)
        Φ = ((DS•D0)T_(D0•D1,DIM) - (DS•D1)T_(D0•D0,DIM)) / ((D0•D0)T_(D1•D1,DIM) - (D0•D1)T_(D0•D1,DIM))

   If ((D0•D0)T_(D1•D1,DIM) - (D0•D1)T_(D0•D1,DIM)) < ε, the lines are parallel

   However, we know that γ ε [ 0, 1], Φ ε [ 0, 1], generating nine cases:

   [1] γ ε (-∞, 0) | Φ ε (-∞, 0)
      [A] DS•D0 ε ( 0, D0•D0) || γ = DS•D0 / D0•D0 | Φ = 0
           = (P1 - P0 - γ•D0)T_(P1 - P0 - γ•D0,DIM)
           = (DS - γ•D0)T_(DS - γ•D0,DIM)
           = (DS•DS) - 2•γ_(DS•D0,DIM) + γ•γ_(D0•D0,DIM)
           = (DS•DS) + 2_(DS•D0 / D0•D0,DIM)T_(DS•D0,DIM) + (DS•D0 / D0•D0)T_(DS•D0 / D0•D0,DIM)T_(D0•D0,DIM)
           = (DS•DS) - (DS•D0)T_(DS•D0,DIM) / (D0•D0)
           = (DS•DS) - γ_(DS•D0,DIM)
      [B] DS•D0 ε ( D0•D0, ∞) || γ = 1 | Φ = 0
           = (P1 - P0 - D0)T_(P1 - P0 - D0,DIM)
           = (DS - D0)T_(DS - D0,DIM)
           = (DS•DS) - 2_(DS•D0,DIM) + (D0•D0)
      [C] DS•D0 ε (-∞, 0), DS•D1 ε [ 0, ∞) || γ = 0 | Φ = 0
           = (P1 - P0)T_(P1 - P0,DIM)
           = (DS•DS)
      [D] DS•D0 ε (-∞, 0), DS•D1 ε (-DS•D1, 0) || γ = 0 | Φ = -DS•D1 / D1•D1
           = (P1 + Φ•D1 - P0)T_(P1 + Φ•D1 - P0,DIM)
           = (DS + Φ•D1)T_(DS + Φ•D1,DIM)
           = (DS•DS) + 2•Φ_(DS•D1,DIM) + Φ•Φ_(D1•D1,DIM)
           = (DS•DS) + 2•Φ_(DS•D1,DIM) + Φ_(-DS•D1 / D1•D1,DIM)T_(D1•D1,DIM)
           = (DS•DS) + Φ_(DS•D1,DIM)
      [E] DS•D0 ε (-∞, 0), DS•D1 ε (-∞,-D1•D1] || γ = 0 | Φ = 1
           = (P1 + D1 - P0)T_(P1 + D1 - P0,DIM)
           = (DS + D1)T_(DS + D1,DIM)
           = (DS•DS) + 2_(DS•D1,DIM) + (D1•D1)

   [2] γ ε (-∞, 0) | Φ ε [ 0, 1]
      [A] DS•D1 ε [ 0, ∞) || γ = 0 | Φ = 0
           Same as [1C]
      [B] DS•D1 ε (-D1•D1, 0) || γ = 0 | Φ = -DS•D1 / D1•D1
           Same as [1D]
      [C] DS•D1 ε (-∞,-D1•D1) || γ = 0 | Φ = 1
           Same as [1E]

   [3] γ ε (-∞, 0) | Φ ε ( 1, ∞)
      [A] DS•D0 ε [D0•D0 - D0•D1, ∞) || γ = 1 | Φ = 1
           = (P1 + D1 - P0 - D0)T_(P1 + D1 - P0 - D0,DIM)
           = (DS + D1 - D0)T_(DS + D1 - D0,DIM)
           = (DS•DS) + (DS•D1) - (DS•D0) + (DS•D1) + (D1•D1) - (D0•D1) - (DS•D0) - (D0•D1) + (D0•D0)
           = (DS•DS) + 2_(DS•D1,DIM) - 2_(D0•D1,DIM) - 2_(DS•D0,DIM) + (D0•D0) + (D1•D1)
      [B] DS•D0 ε (-D0•D1, D0•D0 - D0•D1) || γ = ((D0•D1) + (DS•D0)) / (D0•D0) | Φ = 1
           = (P1 + D1 - P0 - γ•D0)T_(P1 + D1 - P0 - γ•D0,DIM)
           = (DS + D1 - γ•D0)T_(DS + D1 - γ•D0,DIM)
           = (DS•DS) + 2_(DS•D1,DIM) + (D1•D1) - 2•γ_(D0•D1,DIM) - 2•γ_(DS•D0,DIM) + γ•γ_(D0•D0,DIM)
           = (DS•DS) + 2_(DS•D1,DIM) + (D1•D1) - γ_(2•(D0•D1,DIM) + 2_(DS•D0,DIM) - γ_(D0•D0,DIM))
           = (DS•DS) + 2_(DS•D1,DIM) + (D1•D1) - γ_(2•(D0•D1,DIM) + 2_(DS•D0,DIM) - (D0•D1) - (DS•D0))
           = (DS•DS) + 2_(DS•D1,DIM) + (D1•D1) - γ_((D0•D1,DIM) + (DS•D0))
           = (DS•DS) + 2_(DS•D1,DIM) + (D1•D1) - γ•γ_(D0•D0,DIM)
      [C] DS•D0 ε (-∞,-D0•D1) | DS•D1 ε ( 0, ∞) || γ = 0 | Φ = 0
           Same as [1C]
      [D] DS•D0 ε (-∞,-D0•D1) | DS•D1 ε (-D1•D1, 0) || γ = 0 | Φ = -DS•D1 / D1•D1
           Same as [1D]
      [E] DS•D0 ε (-∞,-D0•D1) | DS•D1 ε (-∞,-D1•D1) || γ = 0 | Φ = 1
           Same as [1E]

   [4] γ ε [ 0, 1] | Φ ε (-∞, 0)
      [A] DS•D0 ε (-∞, 0) || γ = 0 | Φ = 0
           Same as [1C]
      [B] DS•D0 ε [ 0, D0•D0] || γ = DS•D0 / D0•D0 | Φ = 0
           Same as [1A]
      [C] DS•D0 ε ( D0•D0, ∞) || γ = 1 | Φ = 0
           Same as [1B]

   [5] γ ε [ 0, 1] | Φ ε [ 0, 1]
       Distance: The distance value would be || v ||.
         = || v || = v•v = (P1 + Φ•D1 - P0 - γ•D0)T_(P1 + Φ•D1 - P0 - γ•D0,DIM)
         = (DS + Φ•D1 - γ•D0)T_(DS + Φ•D1 - γ•D0,DIM)
         = (DS•DS) + 2•Φ_(DS•D1,DIM) - 2•γ_(DS•D0,DIM) + Φ•Φ_(D1•D1,DIM) - 2•γ•Φ_(D0•D1,DIM) + γ•γ_(D0•D0,DIM)
         = (DS•DS) + Φ_(Φ•(D1•D1,DIM) + 2_(DS•D1,DIM)) + γ_(γ•(D0•D0,DIM) - 2_(DS•D0,DIM)) - 2•γ•Φ_(D0•D1,DIM)

   [6] γ ε [ 0, 1] | Φ ε ( 1, ∞)
      [A] DS•D0 ε [D0•D0 - D0•D1, ∞) || γ = 1 | Φ = 1
           Same as [3A]
      [B] DS•D0 ε (-D0•D1, D0•D0 - D0•D1) || γ = ((D0•D1) + (DS•D0)) / (D0•D0) | Φ = 1
           Same as [3B]
      [C] DS•D0 ε (-∞,-D0•D1) || γ = 0 | Φ = 1
           Same as [1E]

   [7] γ ε ( 1, ∞) | Φ ε (-∞, 0)
      [A] DS•D0 ε (-∞, 0) || γ = 0 | Φ = 0
           Same as [1C]
      [B] DS•D0 ε [ 0, D0•D0) || γ = DS•D0 / D0•D0 | Φ = 0
           Same as [1A]
      [C] DS•D0 ε ( D0•D0, ∞), DS•D1 ε ( D0•D1, ∞) || γ = 1 | Φ = 0
           Same as [1B]
      [D] DS•D0 ε ( D0•D0, ∞), DS•D1 ε ( D0•D1 - D1•D1, D0•D1) || γ = 1 | Φ = ((D0•D1) - (DS•D1)) / (D1•D1)
           = (P1 + Φ•D1 - P0 - D0)T_(P1 + Φ•D1 - P0 - D0,DIM)
           = (DS + Φ•D1 - D0)T_(DS + Φ•D1 - D0,DIM)
           = (DS•DS) + 2•Φ_(DS•D1,DIM) + Φ•Φ_(D1•D1,DIM) - 2•Φ_(D0•D1,DIM) - 2_(DS•D0,DIM) + (D0•D0)
           = (DS•DS) + Φ_(2•(DS•D1,DIM) - 2_(D0•D1,DIM) + Φ_(D1•D1,DIM)) - 2_(DS•D0,DIM) + (D0•D0)
           = (DS•DS) + Φ_((DS•D1,DIM) - (D0•D1)) - 2_(DS•D0,DIM) + (D0•D0)
           = (DS•DS) - Φ•Φ_(D1•D1,DIM) - 2_(DS•D0,DIM) + (D0•D0)
      [E] DS•D0 ε ( D0•D0, ∞), DS•D1 ε (-∞, D0•D1 - D1•D1) || γ = 1 | Φ = 1
           Same as [3A]

   [8] γ ε ( 1, ∞) | Φ ε [ 0, 1]
      [A] DS•D1 ε ( D0•D1, ∞) || γ = 1 | Φ = 0
           Same as [1B]
      [B] DS•D1 ε ( D0•D1 - D1•D1, D0•D1) || γ = 1 | Φ = ((D0•D1) - (DS•D1)) / (D1•D1)
           Same as [7D]
      [C] DS•D1 ε (-∞, D0•D1 - D1•D1) || γ = 1 | Φ = 1
           Same as [3A]

   [9] γ ε ( 1, ∞) | Φ ε ( 1, ∞)
      [A] DS•D0 ε [-D0•D1, D0•D0-D0•D1] || γ = ((D0•D1) + (DS•D0)) / (D0•D0) | Φ = 1
           Same as [3B]
      [B] DS•D0 ε (-∞,-D0•D1) || γ = 0 | Φ = 1
           Same as [1E]
      [C] DS•D0 ε ( D0•D0-D0•D1, ∞), DS•D1 ε ( D0•D1, ∞) || γ = 1 | Φ = 0
           Same as [1B]
      [D] DS•D0 ε ( D0•D0-D0•D1, ∞), DS•D1 ε ( D0•D1 - D1•D1, D0•D1) || γ = 1 | Φ = ((D0•D1) - (DS•D1)) / (D1•D1)
           Same as [7D]
      [E] DS•D0 ε ( D0•D0-D0•D1, ∞), DS•D1 ε (-∞, D0•D1 - D1•D1) || γ = 1 | Φ = 1
           Same as [3A]

   -- Parallel Segments --

   [1] D0•D1 ε (-∞, 0)
      [A] DS•D0 ε ( D0•D0-D0•D1, ∞) || γ = 1 | Φ = 1
           Same as [3A]
      [B] DS•D0 ε ( D0•D0, D0•D0-D0•D1] || γ = 1 | Φ = ((D0•D0) - (DS•D0)) / (D0•D1)
           = (P1 + Φ•D1 - P0 - D0)T_(P1 + Φ•D1 - P0 - D0,DIM)
           = (DS + Φ•D1 - D0)T_(DS + Φ•D1 - D0,DIM)
           = (DS•DS) + 2•Φ_(DS•D1,DIM) + Φ•Φ_(D1•D1,DIM) - 2•Φ_(D0•D1,DIM) - 2_(DS•D0,DIM) + (D0•D0)
           = (DS•DS) + 2•Φ_(DS•D1,DIM) + Φ•Φ_(D1•D1,DIM) - 2_((D0•D0,DIM) - (DS•D0)) - 2_(DS•D0,DIM) + (D0•D0)
           = (DS•DS) + 2•Φ_(DS•D1,DIM) + Φ•Φ_(D1•D1,DIM) - 2_(D0•D0,DIM) + 2_(DS•D0,DIM) - 2_(DS•D0,DIM) + (D0•D0)
           = (DS•DS) + 2•Φ_(DS•D1,DIM) + Φ•Φ_(D1•D1,DIM) - (D0•D0)
      [C] DS•D0 ε ( 0, D0•D0] || γ = DS•D0 / D0•D0 | Φ = 0
           Same as [1A]
      [D] DS•D0 ε (-∞, 0) || γ = 0 | Φ = 0
           Same as [1C]

   [2] D0•D1 ε [ 0, ∞)
      [A] DS•D0 ε [ D0•D0, ∞) || γ = 1 | Φ = 0
           Same as [1B]
      [C] DS•D0 ε (-D0•D1, D0•D0) || γ = 0 | Φ = -DS•D0 / D0•D1
           = (P1 + Φ•D1 - P0)T_(P1 + Φ•D1 - P0,DIM)
           = (DS + Φ•D1)T_(DS + Φ•D1,DIM)
           = (DS•DS) + 2•Φ_(DS•D1,DIM) + Φ•Φ_(D1•D1,DIM)
      [D] DS•D0 ε (-∞,-D0•D1] || γ = 0 | Φ = 1
           Same as [1E]
*/


/* == Collision ================================================================================================================================================================== */

#define LN_CAP_0 0
#define LN_CAP_1 0
    #define LN_CAP_2 0
    #define LN_CAP_3 0
    #define VPM(A,B) FCN_VO(A##_LR00_##B##_LR00)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2

    #define LN_CAP_2 1
    #define LN_CAP_3 0
    #define VPM(A,B) FCN_VO(A##_LR00_##B##_LR10)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2

    #define LN_CAP_2 1
    #define LN_CAP_3 1
    #define VPM(A,B) FCN_VO(A##_LR00_##B##_LR11)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2
#undef LN_CAP_1
#undef LN_CAP_0

#define LN_CAP_0 1
#define LN_CAP_1 0
    #define LN_CAP_2 0
    #define LN_CAP_3 0
    #define VPM(A,B) FCN_VO(A##_LR10_##B##_LR00)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2

    #define LN_CAP_2 1
    #define LN_CAP_3 0
    #define VPM(A,B) FCN_VO(A##_LR10_##B##_LR10)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2

    #define LN_CAP_2 1
    #define LN_CAP_3 1
    #define VPM(A,B) FCN_VO(A##_LR10_##B##_LR11)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2
#undef LN_CAP_1
#undef LN_CAP_0

#define LN_CAP_0 1
#define LN_CAP_1 1
    #define LN_CAP_2 0
    #define LN_CAP_3 0
    #define VPM(A,B) FCN_VO(A##_LR11_##B##_LR00)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2

    #define LN_CAP_2 1
    #define LN_CAP_3 0
    #define VPM(A,B) FCN_VO(A##_LR11_##B##_LR10)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2

    #define LN_CAP_2 1
    #define LN_CAP_3 1
    #define VPM(A,B) FCN_VO(A##_LR11_##B##_LR11)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Linear-Linear.c_inc"
    #include "TgS Collision - N - Linear-Linear.c_inc"
    #undef VPM
    #undef LN_CAP_3
    #undef LN_CAP_2
#undef LN_CAP_1
#undef LN_CAP_0
