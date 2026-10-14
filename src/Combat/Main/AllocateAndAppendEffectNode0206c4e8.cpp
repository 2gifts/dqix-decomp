#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct TaggedValue02030b44;

struct Node0206c4e8;

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
    void* field0x14;
};
extern struct Data02108cec data_02108cec;

struct Effect0206c4e8 {
    int tag;
    int f4;
    int f8;
    int fc;
    int f10;
    struct Effect0206c4e8* next;
};

struct Node0206c4e8 {
    unsigned char pad0[0x40];
    struct Effect0206c4e8* head0x40;
    unsigned short id0x44;
    unsigned char pad2[0x70 - 0x46];
    struct Node0206c4e8* next;
};

// USA: func_0206c4e8
ARM int AllocateAndAppendEffectNode0206c4e8(void* param0) {
    struct Node0206c4e8* node;
    struct Effect0206c4e8* eff;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Node0206c4e8*)FindNodeByByteId(data_02108cec.field0x10, key);
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

    eff = (struct Effect0206c4e8*)((SafeAllocator*)data_02108cec.field0x14)->Allocate(0x18);
    eff->f4 = (int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)param0 + 8)))->ToFloat());
    eff->f8 = (int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)param0 + 0x10)))->ToFloat());
    eff->fc = (int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)param0 + 0x18)))->ToFloat());
    eff->f10 = (int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)param0 + 0x20)))->ToFloat());
    eff->tag = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x28)))->ToInt();
    eff->next = 0;

    if (node->head0x40 == 0) {
        node->head0x40 = eff;
        return 1;
    }
    {
        struct Effect0206c4e8* tail = node->head0x40;
        while (tail->next != 0) {
            tail = tail->next;
        }
        tail->next = eff;
    }
    return 1;
}
