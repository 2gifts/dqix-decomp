#include <globaldefs.h>

struct S_b284 {
	char pad[0x39];
	unsigned char val;
};

// USA: func_ov023_021fb284
ARM void SetByteField39_021fb284(S_b284* obj, int v) {
	obj->val = v;
}
