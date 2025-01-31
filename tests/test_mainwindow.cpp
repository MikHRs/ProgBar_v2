#include <gtest/gtest.h>
#include <QApplication>
#include <QTimer>
#include "../mainwindow.h"
#include "../subjectconcrete.h"

// Test della progress bar per verificare che il valore finale sia 100
TEST(MainWindowTest, ProgressBarUpdatesCorrectly) {
    int argc = 0;
    char* argv[] = {nullptr};
    QApplication app(argc, argv);

    // Setup: Creazione del ConcreteSubject e della finestra principale
    ConcreteSubject loader;
    MainWindow window(&loader);

    // Trova il QProgressBar nella MainWindow
    QProgressBar* progressBar = window.findChild<QProgressBar*>();
    ASSERT_NE(progressBar, nullptr) << "ProgressBar non trovata nella finestra.";

    // Aggiungi file e avvia il caricamento
    loader.addFile("file1.txt");
    loader.addFile("file2.txt");
    loader.load();

    // Usa un timer per attendere il completamento del caricamento
    QTimer::singleShot(1000, [&]() {
        EXPECT_EQ(progressBar->value(), 100) << "Il valore della progress bar non è corretto.";
        app.quit();
    });

    // Esegui il loop degli eventi Qt
    app.exec();
}
