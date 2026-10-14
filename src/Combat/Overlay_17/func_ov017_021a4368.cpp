#include <globaldefs.h>

struct S021b6b74;
struct Obj0217eef4;
struct ObjWithField4_021afabc;
struct Obj0217f248;
struct S021a99b0;
struct Obj020dae80;
void ClearGlobalField_021adc44_021adc44(void*);
void CallField1cIfFlagGt1_021a18a4(void*);
void ForwardTeardownB_021b9928(char*);
void CallField6acPtrB_021b8450(void*);
void CallIfGlobalPtrSet_021a5954(void*);
void CallField20PtrB_021bae98(void*);
void CallField1cPtrB_021babe0(void*);
void CallCallbackIfField20Set_0217e598(int*);
void ForwardTeardown_021bb8f0(char*);
void CallHelperIfFlag_021b2f2c(void*);
void CallIfField24_021b6b74(struct S021b6b74*);
void CallIfField1CSet_0217eef4(struct Obj0217eef4*);
void ResetAndForward_021aaec8(char*);
void ResetAndForwardCount2_021acd00(void*);
void CallField700ThenNotify_021afabc(struct ObjWithField4_021afabc*);
void CallField20PtrE_021c0550(void*);
void CallIfField1c_021c1220(void*);
void CallIfFieldCSet_0217f248(struct Obj0217f248*);
void CallHelperIfFlag_021b1d04(void*);
void NoOp_021b1f9c(void*);
void CallHelperIfFlagB_021b2368(void*);
void CallHelperIfFlag_021c166c(void*);
void CallIfField20_021c19e0(void*);
void ResetBattleScaleField_021be3b4(void*);
void BlankFunction_021a9fec(void*);
void ResetBattleScaleField_021bef4c(void*);
void ResetBattleScaleField_021bf360(void*);
void ResetBattleScaleField_021c1dfc(void*);
void ResetBattleScaleFieldAndDtor_021a925c(char*);
void RunBattleScaleStepAndFinalize_021a9638(void*);
void CallIfField20_021a99b0(struct S021a99b0*);
void ResetBattleScaleFieldAndDtor_021a79ac(char*);
void RunBattleScaleStepAndFinalize_020d844c(void*);
void DispatchField0xcHandler(struct Obj020dae80*);

struct EventHeader021a4368 {
    signed char kind;
    unsigned char inactive;
};

// USA: func_ov017_021a4368
extern "C" ARM void func_ov017_021a4368(void* unused, EventHeader021a4368* event) {
    if (!event || event->inactive) return;
    switch (event->kind) {
    case 1: ClearGlobalField_021adc44_021adc44(event); return;
    case 2: CallField1cIfFlagGt1_021a18a4(event); return;
    case 5: ForwardTeardownB_021b9928((char*)event); return;
    case 10: CallField6acPtrB_021b8450(event); return;
    case 12: CallIfGlobalPtrSet_021a5954(event); return;
    case 15: CallField20PtrB_021bae98(event); return;
    case 16: CallField1cPtrB_021babe0(event); return;
    case 17: CallCallbackIfField20Set_0217e598((int*)event); return;
    case 4: ForwardTeardown_021bb8f0((char*)event); return;
    case 18: CallHelperIfFlag_021b2f2c(event); return;
    case 23: CallIfField24_021b6b74((S021b6b74*)event); return;
    case 24: CallIfField1CSet_0217eef4((Obj0217eef4*)event); return;
    case 26: ResetAndForward_021aaec8((char*)event); return;
    case 31: ResetAndForwardCount2_021acd00(event); return;
    case 38: CallField700ThenNotify_021afabc((ObjWithField4_021afabc*)event); return;
    case 40: CallField20PtrE_021c0550(event); return;
    case 41: CallIfField1c_021c1220(event); return;
    case 42: CallIfFieldCSet_0217f248((Obj0217f248*)event); return;
    case 43: CallHelperIfFlag_021b1d04(event); return;
    case 44: NoOp_021b1f9c(event); return;
    case 45: CallHelperIfFlagB_021b2368(event); return;
    case 46: CallHelperIfFlag_021c166c(event); return;
    case 47: CallIfField20_021c19e0(event); return;
    case 51: ResetBattleScaleField_021be3b4(event); return;
    case 59: BlankFunction_021a9fec(event); return;
    case 52: ResetBattleScaleField_021bef4c(event); return;
    case 53: ResetBattleScaleField_021bf360(event); return;
    case 55: ResetBattleScaleField_021c1dfc(event); return;
    case 56: ResetBattleScaleFieldAndDtor_021a925c((char*)event); return;
    case 57: RunBattleScaleStepAndFinalize_021a9638(event); return;
    case 58: CallIfField20_021a99b0((S021a99b0*)event); return;
    case 63: ResetBattleScaleFieldAndDtor_021a79ac((char*)event); return;
    case 67: RunBattleScaleStepAndFinalize_020d844c(event); return;
    case 75: DispatchField0xcHandler((Obj020dae80*)event); return;
    }
}
