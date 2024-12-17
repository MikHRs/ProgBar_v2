#include <gtest/gtest.h> 
#include "subjectconcrete.h"
#include "observerconcrete.h"

class ConcreteSubjectTest : public ::testing::Test {
protected:
    ConcreteSubject* loader;

    void SetUp() override {
        loader = new ConcreteSubject();
    }

    void TearDown() override {
        delete loader;
    }
};

TEST_F(ConcreteSubjectTest, LoadFiles) {
    loader->addFile("file1.txt");
    loader->addFile("file2.txt");
    loader->load();

    EXPECT_EQ(loader->getTotalFilesLoaded(), 2);
}

TEST_F(ConcreteSubjectTest, NotifyObservers) {
    QProgressBar progressBar;
    QLabel fileNameLabel;
    auto observer = std::make_shared<ConcreteObserver>(&progressBar, &fileNameLabel, loader);
    observer->attach(loader);

    loader->addFile("file1.txt");
    loader->addFile("file2.txt");
    loader->load();

    EXPECT_EQ(progressBar.value(), 100);
    EXPECT_EQ(fileNameLabel.text().toStdString(), "file2.txt");
}

TEST_F(ConcreteSubjectTest, SubscribeUnsubscribeObserver) {
    QProgressBar progressBar;
    QLabel fileNameLabel;
    auto observer = std::make_shared<ConcreteObserver>(&progressBar, &fileNameLabel, loader);

    observer->attach(loader);
    EXPECT_EQ(loader->getObservers().size(), 1);

    observer->detach(loader);
    EXPECT_EQ(loader->getObservers().size(), 0);
}