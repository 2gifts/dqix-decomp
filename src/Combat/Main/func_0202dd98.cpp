#include <globaldefs.h>
#if defined(jpn)
#define _Z29SetState3AndDispatch_0202cca4v func_0202c814
#define data_021023c0 data_02102100
#endif

struct BattleDispatchState { char pad0[0x10]; int state_; char pad14[0x34 - 0x14]; int mode_; };
struct BattleEffectContext { char data_[0x820]; };
extern BattleDispatchState data_021015a0;
extern BattleEffectContext data_021023c0, data_02102be0;
int AdvanceStateIfState2();
void TryIssueBattleCommandAndUpdateState();
extern "C" int _Z42ForwardClearBattleSubEffectAt0x800020d68d0Pv(void*);
void SetField0x48UnlessState9Or10(int);
extern "C" int _Z29SetState3AndDispatch_0202d54cv();
int ClearBattleSubEffectAt0x800(void*);
extern "C" int _Z29SetState3AndDispatch_0202cca4v();

static inline int CurrentState() { return data_021015a0.state_; }

// JPN: func_0202d908
// USA: func_0202dd98
extern "C" ARM void func_0202dd98() {
    if (data_021015a0.state_ == 1) return;
    if (data_021015a0.state_ == 2) {
        if (!AdvanceStateIfState2()) TryIssueBattleCommandAndUpdateState();
        return;
    }
    if (data_021015a0.state_ != 6 && data_021015a0.state_ != 5 && data_021015a0.state_ != 4) {
        data_021015a0.state_ = 3;
        TryIssueBattleCommandAndUpdateState();
        return;
    }
    data_021015a0.state_ = 3;
    switch (data_021015a0.mode_) {
    case 3: {
        int result;
        int state = CurrentState();
        if (state != 6) result = 0;
        else {
            data_021015a0.state_ = state;
            int status = _Z42ForwardClearBattleSubEffectAt0x800020d68d0Pv(&data_021023c0);
            if (status) { SetField0x48UnlessState9Or10(status); result = 0; }
            else if (!_Z29SetState3AndDispatch_0202d54cv()) result = 0;
            else result = 1;
        }
        if (!result) TryIssueBattleCommandAndUpdateState();
        break;
    }
    case 5:
        if (ClearBattleSubEffectAt0x800(&data_02102be0)) { TryIssueBattleCommandAndUpdateState(); break; }
    case 1:
        if (!_Z29SetState3AndDispatch_0202d54cv()) TryIssueBattleCommandAndUpdateState();
        break;
    case 2: {
        int result;
        int status = _Z42ForwardClearBattleSubEffectAt0x800020d68d0Pv(&data_021023c0);
        if (status) { SetField0x48UnlessState9Or10(status); result = 0; }
        else if (_Z29SetState3AndDispatch_0202cca4v()) result = 1;
        else { TryIssueBattleCommandAndUpdateState(); result = 0; }
        if (!result) TryIssueBattleCommandAndUpdateState();
        break;
    }
    case 4:
        if (ClearBattleSubEffectAt0x800(&data_02102be0)) { TryIssueBattleCommandAndUpdateState(); break; }
    case 0:
        if (!_Z29SetState3AndDispatch_0202cca4v()) TryIssueBattleCommandAndUpdateState();
        break;
    }
}
