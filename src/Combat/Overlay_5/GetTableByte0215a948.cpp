#include <globaldefs.h>

extern unsigned char data_ov005_0215cd18[8];

// USA: func_ov005_0215a948
ARM unsigned char GetTableByte0215a948(void *unused, int index) {
	if ((unsigned int)index >= 8) return 0;
	return data_ov005_0215cd18[index];
}
