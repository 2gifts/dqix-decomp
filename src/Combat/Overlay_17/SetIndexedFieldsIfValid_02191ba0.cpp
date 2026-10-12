#include <globaldefs.h>

#if defined(jpn)
enum { ENTRY_UPPER_OFFSET = 0x4100, ENTRY_HALF_OFFSET = 0xee, ENTRY_FLAG_OFFSET = 0x1ec };
#else
enum { ENTRY_UPPER_OFFSET = 0x4400, ENTRY_HALF_OFFSET = 0x9e, ENTRY_FLAG_OFFSET = 0x49c };
#endif


#if defined(jpn)
#define SetIndexedFieldsIfValid_02191ba0 func_ov017_02192768
#endif

// USA: func_ov017_02191ba0
#if defined(jpn)
extern "C"
#endif
ARM void SetIndexedFieldsIfValid_02191ba0(char* base, int index, unsigned short val) {
	int valid = index >= 0 && index <= 3;
	if (!valid) {
		return;
	}
	char* p = base + index * 4;
	*(unsigned short*)(p + ENTRY_UPPER_OFFSET + ENTRY_HALF_OFFSET) = val;
	*(unsigned char*)(p + 0x4000 + ENTRY_FLAG_OFFSET) = 1;
}
