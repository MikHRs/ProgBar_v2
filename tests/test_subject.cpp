//
// Created by michele on 16/12/24.

#include <QtTest/QtTest>
#include "../subjectconcrete.h" // Percorso relativo al file da testare

class TestConcreteSubject : public QObject {
    Q_OBJECT

private slots:
    void testAddFile();          // Test per aggiungere file
    void testRemoveFile();       // Test per rimuovere file
    void testClearFiles();       // Test per pulire la lista
    void testLoadFiles();        // Test per il caricamento dei file
};

void TestConcreteSubject::testAddFile() {
    ConcreteSubject subject;

    subject.addFile("file1.txt");
    subject.addFile("file2.txt");

    QCOMPARE(subject.getTotalFilesLoaded(), 0);  // Nessun file caricato ancora
}

void TestConcreteSubject::testRemoveFile() {
    ConcreteSubject subject;

    subject.addFile("file1.txt");
    subject.addFile("file2.txt");
    subject.removeFile("file1.txt");

    // Controlla che il file rimosso non sia più nella lista
    subject.load();  // Simula il caricamento
    QCOMPARE(subject.getTotalFilesLoaded(), 1);  // Solo un file dovrebbe essere caricato
}

void TestConcreteSubject::testClearFiles() {
    ConcreteSubject subject;

    subject.addFile("file1.txt");
    subject.addFile("file2.txt");
    subject.clearFiles();

    QCOMPARE(subject.getTotalFilesLoaded(), 0);
}

void TestConcreteSubject::testLoadFiles() {
    ConcreteSubject subject;

    subject.addFile("file1.txt");
    subject.addFile("file2.txt");

    subject.load();

    QCOMPARE(subject.getTotalFilesLoaded(), 2);
}

// Macro necessaria per eseguire i test
QTEST_MAIN(TestConcreteSubject)
#include "test_subject.moc"

//