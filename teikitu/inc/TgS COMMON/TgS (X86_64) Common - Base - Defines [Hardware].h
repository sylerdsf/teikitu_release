/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (X86_64) Common - Base - Defines [Hardware].h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_X86_64_COMMON_BASE_DEFINES_HARDWARE_H)
#define TGS_X86_64_COMMON_BASE_DEFINES_HARDWARE_H
#pragma once


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Configuration                                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgCOMPILE_FLOAT64                   0
#define TgCOMPILE_SYSTEM_INFORMATION        0

/* Make sure to review the ABI for your compiler to see how many registers will be used. */
#if defined(TgTARGET_HARDWARE__VECTOR_PASS_IN_REGISTER)
    #define TgVEC_PRM                           VEC_N_T(1,C)
    #define TgVEC_VAR(A)                        VEC_N_T(1,C) A
    #define TgVECTOR_LOCAL_COPY(A)
#else
    #define TgVEC_PRM                           V(CPCU_TgVEC_N)
    #define TgVEC_VAR(A)                        V(CPCU_TgVEC_N) _##A
    #define TgVECTOR_LOCAL_COPY(A)              VEC_N_T(1,C) A = *_##A
#endif

/* TgCOMPILE__WORDSIZE is the CPU native integer size */
#if defined(__WORDSIZE)
    #define TgCOMPILE__WORDSIZE __WORDSIZE
#elif defined(__LP64__)
    #define TgCOMPILE__WORDSIZE 64
#else
    #define TgCOMPILE__WORDSIZE 32
#endif

#define TgCOMPILE_CPU_CACHE_LINE_SIZE       64 /* This is the size of a CPU cache line */


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Intrinsics                                                                                                                                                                     */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define TgCOMPILE__HARDWARE__RAND
#define tgPM__HARDWARE__RAND_U16 __builtin_ia32_rdseed16_step
#define tgPM__HARDWARE__RAND_U32 __builtin_ia32_rdseed32_step
#define tgPM__HARDWARE__RAND_U64 __builtin_ia32_rdseed64_step

#define TgCOMPILE__HARDWARE__BSR
#define tgPM__HARDWARE__BSR_U16 __builtin_ia32_lzcnt_u16
#define tgPM__HARDWARE__BSR_U32 __builtin_ia32_lzcnt_u32
#define tgPM__HARDWARE__BSR_U64 __builtin_ia32_lzcnt_u64

#define TgCOMPILE__HARDWARE__BSF
#define tgPM__HARDWARE__BSF_U32 __builtin_ctz
#define tgPM__HARDWARE__BSF_U64 __builtin_ctzll

#define TgCOMPILE__HARDWARE__PAUSE
#define tgPM__HARDWARE__PAUSE _mm_pause


/* =============================================================================================================================================================================== */
#endif
