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
#include <memory>


//creo la claase Subject (carica i file)
class Subject{
protected:
    std::vector<std::shared_ptr<Observer>> observers;
    float progresso=0.0;
    std::mutex mtx;

public:
    virtual ~Subject() = default;

    void subscribe(std::shared_ptr<Observer> obs) {
        std::lock_guard<std::mutex> lock(mtx);
        observers.push_back(obs);
    }

    void unsubscribe(std::shared_ptr<Observer> obs) {
        std::lock_guard<std::mutex> lock(mtx);
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notify(const std::string& currentFile) {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& obs : observers) {
            if (obs) {
                obs->update(progresso, currentFile);  // Passa anche il nome del file
            }
        }
    }


    virtual void load() = 0;
};

#endif //PROGBAR_V2_SUBJECT_H
