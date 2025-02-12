#include "mainwindow.h"

MainWindow::MainWindow(ConcreteSubject* loader) : loader(loader), fileCount(0) {  // Inizializza fileCount
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label = new QLabel("Caricamento risorse", this);
    QProgressBar* progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);

    fileNameLabel = new QLabel("", this);
    fileCountLabel = new QLabel("File caricati: 0", this);  // Inizializza il fileCountLabel
    QPushButton* button = new QPushButton("Seleziona cartella e inizia caricamento", this);

    layout->addWidget(label);
    layout->addWidget(progressBar);
    layout->addWidget(fileCountLabel);  // Aggiungi il fileCountLabel al layout
    layout->addWidget(button);
    layout->addWidget(fileNameLabel);

    // Crea l'observer e lo attacca al loader, passando anche il riferimento a loader
    observer = std::make_shared<ConcreteObserver>(progressBar, fileNameLabel, loader);
    observer->attach(loader);

    // Collegare il segnale fileLoaded al nuovo slot updateFileName
    connect(loader, &ConcreteSubject::fileLoaded, this, &MainWindow::updateFileName);

    connect(button, &QPushButton::clicked, [loader, this]() {
        QString directory = QFileDialog::getExistingDirectory(this, "Seleziona una cartella", "");
        if (!directory.isEmpty()) {
            QDir dir(directory);
            QStringList filesList = dir.entryList(QDir::Files);

            for (const QString& file : filesList) {
                loader->addFile((dir.absoluteFilePath(file)).toStdString());
            }

            if (!filesList.isEmpty()) {
                loader->load();
            }
            else {
                QMessageBox::information(this, "Errore", "Nessun file trovato nella cartella selezionata.");
            }
        }
    });
}

// Implementazione dello slot per aggiornare il nome del file e il numero di file caricati
void MainWindow::updateFileName(const std::string& fileName) {
    fileNameLabel->setText(QString::fromStdString(fileName));  // Imposta il testo del QLabel con il nome del file

    fileCount++;  // Incrementa il contatore dei file caricati
    fileCountLabel->setText(QString("File caricati: %1").arg(fileCount));  // Aggiorna il contatore sul label
}
