cmake_minimum_required(VERSION 3.16)

project(razer-mouse-battery-ui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(apprazer-mouse-battery-ui
    main.cpp
    razermousebattery.h
    razermousebattery.cpp
)

qt_add_qml_module(apprazer-mouse-battery-ui
    URI razer-mouse-battery-ui
    VERSION 1.0
    SOURCES
        razermousebattery.h razermousebattery.cpp
    QML_FILES
        Main.qml BatteryLevelIndicator.qml
)

set_target_properties(apprazer-mouse-battery-ui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apprazer-mouse-battery-ui
    PRIVATE Qt6::Quick
)

install(TARGETS apprazer-mouse-battery-ui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
