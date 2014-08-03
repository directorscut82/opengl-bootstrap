#include <iostream>
#include <stdexcept>

#include <GLFW/glfw3.h>

#include <bootstrap/core/common.h>
#include <bootstrap/core/openglrenderer.h>

#include "application.h"


namespace bootstrap
{

namespace glfw
{

//      Helper functions.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

void errorCallback(int error, const char *description)
{
    std::cerr << description << std::endl;
}



//      Application class.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

//- Public 'tors.

Application::Application()
    : _title("bootstrap"),
      _positionX(0),
      _positionY(0),
      _width(640),
      _height(380)
{}


//- Public properties.

void
Application::setTitle(const std::string &title)
{
    _title = title;
}

void
Application::setPosition(int x, int y)
{
    _positionX = x;
    _positionY = y;
}

void
Application::setSize(int width, int height)
{
    _width = width;
    _height = height;
}


//- Public methods.

int
Application::run()
{
    glfwSetErrorCallback(errorCallback);
    
    if (!glfwInit()) {
        throw std::runtime_error("Could not initialize GLFW.");
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    if (core::profile == core::OpenGLCoreProfile) {
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    else if (core::profile == core::OpenGLCompatibilityProfile) {
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    }
    
    GLFWwindow *window = glfwCreateWindow(_width, _height, _title.c_str(), 0, 0);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Could not initialize the GLFW window.");
    }
    
    glfwSetWindowTitle(window, _title.c_str());
    glfwSetWindowPos(window, _positionX, _positionY);
    glfwSetWindowSize(window, _width, _height);
    
    glfwMakeContextCurrent(window);
    
    core::OpenGLRenderer renderer;
    renderer.setup();
    
    while (!glfwWindowShouldClose(window)) {
        renderer.draw(glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    renderer.cleanup();
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

} // namespace glfw.
} // namespace bootstrap.
