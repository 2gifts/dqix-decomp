// JPN: func_ov017_021a84c8
#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, RegionOffset718 = 0x508 };
#else
enum { RegionOffset6fc = 0x6fc, RegionOffset718 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned short* func_02012fe4(void* p);
struct ListHead02046b60;
extern int ListContainsId(struct ListHead02046b60* list, int id);
struct ListHead02046b38;
struct ListNode02046b38;
int ListContainsNode(struct ListHead02046b38* list, struct ListNode02046b38* target);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_021b7104(void* node, void* out);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Ctx021a7b38 {
    char pad0[0x1];
    unsigned char byte1;
    char pad1[0x8 - 0x2];
    int count8;
    char pad2[0x1a - 0xc];
    unsigned char byte1a;
    char pad3[0x20 - 0x1b];
    int field20;
};

// USA: func_ov017_021a7b38
ARM void RegisterEntryInList_021a7b38(struct Ctx021a7b38* self) {
    GameState::GetInstance();
    char* base = (char*)(long)((int)func_ov017_0218b5b0()) + 0x3000;
    struct ListHead02046b60* list = *(struct ListHead02046b60**)(base + RegionOffset6fc);
    struct ListNode02046b38* node = *(struct ListNode02046b38**)(base + RegionOffset718);
    unsigned short id = *func_02012fe4(base);
    if (self->count8 != 0) {
        return;
    }
    if (ListContainsId((struct ListHead02046b60*)list, 0x3)) {
        self->byte1 = 1;
        return;
    }
    if (self->byte1a != 0) {
        int q = _s32_div_f(id, 0x64);
        if (q * 0x64 != 0x170c && id != 0x2710) {
            self->byte1 = 1;
            return;
        }
    }
    if (!ListContainsNode((struct ListHead02046b38*)list, node)) {
        self->field20 = 1;
        func_ov017_021b6f18(node);
        func_ov017_021b7104(node, (char*)self + 0xc);
        AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
    }
    self->count8 = self->count8 + 1;
    self->byte1 = 1;
}
