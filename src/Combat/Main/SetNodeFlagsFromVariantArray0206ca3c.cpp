#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;
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
    int key = ((Script::Parameter*)((struct Variant02030b0c*)orig))->ToInt();
    node = (Node0206ca3c*)FindNodeByByteId_0206db20(data_02108cec.field0x10, key);
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
        node->flags0xc |= ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
        param0 = (char*)param0 + 8;
    }
    return 1;
}
