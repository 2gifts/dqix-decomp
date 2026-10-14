#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181d88
ARM int QueryAttrM1Idx2_ov000_02181d88(int unused, void* obj, int* out) {
    return func_ov000_021818e0(1, 2, obj, out);
}
