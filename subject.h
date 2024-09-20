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
#include "observer.h"
#include <mutex>


//creo la claase Subject (carica i file)
class Subject{
protected:
    std::vector<std::shared_ptr<Observer>> observers;
    float progresso=0.0;
    std::mutex mtx;

public:
    void attach(std::shared_ptr<Observer> obs) {
        std::lock_guard<std::mutex> lock(mtx);
        observers.push_back(obs);
    }

    void detach(std::shared_ptr<Observer> obs) {
        std::lock_guard<std::mutex> lock(mtx);
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void notify() {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& obs : observers) {
            if (obs) {
                obs->update(progresso);
            }
        }
    }
    virtual void load(const std::vector<std::string>& files) = 0;
};
class ConcreteSubject : public Subject {
public:
    void load(const std::vector<std::string>& files) override {
        int filetotali=files.size();
        for (int i = 0; i < filetotali; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Simula il caricamento
            {
                std::lock_guard<std::mutex> lock(mtx);
                progresso = static_cast<float>(i + 1) / filetotali;
            }
            notify();  // Notifica tutti gli observer
        }
        // Visualizza il numero totale di file caricati
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Numero totale di file caricati: " << filetotali << std::endl; // Aggiungi questa linea
        }
    }
};
#endif //PROGBAR_V2_SUBJECT_H
