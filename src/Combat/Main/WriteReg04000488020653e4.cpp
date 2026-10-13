#include <globaldefs.h>
#include "System/Graphics.h"
#include "System/Matrix.h"

// USA: func_020653e4
extern "C" ARM void func_020653e4(fix32_t s, fix32_t t) {
    short s12_4 = s >> 8;
    short t12_4 = t >> 8;
    GXFIFO_VERTEX_TEXCOORD = static_cast<unsigned short>(s12_4) |
                            (static_cast<unsigned int>(static_cast<unsigned short>(t12_4)) << 16);
}
