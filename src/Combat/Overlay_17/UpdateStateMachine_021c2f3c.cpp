#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02057924(void);
extern "C" void* func_0202ae18(void);
extern "C" void func_020531f0(void* obj);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
extern "C" void func_ov017_021c2b6c(void* self);
void ForwardResetAndCaptureTimestamp_021c2e50(char* self);
void InitAndDispatchCombatant_021c2ea4(unsigned char* self);
extern "C" int _Z28CountValidCombatants02058618v(void* unused);
unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long dividend, unsigned int divisor, unsigned int flag);
int CheckField0NonZero(int* obj);
void SetByteField0x253(void* obj);
extern "C" void func_ov017_021c310c(void* self);
extern "C" void func_020a0c0c(void);

// USA: func_ov017_021c2f3c  (semantic: UpdateStateMachine_021c2f3c)
#pragma optimize_for_size off
extern "C" ARM void func_ov017_021c2f3c(unsigned char* self) {
    GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
    void* r7 = func_02057924();
    void* r5 = func_0202ae18();

    if (combatant == 0) self[0x8c] = 3;
    unsigned char state = self[0x8c];
    if (state == 0) {
        if (combatant != 0) {
            func_020531f0(combatant);
            CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
        }

        if (_ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant) == 0x2710 ||
            _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant) == 0x2774) {
            self[0x8c] = 2;
            return;
        }

        if (self[0x94] == 0) { self[0x8c] = 1; return; }
        if (self[0x94] != 1) return;
        if (CheckField0NonZero((int*)r5) != 0) {
            self[0x8c] = 2;
            return;
        }
        self[0x8c] = 3;
        return;
    }

    if (state == 1) {
        func_ov017_021c2b6c(self);
        if (*(void**)(self + 0x90) != 0) self[0x8c] = 2;
        return;
    }
    if (state == 2) {
        if (self[0x94] == 0) {
            ForwardResetAndCaptureTimestamp_021c2e50((char*)self);
            return;
        }
        if (self[0x94] == 1) InitAndDispatchCombatant_021c2ea4(self);
        return;
    }
    if (state != 3) return;

    if (*(void**)(self + 0x90) != 0) {
        if (_Z28CountValidCombatants02058618v(r7) > 0) return;
    }

    unsigned long long diff = GetCurrentTimestamp() - *(unsigned long long*)(self + 0x98);
    unsigned long long quotient = _ll_udiv(diff << 6, 0x82ea, 0);
    if (quotient < 0x4b0) return;

    self[0x1] = 1;
    func_ov017_021c310c(self);
    if (self[0x96] != 0) func_020a0c0c();
    if (combatant != 0) SetByteField0x253(combatant);
}
