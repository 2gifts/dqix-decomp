#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44;
extern "C" struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44* obj, int* outVec);

struct Node0206c82c;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
    void* field0x14;
};
extern struct Data02108cec data_02108cec;

struct SubNode0206c82c {
    int vec[3];
    int flag0xc;
    struct SubNode0206c82c* next;
};

struct Node0206c82c {
    unsigned char pad0[0x1f];
    unsigned char byte1f;
    unsigned char pad1[0x22 - 0x20];
    unsigned char byte22;
    unsigned char pad2[0x34 - 0x23];
    struct SubNode0206c82c* head0x34;
    unsigned char pad3[0x44 - 0x38];
    unsigned short id0x44;
    unsigned char pad4[0x70 - 0x46];
    struct Node0206c82c* next;
};

// USA: func_0206c82c  (semantic: AllocateAndLinkVec3PointList0206c82c)
extern "C" ARM int func_0206c82c(void* param0, int param1) {
    struct Node0206c82c* node;
    int count;
    struct SubNode0206c82c* prev;
    int i;
    struct SubNode0206c82c* newNode;
    void* orig = param0;
    int key;

    param0 = (char*)param0 + 8;
    key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)orig);
    node = (Node0206c82c*)FindNodeByByteId(data_02108cec.field0x10, key);
    if (node == 0) {
        return 0;
    }
    if ((param1 - 1) % 3 != 0) {
        return 0;
    }
    while (node != 0) {
        if (node->id0x44 == data_02108cec.field0xa) break;
        node = node->next;
    }
    if (node == 0) {
        return 0;
    }
    node->byte1f = 9;
    count = (param1 - 1) / 3;
    prev = 0;
    node->byte22 = (unsigned char)(count - 1);
    for (i = 0; i < count; i++) {
        newNode = (struct SubNode0206c82c*)((SafeAllocator*)data_02108cec.field0x14)->Allocate(0x14);
        if (newNode == 0) {
            return 0;
        }
        param0 = (void*)_ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)param0, newNode->vec);
        newNode->flag0xc = 0;
        if (prev == 0) {
            node->head0x34 = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    prev->next = node->head0x34;
    prev->flag0xc = 1;
    return 1;
}
