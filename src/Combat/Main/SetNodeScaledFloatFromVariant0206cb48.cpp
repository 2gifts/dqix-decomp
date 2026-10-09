#include <globaldefs.h>

#include "Combat/NodeLookup.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct Node0206cb48;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
};
extern struct Data02108cec data_02108cec;

struct Node0206cb48 {
    unsigned char pad0[0x38];
    int value0x38;
    unsigned char pad1[0x44 - 0x3c];
    unsigned short id0x44;
    unsigned char pad2[0x70 - 0x46];
    struct Node0206cb48* next;
};

// USA: func_0206cb48  (semantic: SetNodeScaledFloatFromVariant0206cb48)
extern "C" ARM int func_0206cb48(void* param0) {
    struct Node0206cb48* node;
    int key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    node = (Node0206cb48*)FindNodeByByteId(data_02108cec.field0x10, key);
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
    node->value0x38 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 8)));
    return 1;
}
