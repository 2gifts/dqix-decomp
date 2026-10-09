#include <globaldefs.h>
#include "GameState/GameState.h"

struct SlotWork;
struct Obj02176038;

struct Cmd {
    unsigned char b[4];
    signed char c;
    unsigned short d;
    unsigned short e;
};

struct Roster {
    char pad0[0xf78];
    signed char ids[4];
    unsigned char count;
};

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
};

struct Container_021dae60 {
    char pad0[0xb8];
};

struct BattleWork {
    char pad0[0x2a0];
    PartyState* party;
    char pad2a4[0xc08];
    int state;
    char padeb0[0x28b0];
    Container_021dae60 list;
    char pad3818[0x1cdc];
    int slotDone[4];
    char pad5504[0xf0];
    int workFlags;
    char pad55f8[0x2137];
    unsigned char inputOn;
    char pad7730[0x4];
    int savedWorkFlags;
    unsigned int savedField;
};

extern "C" SlotWork* _Z21FindSlotById_021dae60P18Container_021dae60i(Container_021dae60* c, int id);
int GetCombatWorkFlags0x55f4(void* work, int mask);
void SetCombatWorkFlags0x55f4(void* work, int mask);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int* field, unsigned int bits);
extern "C" void _Z22SetFlagAndCall02176038P11Obj02176038(Obj02176038* obj);

extern "C" {
void* memset(void*, int, unsigned int);
void func_ov000_0217fcc4(Container_021dae60*, int);
void func_ov000_0217f518(SlotWork*);
void func_ov000_02162c14(BattleWork*, int, Cmd*);
void func_ov017_021c6814(unsigned short, unsigned short, Cmd*, unsigned char, int, int);
}

// USA: func_ov026_021dbf04
extern "C" ARM void func_ov026_021dbf04(BattleWork* self) {
    Cmd cmd;

    int state = self->state;
    if (state == 0) {
        self->state = 0;
    } else if (state != 0 && state != 1 && state != 2) {
        self->state = 3;
    }

    func_ov000_0217fcc4(&self->list, -1);
    self->inputOn = 0;
    memset(self->slotDone, 0, sizeof(self->slotDone));

    Roster* roster = (Roster*)GetPtrField0x2a04(GameState::GetInstance());
    for (int i = 0; i < roster->count; i++) {
        int id = roster->ids[i];
        SlotWork* slot = _Z21FindSlotById_021dae60P18Container_021dae60i(&self->list, id);
        if (slot != NULL) {
            func_ov000_0217f518(slot);
            func_ov000_02162c14(self, id, &cmd);
            func_ov017_021c6814(self->party->netId, id, &cmd, 0, -1, 0);
        }
    }

    int wasSet = GetCombatWorkFlags0x55f4(self, 0x2000000);
    self->workFlags = self->savedWorkFlags;
    if (wasSet) {
        SetCombatWorkFlags0x55f4(self, 0x2000000);
    }
    OrBitsIntoField0((unsigned int*)_Z27GetDataPtr02114e04_020d6c00v(), self->savedField);
    _Z22SetFlagAndCall02176038P11Obj02176038((Obj02176038*)&self->list);
}
