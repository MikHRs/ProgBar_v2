//
// Created by michele on 24/09/24.
//

// observerconcrete.h

#ifndef PROGBAR_V2_OBSERVERCONCRETE_H
#define PROGBAR_V2_OBSERVERCONCRETE_H

#include "observer.h"
#include <QProgressBar>
#include <QLabel>

// Classe concreta che osserva e aggiorna la progress bar e il nome del file
class ConcreteObserver : public Observer {
private:
    QProgressBar* progressBar;
    QLabel* fileNameLabel;

public:
    explicit ConcreteObserver(QProgressBar* bar, QLabel* label)
            : progressBar(bar), fileNameLabel(label) {
        // Verifica che i puntatori siano validi
        if (!progressBar || !fileNameLabel) {
            throw std::invalid_argument("Puntatore a QProgressBar o QLabel non valido!");
        }
    }

    void update(float progresso, const std::string& currentFile) override {
        // Aggiorna la progress bar e il nome del file nel thread GUI
        QMetaObject::invokeMethod(progressBar, "setValue", Q_ARG(int, static_cast<int>(progresso * 100)));
        QMetaObject::invokeMethod(fileNameLabel, "setText", Q_ARG(QString, QString::fromStdString(currentFile)));
    }

    void attach(Subject* subject) override {
        subject->subscribe(std::shared_ptr<Observer>(this));
    }

    void detach(Subject* subject) override {
        subject->unsubscribe(std::shared_ptr<Observer>(this));
    }

    ~ConcreteObserver() override = default;
};

#endif // PROGBAR_V2_OBSERVERCONCRETE_H