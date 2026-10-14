#include <globaldefs.h>
#include "World/Object3D.h"

// USA: func_02072ac4
ARM void ResetFieldAc(void* obj) {
    ((Object3D*)obj)->Initialize();
    *(int*)((char*)obj + 0xac) = -1;
}
