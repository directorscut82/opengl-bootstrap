#include <bootstrap/glfw/application.h>


int main(int argc, char* argv[])
{
    bootstrap::glfw::Application application;
    application.setSize(800, 600);
    return application.run();
}
