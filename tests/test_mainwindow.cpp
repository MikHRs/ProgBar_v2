#include <gtest/gtest.h> 
#include <QApplication>
#include <QSignalSpy>
#include "mainwindow.h"
#include "subjectconcrete.h"

class MainWindowTest : public ::testing::Test {
protected:
    QVBoxLayout* layout;
    QProgressBar* progressBar;
    QLabel* fileNameLabel;
    QPushButton* button;
    ConcreteSubject* loader;
    MainWindow* window;

    void SetUp() override {
        layout = new QVBoxLayout();
        progressBar = new QProgressBar();
        fileNameLabel = new QLabel();
        button = new QPushButton("Test Button");

        loader = new ConcreteSubject();
        window = new MainWindow(loader);

        // Configurazione della MainWindow
        window->setLayout(layout);
        layout->addWidget(progressBar);
        layout->addWidget(fileNameLabel);
        layout->addWidget(button);
    }

    void TearDown() override {
        delete window;
        delete loader;
        delete progressBar;
        delete fileNameLabel;
        delete button;
    }
};

TEST_F(MainWindowTest, ButtonClickTest) {
    QSignalSpy spy(button, &QPushButton::clicked);
    button->click();

    EXPECT_EQ(spy.count(), 1);  // Verifica se il pulsante è stato cliccato una volta

    loader->addFile("file1.txt");
    loader->addFile("file2.txt");
    loader->load();

    EXPECT_EQ(progressBar->value(), 100);  // Verifica se la progress bar si è aggiornata
    EXPECT_EQ(fileNameLabel->text().toStdString(), "file2.txt");
}