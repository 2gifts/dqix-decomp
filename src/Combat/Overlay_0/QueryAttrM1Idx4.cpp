#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181dc0
ARM int QueryAttrM1Idx4_ov000_02181dc0(int unused, void* obj, int* out) {
    return func_ov000_021818e0(1, 4, obj, out);
}
