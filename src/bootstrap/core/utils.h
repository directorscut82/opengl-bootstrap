#ifndef BOOTSTRAP_CORE_UTILS_H
#define BOOTSTRAP_CORE_UTILS_H

#include <GLXW/glxw.h>


namespace bootstrap
{

namespace core
{

void setShaderSourceFromFile(GLuint shader, const GLchar *filename);
void checkShaderInfoLog(GLuint shader);

} // namespace core.
} // namespace bootstrap.

#endif // BOOTSTRAP_CORE_UTILS_H
