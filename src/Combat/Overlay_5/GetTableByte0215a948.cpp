#include <globaldefs.h>

#if defined(jpn)
#define GetTableByte0215a948 func_ov005_0215be78
#define data_ov005_0215cd18 data_ov005_0215e0f8
#endif


extern unsigned char data_ov005_0215cd18;

// USA: func_ov005_0215a948
#if defined(jpn)
extern "C"
#endif
ARM unsigned char GetTableByte0215a948(void *unused, int index) {
	if ((unsigned int)index >= 8) return 0;
	return (&data_ov005_0215cd18)[index];
}
