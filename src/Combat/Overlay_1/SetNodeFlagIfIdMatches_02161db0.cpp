#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void* a);

// USA: func_ov001_02161db0
ARM int SetNodeFlagIfIdMatches_02161db0(void *a) {
#if defined(jpn)
    enum { queueOffset = 0x524, nodeOffset = 0xcc };
#else
    enum { queueOffset = 0x734, nodeOffset = 0xd0 };
#endif
	char* p = *(char**)(func_ov017_0218b5b0() + 0x3000 + queueOffset);
	int id = func_ov017_021d60f4(a);
	char* node = *(char**)(p + nodeOffset);
	while (node != 0) {
		if (*(unsigned char*)(node + 1) == id) {
			*(unsigned char*)(node + 4) |= 1;
			break;
		}
		node = *(char**)(node + 0x34);
	}
	return 1;
}
