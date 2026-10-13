#include <globaldefs.h>

extern "C" void _ZN8Object3D21MaybeSetBCFGAnimationEii(void*, int, int);

// USA: func_02041628
ARM void SetByte0x2e8AndDispatch02041628(void* obj, int v, int) {
    unsigned char* p = (unsigned char*)obj + 0x2e8;
    *p = v;
    _ZN8Object3D21MaybeSetBCFGAnimationEii(obj, *p, 0);
}
