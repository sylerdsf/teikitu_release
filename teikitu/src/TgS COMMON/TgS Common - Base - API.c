/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - API.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Random Number Generator - Mersenne Twister */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* M. Matsumoto and T. Nishimura, "Mersenne Twister: A 623-Dimensionally Equidistributed Uniform Pseudo-Random Number Generator",
   ACM Transactions on Modelling and Computer Simulation, Vol. 8, No. 1, January 1998, pp 3-30.
   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   Copyright (C) 2000 - 2009, Richard J. Wagner
   All rights reserved.
   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
     1. Redistribution of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
     2. Redistribution in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials
        provided with the distribution.
     3. The names of its contributors may not be used to endorse or promote products derived from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
   USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Macros                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if TgS_STAT__COMMON
    #define STAT(...)                       __VA_ARGS__
#else
    #define STAT(...)
#endif

#if defined(__STDC_LIB_EXT1__)

    #define TgFOPEN(A,...)                      fopen_s( &(A), __VA_ARGS__ )

#else

    #define TgFOPEN(A,...)                      A = fopen( __VA_ARGS__ )

/*# defined(__STDC_LIB_EXT1__) */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Constants - Random Number Generator                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

enum { KTgMERSENNE_TWISTER_PERIOD_N         = 624 };
enum { KTgMERSENNE_TWISTER_PERIOD_M         = 397 };
enum { KTgMERSENNE_TWISTER_PERIOD_NM        = KTgMERSENNE_TWISTER_PERIOD_N - KTgMERSENNE_TWISTER_PERIOD_N };

#define KTgMERSENNE_TWISTER_UPPER_MASK      0x80000000UL /* MSB */
#define KTgMERSENNE_TWISTER_LOWER_MASK      0x7fffffffUL /* LSB */




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions and Data                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgEXTN TgVOID                               tgCM_Random_MT_Reload( TgVOID );

CLANG_WARN_DISABLE_PUSH(missing-variable-declarations)
TgTLS TgSINT_F32                            tls_uiMT_Index = KTgMERSENNE_TWISTER_PERIOD_N + 1;
TgTLS union
{
    TgUINT_F32                                  m_uiData[KTgMERSENNE_TWISTER_PERIOD_N];
    TgVEC_U32_04_1                              m_vData[KTgMERSENNE_TWISTER_PERIOD_N >> 2];
}                                           tls_uiMT_State;
CLANG_WARN_DISABLE_POP(missing-variable-declarations)

static TgUINT_F32_C                         s_uiMT_Magic[2] = { 0x0UL, 0x9908b0dfUL };

#if !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD
STg1_MT_MX                                  g_csMT_Lock;
/*# !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD */
#endif

#if TgS_STAT__COMMON
static TgSINT_F64_A                               s_iStat_File_Read, s_iStat_File_Write;
#endif

#if !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD
static ETgMODULE_STATE                      s_enRND_MT_State = ETgMODULE_STATE__FREED;
/*# !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD */
#endif




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCM_Init_Random_MT ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCM_Init_Random_MT( TgUINT_F32 uiSeed )
{
    TgUINT_F32                          i;

#if !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD
    if (s_enRND_MT_State != ETgMODULE_STATE__BOOTED)
    {
        TgVERIFY( KTgS_OK == tgPM_MT_MX_Init( &g_csMT_Lock ) );
        s_enRND_MT_State = ETgMODULE_STATE__BOOTED;
    }

    tgPM_MT_MX_Wait_Block( &g_csMT_Lock );
/*# !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD */
#endif

    tls_uiMT_State.m_uiData[0] = uiSeed & 0xFFFFFFFFUL;

    for (i = 1; i < KTgMERSENNE_TWISTER_PERIOD_N; ++i)
    {
        tls_uiMT_State.m_uiData[i] = (1812433253UL * (tls_uiMT_State.m_uiData[i - 1] ^ (tls_uiMT_State.m_uiData[i - 1] >> 30)) + i);
        tls_uiMT_State.m_uiData[i] &= 0xFFFFFFFFUL;
    }

    tls_uiMT_Index = KTgMERSENNE_TWISTER_PERIOD_N;

#if !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD
    tgPM_MT_MX_Release( &g_csMT_Lock );
/*# !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD */
#endif
}


