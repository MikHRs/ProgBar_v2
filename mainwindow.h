#ifndef PROGBAR_V2_MAINWINDOW_H
#define PROGBAR_V2_MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QProgressBar>
#include <QLabel>
#include <QMessageBox>
#include <QDir>
#include <thread>
#include "subjectconcrete.h"
#include "observerconcrete.h"

class MainWindow : public QWidget {
    Q_OBJECT  // Aggiungi il macro per i segnali e slot

private:
    QLabel* fileCountLabel;
    QLabel* fileNameLabel;
    std::shared_ptr<ConcreteObserver> observer;
    ConcreteSubject* loader;

public:
    explicit MainWindow(ConcreteSubject* loader);

    public slots:
        void updateFileName(const std::string& fileName);  // Slot per aggiornare il nome del file
};

#endif // PROGBAR_V2_MAINWINDOW_H
