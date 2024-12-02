cmake_minimum_required(VERSION 3.22...3.27)

project(RushRoyale VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(app_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.qrc)
add_subdirectory(src)

qt_standard_project_setup()

include(GNUInstallDirs)
install(TARGETS rush_royale
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
