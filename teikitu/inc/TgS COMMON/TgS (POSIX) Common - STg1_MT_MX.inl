/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (POSIX) Common - STg1_MT_MX.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_STG1_MP_MX_INL) && TgCOMPILE__THREAD
#define TGS_COMMON_STG1_MP_MX_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgPM_MT_MX_Init ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRESULT tgPM_MT_MX_Init( STg1_MT_MX_PCU psMX, TgCHAR_MB_CPCU UNUSED_PARAM mbzName )
{
    TgSINT_F32                          iRet;
    pthread_mutexattr_t                 sMutexAttrib;

    pthread_mutexattr_init( &sMutexAttrib );
    pthread_mutexattr_settype( &sMutexAttrib, PTHREAD_MUTEX_RECURSIVE );
    iRet = pthread_mutex_init( &psMX->m_hMutex, &sMutexAttrib);
    TgVERIFY(0 == iRet);
    return (0 != iRet ? KTgE_FAIL : KTgS_OK);
}


/* ---- tgPM_MT_MX_Free ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgPM_MT_MX_Free( STg1_MT_MX_PCU psMX )
{
    TgVERIFY(0 <= pthread_mutex_destroy( &psMX->m_hMutex ));
}


/* ---- tgPM_MT_MX_Wait_Block ---------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgPM_MT_MX_Wait_Block( STg1_MT_MX_PCU psMX )
{
    TgVERIFY(0 == pthread_mutex_lock( &psMX->m_hMutex ));
}


/* ---- tgPM_MT_MX_Wait ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRESULT tgPM_MT_MX_Wait( STg1_MT_MX_PCU psMX )
{
    TgSINT_F32                          iRet;
    
    iRet = pthread_mutex_trylock( &psMX->m_hMutex );
    return (0 != iRet ? KTgE_FAIL : KTgS_OK);
}


/* ---- tgPM_MT_MX_Release ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgPM_MT_MX_Release( STg1_MT_MX_PCU psMX )
{
    TgVERIFY(0 == pthread_mutex_unlock( &psMX->m_hMutex ));
}


/* =============================================================================================================================================================================== */
#endif
