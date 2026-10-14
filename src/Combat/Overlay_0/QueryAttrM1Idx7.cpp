#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181e14
ARM int QueryAttrM1Idx7_ov000_02181e14(int unused, void* obj, int* out) {
    return func_ov000_021818e0(1, 7, obj, out);
}
