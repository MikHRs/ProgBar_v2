cmake_minimum_required(VERSION 3.27)
project(ProgBar_v2)

set(CMAKE_CXX_STANDARD 17)
#trova qt
find_package(Qt5 REQUIRED COMPONENTS Widgets)
add_executable(ProgBar_v2 main.cpp
        subject.h
        observer.h
        observerconcrete.h
        subjectconcrete.h)
# Linka Qt5 Widgets
target_link_libraries(ProgBar_v2 Qt5::Widgets)