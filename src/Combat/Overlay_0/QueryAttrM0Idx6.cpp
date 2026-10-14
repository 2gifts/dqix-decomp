#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181edc
ARM int QueryAttrM0Idx6_ov000_02181edc(int unused, void* obj, int* out) {
    return func_ov000_021818e0(0, 6, obj, out);
}
