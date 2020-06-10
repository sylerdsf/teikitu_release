/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry.c
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

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */
/*  File Local Data */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */

#define t0              0.5773502691896257645091487805019F
/* #define fPhi4           6.4721359549995793928183473374626F */
/* #define fRadiusRatio    1.7013016167040798643630809941259F */
#define f2              0.5257311121191336060256690848475F
#define f3              0.8506508083520399321815404970625F




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */
/*  Public Data                                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */

/* ---- TETRAHEDRON -------------------------------------------------------------------------------------------------------------------------------------------------------------- */

TgUINT_F16_C KTgGM_CUBE_INDEX[36] =
{
    0,1,2, 1,3,2, 4,6,5, 5,6,7, 0,5,1, 0,4,5, 2,7,6, 2,3,7, 0,6,4, 0,2,6, 1,7,3, 1,5,7
};

TgFLOAT32_C KTgGM_CUBE_VERTEX[24] =
{
    -0.5f,-0.5f,-0.5f, -0.5f,-0.5f, 0.5f, -0.5f, 0.5f,-0.5f, -0.5f, 0.5f, 0.5f, 0.5f,-0.5f,-0.5f, 0.5f,-0.5f, 0.5f, 0.5f, 0.5f,-0.5f, 0.5f, 0.5f, 0.5f,
};


/* ---- TETRAHEDRON -------------------------------------------------------------------------------------------------------------------------------------------------------------- */

TgUINT_F16_C KTgGM_TETRAHEDRON_INDEX[12] =
{
       0,3,6,     0,9,3,       6,3,9,      9,0,6
};

TgFLOAT32_C KTgGM_TETRAHEDRON_VERTEX[12] =
{
    t0,t0,t0,-t0,-t0,t0,-t0,t0,-t0,t0,-t0,-t0
};


/* ---- OCTOGON ------------------------------------------------------------------------------------------------------------------------------------------------------------------ */

TgUINT_F16_C KTgGM_OCTOGON_INDEX[24] =
{
      0,12,6,     6,12,3,     3,12,9,     9,12,0,     0,6,15,     6,3,15,     3,9,15,     9,0,15
};

TgFLOAT32_C KTgGM_OCTOGON_VERTEX[24] =
{
     1.f, 0.f, 0.f,
    -1.f, 0.f, 0.f,
     0.f, 1.f, 0.f,
     0.f,-1.f, 0.f,
     0.f, 0.f, 1.f,
     0.f, 0.f,-1.f
};


/* ---- ICOSAHEDRON -------------------------------------------------------------------------------------------------------------------------------------------------------------- */

TgUINT_F16_C KTgGM_ICOSAHEDRON_INDEX[60] =
{
     4, 8, 7,     4, 7, 9,     5, 6,11,     5,10, 6,     0, 4, 3,     0, 3, 5,     2, 7, 1,     2, 1, 6,     8, 0,11,     8,11, 1,
     9,10, 3,     9, 2,10,     8, 4, 0,    11, 0, 5,     4, 9, 3,     5, 3,10,     7, 8, 1,     6, 1,11,     7, 2, 9,     6,10, 2
};

TgFLOAT32_C KTgGM_ICOSAHEDRON_VERTEX[96] =
{/* XXXX, XXXX, XXXX, XXXX,         XXXX, XXXX, XXXX, XXXX, */
      f3,   f2, 0.0F, 1.0F,           f3,   f2, 0.0F, 0.0F,
     -f3,   f2, 0.0F, 1.0F,          -f3,   f2, 0.0F, 0.0F,
     -f3,  -f2, 0.0F, 1.0F,          -f3,  -f2, 0.0F, 0.0F,
      f3,  -f2, 0.0F, 1.0F,           f3,  -f2, 0.0F, 0.0F,

      f2, 0.0F,   f3, 1.0F,           f2, 0.0F,   f3, 0.0F,
      f2, 0.0F,  -f3, 1.0F,           f2, 0.0F,  -f3, 0.0F,
     -f2, 0.0F,  -f3, 1.0F,          -f2, 0.0F,  -f3, 0.0F,
     -f2, 0.0F,   f3, 1.0F,          -f2, 0.0F,   f3, 0.0F,

    0.0F,   f3,   f2, 1.0F,         0.0F,   f3,   f2, 0.0F,
    0.0F,  -f3,   f2, 1.0F,         0.0F,  -f3,   f2, 0.0F,
    0.0F,  -f3,  -f2, 1.0F,         0.0F,  -f3,  -f2, 0.0F,
    0.0F,   f3,  -f2, 1.0F,         0.0F,   f3,  -f2, 0.0F,
};


/* ---- ICOSAHEDRON_HEMI --------------------------------------------------------------------------------------------------------------------------------------------------------- */

