/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Geometry 3D - Triangle [Edge].c_inc
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

/* ---- FCN_VO(tgGM_ET_Is_Valid) ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_ET_Is_Valid)( VEC_OBJ_T(TgETRI,CPCU) psET1 )
{
    if (!FCN_VO(tgGM_PT_Is_Valid)( &psET1->m_sPT) )
    {
        return (false);
    };

    /* Sanity Check: on the edge size. */

    if (!FCN_V(tgMH_Is_Valid_Vector)( psET1->m_avEdge[0] ) || FCN_V(tgMH_PRX_CMP_EQ)( psET1->m_avEdge[0], FCN_V(tgMH_SET1)( TYPE_K(0) ) ))
    {
        return (false);
    };

    if (!FCN_V(tgMH_Is_Valid_Vector)( psET1->m_avEdge[1] ) || FCN_V(tgMH_PRX_CMP_EQ)( psET1->m_avEdge[1], FCN_V(tgMH_SET1)( TYPE_K(0) ) ))
    {
        return (false);
    };

    if (!FCN_V(tgMH_Is_Valid_Vector)( psET1->m_avEdge[2] ) || FCN_V(tgMH_PRX_CMP_EQ)( psET1->m_avEdge[2], FCN_V(tgMH_SET1)( TYPE_K(0) ) ))
    {
        return (false);
    };

    return (true);
}


/* ---- FCN_VO(tgGM_ET_Support_Point) -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
VEC_T(1) FCN_VO(tgGM_ET_Support_Point)( VEC_OBJ_T(TgETRI,CPCU) psET0, VEC_T(1,C) vDN )
{
    TgGEOM_ASSERT_PARAM(FCN_VO(tgGM_ET_Is_Valid)( psET0 ) && FCN_V(tgMH_Is_Valid_Unit_Vector)( vDN ));

    VEC_UN_T(1,C)   uDN_E0 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_DOT)( vDN, psET0->m_avEdge[0] ) };
    VEC_UN_T(1,C)   uDN_E2 = { VEC_UN_1_MEMBER() = FCN_V(tgMH_NEG)( FCN_V(tgMH_DOT)( vDN, psET0->m_avEdge[2] ) ) };

    if (FCN_F(tgCM_NR0)( VEC_S_UN_1_MEMBER(uDN_E0).x ) && FCN_F(tgCM_NR0)( VEC_S_UN_1_MEMBER(uDN_E2).x ))
    {
        VEC_T(1,C)      vX0 = FCN_V(tgMH_SUB)( psET0->m_avEdge[0], psET0->m_avEdge[2] );
        VEC_T(1,C)      vX1 = FCN_V(tgMH_MUL)( FCN_V(tgMH_SET1)( VAR_K(KTgTHIRD) ), vX0 );

        return (FCN_V(tgMH_ADD)( psET0->m_sPT.m_avPoint[0], vX1 ));
    }

    if (!(VEC_S_UN_1_MEMBER(uDN_E0).x < TYPE_K(0)))
    {
        if (VEC_S_UN_1_MEMBER(uDN_E2).x > VEC_S_UN_1_MEMBER(uDN_E0).x)
        {
            return (FCN_V(tgMH_SUB)( psET0->m_sPT.m_avPoint[0], psET0->m_avEdge[2] ));
        }
        else
        {
            return (FCN_V(tgMH_ADD)( psET0->m_sPT.m_avPoint[0], psET0->m_avEdge[0] ));
        };
    }
    else if (!(VEC_S_UN_1_MEMBER(uDN_E2).x < TYPE_K(0)))
    {
        return (FCN_V(tgMH_SUB)( psET0->m_sPT.m_avPoint[0], psET0->m_avEdge[2] ));
    };

    return (psET0->m_sPT.m_avPoint[0]);
}


/* ---- FCN_VO(tgGM_ET_Is_Tri_Edge_Ignored) -------------------------------------------------------------------------------------------------------------------------------------- */
/** Edge culling is used in different ways by the different systems.  Sometimes the desired approach is to have an edge included one time even if it's marked to be ignored. For
    instance, during penetration collisions calls it is necessary to ignore an edge in determining the method of separation (normal) but in contact reduction the edge has to be
    considered at least once. */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_ET_Is_Tri_Edge_Ignored)( VEC_OBJ_T(TgETRI,CPCU) psET0, VAR_T(C) fT0, VAR_T(C) fT1 )
{
    VEC_UN_T(1)                         uU0;

    if (FCN_F(tgPM_ABS)( fT1 ) <= VAR_K(KTgEPS))
    {   /*  Edge generated by vertex 0 and vertex 1 */
        VEC_UN_1_MEMBER(uU0) = psET0->m_avEdge[0];
    }
    else if (FCN_F(tgPM_ABS)( fT0 ) <= VAR_K(KTgEPS))
    {   /* Edge generated by vertex 0 and vertex 2 */
        VEC_UN_1_MEMBER(uU0) = psET0->m_avEdge[2];
    }
    else
    {   /*  Edge generated by vertex 1 and vertex 2 */
        VEC_UN_1_MEMBER(uU0) = psET0->m_avEdge[1];
        TgERROR(FCN_F(tgPM_ABS)( fT0 + fT1 - TYPE_K(1 )) <= VAR_K(KTgEPS));
    };

    if (VEC_S_UN_1_MEMBER(uU0).x != TYPE_K(0))
    {
        return (VEC_S_UN_1_MEMBER(uU0).x <= TYPE_K(0));
    }
    else if (VEC_S_UN_1_MEMBER(uU0).y != TYPE_K(0))
    {
        return (VEC_S_UN_1_MEMBER(uU0).y <= TYPE_K(0));
    }
    else
    {
        TgERROR(VEC_S_UN_1_MEMBER(uU0).z != TYPE_K(0));
        return (VEC_S_UN_1_MEMBER(uU0).z <= TYPE_K(0));
    };
}


/* ---- FCN_VO(tgGM_ET_Is_Tri_Edge_Ignored_Code) --------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgBOOL FCN_VO(tgGM_ET_Is_Tri_Edge_Ignored_Code)( VEC_OBJ_T(TgETRI,CPCU) psET0, TgRSIZE_C iEdge )
{
    VEC_UN_T(1)                         uU0;

    if (0 == iEdge)
    {   /*  Edge generated by vertex 0 and vertex 1 */
        VEC_UN_1_MEMBER(uU0) = psET0->m_avEdge[0];
    }
    else if (2 == iEdge)
    {   /* Edge generated by vertex 0 and vertex 2 */
        VEC_UN_1_MEMBER(uU0) = psET0->m_avEdge[2];
    }
    else
    {   /*  Edge generated by vertex 1 and vertex 2 */
        VEC_UN_1_MEMBER(uU0) = psET0->m_avEdge[1];
        TgERROR(1 == iEdge);
    };

    if (VEC_S_UN_1_MEMBER(uU0).x != TYPE_K(0))
    {
        return (VEC_S_UN_1_MEMBER(uU0).x <= TYPE_K(0));
    }
    else if (VEC_S_UN_1_MEMBER(uU0).y != TYPE_K(0))
    {
        return (VEC_S_UN_1_MEMBER(uU0).y <= TYPE_K(0));
    }
    else
    {
        TgERROR(VEC_S_UN_1_MEMBER(uU0).z != TYPE_K(0));
        return (VEC_S_UN_1_MEMBER(uU0).z <= TYPE_K(0));
    };
}


/* =============================================================================================================================================================================== */

#include "TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc"

/*# defined (TGS_COMMON_GEOMETRY_H) */
#endif
