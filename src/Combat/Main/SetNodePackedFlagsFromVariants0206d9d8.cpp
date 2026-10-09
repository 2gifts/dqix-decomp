#include <globaldefs.h>

#include "Combat/NodeLookup.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct Node0206d9d8;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
};
extern struct Data02108cec data_02108cec;

struct Node0206d9d8 {
    unsigned char pad0[0xa];
    unsigned char flag0xa;
    unsigned char pad1[0x20 - 0xb];
    unsigned short field0x20;
    unsigned char pad2[0x44 - 0x22];
    unsigned short id0x44;
    unsigned char pad3[0x70 - 0x46];
    struct Node0206d9d8* next;
};

// USA: func_0206d9d8
ARM int SetNodePackedFlagsFromVariants0206d9d8(void* param0) {
    struct Node0206d9d8* node;
    int a;
    int b;
    int c;
    int key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    node = (Node0206d9d8*)FindNodeByByteId(data_02108cec.field0x10, key);
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
    a = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 8));
    b = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x10));
    c = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x18));
    node->field0x20 = (unsigned short)(a | (b << 5) | (c << 10));
    node->flag0xa |= 0x80;
    return 1;
}
