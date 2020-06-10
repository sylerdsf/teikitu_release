/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common -- VERSION.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON__VERSION_H)
#define TGS_COMMON__VERSION_H
#pragma once

// TODO:|FIXME: Review Console Text processing (and any other text processing)
// TODO:|FIXME: Refactor File IO to use IDs
// TODO:|FIXME: Document math functions
// TODO:|FIXME: Add support for modern intrinsics - 256 and 512 (also note the expanded set of registers for these intrinsics)
// TODO:|FIXME: __builtin_shufflevector
// TODO:|FIXME: __attribute__((cpu_specific(ivybridge))), __attribute__((cpu_specific(generic)))

// FIXME: Effect commented out code

// TODO: Add native vector support for all geometry
// TODO: Add native vector support for collision as needed
// TODO: Render each of the basic geometry forms
// TODO: Implement physics
// TODO: Implement input on all apple devices (ugh)

// TODO: Evaluate writing vector code using GCC / Clang capability

// TODO:|FIXME: Refactor Doxygen - Send in sample


/*
 Checklist
  - Copyright notice
  - Document - data structures
  - Document - API
 
 */


/* == Common ===================================================================================================================================================================== */
/* MARK: No Unit Test Required                                                                                                                                                     */


/* 5.11 */ /* C1663C45-B8EA-46E7-8607-56216A251FC8 */ /* May 2020 - After losing work to reset --hard */
/*  Brief: May 2020 - After losing work to reset --hard
    Description: Includes: reformatting to a wide default file width (size), standardization on C11, cleanup of CMakeFiles, C11 atomics, enforced alignment - the old GCC style
    attribute does not seem to have work in Clang. Moving to C11 alignment command highlighted some areas to improve. Same with the use of C11 atomics, where issues came up that were
    appearing to have worked in the past. Enabled POSIX. Cleaned up the compiler, hardware, platform sequence of defines and includes for compilation to a target platform. Created
    the new text object (to differentiate from strings). This will be the standard way that text is used in the engine and will be based on UTF standards. Unfortunately, uchar.h
    is not available on the Mac. Once it is more common, will integrate it into the text object. In the mean time, will separate out the char type declaration for use with the
    operating system from the common character type used in the engine. Removed the old atomic functions. Kept the other wrapper functions for numerics for standardization. */

/* 5.12 */ /* 964CB1A6-814D-4E19-8E67-A83FCA98BF05 */
/*  Brief: May 2020 - After changing the integer types
    Description: Bumped the version again for an indicator that data structures have been reviewed for C11 atomic implementation and for the distinction between the fast and exact
    integer types. The default should be to use the fast integer types. However, these can be of a indeterminate size and alignment, making structure packing difficult. It is in
    these cases that the exact bit sized versions need to be used. Including doxygen / java docs style comments in all headers.
        Note: STg1_XXX is for low level wrappers of operating system objects. All other types should be STg2. */

/* 5.15 */ /* 00D008E0-5616-4AAF-8989-24865B450F52 */
/*  Brief: June 2020 - WIP for Release 0.1
    Description: Mark files where unit test coverage is 100% (best intention reminder that changes to the file require an update to the unit tests). Modify the header to include
    the necessary @file command (for global functions). Include new group definitions.
        Note: File name nomenclature for include files XXX.h is part of the direct include chain. XXX [YYY].h is part of indirect include chain (include contained in parent file).
 */

/* 5.16 */ /* 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  Brief: June 2020 - WIP for Release 0.1, Finalizing Doxygen configuration and documentation
    Description: Move Doxygen configuration into the individual header files. Include [in] and [out] on the parameter declarations for comments. Move file wide comments into the
    group definition so that it appears under the group. Add comments to all of the header files, including the code generation files (h_inc).
 */


/* =============================================================================================================================================================================== */

/*  % cloc --exclude-dir=web --force-lang="C",c_inc --force-lang="C",i_inc --force-lang="C",h_inc --force-lang="C",h --force-lang="C",inl .
 
        1972 text files.
        1926 unique files.
         177 files ignored.

    github.com/AlDanial/cloc v 1.86  T=3.16 s (575.8 files/s, 102858.5 lines/s)
    -------------------------------------------------------------------------------
    Language                     files          blank        comment           code
    -------------------------------------------------------------------------------
    C                              874          38487          40153         107969
    HTML                           580           1140           3015          65523
    D                              189              0              0          46784
    CMake                           85           1486            610           4048
    TeX                             17            119            237           3912
    XML                             28              8             17           2908
    make                             7           1170            554           2117
    CSS                              3            328             47           1627
    JavaScript                      16            105            144            869
    C++                             10            219            268            838
    HLSL                             3              8              9             39
    Markdown                         1              4              0              8
    XAML                             1              1              0              7
    Bourne Shell                     3              0              0              6
    YAML                             1              0              0              1
    -------------------------------------------------------------------------------
    SUM:                          1818          43075          45054         236656
    -------------------------------------------------------------------------------
*/


/* =============================================================================================================================================================================== */

#endif
