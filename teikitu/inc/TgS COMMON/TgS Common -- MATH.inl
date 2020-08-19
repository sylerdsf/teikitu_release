/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common -- MATH.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.17 / »GUID« 3ED3C595-046B-47FB-8785-5C167178CD24 */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_MATH_INL)
#define TGS_COMMON_MATH_INL
#pragma once

#if defined(TGS_COMMON_MATH_VECTOR_SPECIALIZATION)
    #if defined(TgBUILD_UNIVERSAL) && !defined (TGS_COMMON_MATH_API_VECTOR_SPECIALIZATION_INL)
        #include TgHEADER_UNIVERSAL(TgS COMMON/TgS,Common - Math [Vector].inl)
    #endif
    #if defined(TgBUILD_HARDWARE) && !defined(TgBUILD_HARDWARE__C11_32) && !defined(TgBUILD_HARDWARE__C11_64) && !defined (TGS_COMMON_MATH_API_VECTOR_SPECIALIZATION_INL)
        #include TgHEADER_HARDWARE(TgS COMMON/TgS,Common - Math [Vector].inl)
    #endif
    #if defined(TgBUILD_COMPILER) && !defined (TGS_COMMON_MATH_API_VECTOR_SPECIALIZATION_INL)
        #include TgHEADER_COMPILER(TgS COMMON/TgS,Common - Math [Vector].inl)
    #endif
#endif

#include "TgS COMMON/TgS Common - Math [Vector].inl"


#if defined(TGS_COMMON_MATH_VECTOR_SPECIALIZATION)
    #if defined(TgBUILD_UNIVERSAL) && !defined (TGS_COMMON_MATH_API_MATRIX_SPECIALIZATION_INL)
        #include TgHEADER_UNIVERSAL(TgS COMMON/TgS,Common - Math [Matrix].inl)
    #endif
    #if defined(TgBUILD_HARDWARE) && !defined(TgBUILD_HARDWARE__C11_32) && !defined(TgBUILD_HARDWARE__C11_64) && !defined (TGS_COMMON_MATH_API_MATRIX_SPECIALIZATION_INL)
        #include TgHEADER_HARDWARE(TgS COMMON/TgS,Common - Math [Matrix].inl)
    #endif
    #if defined(TgBUILD_COMPILER) && !defined (TGS_COMMON_MATH_API_MATRIX_SPECIALIZATION_INL)
        #include TgHEADER_COMPILER(TgS COMMON/TgS,Common - Math [Matrix].inl)
    #endif
#endif

#include "TgS COMMON/TgS Common - Math [Matrix].inl"


/* =============================================================================================================================================================================== */
#endif