/* ---- tgCM_Init_Random_MT__Key_List -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCM_Init_Random_MT__Key_List( TgUINT_F32_PU puiKeyList, TgUINT_F32 nuiKey )
{
    TgUINT_F32                          i, j, k;

#if !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD
    tgPM_MT_MX_Wait_Block( &g_csMT_Lock );
/*# !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD */
#endif

    tgCM_Init_Random_MT(19650218UL);

    i = 1;
    j = 0;
    k = tgCM_MIN_U32( KTgMERSENNE_TWISTER_PERIOD_N, nuiKey );

    for (; k; --k)
    {
        tls_uiMT_State.m_uiData[i] ^= (tls_uiMT_State.m_uiData[i - 1] ^ (tls_uiMT_State.m_uiData[i - 1] >> 30)) * 1664525UL;
        tls_uiMT_State.m_uiData[i] += puiKeyList[j] + j;
        tls_uiMT_State.m_uiData[i] &= 0xFFFFFFFFUL;
        ++i; ++j;

        if (i >= KTgMERSENNE_TWISTER_PERIOD_N)
        {
            tls_uiMT_State.m_uiData[0] = tls_uiMT_State.m_uiData[KTgMERSENNE_TWISTER_PERIOD_N - 1];
            i = 1;
        };

        if (j >= nuiKey)
        {
            j = 0;
        };
    };

    for (k = KTgMERSENNE_TWISTER_PERIOD_N - 1; k; --k)
    {
        tls_uiMT_State.m_uiData[i] ^= (tls_uiMT_State.m_uiData[i - 1] ^ (tls_uiMT_State.m_uiData[i - 1] >> 30)) * 1566083941UL;
        tls_uiMT_State.m_uiData[i] = (tls_uiMT_State.m_uiData[i] - i) & 0xFFFFFFFFUL;
        ++i;

        if (i >= KTgMERSENNE_TWISTER_PERIOD_N)
        {
            tls_uiMT_State.m_uiData[0] = tls_uiMT_State.m_uiData[KTgMERSENNE_TWISTER_PERIOD_N - 1];
            i = 1;
        };
    };

    tls_uiMT_State.m_uiData[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */

#if !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD
    tgPM_MT_MX_Release( &g_csMT_Lock );
/*# !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD */
#endif
}


/* ---- tgCM_RAND_MT_U32 --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* Generate a random number [0,0xFFFFFFFF] */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgUINT_F32 tgCM_RAND_MT_U32( TgVOID )
{
    TgUINT_F32                          uiRand_Val;

#if !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD
    tgPM_MT_MX_Wait_Block( &g_csMT_Lock );
/*# !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD */
#endif

    if (tls_uiMT_Index >= KTgMERSENNE_TWISTER_PERIOD_N)
    {
        tgCM_Random_MT_Reload();
        TgCRITICAL( tls_uiMT_Index == 0 );
    }

    uiRand_Val = tls_uiMT_State.m_uiData[tls_uiMT_Index++];
    uiRand_Val ^= (uiRand_Val >> 11);
    uiRand_Val ^= (uiRand_Val << 7) & 0x9d2c5680UL;
    uiRand_Val ^= (uiRand_Val << 15) & 0xefc60000UL;
    uiRand_Val ^= (uiRand_Val >> 18);

#if !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD
    tgPM_MT_MX_Release( &g_csMT_Lock );
/*# !TgCOMPILE__THREAD_LOCAL && TgCOMPILE__THREAD */
#endif

    return (uiRand_Val);
}


