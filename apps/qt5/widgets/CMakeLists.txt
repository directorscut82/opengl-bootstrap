find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


set(
    bootstrap_app_qt5_widgets_h_files
    window.h
)

set(
    bootstrap_app_qt5_widgets_cxx_files
    main.cpp
    window.cpp
)


set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


add_executable(
    bootstrap-app-qt5-widgets
    ${bootstrap_app_qt5_widgets_h_files}
    ${bootstrap_app_qt5_widgets_cxx_files}
)

target_link_libraries(
    bootstrap-app-qt5-widgets
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    bootstrap-qt5
)

set_target_properties(
    bootstrap-app-qt5-widgets
    PROPERTIES
    OUTPUT_NAME widgets
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/apps/qt5
)
