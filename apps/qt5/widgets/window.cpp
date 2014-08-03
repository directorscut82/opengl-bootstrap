#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

#include <bootstrap/qt5/openglsurface.h>
#include <bootstrap/qt5/window.h>

#include "window.h"


//      Window class.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

//- Public 'tors.

Window::Window(QWidget *parent)
    : bootstrap::qt5::Window(parent)
{
    createMenus();
    surface()->setAlwaysRefresh(true);
}


//- Private methods.

void
Window::createMenus()
{
    //
    // File menu.
    //
    
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    
    // Quit.
    QAction *quitAction = new QAction(tr("Q&uit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    quitAction->setStatusTip(tr("Quit the application"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu->addAction(quitAction);
}
