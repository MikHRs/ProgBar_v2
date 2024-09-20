//
// Created by michele on 19/09/24.
//

#ifndef PROGBAR_V2_OBSERVER_H
#define PROGBAR_V2_OBSERVER_H
#include <QProgressBar>
#include <QMetaObject>
//observer interfaccia
class Observer {
public:
    virtual void update(float progresso) =0; //metodo chiamto dal soggetto per aggiornare lo stato di avanzamento della progressbar
    virtual ~Observer() {}  // Distruttore virtuale
};

//Classe concreta che osserva e aggiorna la progress bar
class ConcreteObserver : public Observer {
private:
    QProgressBar* progressBar;

public:
    ConcreteObserver(QProgressBar* bar) : progressBar(bar) {
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


    ~ConcreteObserver() override {}
};


#endif //PROGBAR_V2_OBSERVER_H
