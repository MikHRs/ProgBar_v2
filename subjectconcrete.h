//
// Created by michele on 24/09/24.
//

#ifndef PROGBAR_V2_SUBJECTCONCRETE_H
#define PROGBAR_V2_SUBJECTCONCRETE_H

#include "subject.h"
#include <string>
#include <iostream>
class ConcreteSubject : public Subject {
private:
    std::vector<std::string> files; // Lista dei file da gestire internamente

public:
    void addFile(const std::string& file) {
        files.push_back(file);
    }

    void removeFile(const std::string& file) {
        files.erase(std::remove(files.begin(), files.end(), file), files.end());
    }

    void clearFiles() {
        files.clear();
    }

    void load() override {
        int filetotali = files.size();
        for (int i = 0; i < filetotali; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            {
                std::lock_guard<std::mutex> lock(mtx);
                progresso = static_cast<float>(i + 1) / filetotali;
            }
            notify(files[i]);
        }
        // Visualizza il numero totale di file caricati
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Numero totale di file caricati: " << filetotali << std::endl;
        }
    }
};
#endif //PROGBAR_V2_SUBJECTCONCRETE_H

