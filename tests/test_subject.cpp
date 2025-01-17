#include <gtest/gtest.h>
#include "subjectconcrete.h"
#include "observerconcrete.h"
#include <gtest/gtest.h>
#include <memory>
#include "subjectconcrete.h"
#include "observerconcrete.h"

#include "subjectconcrete.h"
#include "gtest/gtest.h"

#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QSignalSpy>
#include "subjectconcrete.h"
// test_subject.cpp
#include <gtest/gtest.h>
#include "subjectconcrete.h"
#include "observerconcrete.h"

#include <gtest/gtest.h>
#include "subjectconcrete.h"
#include "observerconcrete.h"

#include <gtest/gtest.h>
#include "subjectconcrete.h"
#include "observerconcrete.h"

#include <gtest/gtest.h>
#include <QApplication>
#include "mainwindow.h"
#include "subjectconcrete.h"

#include <gtest/gtest.h>
#include "subjectconcrete.h"
#include "observerconcrete.h"

class TestObserver : public Observer {
public:
    float receivedProgress;
    std::string receivedFile;

    TestObserver() : receivedProgress(0), receivedFile("") {}

    void update(float progresso, const std::string& currentFile) override {
        receivedProgress = progresso;
        receivedFile = currentFile;
    }

    void attach(Subject* subject) override {}
    void detach(Subject* subject) override {}
};

TEST(ConcreteSubjectTest, LoadFilesTest) {
    ConcreteSubject loader;
    auto observer = std::make_shared<TestObserver>();

    loader.subscribe(observer);

    loader.addFile("file1.txt");
    loader.addFile("file2.txt");
    loader.load();

    EXPECT_EQ(loader.getTotalFilesLoaded(), 2);
    EXPECT_EQ(observer->receivedProgress, 1.0);
    EXPECT_EQ(observer->receivedFile, "file2.txt");
}
