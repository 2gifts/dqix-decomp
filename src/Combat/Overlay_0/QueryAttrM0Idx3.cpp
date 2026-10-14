#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181e88
ARM int QueryAttrM0Idx3_ov000_02181e88(int unused, void* obj, int* out) {
    return func_ov000_021818e0(0, 3, obj, out);
}
