#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov001_021539d8(void* self);
extern "C" void func_ov001_02154c64(void* self);
int StoreArgIfMatched_02153948(unsigned short arg);

struct Node1_02155bb8 {
    char pad0[0x2c];
    int field0x2c;
    char pad1[0x31 - 0x30];
    unsigned char field0x31;
    char pad2[0x34 - 0x32];
    struct Node1_02155bb8* next;
};

struct Node2_02155bb8 {
    char pad0[0x24];
    int field0x24;
    struct Node2_02155bb8* next;
    unsigned char field0x2c;
};

struct Self02155bb8 {
    char pad0[0xa];
    unsigned short field0xa;
    char pad1[0x4a - 0xc];
    unsigned short field0x4a;
#if defined(jpn)
    char pad2[0xcc - 0x4c];
#else
    char pad2[0xd0 - 0x4c];
#endif
    struct Node1_02155bb8* field0xd0;
    struct Node2_02155bb8* field0xd4;
    char pad3[0xf4 - 0xd8];
    int field0xf4;
    char pad4[0x100 - 0xf8];
    unsigned char field0x100;
};

// USA: func_ov001_02155bb8  (semantic: CheckPendingListsAndDispatch_02155bb8)
extern "C" ARM int func_ov001_02155bb8(struct Self02155bb8* self) {
    int val = (int)BackgroundLoader::GetInstance();

    struct Node1_02155bb8* n = self->field0xd0;
    while (n) {
        if (n->field0x2c > -1 && n->field0x31 == 0) {
            if (((BackgroundLoader*)((void*)val))->GetTaskStatus((int)(n->field0x2c)) == 0) {
                return self->field0xa;
            }
        }
        n = n->next;
    }

    struct Node2_02155bb8* m = self->field0xd4;
    while (m) {
        if (m->field0x24 > -1 && m->field0x2c == 0) {
            if (((BackgroundLoader*)((void*)val))->GetTaskStatus((int)(m->field0x24)) == 0) {
                return self->field0xa;
            }
        }
        m = m->next;
    }

    if (self->field0xf4 > -1) {
        if (((BackgroundLoader*)((void*)val))->GetTaskStatus((int)(self->field0xf4)) == 0) {
            return self->field0xa;
        }
    }

    func_ov001_021539d8(self);
    if (self->field0x100 == 0) {
        func_ov001_02154c64(self);
        return self->field0xa;
    }
    StoreArgIfMatched_02153948(self->field0x4a);
    return 4;
}
