cmake_minimum_required(VERSION 3.20)

project(sensor_validation C)

add_executable(
    sensor_tests
    src/sensor.c
    tests/test_sensor.c
)

target_include_directories(
    sensor_tests
    PRIVATE
    include
)

target_compile_options(
    sensor_tests
    PRIVATE
    -Wall
    -Wextra
)

enable_testing()

add_test(
    NAME sensor_boundary_tests
    COMMAND sensor_tests
)