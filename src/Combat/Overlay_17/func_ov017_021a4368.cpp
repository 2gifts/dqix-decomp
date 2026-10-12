#include <globaldefs.h>

struct S021b6b74;
struct Obj0217eef4;
struct ObjWithField4_021afabc;
struct Obj0217f248;
struct S021a99b0;
struct Obj020dae80;
extern "C" void _Z34ClearGlobalField_021adc44_021adc44v();
extern "C" void _Z29CallField1cIfFlagGt1_021a18a4Pv(void*);
extern "C" void _Z25ForwardTeardownB_021b9928Pc(char*);
extern "C" void _Z25CallField6acPtrB_021b8450Pv(void*);
extern "C" void _Z27CallIfGlobalPtrSet_021a5954v();
extern "C" void _Z24CallField20PtrB_021bae98Pv(void*);
extern "C" void _Z24CallField1cPtrB_021babe0Pv(void*);
extern "C" void _Z33CallCallbackIfField20Set_0217e598Pi(int*);
extern "C" void _Z24ForwardTeardown_021bb8f0Pc(char*);
extern "C" void _Z25CallHelperIfFlag_021b2f2cv();
extern "C" void _Z22CallIfField24_021b6b74P9S021b6b74(struct S021b6b74*);
extern "C" void _Z25CallIfField1CSet_0217eef4P11Obj0217eef4(struct Obj0217eef4*);
extern "C" void _Z24ResetAndForward_021aaec8Pc(char*);
extern "C" void _Z30ResetAndForwardCount2_021acd00v();
extern "C" void _Z31CallField700ThenNotify_021afabcP22ObjWithField4_021afabc(struct ObjWithField4_021afabc*);
extern "C" void _Z24CallField20PtrE_021c0550Pv(void*);
extern "C" void _Z22CallIfField1c_021c1220Pv(void*);
extern "C" void _Z24CallIfFieldCSet_0217f248P11Obj0217f248(struct Obj0217f248*);
extern "C" void _Z25CallHelperIfFlag_021b1d04v();
extern "C" void _Z13NoOp_021b1f9cv();
extern "C" void _Z26CallHelperIfFlagB_021b2368v();
extern "C" void _Z25CallHelperIfFlag_021c166cv();
extern "C" void _Z22CallIfField20_021c19e0Pv(void*);
extern "C" void _Z30ResetBattleScaleField_021be3b4v();
extern "C" void _Z22BlankFunction_021a9fecv();
extern "C" void _Z30ResetBattleScaleField_021bef4cv();
extern "C" void _Z30ResetBattleScaleField_021bf360v();
extern "C" void _Z30ResetBattleScaleField_021c1dfcv();
extern "C" void _Z37ResetBattleScaleFieldAndDtor_021a925cPc(char*);
extern "C" void _Z38RunBattleScaleStepAndFinalize_021a9638v();
extern "C" void _Z22CallIfField20_021a99b0P9S021a99b0(struct S021a99b0*);
extern "C" void _Z37ResetBattleScaleFieldAndDtor_021a79acPc(char*);
void RunBattleScaleStepAndFinalize();
void DispatchField0xcHandler(struct Obj020dae80*);

struct EventHeader021a4368 {
    signed char kind;
    unsigned char inactive;
};

// USA: func_ov017_021a4368
extern "C" ARM void func_ov017_021a4368(void* unused, EventHeader021a4368* event) {
    if (!event || event->inactive) return;
    switch (event->kind) {
    case 1: ((void (*)(EventHeader021a4368*))_Z34ClearGlobalField_021adc44_021adc44v)(event); return;
    case 2: _Z29CallField1cIfFlagGt1_021a18a4Pv(event); return;
    case 5: _Z25ForwardTeardownB_021b9928Pc((char*)event); return;
    case 10: _Z25CallField6acPtrB_021b8450Pv(event); return;
    case 12: ((void (*)(EventHeader021a4368*))_Z27CallIfGlobalPtrSet_021a5954v)(event); return;
    case 15: _Z24CallField20PtrB_021bae98Pv(event); return;
    case 16: _Z24CallField1cPtrB_021babe0Pv(event); return;
    case 17: _Z33CallCallbackIfField20Set_0217e598Pi((int*)event); return;
    case 4: _Z24ForwardTeardown_021bb8f0Pc((char*)event); return;
    case 18: ((void (*)(EventHeader021a4368*))_Z25CallHelperIfFlag_021b2f2cv)(event); return;
    case 23: _Z22CallIfField24_021b6b74P9S021b6b74((S021b6b74*)event); return;
    case 24: _Z25CallIfField1CSet_0217eef4P11Obj0217eef4((Obj0217eef4*)event); return;
    case 26: _Z24ResetAndForward_021aaec8Pc((char*)event); return;
    case 31: ((void (*)(EventHeader021a4368*))_Z30ResetAndForwardCount2_021acd00v)(event); return;
    case 38: _Z31CallField700ThenNotify_021afabcP22ObjWithField4_021afabc((ObjWithField4_021afabc*)event); return;
    case 40: _Z24CallField20PtrE_021c0550Pv(event); return;
    case 41: _Z22CallIfField1c_021c1220Pv(event); return;
    case 42: _Z24CallIfFieldCSet_0217f248P11Obj0217f248((Obj0217f248*)event); return;
    case 43: ((void (*)(EventHeader021a4368*))_Z25CallHelperIfFlag_021b1d04v)(event); return;
    case 44: ((void (*)(EventHeader021a4368*))_Z13NoOp_021b1f9cv)(event); return;
    case 45: ((void (*)(EventHeader021a4368*))_Z26CallHelperIfFlagB_021b2368v)(event); return;
    case 46: ((void (*)(EventHeader021a4368*))_Z25CallHelperIfFlag_021c166cv)(event); return;
    case 47: _Z22CallIfField20_021c19e0Pv(event); return;
    case 51: ((void (*)(EventHeader021a4368*))_Z30ResetBattleScaleField_021be3b4v)(event); return;
    case 59: ((void (*)(EventHeader021a4368*))_Z22BlankFunction_021a9fecv)(event); return;
    case 52: ((void (*)(EventHeader021a4368*))_Z30ResetBattleScaleField_021bef4cv)(event); return;
    case 53: ((void (*)(EventHeader021a4368*))_Z30ResetBattleScaleField_021bf360v)(event); return;
    case 55: ((void (*)(EventHeader021a4368*))_Z30ResetBattleScaleField_021c1dfcv)(event); return;
    case 56: _Z37ResetBattleScaleFieldAndDtor_021a925cPc((char*)event); return;
    case 57: ((void (*)(EventHeader021a4368*))_Z38RunBattleScaleStepAndFinalize_021a9638v)(event); return;
    case 58: _Z22CallIfField20_021a99b0P9S021a99b0((S021a99b0*)event); return;
    case 63: _Z37ResetBattleScaleFieldAndDtor_021a79acPc((char*)event); return;
    case 67: ((void (*)(EventHeader021a4368*))RunBattleScaleStepAndFinalize)(event); return;
    case 75: DispatchField0xcHandler((Obj020dae80*)event); return;
    }
}
