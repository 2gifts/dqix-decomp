#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570 { unsigned char data[0x7cc]; };
struct Struct_0205def8 { unsigned char data[0x7cc]; };
struct Struct_0205d81c { unsigned char data[0x7cc]; };
struct Struct0217f8c0;
struct Obj0205eaa0 { unsigned char data[0xd0]; };
struct ResourceE558 { unsigned char padding[0x7712]; signed char selected; };
struct PartyEffectsE558 { unsigned char padding[0xf78]; signed char members[4]; unsigned char count; };
struct ActionRecordE558 { int field0; unsigned int value : 12; unsigned int valueRest : 20; unsigned int flags; };
struct ActorE558 {
    unsigned char padding[0x10];
    signed char actions[8];
    signed char actionIndex;
    unsigned char padding19[4];
    signed char target;
    unsigned char padding1e[8];
    unsigned short value;
    unsigned char padding28[6];
    signed char alternateTarget;
    signed char GetTarget() const { return target; }
    signed char GetAlternateTarget() const { return alternateTarget; }
    int SetTarget(int value) { return target = value; }
    int SetAlternateTarget(int value) { return alternateTarget = value; }
};
struct BattleE558 {
    unsigned char padding[0x10];
    union {
        short keys[8];
        struct { unsigned char padding10[0xc]; unsigned char field1c; };
    };
    unsigned char padding20[0x188 - 0x20];
    union { Struct_0205c570 sums; Struct_0205def8 flags; Struct_0205d81c fields; } list;
    unsigned char padding954[2];
    unsigned char field956;
    unsigned char padding957[0x1d60 - 0x957];
    signed char actions[8];
    signed char actionIndex;
    unsigned char padding1d69[4];
    signed char selected;
    unsigned char padding1d6e[4];
    unsigned short flags;
    unsigned char padding1d74[5];
    unsigned char field1d79;
};
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570*);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(Struct_0205def8*, int, int);
void SetElementFieldC2(Struct_0205d81c*, int, int);
GameResources* GetWord0x0(int*);
extern "C" ResourceE558* func_ov017_021b8468(void*);
extern "C" int func_ov000_0217c594(BattleE558*, int);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" ActorE558* func_ov000_02161318(BattleE558*, int);
extern "C" void func_ov000_02170db0(ActorE558*);
char* GetData02108e10();
extern "C" ActionRecordE558* _Z24SearchBothTables02079e2cPci(char*, int);
extern "C" void func_ov000_02175b54(BattleE558*);
int GetField0x3acValue(GameState*);
extern "C" void func_ov000_02176e3c(BattleE558*, int, int, int, int, int);
extern "C" int _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0(Struct0217f8c0*);
extern "C" void func_ov000_02176634(BattleE558*, int, int, int, int);
extern Obj0205eaa0 data_02108760;
extern int data_ov000_02184294[3];

// USA: func_ov000_0217e558
extern "C" ARM void func_ov000_0217e558(BattleE558* battle, int arg1, int arg2) {
    battle->flags |= 0x100;
    battle->selected = _Z26GetActiveScaledSum0205d794P15Struct_0205c570(&battle->list.sums);
    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(&battle->list.flags, 1, 0x18);
    SetElementFieldC2(&battle->list.fields, 0x18, 0);
    GameState* game = GameState::GetInstance();
    GameResources* data = GetWord0x0((int*)game);
    if (func_ov017_021b8468(data->unknown_ptr_3718)->selected != -1 || !func_ov000_0217c594(battle, 5)) return;
    battle->field956 = 0;
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
    if ((unsigned short)battle->keys[battle->selected] == 0) {
        battle->actionIndex++;
        battle->actions[battle->actionIndex] = 100;
        PartyEffectsE558* party = (PartyEffectsE558*)GetPtrField0x2a04(game);
        unsigned char count = party->count;
        for (unsigned char i = 0; i < count; i++) {
            ActorE558* actor = func_ov000_02161318(battle, party->members[i]);
            if (actor) {
                actor->SetTarget(actor->GetTarget());
                actor->value = 0;
                actor->SetAlternateTarget(actor->GetAlternateTarget());
                actor->actions[actor->actionIndex] = 100;
                func_ov000_02170db0(actor);
            }
        }
    } else {
        char* tables = GetData02108e10();
        if (!tables) return;
        ActionRecordE558* entry = _Z24SearchBothTables02079e2cPci(tables, battle->keys[battle->selected]);
        if (!entry) return;
        func_ov000_02175b54(battle);
        GameState* game = GameState::GetInstance();
        PartyEffectsE558* party = (PartyEffectsE558*)GetPtrField0x2a04(game);
        ActorE558* current = func_ov000_02161318(battle, GetField0x3acValue(game));
        if (!current) return;
        switch (battle->actions[battle->actionIndex]) {
        case 14: battle->actions[battle->actionIndex] = 25; battle->field1d79 = 0; break;
        case 18:
        case 19: battle->actions[battle->actionIndex] = 100; break;
        }
        signed char target = -1;
        int alternate = target;
        unsigned int kind = (entry->flags << 22) >> 30;
        if (kind == 1) target = current->target;
        if (kind == 2) alternate = current->alternateTarget;
        unsigned char count = party->count;
        for (unsigned char i = 0; i < count; i++) {
            ActorE558* actor = func_ov000_02161318(battle, party->members[i]);
            if (actor) {
                actor->target = target;
                actor->value = entry->value;
                actor->alternateTarget = alternate;
                actor->actions[actor->actionIndex] = battle->actions[battle->actionIndex];
                func_ov000_02170db0(actor);
            }
        }
    }
    if (battle->actions[battle->actionIndex] != 25) return;
    func_ov000_02176e3c(battle, 0, 23, data_ov000_02184294[1], data_ov000_02184294[0], 1);
    battle->field1c = 0;
    int match = _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0((Struct0217f8c0*)battle);
    func_ov000_02176634(battle, match, 25, arg1, arg2);
}
