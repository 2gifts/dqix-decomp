#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);
struct TaggedValue02030b44;
extern "C" struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44*, int*);
extern "C" int func_ov017_0218b5b0(void);

struct Cont0208e778;
struct Node0208e778;
extern "C" void _Z31AppendNodeToCountedList0208e778P12Cont0208e778P12Node0208e778(struct Cont0208e778*, struct Node0208e778*);

extern int data_02108fe4;

struct Entry02108ff4 {
    unsigned short a;
    unsigned char b;
    unsigned char c;
};
extern Entry02108ff4 data_02108ff4[];

struct Bits0208e0c4 {
    unsigned int fieldA : 4;
    unsigned int low9 : 9;
    unsigned int hi4 : 4;
    unsigned int fieldB : 4;
    unsigned int fieldC : 8;
    unsigned int pad1 : 3;
};

struct Node0208e0c4 {
    struct {
        unsigned int reserved0 : 16;
        unsigned int val1 : 7;
        unsigned int val2 : 2;
        unsigned int pad0 : 7;
    } dw0;
    union {
        unsigned int raw;
        struct Bits0208e0c4 b;
    } dw1;
    int dw2;
    int vec[8][3];
    struct Node0208e778* next;
};

// USA: func_0208e0c4
extern "C" ARM int func_0208e0c4(char* v) {
    SafeAllocator* alloc = (SafeAllocator*)(func_ov017_0218b5b0() + 0x1a0);
    struct Node0208e0c4* node = (struct Node0208e0c4*)alloc->Allocate(0x70);
    node->next = 0;
    node->dw0.val1 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)v);
    node->dw0.reserved0 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(v + 8));
    node->dw0.val2 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(v + 0x10));
    node->dw1.b.fieldA = (unsigned char)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(v + 0x20));
    if (node->dw1.b.fieldA == 8) {
        node->dw1.b.low9 = (unsigned short)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(v + 0x28));
        node->dw1.b.hi4 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((Variant02030b0c*)(v + 0x30));
        Variant02030b0c* p38 = (Variant02030b0c*)(v + 0x38);
        v += 0x40;
        node->dw1.b.fieldB = (unsigned char)_ZNK6Script9Parameter5ToIntEv(p38);
    } else {
        unsigned char* tbl = (unsigned char*)data_02108ff4;
        node->dw1.b.low9 = *(unsigned short*)(tbl + node->dw1.b.fieldA * 4);
        node->dw1.b.hi4 = ((Entry02108ff4*)(tbl + node->dw1.b.fieldA * 4))->b;
        v += 0x40;
        node->dw1.b.fieldB = ((Entry02108ff4*)(tbl + node->dw1.b.fieldA * 4))->c;
    }
    for (int i = 0; i < 8; i++) {
        v = (char*)_ZN6Script9Parameter9ToVec3fixEP8Vector3i((TaggedValue02030b44*)v, node->vec[i]);
    }
    node->dw2 = 0;
    node->dw1.raw &= 0xe01fffff;
    _Z31AppendNodeToCountedList0208e778P12Cont0208e778P12Node0208e778((Cont0208e778*)&data_02108fe4, (Node0208e778*)node);
    return 1;
}