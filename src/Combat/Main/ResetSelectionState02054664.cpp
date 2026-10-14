#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void func_02037d10(void *obj);

struct Obj02054664 {
    unsigned short field0;
    #if defined(jpn)
    char pad2[0x2c2];
#else
    char pad2[0x2ce];
#endif
    signed char b2d0;
    signed char b2d1;
    signed char b2d2;
};

// USA: func_02054664
ARM void ResetSelectionState02054664(struct Obj02054664 *obj) {
    func_02037d10(obj);
    obj->field0 |= 0x1000;
    obj->b2d0 = -1;
    obj->b2d1 = -1;
    obj->b2d2 = 0;
    ((Object3D*)((unsigned char *)obj))->EnableFlag(0x80);
}
