/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Event MGR.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include "TgS Common - Event MGR - Internal.h"
#include "TgS Common - Event MGR.inl"


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Private Data                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgCOMPILER_ASSERT( sizeof( g_apsEM_TE_FRM ) == KTgEM_MAX_TE_FRM_POOL*sizeof( STg2_EM_TE_Pool_P ), 0 );
TgCOMPILER_ASSERT( sizeof( g_apsEM_TE_SEC ) == KTgEM_MAX_TE_SEC_POOL*sizeof( STg2_EM_TE_Pool_P ), 1 );

STg2_EM_TE_Pool_P                           g_apsEM_TE_FRM[KTgEM_MAX_TE_FRM_POOL]; /**< Synchronization: g_sEM_TE_FRM_Lock */
STg2_EM_TE_Pool_P                           g_psEM_TE_FRM_Free_List;               /**< Synchronization: g_sEM_TE_FRM_Lock */
STg2_UT_LF_ISO__SN                          g_sEM_TE_FRM_Lock;
STg2_UT_LF_ISO__SN                          g_asEM_TE_FRM_Data_Lock[KTgEM_MAX_TE_FRM_POOL];
STg2_UT_LF_ISO__SN                          g_asEM_TE_FRM_NewDel_Lock[KTgEM_MAX_TE_FRM_POOL];

STg2_EM_TE_Pool_P                           g_apsEM_TE_SEC[KTgEM_MAX_TE_SEC_POOL]; /**< Synchronization: g_sEM_TE_SEC_Lock */
STg2_EM_TE_Pool_P                           g_psEM_TE_SEC_Free_List;               /**< Synchronization: g_sEM_TE_SEC_Lock */
STg2_UT_LF_ISO__SN                          g_sEM_TE_SEC_Lock;
STg2_UT_LF_ISO__SN                          g_asEM_TE_SEC_Data_Lock[KTgEM_MAX_TE_SEC_POOL];
STg2_UT_LF_ISO__SN                          g_asEM_TE_SEC_NewDel_Lock[KTgEM_MAX_TE_SEC_POOL];




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Types                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

enum { ETgEM_JOB_COMPLETE_COUNT = 4 };

typedef enum
{
    ETgEM_UPDATE_STAGE__UNKNOWN,
    ETgEM_UPDATE_STAGE__WAIT_FOR_EXECUTE,
    ETgEM_UPDATE_STAGE__NEW_STITCH,
    ETgEM_UPDATE_STAGE__PAUSED,
    ETgEM_UPDATE_STAGE__WAITING,
    ETgEM_UPDATE_STAGE__PROCESS,
    ETgEM_UPDATE_STAGE__DELETE,
    ETgEM_UPDATE_STAGE__DONE,
} ETgEM_UPDATE_STAGE;

TgTYPE_STRUCT(STg2_EM_TE_Job_Update_PM,)
{
    /* Pointers to the SoA data elements for the time event pools and locks */
    STg2_EM_TE_Pool_P                           m_psPool;              /**< Example: g_apsEM_TE_FRM[iPool] */
    STg2_UT_LF__SN_P                            m_psData_Lock;         /**< Example: g_asEM_TE_FRM_Data_Lock[iPool] */
    STg2_UT_LF__SN_P                            m_psNewDel_Lock;       /**< Example: g_asEM_TE_FRM_NewDel_Lock[iPool] */

    /* Used to trigger the final free pool cleanup job */
    TgRSIZE_AP                                  m_pxuiFree_Trigger;    /**< Example: s_xuiJob_Trigger_TE_FRM */volatile

    ETgEM_UPDATE_STAGE                          m_enStage;
    TgFLOAT32                                   m_fTime_Step;
    TgFLOAT32                                   m_fTotal;
    TgSINT_F32                                  m_iTotal;
    TgBOOL                                      m_bIsPaused;
    TgUINT_E08                                  m_uiPad0[7];
};

TgTYPE_STRUCT(STg2_EM_TE_Job_Free_Pool_PM,)
{
    STg2_EM_TE_Pool_PP                          m_ppsPool_List;        /**< Example: g_apsEM_TE_FRM */
    STg2_EM_TE_Pool_PP                          m_ppsFree_Pool_Head;   /**< Example: &(g_psEM_TE_FRM_Free_List) */
    STg2_UT_LF__SN_P                            m_psFree_Lock;         /**< Example: g_sEM_TE_FRM_Lock */
    TgSINT_F32                                  m_niMax_Pool;          /**< Example: KTgEM_MAX_TE_FRM_POOL */
    TgUINT_F32                                  m_uiPad0;
    STg2_UT_LF_ISO__SN_P                        m_psData_Lock;         /**< Example: g_asEM_TE_FRM_Data_Lock */
    STg2_UT_LF_ISO__SN_P                        m_psNewDel_Lock;       /**< Example: g_asEM_TE_FRM_NewDel_Lock */
};

TgTYPE_STRUCT(STg2_Event_Pool_Update,)
{
    STg2_EM_TE_Pool_PP                          m_apsPool;
    STg2_UT_LF_ISO__SN_P                        m_asData_Lock;
    STg2_UT_LF_ISO__SN_P                        m_asNewDel_Lock;
    TgSINT_F32                                  m_iMax;
    TgUINT_F32                                  m_uiPad0;
    TgFCN_JOB_CALLBACK                          m_pfnExecute;
    TgRSIZE_AP                                  m_pxuiFree_Trigger;
    STg2_EM_TE_Job_Update_PM_CP                 m_psUpdate_Data;

    STg2_Job_P                                  m_psFree_Job;
    STg2_EM_TE_Pool_PP                          m_ppsFree_Pool_Head;
    STg2_UT_LF__SN_P                            m_psFree_Lock;
};

TgCOMPILER_ASSERT( sizeof( STg2_EM_TE_Job_Update_PM ) <= KTgJOB_DATA_SIZE, 0 );
TgCOMPILER_ASSERT( sizeof( STg2_EM_TE_Job_Free_Pool_PM ) <= KTgJOB_DATA_SIZE, 0 );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions and Data                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

