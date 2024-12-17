#ifndef PROGBAR_V2_SUBJECT_H
#define PROGBAR_V2_SUBJECT_H

#include <memory>
#include <list>
#include "observer.h"

class Subject {
protected:
    std::list<std::shared_ptr<Observer>> observers;  // Lista di osservatori
    float progresso = 0.0;  // Valore del progresso

public:
    virtual ~Subject() = default;

    void subscribe(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }

    void unsubscribe(std::shared_ptr<Observer> obs) {
        observers.remove(obs);
    }

    void notify(const std::string& currentFile) {
        for (const auto& obs : observers) {
            if (obs) {
                obs->update(progresso, currentFile);  // Notifica gli osservatori
            }
        }
    }

    virtual void load() = 0;
    virtual int getTotalFilesLoaded() const = 0;  // Aggiunto il getter per il totale dei file caricati
};

#endif // PROGBAR_V2_SUBJECT_H
