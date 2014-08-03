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
    Impl();
    
public:
    bool setup;
};


//- Public 'tors.

OpenGLRenderer::Impl::Impl()
    : setup(false)
{}



//      OpenGLRenderer class.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

//- Public 'tors.

OpenGLRenderer::OpenGLRenderer()
    : _d(new Impl)
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

} // namespace core.
} // namespace bootstrap.
