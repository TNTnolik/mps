cmake_minimum_required(VERSION 3.19)

project(mps)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(EPOXY epoxy)

link_directories(${GTKMM_LIBRARY_DIRS})
link_directories(${EPOXY_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${EPOXY_INCLUDE_DIRS})

add_executable(mps src/main.cpp src/window.cpp src/window.h src/OpenGLArea.cpp src/OpenGLArea.h src/ui.h)

target_link_libraries(mps ${GTKMM_LIBRARIES})
target_link_libraries(mps ${EPOXY_LIBRARIES})