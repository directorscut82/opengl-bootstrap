#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
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

std::string
getShaderSourceFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file " + filename + ".");
    }
    
    std::stringstream stream;
    stream << file.rdbuf();
    file.close();
    
    return stream.str();
}

GLuint
initializeShaderFromFile(GLenum shaderType, const std::string &filename)
{
    std::string shaderSource = getShaderSourceFromFile(filename);
    const char *shaderSourceBuffer = shaderSource.c_str();
    
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, (GLchar **)&shaderSourceBuffer, 0);
    glCompileShader(shader);
    return shader;
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
