#ifndef BOOTSTRAP_CORE_UTILS_H
#define BOOTSTRAP_CORE_UTILS_H

#include <string>

#include <GLXW/glxw.h>


namespace bootstrap
{

namespace core
{

std::string getShaderSourceFromFile(const std::string &filename);
GLuint initializeShaderFromFile(GLenum shaderType, const std::string &filename);
void checkShaderInfoLog(GLuint shader);

} // namespace core.
} // namespace bootstrap.

#endif // BOOTSTRAP_CORE_UTILS_H
