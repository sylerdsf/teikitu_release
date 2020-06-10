# ========================================================================================================================================================================================================
# Clear out all the default flags - if I don't SET it up, it should not be SET
# ========================================================================================================================================================================================================

SET (CMAKE_C_FLAGS_INIT                         "")
SET (CMAKE_C_FLAGS_DEBUG_INIT                   "")
SET (CMAKE_C_FLAGS_RELEASE_INIT                 "")
SET (CMAKE_C_FLAGS_FINAL_INIT                   "")
SET (CMAKE_C_FLAGS_TOOLS_INIT                   "")
SET (CMAKE_C_FLAGS_MINSIZEREL                   "")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO               "")
SET (CMAKE_C_STANDARD_LIBRARIES_INIT            "")

SET (CMAKE_CXX_FLAGS_INIT                       "")
SET (CMAKE_CXX_FLAGS_DEBUG_INIT                 "")
SET (CMAKE_CXX_FLAGS_RELEASE_INIT               "")
SET (CMAKE_CXX_FLAGS_FINAL_INIT                 "")
SET (CMAKE_CXX_FLAGS_TOOLS_INIT                 "")
SET (CMAKE_CXX_FLAGS_MINSIZEREL                 "")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO             "")
SET (CMAKE_CXX_STANDARD_LIBRARIES_INIT          "")

SET (CMAKE_EXE_LINKER_FLAGS_INIT                "")
SET (CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT          "")
SET (CMAKE_EXE_LINKER_FLAGS_RELEASE_INIT        "")
SET (CMAKE_EXE_LINKER_FLAGS_FINAL_INIT          "")
SET (CMAKE_EXE_LINKER_FLAGS_TOOLS_INIT          "")
SET (CMAKE_EXE_LINKER_FLAGS_MINSIZEREL          "")
SET (CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO      "")

SET (CMAKE_STATIC_LINKER_FLAGS_INIT             "")
SET (CMAKE_STATIC_LINKER_FLAGS_DEBUG_INIT       "")
SET (CMAKE_STATIC_LINKER_FLAGS_RELEASE_INIT     "")
SET (CMAKE_STATIC_LINKER_FLAGS_FINAL_INIT       "")
SET (CMAKE_STATIC_LINKER_FLAGS_TOOLS_INIT       "")
SET (CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL       "")
SET (CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO   "")

SET (CMAKE_MODULE_LINKER_FLAGS_INIT             "")
SET (CMAKE_MODULE_LINKER_FLAGS_DEBUG_INIT       "")
SET (CMAKE_MODULE_LINKER_FLAGS_RELEASE_INIT     "")
SET (CMAKE_MODULE_LINKER_FLAGS_FINAL_INIT       "")
SET (CMAKE_MODULE_LINKER_FLAGS_TOOLS_INIT       "")
SET (CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL       "")
SET (CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO   "")

SET (CMAKE_SHARED_LINKER_FLAGS_INIT             "")
SET (CMAKE_SHARED_LINKER_FLAGS_DEBUG_INIT       "")
SET (CMAKE_SHARED_LINKER_FLAGS_RELEASE_INIT     "")
SET (CMAKE_SHARED_LINKER_FLAGS_FINAL_INIT       "")
SET (CMAKE_SHARED_LINKER_FLAGS_TOOLS_INIT       "")
SET (CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL       "")
SET (CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO   "")

# Mark the new configurations as advanced

MARK_AS_ADVANCED( CMAKE_C_FLAGS_FINAL_INIT )
MARK_AS_ADVANCED( CMAKE_CXX_FLAGS_FINAL_INIT )
MARK_AS_ADVANCED( CMAKE_EXE_LINKER_FLAGS_FINAL_INIT )
MARK_AS_ADVANCED( CMAKE_STATIC_LINKER_FLAGS_FINAL_INIT )
MARK_AS_ADVANCED( CMAKE_MODULE_LINKER_FLAGS_FINAL_INIT )
MARK_AS_ADVANCED( CMAKE_SHARED_LINKER_FLAGS_FINAL_INIT )

