#include <globaldefs.h>
#include "World/Object3D.h"

// USA: func_02041640
ARM void SetWord0x2f4AndDispatch02041640(void* obj, int v, int) {
    int* p = (int*)((char*)obj + 0x2f4);
    *p = v;
    ((Object3D*)obj)->MaybeSetRegularAnimation((char const*)(*p), 0);
}
