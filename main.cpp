#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <thread>
#include <chrono>
#include "subject.h"
class ProgressbarBarObservers : public Observer{
private:
    QProgressBar* progressBar;

public:
    ProgressbarBarObservers(QProgressBar* bar) : progressBar(bar) {};
    void update(float progresso) override{
        progressBar->setValue(static_cast<int>(progresso *100));
    }
};

class MainWindow:public QWidget{
public:
    MainWindow(Subject* loader){
        QVBoxLayout* Layout = new QVBoxLayout(this);

        QLabel* label = new QLabel("caricamento risorse", this);
        QProgressBar* progressBar = new QProgressBar(this);
        progressBar->setRange(0,100);
        progressBar->setValue(0);

        QPushButton*button = new QPushButton("inizia caricamento",this);
        //aggiungo gli elementi al layout
        Layout->addWidget(label);
        Layout->addWidget(progressBar);
        Layout->addWidget(button);

        //collegamento observer alla progress bar
        ProgressbarBarObservers* observer= new ProgressbarBarObservers(progressBar);
        loader->attach(observer);
        // Quando si clicca sul bottone, inizia il caricamento in un thread separato
        connect(button, &QPushButton::clicked, [loader]() {
            std::vector<std::string> files = {"file1.txt", "file2.txt", "file3.txt", "file4.txt"};
            std::thread loadingThread(&Subject::load, loader, files);
            loadingThread.detach();  // Il thread lavora in background
        });
    }
};
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Crea un Subject (caricatore di risorse)
    Subject loader;

    // Crea la finestra principale
    MainWindow window(&loader);
    window.setWindowTitle("Progress Bar Observer");
    window.show();

    return app.exec();
}