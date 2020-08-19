/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - API.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_X86_64_COMMON_BASE_API_INL)
#define TGS_X86_64_COMMON_BASE_API_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define BITFIELD_IMPL( CLASS, TYPE ) \
TgINLINE TgVOID tgBF_Set_Flag_##CLASS ( TYPE##_PCU ptyBF, TgUINT_F08_C uiFlag, TgBOOL_C bFlag ) { \
        TgERROR( uiFlag < sizeof(TYPE) * 8 ); \
        *ptyBF = (TYPE)((bFlag) ? (*ptyBF | ((TYPE)1<<uiFlag)) : (*ptyBF & ~((TYPE)1<<uiFlag))); \
    } \
TgINLINE TgVOID tgBF_Toggle_Flag_##CLASS ( TYPE##_PCU ptyBF, TgUINT_F08_C uiFlag ) { \
        TgERROR( uiFlag < sizeof(TYPE) * 8 ); \
        *ptyBF ^= (TYPE)((TYPE)1<<uiFlag); \
    } \
TgINLINE TgBOOL tgBF_Test_Flag_##CLASS ( TYPE##_CPCU ptyBF, TgUINT_F08_C uiFlag ) { \
        TgERROR( uiFlag < sizeof(TYPE) * 8 ); \
        return (((TYPE)0 != (*ptyBF & ((TYPE)1<<uiFlag)))); \
    } \
TgINLINE TgVOID tgBF_Reset_##CLASS ( TYPE##_PCU ptyBF ) { *ptyBF = (TYPE)0; }

BITFIELD_IMPL( U32, TgUINT_E32 )
BITFIELD_IMPL( U64, TgUINT_E64 )

#undef BITFIELD_IMPL


/* =============================================================================================================================================================================== */
#endif
