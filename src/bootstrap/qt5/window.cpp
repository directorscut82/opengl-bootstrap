#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "openglsurface.h"
#include "window.h"


namespace bootstrap
{

namespace qt5
{

//      Window class.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

//- Public 'tors.

Window::Window(QWidget *parent)
    : QWidget(parent),
      _layout(new QVBoxLayout),
      _surface(new OpenGLSurface)
{
    // Hack until QTBUG-36899 <https://bugreports.qt-project.org/browse/QTBUG-36899>
    // is being implemented in Qt 5.4.0.
    QWidget *container = QWidget::createWindowContainer(
        _surface, const_cast<Window *>(this));
    
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->addWidget(container);
    setLayout(_layout);
}


//- Public properties.

OpenGLSurface *
Window::surface() const
{
    return _surface;
}

QMenuBar *
Window::menuBar() const
{
    QMenuBar *menuBar = qobject_cast<QMenuBar *>(_layout->menuBar());
    if (!menuBar) {
        Window *self = const_cast<Window *>(this);
        menuBar = new QMenuBar(self);
        menuBar->setNativeMenuBar(false);
        self->setMenuBar(menuBar);
    }
    
    return menuBar;
}

void
Window::setMenuBar(QMenuBar *menuBar)
{
    if (_layout->menuBar() && _layout->menuBar() != menuBar) {
        QMenuBar *old = qobject_cast<QMenuBar *>(_layout->menuBar());
        old->hide();
        old->deleteLater();
    }
    
    _layout->setMenuBar(menuBar);
}

} // namespace qt5.
} // namespace bootstrap.
