/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util MT - Stack.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UTIL_MP_ST_H)
#define TGS_COMMON_UTIL_MP_ST_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_UTIL_MT_STACK Stack Container
    @ingroup TGS_COMMON_UTILITY_MT
*/

    /** @defgroup TGS_COMMON_UTIL_MT_STACK_LOCKFREE Stack Container using Lock-free Synchronization
        @ingroup TGS_COMMON_UTIL_MT_STACK
        @note This implementation is not entirely "correct".  It can not guarantee perfect ordering.  Imagine two threads attempting an insert into the stack, with the first
        thread being the earlier arrival.  If the first thread were preempted during its insertion then the second thread would succeed in pushing onto the stack prior to the
        completion of the first thread.
    */

    /** @defgroup TGS_COMMON_UTIL_MT_STACK_MUTEX Stack Container using a Mutex
        @ingroup TGS_COMMON_UTIL_MT_STACK
    */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- STg2_UT_LF__ST ----------------------------------------------------------------------------------------------------------------------------------------------------------- */

TgTYPE_STRUCT(STg2_UT_ST__ST_Node,)
{
    TgVOID_P                                    m_pNext_Node;
};

TgTYPE_STRUCT(STg2_UT_ST__PTR_TKT,)
{
    STg2_UT_ST__ST_Node_P TgALIGN(16)           m_pHead;
    TgRSIZE                                     m_uiTicket; /**< OP Count to avoid ABA issues */
};
TgTYPE_MODIFIER_ATOMIC( STg2_UT_ST__PTR_TKT );

TgTYPE_STRUCT(STg2_UT_LF__ST,)
{
    STg2_UT_ST__PTR_TKT_A                       m_sTop;
};

TgTYPE_STRUCT(STg2_UT_LF_ISO__ST,)
{
    STg2_UT_LF__ST TgALIGN(TgCCL)               m_sStack;
    TgUINT_E08                                  m_uiPad[TgCCL - (16 % TgCCL)];
};

TgCOMPILER_ASSERT( 16 == sizeof( STg2_UT_LF__ST ), 0 );
TgCOMPILER_ASSERT( 0 == sizeof( STg2_UT_LF_ISO__ST ) % TgCCL, 0 ) ;


/* ---- STg2_UT_MT__ST_MX -------------------------------------------------------------------------------------------------------------------------------------------------------- */

#define SIZE_STg2_UT_MT__ST_MX (SIZE_STg1_MT_MX + SIZE_STg1_MT_SM + TgCOMPILE_POINTER_SIZE)
TgCOMPILER_ASSERT( 96 == SIZE_STg2_UT_MT__ST_MX, 0 );

TgTYPE_STRUCT(STg2_UT_MT__ST_MX,)
{
    STg1_MT_MX                                  m_sLock;
    STg1_MT_SM                                  m_sStack_Count;
    STg2_UT_ST__ST_Node_P                       m_psTop_Node;
    TgUINT_E08                                  m_uiPad[TgCCL - (SIZE_STg2_UT_MT__ST_MX % TgCCL)];
};

TgTYPE_STRUCT(STg2_UT_MT_ISO__ST_MX,)
{
    STg2_UT_MT__ST_MX TgALIGN(TgCCL)            m_sStack;
#if (SIZE_STg2_UT_MT__ST_MX < TgCCL)
    TgUINT_E08                                  m_uiPad[TgCCL - (SIZE_STg2_UT_MT__ST_MX % TgCCL)];
/*# (SIZE_STg2_UT_MT__ST_MX < TgCCL) */
#endif
};

TgCOMPILER_ASSERT( 128 == sizeof( STg2_UT_MT__ST_MX ), 0 );
TgCOMPILER_ASSERT( 0 == sizeof( STg2_UT_MT_ISO__ST_MX ) % TgCCL, 0 ) ;


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- Atomic Stack ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_UTIL_MT_STACK_LOCKFREE */
/** @{ */

                                            /** @brief Initialize a stack container
                                                @param[out] OUT Pointer to a stack object */
TgINLINE TgVOID                             tgCM_UT_LF__ST__Init( STg2_UT_LF__ST_PCU OUT );

                                            /** @brief Initialize a stack container filled with the given stack nodes
                                                @param[out] OUT0 Pointer to a stack object
                                                @param[in,out] ARG1 Pointer to the beginning range of elements to place into the stack
                                                @param[in,out] ARG2 Stride of the stack element
                                                @param[in,out] ARG3 Number of elements in the memory range */
TgINLINE TgVOID                             tgCM_UT_LF__ST__Init_PreLoad( STg2_UT_LF__ST_PCU OUT0, TgVOID_P ARG1, TgRSIZE_C ARG2, TgRSIZE_C ARG3 );

                                            /** @brief Free all resources used by the object and perform some sanity checks
                                                @param[in,out] ARG Pointer to a stack object */
TgINLINE TgVOID                             tgCM_UT_LF__ST__Free( STg2_UT_LF__ST_PCU ARG );


                                            /** @brief Insert the element at ARG1 at the top of the stack
                                                @param[in,out] ARG0 Pointer to a stack object
                                                @param[in] ARG1 Pointer to a stack element */
