/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (POSIX) Common - Base - API [Platform].c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions and Data                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
#if TgCOMPILE__THREAD
static TgVOID_P                             tgTR_Thread_Start( TgVOID_P );
/*# TgCOMPILE__THREAD */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if TgCOMPILE__THREAD

/* ---- tgTR_Register_Main_Thread ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgTHREAD_ID tgTR_Register_Main_Thread( TgCHAR_MB_CPC szName )
{
    TgRSIZE                             uiIndex;
    TgTHREAD_ID                         tiThread;

    tgCM_UT_LF__SN__Lock_Spin( &g_sTR_Lock.m_sLock );
    for (uiIndex = 0; uiIndex < KTgMAX_THREAD_ENTRIES; ++uiIndex)
    {
        if (tgTHREAD_ID_Fetch_And_Is_Valid( nullptr, g_atiTR_Thread_Singleton + uiIndex ))
        {
            continue;
        };

        atomic_store( &g_auiTR_Thread_Stack[uiIndex], tgTR_Stack_Size() );
        g_afnTR_Thread_Function[uiIndex] = nullptr;
        g_auiTR_Thread_Param[uiIndex] = 0;
        g_aenTR_Thread_Priority[uiIndex] = ETgTHREAD_PRIORITY__NORMAL;
        g_aTR_Thread[uiIndex] = pthread_self();

    #if TgCOMPILE__THREAD_INFO
        g_aszTR_Name[uiIndex] = szName;
    #endif

        tiThread = tgTHREAD_ID_Init( g_atiTR_Thread_Singleton + uiIndex, (TgUINT_F32)uiIndex );
        tls_tiThread_Local = tiThread;

        tgCM_UT_LF__SN__Signal( &g_sTR_Lock.m_sLock );
        return (tiThread);
    };
    tgCM_UT_LF__SN__Signal( &g_sTR_Lock.m_sLock );
    return (KTgTHREAD_ID__INVALID);
}


/* ---- tgTR_Create -------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgTHREAD_ID tgTR_Create( TgPLATFORM_THREAD_FCN pfnThread, TgUINT_PTR_C uiParam, TgUINT_F32_C uiStack, ETgTHREAD_PRIORITY_C enPriority, TgOSCHAR_CPC szName )
{
    TgRSIZE                             uiIndex;
    TgSINT_F32                          iRet;
    pthread_attr_t                      sAttrib;
    TgRSIZE                             uiCurrentStack;
    TgTHREAD_ID                         tiThread;
    TgUN_SCALAR                         sParam;

    if (0 == pfnThread)
    {
        return (KTgTHREAD_ID__INVALID);
    }

    tgCM_UT_LF__SN__Lock_Spin( &g_sTR_Lock.m_sLock ); /* NOTE: This is done under a lock */
    for (uiIndex = 0; uiIndex < KTgMAX_THREAD_ENTRIES; ++uiIndex)
    {
        if (tgTHREAD_ID_Fetch_And_Is_Valid( nullptr, g_atiTR_Thread_Singleton + uiIndex ))
        {
            continue;
        };

        atomic_store( &g_auiTR_Thread_Stack[uiIndex], KTgMAX_SIZE_ALL-1 );
        g_afnTR_Thread_Function[uiIndex] = pfnThread;
        g_auiTR_Thread_Param[uiIndex] = uiParam;
        g_aenTR_Thread_Priority[uiIndex] = enPriority;

    #if TgCOMPILE__THREAD_INFO
        g_aszTR_Name[uiIndex] = szName;
    #endif

        tiThread = tgTHREAD_ID_Init( g_atiTR_Thread_Singleton + uiIndex, (TgUINT_F32)uiIndex );

        iRet = pthread_attr_init( &sAttrib );
        TgCRITICAL(0 <= iRet);
        iRet = pthread_attr_getstacksize( &sAttrib, &uiCurrentStack );
        TgCRITICAL(0 <= iRet);
        if (uiCurrentStack < uiStack)
        {
            TgVERIFY(0 <= pthread_attr_setstacksize( &sAttrib, uiStack ));
        }
        sParam.m_uiPTR = uiIndex;
        iRet = pthread_create( g_aTR_Thread + uiIndex, nullptr, tgTR_Thread_Start, sParam.m_pPTR );
        TgCRITICAL(0 <= iRet);
        iRet = pthread_attr_destroy( &sAttrib );
        TgCRITICAL(0 <= iRet);

        tgCM_UT_LF__SN__Signal( &g_sTR_Lock.m_sLock );
        return (tiThread);
    };
    tgCM_UT_LF__SN__Signal( &g_sTR_Lock.m_sLock );
    return (KTgTHREAD_ID__INVALID);
}


/* ---- tgTR_Query_Id ------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgTHREAD_ID tgTR_Query_Id( TgVOID )
{
#if !defined(TGS_FINAL) || !TgCOMPILE__THREAD_LOCAL
    pthread_t                           sThread;
    TgRSIZE                             uiIndex;

    tgCM_UT_LF__SN__Lock_Spin( &g_sTR_Lock.m_sLock );

    sThread = pthread_self();
    for (uiIndex = 0; uiIndex < KTgMAX_THREAD_ENTRIES; ++uiIndex)
    {
        if (sThread == g_aTR_Thread[uiIndex])
        {
            tgCM_UT_LF__SN__Signal( &g_sTR_Lock.m_sLock );
            TgERROR(tls_tiThread_Local.m_uiI == uiIndex);
            return (tgTHREAD_ID_Query_Unsafe(g_atiTR_Thread_Singleton + uiIndex));
        };
    };

    tgCM_UT_LF__SN__Signal( &g_sTR_Lock.m_sLock );
    TgCRITICAL_MSGF( 0, "%-16.16s(%-32.32s): Thread not found in thread pool!\n", "Thread", "Query Id" );
    return (KTgTHREAD_ID__INVALID);
/*# !defined(TGS_FINAL) ||  !TgCOMPILE__THREAD_LOCAL */
#else
    return (tgTHREAD_ID_Query_Unsafe(g_atiTR_Thread_Singleton + tls_uiThread_Index));
