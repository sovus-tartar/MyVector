cmake_minimum_required(VERSION 3.0.0)
project(MyVector VERSION 0.1.0 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(MyVector ./src/main.cpp)
include_directories(./include)
add_subdirectory(./test)

add_compile_options(
    -Werror
    -Wall
    -Wextra
    -Wpedantic
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
)