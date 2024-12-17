//
// Created by michele on 16/12/24.
#include <QtTest/QtTest>
#include "../mainwindow.h"

class TestMainWindow : public QObject {
    Q_OBJECT

private slots:
    void testButtonClick();
};

void TestMainWindow::testButtonClick() {
    ConcreteSubject subject;
    MainWindow mainWindow(&subject);

    QPushButton* button = mainWindow.findChild<QPushButton*>();
    QVERIFY(button != nullptr);  // Controlla che il pulsante esista

    QSignalSpy spy(button, &QPushButton::clicked);
    QMetaObject::invokeMethod(button, "click");

    QCOMPARE(spy.count(), 1);  // Verifica che il pulsante sia stato cliccato
}

// Macro necessaria per eseguire i test
QTEST_MAIN(TestMainWindow)
#include "test_mainwindow.moc"

//