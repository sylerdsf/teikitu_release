/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - API [Text].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_API_TEXT_H)
#define TGS_COMMON_BASE_API_TEXT_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_BASE_API_TEXT Text Functions
    @ingroup TGS_COMMON_BASE
    @details String - Traditional "C" style strings which are assumed to be encoded as either ASCII or in a wide character format. These are all assumed to be null-terminated
    without any bounds or error checking. (There is no way to validate the capacity or size of the memory allocated to the string.) The functionality is included primarily for
    backwards compatibility and for simple non-user interactions. It is heavily encouraged to use the text objects in all cases, and to provide full support for unicode encoding
    everywhere.
    @details Text - Multibyte text support - generally assumed to be UTF8, UTF16 or UTF32. However, the text object can store any text encoding that matches a "C" standard locale.
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @brief Used to describe both the character count and byte size of a string */
TgTYPE_STRUCT(STg1_Text_Length,)
{
    TgRSIZE                                     m_nuiCharacters;
    TgRSIZE                                     m_nbyCharacters;
};


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/** @addtogroup TGS_COMMON_BASE_API_TEXT */
/** @{ */

#include "TgS COMMON/TgS Common - Base - API [Text].h_inc"
#define TGS_COMMON_BASE_API_TEXT_HINC

                                            /** @brief Set the "C" runtime locale */
TgEXTN TgVOID                               tgTXT_Set_Local_Global( TgCHAR_NC_P );

                                            /** @brief Return a pointer to the location in the string where the ARG1 character begins
                                                @param[in] ARG0 String to be processed
                                                @param[in] ARG1 Maximum size in \b >bytes< of the string in ARG0
                                                @param[in] ARG2 Offset into the string as a count of \b >characters<
                                                @return Location in the array of the select character */
TgEXTN TgCHAR_MB_CP                         tgMBZ_Query_At( TgCHAR_MB_CPU ARG0, TgRSIZE ARG1, TgRSIZE ARG2 );

                                            /** @brief Return a pointer to the location in the string where the ARG1 character begins
                                                @param[in] ARG0 String to be processed
                                                @param[in] ARG1 Maximum size in \b >bytes< of the string in ARG0
                                                @param[in] ARG2 Offset into the string as a count of \b >characters<
                                                @return Location in the array of the select character */
TgINLINE TgCHAR_MB_P                        tgMBZ_Get_At( TgCHAR_MB_PU ARG0, TgRSIZE ARG1, TgRSIZE ARG2 );

                                            /** @brief Return a pointer to the last character in the string at ARG
                                                @param[in] ARG0 String to be processed
                                                @param[in] ARG1 Maximum size in \b >bytes< of the string in ARG0
                                                @param[in] ARG2 Maximum number of \b >characters< to read 
                                                @return Location in the array of the last character, or nullptr if string is empty */
TgEXTN TgCHAR_MB_CP                         tgMBZ_Query_Last( TgCHAR_MB_CPU ARG0, TgRSIZE ARG1, TgRSIZE ARG2 );

                                            /** @brief Return a pointer to the last character in the string at ARG
                                                @param[in] ARG0 String to be processed
                                                @param[in] ARG1 Maximum size in \b >bytes< of the string in ARG0
                                                @param[in] ARG2 Maximum number of \b >characters< to read 
                                                @return Location in the array of the last character, or nullptr if string is empty */
TgINLINE TgCHAR_MB_P                        tgMBZ_Get_Last( TgCHAR_MB_PU ARG0, TgRSIZE ARG1, TgRSIZE ARG2 );

                                            /** @brief Return a pointer to the null terminator in the string at ARG
                                                @param[in] ARG0 String to be processed
                                                @param[in] ARG1 Maximum size in \b >bytes< of the string in ARG0
                                                @param[in] ARG2 Maximum number of \b >characters< to read 
                                                @return Location in the array of the null terminator */
TgEXTN TgCHAR_MB_CP                         tgMBZ_Query_End( TgCHAR_MB_CPU ARG0, TgRSIZE ARG1, TgRSIZE ARG2 );

                                            /** @brief Return a pointer to the null terminator in the string at ARG
                                                @param[in] ARG0 String to be processed
                                                @param[in] ARG1 Maximum size in \b >bytes< of the string in ARG0
                                                @param[in] ARG2 Maximum number of \b >characters< to read 
                                                @return Location in the array of the null terminator */
TgINLINE TgCHAR_MB_P                        tgMBZ_Get_End( TgCHAR_MB_PU ARG0, TgRSIZE ARG1, TgRSIZE ARG2 );

                                            /** @brief Output the begin and end pointers for a string region
                                                @param[in] ARG0 Pointer to a string location
                                                @param[in] ARG1 Pointer to a string location
                                                @param[in] ARG2 String to be processed
                                                @param[in] ARG3 Maximum size in \b >bytes< of the string in ARG2
                                                @param[in] ARG4 Offset into the string as a count of \b characters
                                                @param[in] ARG5 Maximum number of \b >characters< to be contained in the region
                                                @return Location in the array of the null terminator */
TgINLINE TgRESULT                           tgMBZ_Query_Region( TgCHAR_MB_CPP ARG0, TgCHAR_MB_CPP ARG1, TgCHAR_MB_CP ARG2, TgRSIZE ARG3, TgRSIZE ARG4, TgRSIZE ARG5 );

                                            /** @brief Output the begin and end pointers for a string region
                                                @param[in] ARG0 Pointer to a string location
                                                @param[in] ARG1 Pointer to a string location
                                                @param[in] ARG2 String to be processed
                                                @param[in] ARG3 Maximum size in \b >bytes< of the string in ARG2
                                                @param[in] ARG4 Offset into the string as a count of \b characters
                                                @param[in] ARG5 Maximum number of \b >characters< to be contained in the region
                                                @return Location in the array of the null terminator */
TgINLINE TgRESULT                           tgMBZ_Get_Region( TgCHAR_MB_PP ARG0, TgCHAR_MB_PP ARG1, TgCHAR_MB_P ARG2, TgRSIZE ARG3, TgRSIZE ARG4, TgRSIZE ARG5 );

                                            /** @brief Determine the number bytes needed to convert the string to upper case
                                                @param[in] ARG0 Source string for processing
                                                @param[in] ARG1 Maximum capacity of the string in ARG2
                                                @return Number of bytes needed for the conversion on success or KTgMAX_RSIZE otherwise */
TgEXTN TgRSIZE                              tgMBZ_To_Upper_Length_U08( TgCHAR_MB_CP ARG0, TgRSIZE ARG1 );

                                            /** @brief Determine the number bytes needed to convert the string to lower case
                                                @param[in] ARG0 Source string for processing
                                                @param[in] ARG1 Maximum capacity of the string in ARG2
                                                @return Number of bytes needed for the conversion on success or KTgMAX_RSIZE otherwise */
TgEXTN TgRSIZE                              tgMBZ_To_Lower_Length_U08( TgCHAR_MB_CP ARG0, TgRSIZE ARG1 );

/** @} */


/* =============================================================================================================================================================================== */
#endif
