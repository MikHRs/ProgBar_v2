#include <gtest/gtest.h> 
#include "observerconcrete.h"
#include "subjectconcrete.h"

class ObserverTest : public ::testing::Test {
protected:
    QProgressBar progressBar;
    QLabel fileNameLabel;
    ConcreteSubject* loader;
    std::shared_ptr<ConcreteObserver> observer;

    void SetUp() override {
        loader = new ConcreteSubject();
        observer = std::make_shared<ConcreteObserver>(&progressBar, &fileNameLabel, loader);
        observer->attach(loader);
    }

    void TearDown() override {
        delete loader;
    }
};

TEST_F(ObserverTest, UpdateMethod) {
    loader->addFile("file1.txt");
    loader->load();

    EXPECT_EQ(progressBar.value(), 100);
    EXPECT_EQ(fileNameLabel.text().toStdString(), "file1.txt");
}

TEST_F(ObserverTest, DetachObserver) {
    observer->detach(loader);

    loader->addFile("file2.txt");
    loader->load();

    EXPECT_EQ(progressBar.value(), 0);  // L'observer non dovrebbe aggiornarsi
    EXPECT_EQ(fileNameLabel.text().toStdString(), "");
}