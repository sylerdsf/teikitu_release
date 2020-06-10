
# ========================================================================================================================================================================================================
#  Utility Functions
# ========================================================================================================================================================================================================
INCLUDE (CMakeParseArguments)

##########################################################################################################################################################################################################
# Add/append link flags to a target. 
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_ADD_LIB_FLAGS target) 
    SET_PROPERTY(TARGET ${target} APPEND_STRING PROPERTY STATIC_LIBRARY_FLAGS ${ARGN})
ENDMACRO() 

##########################################################################################################################################################################################################
# Add/append link flags to a target. 
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_ADD_LINKER_FLAGS target) 
    SET_PROPERTY(TARGET ${target} APPEND_STRING PROPERTY LINK_FLAGS ${ARGN})
ENDMACRO() 

##########################################################################################################################################################################################################
# Add/append link flags to a target. 
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_ADD_COMPILER_FLAGS target) 
    SET_PROPERTY(SOURCE ${target} APPEND_STRING PROPERTY COMPILE_FLAGS ${ARGN})
ENDMACRO() 

##########################################################################################################################################################################################################
# Create a precompiled header file
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_ADD_PRECOMPILED_HEADER target ext pch_file) 
    IF (MK_COMPILER_FLAVOUR__MSVC_MSVC)
        TGS_ADD_COMPILER_FLAGS( ${target} " /Fp\"$(IntDir)$(TargetName)_${ext}.pch\" /Yc\"${pch_file}\" /FI\"${pch_file}\" ")

    ELSEIF (MK_COMPILER__CLANG)
        TGS_ADD_COMPILER_FLAGS(${target} " -x c-header ")
        TGS_ADD_COMPILER_FLAGS(${target} " -include \"${pch_file}\" ")

    ENDIF ()
ENDMACRO() 

##########################################################################################################################################################################################################
# Create a precompiled header file
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_ADD_CXX_PRECOMPILED_HEADER target ext pch_file) 
    IF (MK_COMPILER_FLAVOUR__MSVC_MSVC)
        TGS_ADD_COMPILER_FLAGS( ${target} " /Fp\"$(IntDir)$(TargetName)_${ext}.pch\" /Yc\"${pch_file}\" /FI\"${pch_file}\" ")

    ELSEIF (MK_COMPILER__CLANG)
        TGS_ADD_COMPILER_FLAGS(${target} " -x c++-header ")
        TGS_ADD_COMPILER_FLAGS(${target} " -include \"${pch_file}\" ")
    ENDIF ()
ENDMACRO() 

##########################################################################################################################################################################################################
# Use a precompiled header file
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_USE_PRECOMPILED_HEADER target ext pch_file)
    IF (MK_COMPILER_FLAVOUR__MSVC_MSVC)
        TGS_ADD_COMPILER_FLAGS( ${target} " /Fp\"$(IntDir)$(TargetName)_${ext}.pch\" /Yu\"${pch_file}\" /FI\"${pch_file}\" ")

    ELSEIF (MK_COMPILER__CLANG)
        TGS_ADD_COMPILER_FLAGS(${target} " -include \"${pch_file}\" ")

    ENDIF ()
ENDMACRO() 

##########################################################################################################################################################################################################
# Create a precompiled header file
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_ADD_WIN_PRECOMPILED_HEADER target ext pch_file)
    IF (MK_COMPILER__MSVC)
        SET_SOURCE_FILES_PROPERTIES( ${target} PROPERTIES DISABLE_LANGUAGE_EXTENSIONS 0 )
    ENDIF ()
    TGS_ADD_PRECOMPILED_HEADER( ${target} ${ext} ${pch_file} )
ENDMACRO() 

##########################################################################################################################################################################################################
# Create a precompiled header file
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_ADD_WIN_CXX_PRECOMPILED_HEADER target ext pch_file)
    IF (MK_COMPILER__MSVC)
        SET_SOURCE_FILES_PROPERTIES( ${target} PROPERTIES DISABLE_LANGUAGE_EXTENSIONS 0 )
    ENDIF ()
    TGS_ADD_CXX_PRECOMPILED_HEADER( ${target} ${ext} ${pch_file} )
ENDMACRO() 

##########################################################################################################################################################################################################
# Use a precompiled header file
# target: string: target name. 
# flags : string: link flags to be appended 
MACRO(TGS_USE_WIN_PRECOMPILED_HEADER target ext pch_file) 
    IF (MK_COMPILER__MSVC)
        SET_SOURCE_FILES_PROPERTIES( ${target} PROPERTIES DISABLE_LANGUAGE_EXTENSIONS 0 )
    ENDIF ()
    TGS_USE_PRECOMPILED_HEADER( ${target} ${ext} ${pch_file} )
ENDMACRO() 

##########################################################################################################################################################################################################
# add a source file to the given list
MACRO(TGS_ADD_FILE_TO_IDE source_files header_files test_assigned test_current file)
    CMAKE_PARSE_ARGUMENTS (TGS_ADD_FILE_TO_IDE "" "IDE_PATH" "" ${ARGN} )
    #MESSAGE("${source_files}")
    #MESSAGE("${TGS_ADD_FILE_TO_IDE_IDE_PATH}")
    #MESSAGE("${file}")
    #MESSAGE(TEST: ${test_current} ${test_assigned})

    # Add the file to the correct list for compilation
    IF ((${test_current} STREQUAL ${test_assigned}))
        SET (${source_files} ${${source_files}} "${file}")

    ELSEIF (MK_IDE__INCLUDE_NON_SOURCE_FILES)
        SET (${header_files} ${${header_files}} "${file}")
        SET_PROPERTY(SOURCE ${file} PROPERTY  HEADER_FILE_ONLY TRUE)

    ENDIF ()

    # Assign an IDE path (folder structure)
    IF (TGS_ADD_FILE_TO_IDE_IDE_PATH AND NOT ${TGS_ADD_FILE_TO_IDE_IDE_PATH} STREQUAL "")
        STRING( REPLACE "/" "\\" IDE_PATH_FIXED ${TGS_ADD_FILE_TO_IDE_IDE_PATH} )
        #MESSAGE("${IDE_PATH_FIXED}")

        IF (MK_IDE__INCLUDE_NON_SOURCE_FILES AND NOT (${test_current} STREQUAL ${test_assigned}))
            SET (IDE_PATH_FIXED "${IDE_PATH_FIXED}\\${test_assigned} (Inactive)")
        ENDIF ()
        #MESSAGE("${IDE_PATH_FIXED}")

        SOURCE_GROUP ("${IDE_PATH_FIXED}" FILES "${file}")

    ENDIF ()
