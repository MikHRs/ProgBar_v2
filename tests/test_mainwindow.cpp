#include <gtest/gtest.h>
#include <QApplication>
#include <QDir>
#include <QFile>
#include "../mainwindow.h"
#include "../subjectconcrete.h"

class MainWindowTest : public ::testing::Test {
protected:
    static QApplication* app;

    static void SetUpTestSuite() {
        // Crea QApplication una volta per tutti i test
        int argc = 0;
        char** argv = nullptr;
        app = new QApplication(argc, argv);
    }

    static void TearDownTestSuite() {
        delete app; // Rimuovi QApplication quando tutti i test sono completati
    }

    void SetUp() override {
        QDir dir("test_folder");
        if (!dir.exists()) {
            dir.mkpath(".");
        }
    }

    void TearDown() override {
        QDir dir("test_folder");
        if (dir.exists()) {
            dir.removeRecursively();
        }
    }
};

// Definizione statica di QApplication
QApplication* MainWindowTest::app = nullptr;

TEST_F(MainWindowTest, SelectFolderAndLoadFilesFirst) {
    ConcreteSubject loader;
    MainWindow mainWindow(&loader);

    QDir dir("test_folder");
    QFile file1("test_folder/test1.txt");
    QFile file2("test_folder/test2.txt");
    ASSERT_TRUE(file1.open(QIODevice::WriteOnly));
    ASSERT_TRUE(file2.open(QIODevice::WriteOnly));
    file1.close();
    file2.close();

    dir.setPath("test_folder");
    QStringList fileList = dir.entryList(QDir::Files);
    ASSERT_EQ(fileList.size(), 2);

    for (const auto& file : fileList) {
        loader.addFile((dir.absoluteFilePath(file)).toStdString());
    }

    loader.load();

    EXPECT_EQ(loader.getTotalFilesLoaded(), 2);
}

TEST_F(MainWindowTest, SelectFolderAndLoadFilesSecond) {
    ConcreteSubject loader;
    MainWindow mainWindow(&loader);

    QDir dir("test_folder");
    QFile file1("test_folder/test3.txt");
    ASSERT_TRUE(file1.open(QIODevice::WriteOnly));
    file1.close();

    dir.setPath("test_folder");
    QStringList fileList = dir.entryList(QDir::Files);
    ASSERT_EQ(fileList.size(), 1);

    for (const auto& file : fileList) {
        loader.addFile((dir.absoluteFilePath(file)).toStdString());
    }

    loader.load();

    EXPECT_EQ(loader.getTotalFilesLoaded(), 1);
}