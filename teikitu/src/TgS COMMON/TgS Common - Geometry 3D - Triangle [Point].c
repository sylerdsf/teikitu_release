/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Triangle [Point].c_inc
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.17 / »GUID« 3ED3C595-046B-47FB-8785-5C167178CD24 */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if defined (TGS_COMMON_GEOMETRY_H)

#if !defined (ENABLE_RELOAD_GUARD)
    #define TEMPLATE__VECTOR_DIM 4
    #define ENABLE_RELOAD_GUARD
    #if !defined(TEMPLATE__TYPE_SIZE)
        #if TgCOMPILE__NON_NATIVE_VECTOR_AS_NATIVE
            #define TEMPLATE__TYPE_SIZE 64
            #include __FILE__
            #undef TEMPLATE__TYPE_SIZE
        #endif
        #define TEMPLATE__TYPE_SIZE 32
    #endif
    #undef ENABLE_RELOAD_GUARD
#endif

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/* == Common ===================================================================================================================================================================== */

/* ---- FCN_VO(tgGM_PT_Is_Valid) ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_PT_Is_Valid)( VEC_OBJ_T(TgPTRI,CPCU) psPT1 )
{
    VEC_T(1)                            avEdge[2];

    /* Sanity Check: Vector form. */
    if (!FCN_V(tgMH_Is_Valid_Point)( psPT1->m_avPoint[0] ))
    {
        return (false);
    };

    if (!FCN_V(tgMH_Is_Valid_Point)( psPT1->m_avPoint[1] ))
    {
        return (false);
    };

    if (!FCN_V(tgMH_Is_Valid_Point)( psPT1->m_avPoint[2] ))
    {
        return (false);
    };

    if (!FCN_V(tgMH_Is_Valid_Unit_Vector)( psPT1->m_vNormal ))
    {
        return (false);
    };

    avEdge[0] = FCN_V(tgMH_SUB)( psPT1->m_avPoint[1], psPT1->m_avPoint[0] );
    avEdge[1] = FCN_V(tgMH_SUB)( psPT1->m_avPoint[2], psPT1->m_avPoint[0] );

    /* Sanity Check: on the edge size. */

    if (FCN_V(tgMH_PRX_CMP_EQ)( avEdge[0], FCN_V(tgMH_SET1)( TYPE_K(0) ) ) || FCN_V(tgMH_PRX_CMP_EQ)( avEdge[1], FCN_V(tgMH_SET1)( TYPE_K(0) ) ))
    {
        return (false);
    };

    /* Sanity check on the "aspect" ratio of the triangle - remember that |a x b| = |a|•|b|•|sin(Θ)|, and near zero sin(Θ) ≈ Θ */

    VEC_T(1,C)      vNormal = FCN_V(tgMH_CX)( avEdge[0], avEdge[1] );

    VEC_UN_T(1,C)   uU0 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_LSQ)( vNormal ) };
    VEC_T(1,C)      vX0 = FCN_V(tgMH_LSQ)( avEdge[0] );
    VEC_T(1,C)      vX1 = FCN_V(tgMH_LSQ)( avEdge[1] );
    VEC_UN_T(1,C)   uU1 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_MUL)( FCN_V(tgMH_SET1)( VAR_K(KTgEPS) ), FCN_V(tgMH_MUL)( vX0, vX1 ) ) };

    if (VEC_S_UN_1_MEMBER(uU0).x < VEC_S_UN_1_MEMBER(uU1).x)
    {
        return (false);
    };

    return (true);
}


/* ---- FCN_VO(tgGM_PT_Support_Point) -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
VEC_T(1) FCN_VO(tgGM_PT_Support_Point)( VEC_OBJ_T(TgPTRI,CPCU) psPT0, VEC_T(1,C) vDN )
{
    VEC_UN_T(1,C)   uDN_N0 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT3)( vDN, psPT0->m_vNormal ) };

    TgGEOM_ASSERT_PARAM(FCN_VO(tgGM_PT_Is_Valid)( psPT0 ) && FCN_V(tgMH_Is_Valid_Unit_Vector)( vDN ));

    if (FCN_F(tgCM_NR0)(VEC_S_UN_1_MEMBER(uDN_N0).x - TYPE_K(1)))
    {
        VEC_T(1,C)      vX0 = FCN_V(tgMH_SET1)( VAR_K(KTgTHIRD) );
        VEC_T(1,C)      vX1 = FCN_V(tgMH_ADD)( psPT0->m_avPoint[0], psPT0->m_avPoint[1] );
        VEC_T(1,C)      vX2 = FCN_V(tgMH_ADD)( psPT0->m_avPoint[2], vX1 );

        return (FCN_V(tgMH_MUL)( vX0, vX2 ));
    }
    else
    {
        VEC_UN_T(1,C)   uDN_P0 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT3)( vDN, psPT0->m_avPoint[0] ) };
        VEC_UN_T(1,C)   uDN_P1 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT3)( vDN, psPT0->m_avPoint[1] ) };
        VEC_UN_T(1,C)   uDN_P2 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT3)( vDN, psPT0->m_avPoint[2] ) };

        if (VEC_S_UN_1_MEMBER(uDN_P0).x > VEC_S_UN_1_MEMBER(uDN_P1).x)
        {
            if (VEC_S_UN_1_MEMBER(uDN_P0).x > VEC_S_UN_1_MEMBER(uDN_P2).x)
            {
                return (psPT0->m_avPoint[0]);
            }
            else
            {
                return (psPT0->m_avPoint[2]);
            };
        }
        else
        {
            if (VEC_S_UN_1_MEMBER(uDN_P1).x > VEC_S_UN_1_MEMBER(uDN_P2).x)
            {
                return (psPT0->m_avPoint[1]);
            }
            else
            {
                return (psPT0->m_avPoint[2]);
            };
        };
    };
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
