//
// Created by michele on 19/09/24.
//

#ifndef PROGBAR_V2_OBSERVER_H
#define PROGBAR_V2_OBSERVER_H
#include <QProgressBar>
#include <QMetaObject>
//observer interfaccia
class Subject;
class Observer {
public:
    virtual void update(float progresso, const std::string& currentFile) = 0;//metodo chiamto dal soggetto per aggiornare lo stato di avanzamento della progressbar
    virtual void attach(Subject* subject) = 0;
    virtual void detach(Subject* subject) = 0;
    virtual ~Observer() = default;  // Distruttore virtuale
};




#endif //PROGBAR_V2_OBSERVER_H
