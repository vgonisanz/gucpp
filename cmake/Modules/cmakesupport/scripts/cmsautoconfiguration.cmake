MESSAGE( "   · Adding: cmsautoconfiguration macros" )


# 1º Configuration custom build type
# ------------------------------------------------------------------------------------------------------
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release;Relwithdebinfo;Minsizerel" CACHE STRING "Configs" FORCE)
SET(CMAKE_BUILD_TYPE Release CACHE STRING "documentation for this variable")
SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})

# 2º Configuration custom type configuration, git status(Shared, static)
# ------------------------------------------------------------------------------------------------------
SET(${PROJ_MAIN_NAME}_LIB_TYPE "STATIC" CACHE STRING "Type of lib")
SET_PROPERTY(CACHE ${PROJ_MAIN_NAME}_LIB_TYPE PROPERTY STRINGS "SHARED" "STATIC")

# 4º Configuration default CMake options
# ------------------------------------------------------------------------------------------------------
SET(LIBRARY_OUTPUT_PATH 	${PROJECT_BINARY_DIR}/bin 	CACHE PATH "Library output" FORCE)
SET(EXECUTABLE_OUTPUT_PATH 	${PROJECT_BINARY_DIR}/bin 	CACHE PATH "Executable output" FORCE)
SET(CMAKE_DEBUG_POSTFIX )                                   # No postfix

# 5º Add these standard paths to the search paths for FIND_LIBRARY
# to find libraries from these locations first
# Croscompiling is cool
# ------------------------------------------------------------------------------------------------------
 if(UNIX AND NOT ANDROID)
   if(X86_64 OR CMAKE_SIZEOF_VOID_P EQUAL 8)
     if(EXISTS /lib64)
       list(APPEND CMAKE_LIBRARY_PATH /lib64)
     else()
       list(APPEND CMAKE_LIBRARY_PATH /lib)
     endif()
     if(EXISTS /usr/lib64)
       list(APPEND CMAKE_LIBRARY_PATH /usr/lib64)
     else()
       list(APPEND CMAKE_LIBRARY_PATH /usr/lib)
     endif()
   elseif(X86 OR CMAKE_SIZEOF_VOID_P EQUAL 4)
     if(EXISTS /lib32)
       list(APPEND CMAKE_LIBRARY_PATH /lib32)
     else()
       list(APPEND CMAKE_LIBRARY_PATH /lib)
     endif()
     if(EXISTS /usr/lib32)
       list(APPEND CMAKE_LIBRARY_PATH /usr/lib32)
     else()
       list(APPEND CMAKE_LIBRARY_PATH /usr/lib)
     endif()
   endif()
 endif()

MACRO(ENABLE_SSE)
	IF("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
		SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse2")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse2")
	ELSEIF(MSVC)
		SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /arch:SSE2")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:SSE2")
	ENDIF()
ENDMACRO()
