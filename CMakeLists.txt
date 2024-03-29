cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico-sdk/pico_sdk_init.cmake)

project(grove-pico-lcd-example C CXX ASM)
set(CMAKE_C_STANDARD 11)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK
pico_sdk_init()

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function
        -Wno-maybe-uninitialized
        )

add_executable(lcd_example
    lcd_example.c
)

add_subdirectory("grove-lcd-pico")

target_include_directories(rgb_lcd PUBLIC "grove-lcd-pico")
target_link_directories(rgb_lcd PUBLIC "grove-lcd-pico")

target_link_libraries(lcd_example pico_stdlib hardware_i2c pico_binary_info rgb_lcd)

pico_add_extra_outputs(lcd_example)
