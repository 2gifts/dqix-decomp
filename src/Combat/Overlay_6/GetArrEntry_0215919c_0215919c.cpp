#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

// USA: func_ov006_0215919c
ARM int GetArrEntry_0215919c_0215919c(void* p) {
	int result = 0;
	short idx = *(short*)((char*)p + 0x300 + 0x62) - 0x5b;
	if (idx >= 0) {
		int* arr = *(int**)((char*)p + R(0x40, 0x48));
		result = arr[idx];
	}
	return result;
}
