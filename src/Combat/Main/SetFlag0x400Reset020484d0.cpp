#include <globaldefs.h>
#include "World/Object3D.h"

// USA: func_020484d0
ARM void SetFlag0x400Reset020484d0(void* obj) {
    ((Object3D*)obj)->Initialize();
    *(unsigned short*)obj |= 0x400;
    *(int*)((char*)obj + 0xb0) = 0;
    *(int*)((char*)obj + 0xac) = 0;
}
