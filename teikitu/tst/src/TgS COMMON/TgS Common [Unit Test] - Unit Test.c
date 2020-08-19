/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] - Unit Test.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include "TgS COMMON/TgS Common [Unit Test] - Unit Test.h"


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Unit Test Data                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

static STg2_Profile_Record g_sPROFILE_UNIT_TEST__TEST_SET__EXECUTE;
static Test_Set *g_psTest_Set_Start = 0;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- Unit_Test__Sleep --------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Unit_Test__Sleep( TgUINT_F32_C uiNanoseconds )
{
#if TgCOMPILE__THREAD
    tgTR_Sleep( uiNanoseconds );
#else
    TgFLOAT32                               fStart;

    fStart = tgTM_Query_Time();
    while (tgTM_Query_Time() - fStart < (TgFLOAT32)uiMilliseconds)
    {
    }
#endif
}


/* ---- Unit_Test__Case_Init ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Unit_Test__Case_Init( Test_Case_PCU psTest_Case )
{
    tgMM_Set_U08_0x00( psTest_Case, sizeof( Test_Case ) );
}


/* ---- Unit_Test__Case_Execute -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT Unit_Test__Case_Execute( Test_Context_PCU psTest_Context, Test_Case_PCU psCase_Default )
{
    TgBOOL_C            bValid_Case = nullptr != psTest_Context->m_psRestart_Case;
    Test_Case_P                             psCase = bValid_Case ? psTest_Context->m_psRestart_Case : psCase_Default;
    TgRESULT                                tgRet = KTgS_OK;
    TgUINT_F32                              uiTest_Index = psTest_Context->m_psRestart_Case_Test;

    psTest_Context->m_psRestart_Case_Test = 0;
    psTest_Context->m_psRestart_Case = nullptr;

    for (; 0 != psCase && KTgS_OK == tgRet; psCase = psCase->m_psNext)
    {
        for (; uiTest_Index < KTgNUM_TEST_PER_CASE && KTgS_OK == tgRet; ++uiTest_Index)
        {
            if (nullptr == psCase->m_pfnTest[uiTest_Index])
            {
                continue;
            };

            if (nullptr != psCase->m_pfnInit)
            {
                if (TgFAILED( psCase->m_pfnInit() ))
                {
                    psTest_Context->m_psRestart_Case = psCase->m_psNext;
                    tgRet = KTgE_FAIL;

                    if (psCase->m_pfnReport_Case_Failed)
                    {
                        psCase->m_pfnReport_Case_Failed( psTest_Context, psCase, "INIT" );
                    }
                    else if (psTest_Context->m_pfnReport_Case_Failed)
                    {
                        psTest_Context->m_pfnReport_Case_Failed( psTest_Context, psCase, "INIT" );
                    };

                    break;
                }
                else
                {
                    if (psCase->m_pfnReport_Case_Passed)
                    {
                        psCase->m_pfnReport_Case_Passed( psTest_Context, psCase, "INIT" );
                    }
                    else if (psTest_Context->m_pfnReport_Case_Passed)
                    {
                        psTest_Context->m_pfnReport_Case_Passed( psTest_Context, psCase, "INIT" );
                    };
                };
            };

            if (TgFAILED( psCase->m_pfnTest[uiTest_Index]() ))
            {
                if (0 != psTest_Context->m_pfnReport_Case_Report_Failed)
                {
                    psTest_Context->m_pfnReport_Case_Report_Failed( psTest_Context, psCase, uiTest_Index );
                }
                else if (0 != psCase->m_pfnReport_Case_Report_Failed)
                {
                    psCase->m_pfnReport_Case_Report_Failed( psTest_Context, psCase, uiTest_Index );
                };

                if (uiTest_Index + 1 >= KTgNUM_TEST_PER_CASE)
                {
                    psTest_Context->m_psRestart_Case = psCase->m_psNext;
                }
                else
                {
                    psTest_Context->m_psRestart_Case = psCase;
                    psTest_Context->m_psRestart_Case_Test = uiTest_Index + 1;
                }
                tgRet = KTgE_FAIL;

                ++psTest_Context->m_nuiCase_Failed;
            }
            else
            {
                if (0 != psTest_Context->m_pfnReport_Case_Report_Passed)
                {
                    psTest_Context->m_pfnReport_Case_Report_Passed( psTest_Context, psCase, uiTest_Index );
                }
                else if (0 != psCase->m_pfnReport_Case_Report_Passed)
                {
                    psCase->m_pfnReport_Case_Report_Passed( psTest_Context, psCase, uiTest_Index );
                };

                ++psTest_Context->m_nuiCase_Passed;
            };

            if (nullptr != psCase->m_pfnFree)
            {
                if (TgFAILED( psCase->m_pfnFree() ))
                {
                    psTest_Context->m_psRestart_Case = psCase->m_psNext;
                    tgRet = KTgE_FAIL;

                    if (psCase->m_pfnReport_Case_Failed)
                    {
                        psCase->m_pfnReport_Case_Failed( psTest_Context, psCase, "FREE" );
                    }
                    else if (psTest_Context->m_pfnReport_Case_Failed)
                    {
                        psTest_Context->m_pfnReport_Case_Failed( psTest_Context, psCase, "FREE" );
                    };

                    break;
                }
                else
                {
                    if (psCase->m_pfnReport_Case_Passed)
                    {
                        psCase->m_pfnReport_Case_Passed( psTest_Context, psCase, "FREE" );
                    }
                    else if (psTest_Context->m_pfnReport_Case_Passed)
                    {
                        psTest_Context->m_pfnReport_Case_Passed( psTest_Context, psCase, "FREE" );
                    };
                };
            };

            ++psTest_Context->m_nuiCase_Total;
        };

        uiTest_Index = 0;
    };

    return (tgRet);
}


/* ---- Unit_Test__Set_Register_Case --------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Unit_Test__Set_Register_Case( Test_Set_PC psSet, Test_Case_PC psTest_Case )
{
    if (0 == psSet->m_psFirst_Case)
    {
        psSet->m_psFirst_Case = psTest_Case;
    }
    else
    {
        Test_Case *psTest = psSet->m_psFirst_Case;
        for (; 0 != psTest->m_psNext; psTest = psTest->m_psNext);
        psTest->m_psNext = psTest_Case;
        psTest_Case->m_psPrev = psTest;
    };
}


/* ---- Unit_Test__Set_Init ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Unit_Test__Set_Init( Test_Set_PC psSet )
{
    tgMM_Set_U08_0x00( psSet, sizeof( Test_Set ) );
}


/* ---- Unit_Test__Set_Execute --------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT Unit_Test__Set_Execute( Test_Context_PCU psTest_Context, Test_Set_PCU psSet_Start )
{
    TgBOOL_C            bOutput_Message = nullptr == psTest_Context->m_psRestart_Set;
    Test_Set_P                              psSet = psSet_Start;
    TgRESULT                                iResult;
    TgRESULT                                tgRet = KTgS_OK;

    psTest_Context->m_psRestart_Set = nullptr;

    for (; 0 != psSet && KTgS_OK == tgRet; psSet = psSet->m_psNext)
    {
        if (nullptr != psSet->m_pfnInit)
        {
            if (TgFAILED( psSet->m_pfnInit() ))
            {
                psTest_Context->m_psRestart_Set = psSet->m_psNext;
                tgRet = KTgE_FAIL;

                if (psSet->m_pfnReport_Set_Failed)
                {
                    psSet->m_pfnReport_Set_Failed( psTest_Context, psSet, "INIT" );
                }
                else if (psTest_Context->m_pfnReport_Set_Failed)
                {
                    psTest_Context->m_pfnReport_Set_Failed( psTest_Context, psSet, "INIT" );
                };

                break;
            }
            else
            {
                if (psSet->m_pfnReport_Set_Passed)
                {
                    psSet->m_pfnReport_Set_Passed( psTest_Context, psSet, "INIT" );
                }
                else if (psTest_Context->m_pfnReport_Set_Passed)
                {
                    psTest_Context->m_pfnReport_Set_Passed( psTest_Context, psSet, "INIT" );
                };
            }
        };

        if (psSet != psSet_Start || bOutput_Message)
        {
            psSet->m_bPassed = true;

            if (psSet->m_pfnReport_Set_Header)
            {
                psSet->m_pfnReport_Set_Header( psTest_Context, psSet );
            }
            else if (psTest_Context->m_pfnReport_Set_Header)
            {
                psTest_Context->m_pfnReport_Set_Header( psTest_Context, psSet );
            };
        }

        iResult = Unit_Test__Case_Execute( psTest_Context, psSet->m_psFirst_Case );

        if (TgFAILED(iResult))
        {
            psSet->m_bPassed = false;
            tgRet = KTgE_FAIL;

            /* Test to see if there are any further tests in the set to re-enter */
            if (nullptr == psTest_Context->m_psRestart_Case)
            {
                psTest_Context->m_psRestart_Set = psSet->m_psNext;

                /* Wrap up the end of this test set */
                ++psTest_Context->m_nuiSet_Failed;

                if (psSet->m_pfnReport_Set_Footer)
                {
                    psSet->m_pfnReport_Set_Footer( psTest_Context, psSet );
                }
                else if (psTest_Context->m_pfnReport_Set_Footer)
                {
                    psTest_Context->m_pfnReport_Set_Footer( psTest_Context, psSet );
                };
            }
            else
            {
                /* The set will be re-entrant */
                psTest_Context->m_psRestart_Set = psSet;
            };
        }
        else
        {
            if (psSet->m_bPassed)
            {
                ++psTest_Context->m_nuiSet_Passed;
            }
            else
            {
                ++psTest_Context->m_nuiSet_Failed;
            };

            if (psSet->m_pfnReport_Set_Footer)
            {
                psSet->m_pfnReport_Set_Footer( psTest_Context, psSet );
            }
            else if (psTest_Context->m_pfnReport_Set_Footer)
            {
                psTest_Context->m_pfnReport_Set_Footer( psTest_Context, psSet );
            };
        };

        ++psTest_Context->m_nuiSet_Total;

        if (nullptr != psSet->m_pfnFree)
        {
            if (TgFAILED( psSet->m_pfnFree() ))
            {
                psTest_Context->m_psRestart_Set = psSet->m_psNext;
                tgRet = KTgE_FAIL;

                if (psSet->m_pfnReport_Set_Failed)
                {
                    psSet->m_pfnReport_Set_Failed( psTest_Context, psSet, "FREE" );
                }
                else if (psTest_Context->m_pfnReport_Set_Failed)
                {
                    psTest_Context->m_pfnReport_Set_Failed( psTest_Context, psSet, "FREE" );
                };
            }
            else
            {
                if (psSet->m_pfnReport_Set_Passed)
                {
                    psSet->m_pfnReport_Set_Passed( psTest_Context, psSet, "FREE" );
                }
                else if (psTest_Context->m_pfnReport_Set_Passed)
                {
                    psTest_Context->m_pfnReport_Set_Passed( psTest_Context, psSet, "FREE" );
                };
            };
        };
    };

    return (tgRet);
}


