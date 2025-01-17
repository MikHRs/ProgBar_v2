cmake_minimum_required(VERSION 3.27)
project(ProgBar_v2_tests)

# Trova Google Test
add_subdirectory(lib/googletest)

# Trova i pacchetti Qt5 necessari per i test
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Test)

# Aggiungi l'eseguibile per i test
add_executable(ProgBar_v2_tests
        test_subject.cpp
        test_mainwindow.cpp
        ../mainwindow.cpp
        ../subject.h
        ../subjectconcrete.h
        test_main.cpp
        # Aggiungi questi due file
)

# Linka le librerie necessarie ai test
target_link_libraries(ProgBar_v2_tests PRIVATE
        gtest
        gtest_main
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Test
        pthread
)

# Includi directory per i test
target_include_directories(ProgBar_v2_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${Qt5Core_INCLUDE_DIRS}
        ${Qt5Gui_INCLUDE_DIRS}
        ${Qt5Widgets_INCLUDE_DIRS}
)

# Aggiungi un target di test
add_test(NAME ProgBar_v2_UnitTests COMMAND ProgBar_v2_tests)



