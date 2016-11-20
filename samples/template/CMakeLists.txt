#####################################################################################################################################################################################
# This is an Auto-compilable sample configuration script.
# This CMakeLists user some macros to create executable and install following Pipero Style Project.
#     · This CMakeList is the reference .
#     · All headers (*.h, *.hcc) must be in ./include folder
#     · All source (*.c, *.cpp) must be in ./src folder
#
# The steps are:
#   1º  Assign temporal PROJ_NAME variable. Edit with a name and the sample will compile automatically.
#   2º  Assign INCLUDE_DIRECTORIES variable with all include paths needed by your code.
#   3º  Set linking directories (path to libraries needed)
#   4º  Macro to take all files, take all src and includes from their folders.
#   5º  Command ADD_EXECUTABLE create a executable according with your platform
#   6º  Linked libraries with sample. Set the name of libraries needed by the project
#   7º  Install: Where to install binaries
#   8º  Optional, print debug info.
#
#   Warning: Variable ${PROJ_NAME} will be override out of this project.
#   Note: Uncomment macro PRINTBASICINFO if you have a problem with include or library path, or linking and get userful info in Cmake output.
#####################################################################################################################################################################################

# Sample step I: Set a name (PROJ_NAME), version, and enable languages for the current project
# ------------------------------------------------------------------------------------------------------
SET(PROJ_NAME sample-template-gucpp)
PROJECT(${PROJ_NAME})

# Notify start
PRINT("+ Adding sample ${PROJ_NAME} ")				# In info

# Sample step II: Add the given directories to those the compiler uses to search for include files
# ------------------------------------------------------------------------------------------------------
INCLUDE_DIRECTORIES(  ${CMAKE_CURRENT_SOURCE_DIR}/include 	    	# This projects' includes
                      ${${PROJ_MAIN_NAME}_INCLUDE_PATH}           # Main project includes
                      )

# Sample step III: Create variables with all includes and sources. You can add them manually in a VAR.
# ------------------------------------------------------------------------------------------------------
FILE(GLOB ${PROJ_NAME}_HEADERS
    "include/*.h"
    "include/*.hpp"
)
FILE(GLOB ${PROJ_NAME}_SRC
    "src/*.c"
    "src/*.cpp"
)

# Sample step IV: List of linker search directories. Path to headers needed by the project.
# ------------------------------------------------------------------------------------------------------
#LINK_DIRECTORIES( ${DIR1} ${DIR2} ...)

# Sample step V: Create an executable to the project using the specified source files in current project.
# ------------------------------------------------------------------------------------------------------
ADD_EXECUTABLE(${PROJ_NAME} ${${PROJ_NAME}_HEADERS} ${${PROJ_NAME}_SRC} )

# Sample step VI: Link a target to given libraries. Set the name of libraries needed by the project.
# ------------------------------------------------------------------------------------------------------
#TARGET_LINK_LIBRARIES(${PROJ_NAME} project-dependency1)

# Sample step VII: Specify rules to run at install time. Copy generated target to a destination.
# ------------------------------------------------------------------------------------------------------
INSTALL(TARGETS ${PROJ_NAME}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/bin"
        )

# Sample step VIII (DEBUG ONLY): Use macro from cmakesupport to print userful info for free.
# ------------------------------------------------------------------------------------------------------
#PRINTBASICINFO(${PROJ_NAME})						# Print absolute path to includes, libraries, and libs to link.

# Notify end
PRINT("- Sample ${PROJ_NAME} added!")					# Out info
