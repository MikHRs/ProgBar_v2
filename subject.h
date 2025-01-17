#ifndef PROGBAR_V2_SUBJECT_H
#define PROGBAR_V2_SUBJECT_H

#include <QObject>  // Necessario per QObject
#include <memory>
#include <list>
#include "observer.h"
#include <iostream>

class Subject : public QObject {  // Aggiunta ereditarietà da QObject
    Q_OBJECT  // Necessario per usare segnali e slot
protected:
    std::list<std::shared_ptr<Observer>> observers;  // Lista di osservatori
    float progresso = 0.0;  // Valore del progresso

public:  explicit Subject(QObject* parent = nullptr) : QObject(parent) {}  // Costruttore con parent
    virtual ~Subject() = default;

    void subscribe(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }

    void unsubscribe(std::shared_ptr<Observer> obs) {
        observers.remove(obs);
    }

    void notify(const std::string& currentFile) {
        std::cout << "Notifica per il file: " << currentFile << std::endl;
        for (const auto& obs : observers) {
            if (obs) {
                std::cout << "Invocando update per " << typeid(*obs).name() << std::endl;
                obs->update(progresso, currentFile);
            } else {
                std::cout << "Osservatore nullo, non invocato update." << std::endl;
            }
        }
    }

    virtual void load() = 0;
    virtual int getTotalFilesLoaded() const = 0;  // Getter per il totale dei file caricati
};

#endif // PROGBAR_V2_SUBJECT_H
