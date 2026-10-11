#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_021baedc(void* a, int b);
extern "C" void* func_0205ec34(void);

struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
void SetKeyedArrayBit0206e348(unsigned char* obj, int index, int value);

// USA: func_ov004_02167fd4
ARM int AppendAndSetArrayBit_02167fd4(void) {
#if defined(jpn)
    enum { nodeOffset = 0x524, listOffset = 0x4ec };
#else
    enum { nodeOffset = 0x734, listOffset = 0x6fc };
#endif
	char* base = (char*)func_ov017_0218b5b0() + 0x3000;
	struct TailList020469b4* list = *(struct TailList020469b4**)(base + listOffset);
	struct TailNode020469b4* node = *(struct TailNode020469b4**)(base + nodeOffset);
	func_ov017_021baedc(node, 1);
	*(short*)((char*)node + 0x8) = 0x6fae;
	AppendNodeToTail(list, node);
	unsigned char* p = (unsigned char*)func_0205ec34();
	SetKeyedArrayBit0206e348(p, 0x17, 1);
	return 0;
}
