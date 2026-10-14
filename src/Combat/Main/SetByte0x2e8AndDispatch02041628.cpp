#include <globaldefs.h>
#include "World/Object3D.h"

// USA: func_02041628
ARM void SetByte0x2e8AndDispatch02041628(void* obj, int v, int) {
    unsigned char* p = (unsigned char*)obj + 0x2e8;
    *p = v;
    ((Object3D*)obj)->MaybeSetBCFGAnimation(*p, 0);
}