/* ---- tgCM_RAND_NRM_F32 -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgFLOAT32 tgCM_RAND_NRM_F32( TgFLOAT32_C fMean, TgFLOAT32_C fStdDev )
{
    TgFLOAT32                           fX, fY, fR, fS;

    do
    {
        fX = 2.0F * tgCM_RAND_F32() - 1.0F;
        fY = 2.0F * tgCM_RAND_F32() - 1.0F;
        fR = fX*fX + fY*fY;
    }
    while (fR >= 1.0F || fR == 0.0F);

    fS = tgPM_SQRT_F32( -2.0F * tgPM_LOG_F32( fR ) / fR );

    return fMean + fX * fS * fStdDev;
}


/* ---- tgCM_Random_Name --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgCM_Random_Name( TgCHAR_NC_P nczBuffer, TgRSIZE_C nbyBuffer )
{
    if (1 >= nbyBuffer)
    {
        return (KTgE_FAIL);
    };

    for (TgRSIZE uiIndex = 0; uiIndex + 1 < nbyBuffer; uiIndex += 4)
    {
        TgUINT_F32                          uiRand;

        uiRand = tgCM_RAND_MT_U32();

        switch (tgCM_MIN_UMAX( 4, nbyBuffer - uiIndex - 1 ))
        {
            case 4: *nczBuffer++ = (uiRand & 1)*('a' + ((uiRand >> 1) & 25)) + (1 - (uiRand & 1))*('A' + ((uiRand >> 1) & 25));
                    uiRand >>= 8;
            case 3: *nczBuffer++ = (uiRand & 1)*('a' + ((uiRand >> 1) & 25)) + (1 - (uiRand & 1))*('A' + ((uiRand >> 1) & 25));
                    uiRand >>= 8;
            case 2: *nczBuffer++ = (uiRand & 1)*('a' + ((uiRand >> 1) & 25)) + (1 - (uiRand & 1))*('A' + ((uiRand >> 1) & 25));
                    uiRand >>= 8;
            case 1: *nczBuffer++ = (uiRand & 1)*('a' + ((uiRand >> 1) & 25)) + (1 - (uiRand & 1))*('A' + ((uiRand >> 1) & 25));
            case 0: break;
        };
    };

    *nczBuffer = 0;

    return (KTgS_OK);
}




/* == Memory Functions =========================================================================================================================================================== */

/* ---- tgMM_Copy ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgMM_Copy( TgVOID_PU NONULL pDest, TgRSIZE_C nbyDest, TgVOID_CPU NONULL pSrc, TgRSIZE_C nbySrc )
{
    TgPARAM_CHECK(nullptr != pDest && nullptr != pSrc && nbyDest >= nbySrc && nbyDest > 0 && nbySrc > 0 && nbyDest <= KTgMAX_RSIZE && nbySrc <= KTgMAX_RSIZE);
    memcpy( pDest, pSrc, nbySrc );
    return (KTgS_OK);
}


/* ---- tgMM_Move ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgMM_Move( TgVOID_PU pDest, TgRSIZE_C nuiDest, TgVOID_CPU pSrc, TgRSIZE_C nuiSrc )
{
    memmove( pDest, pSrc, nuiSrc );
    return (KTgS_OK);
}


/* ---- tgMM_Set_U08 ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgMM_Set_U08( TgVOID_PU pDest, TgRSIZE_C nuiU08, TgUINT_E08_C uiFill )
{
    memset( pDest, uiFill, nuiU08 );
    return (KTgS_OK);
}


/* ---- tgMM_Set_U08_0x00 -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgMM_Set_U08_0x00( TgVOID_PU pDest, TgRSIZE_C nuiU08 )
{
    memset( pDest, 0x00, nuiU08 );
    return (KTgS_OK);
}


/* ---- tgMM_Set_U08_0xFF -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgMM_Set_U08_0xFF( TgVOID_PU pDest, TgRSIZE_C nuiU08 )
{
    memset( pDest, 0xFF, nuiU08 );
    return (KTgS_OK);
}


/* ---- tgMM_Compare ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgSINT_F32 tgMM_Compare( TgVOID_CPU pCmp0, TgRSIZE_C nuiCmp0, TgVOID_CPU pCmp1, TgRSIZE_C nuiCmp1 )
{
    return (memcmp( pCmp0, pCmp1, nuiCmp1 ));
}




/* == Time Functions ============================================================================================================================================================= */

static TgSINT_F64                   s_iInit_Start_NanoSeconds;
static TgSINT_F64                   s_iStart_NanoSeconds[ETgTIME_CHANNEL__COUNT - 1];
static TgFLOAT32                    s_fLast[ETgTIME_CHANNEL__COUNT - 1];
static TgFLOAT32                    s_fElapsed[ETgTIME_CHANNEL__COUNT - 1];
static TgFLOAT32                    s_fStop[ETgTIME_CHANNEL__COUNT - 1];


