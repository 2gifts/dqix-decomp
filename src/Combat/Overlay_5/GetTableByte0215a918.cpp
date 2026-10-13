#include <globaldefs.h>

extern unsigned char data_ov005_0215cd28[8];

// USA: func_ov005_0215a918
ARM unsigned char GetTableByte0215a918(void *unused, int index) {
	if ((unsigned int)index >= 8) return 0;
	return data_ov005_0215cd28[index];
}
