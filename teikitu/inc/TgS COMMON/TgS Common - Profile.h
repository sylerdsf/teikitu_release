/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Profile.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_PROFILE_H)
#define TGS_COMMON_PROFILE_H
#pragma once
#if TgCOMPILE__PROFILE


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_PROFILE Profiler
    @ingroup TGS_COMMON_COMMON
*/

    /** @defgroup TGS_COMMON_PROFILE_MODULE Module Functions
        @ingroup TGS_COMMON_PROFILE
    */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

enum { KTgMAX_PROFILE_ID                    =   128 };  /**< Maximum number of profile tags in the system */
enum { KTgMAX_PROFILE_CALL_ID               =  4096 };  /**< Maximum number of in-flight calls in the system */
enum { KTgMAX_PROFILE_NAME_LENGTH           =   128 };  /**< Maximum string length of a profile tag. */
enum { KTgMAX_PROFILE_TL_ID                 =    32 };  /**< Maximum number of thread local profile tags in the system */
enum { KTgMAX_PROFILE_TL_CALL_ID            =   256 };  /**< Maximum number of thread local in-flight calls in the system */

#define PFCAT(A,B)                          A##B
#define PFCAT5(A,B,C,D,E)                   A##B##C##D##E
#define PFSTR(A)                            #A

#define PROFILE_DEFINE(...)                 TgPROFILE_ID PFCAT(KTgPF_,__VA_ARGS__)
#define PROFILE_EXTERN(...)                 TgEXTN TgPROFILE_ID PFCAT(KTgPF_,__VA_ARGS__)
#define PROFILE_IS_INIT(...)                tgPROFILE_ID_Fetch_And_Is_Valid( nullptr, &PFCAT(KTgPF_,__VA_ARGS__) )
#define PROFILE_INIT(...)                   PFCAT(KTgPF_,__VA_ARGS__) = tgPF_Mark_Init( PFSTR(__VA_ARGS__) )
#define PROFILE_START(...)                  TgPROFILE_CALL_ID_C PFCAT5(profile_,__VA_ARGS__,call,__FUNC__,id) = tgPF_Mark_Start(PFCAT(KTgPF_,__VA_ARGS__))
#define PROFILE_STOP(...)                   tgPF_Mark_Stop( PFCAT(KTgPF_,__VA_ARGS__), PFCAT5(profile_,__VA_ARGS__,call,__FUNC__,id) )
#define PROFILE_RESET(...)                  tgPF_Mark_Reset( PFCAT(KTgPF_,__VA_ARGS__) )
#define PROFILE_NAME(...)                   tgPF_Query_Name( PFCAT(KTgPF_,__VA_ARGS__) )
#define PROFILE_TOTAL_TIME_CACHED(...)      tgPF_Query_Total_Time_Cached( PFCAT(KTgPF_,__VA_ARGS__) )

#define PROFILE_ARRAY_DEFINE(A,...)         TgPROFILE_ID PFCAT(KTgPF_,__VA_ARGS__)[A]
#define PROFILE_ARRAY_EXTERN(A,...)         TgEXTN TgPROFILE_ID PFCAT(KTgPF_,__VA_ARGS__)[A]
#define PROFILE_ARRAY_IS_INIT(A,...)        tgPROFILE_ID_Fetch_And_Is_Valid( nullptr, &PFCAT(KTgPF_,__VA_ARGS__) [A])
#define PROFILE_ARRAY_INIT(A,B,...)         PFCAT(KTgPF_,__VA_ARGS__)[A] = tgPF_Mark_Init(PFSTR(PFCAT(__VA_ARGS__,B)))
#define PROFILE_ARRAY_START(A,...)          TgPROFILE_CALL_ID_C PFCAT5(profile_,__VA_ARGS__,call,__FUNC__,id) = tgPF_Mark_Start(PFCAT(KTgPF_,__VA_ARGS__)[A])
#define PROFILE_ARRAY_STOP(A,...)           tgPF_Mark_Stop( PFCAT(KTgPF_,__VA_ARGS__)[A], PFCAT5(profile_,__VA_ARGS__,call,__FUNC__,id) )
#define PROFILE_ARRAY_RESET(A,...)          tgPF_Mark_Reset( PFCAT(KTgPF_,__VA_ARGS__)[A] )
#define PROFILE_ARRAY_NAME(A,...)           tgPF_Query_Name( PFCAT(KTgPF_,__VA_ARGS__)[A] )
#define PROFILE_ARRAY_TOTAL_TIME_CACHED(A,...) tgPF_Query_Total_Time_Cached( PFCAT(KTgPF_,__VA_ARGS__)[A] )

