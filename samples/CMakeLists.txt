#####################################################################################################################################################################################
# This is a Modules CMake configuration script. The steps are:
#   1º Configure options with differents samples to be built
#   2º Add samples if options is TRUE
#####################################################################################################################################################################################

PRINTSUBTITLE("Adding samples...")

# Modules step I: Configure options with differents samples to be built
# ------------------------------------------------------------------------------------------------------
OPTION(${PROJ_MAIN_NAME}_SAMPLE_TEMPLATE   			"Sample template"        						 ON )
OPTION(${PROJ_MAIN_NAME}_SAMPLE_COMMON   			"Sample common"        						     ON )
OPTION(${PROJ_MAIN_NAME}_SAMPLE_FACADE   			"Sample facade usage"        				   OFF )
OPTION(${PROJ_MAIN_NAME}_SAMPLE_CORE	   			"Sample core with callbacks usage"     OFF )
OPTION(${PROJ_MAIN_NAME}_SAMPLE_STD   				"Sample std related"        				   ON )
OPTION(${PROJ_MAIN_NAME}_SAMPLE_COMMUNICATION  		"Sample communication"        		ON )
OPTION(${PROJ_MAIN_NAME}_SAMPLE_GEOMETRY2D  		"Sample with abstract geometry in 2D"        				ON )

# Modules step II: Add samples if options is TRUE
# ------------------------------------------------------------------------------------------------------
IF ( ${PROJ_MAIN_NAME}_SAMPLE_TEMPLATE )
  ADD_SUBDIRECTORY( template )
ENDIF()

IF ( ${PROJ_MAIN_NAME}_SAMPLE_COMMON )
  ADD_SUBDIRECTORY( common )
ENDIF()

IF ( ${PROJ_MAIN_NAME}_SAMPLE_FACADE )
  ADD_SUBDIRECTORY( facade )
ENDIF()

IF ( ${PROJ_MAIN_NAME}_SAMPLE_CORE )
  ADD_SUBDIRECTORY( core )
ENDIF()

IF ( ${PROJ_MAIN_NAME}_SAMPLE_STD )
  ADD_SUBDIRECTORY( std )
ENDIF()

IF ( ${PROJ_MAIN_NAME}_SAMPLE_COMMUNICATION)
  ADD_SUBDIRECTORY( communication)
ENDIF()

IF ( ${PROJ_MAIN_NAME}_SAMPLE_GEOMETRY2D)
  ADD_SUBDIRECTORY( geometry2d)
ENDIF()