static TgBOOL                               tgEM_Job_Execute__Submit_Event_Pool_Update( STg2_Event_Pool_Update_PCU );
static TgVOID                               tgEM_Job_Execute__Submit_Free_Pool_Fixup( STg2_Event_Pool_Update_PCU );
TgFORCEINLINE TgVOID                        tgEM_List_Stitch( STg2_EM_TB_PP, STg2_EM_TB_P );
static TgVOID                               tgEM_TE_Update_Internal__Waiting( STg2_EM_TE_Pool_PC, STg2_EM_TE_Job_Update_PM_CPCU );
static TgVOID                               tgEM_TE_Update_Internal__Process( STg2_EM_TB_PP, TgSINT_F32_P , STg2_EM_TE_P, STg2_EM_TE_Pool_PC, STg2_EM_TE_Job_Update_PM_CPCU );
static TgVOID                               tgEM_TE_Update_Internal__Delete( STg2_EM_TE_Pool_PC, STg2_EM_TB_P, STg2_EM_TE_Job_Update_PM_CPCU );
static TgVOID                               tgEM_TE_Update_Internal__Paused( STg2_EM_TE_Pool_PC, STg2_EM_TE_Job_Update_PM_CPCU );
static TgRESULT                             tgEM_Job_Execute__Update( STg2_Job_PC );
static TgRESULT                             tgEM_Job_Execute__TE( STg2_Job_PC );
static TgRESULT                             tgEM_Job_Execute__Free_Pool( STg2_Job_PC );

#if TgS_STAT__COMMON
static TgVOID                               tgEM_Print_Pool_Stat( STg2_EM_TE_Pool_PCU, STg2_Output_P );
#endif

static ETgMODULE_STATE                      s_enEvent_MGR_State = ETgMODULE_STATE__FREED;
static TgUINT_F32                           s_bfCntTime;

static STg2_Job                             s_sJob_Update;
static TgRSIZE_A                            s_xuiJob_Count;

static STg2_Job                             s_sJob_TE_FRM__Free_Pool_Update;
static TgRSIZE_A                            s_xuiJob_Trigger_TE_FRM;
static STg2_Job                             s_sJob_TE_SEC__Free_Pool_Update;
static TgRSIZE_A                            s_xuiJob_Trigger_TE_SEC;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgEM_Init_MGR ------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgEM_Init_MGR( TgVOID )
{
    TgSINT_F32                          iIndex;

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__FREED == s_enEvent_MGR_State);
    s_enEvent_MGR_State = ETgMODULE_STATE__INITIALIZING;

    /* Init Global Variables */
    tgMM_Set_U08_0x00( g_apsEM_TE_FRM, sizeof( g_apsEM_TE_FRM ) );
    g_psEM_TE_FRM_Free_List = nullptr;
    tgCM_UT_LF__SN__Init( &g_sEM_TE_FRM_Lock.m_sLock );

    for (iIndex = 0; iIndex < KTgEM_MAX_TE_FRM_POOL; ++iIndex)
    {
        tgCM_UT_LF__SN__Init( &g_asEM_TE_FRM_Data_Lock[iIndex].m_sLock );
        tgCM_UT_LF__SN__Init( &g_asEM_TE_FRM_NewDel_Lock[iIndex].m_sLock );
    };

    tgMM_Set_U08_0x00( g_apsEM_TE_SEC, sizeof( g_apsEM_TE_SEC ) );
    g_psEM_TE_SEC_Free_List = nullptr;
    tgCM_UT_LF__SN__Init( &g_sEM_TE_SEC_Lock.m_sLock );

    for (iIndex = 0; iIndex < KTgEM_MAX_TE_SEC_POOL; ++iIndex)
    {
        tgCM_UT_LF__SN__Init( &g_asEM_TE_SEC_Data_Lock[iIndex].m_sLock );
        tgCM_UT_LF__SN__Init( &g_asEM_TE_SEC_NewDel_Lock[iIndex].m_sLock );
    };

    /* Configuration Parameters */
    tgBF_Reset_U32( &s_bfCntTime );

    /* Initialize the job structures */
    tgMM_Set_U08_0x00( &s_sJob_Update, sizeof( s_sJob_Update ) );
    atomic_store( &s_xuiJob_Count, 0 );

    s_enEvent_MGR_State = ETgMODULE_STATE__INITIALIZED;
    return (KTgS_OK);
}


/* ---- tgEM_Boot_MGR ------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgEM_Boot_MGR( TgVOID )
{
    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__INITIALIZED == s_enEvent_MGR_State);
    s_enEvent_MGR_State = ETgMODULE_STATE__BOOTED;
    return (KTgS_OK);
}


/* ---- tgEM_Stop_MGR ------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgEM_Stop_MGR( TgVOID )
{
    if ((ETgMODULE_STATE__FREED == s_enEvent_MGR_State) || (ETgMODULE_STATE__INITIALIZED == s_enEvent_MGR_State))
    {
        return (KTgS_OK);
    };

    /* Verify the state of the system */
    TgERROR(ETgMODULE_STATE__BOOTED == s_enEvent_MGR_State);
    s_enEvent_MGR_State = ETgMODULE_STATE__STOPPED;
    return (KTgS_OK);
}


/* ---- tgEM_Free_MGR ------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgEM_Free_MGR( TgVOID )
{
    TgSINT_F32                          iIndex;

    if (ETgMODULE_STATE__FREED == s_enEvent_MGR_State)
    {
        return (KTgS_OK);
    };

    /* Verify the state of the system */
    TgERROR((ETgMODULE_STATE__STOPPED == s_enEvent_MGR_State) || (ETgMODULE_STATE__INITIALIZED == s_enEvent_MGR_State));
    s_enEvent_MGR_State = ETgMODULE_STATE__FREEING;

    for (iIndex = 0; iIndex < KTgEM_MAX_TE_SEC_POOL; ++iIndex)
    {
        if (g_apsEM_TE_SEC[iIndex])
        {
            TgFREE_POOL( g_apsEM_TE_SEC[iIndex] );
            g_apsEM_TE_SEC[iIndex] = nullptr;
        };
        tgCM_UT_LF__SN__Free_Unsafe( &g_asEM_TE_SEC_Data_Lock[iIndex].m_sLock );
        tgCM_UT_LF__SN__Free_Unsafe( &g_asEM_TE_SEC_NewDel_Lock[iIndex].m_sLock );
    };
    tgCM_UT_LF__SN__Free_Unsafe( &g_sEM_TE_SEC_Lock.m_sLock );

    for (iIndex = 0; iIndex < KTgEM_MAX_TE_FRM_POOL; ++iIndex)
    {
        if (g_apsEM_TE_FRM[iIndex])
        {
            TgFREE_POOL( g_apsEM_TE_FRM[iIndex] );
            g_apsEM_TE_FRM[iIndex] = nullptr;
        };
        tgCM_UT_LF__SN__Free_Unsafe( &g_asEM_TE_FRM_Data_Lock[iIndex].m_sLock );
        tgCM_UT_LF__SN__Free_Unsafe( &g_asEM_TE_FRM_NewDel_Lock[iIndex].m_sLock );
    };
    tgCM_UT_LF__SN__Free_Unsafe( &g_sEM_TE_FRM_Lock.m_sLock );

    s_enEvent_MGR_State = ETgMODULE_STATE__FREED;
    return (KTgS_OK);
}


