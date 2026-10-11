#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

// USA: func_ov006_021591c4
ARM int GetArrEntry_021591c4_021591c4(void* p) {
	int result = 0;
	short idx = *(short*)((char*)p + 0x300 + 0x62) - 0x5b;
	if (idx >= 0) {
		int* arr = *(int**)((char*)p + R(0x44, 0x4c));
		result = arr[idx];
	}
	return result;
}
