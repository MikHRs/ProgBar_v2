//
// Created by michele on 17/01/25.
//
#include <gtest/gtest.h>
#include <QApplication>
#include "../mainwindow.h"  // Assicurati che MainWindow sia incluso correttamente
#include "../subjectconcrete.h"

#include <QApplication>
#include "mainwindow.h"
#include "subjectconcrete.h"
#include <gtest/gtest.h>

#include <gtest/gtest.h>
#include <QApplication>
#include "mainwindow.h"
#include "subjectconcrete.h"

#include <gtest/gtest.h>
#include <QApplication>
#include "mainwindow.h"
#include "subjectconcrete.h"

TEST(MainTest, ApplicationStartup) {
    int argc = 0;
    char* argv[] = {nullptr};
    QApplication app(argc, argv);

    ConcreteSubject loader;
    MainWindow window(&loader);

    ASSERT_NE(&window, nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

