#include <globaldefs.h>

int GetByteAtPtrOrZero_02191b58(void);
typedef int (*GetByteAtPtrOrZeroFn1)(void*);

// JPN: func_ov017_02192e74
// USA: func_ov017_021922ac
ARM int CheckByteFlagsAt4488_021922ac(void* self, unsigned int idx) {
#if defined(jpn)
 enum {regionalOffset0=0x41d9, regionalOffset1=0x41d8};
#else
 enum {regionalOffset0=0x4489, regionalOffset1=0x4488};
#endif
	int result = 0;
	unsigned char flagA = *((unsigned char*)self + regionalOffset0);
	if (flagA != 0) {
		int inRange = idx <= 3;
		if (inRange) {
			int b = ((GetByteAtPtrOrZeroFn1)&GetByteAtPtrOrZero_02191b58)(self);
			if (b & 2) result = 1;
		}
		goto checkB;
	}
	result = 1;
checkB:
	if (*((unsigned char*)self + regionalOffset1) == 0) {
		result = 0;
	}
	return result;
}