/* ---- timespec_get_ns ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgSINT_F64 timespec_get_nanoseconds( TgVOID ) /* Nano, Micro, Milli */
{
    struct timespec                     sTime;
    int                                 iRet;

    iRet = clock_gettime( CLOCK_REALTIME, &sTime );
    TgERROR(iRet >= 0);
    return sTime.tv_sec * 1000LL * 1000LL * 1000LL + sTime.tv_nsec;
}


/* ---- tgTM_Init ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgTM_Init( TgVOID )
{
    s_iInit_Start_NanoSeconds = timespec_get_nanoseconds();
}


/* ---- tgTM_Query_Counter_Tick -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgSINT_F64 tgTM_Query_Counter_Tick( TgVOID )
{
    TgSINT_F64                          iTime;

    iTime = timespec_get_nanoseconds();
    return (iTime - s_iInit_Start_NanoSeconds);
}


/* ---- tgTM_Counter_To_MSec ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgFLOAT32 tgTM_Counter_Tick_To_MilliSeconds( TgSINT_F64_C iTime )
{
    return ((TgFLOAT32)((TgFLOAT64)(iTime) / 1000.0 / 1000.0 ));
}


/* ---- tgTM_Query_Time ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgFLOAT32 tgTM_Query_Time( TgVOID )
{
    return (tgTM_Counter_Tick_To_MilliSeconds( tgTM_Query_Counter_Tick() ));
}


/* ---- tgTM_Channel_Query_Time -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgFLOAT32 tgTM_Channel_Query_Time( ETgTIMER_CHANNEL_C enChannel )
{
    TgPARAM_CHECK(enChannel < ETgTIME_CHANNEL__WALL);
    return (tgPM_FSEL_F32( -s_fStop[enChannel], tgTM_Query_Time(), s_fStop[enChannel] ));
}


/* ---- tgTM_Channel_Elapsed_Time ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgFLOAT32 tgTM_Channel_Elapsed_Time( ETgTIMER_CHANNEL_C enChannel )
{
    TgPARAM_CHECK(enChannel < ETgTIME_CHANNEL__WALL);
    return (s_fElapsed[enChannel]);
}


/* ---- tgTM_Channel_Reset ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgTM_Channel_Reset( ETgTIMER_CHANNEL_C enChannel )
{
    TgPARAM_CHECK(enChannel < ETgTIME_CHANNEL__WALL);
    s_iStart_NanoSeconds[enChannel] = timespec_get_nanoseconds();
    s_fLast[enChannel] = tgTM_Query_Time();
    s_fElapsed[enChannel] = 0.0F;
    s_fStop[enChannel] = 0.0F;
}


/* ---- tgTM_Channel_Start ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgTM_Channel_Start( ETgTIMER_CHANNEL_C enChannel )
{
    TgPARAM_CHECK(enChannel < ETgTIME_CHANNEL__WALL);
    if (!(s_fStop[enChannel] <= 0.0F))
    {
        s_fLast[enChannel] = tgTM_Query_Time();
        s_fStop[enChannel] = 0.0F;
    };
}


/* ---- tgTM_Channel_Stop -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgTM_Channel_Stop( ETgTIMER_CHANNEL_C enChannel )
{
    TgPARAM_CHECK(enChannel < ETgTIME_CHANNEL__WALL);
    if (!(s_fStop[enChannel] > 0.0F))
    {
        s_fStop[enChannel] = s_fLast[enChannel];
    };
}


/* ---- tgTM_Channel_Update ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgTM_Channel_Update( ETgTIMER_CHANNEL_C enChannel )
{
    TgPARAM_CHECK(enChannel < ETgTIME_CHANNEL__WALL);
    if (!(s_fStop[enChannel] > 0.0F))
    {
        TgFLOAT32_C fTime = tgTM_Query_Time();
        s_fElapsed[enChannel] = tgCM_MAX_F32( KTgEPS_F32, fTime - s_fLast[enChannel] );
        s_fLast[enChannel] = fTime;
        s_fStop[enChannel] = 0.0F;
    };
}


/* ---- tgTM_Channel_Step -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgTM_Channel_Step( ETgTIMER_CHANNEL_C enChannel, TgFLOAT32_C fTimeAdvance )
{
    TgPARAM_CHECK(enChannel < ETgTIME_CHANNEL__WALL);
    if (!(s_fStop[enChannel] <= 0.0F))
    {
        s_fElapsed[enChannel] = fTimeAdvance;
        s_fStop[enChannel] += fTimeAdvance;
    };
}




/* == IO Functions =============================================================================================================================================================== */

