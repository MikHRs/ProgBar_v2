#include <gtest/gtest.h>
#include <QTest>
#include <QApplication>
#include "../subjectconcrete.h" // Include della classe ConcreteSubject

TEST(ConcreteSubjectTest, AddRemoveAndClearFiles) {
    ConcreteSubject subject;

    // Controlla inizialmente che nessun file sia presente
    EXPECT_EQ(subject.getTotalFilesLoaded(), 0);

    // Aggiungi file
    subject.addFile("file1.txt");
    subject.addFile("file2.txt");

    // Controlla che i file aggiunti non siano ancora caricati
    EXPECT_EQ(subject.getTotalFilesLoaded(), 0);

    // Rimuovi un file specifico
    subject.removeFile("file1.txt");

    // Rimuovi un file che non esiste (non deve causare errori)
    subject.removeFile("file3.txt");

    // Pulisci tutti i file
    subject.clearFiles();
    EXPECT_EQ(subject.getTotalFilesLoaded(), 0);
}

TEST(ConcreteSubjectTest, LoadFiles) {
    int argc = 0;
    char** argv = nullptr;
    QApplication app(argc, argv);  // Necessario per il ciclo eventi Qt

    ConcreteSubject subject;

    // Aggiungi file
    subject.addFile("file1.txt");
    subject.addFile("file2.txt");

    // Controlla che nessun file sia ancora caricato
    EXPECT_EQ(subject.getTotalFilesLoaded(), 0);

    // Simula il caricamento dei file (richiede QTimer e ciclo eventi attivo)
    subject.load();

    // Attendi il completamento dei timer (ogni file richiede 50ms)
    QTest::qWait(200); // 50 ms per ogni file -- attesa massima per 2 file

    // Controlla che tutti i file siano stati caricati
    EXPECT_EQ(subject.getTotalFilesLoaded(), 2);
}