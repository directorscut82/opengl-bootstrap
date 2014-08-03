set(
    bootstrap_glfw_h_files
    application.h
)

set(
    bootstrap_glfw_cxx_files
    application.cpp
)


add_library(
    bootstrap-glfw
    STATIC
    ${bootstrap_glfw_h_files}
    ${bootstrap_glfw_cxx_files}
)

include_directories(${GLFW_INCLUDE_DIRS})

target_link_libraries(
    bootstrap-glfw
    ${GLFW_LIBRARIES}
    bootstrap-core
)

set_property(TARGET bootstrap-glfw PROPERTY OUTPUT_NAME bootstrapglfw)


install(
    TARGETS bootstrap-glfw
    ARCHIVE DESTINATION lib
)

install(
    FILES ${bootstrap_glfw_h_files}
    DESTINATION include/bootstrap/glfw
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)
