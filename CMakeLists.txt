cmake_minimum_required(VERSION 3.19)

set(CMAKE_C_STANDARD 11)

set(PICO_SDK_PATH /home/bczhc/open-source/pico-sdk)
include(pico_sdk_import.cmake)

pico_sdk_init()

project(c)

add_executable(hello hello_world.c)
add_executable(blink blink.c)
add_executable(cpp_test cpp_test.cpp)
add_executable(onboard_temperature onboard_temperature.c)

add_library(
        ext_lib
        third_party/bczhc_cpp/third_party/crypto-algorithms/sha256.c
)

target_link_libraries(hello pico_stdlib)
target_link_libraries(blink pico_stdlib)
target_link_libraries(cpp_test pico_stdlib ext_lib)
target_link_libraries(onboard_temperature pico_stdlib hardware_adc)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(hello)
pico_add_extra_outputs(blink)
pico_add_extra_outputs(cpp_test)
pico_add_extra_outputs(onboard_temperature)