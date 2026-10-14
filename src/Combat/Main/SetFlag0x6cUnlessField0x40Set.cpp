#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void func_02076a8c(void* p);

// USA: func_02078660
ARM void SetFlag0x6cUnlessField0x40Set_02078660(void* p) {
    if (((Object3D*)p)->GetInheritedAlpha() != 0) return;
    func_02076a8c(p);
    ((Object3D*)p)->MakeHidden();
}
