SET(PROJ_NAME fileoperation-tmb)
PROJECT(${PROJ_NAME})

MESSAGE(" + Adding module ${PROJ_NAME} ")

# Include directories with headers
#---------------------------------------------------#
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
INCLUDE_DIRECTORIES( ${${PROJ_MAIN_NAME}_PATH_MAIN}/modules/common/include )	# Other includes in modules

# Source
#---------------------------------------------------#
FILE(GLOB ${PROJ_NAME}_SRC
    "src/*.cpp"
)
FILE(GLOB ${PROJ_NAME}_HEADERS
    "include/*.h"
)

# Create Library
#---------------------------------------------------#
ADD_LIBRARY(${PROJ_NAME} ${${PROJ_MAIN_NAME}_LIB_TYPE} ${${PROJ_NAME}_SRC} ${${PROJ_NAME}_HEADERS})

# Add to global variable
#---------------------------------------------------#
LIST(APPEND ${PROJ_MAIN_NAME}_LIBS ${PROJ_NAME})

# Link libraries with Project
#---------------------------------------------------#
#TARGET_LINK_LIBRARIES(${PROJ_NAME} XXX)

# Installation files in path
#---------------------------------------------------#
INSTALL(TARGETS ${PROJ_NAME}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/lib"
        )
INSTALL(FILES ${${PROJ_NAME}_HEADERS}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/include"
        )

#PRINTBASICINFO(${PROJ_NAME})
MESSAGE(" - Module ${PROJ_NAME} added!")