/*# !defined(TGS_FINAL) ||  !TgCOMPILE__THREAD_LOCAL */
#endif
}


/* ---- tgTR_Close --------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgTR_Close( TgTHREAD_ID tiThread )
{
    pthread_t                           sThreadOS;
    TgSINT_F32                          iRet;

    TgPARAM_CHECK((tiThread.m_uiKI != KTgID__INVALID_VALUE) && (tiThread.m_uiI < KTgMAX_THREAD_ENTRIES));

    /* Get the os handle */
    tgCM_UT_LF__SN__Lock_Spin( &g_sTR_Lock.m_sLock );

    TgERROR(0 != g_afnTR_Thread_Function[tiThread.m_uiI]);
    sThreadOS = g_aTR_Thread[tiThread.m_uiI];
    tgCM_UT_LF__SN__Signal( &g_sTR_Lock.m_sLock );

    iRet = pthread_join( sThreadOS, nullptr );
    TgVERIFY(0 <= iRet);

    /* Mark the thread slot as available */
    tgCM_UT_LF__SN__Lock_Spin( &g_sTR_Lock.m_sLock );
    g_afnTR_Thread_Function[tiThread.m_uiI] = 0;
    g_aTR_Thread[tiThread.m_uiI] = 0;
    atomic_store( &g_auiTR_Thread_Stack[tiThread.m_uiI], KTgMAX_SIZE_ALL );
    tgTHREAD_ID_Invalidate( g_atiTR_Thread_Singleton + tiThread.m_uiI );
    tgCM_UT_LF__SN__Signal( &g_sTR_Lock.m_sLock );
}


/* ---- tgTR_Status -------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
ETgTHREAD_STATUS tgTR_Status( TgTHREAD_ID tiThread )
{
    TgPARAM_CHECK((tiThread.m_uiKI != KTgID__INVALID_VALUE) && (tiThread.m_uiI < KTgMAX_THREAD_ENTRIES));

    if (tiThread.m_uiKI == KTgID__INVALID_VALUE || tiThread.m_uiI >= KTgMAX_THREAD_ENTRIES)
    {
        return (ETgTHREAD_STATUS__INVALID);
    }
    else
    {
        if (!tgTHREAD_ID_Is_Equal( g_atiTR_Thread_Singleton + tiThread.m_uiI, tiThread ))
        {
            return (ETgTHREAD_STATUS__INVALID);
        }
        else
        {
            TgRSIZE                             uiStack;

            uiStack = atomic_load( &g_auiTR_Thread_Stack[tiThread.m_uiI] );
            if (KTgMAX_SIZE_ALL == uiStack)
            {
                TgCRITICAL_MSG( false, "THREAD: Invalid state. There is a valid thread id with an invalid stack memory count." );
                return (ETgTHREAD_STATUS__INVALID);
            }
            else if (KTgMAX_SIZE_ALL-1 == uiStack)
            {
                return (ETgTHREAD_STATUS__INIT);
            }
            else
            {
                return (ETgTHREAD_STATUS__EXEC);
            };
        };
    };
}


/* ---- tgTR_Stack_Size ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgTR_Stack_Size( TgVOID )
{
    size_t                              uiStackSize;
    pthread_attr_t                      sAttr;
    
    pthread_attr_getstacksize(&sAttr, &uiStackSize);
    return (uiStackSize);
}


/*# TgCOMPILE__THREAD */
#endif


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions                                                                                                                                                           */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgTR_Thread_Start -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#if TgCOMPILE__THREAD
static TgVOID_P tgTR_Thread_Start( TgVOID_P pParam )
{
    TgUN_SCALAR                         sParam;
    TgUINT_F32                          uiRet = 1;
    pthread_attr_t                      sAttrib;
    TgSINT_F32                          iRet;
    TgSIZE_ALL                          uiCurrentStack;
    
    iRet = pthread_attr_getstacksize( &sAttrib, &uiCurrentStack );
    TgCRITICAL(0 <= iRet);

    sParam.m_pPTR = pParam;
    TgERROR(sParam.m_uiPTR <= KTgMAX_S32);
 
#if TgCOMPILE__THREAD_LOCAL
    tls_tiThread_Local = tgTHREAD_ID_Query_Unsafe( g_atiTR_Thread_Singleton + sParam.m_uiPTR );
#endif

    atomic_store( &g_auiTR_Thread_Stack[sParam.m_uiE32], uiCurrentStack );
    atomic_thread_fence( memory_order_seq_cst );

    uiRet = g_afnTR_Thread_Function[sParam.m_uiPTR]( g_auiTR_Thread_Param[sParam.m_uiPTR] );

    tgMM_Clear_Thread_Local_Cache();

    pthread_exit( (TgVOID_P)(TgUINT_PTR)uiRet );
}

/*# TgCOMPILE__THREAD */
#endif


MSVC_WARN_DISABLE_POP( 4770 )