/* ---- tgEM_Update_MGR ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgEM_Update_MGR( TgFLOAT32_C fDT )
{
    union
    {
        TgUINT_F08_P                        m_psUntyped;
        STg2_EM_TE_Job_Update_PM_P          m_psJob_Data;
    }                                   tgUpdate_Param;

    /* Yield until the previous update has completed */
    while (!tgEM_Update_MGR_Is_Complete())
    {
        tgTR_Yield();
    };

    /* Submit the first stage of the update chain to the job system */
    tgUpdate_Param.m_psUntyped = s_sJob_Update.m_auiData;
    tgMM_Set_U08_0x00( &s_sJob_Update, sizeof( s_sJob_Update ) );

    s_sJob_Update.m_pfnExecute = tgEM_Job_Execute__Update;
    s_sJob_Update.m_pxuiFinish = &s_xuiJob_Count;

    tgUpdate_Param.m_psJob_Data->m_enStage = ETgEM_UPDATE_STAGE__WAIT_FOR_EXECUTE;
    tgUpdate_Param.m_psJob_Data->m_fTime_Step = fDT;
    tgUpdate_Param.m_psJob_Data->m_fTotal = tgGB_Query_Total_Time();
    tgUpdate_Param.m_psJob_Data->m_iTotal = tgGB_Query_Total_Frame();
    tgUpdate_Param.m_psJob_Data->m_bIsPaused = tgEM_Query_Pause();

    atomic_fetch_add( &s_xuiJob_Count, 1 );
    if (TgFAILED(tgJM_Queue_Job( g_tiJob_Queue__OS, &s_sJob_Update )))
    {
        atomic_fetch_sub( &s_xuiJob_Count, 1 );
    };

    return (KTgS_OK);
}


