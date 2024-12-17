
// main.cpp

#include <QApplication>
#include "mainwindow.h"
#include "subjectconcrete.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);  // Crea l'applicazione Qt

    ConcreteSubject loader;  // Crea l'oggetto loader
    MainWindow window(&loader);  // Crea la finestra principale
    window.setWindowTitle("Progress Bar Observer");
    window.show();  // Mostra la finestra principale

    return app.exec();  // Avvia il loop dell'applicazione Qt
}
