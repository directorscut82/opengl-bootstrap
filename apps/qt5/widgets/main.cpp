#include <QtWidgets/QApplication>

#include "window.h"


int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    Window window;
    window.resize(800, 600);
    window.show();
    return application.exec();
}
