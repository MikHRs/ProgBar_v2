//
// Created by michele on 24/09/24.
//

#ifndef PROGBAR_V2_OBSERVERCONCRETE_H
#define PROGBAR_V2_OBSERVERCONCRETE_H

#include "observer.h"

//Classe concreta che osserva e aggiorna la progress bar
class ConcreteObserver : public Observer {
private:
    QProgressBar* progressBar;

public:
    explicit ConcreteObserver(QProgressBar* bar) : progressBar(bar) {
        // Verifica che la progress bar sia valida
        if (!progressBar) {
            throw std::invalid_argument("Puntatore a QProgressBar non valido!");
        }
    }

    void update(float progresso) override {
        // Assicurati di aggiornare la progress bar nel thread GUI
        QMetaObject::invokeMethod(progressBar, "setValue", Q_ARG(int, static_cast<int>(progresso * 100)));
    }

    void attach(Subject* subject) override {
        subject->subscribe(std::shared_ptr<Observer>(this));
    }

    void detach(Subject* subject) override {
        subject->unsubscribe(std::shared_ptr<Observer>(this));
    }

    ~ConcreteObserver() override = default;
};
#endif //PROGBAR_V2_OBSERVERCONCRETE_H
