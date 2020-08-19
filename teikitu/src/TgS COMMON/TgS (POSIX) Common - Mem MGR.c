/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS (POSIX) Common - Mem MGR.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <unistd.h>
#include <stdlib.h>
#include <mach/mach_init.h>
#include <mach/vm_map.h>

/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Internal Platform Functions                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgEXTN TgUINT_F32                           tgMM_PM_Page_Size( TgVOID );

TgEXTN TgVOID_P                             tgMM_PM_Virtual_Reserve( TgSIZE_ALL_C );
TgEXTN TgVOID_P                             tgMM_PM_Virtual_Commit( TgVOID_PC, TgSIZE_ALL_C );
TgEXTN TgVOID                               tgMM_PM_Virtual_Free( TgVOID_PC );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Internal Functions                                                                                                                                                             */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- tgMM_PM_Page_Size -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgUINT_F32 tgMM_PM_Page_Size( TgVOID )
{
    return ((TgUINT_F32)getpagesize());
}


/* ---- tgMM_PM_Virtual_Reserve -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID_P tgMM_PM_Virtual_Reserve( TgSIZE_ALL_C iSize )
{
    TgVOID_P                            pMem;

    posix_memalign( &pMem, tgMM_PM_Page_Size(), iSize );
    return (pMem);

//    TgSIZE_ALL                          uiPageSize, uiSize_To_Allocate;
//    TgVOID_P                            pMem;
//    kern_return_t                       err;
//
//    uiPageSize = tgMM_PM_Page_Size();
//    uiSize_To_Allocate = uiPageSize * ((uiSize + uiPageSize - 1) / uiPageSize);
//    err = vm_allocate(  (vm_map_t) mach_task_self(),
//                        (vm_address_t*) &pMem,
//                        uiSize_To_Allocate,
//                        VM_FLAGS_ANYWHERE);
//
//    TgERROR(err == KERN_SUCCESS);
//    if(err != KERN_SUCCESS)
//    {
//       pMem = nullptr;
//    }
//
//    return pMem;
}


/* ---- tgMM_PM_Virtual_Commit --------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID_P tgMM_PM_Virtual_Commit( TgVOID_PC pMem, TgSIZE_ALL_C iSize )
{
    return (nullptr == pMem ? tgMM_PM_Virtual_Reserve( iSize ) : pMem);
}


/* ---- tgMM_PM_Virtual_Free ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgVOID tgMM_PM_Virtual_Free( TgVOID_PC pMem )
{
    free( pMem );
}
