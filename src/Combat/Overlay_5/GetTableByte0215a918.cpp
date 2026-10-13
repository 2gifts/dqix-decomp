#include <globaldefs.h>

#if defined(jpn)
#define GetTableByte0215a918 func_ov005_0215be48
#define data_ov005_0215cd28 data_ov005_0215e108
#endif


extern unsigned char data_ov005_0215cd28[8];

// USA: func_ov005_0215a918
#if defined(jpn)
extern "C"
#endif
ARM unsigned char GetTableByte0215a918(void *unused, int index) {
	if ((unsigned int)index >= 8) return 0;
	return data_ov005_0215cd28[index];
}
