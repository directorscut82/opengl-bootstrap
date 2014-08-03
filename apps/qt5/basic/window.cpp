#include <QtGui/QScreen>
#include <QtGui/QWindow>

#include <bootstrap/qt5/openglsurface.h>

#include "window.h"


//      Window class.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

//- Public 'tors.

Window::Window(QScreen *screen)
    : bootstrap::qt5::OpenGLSurface(screen)
{
    initialize();
}

Window::Window(QWindow *parent)
    : bootstrap::qt5::OpenGLSurface(parent)
{
    initialize();
}


//- Private methods.

void
Window::initialize()
{
    setAlwaysRefresh(true);
}
