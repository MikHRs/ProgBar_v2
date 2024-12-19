#ifndef PROGBAR_V2_OBSERVERCONCRETE_H
#define PROGBAR_V2_OBSERVERCONCRETE_H

#include "observer.h"
#include "subjectconcrete.h"
#include <QProgressBar>
#include <QLabel>

#include <memory>

class ConcreteObserver : public Observer, public std::enable_shared_from_this<ConcreteObserver> {
private:
    QProgressBar* progressBar;
    QLabel* fileNameLabel;
    ConcreteSubject* loader;

public:
    explicit ConcreteObserver(QProgressBar* bar, QLabel* label, ConcreteSubject* subject)
            : progressBar(bar), fileNameLabel(label), loader(subject) {
        if (!progressBar || !fileNameLabel || !loader) {
            throw std::invalid_argument("Puntatore a QProgressBar, QLabel o ConcreteSubject non valido!");
        }
    }

    void update(float progresso, const std::string& currentFile) override {
        if (progressBar && fileNameLabel) {
            QMetaObject::invokeMethod(progressBar, "setValue", Q_ARG(int, static_cast<int>(progresso * 100)));
            QMetaObject::invokeMethod(fileNameLabel, "setText", Q_ARG(QString, QString::fromStdString(currentFile)));
        }
    }

    void attach(Subject* subject) override {
        if (subject) {
            // Usa shared_from_this per ottenere un std::shared_ptr valido all'interno di attach
            subject->subscribe(shared_from_this());
        }
    }

    void detach(Subject* subject) override {
        if (subject) {
            // Usa shared_from_this per disiscrivere il puntatore dello stesso oggetto
            subject->unsubscribe(shared_from_this());
        }
    }

    ~ConcreteObserver() override = default;
};

#endif // PROGBAR_V2_OBSERVERCONCRETE_H