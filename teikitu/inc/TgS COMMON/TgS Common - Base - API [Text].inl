/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - API [Text].inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_API_TEXT_INL)
#define TGS_COMMON_BASE_API_TEXT_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#include "TgS COMMON/TgS Common - Base - API [Text].i_inc"
#define TGS_COMMON_BASE_API_TEXT_IINC


/* ---- tgMBZ_Get_At ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgCHAR_MB_P tgMBZ_Get_At( TgCHAR_MB_P NONULL mbzARG, TgRSIZE nbyMaxARG, TgRSIZE uiIndex )
{
    TgCHAR_MB_CP                        mbzARG_Ret;
    
    mbzARG_Ret = tgMBZ_Query_At( mbzARG, nbyMaxARG, uiIndex );
    if (nullptr == mbzARG_Ret)
    {
        return (nullptr);
    };
    
    return (mbzARG + (mbzARG_Ret - mbzARG));
}


/* ---- tgMBZ_Get_Last ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgCHAR_MB_P tgMBZ_Get_Last( TgCHAR_MB_P NONULL mbzARG, TgRSIZE nbyMaxARG, TgRSIZE uiMaxRead )
{
    TgCHAR_MB_CP                        mbzARG_Ret;
    
    mbzARG_Ret = tgMBZ_Query_Last( mbzARG, nbyMaxARG, uiMaxRead );
    if (nullptr == mbzARG_Ret)
    {
        return (nullptr);
    };
    
    return (mbzARG + (mbzARG_Ret - mbzARG));
}


/* ---- tgMBZ_Get_End ------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgCHAR_MB_P tgMBZ_Get_End( TgCHAR_MB_P NONULL mbzARG, TgRSIZE nbyMaxARG, TgRSIZE uiMaxRead )
{
    TgCHAR_MB_CP                        mbzARG_Ret;
    
    mbzARG_Ret = tgMBZ_Query_End( mbzARG, nbyMaxARG, uiMaxRead );
    if (nullptr == mbzARG_Ret)
    {
        return (nullptr);
    };
    
    return (mbzARG + (mbzARG_Ret - mbzARG));
}


/* ---- tgMBZ_Query_Region ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRESULT tgMBZ_Query_Region(
    TgCHAR_MB_CPP pmbzBegin, TgCHAR_MB_CPP pmbzEnd, TgCHAR_MB_CP NONULL mbzARG_Start, TgRSIZE nbyMaxARG, TgRSIZE uiARG_Index, TgRSIZE uiMaxRegion )
{
    *pmbzBegin = tgMBZ_Query_At( mbzARG_Start, nbyMaxARG, uiARG_Index );
    if (nullptr == *pmbzBegin)
    {
        return (KTgE_FAIL);
    };

    *pmbzEnd = tgMBZ_Query_End( *pmbzBegin, nbyMaxARG - (TgRSIZE)(*pmbzBegin - mbzARG_Start), uiMaxRegion );

    return (KTgS_OK);
}


/* ---- tgMBZ_Get_Region --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRESULT tgMBZ_Get_Region(
    TgCHAR_MB_PP NONULL pmbzBegin, TgCHAR_MB_PP NONULL pmbzEnd, TgCHAR_MB_P NONULL mbzARG_Start, TgRSIZE nbyMaxARG, TgRSIZE uiARG_Index, TgRSIZE uiMaxRegion  )
{
    TgCHAR_MB_CP                        mbzBegin, mbzEnd;
    
    if (TgFAILED(tgMBZ_Query_Region( &mbzBegin, &mbzEnd, mbzARG_Start, nbyMaxARG, uiARG_Index, uiMaxRegion )))
    {
        return (KTgE_FAIL);
    };

    *pmbzBegin = mbzARG_Start + (TgRSIZE)(mbzBegin - mbzARG_Start);
    *pmbzEnd = mbzARG_Start + (TgRSIZE)(mbzEnd - mbzARG_Start);

    return (KTgS_OK);
}


/* =============================================================================================================================================================================== */
#endif
