cmake_minimum_required(VERSION 3.19)
project(GraphVisualizer LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Charts)

qt_standard_project_setup()

qt_add_executable(GraphVisualizer
    WIN32 MACOSX_BUNDLE
    main.cpp
    graphvisualizer.cpp
    graphvisualizer.h
    graphvisualizer.ui
)

target_link_libraries(GraphVisualizer
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Charts
)

include(GNUInstallDirs)

install(TARGETS GraphVisualizer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET GraphVisualizer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
