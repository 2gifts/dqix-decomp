#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Id12_021e57e0 {
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Rec_021e57e0 {
    char pad0[4];
    struct Id12_021e57e0 f4;
};

struct Node_021e57e0 {
    char pad0[0x14];
    unsigned char slots[3];
    unsigned char slotCount;
};

struct List021600f8;

struct Act_021e57e0 {
    int f0;
    struct List021600f8* f4;
    void* f8;
    char pad0[4];
    void* f10;
};

struct OutStruct0215ccbc;

extern "C" struct Node_021e57e0* _Z22GetNodeAtIndex021600f8P12List021600f8i(struct List021600f8* list, int index);
extern "C" short func_ov000_0215a004(void* world, int id1, int id2, int value, unsigned long long* bits, struct Rec_021e57e0* rec, int a6, int a7);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* world);
extern "C" int func_ov000_02159f18(void* world, unsigned long long bits, int bit);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* world, void* entry, int msg);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(int unused, struct OutStruct0215ccbc* out, GameObject* combatant,
                            short valC, short valA, short valB, unsigned long long words, unsigned char byteE);
extern "C" void _Z32AppendToChainAndIncCount0215fe84PvS_i(void* chain, void* node, int idx);

static inline short GetCurrentMP(GameObject* c) {
    short mp = c->currentStats_->primaryStats.currMP;
    return mp;
}

// JPN: func_ov024_021e6078
// USA: func_ov024_021e57e0
extern "C" ARM void func_ov024_021e57e0(struct Act_021e57e0* self, int id, struct Rec_021e57e0* rec) {
    GameObject* c = GetCombatantByID((int)self->f10, id);
    if (!c) return;
    if (rec->f4.id == 0xaf) {
        struct Node_021e57e0* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(self->f4, 0);
        for (int i = 1; i < node->slotCount; i++) {
            if (node->slots[i] == 3) return;
        }
    }
    int msg1;
    struct OutStruct0215ccbc* entry;
    int msg2;
    short result;
    int value;
    value = *(int*)((char*)self->f10 + 0x8e38);
    unsigned long long bits = 0;
    result = func_ov000_0215a004(self->f10, id, id, value, &bits, rec, 0, 0);
    entry = func_ov000_0215e958(self->f10);
    if (!entry) return;
    if (value > 0) msg1 = 0x1b4; else msg1 = 0x165;
    msg2 = 0;
    if (func_ov000_02159f18(self->f10, bits, 2)) {
        if (rec->f4.id == 0xaf) msg2 = 0x1b3; else msg2 = 0x117;
    }
    if (msg1) _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->f10, entry, msg1);
    if (msg2) _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->f10, entry, msg2);
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)self->f10, entry, c, value, result, GetCurrentMP(c), bits, 0);
    _Z32AppendToChainAndIncCount0215fe84PvS_i(self->f8, entry, 2);
    ((unsigned char*)self->f10)[0x8e02]++;
}
