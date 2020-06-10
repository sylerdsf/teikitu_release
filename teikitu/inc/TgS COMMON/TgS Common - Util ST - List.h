/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util ST - List.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UTIL_ST_LIST_H)
#define TGS_COMMON_UTIL_ST_LIST_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_UTIL_ST_LIST List Container
    @ingroup TGS_COMMON_UTILITY_ST
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgTYPE_STRUCT(STg2_UT_ST__LT_Node,)
{
    STg2_UT_ST__LT_Node_P                       m_pPrev_Node;
    STg2_UT_ST__LT_Node_P                       m_pNext_Node;
};

TgTYPE_STRUCT(STg2_UT_ST__LT,)
{
    STg2_UT_ST__LT_Node                         m_sNode;
};


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- Linked List -------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_UTIL_ST_LIST */
/** @{ */

                                            /** @brief Initialize a list container
                                                @param[out] OUT Pointer to a list object
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_ST__LT__Init( STg2_UT_ST__LT_PCU OUT );

                                            /** @brief Validates the list is empty
                                                @param[in,out] ARG Pointer to a list object */
TgINLINE TgVOID                             tgCM_UT_ST__LT__Free( STg2_UT_ST__LT_PCU ARG );


                                            /** @brief Insert the node at ARG1 to the front of queue at ARG0
                                                @param[in,out] ARG0 Pointer to a list object
                                                @param[in] ARG1 Pointer to a list node */
TgINLINE TgVOID                             tgCM_UT_ST__LT__Push_Front( STg2_UT_ST__LT_PCU ARG0, STg2_UT_ST__LT_Node_PC ARG1 );

                                            /** @brief Insert the node at ARG1 to the back of queue at ARG0
                                                @param[in,out] ARG0 Pointer to a list object
                                                @param[in] ARG1 Pointer to a list node */
TgINLINE TgVOID                             tgCM_UT_ST__LT__Push_Back( STg2_UT_ST__LT_PCU ARG0, STg2_UT_ST__LT_Node_PC ARG1 );


                                            /** @brief Remove the node at the front of the list, and return a pointer to it
                                                @param[in,out] ARG Pointer to a list object
                                                @return The node removed from the list */
TgINLINE STg2_UT_ST__LT_Node_P              tgCM_UT_ST__LT__Pop_Front( STg2_UT_ST__LT_PCU ARG );

                                            /** @brief Remove the node at the end of the list, and return a pointer to it
                                                @param[in,out] ARG Pointer to a list object
                                                @return The node removed from the list */
TgINLINE STg2_UT_ST__LT_Node_P              tgCM_UT_ST__LT__Pop_Back( STg2_UT_ST__LT_PCU ARG );


                                            /** @brief Insert the node at ARG1 after the node at ARG0
                                                @param[in,out] ARG0 Pointer to a list object
                                                @param[in] ARG1 Pointer to a list node */
TgINLINE TgVOID                             tgCM_UT_ST__LT__Insert( STg2_UT_ST__LT_Node_PC ARG0, STg2_UT_ST__LT_Node_PC ARG1 );

                                            /** @brief Remove the node at ARG from the list
                                                @param[in,out] ARG Pointer to a list object */
TgINLINE TgVOID                             tgCM_UT_ST__LT__Remove( STg2_UT_ST__LT_Node_PC ARG );


                                            /** @brief Check to see if the list is empty
                                                @param[in] ARG Pointer to a list object
                                                @return True if the list is empty, and false otherwise */
TgINLINE TgBOOL                             tgCM_UT_ST__LT__Is_Empty( STg2_UT_ST__LT_PCU ARG );

/** @} TGS_COMMON_UTIL_ST_LIST */


/* =============================================================================================================================================================================== */
#endif
