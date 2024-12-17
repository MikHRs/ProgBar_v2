// observerconcrete.h

#ifndef PROGBAR_V2_OBSERVERCONCRETE_H
#define PROGBAR_V2_OBSERVERCONCRETE_H

#include "observer.h"
#include "subjectconcrete.h"
#include <QProgressBar>
#include <QLabel>

class ConcreteObserver : public Observer {
private:
    QProgressBar* progressBar;
    QLabel* fileNameLabel;
    ConcreteSubject* loader; // Aggiungi il riferimento a ConcreteSubject

public:
    explicit ConcreteObserver(QProgressBar* bar, QLabel* label, ConcreteSubject* subject)
            : progressBar(bar), fileNameLabel(label), loader(subject) {
        if (!progressBar || !fileNameLabel || !loader) {
            throw std::invalid_argument("Puntatore a QProgressBar, QLabel o ConcreteSubject non valido!");
        }
    }

    void update(float progresso, const std::string& currentFile) override {
        // Ora possiamo usare loader direttamente, senza bisogno di dynamic_cast
        QMetaObject::invokeMethod(progressBar, "setValue", Q_ARG(int, static_cast<int>(progresso * 100)));
        QMetaObject::invokeMethod(fileNameLabel, "setText", Q_ARG(QString, QString::fromStdString(currentFile)));

        // Esempio di cosa puoi fare con loader se necessario:
        // loader->doSomething();
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