ENDMACRO()


##########################################################################################################################################################################################################
# add a source file to the given list
MACRO(TGS_ADD_SOURCE_FILE source_files header_files test_assigned test_current ide_path file)
    TGS_ADD_FILE_TO_IDE(${source_files} ${header_files} ${test_assigned} ${test_current} ${file} IDE_PATH ${ide_path})
    IF ((${test_current} STREQUAL ${test_assigned}))
        SET_PROPERTY(SOURCE ${file} PROPERTY XCODE_EXPLICIT_FILE_TYPE sourcecode.c.c)
        SET_PROPERTY(SOURCE ${file} PROPERTY XCODE_LAST_KNOWN_FILE_TYPE sourcecode.c.c)
    ELSE ()
        SET_PROPERTY(SOURCE ${file} PROPERTY XCODE_EXPLICIT_FILE_TYPE sourcecode.c.h)
        SET_PROPERTY(SOURCE ${file} PROPERTY XCODE_LAST_KNOWN_FILE_TYPE sourcecode.c.h)
    ENDIF ()
ENDMACRO()

##########################################################################################################################################################################################################
# add a source file to the given list
MACRO(TGS_ADD_INCSRC_FILE source_files header_files test_assigned test_current ide_path file)
    IF (MK_IDE__INCLUDE_NON_SOURCE_FILES)
        TGS_ADD_FILE_TO_IDE(${header_files} ${header_files} ${test_assigned} ${test_current} ${file} IDE_PATH ${ide_path})
        SET_PROPERTY(SOURCE ${file} PROPERTY XCODE_EXPLICIT_FILE_TYPE sourcecode.c.h)
        SET_PROPERTY(SOURCE ${file} PROPERTY XCODE_LAST_KNOWN_FILE_TYPE sourcecode.c.h)
        SET_PROPERTY(SOURCE ${file} PROPERTY  HEADER_FILE_ONLY TRUE)

    ENDIF ()
ENDMACRO()

##########################################################################################################################################################################################################
# add a source file to the given list
MACRO(TGS_ADD_HEADER_FILE source_files header_files test_assigned test_current ide_path file)
    IF (MK_IDE__INCLUDE_NON_SOURCE_FILES)
        TGS_ADD_FILE_TO_IDE(${header_files} ${header_files} ${test_assigned} ${test_current} ${file} IDE_PATH ${ide_path})
        SET_PROPERTY(SOURCE ${file} PROPERTY XCODE_EXPLICIT_FILE_TYPE sourcecode.c.h)
        SET_PROPERTY(SOURCE ${file} PROPERTY XCODE_LAST_KNOWN_FILE_TYPE sourcecode.c.h)
        SET_PROPERTY(SOURCE ${file} PROPERTY  HEADER_FILE_ONLY TRUE)

    ENDIF ()
ENDMACRO()

##########################################################################################################################################################################################################
# add a source file to the given list
MACRO(TGS_ADD_CMAKE_FILE source_files header_files test_assigned test_current ide_path file)
    IF (MK_IDE__INCLUDE_NON_SOURCE_FILES)
        TGS_ADD_FILE_TO_IDE(${header_files} ${header_files} ${test_assigned} ${test_current} ${file} IDE_PATH ${ide_path})
    ENDIF ()
ENDMACRO()




# ========================================================================================================================================================================================================
#  Feature Enable / Disable and Default Compilation Configuration
#    - Include the list of primary configuration variables for legibility
# ========================================================================================================================================================================================================

SET (MK_CMAKE_BUILD_VERSION                     1.0.0.0) # major[.minor[.patch[.tweak]]]

SET (MK_IDE__UNIX_MAKEFILES                     0 )
SET (MK_IDE__MSVC                               0 )
SET (MK_IDE__XCODE                              0 )

SET (MK_COMPILER__CLANG                         0)
SET (MK_COMPILER__MSVC                          0)
SET (MK_COMPILER__ICL                           0)
SET (MK_COMPILER__GCC                           0)

SET (MK_COMPILE_HW__X86_64                      1 )
SET (MK_COMPILE_HW__X86_32                      0 CACHE BOOL "")
SET (MK_COMPILE_HW__PPC                         0 CACHE BOOL "")
SET (MK_COMPILE_HW__ARM                         0 CACHE BOOL "")

SET (MK_PLATFORM__POSIX                         1)
SET (MK_PLATFORM__WIN                           0 CACHE BOOL "")
SET (MK_PLATFORM__WIN_UWP                       0 CACHE BOOL "")
SET (MK_PLATFORM__XB2                           0 CACHE BOOL "")
SET (MK_PLATFORM__XB3                           0 CACHE BOOL "")
SET (MK_PLATFORM__XB4                           0 CACHE BOOL "")
SET (MK_PLATFORM__PS3                           0 CACHE BOOL "")
SET (MK_PLATFORM__PS4                           0 CACHE BOOL "")
SET (MK_PLATFORM__PS5                           0 CACHE BOOL "")
SET (MK_PLATFORM__IPHONE                        0 CACHE BOOL "")
SET (MK_PLATFORM__IPAD                          0 CACHE BOOL "")
SET (MK_PLATFORM__APPLE_TV                      0 CACHE BOOL "")
SET (MK_PLATFORM__IWATCH                        0 CACHE BOOL "")
SET (MK_PLATFORM__MAC                           0 CACHE BOOL "")
SET (MK_PLATFORM__LINUX                         0 CACHE BOOL "")

