#include <globaldefs.h>

struct Obj5d594;
void GetNibbles_0205d594(struct Obj5d594* obj, unsigned char* outLow, unsigned char* outHigh);

struct ElemTarget0205de24 {
    char pad0[0x4];
    void* matched;
    char pad1[0xE0 - 0x8];
};

struct Struct0205de24 {
    char pad0[0x98];
    unsigned char* field98;
    unsigned char* field9C;
    char pad1[0xb2 - 0xa0];
    unsigned char fieldB2;
    char pad2[0xb4 - 0xb3];
    unsigned char fieldB4;
};

// USA: func_0205de24
ARM void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh) {
    if (obj->field98 == 0 || obj->field9C == 0) return;
    struct ElemTarget0205de24* target = (struct ElemTarget0205de24*)(obj->field9C + obj->fieldB4 * 0xE0);
    if (target == 0) return;
    unsigned char* entry;
    unsigned char i = 0;
    unsigned char low, high;
    while (i < obj->fieldB2) {
        entry = obj->field98 + i * 0x20;
        GetNibbles_0205d594((struct Obj5d594*)entry, &low, &high);
        if (low == keyLow && high == keyHigh) {
            target->matched = entry;
            return;
        }
        i++;
    }
}
