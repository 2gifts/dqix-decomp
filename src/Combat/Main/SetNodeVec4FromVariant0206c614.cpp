#include <globaldefs.h>

#include "Combat/NodeLookup.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct Node0206c614;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
};
extern struct Data02108cec data_02108cec;

struct Node0206c614 {
    unsigned char pad0[0x1f];
    unsigned char byteField0x1f;
    unsigned char pad1[0x24 - 0x20];
    int value0x24;
    int value0x28;
    int value0x2c;
    int value0x30;
    unsigned char pad2[0x44 - 0x34];
    unsigned short id0x44;
    unsigned char pad3[0x70 - 0x46];
    struct Node0206c614* next;
};

// USA: func_0206c614
ARM int SetNodeVec4FromVariant0206c614(void* param0) {
    struct Node0206c614* node;
    int key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    node = (Node0206c614*)FindNodeByByteId(data_02108cec.field0x10, key);
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
    node->value0x24 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 8)));
    node->value0x28 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 0x10)));
    node->value0x2c = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 0x18)));
    node->value0x30 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 0x20)));
    node->byteField0x1f = 7;
    return 1;
}
