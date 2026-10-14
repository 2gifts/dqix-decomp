#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181d68
ARM int QueryAttrM1Idx1_ov000_02181d68(int unused, void* obj, int* out) {
    return func_ov000_021818e0(1, 1, obj, out);
}
