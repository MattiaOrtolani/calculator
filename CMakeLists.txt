cmake_minimum_required(VERSION 3.1)

project(calculator)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_RELEASE "-O2")


find_package(wxWidgets 3.1 REQUIRED COMPONENTS net core base)

include(${wxWidgets_USE_FILE})

add_library(tinyexpr tinyexpr.c)
target_include_directories(tinyexpr PUBLIC tinyexpr.h)

add_executable(calculator App.cpp MainFrame.cpp)

target_link_libraries(calculator ${wxWidgets_LIBRARIES})
target_link_libraries(calculator tinyexpr)