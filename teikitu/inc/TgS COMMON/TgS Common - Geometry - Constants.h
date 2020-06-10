/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry - Constants.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_GEOMETRY_CONSTANTS_H)
#define TGS_COMMON_GEOMETRY_CONSTANTS_H
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Constants                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- Enumerations ------------------------------------------------------------------------------------------------------------------------------------------------------------- */

TgTYPE_ENUM( ETgPRIMITIVE, TgSINT_F32,

    ETgPRIMITIVE_UNKNOWN = 0,

    /* 0D Objects in 3D, Points   */
    ETgPOINT,               /* VT */
    ETgPARTICLE,            /* PC */

    /* 1D Objects in 3D, Lines    */
    ETgLINE,                /* LN */
    ETgRAY,                 /* RY */
    ETgSEGMENT,             /* SG */

    /* 2D Objects in 2D, Surfaces */
    ETgRECTANGLE2D,         /* RT */
    ETgELLIPSE2D ,          /* EL */

    /* 2D Objects in 3D, Surfaces */
    ETgCIRCLE,              /* CI */
    ETgDISK,                /* DK */
    ETgELLIPSE,             /* EL */
    ETgPARALLELOGRAM,       /* PE */
    ETgPLANE,               /* PN */
    ETgRECTANGLE,           /* RT */
    ETgPTRI,                /* PT */
    ETgETRI,                /* ET */
    ETgCTRI,                /* CT */
    ETgSTRI,                /* ST */

    /* 3D Objects, Volumes        */
    ETgBOXAA,               /* BA */
    ETgBOX,                 /* BX */
    ETgCAPSULE,             /* CP */
    ETgCONE,                /* CE */
    ETgCYLINDER,            /* CY */
    ETgFRUSTRUM,            /* FT */
    ETgMESH_SIMPLE,         /* MS */
    ETgMESH_BVT,            /* MB */
    ETgMESH_BA,             /* MA */
    ETgSPHERE,              /* SP */
    ETgTETRAHEDRON,         /* TN */
    ETgTORUS,               /* TS */
    ETgTUBE,                /* TB */

    ETgPRIMITIVE_MAX
);


TgTYPE_ENUM( ETgSWEEP_TYPE, TgSINT_F32,
    ETgSWEEP_STATIC,                ETgSWEEP_LINEAR,                ETgSWEEP_ROTATIONAL
);

TgTYPE_ENUM( ETgFRUSTUM_PLANE, TgSINT_F32,
    ETgFRUSTUM_PLANE__NEAR,         ETgFRUSTUM_PLANE__FAR,          ETgFRUSTUM_PLANE__LEFT,         ETgFRUSTUM_PLANE__RIGHT,        ETgFRUSTUM_PLANE__TOP,
    ETgFRUSTUM_PLANE__BOTTOM,       ETgFRUSTUM_PLANE__MAX
);


/* ---- Constants ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */

TgEXTN TgFLOAT32_C                          KTgGM_CUBE_VERTEX[24];
TgEXTN TgUINT_F16_C                         KTgGM_CUBE_INDEX[36];

TgEXTN TgFLOAT32_C                          KTgGM_TETRAHEDRON_VERTEX[12];
TgEXTN TgUINT_F16_C                         KTgGM_TETRAHEDRON_INDEX[12];

TgEXTN TgFLOAT32_C                          KTgGM_OCTOGON_VERTEX[24];
TgEXTN TgUINT_F16_C                         KTgGM_OCTOGON_INDEX[24];

TgEXTN TgFLOAT32_C                          KTgGM_ICOSAHEDRON_VERTEX[96];
TgEXTN TgUINT_F16_C                         KTgGM_ICOSAHEDRON_INDEX[60];

TgEXTN TgFLOAT32_C                          KTgGM_ICOSAHEDRON_HEMI_VERTEX[160];
TgEXTN TgUINT_F16_C                         KTgGM_ICOSAHEDRON_HEMI_INDEX[108];


/* =============================================================================================================================================================================== */
#endif
