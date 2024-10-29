cmake_minimum_required(VERSION 3.14)

# Project setup
project(client LANGUAGES CXX)

# Automatically process UI, MOC, and RCC files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set C++ standard to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find necessary Qt components
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Widgets LinguistTools)

# Translation files
set(TS_FILES client_ru_RU.ts)

# Define the executable with the source files
add_executable(client
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${TS_FILES}
)

# Link the required Qt libraries
target_link_libraries(client Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Widgets)

# Translation processing (handles both Qt 5 and Qt 6)
if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# Installation setup for the executable
include(GNUInstallDirs)
install(TARGETS client
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

