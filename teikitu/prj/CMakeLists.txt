CMAKE_MINIMUM_REQUIRED(VERSION 3.4)
CMAKE_POLICY(VERSION 3.4)
CMAKE_POLICY(SET CMP0015 NEW)

# Base language overrides
SET (CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_SOURCE_DIR}/flag_overrides.cmake)

# Stream specific solution name
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_stream.cmake)
#MESSAGE("STREAM PROJECT NAME: ${_CMAKE_PROJECT_NAME} / ${MK_PROJECT_NAME}")

# Project (Solution for MSVC)
PROJECT (${_CMAKE_PROJECT_NAME} VERSION 4.5.0.0)
# MESSAGE("DEBUG PROJECT: ${PROJECT_VERSION_MAJOR} / ${PROJECT_VERSION_MINOR} / ${PROJECT_VERSION_PATCH} / ${PROJECT_VERSION_TWEAK}")

# Project Configurations
SET (CMAKE_CONFIGURATION_TYPES Debug Release Final Tools )
SET (CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "Reset the configurations to what we need" FORCE )

# General CMake Environment
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_config.cmake)

# Supported Platforms, Hardware, and Compilers - Used to include inactive files into supported IDEs
SET (MK_GENERATE_LIST__HARDWARE_NAMES ${MK_HARDWARE_NAME} "X86_64")
#MESSAGE(${MK_GENERATE_LIST__HARDWARE_NAMES})
LIST (REMOVE_DUPLICATES MK_GENERATE_LIST__HARDWARE_NAMES)
#MESSAGE(${MK_GENERATE_LIST__HARDWARE_NAMES})

SET (MK_GENERATE_LIST__PLATFORM_NAMES ${MK_PLATFORM_NAME} "POSIX" "WIN")
LIST (REMOVE_DUPLICATES MK_GENERATE_LIST__PLATFORM_NAMES)

SET (MK_GENERATE_LIST__COMPILER_NAMES ${MK_COMPILER_NAME} "CLANG" "MSVC")
LIST (REMOVE_DUPLICATES MK_GENERATE_LIST__COMPILER_NAMES)

# Rings
SET (_Ring_0___LIBS "_Ring_0___TgS_COMMON" )

# Projects
ADD_SUBDIRECTORY ("../src/TgS COMMON" "_Ring_0___TgS_COMMON")


# Unit Tests
#ADD_SUBDIRECTORY ("../tst/src/TgS COMMON" "Unit_Test___Ring_0___TgS_COMMON")


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