/* ---- tgEM_Update_MGR_Is_Complete ---------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL tgEM_Update_MGR_Is_Complete( TgVOID )
{
    return (atomic_load( &s_xuiJob_Count ) > 0 ? false : true);
}

/* ---- tgEM_Query_Init ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL tgEM_Query_Init( TgVOID )
{
    return (ETgMODULE_STATE__INITIALIZED <= s_enEvent_MGR_State && s_enEvent_MGR_State <= ETgMODULE_STATE__STOPPED);
}


/* ---- tgEM_Query_Boot ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL tgEM_Query_Boot( TgVOID )
{
    return (ETgMODULE_STATE__BOOTED == s_enEvent_MGR_State);
}


/* ---- tgEM_Query_Fixed_Memory -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgEM_Query_Fixed_Memory( TgVOID )
{
    return (0
             + sizeof( g_apsEM_TE_FRM )
             + sizeof( g_psEM_TE_FRM_Free_List )
             + sizeof( g_sEM_TE_FRM_Lock )
             + sizeof( g_asEM_TE_FRM_Data_Lock )
             + sizeof( g_asEM_TE_FRM_NewDel_Lock )
             + sizeof( g_apsEM_TE_SEC )
             + sizeof( g_psEM_TE_SEC_Free_List )
             + sizeof( g_sEM_TE_SEC_Lock )
             + sizeof( g_asEM_TE_SEC_Data_Lock )
             + sizeof( g_asEM_TE_SEC_NewDel_Lock )
             + sizeof( s_enEvent_MGR_State )
             + sizeof( s_bfCntTime )
             + sizeof( s_sJob_Update )
             + sizeof( s_xuiJob_Count )
             + sizeof( s_sJob_TE_FRM__Free_Pool_Update )
             + sizeof( s_xuiJob_Trigger_TE_FRM )
             + sizeof( s_sJob_TE_SEC__Free_Pool_Update )
             + sizeof( s_xuiJob_Trigger_TE_SEC )
    );
}


/* ---- tgEM_Set_Pause ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgEM_Set_Pause( TgBOOL_C bFlag )
{
    tgBF_Set_Flag_U32( &s_bfCntTime, 0, bFlag );
}


/* ---- tgEM_Query_Pause --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL tgEM_Query_Pause( TgVOID )
{
    return (tgBF_Test_Flag_U32( &s_bfCntTime, 0 ));
}


/* ---- tgEM_Stats --------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgS_STAT__COMMON
TgVOID tgEM_Stats( STg2_Output_P psOutput )
{
    TgRSIZE                             uiIndex;

    if (nullptr == psOutput)
    {
        return;
    };

    /* Yield until the previous update has completed */
    uiIndex = 0;
    while (!atomic_compare_exchange_weak( &s_xuiJob_Count, &uiIndex, 1))
    {
        tgTR_Yield();
        uiIndex = 0;
    };

    /* Collect all of the pools that have free lists */
    tgCM_UT_LF__SN__Lock_Spin( &g_sEM_TE_FRM_Lock.m_sLock );
    for (uiIndex = 0; uiIndex < KTgEM_MAX_TE_FRM_POOL; ++uiIndex)
    {
        tgCM_UT_LF__SN__Lock_Spin( &g_asEM_TE_FRM_NewDel_Lock[uiIndex].m_sLock );

        if (nullptr != g_apsEM_TE_FRM[uiIndex])
        {
            tgCM_UT_LF__SN__Lock_Spin( &g_asEM_TE_FRM_Data_Lock[uiIndex].m_sLock );
            tgEM_Print_Pool_Stat( g_apsEM_TE_FRM[uiIndex], psOutput );
            tgCM_UT_LF__SN__Signal( &g_asEM_TE_FRM_Data_Lock[uiIndex].m_sLock );
        };

        tgCM_UT_LF__SN__Signal( &g_asEM_TE_FRM_NewDel_Lock[uiIndex].m_sLock );
    };
    tgCM_UT_LF__SN__Signal( &g_sEM_TE_FRM_Lock.m_sLock );

    tgCM_UT_LF__SN__Lock_Spin( &g_sEM_TE_SEC_Lock.m_sLock );
    for (uiIndex = 0; uiIndex < KTgEM_MAX_TE_SEC_POOL; ++uiIndex)
    {
        tgCM_UT_LF__SN__Lock_Spin( &g_asEM_TE_SEC_NewDel_Lock[uiIndex].m_sLock );

        if (nullptr != g_apsEM_TE_SEC[uiIndex])
        {
            tgCM_UT_LF__SN__Lock_Spin( &g_asEM_TE_SEC_Data_Lock[uiIndex].m_sLock );
            tgEM_Print_Pool_Stat( g_apsEM_TE_SEC[uiIndex], psOutput );
            tgCM_UT_LF__SN__Signal( &g_asEM_TE_SEC_Data_Lock[uiIndex].m_sLock );
        };

        tgCM_UT_LF__SN__Signal( &g_asEM_TE_SEC_NewDel_Lock[uiIndex].m_sLock );
    };
    tgCM_UT_LF__SN__Signal( &g_sEM_TE_SEC_Lock.m_sLock );

    /* Free the system for updating */
    atomic_fetch_sub( &s_xuiJob_Count, 1 );
}
/*# TgS_STAT__COMMON */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Private Functions                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgEM_TP_Init ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgEM_TP_Init( STg2_EM_TE_Pool_PC psPool )
{
    TgSINT_F32                          iIndex;

    /* Validate the parameters */
    TgPARAM_CHECK(nullptr != psPool);

    /* Initialize the data structure */
    tgMM_Set_U08_0x00( &psPool->m_sJob, sizeof( psPool->m_sJob ) );
    psPool->m_psFree_Next = 0;
    psPool->m_psFree = psPool->m_asTB;
    psPool->m_niUsed = 0;
    tgBF_Reset_U32( &psPool->m_bfFlags );
    psPool->m_iPool = KTgMAX_S32;
    psPool->m_psWaiting = 0;
    psPool->m_psActive = 0;
    tgCM_UT_LF__ST__Init( &psPool->m_sNew );

    /* Invalidate all of the entity ids */
    tgMM_Set_U08_0xFF( psPool->m_atiEM_TE_FRM_NoSingleton, KTgEM_NUM_TE_IN_POOL*sizeof( TgEM_TE_FRM_ID ) );

    /* Stitch the free list */
    for (iIndex = 0; iIndex < KTgEM_NUM_TE_IN_POOL - 1; ++iIndex)
    {
        psPool->m_asTB[iIndex].m_psHead_Next = psPool->m_asTB + iIndex + 1;
    };

    psPool->m_asTB[KTgEM_NUM_TE_IN_POOL - 1].m_psHead_Next = nullptr;
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions                                                                                                                                                           */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgEM_Job_Execute__Submit_Pool_Update ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgBOOL tgEM_Job_Execute__Submit_Event_Pool_Update( STg2_Event_Pool_Update_PCU psInit )
{
    union
    {
        TgUINT_F08_P                            m_psUntyped;
        STg2_EM_TE_Job_Update_PM_P              m_psJob_Param;
    }                                   tgUpdate_Cast;

    STg2_EM_TE_Job_Update_PM_P          psJob_Data;
    TgSINT_F32                          iIndex;
    TgSINT_F32                          niUpdate;

    niUpdate = 0;
    for (iIndex = 0; iIndex < psInit->m_iMax; ++iIndex)
    {
        if (nullptr == psInit->m_apsPool[iIndex])
        {
            continue;
        };

        tgUpdate_Cast.m_psUntyped = psInit->m_apsPool[iIndex]->m_sJob.m_auiData;
        psJob_Data = tgUpdate_Cast.m_psJob_Param;

        tgMM_Set_U08_0x00( &psInit->m_apsPool[iIndex]->m_sJob, sizeof( STg2_Job ) );
        psInit->m_apsPool[iIndex]->m_sJob.m_pfnExecute = psInit->m_pfnExecute;
        psInit->m_apsPool[iIndex]->m_sJob.m_pxuiFinish = &s_xuiJob_Count;

        psJob_Data->m_psPool = psInit->m_apsPool[iIndex];
        psJob_Data->m_psData_Lock = &(psInit->m_asData_Lock[iIndex].m_sLock);
        psJob_Data->m_psNewDel_Lock = &(psInit->m_asNewDel_Lock[iIndex].m_sLock);
        psJob_Data->m_pxuiFree_Trigger = psInit->m_pxuiFree_Trigger;
        psJob_Data->m_enStage = ETgEM_UPDATE_STAGE__WAIT_FOR_EXECUTE;
        psJob_Data->m_fTime_Step = psInit->m_psUpdate_Data->m_fTime_Step;
        psJob_Data->m_fTotal = psInit->m_psUpdate_Data->m_fTotal;
        psJob_Data->m_iTotal = psInit->m_psUpdate_Data->m_iTotal;
        psJob_Data->m_bIsPaused = psInit->m_psUpdate_Data->m_bIsPaused;

        atomic_fetch_add( psInit->m_pxuiFree_Trigger, 1 );
        atomic_fetch_add( &s_xuiJob_Count, 1 );
        ++niUpdate;
        if (TgFAILED(tgJM_Queue_Job( g_tiJob_Queue__OS, &psInit->m_apsPool[iIndex]->m_sJob )))
        {
            atomic_fetch_sub( psInit->m_pxuiFree_Trigger, 1 );
            atomic_fetch_sub( &s_xuiJob_Count, 1 );
        };
    };

    return (niUpdate > 0);
}


/* ---- tgEM_Job_Execute__Submit_Pool_Update ------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgVOID tgEM_Job_Execute__Submit_Free_Pool_Fixup( STg2_Event_Pool_Update_PCU psInit )
{
    union
    {
        TgUINT_F08_P                            m_psUntyped;
        STg2_EM_TE_Job_Free_Pool_PM_P           m_psJob_Param;
    }                                   tgJob_Cast;

    tgJob_Cast.m_psUntyped = psInit->m_psFree_Job->m_auiData;

    tgMM_Set_U08_0x00( psInit->m_psFree_Job, sizeof( STg2_Job ) );
    psInit->m_psFree_Job->m_pfnExecute = tgEM_Job_Execute__Free_Pool;
    psInit->m_psFree_Job->m_pxuiTrigger = psInit->m_pxuiFree_Trigger;
    psInit->m_psFree_Job->m_pxuiFinish = &s_xuiJob_Count;

    tgJob_Cast.m_psJob_Param->m_ppsPool_List = psInit->m_apsPool;
    tgJob_Cast.m_psJob_Param->m_ppsFree_Pool_Head = psInit->m_ppsFree_Pool_Head;
    tgJob_Cast.m_psJob_Param->m_psFree_Lock = psInit->m_psFree_Lock;
    tgJob_Cast.m_psJob_Param->m_niMax_Pool = psInit->m_iMax;
    tgJob_Cast.m_psJob_Param->m_psData_Lock = psInit->m_asData_Lock;
    tgJob_Cast.m_psJob_Param->m_psNewDel_Lock = psInit->m_asNewDel_Lock;

    atomic_fetch_add( &s_xuiJob_Count, 1 );
    if (TgFAILED(tgJM_Queue_Job( g_tiJob_Queue__OS, psInit->m_psFree_Job )))
    {
        atomic_fetch_sub( &s_xuiJob_Count, 1 );
    };
}


/* ---- tgEM_List_Stitch --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgFORCEINLINE TgVOID tgEM_List_Stitch( STg2_EM_TB_PP ppsTB_List, STg2_EM_TB_P psInsert_TB )
{
    STg2_EM_TB_P                        psTB = *ppsTB_List;
    STg2_EM_TB_P                        psPrev_TB = nullptr;

    /* Add this time line to the parameter list in an index priority */
    while (1)
    {
        if (nullptr == psTB || psTB->m_uiLocal_Index > psInsert_TB->m_uiLocal_Index)
        {
            if (nullptr == psPrev_TB)
            {
                psInsert_TB->m_psHead_Next = *ppsTB_List;
                *ppsTB_List = psInsert_TB;
            }
            else
            {
                psInsert_TB->m_psHead_Next = psTB;
                psPrev_TB->m_psHead_Next = psInsert_TB;
            };

            return;
        };

        psPrev_TB = psTB;
        psTB = psTB->m_psHead_Next;
        TgPARAM_CHECK(psTB != psPrev_TB);
    };
}


