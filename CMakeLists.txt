cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(MineClone VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(GLAD REQUIRED)
find_package(GLFW REQUIRED)
find_package(GLM REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw glm OpenGL::GL)

enable_testing()
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp")
add_executable(TESTS ${TEST_SOURCES})
target_include_directories(TESTS PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(TESTS GTest::gtest_main glad glfw glm OpenGL::GL)

include(GoogleTest)
gtest_discover_tests(TESTS)