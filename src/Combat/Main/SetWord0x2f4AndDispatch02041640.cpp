#include <globaldefs.h>

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void*, int, int);

// USA: func_02041640
ARM void SetWord0x2f4AndDispatch02041640(void* obj, int v, int) {
    int* p = (int*)((char*)obj + 0x2f4);
    *p = v;
    _ZN8Object3D24MaybeSetRegularAnimationEPKci(obj, *p, 0);
}
