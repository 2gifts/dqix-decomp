#include <globaldefs.h>
#if defined(jpn)
enum { kSelectionIndex = 0x753e - 0x6fc0 };
#else
enum { kSelectionIndex = 0x74fe - 0x6fc0 };
#endif
#include "GameState/GameState.h"
#include "System/ProcessorContext.h"

struct BattleSelection0202b000 { unsigned char values[6]; };
struct BattleObject0202b000 {
    int active;
    unsigned short slot;
    char field_0x6[0x102c - 6];
    BattleSelection0202b000 selection;
};
extern "C" void func_0202aec0(BattleObject0202b000*);
void PushInterruptDisableState();
extern "C" int _Z26IncrementSlotIndex020d4dd4v();
extern "C" int _Z29InitBattleWorkAndPoll0202d9e0v();
int SetBattleContextField0xc8IfIdle(void*);
void SetField0x8Of02101640(int);
extern "C" int func_0202b1f4(BattleObject0202b000*, int);
void TryIssueBattleCommandAndUpdateState();
extern "C" int _Z28DispatchSizedRequest020d5974Pvii(void*, int, int);
extern "C" void func_020d8694();
void SetGlobalStateIfField4Is16(void*);

// USA: func_0202b000
extern "C" ARM unsigned char func_0202b000(BattleObject0202b000* obj) {
    func_0202aec0(obj);
    PushInterruptDisableState();
    obj->slot = _Z26IncrementSlotIndex020d4dd4v();
    int attempts = 0;
    while (!_Z29InitBattleWorkAndPoll0202d9e0v()) {
        attempts++;
        if (attempts > 5000) break;
        SleepCurrentContext(1);
    }
    SetBattleContextField0xc8IfIdle((void*)SetGlobalStateIfField4Is16);
    SetField0x8Of02101640(0x785);
    obj->active = 1;
    int result = func_0202b1f4(obj, 1);
    if (result) {
        TryIssueBattleCommandAndUpdateState();
        func_0202b1f4(obj, 1);
    }
    _Z28DispatchSizedRequest020d5974Pvii(0, 255, 235);
    GameState* state = GameState::GetInstance();
    BattleSelection0202b000 selection = *(BattleSelection0202b000*)&state->unk_6fc0[kSelectionIndex];
    obj->selection = selection;
    func_020d8694();
    return result;
}
