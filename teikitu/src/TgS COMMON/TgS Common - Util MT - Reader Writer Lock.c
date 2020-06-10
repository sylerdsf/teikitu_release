/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util MT - Reader Writer Lock.c
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
/*  Private Functions                                                                                                                                                              */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgCM_UT_MT__RW_DATA__Update ---------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgCM_UT_MT__RW_DATA__Update( STg2_UT_ST__RW_DATA_PCU psRW_DATA )
{
    TgUINT_F32_C                        uiIndex = psRW_DATA->m_uiIndex;
    TgUINT_F32_C                        uiMax = psRW_DATA->m_nuiThread;
    TgUINT_F32                          uiCount;

    for (uiCount = 0; uiCount < uiMax; ++uiCount)
    {
        TgUINT_F32_C                        uiThread_Index = (uiIndex + uiCount) % KTgMP_MAX_READ_WRITER_LOCK;
        STg1_MT_SM_P                        psExecute;

        if (psRW_DATA->m_abReader[uiThread_Index])
        {
            TgERROR(psRW_DATA->m_enState != ETgUTM_RW_STATE__Writing);
            TgERROR(nullptr != psRW_DATA->m_psExecute[uiThread_Index]);

            psRW_DATA->m_enState = ETgUTM_RW_STATE__Reading;
            ++psRW_DATA->m_nuiReader;
            ++psRW_DATA->m_uiIndex;
            --psRW_DATA->m_nuiThread;
            psExecute = psRW_DATA->m_psExecute[uiThread_Index];
            psRW_DATA->m_psExecute[uiThread_Index] = nullptr;
            tgPM_MT_SM_Signal( psExecute, 1 );
            continue;
        }
        else
        {
            if (0 == psRW_DATA->m_nuiReader)
            {
                TgERROR(psRW_DATA->m_enState == ETgUTM_RW_STATE__Waiting);
                TgERROR(nullptr != psRW_DATA->m_psExecute[uiThread_Index]);

                psRW_DATA->m_enState = ETgUTM_RW_STATE__Writing;
                ++psRW_DATA->m_uiIndex;
                --psRW_DATA->m_nuiThread;
                psExecute = psRW_DATA->m_psExecute[uiThread_Index];
                psRW_DATA->m_psExecute[uiThread_Index] = nullptr;
                tgPM_MT_SM_Signal( psExecute, 1 );
            };

            return;
        };
    };
}
