#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181f30
ARM int QueryAttrM2Idx1_ov000_02181f30(int unused, void* obj, int* out) {
	return func_ov000_021818e0(2, 1, obj, out);
}
