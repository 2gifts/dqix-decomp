#include <globaldefs.h>

extern "C" void* func_ov001_02158e0c(int type);

// USA: func_ov001_021590dc
ARM void* SetTypeAAndField1c_ov001_021590dc(int type, int val) {
	int* p = (int*)func_ov001_02158e0c(type);
	if (p) {
		p[0] = 0xa;
		p[7] = val;
	}
	return p;
}