TgUINT_F16_C KTgGM_ICOSAHEDRON_HEMI_INDEX[108] =
{
     /* Positive Cap */
      2, 6, 5, /* 0,P,0,*/
      3, 4, 7, /* 0,0,P,*/
      6, 0, 7, /* P,P,P,*/
      6, 7, 1, /* P,P,P,*/
      6, 2, 0, /* P,0,P,*/
      7, 0, 3, /* P,P,0,*/
      5, 6, 1, /* 0,P,P,*/
      4, 1, 7, /* 0,P,P,*/
      2, 8, 0,
      8, 3, 0,
      4, 9, 1,
      9, 5, 1,

     /* Negative Cap */
     12,15,16, /* 0,0,N,*/
     13,17,14, /* 0,N,0,*/
     16,17,11, /* N,N,N,*/
     16,10,17, /* N,N,N,*/
     12,16,11, /* 0,N,N,*/
     13,11,17, /* 0,N,N,*/
     15,10,16, /* 0,N,N,*/
     14,17,10, /* 0,N,N*/
     13,18,11,
     18,12,11,
     15,19,10,
     19,14,10,

     /* Tube Section */
      2,12, 8,
      8,12,18,
      8,18, 3,
      3,18,13,
      3,13, 4,
      4,13,14,
      4,14, 9,
      9,14,19,
      9,19, 5,
      5,19,15,
      5,15, 2,
      2,15,12,
};


TgFLOAT32_C KTgGM_ICOSAHEDRON_HEMI_VERTEX[160] =
{
     /* Positive Cap */
     f3,     f2, 0.0F, 1.0F,       f3,   f2,   0.0F, 0.0F,
    -f3,     f2, 0.0F, 1.0F,      -f3,   f2,   0.0F, 0.0F,
     f2,   0.0F,   f3, 1.0F,       f2,   0.0F, f3,   0.0F,
     f2,   0.0F,  -f3, 1.0F,       f2,   0.0F,-f3,   0.0F,
    -f2,   0.0F,  -f3, 1.0F,      -f2,   0.0F,-f3,   0.0F,
    -f2,   0.0F,   f3, 1.0F,      -f2,   0.0F, f3,   0.0F,
     0.0F,   f3,   f2, 1.0F,       0.0F, f3,   f2,   0.0F,
     0.0F,   f3,  -f2, 1.0F,       0.0F, f3,  -f2,   0.0F,
     0.5F, 0.0F, 0.0F, 1.0F,       1.0F, 0.0F, 0.0F, 0.0F,
    -0.5F, 0.0F, 0.0F, 1.0F,      -1.0F, 0.0F, 0.0F, 0.0F,

     /* Negative Cap */
    -f3,   -f2,  0.0F, 1.0F,      -f3,  -f2,   0.0F,  0.0F,
     f3,   -f2,  0.0F, 1.0F,       f3,  -f2,   0.0F,  0.0F,
     f2,   0.0F,   f3, 1.0F,       f2,   0.0F, f3,    0.0F,
     f2,   0.0F,  -f3, 1.0F,       f2,   0.0F,-f3,    0.0F,
    -f2,   0.0F,  -f3, 1.0F,      -f2,   0.0F,-f3,    0.0F,
    -f2,   0.0F,   f3, 1.0F,      -f2,   0.0F, f3,    0.0F,
     0.0F,  -f3,   f2, 1.0F,       0.0F,-f3,   f2,    0.0F,
     0.0F,  -f3,  -f2, 1.0F,       0.0F,-f3,  -f2,    0.0F,
     0.5F, 0.0F, 0.0F, 1.0F,       1.0F, 0.0F, 0.0F,  0.0F,
    -0.5F, 0.0F, 0.0F, 1.0F,      -1.0F, 0.0F, 0.0F,  0.0F,
};




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-. */

/* ---- tgGM_Primitive_To_String ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgCHAR_MB_P tgGM_Primitive_To_String( ETgPRIMITIVE_C enPM )
{
    switch (enPM)
    {
        case ETgPRIMITIVE_UNKNOWN:
        case ETgPRIMITIVE_MAX:
        default:
            return("UNKNOWN");

        case ETgPOINT: return("POINT");
        case ETgPARTICLE: return("PARTICLE");

        case ETgLINE: return("LINE");
        case ETgRAY: return("RAY");
        case ETgSEGMENT: return("SEGMENT");

        case ETgRECTANGLE2D: return("RECTANGLE2D");
        case ETgELLIPSE2D: return("ELLIPSE2D");

        case ETgCIRCLE: return("CIRCLE");
        case ETgDISK: return("DISK");
        case ETgELLIPSE: return("ELLIPSE");
        case ETgPARALLELOGRAM: return("PARALLELOGRAM");
        case ETgPLANE: return("PLANE");
        case ETgRECTANGLE: return("RECTANGLE");
        case ETgPTRI: return("PTRI");
        case ETgETRI: return("ETRI");
        case ETgCTRI: return("CTRI");
        case ETgSTRI: return("STRI");

        case ETgBOXAA: return("BOXAA");
        case ETgBOX: return("BOX");
        case ETgCAPSULE: return("CAPSULE");
        case ETgCONE: return( "CONE" );
        case ETgCYLINDER: return("CYLINDER");
        case ETgFRUSTRUM: return( "FRUSTRUM" );
        case ETgMESH_SIMPLE: return("MESH_SIMPLE");
        case ETgMESH_BVT: return("MESH_BVT");
        case ETgMESH_BA: return("MESH_BA");
        case ETgSPHERE: return("SPHERE");
        case ETgTETRAHEDRON: return( "TETRAHEDRON" );
        case ETgTORUS: return("TORUS");
        case ETgTUBE: return("TUBE");
    };
}


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

#define TEMPLATE__TEST_AND_UNLOAD_TEMPLATE_MACROS
#define TEMPLATE__VECTOR_DIM 4
#include "TgS Common - Geometry.c_inc"
