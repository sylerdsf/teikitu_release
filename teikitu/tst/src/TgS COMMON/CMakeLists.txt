cmake_minimum_required(VERSION 3.17)
cmake_policy(VERSION 3.17)
#   »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
#library unit test

TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "~Unit Test" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Unit Test.c" )
TGS_ADD_HEADER_FILE( exe_source_files exe_header_files "-" "-" "~Unit Test" "${PROJECT_SOURCE_DIR}/../tst/inc/TgS COMMON/TgS Common [Unit Test] - Unit Test.h")
TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "~Unit Test" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test].c_inc")
TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "/" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Internal.h")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "/" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test].c" )




# BASE

TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests/Template Files" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - API [Text].c_inc" )
TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests/Template Files" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - API [Math].c_inc" )

TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - API [Math].c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - API [Platform].c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - API [Text].c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - API.c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - Type [Constants].c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - Type [File].c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - Type [IO].c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Base - Type [MP].c" )

TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base"       "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Case] - Base - API.c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base"       "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Case] - Base - Type.c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Base"       "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Set] - Base.c" )




# MATH

    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix] [API].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix] [F] [34].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix] [F] [44].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix] [F].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix] [N] [F] [34].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix] [N] [F] [44].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix] [N] [F].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix] [N].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Matrix" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Matrix].c_inc")

    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector] [API].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector] [FXX_04].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector] [F].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector] [I].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector] [N] [F32_04].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector] [N] [F].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector] [N] [I].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector] [N].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Vector" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Vector].c_inc")

    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Scalar" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Constants].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Math/Tests/Scalar" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Math [Scalar] [F].c_inc")

TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Math" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Case] - Math [Matrix].c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Math" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Case] - Math [Vector].c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Math" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Set] - Math.c")




# GEOMETRY

    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 2D - Rectangle.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Box - Axis Aligned.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Box.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Capsule.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Circle.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Cylinder.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Disk.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Ellipse.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Line.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Mesh [BA].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Mesh [BVT].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Mesh [Simple].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Parallelogram.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Particle.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Plane.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Ray.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Rectangle.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Segment.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Sphere.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Torus.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Triangle [Collision].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Triangle [Edge].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Triangle [Point].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Triangle [Space].c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry 3D - Tube.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Set] - Geometry.c_inc")
    TGS_ADD_INCSRC_FILE( exe_source_files exe_header_files "-" "-" "Geometry/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry - Type.c_inc")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Geometry" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Geometry.c")




# UTILITY

TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util MT - Hash Table.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util MT - LA Ring Buffer SRSW.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util MT - Profile Sample.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util MT - Reader Writer Lock.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util MT - Spin Lock.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util MT - Stack.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util ST - Array.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util ST - Colour.c" )
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util ST - List.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util ST - Queue.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Util ST - String.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Utility" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Util.c")




# COMMON

TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Console.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Event MGR.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Global.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Job MGR.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Mem MGR.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - Profile.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - String MGR.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common/Tests" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] [Test] - SysInfo.c")
TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "-" "-" "Common" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS Common [Unit Test] - Common.c")




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
#library platform specific files

TGS_ADD_SOURCE_FILE( exe_source_files exe_header_files "UWP" ${MK_PLATFORM_NAME} "~Unit Test" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON/TgS (UWP) Common [Unit Test].cpp" )




# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
#build library unit test
SET( PCH_INCLUDE_DEFAULT "TgS Common [Unit Test] - Internal.h")

TGS_ADD_UNITTEST_EXECUTABLE( "Unit_Test___Ring_0___TgS_COMMON" "${PROJECT_SOURCE_DIR}/../tst/src/TgS COMMON" "TgS Common [Unit Test]" ${PCH_INCLUDE_DEFAULT} "${exe_source_files}" "${exe_header_files}")

IF (MK_PLATFORM_WIN)
    TGS_ADD_LINKER_FLAGS("Unit_Test___Ring_0___TgS_COMMON" "/SUBSYSTEM:CONSOLE")
    TARGET_COMPILE_OPTIONS("Unit_Test___Ring_0___TgS_COMMON" PRIVATE "-DTgCOMPILE_WINDOWS_CONSOLE ")
ENDIF ()

TARGET_LINK_LIBRARIES("Unit_Test___Ring_0___TgS_COMMON" "_Ring_0___TgS_COMMON")
