#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj021eb00c;
struct List02160094;
struct List021600f8;
struct Obj02033874;

struct Ctx021eb7fc {
    char pad0[0x1c4];
    unsigned int flags;
};

struct Field021eb7fc {
    char pad0[0x278];
    unsigned char ready;
    char pad279[3];
    void* slot;
};

struct Actor021eb7fc {
    char pad0[0xae];
    short facing;
};

struct Leader021eb7fc {
    char pad0[0x20];
    unsigned short id;
};

struct Target021eb7fc {
    char pad0[0xe];
    short id;
};

void* GetActiveCombatWork(void);
extern "C" struct Field021eb7fc* func_ov000_02160f14(void* work);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
extern "C" void _Z30SetFlagField_021eb00c_021eb00cP11Obj021eb00c(struct Obj021eb00c* obj);
extern "C" void _Z42ClearFlagIfParityMismatch02163710_02163710Pvi(void* obj, int flag);
extern "C" void func_ov025_021eb8e8(struct Ctx021eb7fc* ctx);
void ClearBitsInField4(unsigned int* p, unsigned int bits);
extern "C" struct Leader021eb7fc* _Z22GetNodeAtIndex02160094P12List02160094i(struct List02160094* list, int index);
extern "C" struct Target021eb7fc* _Z22GetNodeAtIndex021600f8P12List021600f8i(struct List021600f8* list, int index);
extern "C" struct Actor021eb7fc* _ZN9GameState19GetCombatantByIndexEi(GameState* gs, int idx);
extern "C" void func_02033920(struct Actor021eb7fc* obj, int id, int flag);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int arg);

// USA: func_ov025_021eb7fc
extern "C" ARM void func_ov025_021eb7fc(struct Ctx021eb7fc* ctx) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    void* work = GetActiveCombatWork();
    struct Field021eb7fc* field = func_ov000_02160f14(work);
    field->slot = _Z18GetSlotPtr02160f20Pv(work);
    _Z30SetFlagField_021eb00c_021eb00cP11Obj021eb00c((struct Obj021eb00c*)ctx);
    _Z42ClearFlagIfParityMismatch02163710_02163710Pvi(work, 0);
    func_ov025_021eb8e8(ctx);
    if (!(ctx->flags & 0x20)) {
        ClearBitsInField4((unsigned int*)res, 0x400);
        if (ctx->flags & 0x80) {
            void* list = _Z18GetSlotPtr02160f20Pv(work);
            struct Leader021eb7fc* leader = _Z22GetNodeAtIndex02160094P12List02160094i((struct List02160094*)list, 0);
            struct Target021eb7fc* target = _Z22GetNodeAtIndex021600f8P12List021600f8i((struct List021600f8*)list, 0);
            if (leader != 0 && target != 0) {
                struct Actor021eb7fc* actor = _ZN9GameState19GetCombatantByIndexEi(gs, leader->id);
                if (actor != 0) {
                    func_02033920(actor, target->id, 0);
                    _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)actor, actor->facing);
                }
            }
        }
        field->ready = 1;
    }
    ctx->flags |= 0x20;
}