MARK_AS_ADVANCED( CMAKE_C_FLAGS_TOOLS_INIT )
MARK_AS_ADVANCED( CMAKE_CXX_FLAGS_TOOLS_INIT )
MARK_AS_ADVANCED( CMAKE_EXE_LINKER_FLAGS_TOOLS_INIT )
MARK_AS_ADVANCED( CMAKE_STATIC_LINKER_FLAGS_TOOLS_INIT )
MARK_AS_ADVANCED( CMAKE_MODULE_LINKER_FLAGS_TOOLS_INIT )
MARK_AS_ADVANCED( CMAKE_SHARED_LINKER_FLAGS_TOOLS_INIT )




# ========================================================================================================================================================================================================
#  Setting IDE
# ========================================================================================================================================================================================================

SET (__CMAKE_IDE_MSVC                           0 )
SET (__CMAKE_IDE_XCODE                          0 )
SET (__CMAKE_IDE_UNIX_MAKEFILES                 0 )

IF (${CMAKE_GENERATOR} MATCHES "Visual Studio")
    SET (__CMAKE_IDE_MSVC                           1 )
ELSEIF (${CMAKE_GENERATOR} MATCHES "Xcode")
    SET (__CMAKE_IDE_XCODE                          1 )
ELSEIF (${CMAKE_GENERATOR} MATCHES "Unix Makefiles")
    SET (__CMAKE_IDE_UNIX_MAKEFILES                 1 )
ELSE()
    MESSAGE(FATAL_ERROR "UNKNOWN IDE: " ${CMAKE_GENERATOR})
ENDIF ()




# ========================================================================================================================================================================================================
#  Setting Compiler
# ========================================================================================================================================================================================================

SET (__CMAKE_C_COMPILER__CLANG                  0 )
SET (__CMAKE_C_COMPILER_FLAVOR__CLANG_LLVM      0 )
SET (__CMAKE_C_COMPILER_FLAVOR__CLANG_APPLE     0 )
SET (__CMAKE_C_COMPILER__MSVC                   0 )
SET (__CMAKE_C_COMPILER_FLAVOR__MSVC_MSVC       0 )
SET (__CMAKE_C_COMPILER_FLAVOR__MSVC_CLANG      0 )
SET (__CMAKE_C_COMPILER__ICL                    0 )
SET (__CMAKE_C_COMPILER__GCC                    0 )

IF (DEFINED CMAKE_C_COMPILER_ID)
    IF (${CMAKE_C_COMPILER_ID} MATCHES "AppleClang")
        SET (__CMAKE_C_COMPILER__CLANG                  1 )
        SET (__CMAKE_C_COMPILER_FLAVOUR__CLANG_APPLE    1 )
    ELSEIF (${CMAKE_C_COMPILER_ID} MATCHES "Clang")
        SET (__CMAKE_C_COMPILER__CLANG                  1 )
        SET (__CMAKE_C_COMPILER_FLAVOUR__CLANG_LLVM     1 )
    ELSEIF (${CMAKE_C_COMPILER_ID} MATCHES "MSVC")
        SET (__CMAKE_C_COMPILER__MSVC                   1 )
        IF (${CMAKE_VS_PLATFORM_TOOLSET} MATCHES "_clang_")
            # WORK IN PROGRESS
            SET (__CMAKE_C_COMPILER_FLAVOUR__MSVC_CLANG     1 )
        ELSE()
            SET (__CMAKE_C_COMPILER_FLAVOUR__MSVC_MSVC      1 )
        ENDIF ()
    ELSE()
        MESSAGE(FATAL_ERROR "UNSUPPORTED C COMPILER: " ${CMAKE_C_COMPILER_ID})
    ENDIF ()
ENDIF ()



