#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj021d8c60;
struct Obj0203a588;

struct Obj020444e0 {
    char pad0[0x38];
    void* field38;
#if defined(jpn)
    char pad3C[0x868 - 0x3c];
#else
    char pad3C[0x998 - 0x3c];
#endif
    void* field998;
};

struct CombatWork02160c84 {
#if defined(jpn)
    char pad0[0xe24];
    int phase;
    char padEAC[0x371c - 0xe28];
    char battleField[0x5768 - 0x371c];
    void* combatEntry;
    void* field5578;
    char pad557C[0x5778 - 0x5770];
    struct Obj021d8c60* field5588;
    char pad558C[0x57bc - 0x577c];
    void* field55CC;
    char pad55D0[0x57e4 - 0x57c0];
    unsigned int flags;
    char pad55F8[0x71ec - 0x57e8];
#else
    char pad0[0xea8];
    int phase;
    char padEAC[0x3760 - 0xeac];
    char battleField[0x5574 - 0x3760];
    void* combatEntry;
    void* field5578;
    char pad557C[0x5588 - 0x557c];
    struct Obj021d8c60* field5588;
    char pad558C[0x55cc - 0x558c];
    void* field55CC;
    char pad55D0[0x55f4 - 0x55d0];
    unsigned int flags;
    char pad55F8[0x6ffc - 0x55f8];
#endif
    char field6FFC[1];
};

extern "C" void _Z29InitBuffersIfFlag431_021eb4b8Pv(void* obj);
extern "C" void _Z24DispatchAndFlush02175480Pv(void* obj);
extern "C" void _Z24ResetCombatEntry02184a58Pv(void* obj);
extern "C" void _Z27CallIfFieldNot0Or3_021d8c60P11Obj021d8c60(struct Obj021d8c60* obj);
struct Obj0203a588* GetData02104b6c(void);
int PeekInputLogB(void);
extern "C" struct Obj020444e0* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z31ReleaseField0x38IfValid020444e0P11Obj020444e0(struct Obj020444e0* obj);
extern "C" void func_ov013_02187784(void* obj);
extern "C" void func_ov000_02173954(char* obj);
extern "C" void func_0203a0b4(struct Obj0203a588* data);
extern "C" void func_ov000_0218251c(void* obj);
extern "C" void func_ov026_021dddcc(struct CombatWork02160c84* self);

// USA: func_ov000_02160c84
extern "C" ARM void func_ov000_02160c84(struct CombatWork02160c84* work) {
    if (work->flags & 0x200) {
        if (work->field55CC) {
            _Z29InitBuffersIfFlag431_021eb4b8Pv(work->field55CC);
        }
        if (work->combatEntry) {
            _Z24DispatchAndFlush02175480Pv(work->battleField);
            _Z24ResetCombatEntry02184a58Pv(work->combatEntry);
#if !defined(jpn)
            if (work->field5578) {
                func_ov013_02187784(work->field5578);
            }
#endif
        } else if (work->field5588) {
            _Z24DispatchAndFlush02175480Pv(work->battleField);
            _Z27CallIfFieldNot0Or3_021d8c60P11Obj021d8c60(work->field5588);
        } else if (!(work->flags & 0x40000)) {
            func_ov000_02173954(work->battleField);
        }
        func_0203a0b4(GetData02104b6c());
        func_ov000_0218251c(work->field6FFC);
        if (work->phase == 7 && PeekInputLogB() == 3) {
            func_ov026_021dddcc(work);
        }
    }
    GameState::GetInstance()->GetTickCount();
    struct Obj020444e0* global = _Z26GetGlobalField0x1c020421a0v();
    if (global->field998) {
        _Z31ReleaseField0x38IfValid020444e0P11Obj020444e0(global);
    }
}
