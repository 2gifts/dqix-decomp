#include <globaldefs.h>

#if defined(jpn)
#define SUB_POINTER_OFFSET 0x144
#define INDEX_OFFSET 0x8b8
#else
#define SUB_POINTER_OFFSET 0x150
#define INDEX_OFFSET 0x950
#endif

// USA: func_ov023_021e4250
ARM unsigned char GetByteViaFieldIndirectOffset_021e4250_021e4250(char* p) {
	char* q = *(char**)(p + SUB_POINTER_OFFSET);
	return *(unsigned char*)(q + *(int*)(q + INDEX_OFFSET) + 0x186);
}
