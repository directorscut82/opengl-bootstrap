SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs" FORCE)
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs" FORCE)
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation" FORCE)

add_subdirectory(glfw)
add_subdirectory(glxw)


set(
    GLFW_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include
    CACHE INTERNAL
    "Include directories of GLFW"
)

set(
    GLXW_INCLUDE_DIRS
    ${CMAKE_CURRENT_BINARY_DIR}/glxw/include
    CACHE INTERNAL
    "Include directories for glxw"
)
