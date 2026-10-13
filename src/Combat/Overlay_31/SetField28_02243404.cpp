#include <globaldefs.h>

extern int data_ov031_02291e04;

#if defined(jpn)
enum { kFlagOffset = 0x24 };
#else
enum { kFlagOffset = 0x1c };
#endif

// USA: func_ov031_02243404
ARM void SetField28_02243404(void) {
	*(int*)((char*)&data_ov031_02291e04 + kFlagOffset) = 1;
}
