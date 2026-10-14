#include <globaldefs.h>

struct ElemE {
    unsigned char unk0;
    unsigned char flag;
    unsigned char unk2[6];
};

struct ElemB {
    int unk0;
    int unk4;
    int index;
};

struct ElemA {
    int unk0;
    struct ElemB* list;
};

struct LookupBase {
    char unk0[8];
    struct ElemE* arrayE;
    struct ElemA* arrayA;
    char unk10[0x60];
    int indexB;
    int indexA;
    char unk78[0xc];
    unsigned char flag0 : 1;
    unsigned char flagRest : 7;
};

// USA: func_020479b8
ARM unsigned char GetLinkedFlagByte_020479b8(struct LookupBase* base) {
    struct ElemA* a;
    struct ElemB* b;
    struct ElemE* e;
    if (base->flag0 == 0) {
        return 0;
    }
    a = &base->arrayA[base->indexA];
    b = &a->list[base->indexB];
    e = &base->arrayE[b->index];
    return e->flag;
}
