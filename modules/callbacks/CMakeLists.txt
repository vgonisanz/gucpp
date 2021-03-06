# Header
#-----------------------------------------------------------------------#
SET(PROJ_NAME callbacks-tmb)
PROJECT(${PROJ_NAME})
MESSAGE(" + Adding module ${PROJ_NAME} ")				# In info

# Include directories with headers
#-----------------------------------------------------------------------#
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )		# This projects' includes
INCLUDE_DIRECTORIES( ${${PROJ_MAIN_NAME}_PATH_MAIN}/modules/common/include )	# Other includes in modules

# Source, macro to find all files. If you add more, regenerate project
#-----------------------------------------------------------------------#
FILE(GLOB ${PROJ_NAME}_SRC
    "src/*.cpp"
)
FILE(GLOB ${PROJ_NAME}_HEADERS
    "include/*.h"
)

# Create Library
#-----------------------------------------------------------------------#
ADD_LIBRARY(${PROJ_NAME} ${${PROJ_MAIN_NAME}_LIB_TYPE} ${${PROJ_NAME}_HEADERS} ${${PROJ_NAME}_SRC} )

# Link libraries with Project
#-----------------------------------------------------------------------#
#TARGET_LINK_LIBRARIES(${PROJ_NAME} project-dependency1)

# Install
#-----------------------------------------------------------------------#
INSTALL(TARGETS ${PROJ_NAME}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/lib"
        )
INSTALL(FILES ${${PROJ_NAME}_HEADERS}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/include"
        )

#PRINTBASICINFO(${PROJ_NAME})						# Macro cmake_tools to print, uncomment to add info
MESSAGE(" - Module ${PROJ_NAME} added!")					# Out info
