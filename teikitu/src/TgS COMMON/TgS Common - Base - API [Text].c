/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - API [Text].c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#include "TgS Common - Base - API [Text].c_inc"


/* ---- tgTXT_Set_Local_Global --------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgTXT_Set_Local_Global( TgCHAR_NC_P mbzLocal )
{
    TgVERIFY( nullptr != setlocale( LC_ALL, mbzLocal ) );
}


/* ---- tgMBZ_Query_At ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgCHAR_MB_CP tgMBZ_Query_At( TgCHAR_MB_CP NONULL mbzARG, TgRSIZE nbyMaxARG, TgRSIZE uiARG_Index )
{
    TgPARAM_CHECK(nullptr != mbzARG);

    /* Fast forward the buffer by the requested offset */
    for (; *mbzARG && nbyMaxARG > 0; --nbyMaxARG, ++mbzARG)
    {
        if (!TgMACRO_IS_UTF08_MB_SEQ( *mbzARG ) || TgMACRO_IS_UTF08_MB_SEQ_START( *mbzARG ))
        {
            if (0 == uiARG_Index)
            {
                return (mbzARG);
            };
            --uiARG_Index;
        };
    };
    
    return (0 == uiARG_Index ? mbzARG : nullptr);
}


/* ---- tgMBZ_Query_Last --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgCHAR_MB_CP tgMBZ_Query_Last( TgCHAR_MB_CP NONULL mbzARG, TgRSIZE nbyMaxARG, TgRSIZE uiMaxRead )
{
    TgCHAR_MB_CP                        mbzARG_Last, mbzARG_Test;
    
    mbzARG_Last = nullptr;
    mbzARG_Test = nullptr;

    /* Read through to the end of the string, the given byte limit has been reached, or the maximum number of characters have been read */
    for (; *mbzARG && nbyMaxARG; --nbyMaxARG, ++mbzARG)
    {
        if (!TgMACRO_IS_UTF08_MB_SEQ( *mbzARG ) || TgMACRO_IS_UTF08_MB_SEQ_START( *mbzARG ))
        {
            if (0 == uiMaxRead)
            {
                break;
            };
            --uiMaxRead;
            mbzARG_Last = mbzARG_Test;
            mbzARG_Test = mbzARG;
        };
    };
    
    /* Keep in mind that the byte limit could stop in the middle of a multibyte character and in that case, use the last valid character to end the string */
    if ((mbzARG_Test != mbzARG) && (!TgMACRO_IS_UTF08_MB_SEQ( *mbzARG ) || TgMACRO_IS_UTF08_MB_SEQ_START( *mbzARG )))
    {
        mbzARG_Last = mbzARG_Test;
    };

    return (mbzARG_Last);
}


/* ---- tgMBZ_Query_End ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgCHAR_MB_CP tgMBZ_Query_End( TgCHAR_MB_CP NONULL mbzARG, TgRSIZE nbyMaxARG, TgRSIZE uiMaxRead )
{
    TgCHAR_MB_CP                        mbzARG_Last, mbzARG_End;
    
    /* Read through to the end of the string, or the given byte limit has been reached */
    mbzARG_Last = tgMBZ_Query_Last( mbzARG, nbyMaxARG, uiMaxRead );

    /* There was no last character - empty string */
    if (nullptr == mbzARG_Last)
    {
        return (mbzARG);
    };

    /* Test for the last character be a non-UTF8 sequence (a narrow byte character) */
    if (!TgMACRO_IS_UTF08_MB_SEQ( *mbzARG_Last ) && !TgMACRO_IS_UTF08_MB_SEQ_START( *mbzARG_Last ))
    {
        return (mbzARG_Last + 1);
    };

    nbyMaxARG -= (TgRSIZE)(mbzARG_Last - mbzARG);
    mbzARG_End = mbzARG_Last;

    /* For a UTF8 sequence, need to forward past all of the bytes that are part of the character */
    for (--nbyMaxARG, ++mbzARG_End; *mbzARG_End && nbyMaxARG; --nbyMaxARG, ++mbzARG_End)
    {
        if (!TgMACRO_IS_UTF08_MB_SEQ( *mbzARG_End ) || TgMACRO_IS_UTF08_MB_SEQ_START( *mbzARG_End ))
        {
            break;
        };
    };

    TgERROR(!TgMACRO_IS_UTF08_MB_SEQ( *mbzARG_End ) || TgMACRO_IS_UTF08_MB_SEQ_START( *mbzARG_End ));
    return (mbzARG_End);
}


/* ---- tgMBZ_To_Upper_Length_U08 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgMBZ_To_Upper_Length_U08( TgCHAR_MB_CP NONULL pIN, TgRSIZE nbyMaxIN )
{
    mbstate_t                           mbState0, mbState1; /* Internal C state for the conversion to a wide character */
    TgRSIZE                             nby08; /* Byte count consumed for the next character in the string */
    wchar_t                             wcsCode;
    TgRSIZE                             nbyBuffer_Required;
    TgCHAR_MB                           mbzTemp[16];

    TgPARAM_CHECK(nullptr != pIN && nbyMaxIN > 0);

    tgMM_Set_U08_0x00( &mbState0, sizeof mbState0 );
    tgMM_Set_U08_0x00( &mbState1, sizeof mbState1 );

    nbyBuffer_Required = 0;

    for (; nbyMaxIN ; pIN += nby08, nbyMaxIN -= nby08)
    {
        nby08 = mbrtowc( &wcsCode, pIN, nbyMaxIN, &mbState1 );

        /* Check for early termination and invalid states while processing the strings. */
        if (0 == nby08)
        {
            return (nbyBuffer_Required);
        };

        if (nby08 > KTgMAX_RSIZE)
        {
            return (KTgMAX_RSIZE);
        };

        wcsCode = towupper( wcsCode );
        nbyBuffer_Required += wcrtomb( mbzTemp, wcsCode, &mbState0 );
    };

    return (nbyBuffer_Required);
}


/* ---- tgMBZ_To_Lower_Length_U08 ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgMBZ_To_Lower_Length_U08( TgCHAR_MB_CP NONULL pIN, TgRSIZE nbyMaxIN )
{
    mbstate_t                           mbState0, mbState1; /* Internal C state for the conversion to a wide character */
    TgRSIZE                             nby08; /* Byte count consumed for the next character in the string */
    wchar_t                             wcsCode;
    TgRSIZE                             nbyBuffer_Required;
    TgCHAR_MB                           mbzTemp[16];

    TgPARAM_CHECK(nullptr != pIN && nbyMaxIN > 0);

    tgMM_Set_U08_0x00( &mbState0, sizeof mbState0 );
    tgMM_Set_U08_0x00( &mbState1, sizeof mbState1 );

    nbyBuffer_Required = 0;

    for (; nbyMaxIN ; pIN += nby08, nbyMaxIN -= nby08)
    {
        nby08 = mbrtowc( &wcsCode, pIN, nbyMaxIN, &mbState1 );

        /* Check for early termination and invalid states while processing the strings. */
        if (0 == nby08)
        {
            return (nbyBuffer_Required);
        };

        if (nby08 > KTgMAX_RSIZE)
        {
            return (KTgMAX_RSIZE);
        };

        wcsCode = towlower( wcsCode );
        nbyBuffer_Required += wcrtomb( mbzTemp, wcsCode, &mbState0 );
    };

    return (nbyBuffer_Required);
}

