# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)
find_package(Git REQUIRED)
execute_process(COMMAND "${GIT_EXECUTABLE}" rev-parse --short HEAD OUTPUT_VARIABLE COMMIT_ID OUTPUT_STRIP_TRAILING_WHITESPACE)
message(STATUS "Computed Git Hash: ${COMMIT_ID}")
add_definitions(-DGIT_HASH="${COMMIT_ID}") # Usable in source code.

add_definitions(-DRH_PLATFORM=20)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD adafruit_feather_rp2040 CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(harp-metro C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(./firmware/harp.core.rp2040/firmware build) # Path to harp.core.rp2040's CMakeLists.txt
include_directories(./firmware/RadioHead/)

# Add executable. Default name is the project name, version 0.1

add_executable(harp-metro main.cpp )

pico_set_program_name(harp-metro "harp-metro")
pico_set_program_version(harp-metro "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(harp-metro 0)
pico_enable_stdio_usb(harp-metro 0)

# Add the standard library to the build
target_link_libraries(harp-metro
        pico_stdlib)
target_link_libraries(harp-metro harp_core harp_sync harp_c_app)

# Add the standard include files to the build
target_include_directories(harp-metro PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(harp-metro)

