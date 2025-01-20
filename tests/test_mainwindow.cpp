#include <gtest/gtest.h>
#include <QApplication>
#include "../mainwindow.h"
#include "../subjectconcrete.h"
#include "mainwindow.h"
#include "subjectconcrete.h"
#include <gtest/gtest.h>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QCoreApplication>

#include <gtest/gtest.h>
#include <QApplication>
#include "mainwindow.h"
#include "subjectconcrete.h"

#include <gtest/gtest.h>
#include <QApplication>
#include "mainwindow.h"
#include "subjectconcrete.h"
#include <iostream>
#include <QDebug>
TEST(MainWindowTest, ProgressBarTest) {
    int argc = 0;
    char* argv[] = {nullptr};
    QApplication app(argc, argv);

    ConcreteSubject loader;
    MainWindow window(&loader);

    QProgressBar* progressBar = window.findChild<QProgressBar*>();
    ASSERT_NE(progressBar, nullptr);

    loader.addFile("file1.txt");
    loader.addFile("file2.txt");
    loader.load();

    QTimer::singleShot(1000, [&]() {
        EXPECT_EQ(progressBar->value(), 100);
        app.quit();
    });

    app.exec();
}

