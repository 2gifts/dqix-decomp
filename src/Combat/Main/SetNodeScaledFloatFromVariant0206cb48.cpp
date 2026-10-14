#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct TaggedValue02030b44;

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
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Node0206cb48*)FindNodeByByteId_0206db20(data_02108cec.field0x10, key);
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
    node->value0x38 = (int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)param0 + 8)))->ToFloat());
    return 1;
}
