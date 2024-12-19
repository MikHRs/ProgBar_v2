cmake_minimum_required(VERSION 3.27)
project(ProgBar_v2)

# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 17)

# Abilita AUTOMOC per Qt5
set(CMAKE_AUTOMOC ON)

# Percorso per trovare Qt5
set(CMAKE_PREFIX_PATH "/usr/lib/qt5/lib/cmake/Qt5")

# Trova i pacchetti Qt5 necessari
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Aggiungi l'eseguibile principale
add_executable(ProgBar_v2
        main.cpp
        mainwindow.cpp
        mainwindow.h
        subject.h
        observer.h
        observerconcrete.h
        subjectconcrete.h
)

# Linka le librerie Qt5 all'eseguibile principale
target_link_libraries(ProgBar_v2 PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

# Aggiungi la directory dei test
add_subdirectory(tests)
