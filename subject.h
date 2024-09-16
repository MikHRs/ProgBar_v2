//
// Created by michele on 16/09/24.
//

#ifndef PROGBAR_V2_SUBJECT_H
#define PROGBAR_V2_SUBJECT_H
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>

//observer interfaccia
class Observer {
public:
    virtual void update(float progresso) =0; //metodo chiamto dal soggetto per aggiornare lo stato di avanzamento della progressbar
};

//creo la claase Subject (carica i file)
class Subject{
private:
    std::vector<Observer*> observers;
    float progresso=0.0;

public:
    void attach(Observer* obs){
        observers.push_back(obs);
    }
    void detach(Observer* obs){
        observers.erase(std::remove(observers.begin(),observers.end(),obs),observers.end());
    }
    void notify(){
        for (Observer*obs : observers){
            obs->update(progresso);
        }
    }
    void load(const std::vector<std::string>& files){
        for (int i = 0; i < files.size(); ++i) {
            //simulazione caricamento
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            progresso = static_cast<float>(i+1)/(files.size());
            notify();
            
        }
    }
};
#endif //PROGBAR_V2_SUBJECT_H
