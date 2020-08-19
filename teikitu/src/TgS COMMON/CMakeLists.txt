cmake_minimum_required(VERSION 3.17)
cmake_policy(VERSION 3.17)
#    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
#build library

TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files" "${PROJECT_SOURCE_DIR}/../inc/TgS Ring 0 - Type.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files" "${PROJECT_SOURCE_DIR}/../inc/TgS Common.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- VERSION.h" )




# BASE

    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base/Template" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Math].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base/Template" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Text].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base/Template" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Defines [Template] [Math].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base/Template" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Defines [Template] [Text].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base/Template" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [Vector].h_inc" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Math].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Platform].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Text].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Defines [Code].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Defines [Configuration].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Defines [Hardware].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Defines [Text].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Defines.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Include.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [Platform].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [Constants].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [File].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [IO].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [Limits].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [MT].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [Vector].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- BASE.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Errors.TgS" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Literals.TgS" )

TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Base/Template Files" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Math].i_inc" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Base/Template Files" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Text].i_inc" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Math].inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API [Text].inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - API.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type [IO].inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Base - Type.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Base" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- BASE.inl" )

TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "SDK/Header Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Internal.h" )

TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base/Template Files" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - API [Math].c_inc" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base/Template Files" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - API [Text].c_inc" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base/Template Files" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - Type [IO] [Text].c_inc" )

TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - API [Math].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - API [Text].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - API.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - Data.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - Type [Constants].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - Type [File] [Data].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - Type [File].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - Type [IO].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Base" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common [Static].c" )




# MATH

    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [API].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [S] [F] [34].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [S] [F] [44].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [S] [F].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [S].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [F] [34].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [F] [44].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [F].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix].h_inc" )

    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [API].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [S] [FXX_04].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [S] [F].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [S] [I].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [S].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [FXX_04].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [F].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [I].h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector].h_inc" )
    
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math/Template Files/Scalar" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Scalar] [F].h_inc" )

TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- MATH.h" )

    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [API].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [S] [F] [34].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [S] [F] [44].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [S] [F].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [S].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [F] [34].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [F] [44].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix] [F].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Matrix" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix].i_inc" )

    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [API].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [S] [FXX_04].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [S] [F].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [S] [I].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [S].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [FXX_04].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [F].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector] [I].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math/Template Files/Vector" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector].i_inc" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Matrix].inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Math [Vector].inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- MATH.inl" )

TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Math/Template Files" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Math [Scalar] [F].c_inc" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Math/Template Files" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Math [Matrix] [FXX_04].c_inc" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Math" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Math [Matrix].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Math" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Math.c" )





# GEOMETRY

        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 2D - Rectangle.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Box - Axis Aligned.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Box.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Capsule.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Circle.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Cylinder.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Disk.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Ellipse.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Line.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Mesh [BA].h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Mesh [BVT].h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Mesh [Simple].h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Parallelogram.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Particle.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Plane.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Ray.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Rectangle.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Segment.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Sphere.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Torus.h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Triangle [Collision].h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Triangle [Edge].h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Triangle [Point].h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Triangle [Space].h_inc" )
        TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Tube.h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry - Type.h_inc" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry/Template Files" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry.h_inc" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry - Constants.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- GEOMETRY.h" )

        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 2D - Rectangle.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Box - Axis Aligned.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Box.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Capsule.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Circle.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Cylinder.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Disk.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Ellipse.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Line.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Mesh [BA].i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Mesh [BVT].i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Mesh [Simple].i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Mesh [Utility].i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Parallelogram.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Particle.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Plane.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Ray.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Rectangle.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Segment.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Sphere.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Torus.i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Triangle [Collision].i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Triangle [Edge].i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Triangle [Point].i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Triangle [Space].i_inc" )
        TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry 3D - Tube.i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry - Type.i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry/Template Files" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Geometry - API.i_inc" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Geometry" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- GEOMETRY.inl" )

TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Circle.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Cylinder.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Disk.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Ellipse.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Mesh [BA].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Mesh [Simple].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Mesh [Utility].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Particle.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Torus.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Triangle [Collision].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Triangle [Edge].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry 3D - Triangle [Point].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Geometry" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Geometry.c" )





# UTILITY

TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Hash Table.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - LA Ring Buffer SRSW.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Profile Sample.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Reader Writer Lock.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Spin Lock.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Stack.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - Array.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - Colour.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - Job.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - List.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - Queue.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - String.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- UTIL.h" )

TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Hash Table.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - LA Ring Buffer SRSW.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Profile Sample.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Reader Writer Lock.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Spin Lock.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util MT - Stack.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - Array.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - Colour.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - List.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - Queue.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Util ST - String.inl" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "Public/Inline Files/Utility" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- UTIL.inl" )

TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Utility" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Util MT - Hash Table.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Utility" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Util MT - Reader Writer Lock.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Utility" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Util ST - Array.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Utility" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Util ST - Colour.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Utility" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Util ST - String.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Utility" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Util.c" )




# COMMON

TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common -- COMMON.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Console.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Console [Var].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Event MGR.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Job MGR.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Global.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Mem MGR.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - Profile.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "Public/Header Files/Common" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS Common - String MGR.h" )

TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "SDK/Header Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Event MGR - Internal.h" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "SDK/Header Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Event MGR.inl" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "-" "-" "SDK/Header Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Console - Internal.h" )
TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "SDK/Header Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Console.inl" )

TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common/Template" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Profile.c_inc" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Console [Var].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Console.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Event MGR [Time Event].c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Event MGR.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Job MGR.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Global.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Mem MGR.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Profile.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "-" "-" "SDK/Source Files/Common" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - String MGR.c" )





# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
#library compiler specific files

FOREACH (MK_LIST_ITEM__COMPILER_NAME IN LISTS MK_GENERATE_LIST__COMPILER_NAMES)
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__COMPILER_NAME} ${MK_COMPILER_NAME} "Public/Header Files/@Specialization/Compiler" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__COMPILER_NAME}) Common - Base - Defines [Compiler].h" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__COMPILER_NAME} ${MK_COMPILER_NAME} "Public/Inline Files/@Specialization/Compiler" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__COMPILER_NAME}) Common - Base - API [Platform].inl" )

ENDFOREACH ()




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
#library hardware specific files

FOREACH (MK_LIST_ITEM__HARDWARE_NAME IN LISTS MK_GENERATE_LIST__HARDWARE_NAMES)
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__HARDWARE_NAME} ${MK_HARDWARE_NAME} "Public/Header Files/@Specialization/Hardware" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__HARDWARE_NAME}) Common - Base - Defines [Hardware].h" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__HARDWARE_NAME} ${MK_HARDWARE_NAME} "Public/Header Files/@Specialization/Hardware" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__HARDWARE_NAME}) Common - Base - Include.h" )

ENDFOREACH ()




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
# threading library

FOREACH (MK_LIST_ITEM__THREAD_NAME IN LISTS MK_GENERATE_LIST__THREAD_NAMES)
    TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "SDK/Source Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Base - API [Platform].c" )
    TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "SDK/Source Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Global.c" )
    TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "SDK/Source Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Mem MGR.c" )

    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "Public/Inline Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Base - API [Platform].inl" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "Public/Header Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Base - Defines [Platform].h" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "Public/Header Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Base - Include.h" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "Public/Header Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Base - Type [MT].h" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "Public/Header Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Base - Type.h" )
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "Public/Header Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - Global.h" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "Public/Inline Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - STg1_MT_MX.inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__THREAD_NAME} ${MK_BUILD__THREAD_NAME} "Public/Inline Files/@Specialization/Thread Support" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__THREAD_NAME}) Common - STg1_MT_SM.inl" )

ENDFOREACH ()




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
# operating system

TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "WIN" ${MK_BUILD__OS_NAME} "SDK/Source Files/@Specialization/Operating System" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (WIN) Common - Link Test.c" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "WIN" ${MK_BUILD__OS_NAME} "SDK/Source Files/@Specialization/Operating System" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (WIN) Common - SysInfo.c" )

TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "WIN" ${MK_BUILD__OS_NAME} "Public/Header Files/@Specialization/Operating System" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (WIN) Common - Base - Defines [Platform].h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "WIN" ${MK_BUILD__OS_NAME} "Public/Header Files/@Specialization/Operating System" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (WIN) Common - Base - LoadDLL.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "WIN" ${MK_BUILD__OS_NAME} "Public/Header Files/@Specialization/Operating System" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (WIN) Common - Base - Type.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "WIN" ${MK_BUILD__OS_NAME} "Public/Header Files/@Specialization/Operating System" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (WIN) Common - SysInfo.h" )
TGS_ADD_HEADER_FILE( lib_source_files lib_header_files "WIN" ${MK_BUILD__OS_NAME} "SDK/Header Files/@Specialization/Operating System" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (WIN) Common - Internal with Windows.h" )




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
# universal package

FOREACH (MK_LIST_ITEM__UNIVERSAL_NAME IN LISTS MK_GENERATE_LIST__UNIVERSAL_NAMES)

ENDFOREACH ()

TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "UWP" ${MK_BUILD__UNIVERSAL_NAME} "SDK/Source Files/@Specialization/Universal" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common [Static].cpp" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "UWP" ${MK_BUILD__UNIVERSAL_NAME} "SDK/Source Files/@Specialization/Universal" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (UWP) Common - Base - API [Platform].cpp" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "UWP" ${MK_BUILD__UNIVERSAL_NAME} "SDK/Source Files/@Specialization/Universal" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (UWP) Common - Global.cpp" )
TGS_ADD_SOURCE_FILE( lib_source_files lib_header_files "UWP" ${MK_BUILD__UNIVERSAL_NAME} "SDK/Source Files/@Specialization/Universal" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (UWP) Common - Base - API [Platform].cpp" )

#TGS_ADD_WIN_PRECOMPILED_HEADER("${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (WIN) Common [Static].c" "WIN_C" "TgS (WIN) Common - Internal with Windows.h" )
#TGS_USE_WIN_PRECOMPILED_HEADER("${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (WIN) Common - Link Test.c" "WIN_C" "TgS (WIN) Common - Internal with Windows.h" )
#TGS_USE_WIN_PRECOMPILED_HEADER("${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS (WIN) Common - Base - API - Platform.c" "WIN_C" "TgS (WIN) Common - Internal with Windows.h" )




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
# math interface and implementation

SET( MK_GENERATE_LIST__MATH_INTERFACE_LIST_0    CLANG               X86_64              APPLE)
SET( MK_GENERATE_LIST__MATH_INTERFACE_LIST_1    ${MK_COMPILER_NAME} ${MK_HARDWARE_NAME} ${MK_BUILD__UNIVERSAL_NAME})
SET( MK_GENERATE_LIST__MATH_IMPLEMENTATION_0    X86_64              APPLE)
SET( MK_GENERATE_LIST__MATH_IMPLEMENTATION_1    ${MK_HARDWARE_NAME} ${MK_BUILD__UNIVERSAL_NAME})

FOREACH (MK_LIST_ITEM__NAME_0 MK_LIST_ITEM__NAME_1 IN ZIP_LISTS MK_GENERATE_LIST__MATH_INTERFACE_LIST_0 MK_GENERATE_LIST__MATH_INTERFACE_LIST_1)
    TGS_ADD_HEADER_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Header Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector].h" )

ENDFOREACH ()

FOREACH (MK_LIST_ITEM__NAME_0 MK_LIST_ITEM__NAME_1 IN ZIP_LISTS MK_GENERATE_LIST__MATH_IMPLEMENTATION_0 MK_GENERATE_LIST__MATH_IMPLEMENTATION_1)
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector].i_inc" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Matrix] [F32] [34].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Matrix] [F32] [44].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Matrix].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector] [F32_04].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector] [F32].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector] [S08].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector] [S16].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector] [S32].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector] [U08].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector] [U16].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector] [U32].inl" )
    TGS_ADD_INCSRC_FILE( lib_source_files lib_header_files ${MK_LIST_ITEM__NAME_0} ${MK_LIST_ITEM__NAME_1} "Public/Inline Files/@Specialization/Math" "${PROJECT_SOURCE_DIR}/../inc/TgS COMMON/TgS (${MK_LIST_ITEM__NAME_0}) Common - Math [Vector].inl" )

ENDFOREACH ()




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
ADD_LIBRARY("_Ring_0___TgS_COMMON" STATIC ${lib_source_files} ${lib_header_files})

SET( PCH_INCLUDE_DEFAULT "TgS Common - Internal.h")

TGS_SET_STANDARD_PROPERTIES( "_Ring_0___TgS_COMMON" "${PROJECT_SOURCE_DIR}/../src/TgS COMMON" "TgS Common [Static]" ${PCH_INCLUDE_DEFAULT} ${lib_source_files} ${lib_header_files} )

IF (MK_PLATFORM_UWP)
    TGS_ADD_CXX_PRECOMPILED_HEADER("${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common [Static].cpp" "CXX" ${PCH_INCLUDE_DEFAULT} )
    TGS_USE_PRECOMPILED_HEADER("${PROJECT_SOURCE_DIR}/../src/TgS COMMON/TgS Common - Base - API - Platform.cpp" "CXX" ${PCH_INCLUDE_DEFAULT} )
ENDIF ()
