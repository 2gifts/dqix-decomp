#include <globaldefs.h>

// USA: func_ov000_02171a60
ARM int IsFlag0x28Bit0Set_ov000_02171a60(void* obj) {
	return (*(int*)((char*)obj + 0x28) & 1) != 0;
}
