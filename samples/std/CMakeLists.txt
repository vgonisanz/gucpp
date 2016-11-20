# OPTIONS
#---------------------------------------------------#
OPTION(${PROJ_MAIN_NAME}_SAMPLE_STD_REGEX   		"Sample std standard regex"        	ON )
OPTION(${PROJ_MAIN_NAME}_SAMPLE_STD_OVERFLOW   		"Sample std standard overflow"        	ON )

#---------------------------------------------------#
#                     LOGIC                         #
#---------------------------------------------------#
IF ( ${PROJ_MAIN_NAME}_SAMPLE_STD_REGEX )
  ADD_SUBDIRECTORY( regex )
ENDIF()

IF ( ${PROJ_MAIN_NAME}_SAMPLE_STD_OVERFLOW )
  ADD_SUBDIRECTORY( overflow )
ENDIF()
