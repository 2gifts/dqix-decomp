#include <globaldefs.h>

#include "Combat/NodeLookup.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct Node0206d734;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
};
extern struct Data02108cec data_02108cec;

struct Node0206d734 {
    unsigned char pad0[0xa];
    unsigned char byteField0xa;
    unsigned char pad1[0x44 - 0xb];
    unsigned short id0x44;
    unsigned char pad2[0x60 - 0x46];
    int value0x60;
    unsigned char pad3[0x70 - 0x64];
    struct Node0206d734* next;
};

// USA: func_0206d734
ARM int SetNodeByteAndMaybeScaledFloat0206d734(void* param0, int param1) {
    struct Node0206d734* node;
    int key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    node = (Node0206d734*)FindNodeByByteId(data_02108cec.field0x10, key);
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
    {
        unsigned char v = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 8));
        node->byteField0xa = (node->byteField0xa & ~0x38) | ((v & 7) << 3);
    }
    if (param1 > 2) {
        node->value0x60 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 0x10)));
    }
    return 1;
}
