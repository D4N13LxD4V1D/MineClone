include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(cpp_test
    window_test.cpp
)

target_link_libraries(cpp_test
    PRIVATE
        GTest::gtest_main
        window
)

include(GoogleTest)
gtest_discover_tests(cpp_test)