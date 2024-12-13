cmake_minimum_required(VERSION 3.27)
project(ProgBar_v2)
# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 17)
# Abilita AUTOMOC per Qt5
set(CMAKE_AUTOMOC ON)
# Percorso per trovare Qt5
set(CMAKE_PREFIX_PATH "/usr/lib/qt5/lib/cmake/Qt5")
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Test)
# Aggiungi l'eseguibile principale
add_executable(ProgBar_v2    main.cpp
        mainwindow.cpp    mainwindow.h
        subject.h    observer.h
        observerconcrete.h    subjectconcrete.h
)
# Linka Qt5 Widgets alla tua applicazione principale
target_link_libraries(ProgBar_v2 Qt5::Widgets)
# Aggiungi Google Test
add_subdirectory(googletest)  # Assicurati che la cartella "googletest" esista nel progetto
# Aggiungi l'eseguibile per i test
add_executable(ProgBar_v2_tests
tests/test_subject.cpp    tests/test_observe.cpp
tests/test_mainwindow.cpp)
# Linka Google Test, Qt5 Test e pthread ai test
target_link_libraries(ProgBar_v2_tests    gtest
gtest_main    Qt5::Test
pthread)
# Includi la directory corrente per entrambi gli eseguibili
target_include_directories(ProgBar_v2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ProgBar_v2_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ProgBar_v2 PRIVATE ${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
target_include_directories(ProgBar_v2_tests PRIVATE ${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(ProgBar_v2 Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(ProgBar_v2_tests gtest gtest_main Qt5::Test pthread)
# Aggiungi target di test manualmente
add_test(NAME ProgBar_v2_UnitTests COMMAND ProgBar_v2_tests)