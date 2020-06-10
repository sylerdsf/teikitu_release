/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Profile.c
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
#if TgCOMPILE__PROFILE


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Types                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgTYPE_STRUCT(STg2_PROFILE_TL_CALL_ID_RECORD,)
{
    union
    {
        TgPROFILE_TL_CALL_ID_SINGLETON              m_tiCall_Singleton;
        STg2_UT_ST__ST_Node                         m_sNext;
    };
    TgPROFILE_TL_ID                             m_tiProf;
    TgSINT_F64                                  m_iStartOrElapsed;
};

TgTYPE_STRUCT(STg2_PROFILE_CALL_ID_RECORD,)
{
    union
    {
        TgPROFILE_CALL_ID_SINGLETON                 m_tiCall_Singleton;
        STg2_UT_ST__ST_Node                         m_sNext;
    };
    TgPROFILE_ID                                m_tiProf;
    TgSINT_F64                                  m_iStartOrElapsed;
};




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */



#define VAR_DECL                            static TgTLS
#define STORAGE(A)                          tls_##A
#define FCN(A)                              tgPF_TL_##A
#define PROFILE_ID(A,B)                     A##PROFILE_TL_ID##B
#define PROFILE_CALL_ID(A,B)                A##PROFILE_TL_CALL_ID##B
#define MT_CODE(A)

#include "TgS Common - Profile.c_inc"

#define VAR_DECL                            static
#define STORAGE(A)                          s_##A
#define FCN(A)                              tgPF_##A
#define PROFILE_ID(A,B)                     A##PROFILE_ID##B
#define PROFILE_CALL_ID(A,B)                A##PROFILE_CALL_ID##B
#define MT_CODE(A)                          A

#include "TgS Common - Profile.c_inc"


#else

/* 2183: Empty Translation Unit */
TgEXTN TgVOID Prevent2183_Common_Profile( TgVOID );
TgVOID Prevent2183_Common_Profile( TgVOID )
{
}

#endif /* TgCOMPILE__PROFILE */
