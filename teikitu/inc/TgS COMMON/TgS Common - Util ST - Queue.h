/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util ST - Queue.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UTIL_ST_QUEUE_H)
#define TGS_COMMON_UTIL_ST_QUEUE_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_UTIL_ST_QUEUE Queue Container
    @ingroup TGS_COMMON_UTILITY_ST
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgTYPE_STRUCT(STg2_UT_ST__QU_Node,)
{
    STg2_UT_ST__QU_Node_P                       m_pNext_Node;
};

TgTYPE_STRUCT(STg2_UT_ST__QU,)
{
    STg2_UT_ST__QU_Node                         m_sNode;
    STg2_UT_ST__QU_Node_P                       m_psTail_Node;
};

TgCOMPILER_ASSERT( 8 == sizeof( STg2_UT_ST__QU_Node ), 1 );
TgCOMPILER_ASSERT( 16 == sizeof( STg2_UT_ST__QU ), 1 );


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- Queue -------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_UTIL_ST_QUEUE */
/** @{ */

                                            /** @brief Initialize a queue object
                                                @param[out] OUT Pointer to a queue object
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgINLINE TgRESULT                           tgCM_UT_ST__QU__Init( STg2_UT_ST__QU_PC OUT );

                                            /** @brief Free all resources used by the object and perform some sanity checks
                                                @param[in,out] ARG Pointer to a queue object */
TgINLINE TgVOID                             tgCM_UT_ST__QU__Free( STg2_UT_ST__QU_PC ARG );


                                            /** @brief Enqueue the node at ARG1 to the queue at ARG0
                                                @param[in,out] ARG0 Pointer to a queue object
                                                @param[in] ARG1 Pointer to a queue node */
TgINLINE TgVOID                             tgCM_UT_ST__QU__Enqueue( STg2_UT_ST__QU_PC ARG0, STg2_UT_ST__QU_Node_PC ARG1 );

                                            /** @brief Merge the queues, where ARG1 is added to ARG0
                                                @param[in,out] ARG0 Pointer to a queue object
                                                @param[in] ARG1 Pointer to a queue object */
TgINLINE TgVOID                             tgCM_UT_ST__QU__Merge( STg2_UT_ST__QU_PC ARG0, STg2_UT_ST__QU_PC ARG1 );

                                            /** @brief Dequeue a node from the queue
                                                @param[in,out] ARG Pointer to a queue object
                                                @return Pointer to the node that was dequeued, and nullptr otherwise */
TgINLINE STg2_UT_ST__QU_Node_P              tgCM_UT_ST__QU__Dequeue( STg2_UT_ST__QU_PC ARG );


                                            /** @brief Check to see if the queue object is empty
                                                @param[in] ARG Pointer to a queue object
                                                @return True if the queue is empty, and false otherwise */
TgINLINE TgBOOL                             tgCM_UT_ST__QU__Is_Empty( STg2_UT_ST__QU_PC ARG );

/** @} TGS_COMMON_UTIL_ST_QUEUE */


/* =============================================================================================================================================================================== */
#endif
