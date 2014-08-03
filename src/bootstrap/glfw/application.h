#ifndef BOOTSTRAP_GLFW_APPLICATION_H
#define BOOTSTRAP_GLFW_APPLICATION_H

#include <string>


namespace bootstrap
{

namespace glfw
{

class Application
{
public:
    Application();
    
    void setTitle(const std::string &title);
    void setPosition(int x, int y);
    void setSize(int width, int height);
    
    int run();
    
private:
    std::string _title;
    int _positionX, _positionY;
    int _width, _height;
};

} // namespace core.
} // namespace bootstrap.

#endif // BOOTSTRAP_GLFW_APPLICATION_H
