#include <globaldefs.h>

struct CombatStats {
    char pad0[0x21];
    unsigned char field_0x21;
};

struct Combatant {
    char pad0[0x138];
    CombatStats* stats;
    char pad13c[0x184 - 0x13c];
    unsigned char busy;
};

struct Battle {
    char pad0[0x81b1];
    unsigned char aliveCount : 4;
    unsigned char groupCount : 2;
    char pad81b2[0x8e14 - 0x81b2];
    signed char result;
    char pad8e15[0x8e20 - 0x8e15];
    int turnCount;
};

struct IdList { short v[16]; };
struct TargetList { short v[8]; };

extern IdList data_ov000_02182cf4;
extern TargetList data_ov000_02182bc4;

extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" Combatant* _ZN9GameState19GetCombatantByIndexEi(void* gs, int id);
extern "C" Combatant* _Z25GetCombatantWithFlag0x400P9GameStatei(void* gs, int id);
extern "C" Combatant* _Z25GetCombatantWithFlag0x100P9GameStatei(void* gs, int id);
extern "C" void _Z22SetBool0x17fClear0x180Phi(Combatant* c, int value);
extern "C" void _Z22SetBool0x180Clear0x17fPhi(Combatant* c, int value);
extern "C" void _Z18ClearBits0x1And0x4Ph(CombatStats* stats);
extern "C" int _Z19ClassifyField0x81fePc(Battle* battle);
extern "C" int func_ov000_02153e40(Battle* battle, short* buf, int max, int start);
extern "C" int func_ov000_0215e9fc(Battle* battle, short* buf, int max, int start);
extern "C" void func_ov000_0215a23c(Battle* battle);
extern "C" void func_ov000_02157e1c(Battle* battle);
extern "C" void func_ov000_02155e94(Battle* battle);

// USA: func_ov000_0215e6e8
extern "C" ARM void func_ov000_0215e6e8(Battle* battle) {
    int count;
    IdList ids = data_ov000_02182cf4;
    if (battle->result == 0) {
        count = func_ov000_02153e40(battle, ids.v, 0x10, 1);
        for (int i = 0; i < count; i++) {
            int id = ids.v[i];
            void* gs = _ZN9GameState11GetInstanceEv();
            Combatant* c = _ZN9GameState19GetCombatantByIndexEi(gs, id);
            if (c != NULL) {
                int isPlayerSlot = 0;
                int id2 = ids.v[i];
                if (id2 >= 0) {
                    if (id2 <= 3) {
                        isPlayerSlot = 1;
                    }
                }
                if (isPlayerSlot == 0) {
                    Combatant* other = _Z25GetCombatantWithFlag0x400P9GameStatei(_ZN9GameState11GetInstanceEv(), id2);
                    if (other != NULL) {
                        other->busy = 0;
                        _Z22SetBool0x17fClear0x180Phi(other, 0);
                        _Z22SetBool0x180Clear0x17fPhi(other, 0);
                    }
                }
                _Z18ClearBits0x1And0x4Ph(c->stats);
                c->stats->field_0x21 = 0;
            }
        }
        func_ov000_0215a23c(battle);
        if (battle->result == 0) {
            func_ov000_02157e1c(battle);
        }
        func_ov000_02155e94(battle);
        TargetList targets = data_ov000_02182bc4;
        if (func_ov000_0215e9fc(battle, targets.v, 8, 9) <= 0) {
            battle->result = 2;
        } else if (battle->aliveCount == 0) {
            battle->result = 1;
        }
    }
    if (_Z19ClassifyField0x81fePc(battle) != 0) {
        battle->result = 0;
    }
    battle->turnCount++;
    if (battle->result != 0) {
        count = func_ov000_0215e9fc(battle, ids.v, 0x10, 0);
        void* gs = _ZN9GameState11GetInstanceEv();
        for (int i = 0; i < count; i++) {
            _Z25GetCombatantWithFlag0x100P9GameStatei(gs, ids.v[i]);
        }
    }
}