SET (__CMAKE_CXX_COMPILER__CLANG                0 )
SET (__CMAKE_CXX_COMPILER_FLAVOR__CLANG_LLVM    0 )
SET (__CMAKE_CXX_COMPILER_FLAVOR__CLANG_APPLE   0 )
SET (__CMAKE_CXX_COMPILER__MSVC                 0 )
SET (__CMAKE_CXX_COMPILER_FLAVOR__MSVC_MSVC     0 )
SET (__CMAKE_CXX_COMPILER_FLAVOR__MSVC_CLANG    0 )
SET (__CMAKE_CXX_COMPILER__ICL                  0 )
SET (__CMAKE_CXX_COMPILER__GCC                  0 )

IF (DEFINED CMAKE_CXX_COMPILER_ID)
    IF (${CMAKE_CXX_COMPILER_ID} MATCHES "AppleClang")
        SET (__CMAKE_CXX_COMPILER__CLANG                1 )
        SET (__CMAKE_CXX_COMPILER_FLAVOUR__CLANG_APPLE  1 )
    ELSEIF (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
        SET (__CMAKE_CXX_COMPILER__CLANG                1 )
        SET (__CMAKE_CXX_COMPILER_FLAVOUR__CLANG_LLVM   1 )
    ELSEIF (${CMAKE_CXX_COMPILER_ID} MATCHES "MSVC")
        SET (__CMAKE_CXX_COMPILER__MSVC                 1 )
        IF (${CMAKE_VS_PLATFORM_TOOLSET} MATCHES "_clang_")
            # WORK IN PROGRESS
            SET (__CMAKE_CXX_COMPILER_FLAVOUR__MSVC_CLANG   1 )
        ELSE()
            SET (__CMAKE_CXX_COMPILER_FLAVOUR__MSVC_MSVC    1 )
        ENDIF ()
    ELSE()
        MESSAGE(FATAL_ERROR "UNSUPPORTED C COMPILER: " ${CMAKE_CXX_COMPILER_ID})
    ENDIF ()
ENDIF ()



IF (DEFINED CMAKE_C_COMPILER_ID AND DEFINED CMAKE_CXX_COMPILER_ID)
    IF (NOT __CMAKE_C_COMPILER__CLANG EQUAL __CMAKE_CXX_COMPILER__CLANG)
        MESSAGE(FATAL_ERROR "MISMATCHED C AND CXX COMPILERS: " ${CMAKE_C_COMPILER_ID} ", " ${CMAKE_CXX_COMPILER_ID})
    ENDIF ()
    IF (NOT __CMAKE_C_COMPILER__MSVC EQUAL __CMAKE_CXX_COMPILER__MSVC)
        MESSAGE(FATAL_ERROR "MISMATCHED C AND CXX COMPILERS: " ${CMAKE_C_COMPILER_ID} ", " ${CMAKE_CXX_COMPILER_ID})
    ENDIF ()
    IF (NOT __CMAKE_C_COMPILER__ICL EQUAL __CMAKE_CXX_COMPILER__ICL)
        MESSAGE(FATAL_ERROR "MISMATCHED C AND CXX COMPILERS: " ${CMAKE_C_COMPILER_ID} ", " ${CMAKE_CXX_COMPILER_ID})
    ENDIF ()
    IF (NOT __CMAKE_C_COMPILER__GCC EQUAL __CMAKE_CXX_COMPILER__GCC)
        MESSAGE(FATAL_ERROR "MISMATCHED C AND CXX COMPILERS: " ${CMAKE_C_COMPILER_ID} ", " ${CMAKE_CXX_COMPILER_ID})
    ENDIF ()
ENDIF ()




# ========================================================================================================================================================================================================
#  Compilation Configuration
# ========================================================================================================================================================================================================

IF (__CMAKE_C_COMPILER__MSVC)
    SET (CMAKE_C_FLAGS_INIT                         "${CMAKE_C_FLAGS_INIT} /nologo /Wall /WX /Gy- /Gv /arch:AVX /fp:precise /fp:except- /Zc:wchar_t /Zc:forScope /GR- /GF /Oi /Ot")
    SET (CMAKE_C_FLAGS_DEBUG_INIT                   "${CMAKE_C_FLAGS_DEBUG_INIT} /MTd /Od /RTCc /GS")
    SET (CMAKE_C_FLAGS_RELEASE_INIT                 "${CMAKE_C_FLAGS_RELEASE_INIT} /MT /Ox /GS-")
    SET (CMAKE_C_FLAGS_FINAL_INIT                   "${CMAKE_C_FLAGS_FINAL_INIT} /MT /Ox /GS-")
    SET (CMAKE_C_FLAGS_TOOLS_INIT                   "${CMAKE_C_FLAGS_TOOLS_INIT} /MT /Ox /GS-")
    SET (CMAKE_EXE_LINKER_FLAGS_FINAL_INIT          "${CMAKE_EXE_LINKER_FLAGS_FINAL_INIT} /INCREMENTAL:NO")

    IF (__CMAKE_C_COMPILER_FLAVOUR__MSVC_MSVC)
        SET (CMAKE_C_FLAGS_INIT                         "${CMAKE_C_FLAGS_INIT} /Ob2 /GT /Gm- /openmp- /Qpar-")
        SET (CMAKE_C_FLAGS_DEBUG_INIT                   "${CMAKE_C_FLAGS_DEBUG_INIT} /RTC1")
    ENDIF ()
    
ELSEIF (__CMAKE_C_COMPILER__CLANG)
    SET (CMAKE_C_FLAGS_INIT                         "${CMAKE_C_FLAGS_INIT} -Weverything -fstack-protector -fstrict-aliasing -ffunction-sections -g2 -gdwarf-2 -O0")
    SET (CMAKE_C_FLAGS_INIT                         "${CMAKE_C_FLAGS_INIT} -fomit-frame-pointer -fdata-sections -fno-ms-compatibility -fno-short-enums -fno-exceptions")
    SET (CMAKE_C_FLAGS_INIT                         "${CMAKE_C_FLAGS_INIT} -std=c11 -fno-ms-extensions -fno-rtti -march=native -Wall")
    
ENDIF ()



IF (__CMAKE_CXX_COMPILER__MSVC)
    SET (CMAKE_CXX_FLAGS_INIT                       "${CMAKE_CXX_FLAGS_INIT} /nologo /Wall /WX /Gy- /Gv /arch:AVX /fp:precise /fp:except- /Zc:wchar_t /Zc:forScope /GR- /GF /Oi /Ot")
    SET (CMAKE_CXX_FLAGS_DEBUG_INIT                 "${CMAKE_CXX_FLAGS_DEBUG_INIT} /MTd /Od /RTCc /GS")
    SET (CMAKE_CXX_FLAGS_RELEASE_INIT               "${CMAKE_CXX_FLAGS_RELEASE_INIT} /MT /Ox /GS-")
    SET (CMAKE_CXX_FLAGS_FINAL_INIT                 "${CMAKE_CXX_FLAGS_FINAL_INIT} /MT /Ox /GS-")
    SET (CMAKE_CXX_FLAGS_TOOLS_INIT                 "${CMAKE_CXX_FLAGS_TOOLS_INIT} /MT /Ox /GS-")
    SET (CMAKE_EXE_LINKER_FLAGS_TOOLS_INIT          "${CMAKE_EXE_LINKER_FLAGS_TOOLS_INIT} /INCREMENTAL:NO")
    IF (__CMAKE_CXX_COMPILER_FLAVOUR__MSVC_MSVC)
        SET (CMAKE_CXX_FLAGS_INIT                       "${CMAKE_CXX_FLAGS_INIT} /Ob2 /GT /Gm- /openmp- /Qpar-")
        SET (CMAKE_CXX_FLAGS_DEBUG_INIT                 "${CMAKE_CXX_FLAGS_DEBUG_INIT} /RTC1")
    ENDIF ()

ELSEIF (__CMAKE_CXX_COMPILER__CLANG)
    SET (CMAKE_CXX_FLAGS_INIT                       "${CMAKE_CXX_FLAGS_INIT} -Weverything -fstack-protector -fstrict-aliasing -ffunction-sections -g2 -gdwarf-2 -O0")
    SET (CMAKE_CXX_FLAGS_INIT                       "${CMAKE_CXX_FLAGS_INIT} -fomit-frame-pointer -fdata-sections -fno-ms-compatibility -fno-short-enums -fno-exceptions")
    SET (CMAKE_CXX_FLAGS_INIT                       "${CMAKE_CXX_FLAGS_INIT} -std=c++1y -fno-ms-extensions -fno-rtti -march=native -Wall")

ENDIF ()



SET (CMAKE_CXX_FLAGS_MINSIZEREL                 "${CMAKE_C_FLAGS_MINSIZEREL}")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO             "${CMAKE_C_FLAGS_RELWITHDEBINFO}")
SET (CMAKE_CXX_STANDARD_LIBRARIES_INIT          "${CMAKE_C_STANDARD_LIBRARIES_INIT}")

