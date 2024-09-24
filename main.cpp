#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <thread>
#include <chrono>
#include "subject.h"
#include "observer.h"
#include "subjectconcrete.h"
#include "observerconcrete.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

class MainWindow : public QWidget {
private:
    QLabel* fileCountLabel; // Dichiara il QLabel per il conteggio dei file
public:
    MainWindow(ConcreteSubject* loader) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        QLabel* label = new QLabel("Caricamento risorse", this);
        QProgressBar* progressBar = new QProgressBar(this);
        progressBar->setRange(0, 100);
        progressBar->setValue(0);

        fileCountLabel = new QLabel("", this); // Nuovo QLabel per mostrare il numero di file
        QPushButton* button = new QPushButton("Seleziona cartella e inizia caricamento", this);


        layout->addWidget(label);
        layout->addWidget(progressBar);
        layout->addWidget(fileCountLabel);
        layout->addWidget(button);

        auto observer = std::make_shared<ConcreteObserver>(progressBar);
        loader->attach(observer);

        connect(button, &QPushButton::clicked, [loader, this]() {
            QString directory = QFileDialog::getExistingDirectory(this, "Seleziona una cartella", "");
            if (!directory.isEmpty()) {
                QDir dir(directory);
                QStringList filesList = dir.entryList(QDir::Files);

                std::vector<std::string> files;
                for (const QString& file : filesList) {
                    files.push_back((dir.absoluteFilePath(file)).toStdString());
                }

                if (!files.empty()) {
                    std::thread loadingThread(&ConcreteSubject::load, loader, files);
                    loadingThread.detach();

                    fileCountLabel->setText(QString("Numero di file: %1").arg(files.size()));
                } else {
                    QMessageBox::information(this, "Errore", "Nessun file trovato nella cartella selezionata.");
                }
            }
        });
    }

};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ConcreteSubject loader;
    MainWindow window(&loader);
    window.setWindowTitle("Progress Bar Observer");
    window.show();

    return app.exec();
}