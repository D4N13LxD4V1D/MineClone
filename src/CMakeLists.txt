add_executable(main main.cpp)

add_subdirectory(window)

target_link_libraries(main
    PRIVATE
        window
        glad
        glfw
)