IF (DEFINED CMAKE_C_COMPILER_ID AND NOT CMAKE_C_FLAGS_INIT)
    MESSAGE(FATAL_ERROR "C Compile Flags not initialized: " ${CMAKE_C_FLAGS_INIT})
ENDIF ()

IF (DEFINED CMAKE_CXX_COMPILER_ID AND NOT CMAKE_CXX_FLAGS_INIT)
    MESSAGE(FATAL_ERROR "CXX Compile Flags not initialized.")
ENDIF ()




# ========================================================================================================================================================================================================
#  Configuration Types
# ========================================================================================================================================================================================================

IF (CMAKE_CONFIGURATION_TYPES)

    SET (CMAKE_CONFIGURATION_TYPES                  Debug Release Final Tools )
    SET (CMAKE_CONFIGURATION_TYPES                  "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "Reset the configurations to what we need" FORCE )
    SET (CMAKE_BUILD_TYPE                           "${CMAKE_BUILD_TYPE}" CACHE STRING "Choose the type of build, options are: None Debug Release Final Tools." FORCE )
    MARK_AS_ADVANCED(                               CMAKE_BUILD_TYPE )

ELSE(CMAKE_CONFIGURATION_TYPES)

    SET (CONFIGURATION_TYPE_DEBUG                   1 CACHE BOOL "")
    SET (CONFIGURATION_TYPE_RELEASE                 0 CACHE BOOL "")
    SET (CONFIGURATION_TYPE_FINAL                   0 CACHE BOOL "")
    SET (CONFIGURATION_TYPE_TOOLS                   0 CACHE BOOL "")

    IF (CONFIGURATION_TYPE_DEBUG)

        SET (CONFIGURATION_TYPE_RELEASE                 0 CACHE BOOL "" FORCE)
        SET (CONFIGURATION_TYPE_FINAL                   0 CACHE BOOL "" FORCE)
        SET (CONFIGURATION_TYPE_TOOLS                   0 CACHE BOOL "" FORCE)

    ENDIF (CONFIGURATION_TYPE_DEBUG)

    IF (CONFIGURATION_TYPE_RELEASE)

        SET (CONFIGURATION_TYPE_DEBUG                   0 CACHE BOOL "" FORCE)
        SET (CONFIGURATION_TYPE_FINAL                   0 CACHE BOOL "" FORCE)
        SET (CONFIGURATION_TYPE_TOOLS                   0 CACHE BOOL "" FORCE)

    ENDIF (CONFIGURATION_TYPE_RELEASE)

    IF (CONFIGURATION_TYPE_FINAL)

        SET (CONFIGURATION_TYPE_DEBUG                   0 CACHE BOOL "" FORCE)
        SET (CONFIGURATION_TYPE_RELEASE                 0 CACHE BOOL "" FORCE)
        SET (CONFIGURATION_TYPE_TOOLS                   0 CACHE BOOL "" FORCE)

    ENDIF (CONFIGURATION_TYPE_FINAL)

    IF (CONFIGURATION_TYPE_TOOLS)

        SET (CONFIGURATION_TYPE_DEBUG                   0 CACHE BOOL "" FORCE)
        SET (CONFIGURATION_TYPE_RELEASE                 0 CACHE BOOL "" FORCE)
        SET (CONFIGURATION_TYPE_FINAL                   0 CACHE BOOL "" FORCE)

    ENDIF (CONFIGURATION_TYPE_TOOLS)

ENDIF (CMAKE_CONFIGURATION_TYPES)




# ========================================================================================================================================================================================================
#  Final and Tools Configuration
# ========================================================================================================================================================================================================

# Setup the Final flags
SET (CMAKE_C_FLAGS_FINAL                        "${CMAKE_C_FLAGS_FINAL_INIT}"             CACHE STRING "")
SET (CMAKE_CXX_FLAGS_FINAL                      "${CMAKE_CXX_FLAGS_FINAL_INIT}"           CACHE STRING "")
SET (CMAKE_EXE_LINKER_FLAGS_FINAL               "${CMAKE_EXE_LINKER_FLAGS_FINAL_INIT}"    CACHE STRING "")
SET (CMAKE_STATIC_LINKER_FLAGS_FINAL            "${CMAKE_STATIC_LINKER_FLAGS_FINAL_INIT}" CACHE STRING "")
SET (CMAKE_MODULE_LINKER_FLAGS_FINAL            "${CMAKE_MODULE_LINKER_FLAGS_FINAL_INIT}" CACHE STRING "")
SET (CMAKE_SHARED_LINKER_FLAGS_FINAL            "${CMAKE_SHARED_LINKER_FLAGS_FINAL_INIT}" CACHE STRING "")

MARK_AS_ADVANCED(                               CMAKE_C_FLAGS_FINAL )
MARK_AS_ADVANCED(                               CMAKE_CXX_FLAGS_FINAL )
MARK_AS_ADVANCED(                               CMAKE_EXE_LINKER_FLAGS_FINAL )
MARK_AS_ADVANCED(                               CMAKE_STATIC_LINKER_FLAGS_FINAL )
MARK_AS_ADVANCED(                               CMAKE_MODULE_LINKER_FLAGS_FINAL )
MARK_AS_ADVANCED(                               CMAKE_SHARED_LINKER_FLAGS_FINAL )

# Setup the Tools flags
SET (CMAKE_C_FLAGS_TOOLS                        "${CMAKE_C_FLAGS_TOOLS_INIT}"             CACHE STRING "")
SET (CMAKE_CXX_FLAGS_TOOLS                      "${CMAKE_CXX_FLAGS_TOOLS_INIT}"           CACHE STRING "")
SET (CMAKE_EXE_LINKER_FLAGS_TOOLS               "${CMAKE_EXE_LINKER_FLAGS_TOOLS_INIT}"    CACHE STRING "")
SET (CMAKE_STATIC_LINKER_FLAGS_TOOLS            "${CMAKE_STATIC_LINKER_FLAGS_TOOLS_INIT}" CACHE STRING "")
SET (CMAKE_MODULE_LINKER_FLAGS_TOOLS            "${CMAKE_MODULE_LINKER_FLAGS_TOOLS_INIT}" CACHE STRING "")
SET (CMAKE_SHARED_LINKER_FLAGS_TOOLS            "${CMAKE_SHARED_LINKER_FLAGS_TOOLS_INIT}" CACHE STRING "")

MARK_AS_ADVANCED(                               CMAKE_C_FLAGS_TOOLS )
MARK_AS_ADVANCED(                               CMAKE_CXX_FLAGS_TOOLS )
MARK_AS_ADVANCED(                               CMAKE_EXE_LINKER_FLAGS_TOOLS )
MARK_AS_ADVANCED(                               CMAKE_STATIC_LINKER_FLAGS_TOOLS )
MARK_AS_ADVANCED(                               CMAKE_MODULE_LINKER_FLAGS_TOOLS )
MARK_AS_ADVANCED(                               CMAKE_SHARED_LINKER_FLAGS_TOOLS )
