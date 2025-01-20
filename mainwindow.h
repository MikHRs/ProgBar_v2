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
private:
    QLabel* fileCountLabel;
    QLabel* fileNameLabel;
    std::shared_ptr<ConcreteObserver> observer;
    ConcreteSubject* loader;
    int fileCount;  // Aggiungi il contatore dei file caricati

public:
    explicit MainWindow(ConcreteSubject* loader);
    void updateFileName(const std::string& fileName);
};

#endif // PROGBAR_V2_MAINWINDOW_H
