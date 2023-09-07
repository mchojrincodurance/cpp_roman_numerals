cmake_minimum_required(VERSION 3.26)
project(roman_numerals)

set(CMAKE_CXX_STANDARD 17)

add_executable(roman_numerals main.cpp
        RomanNumeralsSuite.cc
        RomanNumeralsSuite.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)
target_link_libraries(roman_numerals GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(roman_numerals)
