#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181ea4
ARM int QueryAttrM0Idx4_ov000_02181ea4(int unused, void* obj, int* out) {
    return func_ov000_021818e0(0, 4, obj, out);
}