/* ---- Unit_Test__Context_Init -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Unit_Test__Context_Init( Test_Context_PCU psContext )
{
    tgMM_Set_U08_0x00( psContext, sizeof( Test_Context ) );

    psContext->m_bReport_Case_Report = true;
    psContext->m_bReport_Set_Report = true;
    psContext->m_bReport_Context_Report = true;

    psContext->m_pfnReport_Case_Report_Passed = Default_Report_Case_Report_Passed;
    psContext->m_pfnReport_Case_Report_Failed = Default_Report_Case_Report_Failed;
    psContext->m_pfnReport_Case_Passed = Default_Report_Case_Passed;
    psContext->m_pfnReport_Case_Failed = Default_Report_Case_Failed;
    psContext->m_pfnReport_Set_Header = Default_Report_Set_Header;
    psContext->m_pfnReport_Set_Footer = Default_Report_Set_Footer;
    psContext->m_pfnReport_Set_Passed = Default_Report_Set_Passed;
    psContext->m_pfnReport_Set_Failed = Default_Report_Set_Failed;
    psContext->m_pfnReport_Context_Header = Default_Report_Context_Header;
    psContext->m_pfnReport_Context_Footer = Default_Report_Context_Footer;
    psContext->m_pfnReport_Context_Passed = Default_Report_Context_Passed;
    psContext->m_pfnReport_Context_Failed = Default_Report_Context_Failed;
}


/* ---- Unit_Test__Register ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Unit_Test__Register( Test_Set_PC psSet )
{
    if (0 == g_psTest_Set_Start)
    {
        g_psTest_Set_Start = psSet;
    }
    else
    {
        Test_Set_P                              psTest_Set = g_psTest_Set_Start;

        for (; 0 != psTest_Set->m_psNext; psTest_Set = psTest_Set->m_psNext);
        psTest_Set->m_psNext = psSet;
        psSet->m_psPrev = psTest_Set;
    };
}


/* ---- Unit_Test__Execute ------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgRESULT Unit_Test__Execute( Test_Context_PC psTest_Context )
{
    TgBOOL                                  bExecute_Loop = true;
    TgRESULT                                tgRet = KTgS_OK;

    if (nullptr != psTest_Context->m_pfnReport_Context_Header)
    {
        psTest_Context->m_pfnReport_Context_Header( psTest_Context );
    };

    while (bExecute_Loop)
    {
        /* UNIT TEST - CONTEXT INIT ---------------------------------------------------------------------------------------------------------------------------------------------- */
        if ((nullptr != psTest_Context->m_pfnInit) && TgFAILED( psTest_Context->m_pfnInit() ))
        {
            if (nullptr != psTest_Context->m_pfnReport_Context_Failed)
            {
                psTest_Context->m_pfnReport_Context_Failed( psTest_Context, "INIT" );
            };

            return (KTgE_FAIL);
        }
        else
        {
            if (nullptr != psTest_Context->m_pfnReport_Context_Passed)
            {
                psTest_Context->m_pfnReport_Context_Passed( psTest_Context, "INIT" );
            };
        }


        /* UNIT TEST - CONTEXT BOOT ---------------------------------------------------------------------------------------------------------------------------------------------- */
        if ((nullptr != psTest_Context->m_pfnBoot) && TgFAILED( psTest_Context->m_pfnBoot() ))
        {
            if (nullptr != psTest_Context->m_pfnReport_Context_Failed)
            {
                psTest_Context->m_pfnReport_Context_Failed( psTest_Context, "BOOT" );
            };

            tgRet = KTgE_FAIL;
            bExecute_Loop = false;
        }
        else
        {
            Test_Set_P                              psRestart_Set = psTest_Context->m_psRestart_Set;

            if (nullptr != psTest_Context->m_pfnReport_Context_Passed)
            {
                psTest_Context->m_pfnReport_Context_Passed( psTest_Context, "BOOT" );
            };

            if (TgFAILED( Unit_Test__Set_Execute( psTest_Context, 0 != psRestart_Set ? psRestart_Set : g_psTest_Set_Start ) ))
            {
                if (psTest_Context->m_bFail_On_First_Fail || nullptr == psTest_Context->m_psRestart_Set)
                {
                    tgRet = KTgE_FAIL;
                    bExecute_Loop = false;
                };
            }
            else
            {
                bExecute_Loop = false;
            };

            /* UNIT TEST - CONTEXT STOP ------------------------------------------------------------------------------------------------------------------------------------------ */
            if ((nullptr != psTest_Context->m_pfnStop) && TgFAILED( psTest_Context->m_pfnStop() ))
            {
                if (nullptr != psTest_Context->m_pfnReport_Context_Failed)
                {
                    psTest_Context->m_pfnReport_Context_Failed( psTest_Context, "STOP" );
                };

                tgRet = KTgE_FAIL;
                bExecute_Loop = false;
            }
            else
            {
                if (nullptr != psTest_Context->m_pfnReport_Context_Passed)
                {
                    psTest_Context->m_pfnReport_Context_Passed( psTest_Context, "STOP" );
                };
            };
        }


        /* UNIT TEST - CONTEXT FREE ---------------------------------------------------------------------------------------------------------------------------------------------- */
        if ((nullptr != psTest_Context->m_pfnFree) && TgFAILED( psTest_Context->m_pfnFree() ))
        {
            if (nullptr != psTest_Context->m_pfnReport_Context_Failed)
            {
                psTest_Context->m_pfnReport_Context_Failed( psTest_Context, "FREE" );
            };

            return (KTgE_FAIL);
        }
        else
        {
            if (nullptr != psTest_Context->m_pfnReport_Context_Passed)
            {
                psTest_Context->m_pfnReport_Context_Passed( psTest_Context, "FREE" );
            };
        };
    };

    if (nullptr != psTest_Context->m_pfnReport_Context_Footer)
    {
        psTest_Context->m_pfnReport_Context_Footer( psTest_Context );
    };

    return (tgRet);
}