SET (MK_COMPILE_PLATFORM_TEXT__ANSI             1)
SET (MK_COMPILE_PLATFORM_TEXT__WIDE             0 CACHE BOOL "")

SET (MK_FEATURE_GPU__NONE                       1)
SET (MK_FEATURE_GPU__DX12                       0 CACHE BOOL "")
SET (MK_FEATURE_GPU__OGL                        0 CACHE BOOL "")
SET (MK_FEATURE_GPU__OGLES                      0 CACHE BOOL "")
SET (MK_FEATURE_GPU__METAL                      0 CACHE BOOL "")
SET (MK_FEATURE_GPU__VULKAN                     0 CACHE BOOL "")

SET (MK_FEATURE_AUDIO__NONE                     1)
SET (MK_FEATURE_AUDIO__XAUDIO2                  0 CACHE BOOL "")




# ========================================================================================================================================================================================================
#  Standard Configuration
# ========================================================================================================================================================================================================

SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY             ${PROJECT_SOURCE_DIR}/../lib/)
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY             ${PROJECT_SOURCE_DIR}/../lib/)
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY             ${PROJECT_SOURCE_DIR}/../bin/)
SET (CMAKE_OBJECT_OUTPUT_DIRECTORY              ${PROJECT_SOURCE_DIR}/../obj/)
SET (CMAKE_DEFAULT_LIBRARIES                    "")

# Compiler Flags for Configuration

SET (CMAKE_C_FLAGS_DEBUG                        "${CMAKE_C_FLAGS_DEBUG} -DTGS_DEBUG")
SET (CMAKE_C_FLAGS_RELEASE                      "${CMAKE_C_FLAGS_RELEASE} -DTGS_RELEASE")
SET (CMAKE_C_FLAGS_FINAL                        "${CMAKE_C_FLAGS_FINAL} -DTGS_FINAL")
SET (CMAKE_C_FLAGS_TOOLS                        "${CMAKE_C_FLAGS_TOOLS} -DTGS_TOOLS")

SET (CMAKE_CXX_FLAGS_DEBUG                      "${CMAKE_CXX_FLAGS_DEBUG} -DTGS_DEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE                    "${CMAKE_CXX_FLAGS_RELEASE} -DTGS_RELEASE")
SET (CMAKE_CXX_FLAGS_FINAL                      "${CMAKE_CXX_FLAGS_FINAL} -DTGS_FINAL")
SET (CMAKE_CXX_FLAGS_TOOLS                      "${CMAKE_CXX_FLAGS_TOOLS} -DTGS_TOOLS")

SET (CMAKE_DEBUG_POSTFIX                        "")
SET (CMAKE_RELEASE_POSTFIX                      "")
SET (CMAKE_FINAL_POSTFIX                        "")
SET (CMAKE_TOOLS_POSTFIX                        "")




# ========================================================================================================================================================================================================
#  Configuration for IDE
# ========================================================================================================================================================================================================

IF (__CMAKE_IDE_MSVC)
    SET (MK_IDE__MSVC                               1)
    SET (MK_IDE__INCLUDE_NON_SOURCE_FILES           1) # Add the non-source files to the project
    SET (MK_IDE_NAME                                MSVC)

    IF (CMAKE_VS_PLATFORM_NAME MATCHES "x64")
        SET (MK_PLATFORM__WIN                           1 )
        SET (MK_PLATFORM__WIN_WIN64                     1 )
    ELSE ()
        MESSAGE(FATAL_ERROR "UNSUPPORTED VS PLATFORM")
    ENDIF ()

ELSEIF (__CMAKE_IDE_XCODE)
    SET (MK_IDE__XCODE                              1)
    SET (MK_IDE__INCLUDE_NON_SOURCE_FILES           1) # Add the non-source files to the project
    SET (MK_IDE_NAME                                XCODE)

    # Copy the Workspace settings file from the current directory to the given location
    CONFIGURE_FILE(
        WorkspaceSettings.xcsettings
        ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.xcodeproj/project.xcworkspace/xcuserdata/$ENV{USER}.xcuserdatad/WorkspaceSettings.xcsettings
        COPYONLY
    )

ELSEIF (__CMAKE_IDE_UNIX_MAKEFILES)
    SET (MK_IDE__UNIX_MAKEFILES                     1)
    SET (MK_IDE_NAME                                UNIX_MAKEFILES)

    #SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -save-temps=obj --comments --preprocess")

ENDIF ()

IF ("${MK_IDE_NAME}" STREQUAL "")
    MESSAGE(FATAL_ERROR "UNSUPPORTED IDE: " ${CMAKE_GENERATOR})
ENDIF ()

SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgIDE__${MK_IDE_NAME}")
SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgIDE=${MK_IDE_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgIDE__${MK_IDE_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgIDE=${MK_IDE_NAME}")




# ========================================================================================================================================================================================================
#  Configuration for Compiler
# ========================================================================================================================================================================================================

# Compiler Flags for Compiler

SET (MK_COMPILER_NAME                         "")

IF (__CMAKE_C_COMPILER__CLANG)
    SET (MK_COMPILER__CLANG                         1)
    SET (MK_COMPILER_NAME                           "CLANG")

ELSEIF (__CMAKE_C_COMPILER__MSVC)
    SET (MK_COMPILER__MSVC                          1)
    SET (MK_COMPILER_NAME                           "MSVC")

ELSEIF (__CMAKE_CXX_COMPILER__ICL)
    SET (MK_COMPILER__ICL                           1)
    SET (MK_COMPILER_NAME                           "ICL")

ELSEIF (__CMAKE_CXX_COMPILER__GCC)
    SET (MK_COMPILER__GCC                           1)
    SET (MK_COMPILER_NAME                           "GCC")
ENDIF ()

IF ("${MK_COMPILER_NAME}" STREQUAL "")
    MESSAGE(FATAL_ERROR "UNKNOWN OR UNSUPPORTED COMPILER")
ENDIF ()

SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgBUILD_COMPILER__${MK_COMPILER_NAME}")
SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgBUILD_COMPILER=${MK_COMPILER_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgBUILD_COMPILER__${MK_COMPILER_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgBUILD_COMPILER=${MK_COMPILER_NAME}")

STRING( TOLOWER ${MK_COMPILER_NAME}             MK_COMPILER_PATH )
SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY             ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}${MK_COMPILER_PATH}/)
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY             ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}${MK_COMPILER_PATH}/)
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY             ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}${MK_COMPILER_PATH}/)
SET (CMAKE_OBJECT_OUTPUT_DIRECTORY              ${CMAKE_OBJECT_OUTPUT_DIRECTORY}${MK_COMPILER_PATH}/)


