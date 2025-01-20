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

#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QSignalSpy>
#include "subjectconcrete.h"

TEST(ConcreteSubjectTest, AsynchronousLoading) {
    int argc = 0;
    char** argv = nullptr;
    QCoreApplication app(argc, argv);

    ConcreteSubject loader;

    QSignalSpy finishedSpy(&loader, &ConcreteSubject::loadingFinished);

    loader.addFile("file1.txt");
    loader.addFile("file2.txt");
    loader.load();

    // Aspetta che il segnale "loadingFinished" venga emesso entro 3 secondi
    ASSERT_TRUE(finishedSpy.wait(3000));

    EXPECT_EQ(loader.getTotalFilesLoaded(), 2);
}
