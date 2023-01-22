cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(MineClone VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/GLAD.cmake)
include(cmake/GLFW.cmake)

add_subdirectory(src)
add_subdirectory(tests)