/* ---- tgEM_TE_Update_Internal__Waiting ----------------------------------------------------------------------------------------------------------------------------------------- */
/** @note Since pause state is polled it is possible, if the time line pause state is being toggled on a concurrent thread that we will retrieve a temporary or in-flight value.
    If you need to toggle pause state this should be done within the events instead as a directed action instead of indirectly by pause state on the time line                     */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgVOID tgEM_TE_Update_Internal__Waiting( STg2_EM_TE_Pool_PC psPool, STg2_EM_TE_Job_Update_PM_CPCU psParam )
{
    STg2_EM_TB_PP                       ppsPrev_TB;
    STg2_EM_TB_P                        psTB;

    /* Process all the waiting time lines based on frame count */
    for (ppsPrev_TB = &psPool->m_psWaiting, psTB = psPool->m_psWaiting; nullptr != psTB; )
    {
        TgERROR((TgSINT_F32 )(psTB->m_uiLocal_Index & 0xFFFF) < KTgEM_NUM_TE_IN_POOL);

        /* Check to see if the time line is paused */
        if (tgEM_TB_Is_Paused( psTB ))
        {
            psTB->m_fStart = tgPM_FSEL_F32( psTB->m_fStart, psTB->m_fStart + psParam->m_fTime_Step, psTB->m_fStart );
            psTB->m_fEnd = tgPM_FSEL_F32( psTB->m_fEnd, psTB->m_fEnd + psParam->m_fTime_Step, psTB->m_fEnd );
            psTB->m_iStart = psTB->m_iStart >= 0 ? psTB->m_iStart + 1 : psTB->m_iStart;
            psTB->m_iEnd = psTB->m_iEnd >= 0 ? psTB->m_iEnd + 1 : psTB->m_iEnd;

            ppsPrev_TB = &psTB->m_psHead_Next;
            psTB = psTB->m_psHead_Next;
            continue;
        };

        /* Check to see if the entity should be started (negative values in unsigned space will always exceed signed total) */
        /* Thus, only one of these tests can ever be true (the unused value has a negative value) */
        if (((TgUINT_F32)psTB->m_iStart <= (TgUINT_F32)psParam->m_iTotal) || (tgPM_FSEL_F32( psTB->m_fStart, psTB->m_fStart, KTgMAX_F32 ) <= psParam->m_fTotal))
        {
            STg2_EM_TB_PC                       psActive_TB = psTB;

            /* Remove this entry from the waiting list */
            *ppsPrev_TB = psTB->m_psHead_Next;
            psTB = psTB->m_psHead_Next;

            /* Add the entity to the active list */
            tgEM_TB_Set_Active( psActive_TB, true );
            tgEM_List_Stitch( &psPool->m_psActive, psActive_TB );
        }
        else
        {
            ppsPrev_TB = &psTB->m_psHead_Next;
            psTB = psTB->m_psHead_Next;
        };
    };
}


/* ---- tgEM_TE_Update_Internal__Process ----------------------------------------------------------------------------------------------------------------------------------------- */
/** @note Since pause state is polled it is possible, if the time line pause state is being toggled on a concurrent thread that we will retrieve a temporary or in-flight value. If
    you need to toggle pause state this should be done within the events instead as a directed action instead of indirectly by pause state on the time line */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgVOID tgEM_TE_Update_Internal__Process( STg2_EM_TB_PP ppsFree_TB, TgSINT_F32_P pniCallback, STg2_EM_TE_P psCallback, STg2_EM_TE_Pool_PC psPool_TB,
                                                STg2_EM_TE_Job_Update_PM_CPCU psParam )
{
    STg2_EM_TB_PP                       ppsPrev_TB;
    STg2_EM_TB_P                        psTB;
    STg2_EM_TE_Pool_P                   psPool_TE;
    TgSINT_F32                          niCallback;
    STg2_EM_TB_P                        psFree_TB;

    TgPARAM_CHECK(nullptr != ppsFree_TB && nullptr != pniCallback && nullptr != psCallback && nullptr != psPool_TB && nullptr != psParam);

    psPool_TE = (STg2_EM_TE_Pool_P)psPool_TB;
    niCallback = 0;
    psFree_TB = nullptr;

    /* Process all the waiting time lines based on frame count */
    for (ppsPrev_TB = &psPool_TB->m_psActive, psTB = psPool_TB->m_psActive; nullptr != psTB; )
    {
        TgSINT_F32                          iLocal_Index;
        TgUINT_F32                          uiIndex;

        iLocal_Index = (TgSINT_F32)(psTB->m_uiLocal_Index & 0xFFFF);
        TgERROR(iLocal_Index < KTgEM_NUM_TE_IN_POOL);

        uiIndex = (TgUINT_F32)((psTB - psPool_TB->m_asTB) & 0xFFFF);
        TgPARAM_CHECK_INDEX( uiIndex, psPool_TB->m_asTB );

        /* Check to see if the time line is paused */
        if (tgEM_TB_Is_Paused( psTB ))
        {
            psTB->m_fEnd = tgPM_FSEL_F32( psTB->m_fEnd, psTB->m_fEnd + psParam->m_fTime_Step, psTB->m_fEnd );
            psTB->m_iEnd = psTB->m_iEnd >= 0 ? psTB->m_iEnd + 1 : psTB->m_iEnd;

            ppsPrev_TB = &psTB->m_psHead_Next;
            psTB = psTB->m_psHead_Next;
            continue;
        };

        /* Add this call back to the queue */
        if (KTgID__INVALID_VALUE != psPool_TB->m_atiEM_TE_FRM_NoSingleton[uiIndex].m_uiKI)
        {
            psCallback[niCallback++] = psPool_TB->m_asTE[iLocal_Index];
        };

        /* Check to see if the time line should be closed (negative values in unsigned space will always exceed signed total) */
        /* Thus, only one of these tests can ever be true (the unused value has a negative value) */
        if (((TgUINT_F32)psTB->m_iEnd <= (TgUINT_F32)psParam->m_iTotal) || (tgPM_FSEL_F32( psTB->m_fEnd, psTB->m_fEnd, KTgMAX_F32 ) <= psParam->m_fTotal))
        {
            STg2_EM_TB_P                        psFinish_TB;

            psFinish_TB = psTB;

            /* Mark the entry to be invalid (FRM and SEC ID are unioned) */
            psPool_TB->m_atiEM_TE_FRM_NoSingleton[uiIndex].m_uiKI = KTgID__INVALID_VALUE;

            /* Remove this entry from the processing list */
            *ppsPrev_TB = psTB->m_psHead_Next;
            psTB = psTB->m_psHead_Next;

            /* Add the entity to the free list */
            psFinish_TB->m_psHead_Next = psFree_TB;
            psFree_TB = psFinish_TB;
        }
        else
        {
            ppsPrev_TB = &psTB->m_psHead_Next;
            psTB = psTB->m_psHead_Next;
        };
    };

    *ppsFree_TB = psFree_TB;
    *pniCallback = niCallback;
}


