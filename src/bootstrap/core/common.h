#ifndef BOOTSTRAP_CORE_COMMON_H
#define BOOTSTRAP_CORE_COMMON_H


namespace bootstrap
{

namespace core
{

enum OpenGLProfile {
    OpenGLDefaultProfile = 0,
    OpenGLCoreProfile = 1,
    OpenGLCompatibilityProfile = 2
};

static const int majorVersion = 3;
static const int minorVersion = 2;
static const bool profile = OpenGLCoreProfile;

} // namespace core.
} // namespace bootstrap.

#endif // BOOTSTRAP_CORE_COMMON_H