# Compiler Flags for Compiler Flavours

SET (MK_COMPILER_FLAVOUR_NAME                    "")

IF (__CMAKE_C_COMPILER_FLAVOUR__CLANG_LLVM)
    SET (MK_COMPILER_FLAVOUR__CLANG_LLVM            1)
    SET (MK_COMPILER_FLAVOUR_NAME                   "LLVM")

ELSEIF (__CMAKE_C_COMPILER_FLAVOUR__CLANG_APPLE)
    SET (MK_COMPILER_FLAVOUR__CLANG_APPLE           1)
    SET (MK_COMPILER_FLAVOUR_NAME                   "APPLE")

ELSEIF (__CMAKE_C_COMPILER_FLAVOUR__MSVC_CLANG)
    SET (MK_COMPILER_FLAVOUR__MSVC_CLANG            1)
    SET (MK_COMPILER_FLAVOUR_NAME                   "CLANG")
    
ELSEIF (__CMAKE_C_COMPILER_FLAVOUR__MSVC_MSVC)
    SET (MK_COMPILER_FLAVOUR__MSVC_MSVC             1)
    SET (MK_COMPILER_FLAVOUR_NAME                   "MSVC")
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} /Z7 /Fp\"$(IntDir)$(TargetName)_C.pch\" -D_ANALYSIS")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} /Fp\"$(IntDir)$(TargetName)_CXX.pch\" -D_ANALYSIS")

ENDIF ()


IF ("${MK_COMPILER_FLAVOUR_NAME}" STREQUAL "")
    SET (MK_PROJECT_NAME                            "${MK_PROJECT_NAME} [${MK_COMPILER_NAME}]")
ELSE ()
    SET (MK_PROJECT_NAME                            "${MK_PROJECT_NAME} [${MK_COMPILER_NAME}-${MK_COMPILER_FLAVOUR_NAME}]")
    
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgBUILD_COMPILER_FLAVOUR__${MK_COMPILER_NAME}_${MK_COMPILER_FLAVOUR_NAME}")
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgBUILD_COMPILER_FLAVOUR=${MK_COMPILER_NAME}_${MK_COMPILER_FLAVOUR_NAME}")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgBUILD_COMPILER_FLAVOUR__${MK_COMPILER_NAME}_${MK_COMPILER_FLAVOUR_NAME}")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgBUILD_COMPILER_FLAVOUR=${MK_COMPILER_NAME}_${MK_COMPILER_FLAVOUR_NAME}")

    STRING( TOLOWER ${MK_COMPILER_FLAVOUR_NAME}     MK_COMPILER_FLAVOUR_PATH )
    SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY             "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}${MK_COMPILER_FLAVOUR_PATH}/")
    SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY             "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}${MK_COMPILER_FLAVOUR_PATH}/")
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY             "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}${MK_COMPILER_FLAVOUR_PATH}/")
    SET (CMAKE_OBJECT_OUTPUT_DIRECTORY              "${CMAKE_OBJECT_OUTPUT_DIRECTORY}${MK_COMPILER_FLAVOUR_PATH}/")
ENDIF ()




# ========================================================================================================================================================================================================
#  Configuration for Hardware
# ========================================================================================================================================================================================================

SET (MK_HARDWARE_NAME                           "")
SET (MK_HARDWARE__POINTER_SIZE                  0)
SET (MK_HARDWARE__VECTOR_PASS_IN_REGISTER       0)

IF (MK_COMPILE_HW__X86_32)
    SET (MK_HARDWARE_NAME                           "X86_32")
    SET (MK_HARDWARE__POINTER_SIZE                  4)
    SET (MK_HARDWARE__VECTOR_PASS_IN_REGISTER       0)
ELSEIF (MK_COMPILE_HW__ARM)
    SET (MK_HARDWARE_NAME                           "ARM")
    SET (MK_HARDWARE__POINTER_SIZE                  8)
    SET (MK_HARDWARE__VECTOR_PASS_IN_REGISTER       0)
ELSEIF (MK_COMPILE_HW__PPC)
    SET (MK_HARDWARE_NAME                           "PPC")
    SET (MK_HARDWARE__POINTER_SIZE                  4)
    SET (MK_HARDWARE__VECTOR_PASS_IN_REGISTER       1)
ELSEIF (MK_COMPILE_HW__X86_64)
    SET (MK_HARDWARE_NAME                           "X86_64")
    SET (MK_HARDWARE__POINTER_SIZE                  8)
    SET (MK_HARDWARE__VECTOR_PASS_IN_REGISTER       1)
ENDIF ()

IF ("${MK_HARDWARE_NAME}" STREQUAL "")
    MESSAGE(FATAL_ERROR "MUST HAVE A TARGET HARDWARE ARCHITECTURE")
ENDIF ()

SET (MK_PROJECT_NAME                            "${MK_PROJECT_NAME} [${MK_HARDWARE_NAME}]")

SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_HARDWARE__${MK_HARDWARE_NAME}")
SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_HARDWARE=${MK_HARDWARE_NAME}")
SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgTARGET_HARDWARE__POINTER_SIZE=${MK_HARDWARE__POINTER_SIZE}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_HARDWARE__${MK_HARDWARE_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_HARDWARE=${MK_HARDWARE_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgTARGET_HARDWARE__POINTER_SIZE=${MK_HARDWARE__POINTER_SIZE}")

IF (MK_HARDWARE__VECTOR_PASS_IN_REGISTER)
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgTARGET_HARDWARE__VECTOR_PASS_IN_REGISTER")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgTARGET_HARDWARE__VECTOR_PASS_IN_REGISTER")
ENDIF ()




# ========================================================================================================================================================================================================
#  Configuration for Platform
# ========================================================================================================================================================================================================

SET (MK_PLATFORM_NAME                           "")

IF (MK_PLATFORM__POSIX)
    SET (MK_PLATFORM_NAME                           "POSIX")

ELSEIF (MK_PLATFORM__WIN)
    SET (MK_PLATFORM_NAME                           "WIN")

ELSEIF (MK_PLATFORM__WIN_UWP)
    IF (NOT WINDOWS_STORE)
        MESSAGE(FATAL_ERROR "PLATFORM UWP SELECTED BUT WINDOWS_STORE NOT ENABLED")
    ENDIF ()
    SET (MK_COMPILE_PLATFORM_TEXT__WIDE             1)
    SET (MK_PLATFORM_NAME                           "UWP")

ELSEIF (MK_PLATFORM__IPHONE)
    SET (MK_PLATFORM_NAME                           "IPHONE")

ELSEIF (MK_PLATFORM__IPAD)
    SET (MK_PLATFORM_NAME                           "IPAD")

ELSEIF (MK_PLATFORM__APPLE_TV)
    SET (MK_PLATFORM_NAME                           "APPLE_TV")

ELSEIF (MK_PLATFORM__IWATCH)
    SET (MK_PLATFORM_NAME                           "IWATCH")

ELSEIF (MK_PLATFORM__MAC)
    SET (MK_PLATFORM_NAME                           "MAC")

ELSEIF (MK_PLATFORM__LINUX)
    SET (MK_PLATFORM_NAME                           "LINUX")

ENDIF ()

IF ("${MK_PLATFORM_NAME}" STREQUAL "")
    MESSAGE(FATAL_ERROR "MUST HAVE A TARGET PLATFORM")
ENDIF ()

SET (MK_PROJECT_NAME                            "${MK_PROJECT_NAME} [${MK_PLATFORM_NAME}]")

SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_PLATFORM__${MK_PLATFORM_NAME}")
SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_PLATFORM=${MK_PLATFORM_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_PLATFORM__${MK_PLATFORM_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_PLATFORM=${MK_PLATFORM_NAME}")

STRING( TOLOWER ${MK_PLATFORM_NAME}             MK_PLATFORM_PATH )
SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY             ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}${MK_PLATFORM_PATH}/)
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY             ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}${MK_PLATFORM_PATH}/)
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY             ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}${MK_PLATFORM_PATH}/)
SET (CMAKE_OBJECT_OUTPUT_DIRECTORY              ${CMAKE_OBJECT_OUTPUT_DIRECTORY}${MK_PLATFORM_PATH}/)


# Platform Flavors - Specifically for Windows

SET (MK_PLATFORM_FLAVOUR_NAME                   "")

IF (MK_PLATFORM__WIN OR MK_PLATFORM__WIN_UWP)
    SET (CMAKE_SYSTEM_VERSION                       "10.0.14393.0")
    SET (APP_TYPE                                   "WIN32")

    SET (CMAKE_C_STANDARD_LIBRARIES                 "${CMAKE_C_STANDARD_LIBRARIES} UUID.LIB KERNEL32.LIB")
    SET (CMAKE_C_STANDARD_LIBRARIES_DEBUG           "${CMAKE_C_STANDARD_LIBRARIES} LIBCMTD.LIB LIBCPMTD.LIB LIBUCRTD.LIB LIBVCRUNTIMED.LIB MSVCRTD.LIB")
    SET (CMAKE_C_STANDARD_LIBRARIES_RELEASE         "${CMAKE_C_STANDARD_LIBRARIES} LIBCMT.LIB LIBCPMT.LIB LIBUCRT.LIB LIBVCRUNTIME.LIB MSVCRT.LIB")
    SET (CMAKE_C_STANDARD_LIBRARIES_FINAL           "${CMAKE_C_STANDARD_LIBRARIES} LIBCMT.LIB LIBCPMT.LIB LIBUCRT.LIB LIBVCRUNTIME.LIB MSVCRT.LIB")
    SET (CMAKE_C_STANDARD_LIBRARIES_TOOLS           "${CMAKE_C_STANDARD_LIBRARIES} LIBCMT.LIB LIBCPMT.LIB LIBUCRT.LIB LIBVCRUNTIME.LIB MSVCRT.LIB")
    
    SET (CMAKE_CXX_STANDARD_LIBRARIES               "${CMAKE_CXX_STANDARD_LIBRARIES} UUID.LIB KERNEL32.LIB")
    SET (CMAKE_CXX_STANDARD_LIBRARIES_DEBUG         "${CMAKE_CXX_STANDARD_LIBRARIES} LIBCMTD.LIB LIBCPMTD.LIB LIBUCRTD.LIB LIBVCRUNTIMED.LIB MSVCRTD.LIB")
    SET (CMAKE_CXX_STANDARD_LIBRARIES_RELEASE       "${CMAKE_CXX_STANDARD_LIBRARIES} LIBCMT.LIB LIBCPMT.LIB LIBUCRT.LIB LIBVCRUNTIME.LIB MSVCRT.LIB")
    SET (CMAKE_CXX_STANDARD_LIBRARIES_FINAL         "${CMAKE_CXX_STANDARD_LIBRARIES} LIBCMT.LIB LIBCPMT.LIB LIBUCRT.LIB LIBVCRUNTIME.LIB MSVCRT.LIB")
    SET (CMAKE_CXX_STANDARD_LIBRARIES_TOOLS         "${CMAKE_CXX_STANDARD_LIBRARIES} LIBCMT.LIB LIBCPMT.LIB LIBUCRT.LIB LIBVCRUNTIME.LIB MSVCRT.LIB")

    IF (MK_PLATFORM__WIN_UWP)
        SET (MK_PLATFORM_FLAVOUR_NAME                   "NEUTRAL")
        SET (CMAKE_C_STANDARD_LIBRARIES                 "${CMAKE_C_STANDARD_LIBRARIES} WindowsApp.lib")
        SET (CMAKE_CXX_STANDARD_LIBRARIES               "${CMAKE_CXX_STANDARD_LIBRARIES} WindowsApp.lib")
        
    ELSEIF (MK_COMPILE_HW__X86_32)
        SET (MK_PLATFORM_FLAVOUR_NAME                   "W32")

    ELSEIF (MK_COMPILE_HW__X86_64)
        SET (MK_PLATFORM_FLAVOUR_NAME                   "W64")

    ELSE ()
        MESSAGE(FATAL_ERROR "UNKNOWN WINDOWS PLATFORM")

    ENDIF ()
    
    SET (MK_PROJECT_NAME                            "${MK_PROJECT_NAME} [${MK_PLATFORM_FLAVOUR_NAME}]")

    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_PLATFORM_FLAVOUR__${MK_PLATFORM_FLAVOUR_NAME}")
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_PLATFORM_FLAVOUR=${MK_PLATFORM_FLAVOUR_NAME}")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_PLATFORM_FLAVOUR__${MK_PLATFORM_FLAVOUR_NAME}")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_PLATFORM_FLAVOUR=${MK_PLATFORM_FLAVOUR_NAME}")
    
    STRING( TOLOWER ${MK_PLATFORM_FLAVOUR_NAME}     MK_PLATFORM_FLAVOUR_PATH )
    SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY             ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}${MK_PLATFORM_FLAVOUR_PATH}/)
    SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY             ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}${MK_PLATFORM_FLAVOUR_PATH}/)
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY             ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}${MK_PLATFORM_FLAVOUR_PATH}/)
    SET (CMAKE_OBJECT_OUTPUT_DIRECTORY              ${CMAKE_OBJECT_OUTPUT_DIRECTORY}${MK_PLATFORM_FLAVOUR_PATH}/)

