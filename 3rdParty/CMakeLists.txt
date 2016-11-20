#####################################################################################################################################################################################
# This is a 3rdParty CMake configuration script.
# · If variable build is true, configure and ADD_SUBDIRECTORY
#####################################################################################################################################################################################

PRINTSUBTITLE("Adding 3rdParty")				# In info

# Google test for unit test
# ------------------------------------------------------------------------------------------------------
IF(${PROJ_MAIN_NAME}_BUILD_TEST)
  PRINT("+ Adding 3rdParty GMock 1.7.0")
  ADD_SUBDIRECTORY( ./code/gmock-1.7.0 )
  PRINT("- Added GMock")
ELSE()
    PRINT("x Build test is disabled, no add gmock-1.7.0")
ENDIF()

# CUrl
# ------------------------------------------------------------------------------------------------------
IF(${PROJ_MAIN_NAME}_DEPENDENCY_CURL )
  PRINT("+ Adding 3rdParty curl code")
  ADD_SUBDIRECTORY( ./code/curl )
  # Configure curl to work propertly
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/code/curl/curl-config.in"
                 "${${PROJ_MAIN_NAME}_PATH_BIN}/curl-config" @ONLY)
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/code/curl/libcurl.pc.in"
                "${${PROJ_MAIN_NAME}_PATH_BIN}/libcurl.pc" @ONLY)
  # CURL Variables
  SET(BUILD_CURL_TESTS OFF CACHE BOOL "Build test off" FORCE)
  SET(BUILD_CURL_EXE OFF CACHE BOOL "Build executables off" FORCE)
  PRINT("- Added curl code")
ELSE()
  PRINT("x Curl is disabled")
ENDIF()

# Simple JSON
# ------------------------------------------------------------------------------------------------------
IF(${PROJ_MAIN_NAME}_DEPENDENCY_JSON )
  PRINT("+ Adding 3rdParty simpleJSON code")
  # SimpleJSON have a main configuration CMakeLists in base path, take library directly
  ADD_SUBDIRECTORY( ./code/SimpleJSON/code )
  PRINT("- Added simpleJSON")
ELSE()
  PRINT("x SimpleJSON is disabled")
ENDIF()
