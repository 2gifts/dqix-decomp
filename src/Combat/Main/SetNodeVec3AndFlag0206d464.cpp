#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Node0206d464;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
};
extern struct Data02108cec data_02108cec;

struct TaggedValue02030b44;
struct Vector3i;

struct Node0206d464 {
    unsigned char pad0[0xc];
    int fieldC;
    unsigned char pad1[0x44 - 0x10];
    unsigned short id0x44;
    unsigned char pad2[0x48 - 0x46];
    int outVec[3];
    unsigned char pad3[0x70 - 0x54];
    struct Node0206d464* next;
};

// USA: func_0206d464  (semantic: SetNodeVec3AndFlag0206d464)
extern "C" ARM int func_0206d464(void* param0) {
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    struct Node0206d464* node = (Node0206d464*)FindNodeByByteId_0206db20(data_02108cec.field0x10, key);
    if (node == 0) return 0;
    while (node != 0) {
        if (node->id0x44 == data_02108cec.field0xa) break;
        node = node->next;
    }
    if (node == 0) return 0;
    node->fieldC = node->fieldC | 0x2000;
    (TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)((char*)param0 + 8)))->ToVec3fix((Vector3i*)node->outVec);
    return 1;
}
