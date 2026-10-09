#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct VariantNodeTag0x73 {
    int tag;
    int unused;
    int value;
    unsigned short id;
    unsigned char flag;
};

// USA: func_ov000_0216c85c
extern "C" ARM int func_ov000_0216c85c(struct Variant02030b0c* v, int count) {
    struct VariantNodeTag0x73* node = (struct VariantNodeTag0x73*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x73));
    if (node == NULL) {
        return 0;
    }
    unsigned short id;
    int value;
    unsigned char flag;
    value = _ZNK6Script9Parameter5ToIntEv(&v[0]);
    id = _ZNK6Script9Parameter5ToIntEv(&v[1]);
    flag = 0;
    if (count >= 3) {
        flag = _ZNK6Script9Parameter5ToIntEv(&v[2]);
    }
    node->value = value;
    node->id = id - 0x1a;
    node->flag = flag;
    node->tag = 0x73;
    func_ov000_02169b78(node);
    return 1;
}
