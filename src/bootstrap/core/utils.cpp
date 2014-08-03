#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <GLXW/glxw.h>


namespace bootstrap
{

namespace core
{

//      Utility functions.
// 
//   C-(''C)
// -----------------------------------------------------------------------------

void
setShaderSourceFromFile(GLuint shader, const GLchar *filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }
    
    std::stringstream stream;
    stream << file.rdbuf();
    file.close();
    
    std::string string = stream.str();
    const char *buffer = string.c_str();
    glShaderSource(shader, 1, (GLchar **)&buffer, 0);
}

void
checkShaderInfoLog(GLuint shader)
{
    GLint logLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 1) {
        GLchar *log = new GLchar[logLength + 1];
        glGetShaderInfoLog(shader, logLength, 0, log);
        std::cerr << log << std::endl;
        delete log;
    }
}

} // namespace core.
} // namespace bootstrap.
