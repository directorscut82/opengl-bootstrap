#ifndef BOOTSTRAP_APPS_QT5_BASIC_WINDOW_H
#define BOOTSTRAP_APPS_QT5_BASIC_WINDOW_H

#include <bootstrap/qt5/openglsurface.h>


class QScreen;
class QWindow;


class Window : public bootstrap::qt5::OpenGLSurface
{
    Q_OBJECT
    
public:
    explicit Window(QScreen *screen = 0);
    explicit Window(QWindow *parent);
    
private:
    void initialize();
};

#endif // BOOTSTRAP_APPS_QT5_BASIC_WINDOW_H
