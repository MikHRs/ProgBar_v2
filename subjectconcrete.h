// subjectconcrete.h

#ifndef PROGBAR_V2_SUBJECTCONCRETE_H
#define PROGBAR_V2_SUBJECTCONCRETE_H

#include "subject.h"
#include <list>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>


class ConcreteSubject : public Subject {
private:
    std::list<std::string> files;  // Lista dei file da caricare
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

    // Funzione di caricamento dei file
    void load() override {
        int totalFiles = files.size();
        for (const auto& file : files) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Simula un tempo di caricamento
            progresso = static_cast<float>(totalFilesLoaded + 1) / totalFiles;  // Aggiorna il progresso

            totalFilesLoaded++;  // Incrementa il contatore dei file caricati

            notify(file);  // Notifica gli osservatori
        }

        std::cout << "Numero totale di file caricati: " << totalFilesLoaded << std::endl;
    }
    const std::list<std::shared_ptr<Observer>>& getObservers() const {
        return observers;
    }
};

#endif // PROGBAR_V2_SUBJECTCONCRETE_H

