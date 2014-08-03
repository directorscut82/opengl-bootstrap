find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


set(
    bootstrap_qt5_h_files
    openglsurface.h
    window.h
)

set(
    bootstrap_qt5_cxx_files
    openglsurface.cpp
    window.cpp
)


set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


add_library(
    bootstrap-qt5
    STATIC
    ${bootstrap_qt5_h_files}
    ${bootstrap_qt5_cxx_files}
)

target_link_libraries(
    bootstrap-qt5
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    bootstrap-core
)

set_property(TARGET bootstrap-qt5 PROPERTY OUTPUT_NAME bootstrapqt5)


install(
    TARGETS bootstrap-qt5
    ARCHIVE DESTINATION lib
)

install(
    FILES ${bootstrap_qt5_h_files}
    DESTINATION include/bootstrap/qt5
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)