#define PROFILE_TL_DEFINE(...)              TgPROFILE_TL_ID PFCAT(KTgPF_,__VA_ARGS__)
#define PROFILE_TL_EXTERN(...)              TgEXTN TgPROFILE_TL_ID PFCAT(KTgPF_,__VA_ARGS__)
#define PROFILE_TL_IS_INIT(...)             tgPROFILE_TL_ID_Fetch_And_Is_Valid( nullptr, &PFCAT(KTgPF_,__VA_ARGS__) )
#define PROFILE_TL_INIT(...)                PFCAT(KTgPF_,__VA_ARGS__) = tgPF_TL_Mark_Init( PFSTR(__VA_ARGS__) )
#define PROFILE_TL_START(...)               TgPROFILE_CALL_TL_ID_C PFCAT5(profile_,__VA_ARGS__,call,__FUNC__,id) = tgPF_TL_Mark_Start(PFCAT(KTgPF_,__VA_ARGS__))
#define PROFILE_TL_STOP(...)                tgPF_TL_Mark_Stop( PFCAT(KTgPF_,__VA_ARGS__), PFCAT5(profile_,__VA_ARGS__,call,__FUNC__,id) )
#define PROFILE_TL_RESET(...)               tgPF_TL_Mark_Reset( PFCAT(KTgPF_,__VA_ARGS__) )
#define PROFILE_TL_NAME(...)                tgPF_TL_Query_Name( PFCAT(KTgPF_,__VA_ARGS__) )
#define PROFILE_TL_TOTAL_TIME_CACHED(...)   tgPF_TL_Query_Total_Time_Cached( PFCAT(KTgPF_,__VA_ARGS__) )


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* The profile system tracks time spent per call and on module update will aggregate values into a per-tag summary. */
/* Note: time spent in a profile tag across multiple threads will be collected correctly, but time spent on a single thread in a function recursively will not be correct */

/** @addtogroup TGS_COMMON_PROFILE_MODULE */
/** @{ */

TgEXTN TgRESULT                             tgPF_Init( TgVOID );
TgEXTN TgRESULT                             tgPF_Boot( TgVOID );
TgEXTN TgVOID                               tgPF_Stop( TgVOID );
TgEXTN TgVOID                               tgPF_Free( TgVOID );
TgEXTN TgRESULT                             tgPF_Update( TgFLOAT32_C );

TgEXTN TgRSIZE                              tgPF_Query_Fixed_Memory( TgVOID );

TgEXTN TgBOOL                               tgPF_Query_Init( TgVOID );
TgEXTN TgBOOL                               tgPF_Query_Boot( TgVOID );

/** @} TGS_COMMON_PROFILE_MODULE */


/** @addtogroup TGS_COMMON_PROFILE */
/** @{ */

                                            /** @brief Output a report of all the profile information
                                                @param[in] ARG Pointer to an output object  */
TgEXTN TgVOID                               tgPF_Report_Module( STg2_Output_PC ARG );


                                            /** @brief Initialize a new profile marker
                                                @param[in] ARG String to be associated with the profile marker
                                                @return A new profile marker identifier on success and the invalid identifier otherwise */
TgEXTN TgPROFILE_ID                         tgPF_Mark_Init( TgCHAR_MB_CPC ARG );

                                            /** @brief Start a new profile segment for this market
                                                @param[in] ARG A profile marker identifier
                                                @return An identifier for this specific profile segment (call) */
TgEXTN TgPROFILE_CALL_ID                    tgPF_Mark_Start( TgPROFILE_ID ARG );

                                            /** @brief Stop the profile segment (call) ARG1 for this marker
                                                @param[in] ARG0 A profile marker identifier
                                                @param[in] ARG1 A profile segment (call) identifier */
TgEXTN TgVOID                               tgPF_Mark_Stop( TgPROFILE_ID ARG0, TgPROFILE_CALL_ID ARG1 );

                                            /** @brief Reset the accumulated data for this marker
                                                @param[in] ARG A profile marker identifier */
TgEXTN TgVOID                               tgPF_Mark_Reset( TgPROFILE_ID ARG );


                                            /** @brief Return the name that was used when the marker was first initialized
                                                @param[in] ARG A profile marker identifier
                                                @return The name that was used when the marker was first initialized */
TgEXTN TgCHAR_MB_CP                         tgPF_Query_Name( TgPROFILE_ID ARG );

                                            /** @brief Return the total amount of time spent in the profile segment
                                                @param[in] ARG A profile marker identifier
                                                @return The total amount of time spent in the profile segment*/
TgEXTN TgFLOAT64                            tgPF_Query_Total_Time_Cached( TgPROFILE_ID ARG );

/** @} TGS_COMMON_PROFILE */


/* ---- Thread Local ------------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** @addtogroup TGS_COMMON_PROFILE_MODULE */
/** @{ */

