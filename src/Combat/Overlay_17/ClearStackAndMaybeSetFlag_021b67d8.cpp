#if defined(jpn)
enum {regionalOffset0=0x4ec, regionalOffset1=0x524, regionalOffset2=0xc8};
#else
enum {regionalOffset0=0x6fc, regionalOffset1=0x734, regionalOffset2=0xcc};
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void PopStack0AndTrigger(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern "C" void func_020a0c0c(void);
extern "C" void* func_ov017_0218b5b0(void);
struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void* func_0202ae18(void);

extern int data_02114e20;

struct Obj021b67d8 {
    unsigned char pad0[0x8];
    SafeAllocator allocator;
    unsigned char pad24[0x24 - 0x8 - sizeof(SafeAllocator)];
    void* field24;
};

struct Ctx021b67d8 {
    unsigned char pad0[regionalOffset0];
    struct ListHead02046b60* list6fc;
    unsigned char pad734[regionalOffset1 - regionalOffset0 - 4];
    unsigned char* field734;
};

// JPN: func_ov017_021b6d8c
// USA: func_ov017_021b67d8  (semantic: ClearStackAndMaybeSetFlag_021b67d8)
extern "C" ARM void func_ov017_021b67d8(struct Obj021b67d8* self) {
    if (self->field24 != NULL) {
        self->field24 = NULL;
        PopStack0AndTrigger(1);
    }

    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }

    func_020a0c0c();

    int flag = 1;
    struct Ctx021b67d8* ctx = (struct Ctx021b67d8*)((char*)func_ov017_0218b5b0() + 0x3000);
    struct ListHead02046b60* list = ctx->list6fc;
    unsigned char* field = ctx->field734;

    if (ListContainsId(list, 0x18) != 0) {
        flag = 0;
    }
    if (ListContainsId(list, 4) != 0) {
        if (field[regionalOffset2] == 1) {
            flag = 0;
        }
    }
    if (flag == 0) {
        return;
    }

    char* q = (char*)func_0202ae18();
    q[0x1000 + 0x11] = 1;
}
