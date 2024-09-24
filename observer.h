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




#endif //PROGBAR_V2_OBSERVER_H
