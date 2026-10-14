#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181ec0
ARM int QueryAttrM0Idx5_ov000_02181ec0(int unused, void* obj, int* out) {
    return func_ov000_021818e0(0, 5, obj, out);
}
