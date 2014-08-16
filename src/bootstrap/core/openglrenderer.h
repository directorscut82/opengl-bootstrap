#ifndef BOOTSTRAP_CORE_OPENGLRENDERER_H
#define BOOTSTRAP_CORE_OPENGLRENDERER_H


namespace bootstrap
{

namespace core
{

class OpenGLRenderer
{
public:
    OpenGLRenderer(int width, int height);
    ~OpenGLRenderer();
    
    void setup();
    void draw(double time);
    void cleanup();
    
    void setSize(int width, int height);
    
private:
    class Impl;
    Impl *_d;
};

} // namespace core.
} // namespace bootstrap.

#endif // BOOTSTRAP_CORE_OPENGLRENDERER_H
