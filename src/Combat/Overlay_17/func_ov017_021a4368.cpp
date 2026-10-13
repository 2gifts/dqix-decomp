#include <globaldefs.h>

struct S021b6b74;
struct Obj0217eef4;
struct ObjWithField4_021afabc;
struct Obj0217f248;
struct S021a99b0;
struct Obj020dae80;
void ClearGlobalField_021adc44_021adc44(void*);
extern "C" void _Z29CallField1cIfFlagGt1_021a18a4Pv(void*);
extern "C" void _Z25ForwardTeardownB_021b9928Pc(char*);
extern "C" void _Z25CallField6acPtrB_021b8450Pv(void*);
void CallIfGlobalPtrSet_021a5954(void*);
extern "C" void _Z24CallField20PtrB_021bae98Pv(void*);
extern "C" void _Z24CallField1cPtrB_021babe0Pv(void*);
extern "C" void _Z33CallCallbackIfField20Set_0217e598Pi(int*);
extern "C" void _Z24ForwardTeardown_021bb8f0Pc(char*);
void CallHelperIfFlag_021b2f2c(void*);
extern "C" void _Z22CallIfField24_021b6b74P9S021b6b74(struct S021b6b74*);
extern "C" void _Z25CallIfField1CSet_0217eef4P11Obj0217eef4(struct Obj0217eef4*);
extern "C" void _Z24ResetAndForward_021aaec8Pc(char*);
void ResetAndForwardCount2_021acd00(void*);
extern "C" void _Z31CallField700ThenNotify_021afabcP22ObjWithField4_021afabc(struct ObjWithField4_021afabc*);
extern "C" void _Z24CallField20PtrE_021c0550Pv(void*);
extern "C" void _Z22CallIfField1c_021c1220Pv(void*);
extern "C" void _Z24CallIfFieldCSet_0217f248P11Obj0217f248(struct Obj0217f248*);
void CallHelperIfFlag_021b1d04(void*);
void NoOp_021b1f9c(void*);
void CallHelperIfFlagB_021b2368(void*);
void CallHelperIfFlag_021c166c(void*);
extern "C" void _Z22CallIfField20_021c19e0Pv(void*);
void ResetBattleScaleField_021be3b4(void*);
void BlankFunction_021a9fec(void*);
void ResetBattleScaleField_021bef4c(void*);
void ResetBattleScaleField_021bf360(void*);
void ResetBattleScaleField_021c1dfc(void*);
extern "C" void _Z37ResetBattleScaleFieldAndDtor_021a925cPc(char*);
void RunBattleScaleStepAndFinalize_021a9638(void*);
extern "C" void _Z22CallIfField20_021a99b0P9S021a99b0(struct S021a99b0*);
extern "C" void _Z37ResetBattleScaleFieldAndDtor_021a79acPc(char*);
void RunBattleScaleStepAndFinalize(void*);
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
    case 2: _Z29CallField1cIfFlagGt1_021a18a4Pv(event); return;
    case 5: _Z25ForwardTeardownB_021b9928Pc((char*)event); return;
    case 10: _Z25CallField6acPtrB_021b8450Pv(event); return;
    case 12: CallIfGlobalPtrSet_021a5954(event); return;
    case 15: _Z24CallField20PtrB_021bae98Pv(event); return;
    case 16: _Z24CallField1cPtrB_021babe0Pv(event); return;
    case 17: _Z33CallCallbackIfField20Set_0217e598Pi((int*)event); return;
    case 4: _Z24ForwardTeardown_021bb8f0Pc((char*)event); return;
    case 18: CallHelperIfFlag_021b2f2c(event); return;
    case 23: _Z22CallIfField24_021b6b74P9S021b6b74((S021b6b74*)event); return;
    case 24: _Z25CallIfField1CSet_0217eef4P11Obj0217eef4((Obj0217eef4*)event); return;
    case 26: _Z24ResetAndForward_021aaec8Pc((char*)event); return;
    case 31: ResetAndForwardCount2_021acd00(event); return;
    case 38: _Z31CallField700ThenNotify_021afabcP22ObjWithField4_021afabc((ObjWithField4_021afabc*)event); return;
    case 40: _Z24CallField20PtrE_021c0550Pv(event); return;
    case 41: _Z22CallIfField1c_021c1220Pv(event); return;
    case 42: _Z24CallIfFieldCSet_0217f248P11Obj0217f248((Obj0217f248*)event); return;
    case 43: CallHelperIfFlag_021b1d04(event); return;
    case 44: NoOp_021b1f9c(event); return;
    case 45: CallHelperIfFlagB_021b2368(event); return;
    case 46: CallHelperIfFlag_021c166c(event); return;
    case 47: _Z22CallIfField20_021c19e0Pv(event); return;
    case 51: ResetBattleScaleField_021be3b4(event); return;
    case 59: BlankFunction_021a9fec(event); return;
    case 52: ResetBattleScaleField_021bef4c(event); return;
    case 53: ResetBattleScaleField_021bf360(event); return;
    case 55: ResetBattleScaleField_021c1dfc(event); return;
    case 56: _Z37ResetBattleScaleFieldAndDtor_021a925cPc((char*)event); return;
    case 57: RunBattleScaleStepAndFinalize_021a9638(event); return;
    case 58: _Z22CallIfField20_021a99b0P9S021a99b0((S021a99b0*)event); return;
    case 63: _Z37ResetBattleScaleFieldAndDtor_021a79acPc((char*)event); return;
    case 67: RunBattleScaleStepAndFinalize(event); return;
    case 75: DispatchField0xcHandler((Obj020dae80*)event); return;
    }
}
