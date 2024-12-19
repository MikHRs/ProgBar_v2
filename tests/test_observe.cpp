#include <gtest/gtest.h>
#include <QProgressBar>
#include <QLabel>
#include <QApplication>
#include "../observerconcrete.h" // Include della classe ConcreteObserver
#include "../subjectconcrete.h" // Include per ConcreteSubject usato nei test

TEST(ConcreteObserverTest, UpdateProgressBar) {
    int argc = 0;
    char** argv = nullptr;
    QApplication app(argc, argv); // Necessario per il ciclo eventi di Qt

    // Crea i componenti della GUI necessari
    QProgressBar progressBar;
    QLabel fileNameLabel;

    // Crea un ConcreteSubject
    ConcreteSubject subject;

    // Crea un ConcreteObserver e collegalo a subject
    auto observer = std::make_shared<ConcreteObserver>(&progressBar, &fileNameLabel, &subject);

    // Associa l'osservatore al soggetto
    observer->attach(&subject);

    // Simula un aggiornamento dalla subject
    observer->update(0.5f, "file1.txt");

    // Verifica che la progress bar sia aggiornata correttamente
    EXPECT_EQ(progressBar.value(), 50);

    // Verifica che il nome del file aggiornato sia corretto
    EXPECT_EQ(fileNameLabel.text().toStdString(), "file1.txt");

    // Rimuovi l'osservatore dalla subject
    observer->detach(&subject);

    // Verifica che l'osservatore sia stato rimosso
    EXPECT_EQ(subject.getObservers().size(), 0);
}