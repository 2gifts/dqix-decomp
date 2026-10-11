#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
extern "C" int func_ov023_021f6f10(void);

// USA: func_ov004_0215e49c
ARM void SetField38IfState8_0215e49c(void* a, int key, short value) {
	char* node = (char*)func_ov004_0215e47c(a, key);
	if (node == NULL) {
		return;
	}
	int state = func_ov023_021f6f10();
	if (state == 8) {
		*(short*)(node + 0x38) = value;
	}
}
