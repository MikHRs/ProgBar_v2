#include <gtest/gtest.h>     // Libreria Google Test per test automatizzati
#include <QApplication>      // Necessario per QApplication
#include "../subjectconcrete.h"  // Inclusione per la classe ConcreteSubject
#include "../mainwindow.h"       // Inclusione per la classe MainWindow
#include <gtest/gtest.h>
#include <QApplication>

#include <gtest/gtest.h>
#include <QApplication>

// Funzione principale dei test
int main(int argc, char** argv) {
    // Inizializza QApplication per test con Qt
    QApplication app(argc, argv);

    // Inizializza Google Test
    ::testing::InitGoogleTest(&argc, argv);

    // Esegui tutti i test Google Test e restituisci il risultato
    return RUN_ALL_TESTS();
}