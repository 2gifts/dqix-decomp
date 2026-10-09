#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"

struct Combatant021c9954 {
    Object3D obj3D;
    char padAc[0x17d - 0xac];
    unsigned char flags17d : 7;
    unsigned char active : 1;
};

struct Party021c9954 {
    char pad0[3];
    unsigned char locked;
};

struct Leader021c9954 {
    char pad0[8];
    unsigned short id;
};

struct Slot021c9954 {
    char pad0[4];
    unsigned short id;
};

struct Cursor021c9954 {
    char pad0[2];
    unsigned char active;
};

struct Target021c9954 {
    unsigned short id;
    unsigned short arg;
};

struct Battle021c9954 {
    char pad0[0x3718];
    Party021c9954* party;
    char pad371c[0x3b98 - 0x371c];
    Cursor021c9954* cursor;
    char pad3b9c[0x44ae - 0x3b9c];
    Target021c9954 target;
};

extern "C" void func_ov017_021b86f8(Party021c9954* party, int id, int flag, int keep);
extern "C" void func_02076a8c(void* obj);
extern "C" Leader021c9954* func_ov017_021b8478(Party021c9954* party);
extern "C" Leader021c9954* func_ov017_021b8468(Party021c9954* party);
extern "C" void _Z12NoOp02163778v(Leader021c9954* current);
extern "C" void func_020dc548(signed char id, signed char* out, signed char* count);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" Combatant021c9954* _Z32FindCombatantByField16a_021a278cPvi(void* unused, int val);
extern "C" void _Z37SetFieldForMatchingCombatant_021c98f4ii(int id, int value);
extern "C" void _Z18TrySetMode02076cccPvi(void* obj, int mode);
extern "C" Slot021c9954* _Z26GetPtrPlusOffsetC_021a7c8cPv(void* obj);
extern "C" void _Z25SetByteAtOffset1_021a7c1cPh(unsigned char* obj);

// USA: func_ov017_021c9954
extern "C" ARM void func_ov017_021c9954(int id, int checkLeader, int keep, int group) {
    GameState::GetInstance();
    Battle021c9954* battle = (Battle021c9954*)func_ov017_0218b5b0();
    Combatant021c9954* combatant;
    Party021c9954* party = battle->party;
    func_ov017_021b86f8(party, id, 1, keep);

    combatant = _Z32FindCombatantByField16a_021a278cPvi(battle, id);
    if (combatant != 0 && keep == 0) {
        func_02076a8c(combatant);
        combatant->obj3D.MakeHidden();
    }
    _Z37SetFieldForMatchingCombatant_021c98f4ii(id, 0);

    if (checkLeader != 0) {
        Leader021c9954* leader = func_ov017_021b8478(party);
        Leader021c9954* current = func_ov017_021b8468(party);
        if (current != 0 && leader != 0 && leader->id == id) {
            _Z12NoOp02163778v(current);
        }
    }

    Target021c9954* target = &battle->target;
    if (battle->target.id == id) {
        target->id = 0;
        target->arg = 0;
    }

    if (combatant != 0 && keep != 0) {
        _Z18TrySetMode02076cccPvi(combatant, 1);
        combatant->active = 0;
    }

    Cursor021c9954* cursor = battle->cursor;
    if (cursor->active != 0) {
        Slot021c9954* slot = _Z26GetPtrPlusOffsetC_021a7c8cPv(cursor);
        if (slot->id == id) {
            _Z25SetByteAtOffset1_021a7c1cPh((unsigned char*)cursor);
        }
    }

    if (group > -1 && party->locked == 0) {
        signed char count;
        signed char members[7];
        func_020dc548(group, members, &count);
        for (int i = 0; i < count; i++) {
            func_ov017_021917f0(members[i], 0);
        }
    }
}
