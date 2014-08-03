set(
    bootstrap_core_h_files
    common.h
    openglrenderer.h
    utils.h
)

set(
    bootstrap_core_cxx_files
    openglrenderer.cpp
    utils.cpp
)


add_library(
    bootstrap-core
    STATIC
    ${bootstrap_core_h_files}
    ${bootstrap_core_cxx_files}
)

add_dependencies(bootstrap-core shaders)
include_directories(${GLXW_INCLUDE_DIRS} ${SHADERS_INCLUDE_DIRS})
target_link_libraries(bootstrap-core glxw)
set_property(TARGET bootstrap-core PROPERTY OUTPUT_NAME bootstrapcore)


install(
    TARGETS bootstrap-core
    ARCHIVE DESTINATION lib
)

install(
    FILES ${bootstrap_core_h_files}
    DESTINATION include/bootstrap/core
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)
