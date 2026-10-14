#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181ddc
ARM int QueryAttrM1Idx5_ov000_02181ddc(int unused, void* obj, int* out) {
    return func_ov000_021818e0(1, 5, obj, out);
}
