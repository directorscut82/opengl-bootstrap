#include <stdexcept>

#include <GLXW/glxw.h>

#include "openglrenderer.h"
#include "utils.h"


namespace bootstrap
{

namespace core
{

//      OpenGLRenderer::Impl class.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

class OpenGLRenderer::Impl
{
public:
    Impl(GLint width, GLint height);
    
    void updateViewport();
    
public:
    bool setup;
    
    GLint width;
    GLint height;
};


//- Public 'tors.

OpenGLRenderer::Impl::Impl(GLint width, GLint height)
    : setup(false),
      width(width),
      height(height)
{}


//- Public members.

void
OpenGLRenderer::Impl::updateViewport()
{
    glViewport(0, 0, width, height);
}



//      OpenGLRenderer class.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

//- Public 'tors.

OpenGLRenderer::OpenGLRenderer(int width, int height)
    : _d(new Impl(width, height))
{}

OpenGLRenderer::~OpenGLRenderer()
{
    delete _d;
}


//- Public methods.

void
OpenGLRenderer::setup()
{
    if (_d->setup) {
        return;
    }
    
    if (glxwInit() != 0) {
        throw std::runtime_error("Could not link with OpenGL through GLXW.");
    }
    
    // -------------------------------------------------------------------------
    
    // Insert the code to setup OpenGL here.
    
    // -------------------------------------------------------------------------
    
    _d->setup = true;
    
    _d->updateViewport();
}

void
OpenGLRenderer::draw(double time)
{
    // -------------------------------------------------------------------------
    
    // Insert the code to draw with OpenGL here.
    
    // -------------------------------------------------------------------------
}

void
OpenGLRenderer::cleanup()
{
    // -------------------------------------------------------------------------
    
    // Insert the code to cleanup OpenGL here.
    
    // -------------------------------------------------------------------------
}

void
OpenGLRenderer::setSize(int width, int height)
{
    _d->width = width;
    _d->height = height;
    if (_d->setup) {
        _d->updateViewport();
    }
}

} // namespace core.
} // namespace bootstrap.
