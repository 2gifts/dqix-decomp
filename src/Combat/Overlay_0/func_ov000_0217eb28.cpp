#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Actor0209c73c;
struct Struct0205d888;
struct Entry_0205d6a0;
struct Struct_0205def8;
struct MenuEntry {
    unsigned char padding0[0xc4];
    unsigned char type;
};
struct BattleCommand {
    unsigned char padding0[0x10];
    signed char commands[8];
    signed char selected;
    unsigned char padding19[0xb];
    unsigned char flags;
    unsigned char padding25[0x62];
    unsigned char active;
};
struct BattleMenuState {
    unsigned char padding0[0x70];
    signed char party[4];
    unsigned char padding74[0x108];
    int current;
    unsigned char padding180[8];
    unsigned char entries[0x1bd8];
    signed char commands[8];
    signed char selected;
    unsigned char padding1d69[2];
    signed char character;
    unsigned char padding1d6c[3];
    unsigned char field1d6f;
    unsigned char padding1d70[0xa];
    unsigned char animation;
};
struct PartyState {
    unsigned char padding0[0xf7c];
    unsigned char count;
};
extern Actor0209c73c data_02109bf4;
extern unsigned short data_02114e30;
extern "C" int _Z25IsAnimationActive0209ca2cPv(void*);
extern "C" void _Z26DispatchActorState0209c73cP13Actor0209c73c(Actor0209c73c*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" int func_0205d97c(void*);
int GetAdjustedByteField0x1d6b(void*);
extern "C" int* func_0202ae18();
int CheckField0NonZero(int*);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern "C" BattleCommand* func_ov000_02161318(BattleMenuState*, int);
extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int*);
extern "C" void func_ov000_02171c04(BattleCommand*);
extern "C" MenuEntry* _Z20GetLastEntry0205d888P14Struct0205d888(Struct0205d888*);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0*, int);
extern "C" void func_ov000_0217c638(BattleMenuState*, int, int);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(Struct_0205def8*, int, int);

// USA: func_ov000_0217eb28
extern "C" ARM void func_ov000_0217eb28(BattleMenuState* state, int first, int second) {
    if (state->animation) {
        if (_Z25IsAnimationActive0209ca2cPv(&data_02109bf4)) return;
        _Z26DispatchActorState0209c73cP13Actor0209c73c(&data_02109bf4);
    }
    int triggered = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    triggered |= TestFlag0SetAndFlag1Clear(&data_02114e30, 0x802);
    triggered |= func_0205d97c(state->entries) == 2;
    if (!triggered) return;
    if (state->commands[state->selected] == 0x20) {
        state->animation = 0;
        while (state->commands[state->selected] != 2) {
            state->commands[state->selected] = 0;
            state->selected--;
        }
        int character = GetAdjustedByteField0x1d6b(state);
        if (CheckField0NonZero(func_0202ae18()))
            func_ov017_021c3fb4(character, 1);
        GameResources* resources = func_ov017_0218b5b0();
        BackgroundLoader::GetInstance();
        func_ov017_0218f5a4(resources, character, 1, 0, 0);
        BattleCommand* command = func_ov000_02161318(state, character);
        if (!command) return;
        if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)command)) {
            command->commands[command->selected] = 0x64;
            command->flags &= ~4;
        }
        func_ov000_02171c04(command);
        MenuEntry* entry = _Z20GetLastEntry0205d888P14Struct0205d888((Struct0205d888*)state->entries);
        while (entry) {
            if (entry->type == 2) break;
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)state->entries, 0);
            entry = _Z20GetLastEntry0205d888P14Struct0205d888((Struct0205d888*)state->entries);
        }
        unsigned char count = ((PartyState*)GetPtrField0x2a04(GameState::GetInstance()))->count;
        for (unsigned char i = 0; i < count; i++) {
            int id = state->party[i];
            BattleCommand* candidate = func_ov000_02161318(state, id);
            if (candidate && !_Z29HasAnyFlags_021719f8_021719f8Pi((int*)candidate) && candidate->active) {
                state->current = id;
                break;
            }
        }
        func_ov000_0217c638(state, first, second);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)state->entries, 1, 1);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)state->entries, 1, 2);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)state->entries, 1, 5);
        state->character = -1;
        state->field1d6f = 0;
    } else {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)state->entries, 0);
        state->commands[state->selected] = 0;
        state->selected--;
        func_ov000_0217c638(state, first, second);
    }
}
