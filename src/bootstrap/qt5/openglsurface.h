#ifndef BOOTSTRAP_QT5_OPENGLSURFACE_H
#define BOOTSTRAP_QT5_OPENGLSURFACE_H

#include <QtCore/QTime>
#include <QtGui/QWindow>


class QEvent;
class QExposeEvent;
class QOpenGLContext;
class QResizeEvent;
class QScreen;


namespace bootstrap
{

namespace core { class OpenGLRenderer; }


namespace qt5
{

class OpenGLSurface : public QWindow
{
    Q_OBJECT
    Q_PROPERTY(bool alwaysRefresh READ alwaysRefresh WRITE setAlwaysRefresh)
    
public:
    explicit OpenGLSurface(QScreen *screen = 0);
    explicit OpenGLSurface(QWindow *parent);
    virtual ~OpenGLSurface();
    
    bool alwaysRefresh() const;
    void setAlwaysRefresh(bool alwaysRefresh);
    
protected:
    virtual bool event(QEvent *event);
    virtual void exposeEvent(QExposeEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    
private:
    void initialize();
    void render();
    void requestRefresh();
    
    QOpenGLContext *_context;
    core::OpenGLRenderer *_renderer;
    
    bool _alwaysRefresh;
    bool _pendingRefresh;
    QTime _time;
};

} // namespace qt5.
} // namespace bootstrap.

#endif // BOOTSTRAP_QT5_OPENGLSURFACE_H