/* ---- tgEM_TE_Update_Internal__Delete ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgVOID tgEM_TE_Update_Internal__Delete( STg2_EM_TE_Pool_PC psPool, STg2_EM_TB_P psFree_TB, STg2_EM_TE_Job_Update_PM_CPCU psParam )
{
    STg2_EM_TB_P                        psTB;

    TgPARAM_CHECK(nullptr != psFree_TB);

    /* Add all of the deleted entities to the pool's free list */
    while (nullptr != (psTB = psFree_TB))
    {
        psFree_TB = psFree_TB->m_psHead_Next;

        /* We recheck after processing since it is possible that the call back functions have modified our end criteria */
        if (((TgUINT_F32)psTB->m_iEnd <= (TgUINT_F32)psParam->m_iTotal) || (tgPM_FSEL_F32( psTB->m_fEnd, psTB->m_fEnd, KTgMAX_F32 ) <= psParam->m_fTotal))
        {
            --psPool->m_niUsed;
            tgEM_List_Stitch( &psPool->m_psFree, psTB );
        }
        else
        {
            tgEM_List_Stitch( &psPool->m_psWaiting, psTB );
        };
    };
}


/* ---- tgEM_TE_Update_Internal__Paused ------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgVOID tgEM_TE_Update_Internal__Paused( STg2_EM_TE_Pool_PC psPool, STg2_EM_TE_Job_Update_PM_CPCU psParam )
{
    STg2_EM_TB_P                        psTB;

    /* PROCESS ALL WAITING TIME LINES */
    for (psTB = psPool->m_psWaiting; nullptr != psTB; psTB = psTB->m_psHead_Next)
    {
        TgERROR((TgSINT_F32 )(psTB->m_uiLocal_Index & 0xFFFF) < KTgEM_NUM_TE_IN_POOL);

        /* Check to see if the time line is paused */
        psTB->m_fStart = tgPM_FSEL_F32( psTB->m_fStart, psTB->m_fStart + psParam->m_fTime_Step, psTB->m_fStart );
        psTB->m_fEnd = tgPM_FSEL_F32( psTB->m_fEnd, psTB->m_fEnd + psParam->m_fTime_Step, psTB->m_fEnd );
        psTB->m_iStart = (TgSINT_F32 )((TgUINT_F32)psTB->m_iStart & 0x80000000) | (psTB->m_iStart + 1);
        psTB->m_iEnd = (TgSINT_F32 )((TgUINT_F32)psTB->m_iEnd & 0x80000000) | (psTB->m_iEnd + 1);
    };


    /* PROCESS ALL PROCESS TIME LINES */
    for (psTB = psPool->m_psActive; nullptr != psTB; psTB = psTB->m_psHead_Next)
    {
        TgERROR((TgSINT_F32 )(psTB->m_uiLocal_Index & 0xFFFF) < KTgEM_NUM_TE_IN_POOL);

        /* Check to see if the time line is paused */
        psTB->m_fStart = tgPM_FSEL_F32( psTB->m_fStart, psTB->m_fStart + psParam->m_fTime_Step, psTB->m_fStart );
        psTB->m_fEnd = tgPM_FSEL_F32( psTB->m_fEnd, psTB->m_fEnd + psParam->m_fTime_Step, psTB->m_fEnd );
        psTB->m_iStart = (TgSINT_F32 )((TgUINT_F32)psTB->m_iStart & 0x80000000) | (psTB->m_iStart + 1);
        psTB->m_iEnd = (TgSINT_F32 )((TgUINT_F32)psTB->m_iEnd & 0x80000000) | (psTB->m_iEnd + 1);
    };
}


