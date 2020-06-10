CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
CMAKE_POLICY(VERSION 3.17)


# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
# SETUP

MESSAGE("")
MESSAGE("")
MESSAGE("DEBUG PROJECT NAME: ${_CMAKE_PROJECT_NAME} / ${MK_PROJECT_NAME}")
MESSAGE("")
MESSAGE("PROJECT IDE: ${MK_IDE_NAME}")
IF ("${MK_COMPILER_FLAVOUR_NAME}" STREQUAL "")
    MESSAGE("COMPILER: ${MK_COMPILER_FLAVOUR_NAME}")
ELSE ()
    MESSAGE("COMPILER: ${MK_COMPILER_NAME}")
ENDIF ()
MESSAGE("HARDWARE: ${MK_HARDWARE_NAME}")
MESSAGE("PLATFORM: ${MK_PLATFORM_NAME}")
IF (MK_COMPILE_PLATFORM_TEXT__WIDE)
    MESSAGE("PLATFORM TEXT: WIDE")
ELSE ()
    MESSAGE("PLATFORM TEXT: ANSI")
ENDIF ()
MESSAGE("FEATURE (GPU): ${MK_FEATURE_GPU_NAME}")
MESSAGE("FEATURE (AUDIO): ${MK_FEATURE_AUDIO_NAME}")
MESSAGE("")
MESSAGE("")



# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ #
# COMPILE FLAGS

MESSAGE(VERBOSE "COMPILE FLAGS (C): ${CMAKE_C_FLAGS}")
MESSAGE(VERBOSE "")
MESSAGE(VERBOSE "")
MESSAGE(VERBOSE "COMPILE FLAGS (C++): ${CMAKE_CXX_FLAGS}")
MESSAGE(VERBOSE "")
MESSAGE(VERBOSE "")
