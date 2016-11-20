# TODO comment all macros remaining to add
################################################################################
##
##  Provide Macro support for the CMake build system
##
##  Version: 0.8
##  Author: Victor Goñi Sanz (vgonisanz@gmail.com)
##
##  Copyright 2016 - Victor Goñi Sanz.
##
##  This program is free software; you can redistribute it and/or modify
##  it under the terms of the GNU General Public License as published by
##  the Free Software Foundation; either version 3 of the License, or
##  (at your option) any later version.
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License along
##  with this program. If not, see <http://www.gnu.org/licenses/>.
##
###############################################################################

# USAGE:
#   Append the folder in your main CMakeLists relative the position of the
#   submodule CMakeSupporter, and the include it, Example:
# LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/cmakesupport")
# MESSAGE( ${CMAKE_MODULE_PATH})
# INCLUDE( cms )

###############################################################################
# Declaration of all functions
###############################################################################
# cmsprint
###############################################################################
#   PRINT         ${MESSAGE}  | Print string message
#   PRINTTITLE    ${MESSAGE}  | Print string message with title format
#   PRINTSUBTITLE ${MESSAGE}  | Print string message with subtitle formar
#   PRINTIF       ${VALUE} ${MESSAGE}   | Print string message with VALUE is true
#   PRINTBASICINFO ${PROJ_NAME} | print userful, include directroreis, libraries path and libs to debug.
#   PRINTADVANCEDINFO ${PROJ_NAME}    | Print userful FULL info with PROJ_NAME title, flags, etc
###############################################################################
# cmscrossplatform
###############################################################################
#   CHECKCROSSPLATFORM  | Autodetect Win32, MAC, Linux iOS or android.
#                       | Android & iOS based on Toolchain
#                       | If you use other toolchain, arm or similar, avoid use this
###############################################################################

# Include files with macros and functions
MESSAGE( " * You are including CMakeSupporter scripts" )

INCLUDE( scripts/signature )                # My own signature, comment it if you want to avoid
INCLUDE( scripts/cmsprint )                 # Userful macros to print logs
INCLUDE( scripts/cmscrossplatform )         # Autodetect target platform, compatible with: GNU/Linux, MAC, Windows, iOS and Android, comment with different toolchains
INCLUDE( scripts/cmsconfigureproject )      # Configure some userful variables with this macro
INCLUDE( scripts/cmsgccversion )            # Configure GCC Options, need to improve
INCLUDE( scripts/cmsautoconfiguration )     # Auto configure some variables, could affect your previous configuration.  You can override it after the include
#INCLUDE( scripts/scripts )
