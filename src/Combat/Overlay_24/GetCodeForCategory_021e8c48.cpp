#include <globaldefs.h>

// USA: func_ov024_021e8c48
ARM int GetCodeForCategory_021e8c48(void* unused, signed char category) {
	switch (category) {
		case -1:
			return 0x36;
		case 1:
			return 0x31;
		case 2:
			return 0x32;
		case 3:
			return 0x33;
		case 4:
			return 0x34;
		default:
			return 0x1f;
	}
}
