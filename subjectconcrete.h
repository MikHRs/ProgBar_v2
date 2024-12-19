// subjectconcrete.h

#ifndef PROGBAR_V2_SUBJECTCONCRETE_H
#define PROGBAR_V2_SUBJECTCONCRETE_H

#include "subject.h"
#include <list>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <QTimer>


class ConcreteSubject : public Subject {
private:
    std::list<std::string> files;  // Lista dei file da caricare
    std::list<std::string>::iterator fileIterator;  // Iteratore per scorrere i file
    int totalFilesLoaded = 0;  // Contatore dei file caricati

public:
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
        // Quando tutti i file sono stati caricati
        std::cout << "Caricamento completato. File totali caricati: " << totalFilesLoaded << std::endl;
        return;
    }

    // Nome del file corrente
    std::string currentFile = *fileIterator;

    // Aggiorna il progresso
    progresso = static_cast<float>(totalFilesLoaded + 1) / files.size();  // Calcola il progresso
    totalFilesLoaded++;  // Incrementa il contatore dei file caricati
    notify(currentFile);  // Notifica gli osservatori del file corrente

    ++fileIterator;  // Passa al prossimo file

    // Pianifica il prossimo caricamento dopo 50ms
    QTimer::singleShot(50, [this]() { this->loadNextFile(); });
}
    // Funzione di caricamento dei file
    void load() override {
    if (files.empty()) {
        std::cout << "Nessun file da caricare." << std::endl;
        return;
    }

    totalFilesLoaded = 0;  // Reset del contatore
    fileIterator = files.begin();  // Inizializza l'iteratore al primo elemento

        std::cout << "Avvio caricamento con " << files.size() << " file." << std::endl;
    // Avvia il caricamento del primo file dopo 0 ms
    QTimer::singleShot(0, [this]() { this->loadNextFile(); });
}
    const std::list<std::shared_ptr<Observer>>& getObservers() const {
        return observers;
    }
};

#endif // PROGBAR_V2_SUBJECTCONCRETE_H

