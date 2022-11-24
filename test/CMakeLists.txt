cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD                11)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_C_EXTENSIONS              ON)
set(CMAKE_CXX_STANDARD              14)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            ON)

project(STM32F303RE_TEST)
enable_language(C CXX ASM)

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_library(AD9833 ../src/AD9833_driver.c)
include_directories(../inc)

add_executable(AD9833_test main.cpp AD9833_test.cpp)

target_link_libraries(AD9833_test
PRIVATE
  GTest::GTest
  AD9833)

enable_testing()

add_test(NAME AD9833_test
        COMMAND AD9833_test          
) 
include(GoogleTest)

gtest_discover_tests(AD9833_test)