#include <globaldefs.h>
#include "World/Object3D.h"

// USA: func_0203400c
ARM void ClearStateFlags0203400c(unsigned char* obj) {
    ((Object3D*)obj)->DisableFlag(0x40000);
    obj[0xe0] &= ~0x2;
}
