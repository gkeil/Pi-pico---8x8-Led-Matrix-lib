# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#set board taget
set(PICO_BOARD pico_w CACHE STRING "Board type")

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/pi/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()


project(libled8x8 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

###################################################

# Include/add the directories of dependencies INTERFACE Libs
set ( CUSTOM_LIBS "/home/pi/pico-projects")


# add lcd lib
#add_subdirectory( ${CUSTOM_LIBS}/liblcd build2)


# Add subdirectories of the project
add_subdirectory( src )

# enable when ready
add_subdirectory( test )




