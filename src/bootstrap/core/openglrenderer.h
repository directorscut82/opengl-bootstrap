#ifndef BOOTSTRAP_CORE_OPENGLRENDERER_H
#define BOOTSTRAP_CORE_OPENGLRENDERER_H


namespace bootstrap
{

namespace core
{

class OpenGLRenderer
{
public:
    OpenGLRenderer();
    ~OpenGLRenderer();
    
    void setup();
    void draw(double time);
    void cleanup();
    
private:
    class Impl;
    Impl *_d;
};

} // namespace core.
} // namespace bootstrap.

#endif // BOOTSTRAP_CORE_OPENGLRENDERER_H
