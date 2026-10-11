#include <globaldefs.h>

// USA: func_ov023_021dce88
ARM void ClearField784Array3_021dce88(void* obj) {
	for (int i = 0; i < 3; i++) {
		*(int*)((char*)obj + i * 4
#if defined(jpn)
            + 0x700
#else
            + 0x784
#endif
) = 0;
	}
}