/* ---- tgEM_Job_Execute__Update ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgRESULT tgEM_Job_Execute__Update( STg2_Job_PC psJob )
{
    union
    {
        TgUINT_F08_P                            m_psUntyped;
        STg2_EM_TE_Job_Update_PM_P              m_psJob_Data;
    }                                   tgJob_Cast;
    TgBOOL                              bNeedFixUp;
    STg2_Event_Pool_Update              tgUpdate_Init;

    tgJob_Cast.m_psUntyped = psJob->m_auiData;

    /* Submit the jobs to update the time event pools */
    tgUpdate_Init.m_apsPool = g_apsEM_TE_FRM;
    tgUpdate_Init.m_asData_Lock = g_asEM_TE_FRM_Data_Lock;
    tgUpdate_Init.m_asNewDel_Lock = g_asEM_TE_FRM_NewDel_Lock;
    tgUpdate_Init.m_iMax = KTgEM_MAX_TE_FRM_POOL;
    tgUpdate_Init.m_pfnExecute = tgEM_Job_Execute__TE;
    tgUpdate_Init.m_pxuiFree_Trigger = &s_xuiJob_Trigger_TE_FRM;
    tgUpdate_Init.m_psUpdate_Data = tgJob_Cast.m_psJob_Data;

    bNeedFixUp = tgEM_Job_Execute__Submit_Event_Pool_Update( &tgUpdate_Init );
    if (bNeedFixUp)
    {
        tgUpdate_Init.m_psFree_Job = &s_sJob_TE_FRM__Free_Pool_Update;
        tgUpdate_Init.m_psFree_Lock = &g_sEM_TE_FRM_Lock.m_sLock;
        tgUpdate_Init.m_ppsFree_Pool_Head = &g_psEM_TE_FRM_Free_List;

        tgEM_Job_Execute__Submit_Free_Pool_Fixup( &tgUpdate_Init );
    };

    tgUpdate_Init.m_apsPool = g_apsEM_TE_SEC;
    tgUpdate_Init.m_asData_Lock = g_asEM_TE_SEC_Data_Lock;
    tgUpdate_Init.m_asNewDel_Lock = g_asEM_TE_SEC_NewDel_Lock;
    tgUpdate_Init.m_iMax = KTgEM_MAX_TE_SEC_POOL;
    tgUpdate_Init.m_pfnExecute = tgEM_Job_Execute__TE;
    tgUpdate_Init.m_pxuiFree_Trigger = &s_xuiJob_Trigger_TE_SEC;
    tgUpdate_Init.m_psUpdate_Data = tgJob_Cast.m_psJob_Data;

    bNeedFixUp = tgEM_Job_Execute__Submit_Event_Pool_Update( &tgUpdate_Init );
    if (bNeedFixUp)
    {
        tgUpdate_Init.m_psFree_Job = &s_sJob_TE_SEC__Free_Pool_Update;
        tgUpdate_Init.m_psFree_Lock = &g_sEM_TE_SEC_Lock.m_sLock;
        tgUpdate_Init.m_ppsFree_Pool_Head = &g_psEM_TE_SEC_Free_List;

        tgEM_Job_Execute__Submit_Free_Pool_Fixup( &tgUpdate_Init );
    };

    return (KTgS_OK);
}


/* ---- tgEM_Job_Execute__TE ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgRESULT tgEM_Job_Execute__TE( STg2_Job_PC psJob )
{
    union
    {
        TgUINT_F08_P                        m_psUntyped;
        STg2_EM_TE_Job_Update_PM_P          m_psJob_Data;
    }                                   tgJob_Cast;
    union
    {
        STg2_UT_ST__ST_Node_P               m_psElement;
        STg2_EM_TB_P                        m_psJob;
    }                                   tgJob;
    STg2_EM_TE_Job_Update_PM_P          psJob_Data;
    TgSINT_F32                          iIndex;

    TgPARAM_CHECK(nullptr != psJob);

    tgJob_Cast.m_psUntyped = psJob->m_auiData;
    psJob_Data = tgJob_Cast.m_psJob_Data;

    TgPARAM_CHECK(nullptr != psJob_Data->m_psPool);

    /* Add new time events to the waiting or processing linked lists */
    psJob_Data->m_enStage = ETgEM_UPDATE_STAGE__NEW_STITCH;
    tgJob.m_psElement = tgCM_UT_LF__ST__Pop( &psJob_Data->m_psPool->m_sNew );
    while (nullptr != tgJob.m_psJob)
    {
        tgEM_List_Stitch( &psJob_Data->m_psPool->m_psWaiting, tgJob.m_psJob );
        tgJob.m_psElement = tgCM_UT_LF__ST__Pop( &psJob_Data->m_psPool->m_sNew );
    };

    /* Process all of the time events attached to the linked lists */
    /* This includes moving deleted entities to the free list */
    if (psJob_Data->m_bIsPaused)
    {
        tgCM_UT_LF__SN__Lock_Spin( psJob_Data->m_psData_Lock );
        psJob_Data->m_enStage = ETgEM_UPDATE_STAGE__PAUSED;
        tgEM_TE_Update_Internal__Paused( psJob_Data->m_psPool, psJob_Data );
        tgCM_UT_LF__SN__Signal( psJob_Data->m_psData_Lock );
    }
    else
    {
        STg2_EM_TE                          asCallback[KTgEM_NUM_TE_IN_POOL];
        TgSINT_F32                          niCallback;
        STg2_EM_TB_P                        psFree_TB;

        tgCM_UT_LF__SN__Lock_Spin( psJob_Data->m_psData_Lock );
        psJob_Data->m_enStage = ETgEM_UPDATE_STAGE__WAITING;
        tgEM_TE_Update_Internal__Waiting( psJob_Data->m_psPool, psJob_Data );
        psJob_Data->m_enStage = ETgEM_UPDATE_STAGE__PROCESS;
        tgEM_TE_Update_Internal__Process( &psFree_TB, &niCallback, asCallback, psJob_Data->m_psPool, psJob_Data );
        tgCM_UT_LF__SN__Signal( psJob_Data->m_psData_Lock );

        for (iIndex = 0; iIndex < niCallback; ++iIndex)
        {
            asCallback[iIndex].m_pfnCallback( asCallback[iIndex].m_uiParam );
        };

        if (nullptr != psFree_TB)
        {
            tgCM_UT_LF__SN__Lock_Spin( psJob_Data->m_psNewDel_Lock );
            psJob_Data->m_enStage = ETgEM_UPDATE_STAGE__DELETE;
            tgEM_TE_Update_Internal__Delete( psJob_Data->m_psPool, psFree_TB, psJob_Data );
            tgCM_UT_LF__SN__Signal( psJob_Data->m_psNewDel_Lock );
        }
    };

    psJob_Data->m_enStage = ETgEM_UPDATE_STAGE__DONE;
    atomic_thread_fence( memory_order_seq_cst );

    atomic_fetch_sub( psJob_Data->m_pxuiFree_Trigger, 1 );

    return (KTgS_OK);
}


