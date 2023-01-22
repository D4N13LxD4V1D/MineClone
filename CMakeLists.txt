cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(MineClone VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(GLAD REQUIRED)
find_package(GLFW REQUIRED)
find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_library(LIB ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw)

enable_testing()
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp")
add_executable(TESTS ${TEST_SOURCES})
target_link_libraries(TESTS GTest::gtest_main LIB glad glfw)
