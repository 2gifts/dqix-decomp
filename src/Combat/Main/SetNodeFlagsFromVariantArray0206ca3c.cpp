#include <globaldefs.h>

#include "Combat/NodeLookup.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct Node0206ca3c;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
};
extern struct Data02108cec data_02108cec;

struct Node0206ca3c {
    unsigned char pad0[0xc];
    unsigned int flags0xc;
    unsigned char pad1[0x44 - 0x10];
    unsigned short id0x44;
    unsigned char pad2[0x70 - 0x46];
    struct Node0206ca3c* next;
};

// USA: func_0206ca3c
ARM int SetNodeFlagsFromVariantArray0206ca3c(void* param0, int count) {
    struct Node0206ca3c* node;
    void* orig = param0;
    int i;
    param0 = (char*)param0 + 8;
    int key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)orig);
    node = (Node0206ca3c*)FindNodeByByteId(data_02108cec.field0x10, key);
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
    for (i = 0; i < count - 1; i++) {
        node->flags0xc |= _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
        param0 = (char*)param0 + 8;
    }
    return 1;
}