/* ---- tgIO_File_Open ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgSINT_PTR tgIO_File_Open( TgCHAR_MB_CPC NONULL mbzFile, TgRSIZE_C nbyMaxFile, TgSINT_F32_C enAccessMask )
{
    FILE                                *piFile;

    TgPARAM_CHECK(nullptr != mbzFile);

    piFile = nullptr;

    if ((ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE) == (enAccessMask & (ETgFILE_IO_ACCESS__READ | ETgFILE_IO_ACCESS__WRITE)))
    {
        TgFOPEN( piFile, mbzFile, "w+" );
    }
    else if (enAccessMask & ETgFILE_IO_ACCESS__READ)
    {
        TgFOPEN( piFile, mbzFile, "r+" );
    }
    else if (enAccessMask & ETgFILE_IO_ACCESS__WRITE)
    {
        TgFOPEN( piFile, mbzFile, "w+" );
    };

    return ((TgSINT_PTR)piFile);
}


/* ---- tgIO_File_Read ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgIO_File_Read( TgVOID_P NONULL pDest, TgSINT_PTR_C iFile, TgRSIZE uiTotalBytesToRead )
{
    TgRSIZE                             uiTotalBytesRead;

    uiTotalBytesRead = 0;
    while (uiTotalBytesToRead > 0)
    {
        TgRSIZE                             uiBytesToRead;
        TgRSIZE                             uiBytesRead;

        uiBytesToRead = uiTotalBytesToRead % KTgMAX_U32;
        uiBytesRead = fread( pDest, 1, uiBytesToRead, (FILE*)iFile );
        uiTotalBytesToRead -= uiBytesRead;
        uiTotalBytesRead += uiBytesRead;
        if (uiBytesToRead != uiBytesRead)
            break;
    };

    STAT( atomic_fetch_add( &s_iStat_File_Read, (TgSINT_F64 )uiTotalBytesRead ) );
    return (uiTotalBytesRead);
}


/* ---- tgIO_File_Write ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgIO_File_Write( TgSINT_PTR_C iFile, TgVOID_CP NONULL pSource, TgRSIZE uiTotalBytesToWrite )
{
    TgRSIZE                             uiTotalBytesWriten;

    uiTotalBytesWriten = 0;
    while (uiTotalBytesToWrite > 0)
    {
        TgRSIZE                             uiBytesWriten;
        TgRSIZE                             uiBytesWrite;

        uiBytesWrite = uiTotalBytesToWrite % KTgMAX_U32;
        uiBytesWriten = fwrite( pSource, 1, uiBytesWrite, (FILE*)iFile );
        uiTotalBytesToWrite -= uiBytesWriten;
        uiTotalBytesWriten += uiBytesWriten;
        if (uiBytesWrite != uiBytesWriten)
            break;
        pSource = (TgUINT_F08_CP )pSource + uiBytesWrite;
    };

    STAT( atomic_fetch_add( &s_iStat_File_Write, (TgSINT_F64 )uiTotalBytesWriten ) );
    return (uiTotalBytesWriten);
}


/* ---- tgIO_File_Flush ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgIO_File_Flush( TgSINT_PTR_C iFile )
{
    return (0 == fflush( (FILE*)iFile ) ? KTgS_OK : KTgE_FAIL);
}


/* ---- tgIO_File_Close ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgIO_File_Close( TgSINT_PTR_C iFile )
{
    return (0 == fclose( (FILE*)iFile ) ? KTgS_OK : KTgE_FAIL);
}


/* ---- tgIO_File_Valid ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL tgIO_File_Valid( TgSINT_PTR_C iFile )
{
    return (0 == iFile ? false : true);
}


/* ---- tgIO_File_Seek ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgSINT_MAX tgIO_File_Seek( TgSINT_PTR_C iFile, ETgIO_SEEK_C enSeek_Mode, TgSINT_MAX_C iPos )
{
    switch (enSeek_Mode)
    {
        case ETgIO_SEEK__BEGIN:
            fseek( (FILE*)iFile, (long)iPos, SEEK_SET );
            break;
        case ETgIO_SEEK__END:
            fseek( (FILE*)iFile, (long)iPos, SEEK_END );
            break;
        case ETgIO_SEEK__CURRENT:
            fseek( (FILE*)iFile, (long)iPos, SEEK_CUR );
            break;
    }

    return ((TgSINT_MAX)ftell( (FILE*)iFile ));
}


/* ---- tgIO_File_Size ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgIO_File_Size( TgSINT_PTR_C iFile )
{
    TgSINT_F32                          iCurrent;
    TgSINT_F32                          iSize;

    iCurrent = (TgSINT_F32 )ftell( (FILE*)iFile );
    fseek( (FILE*)iFile, 0, SEEK_END );
    iSize = (TgSINT_F32 )ftell( (FILE*)iFile );
    fseek( (FILE*)iFile, iCurrent, SEEK_SET );
    TgERROR(iSize >=0);

    return ((TgRSIZE)iSize);
}


/* ---- tgIO_Directory_Make ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgIO_Directory_Make( TgCHAR_MB_CPC NONULL mbzPath, TgRSIZE_C nbyMaxPath )
{
    return (0 == mkdir( mbzPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH ) || EEXIST == errno ? KTgS_OK : KTgE_FAIL);
}


/* ---- tgIO_Directory_Remove ---------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgIO_Directory_Remove( TgCHAR_MB_CPC NONULL mbzPath, TgRSIZE_C nbyMaxPath )
{
    return (0 == rmdir( mbzPath ) ? KTgS_OK : KTgE_FAIL);
}


/* ---- tgIO_Directory_Exists ---------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL tgIO_Directory_Exists( TgCHAR_MB_CPC NONULL mbzPath, TgRSIZE_C nbyMaxPath )
{
    struct stat sStatInfo = { 0 };
    return (0 == stat(mbzPath, &sStatInfo));
}


/* ---- tgIO_File_Delete --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgIO_File_Delete( TgCHAR_MB_CPC NONULL mbzFile, TgRSIZE_C nbyMaxFile )
{
    return (0 == remove( mbzFile ) ? KTgS_OK : KTgE_FAIL);
}


/* ---- tgIO_File_Copy ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgIO_File_Copy( TgCHAR_MB_CPC NONULL mbzDest, TgRSIZE_C nbyMaxDest, TgCHAR_MB_CPC NONULL mbzExisting, TgRSIZE_C nbyMaxExisting )
{
    FILE                                *pSource;
    FILE                                *pDest;
    TgUINT_F08                          uiBuffer[1024];
    TgRSIZE                             uiBytesRead;
    TgRSIZE                             uiBytesWriten;

    TgFOPEN( pSource, mbzExisting, "r" );
    if (!pSource)
        return (KTgE_FAIL);
    TgFOPEN( pDest, mbzDest, "w" );
    if (!pDest)
        return (KTgE_FAIL);

    uiBytesRead = 0;
    uiBytesWriten = 0;

    while (!feof( pSource ))
    {
        uiBytesRead = fread( uiBuffer, 1, 1024, pSource );
        uiBytesWriten = fwrite( uiBuffer, 1, uiBytesRead, pDest );

        if (uiBytesRead != uiBytesWriten)
            break;
    };

    fclose( pDest );
    fclose( pSource );

    return (uiBytesRead != uiBytesWriten ? KTgE_FAIL : KTgS_OK);
}


/* ---- tgIO_File_Move ----------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT tgIO_File_Move( TgCHAR_MB_CPC NONULL mbzDest, TgRSIZE_C nbyMaxDest, TgCHAR_MB_CPC NONULL mbzExisting, TgRSIZE_C nbyMaxExisting )
{
    if (TgSUCCEEDED(tgIO_File_Copy( mbzDest, nbyMaxDest, mbzExisting, nbyMaxExisting )))
    {
        if (TgSUCCEEDED( tgIO_File_Delete( mbzExisting, nbyMaxExisting ) ))
        {
            return (KTgS_OK);
        }
    }
    return (KTgE_FAIL);
}


/* ---- tgIO_File_Exists --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL tgIO_File_Exists( TgCHAR_MB_CPC NONULL mbzFile, TgRSIZE_C nbyMaxFile )
{
   struct stat sStatInfo = { 0 };
   return (0 == stat(mbzFile, &sStatInfo));
}




/* ---- DBG ERR ------------------------------------------------------------------------------------------------------------------------------------------------------------------ */

