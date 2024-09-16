#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <thread>
#include <chrono>
#include "subject.h"
class ProgressbarBarObservers : public Observer{
private:
    QProgressBar* progressBar;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
