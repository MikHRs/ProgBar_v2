//
// Created by michele on 16/12/24.

#include <QtTest/QtTest>
#include "../observerconcrete.h"
#include "../subjectconcrete.h"

class TestConcreteObserver : public QObject {
    Q_OBJECT

private slots:
    void testObserverUpdate();
};

void TestConcreteObserver::testObserverUpdate() {
    QProgressBar progressBar;
    QLabel fileNameLabel;
    ConcreteSubject subject;

    ConcreteObserver observer(&progressBar, &fileNameLabel, &subject);
    observer.attach(&subject);

    subject.addFile("file1.txt");
    subject.addFile("file2.txt");

    subject.load();

    QCOMPARE(progressBar.value(), 100);  // Controlla che il progresso sia al massimo
    QCOMPARE(fileNameLabel.text(), "file2.txt");  // Controlla l'ultimo file caricato
}

// Macro necessaria per eseguire i test
QTEST_MAIN(TestConcreteObserver)
#include "test_observer.moc"

//