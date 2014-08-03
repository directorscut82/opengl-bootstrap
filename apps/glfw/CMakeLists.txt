set(
    bootstrap_app_glfw_h_files
)

set(
    bootstrap_app_glfw_cxx_files
    main.cpp
)


add_executable(
    bootstrap-app-glfw
    ${bootstrap_app_glfw_h_files}
    ${bootstrap_app_glfw_cxx_files}
)

target_link_libraries(
    bootstrap-app-glfw
    glfw
    bootstrap-glfw
)

set_target_properties(
    bootstrap-app-glfw
    PROPERTIES
    OUTPUT_NAME glfw
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/apps
)
