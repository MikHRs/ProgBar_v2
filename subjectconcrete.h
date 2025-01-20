#ifndef PROGBAR_V2_SUBJECTCONCRETE_H
#define PROGBAR_V2_SUBJECTCONCRETE_H

#include "subject.h"
#include <list>
#include <string>
#include <iostream>
#include <QTimer>

class ConcreteSubject : public Subject {
    Q_OBJECT

private:
    std::list<std::string> files;  // Lista dei file da caricare
    std::list<std::string>::iterator fileIterator;  // Iteratore per scorrere i file
    int totalFilesLoaded = 0;  // Contatore dei file caricati

public:
    // Costruttore che chiama il costruttore della classe base
    explicit ConcreteSubject(QObject* parent = nullptr) : Subject(parent) {}
    // Aggiungi un file alla lista
    void addFile(const std::string& file) {
        files.push_back(file);
    }

    // Rimuovi un file dalla lista
    void removeFile(const std::string& file) {
        files.remove(file);
    }

    // Pulisci la lista dei file
    void clearFiles() {
        files.clear();
        totalFilesLoaded = 0;  // Reset del contatore
    }

    // Ottieni il numero totale dei file caricati
    int getTotalFilesLoaded() const override {
        return totalFilesLoaded;
    }

    void loadNextFile() {
        if (fileIterator == files.end()) {
            std::cout << "Caricamento completato. File totali caricati: " << totalFilesLoaded << std::endl;
            emit loadingFinished();
            return;
        }

        std::string currentFile = *fileIterator;

        progresso = static_cast<float>(totalFilesLoaded + 1) / files.size();
        totalFilesLoaded++;

        std::cout << "File caricato: " << currentFile << std::endl;

        // Notifica gli observer
        notify(currentFile);

        emit progressUpdated(progresso);

        // Emessi il segnale per notificare che un file è stato caricato
        emit fileLoaded(currentFile);

        ++fileIterator;

        QTimer::singleShot(500, this, &ConcreteSubject::loadNextFile);
    }

    void load() override {
        if (files.empty()) {
            std::cout << "Nessun file da caricare." << std::endl;
            return;
        }

        totalFilesLoaded = 0;  // Reset del contatore
        fileIterator = files.begin();  // Inizializza l'iteratore al primo elemento

        std::cout << "Avvio caricamento con " << files.size() << " file." << std::endl;

        QTimer::singleShot(0, this, &ConcreteSubject::loadNextFile);  // Avvia il caricamento
    }

signals:
    void loadingFinished();  // Segnale che indica il completamento del caricamento
    void progressUpdated(float progress);  // Segnale per aggiornare il progr
    void fileLoaded(const std::string& fileName);
};

#endif // PROGBAR_V2_SUBJECTCONCRETE_H


