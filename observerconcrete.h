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
        if (progressBar) {
            QMetaObject::invokeMethod(progressBar, [this, progresso]() {
                if (progressBar) {
                    progressBar->setValue(static_cast<int>(progresso * 100));
                }
            }, Qt::QueuedConnection);
        }
    }


    ~ConcreteObserver() override = default;
};
#endif //PROGBAR_V2_OBSERVERCONCRETE_H
