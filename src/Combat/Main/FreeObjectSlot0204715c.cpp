#include <globaldefs.h>
#include "World/Object3D.h"

// USA: func_0204715c
ARM void FreeObjectSlot0204715c(char* obj) {
    void* p = *(void**)(obj + 0xe8);
    if (p != NULL) {
        ((Object3D*)p)->Draw(1);
        return;
    }
    if (*(unsigned char*)(obj + 0x1d) != 0) {
        ((Object3D*)(obj + 0x3c))->Draw(1);
    }
}
