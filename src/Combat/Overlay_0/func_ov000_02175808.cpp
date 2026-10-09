#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct PartyRecord { char pad0[0x950]; int vocation; };
struct PartyCombatant : GameObject { char pad13c[0x14]; PartyRecord* record; };
struct Entry_0205d6a0 { int field0; };
struct Struct0217f8c0 {
    char pad0[0x10];
    unsigned short values[5];
    unsigned char count;
    char pad1b[5];
    int mode;
    char pad24[0x158];
    int protagonist;
    char pad180[8];
    Entry_0205d6a0 list;
    char pad18c[0x1d60-0x18c];
    unsigned char commands[8];
    signed char commandIndex;
    char pad1d69[4];
    unsigned char step;
    char pad1d6e[0x13];
    unsigned char state;
};
struct PartySlots { char pad0[0xf78]; signed char ids[4]; unsigned char count; };
struct CombatCommand { char pad0[0x10]; unsigned char commands[8]; signed char index; };
extern "C" void __clear(void*, unsigned long);
extern "C" void func_ov000_021757ac(Struct0217f8c0*, unsigned short);
int GetField0x3acValue(GameState*);
extern "C" CombatCommand* func_ov000_02161318(Struct0217f8c0*, int);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0*, int);
extern "C" int _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0(Struct0217f8c0*);
extern "C" void func_ov000_02176634(Struct0217f8c0*, int, int, int, int);
extern unsigned short data_ov000_0218342a[];
extern int data_ov000_02184288[3];
extern int data_ov000_02183ff0;

// USA: func_ov000_02175808
extern "C" ARM void func_ov000_02175808(Struct0217f8c0* self) {
    memset(self->values, 0, 10);
    self->count = 0;
    unsigned char vocations[13];
    __clear(vocations, 13);
    unsigned char count = 0;
    GameState* game = GameState::GetInstance();
    for (signed char i = 0; i < 4; ++i) {
        PartyCombatant* member = (PartyCombatant*)game->GetPartyMemberByIndex(i);
        if (!member) return;
        int vocation = member->record->vocation;
        if (self->mode >= 0 && data_ov000_0218342a[vocation] == 0x20a) continue;
        vocations[vocation] = 1;
    }
    for (signed char i = 0; i < 13; ++i) {
        if (vocations[i]) {
            func_ov000_021757ac(self, data_ov000_0218342a[i]);
            ++count;
        }
    }
    if (!count) return;
    GameState* current = GameState::GetInstance();
    self->protagonist = GetField0x3acValue(current);
    func_ov000_021757ac(self, 0);
    PartySlots* party = (PartySlots*)GetPtrField0x2a04(current);
    unsigned char slots = party->count;
    for (unsigned char i = 0; i < slots; ++i) {
        CombatCommand* command = func_ov000_02161318(self, party->ids[i]);
        if (command) command->commands[command->index] = 13;
    }
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(&self->list, 1);
    self->step = 0;
    ++self->commandIndex;
    self->commands[self->commandIndex] = 0x17;
    int entry = _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0(self);
    func_ov000_02176634(self, entry, 0x17, data_ov000_02183ff0, data_ov000_02184288[1]);
    self->state = 0;
}
