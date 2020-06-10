/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Ring 0 - Type.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_RING_0_TYPE_H)
#define TGS_RING_0_TYPE_H
#pragma once


/* == Ring 0 ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  System ID                                                                                                                                                                      */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* Common */
TgKI_DECLARE(STRING_TABLE_ID)
TgKI_DECLARE(STRING_DICT_ID)
TgKI_DECLARE(JOB_THREAD_ID)
TgKI_DECLARE(JOB_QUEUE_ID)
TgKI_DECLARE(EM_TE_FRM_ID)
TgKI_DECLARE(EM_TE_SEC_ID)
TgKI_DECLARE(CN_VAR_ID)
TgKI_DECLARE(CONFIG_ID)
TgKI_DECLARE(THREAD_ID)
TgKI_DECLARE(FILE_ID)
TgKI_DECLARE(FILE_FIND_ID)

#if TgCOMPILE__PROFILE
TgKI_DECLARE(PROFILE_ID)
TgKI_DECLARE(PROFILE_CALL_ID)
TgKI_DECLARE(PROFILE_TL_ID)
TgKI_DECLARE(PROFILE_TL_CALL_ID)
/*# TgCOMPILE__PROFILE */
#endif

TgKI_DECLARE(PATH_NAV_MESH_ID)
TgKI_DECLARE(PATH_ENTITY_ID)
TgKI_DECLARE(PATH_OBSTACLE_ID)

TgKI_DECLARE(PNS_OBJECT_ID)


/* =============================================================================================================================================================================== */
#endif
