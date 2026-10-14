#include <globaldefs.h>
#if defined(jpn)
#define data_021023c0 data_02102100
#endif

struct BattleDispatchState { char pad0[0x10]; int state_; char pad14[0x34 - 0x14]; int mode_; };
struct BattleEffectContext { char data_[0x820]; };
extern BattleDispatchState data_021015a0;
extern BattleEffectContext data_021023c0, data_02102be0;
int AdvanceStateIfState2_0202d0b4();
void TryIssueBattleCommandAndUpdateState_0202dd28();
int ForwardClearBattleSubEffectAt0x800020d68d0(void*);
void SetField0x48UnlessState9Or10_0202c848(int);
int SetState3AndDispatch_0202d54c();
int ClearBattleSubEffectAt0x800_020d5f88(void*);
int SetState3AndDispatch_0202cca4();

static inline int CurrentState() { return data_021015a0.state_; }

// USA: func_0202dd98
extern "C" ARM void func_0202dd98() {
    if (data_021015a0.state_ == 1) return;
    if (data_021015a0.state_ == 2) {
        if (!AdvanceStateIfState2_0202d0b4()) TryIssueBattleCommandAndUpdateState_0202dd28();
        return;
    }
    if (data_021015a0.state_ != 6 && data_021015a0.state_ != 5 && data_021015a0.state_ != 4) {
        data_021015a0.state_ = 3;
        TryIssueBattleCommandAndUpdateState_0202dd28();
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
            int status = ForwardClearBattleSubEffectAt0x800020d68d0(&data_021023c0);
            if (status) { SetField0x48UnlessState9Or10_0202c848(status); result = 0; }
            else if (!SetState3AndDispatch_0202d54c()) result = 0;
            else result = 1;
        }
        if (!result) TryIssueBattleCommandAndUpdateState_0202dd28();
        break;
    }
    case 5:
        if (ClearBattleSubEffectAt0x800_020d5f88(&data_02102be0)) { TryIssueBattleCommandAndUpdateState_0202dd28(); break; }
    case 1:
        if (!SetState3AndDispatch_0202d54c()) TryIssueBattleCommandAndUpdateState_0202dd28();
        break;
    case 2: {
        int result;
        int status = ForwardClearBattleSubEffectAt0x800020d68d0(&data_021023c0);
        if (status) { SetField0x48UnlessState9Or10_0202c848(status); result = 0; }
        else if (SetState3AndDispatch_0202cca4()) result = 1;
        else { TryIssueBattleCommandAndUpdateState_0202dd28(); result = 0; }
        if (!result) TryIssueBattleCommandAndUpdateState_0202dd28();
        break;
    }
    case 4:
        if (ClearBattleSubEffectAt0x800_020d5f88(&data_02102be0)) { TryIssueBattleCommandAndUpdateState_0202dd28(); break; }
    case 0:
        if (!SetState3AndDispatch_0202cca4()) TryIssueBattleCommandAndUpdateState_0202dd28();
        break;
    }
}
