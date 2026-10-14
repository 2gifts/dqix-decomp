#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Entry_0205d6a0;
struct Obj0205eaa0;
struct BattleCommand {
    char padding0[0x10];
    signed char commands[8];
    signed char selected;
    char padding19[4];
    signed char previous;
    char padding1e[8];
    unsigned short action;
    char padding28[6];
    signed char variant;
};
struct BattleMenuState {
    char padding0[0x1c];
    signed char current;
    char padding1d[0x16b];
    char entries[0x1bd8];
    signed char commands[8];
    signed char selected;
    char padding1d69[9];
    unsigned short flags;
    char padding1d74[5];
    unsigned char field1d79;
};
struct PartyState {
    char padding0[0xf78];
    signed char ids[4];
    unsigned char count;
};
extern Obj0205eaa0 data_02108760;
extern int data_ov000_02184294[2];
int GetField0x3acValue_020100a8(GameState*);
int GetActiveScaledSum0205d794(Struct_0205c570*);
extern "C" BattleCommand* func_ov000_02161318(BattleMenuState*, int);
extern "C" int func_ov000_0217c594(BattleMenuState*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern "C" void func_ov000_02176e3c(BattleMenuState*, BattleCommand*, int, int, int, int);
extern "C" void func_ov000_02170db0(BattleCommand*);
int CheckFlagsOrField_0217c5f4_0217c5f4(void*);
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
extern "C" void func_ov000_0217c638(BattleMenuState*, int, int);
extern "C" void func_ov000_02177038(BattleMenuState*, BattleCommand*, int, int, int);

// USA: func_ov000_0217e870
extern "C" ARM void func_ov000_0217e870(BattleMenuState* state, int first, int second) {
    state->flags |= 0x100;
    state->current = GetActiveScaledSum0205d794((Struct_0205c570*)state->entries);
    GameState* game = GameState::GetInstance();
    PartyState* party = (PartyState*)GetPtrField0x2a04_02010828(game);
    BattleCommand* command = func_ov000_02161318(state, GetField0x3acValue_020100a8(game));
    if (func_ov000_0217c594(state, 0)) {
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        if (!command) return;
        func_ov000_02176e3c(state, command, state->commands[state->selected], data_ov000_02184294[1], data_ov000_02184294[0], 1);
        state->flags &= ~0x100;
        state->selected++;
        state->commands[state->selected] = 0x64;
        unsigned char count = party->count;
        for (unsigned char i = 0; i < count; i++) {
            BattleCommand* candidate = func_ov000_02161318(state, party->ids[i]);
            if (candidate) {
                candidate->previous = state->current;
                candidate->action = command->action;
                candidate->variant = -1;
                candidate->commands[candidate->selected] = 0x64;
                func_ov000_02170db0(candidate);
            }
        }
    } else if (CheckFlagsOrField_0217c5f4_0217c5f4(state)) {
        state->flags &= ~0x100;
        ResetEntryList0205d6a0((Entry_0205d6a0*)state->entries, 0);
        state->commands[state->selected] = 0;
        state->selected--;
        state->current = -1;
        func_ov000_0217c638(state, first, second);
        GameState* game = GameState::GetInstance();
        PartyState* party = (PartyState*)GetPtrField0x2a04_02010828(game);
        BattleCommand* current = func_ov000_02161318(state, GetField0x3acValue_020100a8(game));
        if (!current) return;
        current->commands[current->selected] = 0x17;
        unsigned char count = party->count;
        BattleCommand* candidate;
        for (unsigned char i = 0; i < count; i++) {
            candidate = func_ov000_02161318(state, party->ids[i]);
            if (candidate) {
                candidate->previous = -1;
                candidate->action = current->action;
                candidate->variant = -1;
                candidate->commands[candidate->selected] = 0x17;
            }
        }
        state->field1d79 = 0;
        func_ov000_02176e3c(state, candidate, 0x17, data_ov000_02184294[1], data_ov000_02184294[0], 0);
    }
    func_ov000_02177038(state, command, 0x19, first, second);
}
