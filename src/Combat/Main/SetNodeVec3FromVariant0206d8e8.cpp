#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct Node0206d8e8;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
    void* field0x14;
};
extern struct Data02108cec data_02108cec;

struct Vec3Fixed0206d8e8 {
    int f0;
    int f4;
    int f8;
    int fc;
};

struct Node0206d8e8 {
    unsigned char pad0[0x44];
    unsigned short id0x44;
    unsigned char pad1[0x5c - 0x46];
    struct Vec3Fixed0206d8e8* vec0x5c;
    unsigned char pad2[0x70 - 0x60];
    struct Node0206d8e8* next;
};

// USA: func_0206d8e8
ARM int SetNodeVec3FromVariant0206d8e8(void* param0) {
    struct Node0206d8e8* node;
    int key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    node = (Node0206d8e8*)FindNodeByByteId(data_02108cec.field0x10, key);
    if (node == 0) {
        return 0;
    }
    while (node != 0) {
        if (node->id0x44 == data_02108cec.field0xa) {
            break;
        }
        node = node->next;
    }
    if (node == 0) {
        return 0;
    }
    node->vec0x5c = (struct Vec3Fixed0206d8e8*)((SafeAllocator*)data_02108cec.field0x14)->Allocate(0x10);
    if (node->vec0x5c != 0) {
        node->vec0x5c->fc = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 8)));
        node->vec0x5c->f0 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 0x10)));
        node->vec0x5c->f4 = 0;
        node->vec0x5c->f8 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 0x18)));
    }
    return 1;
}
