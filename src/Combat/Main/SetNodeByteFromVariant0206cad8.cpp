#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Node0206cad8;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
};
extern struct Data02108cec data_02108cec;

struct Node0206cad8 {
    unsigned char pad0[0xb];
    unsigned char flag0xb;
    unsigned char pad1[0x38];
    unsigned short id0x44;
    unsigned char pad2[0x2a];
    struct Node0206cad8* next;
};

// USA: func_0206cad8
ARM int SetNodeByteFromVariant0206cad8(void* param0) {
    struct Node0206cad8* node;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Node0206cad8*)FindNodeByByteId(data_02108cec.field0x10, key);
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
    node->flag0xb = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    return 1;
}