/* ---- Default_Report_Case_Report_Passed ---------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Case_Report_Passed( Test_Context_PC psTest_Context, Test_Case_PC psCase_Test, TgUINT_F32_C uiTest )
{
    if (psTest_Context->m_bReport_Case_Report)
    {
        if (psCase_Test->m_apszTest[uiTest])
        {
            TgMSGF( 0, UNIT_TEST__MSG_LITERAL_2, "PASSED:", psCase_Test->m_pszSet, psCase_Test->m_pszCase, psCase_Test->m_apszTest[uiTest] );
        }
        else
        {
            TgMSGF( 0, UNIT_TEST__MSG_LITERAL_1, "PASSED:", psCase_Test->m_pszSet, psCase_Test->m_pszCase );
        };
    };
}


/* ---- Default_Report_Case_Report_Failed ---------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Case_Report_Failed( Test_Context_PC psTest_Context, Test_Case_PC psCase_Test, TgUINT_F32_C uiTest )
{
    if (psTest_Context->m_bIgnore_On_Fail)
    {
        if (psTest_Context->m_bReport_Case_Report)
        {
            if (psCase_Test->m_apszTest[uiTest])
            {
                TgMSGF( 0x0, UNIT_TEST__MSG_LITERAL_2, "FAILED:", "Test Set:",
                    psCase_Test->m_pszSet, "Test Case:", psCase_Test->m_pszCase, psCase_Test->m_apszTest[uiTest] );
            }
            else
            {
                TgMSGF( 0x0, UNIT_TEST__MSG_LITERAL_1, "FAILED:", "Test Set:",
                    psCase_Test->m_pszSet, "Test Case:", psCase_Test->m_pszCase );
            };
        };
    }
    else
    {
        if (psCase_Test->m_apszTest[uiTest])
        {
            TgERROR_MSGF( 0, UNIT_TEST__MSG_LITERAL_2, "FAILED:", psCase_Test->m_pszSet, 
                psCase_Test->m_pszCase, psCase_Test->m_apszTest[uiTest] );
        }
        else
        {
            TgERROR_MSGF( 0, UNIT_TEST__MSG_LITERAL_1, "FAILED:", psCase_Test->m_pszSet, psCase_Test->m_pszCase );
        };
    };
}


/* ---- Default_Report_Case_Passed ----------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Case_Passed( Test_Context_PC psTest_Context, Test_Case_PC psCase_Test, TgCHAR_MB_CPC szMsg )
{
    if (psTest_Context->m_bReport_Case_Result)
    {
        TgMSGF( 0x0, "%-16.16s %-31.31s    %-48.48s- %s\n", "PASSED:", psCase_Test->m_pszSet, psCase_Test->m_pszCase, szMsg );
    };
}


/* ---- Default_Report_Case_Failed ----------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Case_Failed( Test_Context_PC psTest_Context, Test_Case_PC psCase_Test, TgCHAR_MB_CPC szMsg )
{
    if (psTest_Context->m_bIgnore_On_Fail)
    {
        if (psTest_Context->m_bReport_Set_Result)
        {
            TgMSGF( 0x0, "%-16.16s %-31.31s    %-48.48s- %s\n", "FAILED:", psCase_Test->m_pszSet, psCase_Test->m_pszCase, szMsg );
        };
    }
    else
    {
        TgERROR_MSGF( 0, "%-16.16s %-31.31s    %-48.48s- %s\n", "FAILED:", psCase_Test->m_pszSet, psCase_Test->m_pszCase, szMsg );
    };
}


/* ---- Default_Report_Set_Header ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Set_Header( Test_Context_PC psTest_Context, Test_Set_PC UNUSED_PARAM psSet_Test )
{
    tgProfile_Sample_Reset( &g_sPROFILE_UNIT_TEST__TEST_SET__EXECUTE );
    tgProfile_Sample_Start( &g_sPROFILE_UNIT_TEST__TEST_SET__EXECUTE );

    if (psTest_Context->m_bReport_Set_Report)
    {
        TgMSGF( 0x0, "\n" UNIT_TEST__MSG_LITERAL_2, "", "TEST SET", "CASE", "TEST" );
    };
    tgProfile_Sample_Stop( &g_sPROFILE_UNIT_TEST__TEST_SET__EXECUTE );
}


/* ---- Default_Report_Set_Footer ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Set_Footer( Test_Context_PC psTest_Context, Test_Set_PC psSet_Test )
{
    TgFLOAT64                               fExecute;

    tgProfile_Sample_Report( &g_sPROFILE_UNIT_TEST__TEST_SET__EXECUTE );
    fExecute = (TgFLOAT64)g_sPROFILE_UNIT_TEST__TEST_SET__EXECUTE.m_fReport_Sample;

    tgProfile_Sample_Start( &g_sPROFILE_UNIT_TEST__TEST_SET__EXECUTE );
    if (psSet_Test->m_bPassed)
    {
        if (psTest_Context->m_bReport_Set_Report)
        {
            TgMSGF( 0x0, "%-16.16s %-31.31s    %-6.2f ms\n", "PASSED:", psSet_Test->m_szSet, 1E3 * fExecute );
        };
    }
    else
    {
        if (psTest_Context->m_bIgnore_On_Fail)
        {
            if (psTest_Context->m_bReport_Set_Report)
            {
                TgMSGF( 0x0, "%-16.16s %-31.31s    %-6.2f ms\n", "FAILED:", psSet_Test->m_szSet, 1E3 * fExecute );
            };
        }
        else
        {
            TgERROR_MSGF( 0, "%-16.16s %-31.31s    %-6.2f ms\n", "FAILED:", psSet_Test->m_szSet, 1E3 * fExecute );
        };
    };
    tgProfile_Sample_Stop( &g_sPROFILE_UNIT_TEST__TEST_SET__EXECUTE );
}


/* ---- Default_Report_Set_Passed ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Set_Passed( Test_Context_PC psTest_Context, Test_Set_PC psSet_Test, TgCHAR_MB_CPC szMsg )
{
    if (psTest_Context->m_bReport_Set_Result)
    {
        TgMSGF( 0x0, "%-16.16s %-31.31s     - %s\n", "PASSED:", psSet_Test->m_szSet, szMsg );
    };
}


/* ---- Default_Report_Set_Failed ------------------------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Set_Failed( Test_Context_PC psTest_Context, Test_Set_PC psSet_Test, TgCHAR_MB_CPC szMsg )
{
    if (psTest_Context->m_bIgnore_On_Fail)
    {
        if (psTest_Context->m_bReport_Set_Result)
        {
            TgMSGF( 0x0, "%-16.16s %-31.31s     - %ss\n", "FAILED:", psSet_Test->m_szSet, szMsg );
        };
    }
    else
    {
        TgERROR_MSGF( 0, "%-16.16s %-31.31s     - %s\n", "FAILED:", psSet_Test->m_szSet, szMsg );
    };
}


/* ---- Default_Report_Context_Header -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Context_Header( Test_Context_PC UNUSED_PARAM psTest_Context )
{
}


/* ---- Default_Report_Context_Footer -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Context_Footer( Test_Context_PC psTest_Context )
{
    if (psTest_Context->m_bReport_Context_Report)
    {
    };
}


/* ---- Default_Report_Context_Passed -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Context_Passed( Test_Context_PC psTest_Context, TgCHAR_MB_CPC szMsg )
{
    if (psTest_Context->m_bReport_Context_Result)
    {
        TgCHAR_MB                               szBuffer[1024];

        tgMBZ_PrintF( szBuffer, 1024, "ERR: %-16.16s %-31.31s    %s\n", "PASSED:", "TEST CONTEXT", szMsg );
        tgPM_DBG_OUT_Write( 0, KTgMAX_RSIZE, szBuffer, 0 );
    };
}


/* ---- Default_Report_Context_Failed -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID Default_Report_Context_Failed( Test_Context_PC psTest_Context, TgCHAR_MB_CPC szMsg )
{
    if (psTest_Context->m_bIgnore_On_Fail)
    {
        if (psTest_Context->m_bReport_Context_Result)
        {
            TgCHAR_MB                               szBuffer[1024];

            tgMBZ_PrintF( szBuffer, 1024, "ERR: %-16.16s %-31.31s    %s\n", "FAILED:", "TEST CONTEXT", szMsg );
            tgPM_DBG_OUT_Write( 0, KTgMAX_RSIZE, szBuffer, 0 );
        };
    }
    else
    {
        TgCHAR_MB                               szBuffer[1024];

        tgMBZ_PrintF( szBuffer, 1024, "ERR: %-16.16s %-31.31s    %s\n", "FAILED:", "TEST CONTEXT", szMsg );
        tgPM_DBG_OUT_Write( 0, KTgMAX_RSIZE, szBuffer, 0 );

        tgPM_Break();
    };
}