TgEXTN TgRESULT                             tgPF_TL_Init( TgVOID );
TgEXTN TgRESULT                             tgPF_TL_Boot( TgVOID );
TgEXTN TgVOID                               tgPF_TL_Stop( TgVOID );
TgEXTN TgVOID                               tgPF_TL_Free( TgVOID );
TgEXTN TgRESULT                             tgPF_TL_Update( TgFLOAT32_C );

TgEXTN TgRSIZE                              tgPF_TL_Query_Fixed_Memory( TgVOID );

TgEXTN TgBOOL                               tgPF_TL_Query_Init( TgVOID );
TgEXTN TgBOOL                               tgPF_TL_Query_Boot( TgVOID );

/** @} TGS_COMMON_PROFILE_MODULE */


/** @addtogroup TGS_COMMON_PROFILE */
/** @{
                                                @brief Output a report of all the profile information recorded on this thread
                                                @param[in] ARG Pointer to an output object  */
TgEXTN TgVOID                               tgPF_TL_Report_Module( STg2_Output_PC ARG );


                                            /** @brief Initialize a new profile marker
                                                @param[in] ARG String to be associated with the profile marker
                                                @return A new profile marker identifier on success and the invalid identifier otherwise */
TgEXTN TgPROFILE_TL_ID                      tgPF_TL_Mark_Init( TgCHAR_MB_CPC ARG );

                                            /** @brief Start a new profile segment for this market
                                                @param[in] ARG A profile marker identifier
                                                @return An identifier for this specific profile segment (call) */
TgEXTN TgPROFILE_TL_CALL_ID                 tgPF_TL_Mark_Start( TgPROFILE_TL_ID ARG );

                                            /** @brief Stop the profile segment (call) ARG1 for this marker
                                                @param[in] ARG0 A profile marker identifier
                                                @param[in] ARG1 A profile segment (call) identifier */
TgEXTN TgVOID                               tgPF_TL_Mark_Stop( TgPROFILE_TL_ID ARG0, TgPROFILE_TL_CALL_ID ARG1 );

                                            /** @brief Reset the accumulated data for this marker
                                                @param[in] ARG A profile marker identifier */
TgEXTN TgVOID                               tgPF_TL_Mark_Reset( TgPROFILE_TL_ID ARG );


                                            /** @brief Return the name that was used when the marker was first initialized
                                                @param[in] ARG A profile marker identifier
                                                @return The name that was used when the marker was first initialized */
TgEXTN TgCHAR_MB_CP                         tgPF_TL_Query_Name( TgPROFILE_TL_ID ARG );

                                            /** @brief Return the total amount of time spent in the profile segment
                                                @param[in] ARG A profile marker identifier
                                                @return The total amount of time spent in the profile segment*/
TgEXTN TgFLOAT64                            tgPF_TL_Query_Total_Time_Cached( TgPROFILE_TL_ID ARG );

/** @} TGS_COMMON_PROFILE */


/*# TgCOMPILE__PROFILE */
#else

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Profile System Disabled */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define PFCAT(a,b)                          a##b

#define PROFILE_DEFINE(tag)                 UNUSED_TYPE TgSINT_F32 PFCAT(TgNOT_USED__, tag)
#define PROFILE_EXTERN(tag)                 TgEXTN TgSINT_F32 PFCAT(TgNOT_USED__, tag)
#define PROFILE_IS_INIT(tag)                false
#define PROFILE_INIT(tag)
#define PROFILE_START(tag)
#define PROFILE_STOP(tag)
#define PROFILE_RESET(tag)

#define PROFILE_ARRAY_DEFINE(A,...)         UNUSED_TYPE TgSINT_F32 PFCAT(TgNOT_USED_ARRAY__, __VA_ARGS__)
#define PROFILE_ARRAY_EXTERN(A,...)         TgEXTN TgSINT_F32 PFCAT(TgNOT_USED_ARRAY__, __VA_ARGS__)
#define PROFILE_ARRAY_IS_INIT(A,...)        false
#define PROFILE_ARRAY_INIT(A,B,...)
#define PROFILE_ARRAY_START(A,...)
#define PROFILE_ARRAY_STOP(A,...)
#define PROFILE_ARRAY_RESET(A,...)

#define PROFILE_TL_DEFINE(tag)              UNUSED_TYPE TgSINT_F32 PFCAT(TgNOT_USED_TLS__, tag)
#define PROFILE_TL_EXTERN(tag)              TgEXTN TgSINT_F32 PFCAT(TgNOT_USED_TLS__, tag)
#define PROFILE_TL_IS_INIT(tag)             false
#define PROFILE_TL_INIT(tag)
#define PROFILE_TL_START(tag)
#define PROFILE_TL_STOP(tag)
#define PROFILE_TL_RESET(tag)

/*# TgCOMPILE__PROFILE */
#endif


/* =============================================================================================================================================================================== */
#endif
