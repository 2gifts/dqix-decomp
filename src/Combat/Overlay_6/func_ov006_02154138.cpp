#include <globaldefs.h>

extern "C" void* __clear(void*, int);
extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void*);
int CopyInBattleField0x7540(void*);

// Partial local views: the item IDs and offsets are supported by this routine
// and the neighboring alchemy sources; the complete record meanings are unknown.
struct AlchemyStatus02154138 {
    short item;
    unsigned short selected : 1;
    unsigned short otherFlags : 15;
};
struct AlchemyRecord02154138 {
    short item;
    char unknown02[0x14];
    short field16;
    char unknown18[8];
};
struct AlchemyList02154138 {
    char unknown00[4];
    AlchemyRecord02154138* entries;
    char unknown08[2];
    unsigned short count;
};
struct AlchemyState02154138 {
    AlchemyList02154138* list;
    char unknown04[0x1c];
    AlchemyStatus02154138* statuses;
    unsigned short count;
};
struct AlchemyWork02154138 {
    char unknown00[0x10];
    unsigned int otherFlags : 23;
    unsigned int count : 9;
    char unknown14[0x9c];
};

// Count IDs 1..471 present in both the selected-status scan and the negative
// field16 record scan. Store the count in bits23..31 of the battle work block.
// Signed item IDs index the scratch table; callers must supply valid IDs.
// USA: func_ov006_02154138
extern "C" ARM int func_ov006_02154138(void* context) {
    AlchemyState02154138* state = (AlchemyState02154138*)context;
    if (!state->list) return 0;
    signed char marks[472];
    AlchemyWork02154138 work;
    unsigned short count = 0;
    __clear(marks, sizeof(marks));
    for (unsigned short statusIndex = 0; statusIndex < state->count; statusIndex++) {
        short item = state->statuses[statusIndex].item;
        marks[item] |= state->statuses[statusIndex].selected;
    }
    for (unsigned short recordIndex = 0; recordIndex < state->list->count; recordIndex++) {
        AlchemyRecord02154138* record = (AlchemyRecord02154138*)((unsigned int)state->list->entries + (short)recordIndex * 0x20);
        if (record && record->field16 < 0) marks[record->item] |= 2;
    }
    for (unsigned short itemIndex = 1; itemIndex < 472; itemIndex++) {
        if (marks[itemIndex] == 3) count++;
    }
    _Z23LoadBattleBlock020ac4c0Pv(&work);
    work.count = count;
    CopyInBattleField0x7540(&work);
    return (short)count;
}
