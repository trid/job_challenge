cmake_minimum_required(VERSION 3.27)
project(challenge LANGUAGES CXX)

find_package(Qt5 REQUIRED COMPONENTS Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

enable_testing(true)

add_executable(mytest
        cable_type_suite.cpp
        cable_type_suite.h
        cable_type_crud_mock.cpp
        cable_type_crud_mock.h
        cable_type_builder.cpp
        cable_type_builder.h)
add_test(NAME mytest COMMAND mytest)

target_link_libraries(mytest PRIVATE Qt::Test)