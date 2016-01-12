cmake_minimum_required (VERSION 2.8.11)

project (KeySender)
set (KeySender_VERSION_MAJOR 0)
set (KeySender_VERSION_MINOR 1)

# Configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)
if (UNIX)
    find_package(X11 REQUIRED)
endif()

# Include paths
include_directories("/usr/include/qt/")
include_directories("/usr/include/qt/QtCore")
include_directories("/usr/include/qt/QtWidgets")

# Executable
if (UNIX)
    # Compile with Xlib wrapped by XWrapper
    add_executable(KeySender main.cpp mainwindow.cpp xwrapper.cpp)
    target_link_libraries(KeySender Qt5::Widgets X11)
endif()
if (WIN32)
    # TODO
endif()
