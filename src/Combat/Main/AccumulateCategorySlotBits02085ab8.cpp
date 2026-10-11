#include <globaldefs.h>
#include "GameState/GameState.h"

int TestBitInArray0x8ec(unsigned char* obj, int index);
int GetSlotBits0201137c(char* base, int id);

struct Param2085ab8 {
    unsigned char pad[0x18];
    unsigned int lowBits : 12;
    unsigned int category : 4;
    unsigned int highBits : 16;
};

struct Field29c {
    unsigned int lowBits : 4;
    unsigned int val5 : 5;
    unsigned int highBits : 23;
};

struct SlotEntry020e8c00 {
    int key;
    int val;
};
extern struct SlotEntry020e8c00 data_020e8c00[];


#if defined(jpn)
enum { CategoryFlagOffset = 0x860 };
#else
enum { CategoryFlagOffset = 0x8f8 };
#endif

// JPN: func_020863d8
// USA: func_02085ab8
ARM int AccumulateCategorySlotBits02085ab8(unsigned char* actor, struct Param2085ab8* p2) {
    GameState* bs = GameState::GetInstance();
    unsigned int category = p2->category;
    if (category == 2) {
        if ((actor[CategoryFlagOffset] & 0x80) == 0) {
            return 0;
        }
        return GetSlotBits0201137c((char*)bs, 0x67);
    }

    int threshold = 0x21;
    if (*(short*)(actor + 0x2ac) > 0) {
        threshold = ((struct Field29c*)(actor + 0x29c))->val5;
    }

    int matched = -1;
    struct SlotEntry020e8c00* entry = data_020e8c00;
    while (entry->key != matched) {
        if (entry->key == threshold) {
            matched = (short)entry->val;
            break;
        }
        entry++;
    }

    int total = 0;
    if (matched != -1) {
        if (TestBitInArray0x8ec(actor, matched)) {
            total += GetSlotBits0201137c((char*)bs, matched);
        }
    }
    return total;
}
