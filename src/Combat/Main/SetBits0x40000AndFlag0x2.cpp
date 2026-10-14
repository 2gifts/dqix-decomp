#include <globaldefs.h>
#include "World/Object3D.h"

// USA: func_02033fec
ARM void SetBits0x40000AndFlag0x2(unsigned char* obj) {
    ((Object3D*)obj)->EnableFlag(0x40000);
    obj[0xe0] |= 0x2;
}
