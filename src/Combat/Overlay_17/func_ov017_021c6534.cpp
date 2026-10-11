#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct Nibbles021c6534 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct EvtData021c6534 {
    unsigned short key;
    unsigned short ids[3];
    unsigned char vals[3];
    Nibbles021c6534 nibbles[3];
    unsigned char mode;
};

struct Evt021c6534 {
    unsigned char pad0[4];
    EvtData021c6534 data;
};

struct Field021c6534 {
    unsigned char pad0[8];
    unsigned short key;
    unsigned char pad0a[0x2a - 0x0a];
    signed char field_0x2a;
};

struct Slot021c6534 {
    unsigned short id;
    unsigned char pad2[0xa - 0x2];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char val;
    unsigned char pad0c[0x18 - 0x0c];
};

struct Party021c6534 {
    unsigned char sumLo;
    unsigned char sumHi : 4;
    unsigned char count : 2;
    unsigned char mode : 2;
    unsigned char pad2[2];
    Slot021c6534 slots[3];
};

// JPN: func_ov017_021c69e4
// USA: func_ov017_021c6534
extern "C" ARM void func_ov017_021c6534(int unused0, Evt021c6534* evt, GameState* battleStruct, char* base) {
#if defined(jpn)
 enum { regionalOffset = 0x508 };
#else
 enum { regionalOffset = 0x718 };
#endif
    void* table = *(void**)(base + 0x3000 + regionalOffset);

    Field021c6534* fieldObj = (Field021c6534*)func_ov017_021b8478(table);
    if (!fieldObj) return;

    void* state = _Z20GetField6b0_021b8470Pv(table);
    if (!state) return;

    if (fieldObj->field_0x2a == GetField0x3acValue(battleStruct)) return;
    EvtData021c6534* data = &evt->data;
    if (fieldObj->key != data->key) return;

    Party021c6534* party = (Party021c6534*)((char*)state + 0x1b0 + 0x8000);
    unsigned char lo[3];
    unsigned char hi[3];
    lo[0] = data->nibbles[0].lo;
    lo[1] = data->nibbles[1].lo;
    lo[2] = data->nibbles[2].lo;
    hi[0] = data->nibbles[0].hi;
    hi[1] = data->nibbles[1].hi;
    hi[2] = data->nibbles[2].hi;

    int count = 0;
    int sumLo = 0;
    int sumHi = 0;
    for (int i = 0; i < 3; i++) {
        Slot021c6534* slot = &party->slots[i];
        slot->id = data->ids[i];
        slot->val = data->vals[i];
        slot->lo = lo[i];
        slot->hi = hi[i];
        if (slot->id != 0) {
            count++;
            sumLo += slot->lo;
            sumHi += slot->hi;
        }
    }
    party->count = count;
    party->mode = data->mode;
    party->sumLo = sumLo;
    party->sumHi = sumHi;
}
