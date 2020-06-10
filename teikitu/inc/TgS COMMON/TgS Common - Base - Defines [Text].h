/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - Defines [Text].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_DEFINES_TEXT_H)
#define TGS_COMMON_BASE_DEFINES_TEXT_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

CLANG_PRAGMA( system_header )

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  String Literals for Testing                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define KTgMB_LIT_TEST__ENGLISH             "Test"
#define KTgMB_LIT_TEST__JAPANESE            "\xe3\x83\x86\xe3\x82\xb9\xe3\x83\x88"
#define KTgMB_LIT_TEST__CHINESE_SIMPLIFIED  "\xe6\xb5\x8b\xe8\xaf\x95"
#define KTgMB_LIT_TEST__RUSSIAN             "\xd1\x82\xd0\xb5\xd1\x81\xd1\x82\xd0\xbe\xd0\xb2\xd0\xbe\xd0\xb5 \xd0\xb7\xd0\xb0\xd0\xb4\xd0\xb0\xd0\xbd\xd0\xb8\xd0\xb5"
#define KTgMB_LIT_TEST__BURMESE             "\xe1\x80\x85\xe1\x80\x99\xe1\x80\xba\xe1\x80\xb8\xe1\x80\x9e\xe1\x80\x95\xe1\x80\xba\xe1\x80\x99\xe1\x80\xbe\xe1\x80\xaf"
#define KTgMB_LIT_TEST__KOREAN              "\xed\x85\x8c\xec\x8a\xa4\xed\x8a\xb8"

#define KTgWC_LIT_TEST__ENGLISH             L"Test"
#define KTgWC_LIT_TEST__JAPANESE            L"\x30c6\x30b9\x30c8"
#define KTgWC_LIT_TEST__CHINESE_SIMPLIFIED  L"\x6d4b\x8bd5"
#define KTgWC_LIT_TEST__RUSSIAN             L"\x0442\x0435\x0441\x0442\x043e\x0432\x043e\x0435\x0020\x0437\x0430\x0434\x0430\x043d\x0438\x0435"
#define KTgWC_LIT_TEST__BURMESE             L"\x1005\x1019\x103a\x1038\x101e\x1015\x103a\x1019\x103e\x102f"
#define KTgWC_LIT_TEST__KOREAN              L"\xd14c\xc2a4\xd2b8"




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Unicode Macros                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgMACRO_IS_UTF08_MB_SEQ_START(A)    (0xC0 == ((A) & 0xC0))
#define TgMACRO_IS_UTF08_MB_SEQ(A)          (0x80 == ((A) & 0xC0))


/* =============================================================================================================================================================================== */
#endif
