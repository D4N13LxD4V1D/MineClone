cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(MineClone VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(GLAD REQUIRED)
find_package(GLFW REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)