TgINLINE TgVOID                             tgCM_UT_LF__ST__Push( STg2_UT_LF__ST_PCU ARG0, STg2_UT_ST__ST_Node_PCU ARG1 );


                                            /** @brief Remove the top element from the stack, return it, if able to acquire the synchronization lock
                                                @param[in,out] ARG Pointer to a stack object
                                                @return The removed node or nullptr otherwise */
TgINLINE STg2_UT_ST__ST_Node_P              tgCM_UT_LF__ST__Pop( STg2_UT_LF__ST_PCU ARG );

                                            /** @brief Remove the top element from the stack, return it, once the synchronization lock is acquired
                                                @param[in,out] ARG Pointer to a stack object
                                                @return The removed node or nullptr otherwise */
TgINLINE STg2_UT_ST__ST_Node_P              tgCM_UT_LF__ST__Pop_Wait_Yield( STg2_UT_LF__ST_PCU ARG );

                                            /** @brief Remove the top element from the stack, return it, once the synchronization lock is acquired
                                                @param[in,out] ARG Pointer to a stack object
                                                @return The removed node or nullptr otherwise */
TgINLINE STg2_UT_ST__ST_Node_P              tgCM_UT_LF__ST__Pop_Wait_Spin( STg2_UT_LF__ST_PCU ARG );


                                            /** @brief Return if the stack is empty
                                                @param[in,out] ARG Pointer to a stack object
                                                @return True if the stack is empty, and false otherwise */
TgINLINE TgBOOL                             tgCM_UT_LF__ST__Is_Empty( STg2_UT_LF__ST_PCU ARG );


                                            /** @brief Pop (clear) the entire stack returning the former stack head
                                                @param[in,out] ARG Pointer to a stack object
                                                @return The former head of the stack, and nullptr otherwise */
TgINLINE STg2_UT_ST__ST_Node_P              tgCM_UT_LF__ST__Release( STg2_UT_LF__ST_PCU ARG );


                                            /** @brief Push (append) an entire list of notes [ARG1,ARG2) onto the stack
                                                @param[in,out] ARG0 Pointer to a stack object
                                                @param[in] ARG1 Pointer to start of region to merge
                                                @param[in] ARG2 Pointer to end of region to merge */
TgINLINE TgVOID                             tgCM_UT_LF__ST__Merge( STg2_UT_LF__ST_PCU ARG0, STg2_UT_ST__ST_Node_P ARG1, STg2_UT_ST__ST_Node_P ARG2 );

/** @} TGS_COMMON_UTIL_MT_STACK_LOCKFREE */


/* ---- Critical Section Stack --------------------------------------------------------------------------------------------------------------------------------------------------- */

#if TgCOMPILE__THREAD
/** @addtogroup TGS_COMMON_UTIL_MT_STACK_MUTEX */
/** @{ */

                                            /** @brief Initialize a stack container and mutex for synchronization
                                                @param[out] OUT0 Pointer to a stack object
                                                @param[in] ARG1 Name for the operating system mutex */
TgINLINE TgVOID                             tgCM_UT_MT__ST_MX__Init( STg2_UT_MT__ST_MX_PCU OUT0, TgCHAR_MB_CPCU ARG1 );

                                            /** @brief Release the mutex and perform any needed validation
                                                @param[in,out] ARG Pointer to a stack object */
TgINLINE TgVOID                             tgCM_UT_MT__ST_MX__Free( STg2_UT_MT__ST_MX_PCU ARG );


                                            /** @brief Insert the element at ARG1 at the top of the stack 
                                                @param[in,out] ARG0 Pointer to a stack object
                                                @param[in] ARG1 Pointer to a stack node */
TgINLINE TgVOID                             tgCM_UT_MT__ST_MX__Push( STg2_UT_MT__ST_MX_PCU ARG0, STg2_UT_ST__ST_Node_PCU ARG1 );


                                            /** @brief Remove the top element from the stack, return it, if able to acquire the synchronization lock
                                                @param[in,out] ARG Pointer to a stack object
                                                @return The removed node */
TgINLINE STg2_UT_ST__ST_Node_P              tgCM_UT_MT__ST_MX__Pop( STg2_UT_MT__ST_MX_PCU ARG );


                                            /** @brief Remove the top element from the stack, return it, once the synchronization lock is acquired
                                                @param[in,out] ARG Pointer to a stack object
                                                @return The removed node */
TgINLINE STg2_UT_ST__ST_Node_P              tgCM_UT_MT__ST_MX__Pop_Wait_Block( STg2_UT_MT__ST_MX_PCU ARG );


                                            /** @brief Return if the stack is empty
                                                @param[in,out] ARG Pointer to a stack object
                                                @return True if the stack is empty, and false otherwise */
TgINLINE TgBOOL                             tgCM_UT_MT__ST_MX__Is_Empty( STg2_UT_MT__ST_MX_PCU ARG );

/** @} TGS_COMMON_UTIL_MT_STACK_MUTEX */


/*# TgCOMPILE__THREAD */
#endif


/* =============================================================================================================================================================================== */
#endif
