cmake_minimum_required(VERSION 3.13)

if(NOT DEFINED PICO_SDK_PATH)
    message(FATAL_ERROR
            "PICO_SDK_PATH was not specified.
             pico_sdk_init() must first be invoked.")
endif()

project(rc_switch)

set(CMAKE_CXX_STANDARD 17)

add_library(radio_switch
    src/radio_switch.cpp
)

target_include_directories(radio_switch PUBLIC inc)
target_link_libraries(radio_switch pico_stdlib)