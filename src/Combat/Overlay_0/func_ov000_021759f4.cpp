#include <globaldefs.h>
#include "GameState/GameState.h"

struct Combatant020A36A8;

struct PartyEntry {
    char pad0[0x10];
    signed char hpState[8];
    signed char stateIndex;
    char pad19[0x1c - 0x19];
    signed char field_0x1c;
    signed char field_0x1d;
    char pad1E[0x26 - 0x1e];
    short field_0x26;
    char pad28[0x2e - 0x28];
    signed char field_0x2e;
};

struct PlayerData {
    char pad0[0x950];
    int vocation;
};

struct PartyMemberExt {
    char pad0[0x150];
    struct PlayerData* data;
};

struct TeamWork {
    short field_0x0[4];
    signed char field_0x8[4];
    signed char field_0xc[4];
    char pad10[0x20 - 0x10];
    int field_0x20;
    char pad24[0x1d72 - 0x24];
    unsigned short flags;
};

struct EventSource {
    char pad0[0xeb4];
    unsigned char result;
};

extern "C" GameResources* func_ov017_0218b5b0(void);
extern "C" struct Combatant020A36A8* func_ov017_021b8478(void* obj);
extern "C" int _Z26MatchesActiveIndex020a36a8P17Combatant020A36A8(struct Combatant020A36A8* obj);
extern "C" struct EventSource* func_ov017_021b8468(void* obj);
extern "C" struct PartyEntry* func_ov000_02161318(void* obj, int id);
extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
extern "C" void _Z27EnqueueEventTag125_021c9cd8h(unsigned char tag);
extern unsigned short data_ov000_02183444[];

// USA: func_ov000_021759f4
extern "C" ARM int func_ov000_021759f4(struct TeamWork* work) {
    void* node = func_ov017_0218b5b0()->unknown_ptr_3718;
    struct Combatant020A36A8* active = func_ov017_021b8478(node);
    if (work->flags & 0x200) {
        return 0;
    }
    if (work->flags & 0x400) {
        return 0;
    }
    if (active != NULL && !_Z26MatchesActiveIndex020a36a8P17Combatant020A36A8(active)) {
        struct EventSource* source = func_ov017_021b8468(node);
        if (source != NULL) {
            return source->result;
        }
    }

    GameState* gs = GameState::GetInstance();
    unsigned char matched = 0;
    unsigned char count = 0;
    for (int i = 0; i < 4; i++) {
        struct PartyEntry* entry = func_ov000_02161318(work, i);
        if (entry == NULL) {
            break;
        }
        if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)entry) != 0 || entry->hpState[entry->stateIndex] != 100 ||
            entry->field_0x1c != 5) {
            break;
        }
        GameObject* member = gs->GetPartyMemberByIndex(i);
        if (member == NULL) {
            break;
        }
        int vocation = ((struct PartyMemberExt*)member)->data->vocation;
        unsigned short expected = data_ov000_02183444[vocation];
        if (expected != entry->field_0x26) {
            break;
        }
        work->field_0x0[i] = entry->field_0x26;
        work->field_0x8[i] = entry->field_0x1d;
        work->field_0xc[i] = entry->field_0x2e;
        if (work->field_0x20 >= 0 && (vocation == 6 || vocation == 0xb)) {
            matched++;
        }
        count++;
    }
    if (count == 4 && matched != 4) {
        _Z27EnqueueEventTag125_021c9cd8h(1);
        return 1;
    }
    return 0;
}
