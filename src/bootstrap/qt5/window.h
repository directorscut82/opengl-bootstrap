#ifndef BOOTSTRAP_QT5_WINDOW_H
#define BOOTSTRAP_QT5_WINDOW_H

#include <QtWidgets/QWidget>


class QMenuBar;
class QVBoxLayout;


namespace bootstrap
{

namespace qt5
{

class OpenGLSurface;


class Window : public QWidget
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    
    OpenGLSurface * surface() const;
    
    QMenuBar * menuBar() const;
    void setMenuBar(QMenuBar *menuBar);
    
private:
    QVBoxLayout *_layout;
    OpenGLSurface *_surface;
};

} // namespace qt5.
} // namespace bootstrap.

#endif // BOOTSTRAP_QT5_WINDOW_H
