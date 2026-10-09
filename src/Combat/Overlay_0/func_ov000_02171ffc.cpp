#include <globaldefs.h>
#include "GameState/GameState.h"

struct Outer_02054000;
extern "C" void* _Z21GetActiveSub_02054000P14Outer_02054000(struct Outer_02054000* p);
int TestBitInArray0x8ec(unsigned char* obj, int index);

struct CombatantFlags02f4 {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int rest : 30;
};

struct CombatantData {
    char unk0[0x2f4];
    struct CombatantFlags02f4 flags;
};

struct CombatantObject {
    char unk0[0x150];
    struct CombatantData* data;
};

struct ActiveSub {
    char unk0[0x18];
    short count;
};

struct ActionEntry {
    char unk0[0x16];
    short actionId;
};

struct ActionInfo {
    char unk0[8];
    unsigned int unk8_0 : 8;
    unsigned int kind : 2;
    unsigned int unk8_10 : 22;
    char unkC[0x14 - 0xc];
    unsigned int unk14_0 : 28;
    unsigned int category : 4;
};

struct Combatant {
    char unk0[0x1c];
    signed char actionType;
    char unk1d[0x26 - 0x1d];
    short actionId;
    char unk28[0x2c - 0x28];
    short actionKey;
    char unk2e[0x4c - 0x2e];
    int combatantId;
};

extern "C" struct ActionEntry* func_ov000_02171d90(struct Combatant* obj, int key);
extern "C" struct ActionInfo* func_ov000_02170cf8(struct Combatant* obj, int id);

// USA: func_ov000_02171ffc
extern "C" ARM int func_ov000_02171ffc(struct Combatant* obj) {
    struct CombatantObject* combatant = (struct CombatantObject*)GetCombatantWithFlag0x100(GameState::GetInstance(), obj->combatantId);
    if (combatant == 0) {
        return 2;
    }
    short actionId = obj->actionId;
    int result = 2;
    if (obj->actionType == 4) {
        struct ActionEntry* entry = func_ov000_02171d90(obj, obj->actionKey);
        if (entry == 0) {
            return result;
        }
        actionId = entry->actionId;
    }
    if (actionId == 0x20a) {
        return 3;
    }
    struct ActionInfo* info = func_ov000_02170cf8(obj, (unsigned short)actionId);
    if (info == 0) {
        return 2;
    }
    if (actionId == 1) {
        if (combatant != 0) {
            struct ActiveSub* sub = (struct ActiveSub*)_Z21GetActiveSub_02054000P14Outer_02054000((struct Outer_02054000*)combatant);
            if (sub != 0 && sub->count > 0) {
                struct CombatantFlags02f4* flags = &combatant->data->flags;
                if (flags->bit1) {
                    result = 3;
                } else if (flags->bit0) {
                    result = 4;
                }
            }
        }
    } else {
        int kind = info->kind;
        if (kind == 1) {
            result = info->category;
        } else if (kind == 2) {
            result = info->category;
        }
    }
    if (result == 6 && combatant != 0) {
        result = 2;
        if (TestBitInArray0x8ec((unsigned char*)combatant->data, 0xe6)) {
            result = 3;
        }
    }
    return result;
}