ENDIF ()

IF (MK_COMPILER_FLAVOUR__MSVC_MSVC)
    IF (MK_PLATFORM__WIN_UWP)
        SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} /ZW /EHsc /D\"_HAS_EXCEPTIONS=1\" ")
        SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} /D\"_HAS_EXCEPTIONS=0\"")
    ELSEIF (MK_PLATFORM__WIN)
        SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} /D\"_HAS_EXCEPTIONS=0\" ")
        SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} /D\"_HAS_EXCEPTIONS=0\"")
    ENDIF ()
ENDIF ()




# ========================================================================================================================================================================================================
#  Compiler Flags for Features / Modules
# ========================================================================================================================================================================================================

MARK_AS_ADVANCED(                               CMAKE_INSTALL_PREFIX )

IF (MK_COMPILE_PLATFORM_TEXT__WIDE)
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_PLATFORM_TEXT__WIDE")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_PLATFORM_TEXT__WIDE")
    
ELSEIF (MK_COMPILE_PLATFORM_TEXT__ANSI)
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_PLATFORM_TEXT__ANSI")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_PLATFORM_TEXT__ANSI")
    
ELSE ()
    MESSAGE(FATAL_ERROR "UNKNOWN PLATFORM TEXT TYPE")

ENDIF ()



SET (MK_FEATURE_GPU_NAME                        "")

IF (MK_FEATURE_GPU__DX12)
    SET (MK_FEATURE_GPU_NAME                        DX12)
ELSEIF (MK_FEATURE_GPU__OGL)
    SET (MK_FEATURE_GPU_NAME                        OGL)
ELSEIF (MK_FEATURE_GPU__OGLES)
    SET (MK_FEATURE_GPU_NAME                        OGLES)
ELSEIF (MK_FEATURE_GPU__METAL)
    SET (MK_FEATURE_GPU_NAME                        METAL)
ELSEIF (MK_FEATURE_GPU__VULKAN)
    SET (MK_FEATURE_GPU_NAME                        VULKAN)
ELSEIF (MK_FEATURE_GPU__NONE)
    SET (MK_FEATURE_GPU_NAME                        NONE)
ELSE ()
    MESSAGE(FATAL_ERROR "UNSUPPORTED GPU FEATURE")
ENDIF ()

SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgFEATURE_GPU__${MK_FEATURE_GPU_NAME}")
SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgFEATURE_GPU=${MK_FEATURE_GPU_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgFEATURE_GPU__${MK_FEATURE_GPU_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgFEATURE_GPU=${MK_FEATURE_GPU_NAME}")

IF (NOT MK_FEATURE_GPU__NONE)
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_GPU_SUPPORT")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_GPU_SUPPORT")
ENDIF ()



SET (MK_FEATURE_AUDIO_NAME                      "")

IF (MK_FEATURE_AUDIO__XAUDIO2)
    SET (MK_FEATURE_AUDIO_NAME                      "XAUDIO2")
ELSEIF (MK_FEATURE_AUDIO__NONE)
    SET (MK_FEATURE_AUDIO_NAME                      "NONE")
ELSE ()
    MESSAGE(FATAL_ERROR "UNSUPPORTED AUDIO FEATURE")
ENDIF ()

SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgFEATURE_AUDIO__${MK_FEATURE_AUDIO_NAME}")
SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgFEATURE_AUDIO=${MK_FEATURE_AUDIO_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgFEATURE_AUDIO__${MK_FEATURE_AUDIO_NAME}")
SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgFEATURE_AUDIO=${MK_FEATURE_AUDIO_NAME}")

IF (NOT MK_FEATURE_AUDIO__NONE)
    SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} -DTgCOMPILE_AUDIO_SUPPORT")
    SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} -DTgCOMPILE_AUDIO_SUPPORT")
ENDIF ()




# ========================================================================================================================================================================================================
# Build does not support Configurations
# ========================================================================================================================================================================================================

# If Generator does not support multiple configurations, collapse the flags

