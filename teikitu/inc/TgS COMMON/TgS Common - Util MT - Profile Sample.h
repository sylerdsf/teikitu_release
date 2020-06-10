/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util MT - Profile Sample.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*   ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
#if !defined(TGS_COMMON_UTIL_MP_PROFILE_SAMPLE_H)
#define TGS_COMMON_UTIL_MP_PROFILE_SAMPLE_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_UTIL_MT_PROFILE_RECORD Profile Record
    @ingroup TGS_COMMON_UTILITY_MT
    @warning WARNING: Keep in mind that there is no guarantee (and in fact is unlikely) that the execution of a large amount of code will not be stalled by other thread processing
    taking the CPU context. Therefore, the timing reported by this process is more of a rough guide or framework since it only considers the time between the two markers (start,
    stop) and not the actual amount of time spent processing on the hardware.
    @note We use 16 bits to record the max depth (recursion) into the profile marker, and 48 bits (of a possible 64 bits) to record the the CPU cycle count | timer. Note that the
    system returns the relative count from process start.
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgTYPE_STRUCT(STg2_Profile_Record,)
{
    TgSINT_F64_A TgALIGN(TgCCL)              m_iRecord_DepthAndStart;
    TgUINT_E08                                  m_uiPad0[TgCCL - (8 % TgCCL)];
    TgSINT_F64_A                                m_iRecord_Idle_Total;
    TgUINT_E08                                  m_uiPad1[TgCCL - (8 % TgCCL)];
    TgSINT_F64_A                                m_iRecord_Sample_Total;
    TgUINT_E08                                  m_uiPad2[TgCCL - (8 % TgCCL)];

    TgFLOAT32                                   m_fReport_Sample;
    TgFLOAT32                                   m_fReport_Idle;
    TgFLOAT32                                   m_fReport_Total;
    TgUINT_E08                                  m_uiPad3[TgCCL - (12 % TgCCL)];
};


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/** @addtogroup TGS_COMMON_UTIL_MT_PROFILE_RECORD */
/** @{ */

                                            /** @brief Reset the current profile sample (clear it)
                                                @param[in,out] ARG Pointer to a profile record object */
TgINLINE TgVOID                             tgProfile_Sample_Reset( STg2_Profile_Record_PCU ARG );

                                            /** @brief Mark the start of a profile sample
                                                @param[in,out] ARG Pointer to a profile record object
                                                @return The current time value that was used */
TgINLINE TgSINT_F64                         tgProfile_Sample_Start( STg2_Profile_Record_PCU ARG );

                                            /** @brief Mark the end of a profile sample
                                                @param[in,out] ARG Pointer to a profile record object
                                                @return The current time value that was used */
TgINLINE TgSINT_F64                         tgProfile_Sample_Stop( STg2_Profile_Record_PCU  ARG );

                                            /** @brief Generate a report from the profile record
                                                @param[in,out] ARG Pointer to a profile record object */
TgINLINE TgVOID                             tgProfile_Sample_Report( STg2_Profile_Record_PCU ARG );

/** @} TGS_COMMON_UTIL_MT_PROFILE_RECORD */


/* =============================================================================================================================================================================== */
#endif
