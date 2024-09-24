//
// Created by michele on 24/09/24.
//

#ifndef PROGBAR_V2_SUBJECTCONCRETE_H
#define PROGBAR_V2_SUBJECTCONCRETE_H

#include "subject.h"
#include <string>
#include <iostream>
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
#endif //PROGBAR_V2_SUBJECTCONCRETE_H