IF (MK_IDE__UNIX_MAKEFILES)
    IF (CONFIGURATION_TYPE_DEBUG)
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG}")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
    ELSEIF (CONFIGURATION_TYPE_RELEASE)
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE}")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
    ELSEIF (CONFIGURATION_TYPE_FINAL)
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_FINAL}")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_FINAL}")
    ELSEIF (CONFIGURATION_TYPE_TOOLS)
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_TOOLS}")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_TOOLS}")
    ELSE ()
        MESSAGE(FATAL_ERROR "Unknown Makefile Build Configuration")
    ENDIF ()

ENDIF ()




# ========================================================================================================================================================================================================
# Validation and Reporting
# ========================================================================================================================================================================================================

# Validate project name

IF (NOT ${__CMAKE_PROJECT_NAME} STREQUAL ${MK_PROJECT_NAME})
    MESSAGE("Solution name has changed - remake the cmake project directory.")
    MESSAGE("[${MK_PROJECT_NAME}] vs [${__CMAKE_PROJECT_NAME}]")
    MESSAGE(FATAL_ERROR "Terminating Execution")
ENDIF ()




# ========================================================================================================================================================================================================
#  Function: TGS_SET_STANDARD_PROPERTIES
# ========================================================================================================================================================================================================

FUNCTION (TGS_SET_STANDARD_PROPERTIES TARGET PCH_SOURCE_DIR PCH_SOURCE PCH_INCLUDE SOURCE_FILES HEADER_FILES)

    # Add standard include paths
    TARGET_INCLUDE_DIRECTORIES(${TARGET}            BEFORE PRIVATE "${PCH_SOURCE_DIR}")
    TARGET_INCLUDE_DIRECTORIES(${TARGET}            BEFORE PRIVATE "${PROJECT_SOURCE_DIR}/../inc")

    # Setup the source control values (Keep them SAKed so that source control is done through the solution file)
    # SET_TARGET_PROPERTIES (${TARGET}                PROPERTIES VS_SCC_PROJECTNAME "Perforce Project")
    # SET_TARGET_PROPERTIES (${TARGET}                PROPERTIES VS_SCC_LOCALPATH "..\\..\\..")
    # SET_TARGET_PROPERTIES (${TARGET}                PROPERTIES VS_SCC_PROVIDER "MSSCCI:Perforce SCM")



    # -- COMPILER SETTINGS ----

    # Enable LTCG for final and tool builds
    SET_TARGET_PROPERTIES (${TARGET}                PROPERTIES LTCG_GLOBAL_OPT_FINAL 1)
    SET_TARGET_PROPERTIES (${TARGET}                PROPERTIES LTCG_GLOBAL_OPT_TOOLS 1)

    IF (MK_COMPILER_FLAVOUR__MSVC_MSVC)

        SET_TARGET_PROPERTIES(${TARGET}                 PROPERTIES DISABLE_LANGUAGE_EXTENSIONS 1)

        # Custom properties used in our version of CMake to set the intermediate directory and the global ltcg setting
        SET_TARGET_PROPERTIES (${TARGET}                PROPERTIES OBJECT_OUTPUT_DIRECTORY ${CMAKE_OBJECT_OUTPUT_DIRECTORY})

        # Custom properties used in our version of CMake to set the intermediate directory and the global ltcg setting
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " /DEBUG ")
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " /NODEFAULTLIB ")
        TGS_ADD_LIB_FLAGS(${TARGET}                     " /NODEFAULTLIB ")

        TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE "/MP ")
        TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE "-DTgCOMPILE_DEFAULT_PCH=\"${PCH_INCLUDE}\" ")

        # Setup flags on the target to create and use the precompiled header.
        TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE "/FI\"${PCH_INCLUDE}\" ")
        TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE "/Yu${PCH_INCLUDE} ")

        SET (CMAKE_C_FLAGS                              "${CMAKE_C_FLAGS} /Fp\"$(IntDir)$(TargetName)_C.pch\" ")
        TGS_ADD_PRECOMPILED_HEADER("${PCH_SOURCE_DIR}/${PCH_SOURCE}.c" "C" ${PCH_INCLUDE})

        SET (CMAKE_CXX_FLAGS                            "${CMAKE_CXX_FLAGS} /Fp\"$(IntDir)$(TargetName)_CXX.pch\" ")
        TGS_ADD_CXX_PRECOMPILED_HEADER("${PCH_SOURCE_DIR}/${PCH_SOURCE}.cpp" "CXX" ${PCH_INCLUDE})
    ENDIF ()

    IF (MK_COMPILER_FLAVOUR__MSVC_CLANG)
        # Clang-CL syntax - seems the VS integration does not have a clean way to flip to regular clang syntax
        TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE "-DTgCOMPILE_DEFAULT_PCH=\"${PCH_INCLUDE}\" ")

        # Setup flags on the target to create and use the precompiled header.
        TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE "/FI\"${PCH_INCLUDE}\" ")
    ENDIF ()

    IF (MK_COMPILER_FLAVOUR__CLANG_LLVM OR MK_COMPILER_FLAVOUR__CLANG_APPLE)
        # Clang-CL syntax - seems the VS integration does not have a clean way to flip to regular clang syntax
        TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE -DTgCOMPILE_DEFAULT_PCH="${PCH_INCLUDE}")

        # Setup flags on the target to create and use the precompiled header.
        TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE -include "${PCH_INCLUDE}")
    ENDIF ()



    # -- PLATFORM SETTINGS ----

    IF (MK_PLATFORM__WIN AND NOT MK_PLATFORM__WIN_UWP)
        SET_TARGET_PROPERTIES( ${TARGET}                PROPERTIES WIN32 1)

        IF (MK_COMPILER_FLAVOUR__MSVC_MSVC)
            TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE "/MT$<$<CONFIG:Debug>:d>")
        ENDIF ()
    ENDIF ()

    # UWP Configuration
    IF (MK_PLATFORM__WIN_UWP)
        SET_TARGET_PROPERTIES(${TARGET}                 PROPERTIES USE_DEBUG_LIB_DEBUG 1)
        SET_TARGET_PROPERTIES(${TARGET}                 PROPERTIES USE_DOT_NET_NATIVE_RELEASE 1)
        SET_TARGET_PROPERTIES(${TARGET}                 PROPERTIES USE_DOT_NET_NATIVE_FINAL 1)

        # Extensions
        SET_TARGET_PROPERTIES(${TARGET}                 PROPERTIES VS_DESKTOP_EXTENSIONS_VERSION "10.0.14393.0" )

        # Code Generation Runtime Library
        IF (MK_COMPILER__MSVC)
            TARGET_COMPILE_OPTIONS(${TARGET}                PRIVATE "/MD$<$<CONFIG:Debug>:d>")
            TGS_ADD_LINKER_FLAGS(${TARGET}                  " /NODEFAULTLIB:vccorlibd ")
            TGS_ADD_LINKER_FLAGS(${TARGET}                  " /NODEFAULTLIB:msvcrtd ")
            TGS_ADD_LINKER_FLAGS(${TARGET}                  " vccorlibd.lib ")
            TGS_ADD_LINKER_FLAGS(${TARGET}                  " msvcrtd.lib ")
        ENDIF ()
    ENDIF ()

    IF (MK_PLATFORM__MAC)
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " -framework AudioToolbox ")
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " -framework CoreGraphics ")
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " -framework QuartzCore ")
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " -framework UIKit ")
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " -framework Foundation ")

    ENDIF ()

