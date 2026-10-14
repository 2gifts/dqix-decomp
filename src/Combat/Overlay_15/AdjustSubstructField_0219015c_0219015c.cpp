#include <globaldefs.h>

struct IndexNode_0202a9ac {
    char unk[0x34];
    struct IndexNode_0202a9ac* next;
};

struct IndexList_0202a9ac {
    char unk[0x44];
    struct IndexNode_0202a9ac* head;
    char unk2[0x12];
    unsigned short count;
};

struct IndexNode_0202a9ac* GetNodeAtIndex(struct IndexList_0202a9ac* list, int index);
void* GetSubstructAt0x4_02029560(void* base);
extern "C" void* func_ov015_0218f39c(void*, void*);

struct SubField_0219015c {
    char pad[0x10];
    int field0x10;
    int field0x14;
    int field0x18;
};

struct S0219015c {
    void* field0;
    char pad[0x34];
    short field0x38;
};

// USA: func_ov015_0219015c
ARM void AdjustSubstructField_0219015c_0219015c(struct S0219015c* obj, int delta) {
    struct IndexList_0202a9ac* list = (struct IndexList_0202a9ac*)((char*)obj->field0 + 0x2c4);
    struct IndexNode_0202a9ac* node = GetNodeAtIndex(list, obj->field0x38);
    if (node == 0) {
        return;
    }
    void* sub = GetSubstructAt0x4_02029560(node);
    struct SubField_0219015c* q = (struct SubField_0219015c*)func_ov015_0218f39c(obj, sub);
    if (q == 0) {
        return;
    }
    int cap = q->field0x14 - q->field0x10;
    int v = q->field0x18 + delta;
    q->field0x18 = v;
    if (v < 0) {
        q->field0x18 = 0;
    }
    v = q->field0x18;
    if (v > cap) {
        q->field0x18 = cap;
    }
}
