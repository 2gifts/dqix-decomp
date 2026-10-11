#include <globaldefs.h>

#if defined(jpn)
#define REGION_FIELD_0 0x958
#define REGION_FIELD_1 0x4ec
#else
#define REGION_FIELD_0 0xb78
#define REGION_FIELD_1 0x6fc
#endif


extern "C" ARM int func_ov017_0218b5b0(void);
void InitByteHeader_021c1acc(unsigned char* self);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021c1a98  (semantic: CreateAndAppendNode_021c1a98)
extern "C" ARM void func_ov017_021c1a98(void* unused, int val) {
	char* base = (char*)func_ov017_0218b5b0() + 0x3000;
	TailList020469b4* list = *(TailList020469b4**)(base + REGION_FIELD_1);
	unsigned char* node = *(unsigned char**)(base + REGION_FIELD_0);
	InitByteHeader_021c1acc(node);
	*(int*)(node + 0xc) = val;
	AppendNodeToTail(list, (TailNode020469b4*)node);
}
