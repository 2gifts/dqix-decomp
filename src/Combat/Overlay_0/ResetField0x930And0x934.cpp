#include <globaldefs.h>

// USA: func_ov000_02180b3c
ARM void ResetField0x930And0x934_ov000_02180b3c(void* obj) {
	*(int*)((char*)obj + 0x934) = 0;
	*(int*)((char*)obj + 0x930) = 0x180;
}
