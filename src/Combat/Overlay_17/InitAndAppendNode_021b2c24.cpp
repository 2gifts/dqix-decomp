#include <globaldefs.h>

struct TailNode020469b4;
struct TailList020469b4;
extern "C" void func_ov017_021b2c4c(void* a);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

#if defined(jpn)
#define NODE_OFFSET 0x3528
#define NODE_TAIL 0x528
#define LIST_TAIL 0x4ec
#else
#define NODE_OFFSET 0x3738
#define NODE_TAIL 0x738
#define LIST_TAIL 0x6fc
#endif

// USA: func_ov017_021b2c24  (semantic: InitAndAppendNode_021b2c24)
extern "C" ARM void func_ov017_021b2c24(char* p) {
	func_ov017_021b2c4c(*(void**)(p + NODE_OFFSET));
	char* base = p + 0x3000;
	void* list = *(void**)(base + LIST_TAIL);
	void* node = *(void**)(base + NODE_TAIL);
	AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
}
