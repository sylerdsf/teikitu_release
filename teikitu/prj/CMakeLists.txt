# 015482FC-A4BD-4E1C-AE49-A30E5728D73A
CMAKE_MINIMUM_REQUIRED(VERSION 3.4)
CMAKE_POLICY(VERSION 3.4)
CMAKE_POLICY(SET CMP0015 NEW)

# Base language overrides
SET (CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_SOURCE_DIR}/flag_overrides.cmake)

# Stream specific solution name
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_stream.cmake)
#MESSAGE("STREAM PROJECT NAME: ${_CMAKE_PROJECT_NAME} / ${MK_PROJECT_NAME}")

# Project (Solution for MSVC)
PROJECT (${_CMAKE_PROJECT_NAME} VERSION 4.5.0.0 LANGUAGES C)
# MESSAGE("DEBUG PROJECT: ${PROJECT_VERSION_MAJOR} / ${PROJECT_VERSION_MINOR} / ${PROJECT_VERSION_PATCH} / ${PROJECT_VERSION_TWEAK}")

# Project Configurations
SET (CMAKE_CONFIGURATION_TYPES Debug Release Final Tools )
SET (CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "Reset the configurations to what we need" FORCE )

# General CMake Environment
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_config.cmake)

# Supported Platforms, Hardware, and Compilers - Used to include inactive files into supported IDEs
SET (MK_GENERATE_LIST__COMPILER_NAMES "CLANG" "MSVC")
LIST (REMOVE_DUPLICATES MK_GENERATE_LIST__COMPILER_NAMES)

SET (MK_GENERATE_LIST__HARDWARE_NAMES "C11_64" "X86_64")
#MESSAGE(${MK_GENERATE_LIST__HARDWARE_NAMES})
LIST (REMOVE_DUPLICATES MK_GENERATE_LIST__HARDWARE_NAMES)
#MESSAGE(${MK_GENERATE_LIST__HARDWARE_NAMES})

SET (MK_GENERATE_LIST__THREAD_NAMES "POSIX" "WIN")
LIST (REMOVE_DUPLICATES MK_GENERATE_LIST__PLATFORM_NAMES)

SET (MK_GENERATE_LIST__UNIVERSAL_NAMES "APPLE" "UWP")
LIST (REMOVE_DUPLICATES MK_GENERATE_LIST__UNIVERSAL_NAMES)


# Rings
#SET (_Ring_0___LIBS "_Ring_0___TgS_COMMON" )
SET (_Ring_0___LIBS "_Ring_0___TgS_COMMON" "_Ring_0___TgS_COLLISION" "_Ring_0___TgS_PARTITION" "_Ring_0___TgS_PATH-AI" )
SET (_Ring_2___LIBS "_Ring_2___TgS_KERNEL" "_Ring_U___TgS_UTILITY" )
SET (_Ring_3___LIBS "_Ring_3___TgS_ANIMATION" "_Ring_3___TgS_INPUT" "_Ring_3___TgS_PHYSICS" "_Ring_3___TgS_RENDER" "_Ring_3___TgS_SOUND" )
SET (_Ring_4___LIBS "_Ring_4___TgS_EFFECT" "_Ring_4___TgS_OBJECT" "_Ring_4___TgS_SCRIPT" "_Ring_4___TgS_SET" )
SET (_Ring_5___LIBS "_Ring_5___TgS_EXECUTE" )

# Projects
ADD_SUBDIRECTORY ("../src/TgS COMMON" "_Ring_0___TgS_COMMON")
ADD_SUBDIRECTORY ("../src/TgS COLLISION" "_Ring_0___TgS_COLLISION")
ADD_SUBDIRECTORY ("../src/TgS PARTITION" "_Ring_0___TgS_PARTITION")
ADD_SUBDIRECTORY ("../src/TgS PATH-AI" "_Ring_0___TgS_PATH-AI")

ADD_SUBDIRECTORY ("../src/TgS KERNEL" "_Ring_2___TgS_KERNEL")