ENDFUNCTION (TGS_SET_STANDARD_PROPERTIES)




# ========================================================================================================================================================================================================
#  Function: TGS_SET_STANDARD_EXECUTABLE
# ========================================================================================================================================================================================================

FUNCTION (TGS_ADD_STANDARD_EXECUTABLE TARGET PCH_SOURCE_DIR PCH_SOURCE PCH_INCLUDE SOURCE_FILES HEADER_FILES)

    ADD_EXECUTABLE (${TARGET}                       ${APP_TYPE} ${SOURCE_FILES})

    #SET_TARGET_PROPERTIES (${TARGET}                PROPERTIES XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer: Andrew Aye")
    TGS_SET_STANDARD_PROPERTIES ( ${TARGET}         ${PCH_SOURCE_DIR} ${PCH_SOURCE} ${PCH_INCLUDE} ${SOURCE_FILES} ${HEADER_FILES})

ENDFUNCTION (TGS_ADD_STANDARD_EXECUTABLE)




# ========================================================================================================================================================================================================
#  Function: TGS_ADD_UNITTEST_EXECUTABLE
# ========================================================================================================================================================================================================

FUNCTION (TGS_ADD_UNITTEST_EXECUTABLE TARGET PCH_SOURCE_DIR PCH_SOURCE PCH_INCLUDE SOURCE_FILES HEADER_FILES)

    # Include the UWP standard runtime files
    IF (MK_PLATFORM__WIN_UWP)
        SET (SOURCE_FILES ${SOURCE_FILES} "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.xaml.cpp")
        SOURCE_GROUP ("Resource Files" FILES "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.xaml.cpp")
        SET (SOURCE_FILES ${SOURCE_FILES} "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.xaml")
        SOURCE_GROUP ("Resource Files" FILES "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.xaml")
        SET_SOURCE_FILES_PROPERTIES("${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.xaml" PROPERTIES VS_XAML_TYPE "ApplicationDefinition" )

        IF (INCLUDE_NON_SOURCE_FILES)
            SET (SOURCE_FILES ${SOURCE_FILES} "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.xaml.h")
            SOURCE_GROUP ("Resource Files" FILES "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.xaml.h")
            SET (SOURCE_FILES ${SOURCE_FILES} "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/pch.h")
            SOURCE_GROUP ("Resource Files" FILES "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/pch.h")
            SET (SOURCE_FILES ${SOURCE_FILES} "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.rd.xml")
            SOURCE_GROUP ("Resource Files" FILES "${PROJECT_SOURCE_DIR}/../src/TgS UNIT TEST/UnitTestApp.rd.xml")
        ENDIF (INCLUDE_NON_SOURCE_FILES)
    ENDIF ()


    ADD_EXECUTABLE (${TARGET}                       ${APP_TYPE} ${SOURCE_FILES} ${HEADER_FILES})

    # Add Unit Test paths for compilation
    TARGET_INCLUDE_DIRECTORIES(${TARGET}            PRIVATE "${PROJECT_SOURCE_DIR}/../tst/src/TgS UNIT TEST")
    TARGET_INCLUDE_DIRECTORIES(${TARGET}            PRIVATE "${PROJECT_SOURCE_DIR}/../tst/inc")
    IF (MK_PLATFORM__WIN_UWP)
        TARGET_INCLUDE_DIRECTORIES(${TARGET}            PRIVATE "$(VCInstallDir)UnitTest/include/UWP")
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " /LIBPATH:\"$(VCInstallDir)UnitTest/lib/UWP\" ")
    ELSEIF (MK_PLATFORM__WIN)
        TGS_ADD_LINKER_FLAGS(${TARGET}                  " /LIBPATH:\"$(VCInstallDir)UnitTest/lib/W64\" ")
    ENDIF ()

    # Set UWP Unit Test configuration / references
    IF (MK_PLATFORM__WIN_UWP)
        SET_TARGET_PROPERTIES(${TARGET}                 PROPERTIES VS_CPPUNITTESTFRAMEWORK_EXTENSIONS_VERSION "14.0" )
        SET_TARGET_PROPERTIES(${TARGET}                 PROPERTIES VS_TESTPLATFORM_EXTENSIONS_VERSION "14.0" )
        SET_TARGET_PROPERTIES(${TARGET}                 PROPERTIES UWP_APPLICATION_ID "vstest.executionengine.universal.App")
    ENDIF ()

    # SET_TARGET_PROPERTIES (${TARGET}                PROPERTIES XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "Sign to Run Locally")
    TGS_SET_STANDARD_PROPERTIES ( ${TARGET}         ${PCH_SOURCE_DIR} ${PCH_SOURCE} ${PCH_INCLUDE} ${SOURCE_FILES} ${HEADER_FILES})

ENDFUNCTION (TGS_ADD_UNITTEST_EXECUTABLE)




# ========================================================================================================================================================================================================
# ========================================================================================================================================================================================================
