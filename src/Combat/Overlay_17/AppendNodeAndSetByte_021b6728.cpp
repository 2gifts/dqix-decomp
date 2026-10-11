#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;

extern "C" void func_ov017_021b6790(void* node);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// JPN: func_ov017_021b6cdc
// USA: func_ov017_021b6728  (semantic: AppendNodeAndSetByte_021b6728)
extern "C" ARM void func_ov017_021b6728(char* obj, int mode, unsigned char val) {
#if defined(jpn)
 enum {regionalOffset0=0x8e0, regionalOffset1=0x4ec};
#else
 enum {regionalOffset0=0xb00, regionalOffset1=0x6fc};
#endif
	func_ov017_021b6790(*(void**)(obj + 0x3000 + regionalOffset0));
	AppendNodeToTail((struct TailList020469b4*)*(void**)(obj + 0x3000 + regionalOffset1),
	                 (struct TailNode020469b4*)*(void**)(obj + 0x3000 + regionalOffset0));
	if (mode == 1) {
		((unsigned char*)(*(void**)(obj + 0x3000 + regionalOffset0)))[0x1f] = 4;
		((unsigned char*)(*(void**)(obj + 0x3000 + regionalOffset0)))[0x20] = val;
	} else if (mode == 0) {
		((unsigned char*)(*(void**)(obj + 0x3000 + regionalOffset0)))[0x1f] = 3;
	}
}
