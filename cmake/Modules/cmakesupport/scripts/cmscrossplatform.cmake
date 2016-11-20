MESSAGE( "   · Adding: cmscrossplatform macros" )


# Select only one target to compile the code, easier for cross-compiling
# Try to auto detect and set the target parameter
# ------------------------------------------------------------------------------------------------------
MACRO(CHECKCROSSPLATFORM)
  SET(TARGET_PLATFORM CACHE STRING "TARGET_NONE")
  # TODO check for general options, and toolchains
  SET_PROPERTY(CACHE TARGET_PLATFORM PROPERTY STRINGS "TARGET_NONE" "TARGET_ANDROID" "TARGET_WIN32" "TARGET_LINUX" "TARGET_IOS" "TARGET_APPLE")	# List with targets types

  PRINTTITLE("Autodetecting architecture . . .")

  IF(NOT CMAKE_TOOLCHAIN_FILE)
    PRINT("You are not using a toolchain")
    IF(WIN32)
      PRINT("Consider your target: Windows")
      SET(TARGET_PLATFORM TARGET_WIN32 CACHE STRING "Target Platform" FORCE)
    ELSEIF(APPLE)
      PRINT("Consider your target: MAC")
      SET(TARGET_PLATFORM TARGET_APPLE CACHE STRING "Target Platform" FORCE)
    ELSEIF(UNIX)
      PRINT("Consider your target: Linux")
      SET(TARGET_PLATFORM TARGET_LINUX CACHE STRING "Target Platform" FORCE)
    ELSE()
      MESSAGE(FATAL_ERROR "Unknown architecture")
    ENDIF(WIN32)
  ELSE()
    PRINT("You are using a toolchain")
    IF(APPLE)
      PRINT("Consider your target: iOS.")
      SET(TARGET_PLATFORM TARGET_IOS CACHE STRING "Target Platform" FORCE)
    ELSE(APPLE)
      PRINT("Consider your target: Android.")
      SET(TARGET_PLATFORM TARGET_ANDROID CACHE STRING "Target Platform" FORCE)
    ENDIF(APPLE)
  ENDIF()
  PRINT("Your target is: ${TARGET_PLATFORM}")
ENDMACRO()
