#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov001_02158dcc(int type);

// USA: func_ov001_0215905c
ARM void* SetType7AndField1c(int type, int val) {
	int* p = (int*)func_ov001_02158dcc(type);
	if (p) {
		p[0] = 7;
		p[7] = val;
	}
	return p;
}