/* ---- tgEM_Job_Execute__Free_Pool ---------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
static TgRESULT tgEM_Job_Execute__Free_Pool( STg2_Job_PC psJob )
{
    union
    {
        TgUINT_F08_P                            m_psUntyped;
        STg2_EM_TE_Job_Free_Pool_PM_P           m_psJob_Data;
    }                                   tgJob_Cast;

    STg2_EM_TE_Job_Free_Pool_PM_P       psJob_Data;

    TgSINT_F32                          iSort0, iSort1, iIndex;
    STg2_EM_TE_Pool_PP                  ppsFP_List; /* Dynamic array holding all of the valid pools with free elements */

    TgSINT_F32                          niFree = 0;

    TgPARAM_CHECK(nullptr != psJob);

    tgJob_Cast.m_psUntyped = psJob->m_auiData;
    psJob_Data = tgJob_Cast.m_psJob_Data;

    /* Lock the free pools for the system. */
    TgPARAM_CHECK(nullptr != psJob_Data->m_psFree_Lock);
    tgCM_UT_LF__SN__Lock_Spin( psJob_Data->m_psFree_Lock );

    TgALLOCA( STg2_EM_TE_Pool_P, (TgRSIZE)psJob_Data->m_niMax_Pool, ppsFP_List );
    if (!ppsFP_List)
    {
        TgFREEA( ppsFP_List );
        tgCM_UT_LF__SN__Signal( psJob_Data->m_psFree_Lock );
        return (KTgE_FAIL);
    }

    /* Collect all of the pools that have free lists */
    for (iIndex = 0; iIndex < psJob_Data->m_niMax_Pool; ++iIndex)
    {
        tgCM_UT_LF__SN__Lock_Spin( &psJob_Data->m_psNewDel_Lock[iIndex].m_sLock );

        if (nullptr != psJob_Data->m_ppsPool_List[iIndex] && nullptr != psJob_Data->m_ppsPool_List[iIndex]->m_psFree)
        {
            ppsFP_List[niFree++] = psJob_Data->m_ppsPool_List[iIndex];
        }
        else
        {
            tgCM_UT_LF__SN__Signal( &psJob_Data->m_psNewDel_Lock[iIndex].m_sLock );
        };
    };

    if (0 == niFree)
    {
        TgFREEA( ppsFP_List );
        tgCM_UT_LF__SN__Signal( psJob_Data->m_psFree_Lock );
        return (KTgS_OK);
    }

    /* Free Pool Sort - The most filled pools are the top of the free stack */
    for (iSort0 = 0; iSort0 < niFree; ++iSort0)
    {
        TgSINT_F32                          niUsed = ppsFP_List[iSort0]->m_niUsed;
        TgSINT_F32                          iSort_Swap = -1;

        for (iSort1 = iSort0 + 1; iSort1 < niFree; ++iSort1)
        {
            if (ppsFP_List[iSort1]->m_niUsed > niUsed)
            {
                niUsed = ppsFP_List[iSort1]->m_niUsed;
                iSort_Swap = iSort1;
            };
        };

        if (iSort_Swap >= 0)
        {
            STg2_EM_TE_Pool_P                   psSwap = ppsFP_List[iSort0];

            ppsFP_List[iSort0] = ppsFP_List[iSort1];
            ppsFP_List[iSort1] = psSwap;
        };
    };

    /* Look to remove empty pools */
    if (niFree >= 2)
    {
        do
        {
            TgSINT_F32_C                        iPool = ppsFP_List[niFree - 1]->m_iPool;
            STg2_EM_TE_Pool_P                   psDel;

            if (0 == ppsFP_List[niFree - 1]->m_niUsed && tgCM_UT_LF__ST__Is_Empty( &ppsFP_List[niFree - 1]->m_sNew ))
            {
                break;
            };

            tgCM_UT_LF__SN__Lock_Spin( &psJob_Data->m_psData_Lock[iPool].m_sLock );

            psDel = psJob_Data->m_ppsPool_List[iPool];
            psJob_Data->m_ppsPool_List[iPool] = nullptr;

            tgCM_UT_LF__ST__Free( &ppsFP_List[niFree - 1]->m_sNew );
            TgFREE_POOL( psDel );
            --niFree;

            tgCM_UT_LF__SN__Signal( &psJob_Data->m_psData_Lock[iPool].m_sLock );
            tgCM_UT_LF__SN__Signal( &psJob_Data->m_psNewDel_Lock[iPool].m_sLock );
        }
        while (0);
    };


    /* Link up the free pool list and assigned into the link list head */
    for (iIndex = 0; iIndex + 1 < niFree; ++iIndex)
    {
        ppsFP_List[iIndex]->m_psFree_Next = ppsFP_List[iIndex + 1];
        tgCM_UT_LF__SN__Signal( &psJob_Data->m_psNewDel_Lock[ppsFP_List[iIndex]->m_iPool].m_sLock );
    };

    ppsFP_List[niFree - 1]->m_psFree_Next = nullptr;
    tgCM_UT_LF__SN__Signal( &psJob_Data->m_psNewDel_Lock[ppsFP_List[niFree - 1]->m_iPool].m_sLock );

    *psJob_Data->m_ppsFree_Pool_Head = ppsFP_List[0];


    /* Free the system lock and terminate */
    TgFREEA( ppsFP_List );
    tgCM_UT_LF__SN__Signal( psJob_Data->m_psFree_Lock );
    return (KTgS_OK);
}


/* ---- tgEM_Print_Pool_Stat ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgS_STAT__COMMON
static TgVOID tgEM_Print_Pool_Stat( STg2_EM_TE_Pool_PCU psPool, STg2_Output_P psOutput )
{
    STg2_EM_TB_P                        psTB;

    for (psTB = psPool->m_psWaiting; psTB != nullptr; psTB = psTB->m_psHead_Next)
    {
        tgIO_PrintF_NCZ( psOutput, "% 2d (% 9d) ", psPool->m_iPool, psPool->m_atiEM_TE_FRM_NoSingleton[psTB - psPool->m_psWaiting].m_uiI );

        if (psTB->m_iStart < 0)
        {
            tgIO_PrintF_NCZ( psOutput, "SEC   %5.2f - %5.2f", (TgFLOAT64)psTB->m_fStart, (TgFLOAT64)psTB->m_fEnd );
        }
        else
        {
            tgIO_PrintF_NCZ( psOutput, "FRM   %8d - %8d", psTB->m_iStart, psTB->m_iEnd );
        };

        tgIO_PrintF_NCZ( psOutput, " Waiting\n" );
    };

    for (psTB = psPool->m_psActive; psTB != nullptr; psTB = psTB->m_psHead_Next)
    {
        tgIO_PrintF_NCZ( psOutput, "% 2d (% 9d) ", psPool->m_iPool, psPool->m_atiEM_TE_FRM_NoSingleton[psTB - psPool->m_psActive].m_uiI );

        if (psTB->m_iStart < 0)
        {
            tgIO_PrintF_NCZ( psOutput, "SEC   %5.2f - %5.2f", (TgFLOAT64)psTB->m_fStart, (TgFLOAT64)psTB->m_fEnd );
        }
        else
        {
            tgIO_PrintF_NCZ( psOutput, "FRM   %8d - %8d", psTB->m_iStart, psTB->m_iEnd );
        };

        tgIO_PrintF_NCZ( psOutput, " Process\n" );
    };
}
/*# TgS_STAT__COMMON */
#endif