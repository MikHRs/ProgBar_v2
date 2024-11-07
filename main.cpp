#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <thread>
#include "subjectconcrete.h"
#include "observerconcrete.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

class MainWindow : public QWidget {
private:
    QLabel* fileCountLabel;
    QLabel* fileNameLabel;
    std::shared_ptr<ConcreteObserver> observer; // Manteniamo un riferimento all'observer
    ConcreteSubject* loader; // Puntatore al ConcreteSubject

public:
    explicit MainWindow(ConcreteSubject* loader) : loader(loader) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        QLabel* label = new QLabel("Caricamento risorse", this);
        QProgressBar* progressBar = new QProgressBar(this);
        progressBar->setRange(0, 100);
        progressBar->setValue(0);

        fileNameLabel = new QLabel("", this);
        fileCountLabel = new QLabel("", this);
        QPushButton* button = new QPushButton("Seleziona cartella e inizia caricamento", this);

        layout->addWidget(label);
        layout->addWidget(progressBar);
        layout->addWidget(fileCountLabel);
        layout->addWidget(button);
        layout->addWidget(fileNameLabel);

        // Crea l'observer e lo attacca al loader
        observer = std::make_shared<ConcreteObserver>(progressBar, fileNameLabel);
        observer->attach(loader);

        connect(button, &QPushButton::clicked, [loader, this]() {  // Cattura loader esplicitamente
            QString directory = QFileDialog::getExistingDirectory(this, "Seleziona una cartella", "");
            if (!directory.isEmpty()) {
                QDir dir(directory);
                QStringList filesList = dir.entryList(QDir::Files);

                loader->clearFiles();  // Pulisce la lista dei file prima di aggiungere i nuovi

                for (const QString& file : filesList) {
                    loader->addFile((dir.absoluteFilePath(file)).toStdString());  // Aggiungi ogni file singolarmente
                }

                if (!filesList.isEmpty()) {
                    std::thread loadingThread([loader]() { loader->load(); });  // Esegue il caricamento senza parametri
                    loadingThread.detach();

                    fileCountLabel->setText(QString("Numero di file: %1").arg(filesList.size()));
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
