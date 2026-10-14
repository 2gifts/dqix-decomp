#include <globaldefs.h>

extern "C" void* func_ov001_02158e0c(int type);

// USA: func_ov001_0215911c
ARM void* SetTypeCAndField1c_ov001_0215911c(int type, int val) {
	int* p = (int*)func_ov001_02158e0c(type);
	if (p) {
		p[0] = 0xc;
		p[7] = val;
	}
	return p;
}
