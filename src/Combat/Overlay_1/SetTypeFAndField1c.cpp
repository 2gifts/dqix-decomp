#include <globaldefs.h>

extern "C" void* func_ov001_02158e4c(int type);

// USA: func_ov001_021591b0
ARM void* SetTypeFAndField1c_ov001_021591b0(int type, int val) {
	int* p = (int*)func_ov001_02158e4c(type);
	if (p) {
		p[0] = 0xf;
		p[7] = val;
	}
	return p;
}
