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
set(JagatiChecksum "5e8e040023c56bddcaa5e7e7f540580c5e62f6470081208cd222ae\
2e35019311f3eae1070c55f573990cb47adca4505099bac7f58889044881728f533076f627")
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
    "${ForkYourFriendsIncludeDir}forklift.h"
)
ShowList("Header Files:" "\t" "${HeaderFiles}")

set(SourceFiles
    "${ForkYourFriendsSourceDir}main.cpp"
    "${ForkYourFriendsSourceDir}forklift.cpp"

)
ShowList("Source Files:" "\t" "${SourceFiles}")

####################################################################################################
# Mezzanine finding options

set(MEZZ_Mezzanine_Library_Binary "" CACHE FILEPATH
    "The .DLL, .SO, .A or other binary that contains the Mezzanine.")
set(MEZZ_Library_Source "" CACHE PATH
    "The Root folder of the Mezzanine Source")
set(ActualSourceDir "${MEZZ_Library_Source}/Mezzanine/src")


####################################################################################################
# Set up Include Directories

include_directories(
    ${ForkYourFriendsIncludeDir}
    ${ActualSourceDir}
)

####################################################################################################
# Define executable

add_executable(${PROJECT_NAME} ${HeaderFiles} ${SourceFiles})
#target_link_libraries(${PROJECT_NAME}_Tester ${StaticFoundationLib})
target_link_libraries(${PROJECT_NAME} ${MEZZ_Mezzanine_Library_Binary})

####################################################################################################
# A Project to do nothing but get All the Source files visible in IDEs
add_custom_target(
    ${PROJECT_NAME}_IDE_Visibility
    DEPENDS ${PROJECT_NAME}
    SOURCES ${HeaderFiles}
            ${SourceFiles}
            README.md
            LICENSE.txt
)


message(STATUS "${PROJECT_NAME} - Ending Configuration.")
