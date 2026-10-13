#include <globaldefs.h>
#include "Graphics/Vector.h"

#if defined(jpn)
enum { X_OFFSET = 0x4c, Y_OFFSET = 0x4e };
#else
enum { X_OFFSET = 0x50, Y_OFFSET = 0x52 };
#endif

struct ElementPosition_021f7d48 {
    unsigned char unknown0[X_OFFSET];
    short x;
    short y;
};

// USA: func_ov023_021f7d48
ARM Vector3fix GetFixed12PairAndZero_021f7d48(void* element) {
    const ElementPosition_021f7d48* position = (const ElementPosition_021f7d48*)element;
    Vector3fix result;
    result.x = position->x * 4096;
    result.y = position->y * 4096;
    result.z = 0;
    return result;
}
