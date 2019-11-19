#include <iostream>
#include <QApplication>
#include "RenderWindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    RenderWindow window(NULL);
    window.resize(600, 600);
    window.show();
    return app.exec();
}