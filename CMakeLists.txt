# © Copyright 2010 - 2016 BlackTopp Studios Inc.
# This file is part of ForYourFriends.
#
#    The Mezzanine Engine is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    The Mezzanine Engine is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with The Mezzanine Engine.  If not, see <http://www.gnu.org/licenses/>.
#
#   The original authors have included a copy of the license specified above in the
#   'Docs' folder. See 'gpl.txt'
#
#   We welcome the use of the Mezzanine engine to anyone, including companies who wish to
#   Build professional software and charge for their product.
#
#   However there are some practical restrictions, so if your project involves
#   any of the following you should contact us and we will try to work something
#   out:
#    - DRM or Copy Protection of any kind(except Copyrights)
#    - Software Patents You Do Not Wish to Freely License
#    - Any Kind of Linking to Non-GPL licensed Works
#    - Are Currently In Violation of Another Copyright Holder's GPL License
#    - If You want to change our code and not add a few hundred MB of stuff to
#        your distribution
#
#   These and other limitations could cause serious legal problems if you ignore
#   them, so it is best to simply contact us or the Free Software Foundation, if
#   you have any questions.
#
#   Joseph Toppi - toppij@gmail.com
#   John Blackwood - makoenergy02@gmail.com

####################################################################################################
cmake_minimum_required(VERSION 2.8)
project(ForkYourFriends CXX)
message(STATUS "${PROJECT_NAME} - Starting Configuration.")

##########################################################################|#########################
set(JagatiChecksum "96252daabd7b82f6e8b1a667246ba252a462e604b055ddf99e5157\
7f7fb77a0ca5a8c7da7ff7bd209efde2b86919cb2130ed657235d00208a53f0646e0e4f5ba")
file(DOWNLOAD
    "https://raw.githubusercontent.com/BlackToppStudios/Jagati/master/Jagati.cmake"
    "${${PROJECT_NAME}_BINARY_DIR}/Jagati.cmake"
    EXPECTED_HASH SHA512=${JagatiChecksum}
)
include("${${PROJECT_NAME}_BINARY_DIR}/Jagati.cmake")

StandardJagatiSetup()

####################################################################################################
message(STATUS "Determining Source Files.")

set(HeaderFiles
    "${ForkYourFriendsIncludeDir}main.h"
)
ShowList("Header Files:" "\t" "${HeaderFiles}")

set(SourceFiles
    "${ForkYourFriendsSourceDir}main.cpp"

)
ShowList("Source Files:" "\t" "${SourceFiles}")

####################################################################################################
# Set up Include Directories

include_directories(
    ${ForkYourFriendsIncludeDir}
)

####################################################################################################
# Define executable 

add_executable(${PROJECT_NAME} ${HeaderFiles} ${SourceFiles})
#target_link_libraries(${PROJECT_NAME}_Tester ${StaticFoundationLib})

####################################################################################################
message(STATUS "${PROJECT_NAME} - Ending Configuration.")
