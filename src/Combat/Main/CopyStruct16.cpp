#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201d474
ARM MaybeVector4fix& MaybeVector4fix::CopyFrom_0201d474(const MaybeVector4fix& other) {
    vec3 = other.vec3;
    w = other.w;
    return *this;
}
