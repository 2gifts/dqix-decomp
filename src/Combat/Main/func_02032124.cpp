#include <globaldefs.h>
#include "System/Matrix.h"

extern "C" fix32_t Vector3fix_InnerProduct(const Vector3fix *a, const Vector3fix *b);

// USA: func_02032124
extern "C" ARM int func_02032124(const Vector3fix *self, const Vector4fix *other) {
    return Vector3fix_InnerProduct(&other->xyz, self) - other->w;
}
