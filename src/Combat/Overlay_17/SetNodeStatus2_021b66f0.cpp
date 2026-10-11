#include <globaldefs.h>

extern "C" void func_ov017_021b6790(void* node);

struct TailList020469b4;
struct TailNode020469b4;
extern void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

#if defined(jpn)
static const int kListOffset=0x4ec, kNodeOffset=0x8e0;
#else
static const int kListOffset=0x6fc, kNodeOffset=0xb00;
#endif

struct Region021b66f0 {
    unsigned char pad[kListOffset];
    TailList020469b4* list;
    unsigned char pad2[kNodeOffset - kListOffset - 4];
    TailNode020469b4* node;
};

// USA: func_ov017_021b66f0
ARM void SetNodeStatus2_021b66f0(unsigned char* base) {
    func_ov017_021b6790(((Region021b66f0*)(base + 0x3000))->node);
    AppendNodeToTail(((Region021b66f0*)(base + 0x3000))->list, ((Region021b66f0*)(base + 0x3000))->node);
    *((unsigned char*)((Region021b66f0*)(base + 0x3000))->node + 0x1f) = 2;
}