/* ---- tgPM_DBG_ERR_Write_Byte -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgPM_DBG_ERR_Write_Byte( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgUINT_F08_C UNUSED_PARAM ptbUnused )
{
    return 0;
}


/* ---- tgPM_DBG_ERR_Write ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgPM_DBG_ERR_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _niText)
{
    printf( "%.*s", (int)(_niText / sizeof(TgCHAR_MB)), (TgCHAR_MB_CP)mbzText );
    return 0;
}


/* ---- tgPM_DBG_OUT_Write_Byte -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgPM_DBG_OUT_Write_Byte( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgUINT_F08_C UNUSED_PARAM ptbUnused )
{
    return 0;
}


/* ---- tgPM_DBG_OUT_Write ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRSIZE tgPM_DBG_OUT_Write( STg2_Output_PC UNUSED_PARAM psOut, TgRSIZE_C UNUSED_PARAM uiOffset, TgVOID_CP mbzText, TgRSIZE_C _niText)
{
    printf( "%.*s", (int)(_niText / sizeof(TgCHAR_MB)), (TgCHAR_MB_CP)mbzText );
    return 0;
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions                                                                                                                                                           */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCM_Random_MT_Reload ---------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCM_Random_MT_Reload( TgVOID )
{
    TgUINT_F32                          uiIndex, uiSeed;

    if (KTgMERSENNE_TWISTER_PERIOD_N + 1 == tls_uiMT_Index)
    {
        tgCM_Init_Random_MT( 4357UL );
    };

    for (uiIndex = 0; uiIndex < KTgMERSENNE_TWISTER_PERIOD_NM; ++uiIndex)
    {
        uiSeed = (tls_uiMT_State.m_uiData[uiIndex] & KTgMERSENNE_TWISTER_UPPER_MASK);
        uiSeed |= (tls_uiMT_State.m_uiData[uiIndex + 1] & KTgMERSENNE_TWISTER_LOWER_MASK);
        tls_uiMT_State.m_uiData[uiIndex] = tls_uiMT_State.m_uiData[uiIndex + KTgMERSENNE_TWISTER_PERIOD_N] ^ (uiSeed >> 1);
        tls_uiMT_State.m_uiData[uiIndex] ^= s_uiMT_Magic[uiSeed & 0x1UL];
    };

    for (; uiIndex < KTgMERSENNE_TWISTER_PERIOD_N - 1; ++uiIndex)
    {
        uiSeed = (tls_uiMT_State.m_uiData[uiIndex] & KTgMERSENNE_TWISTER_UPPER_MASK);
        uiSeed |= (tls_uiMT_State.m_uiData[uiIndex + 1] & KTgMERSENNE_TWISTER_LOWER_MASK);
        tls_uiMT_State.m_uiData[uiIndex] = tls_uiMT_State.m_uiData[uiIndex - KTgMERSENNE_TWISTER_PERIOD_NM] ^ (uiSeed >> 1);
        tls_uiMT_State.m_uiData[uiIndex] ^= s_uiMT_Magic[uiSeed & 0x1UL];
    };

    uiSeed = (tls_uiMT_State.m_uiData[KTgMERSENNE_TWISTER_PERIOD_N - 1] & KTgMERSENNE_TWISTER_UPPER_MASK);
    uiSeed |= (tls_uiMT_State.m_uiData[0] & KTgMERSENNE_TWISTER_LOWER_MASK);
    tls_uiMT_State.m_uiData[KTgMERSENNE_TWISTER_PERIOD_N - 1] =
        tls_uiMT_State.m_uiData[KTgMERSENNE_TWISTER_PERIOD_N - 1] ^ (uiSeed >> 1);
    tls_uiMT_State.m_uiData[KTgMERSENNE_TWISTER_PERIOD_N - 1] ^= s_uiMT_Magic[uiSeed & 0x1UL];

    tls_uiMT_Index = 0;
}
