#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;

extern "C" void func_ov017_021b6790(void* node);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

#if defined(jpn)
static const int kListOffset=0x4ec, kNodeOffset=0x8e0;
#else
static const int kListOffset=0x6fc, kNodeOffset=0xb00;
#endif

// USA: func_ov017_021b66b8
ARM void AppendNode_021b66b8(char* obj) {
	func_ov017_021b6790(*(void**)(obj + 0x3000 + kNodeOffset));
	AppendNodeToTail((struct TailList020469b4*)*(void**)(obj + 0x3000 + kListOffset),
	                 (struct TailNode020469b4*)*(void**)(obj + 0x3000 + kNodeOffset));
	((unsigned char*)(*(void**)(obj + 0x3000 + kNodeOffset)))[0x1f] = 1;
}
