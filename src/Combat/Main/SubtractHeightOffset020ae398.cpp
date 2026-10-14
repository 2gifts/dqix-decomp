#include <globaldefs.h>
#include "System/Matrix.h"

struct Entity020AE398 {
    char pad0[0x44];
    Vector3i vec44;
    char pad1[0x168 - 0x44 - 12];
    int field168;
    char pad2[0x178 - 0x168 - 4];
    int field178;
};

// USA: func_020ae398
ARM void SubtractHeightOffset020ae398(struct Entity020AE398* obj) {
    Vector3i local;
    local = obj->vec44;
    local.y -= 0x199;
    obj->vec44 = local;
    obj->field168 -= 0x199;
    obj->field178 -= 0x199;
}