ADD_SUBDIRECTORY ("../src/TgS ANIMATION" "_Ring_3___TgS_ANIMATION")
ADD_SUBDIRECTORY ("../src/TgS INPUT" "_Ring_3___TgS_INPUT")
ADD_SUBDIRECTORY ("../src/TgS PHYSICS" "_Ring_3___TgS_PHYSICS")
ADD_SUBDIRECTORY ("../src/TgS RENDER" "_Ring_3___TgS_RENDER")
ADD_SUBDIRECTORY ("../src/TgS SOUND" "_Ring_3___TgS_SOUND")

ADD_SUBDIRECTORY ("../src/TgS EFFECT" "_Ring_4___TgS_EFFECT")
ADD_SUBDIRECTORY ("../src/TgS OBJECT" "_Ring_4___TgS_OBJECT")
ADD_SUBDIRECTORY ("../src/TgS SCRIPT" "_Ring_4___TgS_SCRIPT")
ADD_SUBDIRECTORY ("../src/TgS SET" "_Ring_4___TgS_SET")

ADD_SUBDIRECTORY ("../src/TgS EXECUTE" "_Ring_5___TgS_EXECUTE")

ADD_SUBDIRECTORY ("../src/TgS UTILITY" "_Ring_U___TgS_UTILITY")


# Unit Tests
ADD_SUBDIRECTORY ("../tst/src/TgS COMMON" "Unit_Test___Ring_0___TgS_COMMON")
ADD_SUBDIRECTORY ("../tst/src/TgS COLLISION" "Unit_Test___Ring_0___TgS_COLLISION")
ADD_SUBDIRECTORY ("../tst/src/TgS PARTITION" "Unit_Test___Ring_0___TgS_PARTITION")
ADD_SUBDIRECTORY ("../tst/src/TgS PATH-AI" "Unit_Test___Ring_0___TgS_PATH-AI")

ADD_SUBDIRECTORY ("../tst/src/TgS KERNEL" "Unit_Test___Ring_2___TgS_KERNEL")

ADD_SUBDIRECTORY ("../tst/src/TgS ANIMATION" "Unit_Test___Ring_3___TgS_ANIMATION")
ADD_SUBDIRECTORY ("../tst/src/TgS INPUT" "Unit_Test___Ring_3___TgS_INPUT")
ADD_SUBDIRECTORY ("../tst/src/TgS PHYSICS" "Unit_Test___Ring_3___TgS_PHYSICS")
ADD_SUBDIRECTORY ("../tst/src/TgS RENDER" "Unit_Test___Ring_3___TgS_RENDER")
ADD_SUBDIRECTORY ("../tst/src/TgS SOUND" "Unit_Test___Ring_3___TgS_SOUND")

#All the dependencies (rendering etc.) need to be completed first
ADD_SUBDIRECTORY ("../tst/src/TgS EFFECT" "Unit_Test___Ring_4___TgS_EFFECT")


# Documentation
INCLUDE(${CMAKE_SOURCE_DIR}/project_report.cmake)


# Cmake files in the project tree
TGS_ADD_CMAKE_FILE( build_files__cmake build_files__cmake "-" "-" "" "${PROJECT_SOURCE_DIR}/../prj/cmake_config.cmake" )
TGS_ADD_CMAKE_FILE( build_files__cmake build_files__cmake "-" "-" "" "${PROJECT_SOURCE_DIR}/../prj/cmake_solution_name.cmake" )
TGS_ADD_CMAKE_FILE( build_files__cmake build_files__cmake "-" "-" "" "${PROJECT_SOURCE_DIR}/../prj/flag_overrides.cmake" )
TGS_ADD_CMAKE_FILE( build_files__cmake build_files__cmake "-" "-" "" "${PROJECT_SOURCE_DIR}/../prj/project_report.cmake" )
TGS_ADD_CMAKE_FILE( build_files__cmake build_files__cmake "-" "-" "" "${PROJECT_SOURCE_DIR}/CMakeLists.txt" )
TGS_ADD_CMAKE_FILE( build_files__cmake build_files__cmake "-" "-" "bootstrap" "${PROJECT_SOURCE_DIR}/bootstrap/CMakeLists.txt" )

ADD_CUSTOM_TARGET( CMakeFiles SOURCES ${build_files__cmake})

