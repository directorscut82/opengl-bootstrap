#ifndef BOOTSTRAP_APPS_QT5_WIDGETS_WINDOW_H
#define BOOTSTRAP_APPS_QT5_WIDGETS_WINDOW_H

#include <bootstrap/qt5/window.h>


class QWidget;


class Window : public bootstrap::qt5::Window
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    
private:
    void createMenus();
};

#endif // BOOTSTRAP_APPS_QT5_WIDGETS_WINDOW_H
