#include <QtCore/QCoreApplication>
#include <QtCore/QEvent>
#include <QtGui/QExposeEvent>
#include <QtGui/QOpenGLContext>
#include <QtGui/QResizeEvent>
#include <QtGui/QScreen>
#include <QtGui/QSurfaceFormat>

#include <bootstrap/core/common.h>
#include <bootstrap/core/openglrenderer.h>

#include "openglsurface.h"


namespace bootstrap
{

namespace qt5
{

//      OpenGLSurface class.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

//- Public 'tors.

OpenGLSurface::OpenGLSurface(QScreen *screen)
    : QWindow(screen),
      _context(0),
      _renderer(0),
      _alwaysRefresh(false),
      _pendingRefresh(false)
{
    initialize();
}

OpenGLSurface::OpenGLSurface(QWindow *parent)
    : QWindow(parent),
      _context(0),
      _renderer(0),
      _alwaysRefresh(false),
      _pendingRefresh(false)
{
    initialize();
}

OpenGLSurface::~OpenGLSurface()
{
    _renderer->cleanup();
    delete _renderer;
    delete _context;
}


//- Public properties.

bool
OpenGLSurface::alwaysRefresh() const
{
    return _alwaysRefresh;
}

void
OpenGLSurface::setAlwaysRefresh(bool alwaysRefresh)
{
    _alwaysRefresh = alwaysRefresh;
    if (alwaysRefresh) {
        requestRefresh();
    }
}


//- Protected methods.

bool
OpenGLSurface::event(QEvent *event)
{
    switch (event->type()) {
        case QEvent::UpdateRequest:
            _pendingRefresh = false;
            render();
            return true;
        
        default:
            return QWindow::event(event);
    }
}

void
OpenGLSurface::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);
    
    if (isExposed()) {
        render();
    }
}

void
OpenGLSurface::resizeEvent(QResizeEvent *event)
{
    _renderer->setSize(event->size().width() * devicePixelRatio(),
                       event->size().height() * devicePixelRatio());
    requestRefresh();
}


//- Private methods.

void
OpenGLSurface::initialize()
{
    setSurfaceType(QWindow::OpenGLSurface);
    
    QSurfaceFormat format;
    format.setVersion(core::majorVersion, core::minorVersion);
    
    if (core::profile == core::OpenGLCoreProfile) {
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    else if (core::profile == core::OpenGLCompatibilityProfile) {
        format.setProfile(QSurfaceFormat::CompatibilityProfile);
    }
    else {
        format.setProfile(QSurfaceFormat::NoProfile);
    }
    
    setFormat(format);
    create();
    
    _context = new QOpenGLContext(this);
    _context->setFormat(requestedFormat());
    _context->create();
    
    _renderer = new core::OpenGLRenderer(width() * devicePixelRatio(),
                                         height() * devicePixelRatio());
    
    _context->makeCurrent(this);
    _renderer->setup();
    
    _time.start();
}

void
OpenGLSurface::render()
{
    if (!isExposed()) {
        return;
    }
    
    _context->makeCurrent(this);
    _renderer->draw(_time.elapsed());
    _context->swapBuffers(this);
    
    if (_alwaysRefresh) {
        requestRefresh();
    }
}

void
OpenGLSurface::requestRefresh()
{
    if (!_pendingRefresh) {
        _pendingRefresh = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

} // namespace qt5.
} // namespace bootstrap.
