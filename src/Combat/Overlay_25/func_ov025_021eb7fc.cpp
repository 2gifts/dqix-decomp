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

void* GetActiveCombatWork_ov000_02160130(void);
extern "C" struct Field021eb7fc* func_ov000_02160f14(void* work);
void* GetSlotPtr02160f20(void* obj);
void SetFlagField_021eb00c_021eb00c(struct Obj021eb00c* obj);
void ClearFlagIfParityMismatch02163710_02163710(void* obj, int flag);
extern "C" void func_ov025_021eb8e8(struct Ctx021eb7fc* ctx);
void ClearBitsInField4_0203b4e8(unsigned int* p, unsigned int bits);
struct Leader021eb7fc* GetNodeAtIndex02160094(struct List02160094* list, int index);
struct Target021eb7fc* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
extern "C" void func_02033920(struct Actor021eb7fc* obj, int id, int flag);
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

// USA: func_ov025_021eb7fc
extern "C" ARM void func_ov025_021eb7fc(struct Ctx021eb7fc* ctx) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    void* work = GetActiveCombatWork_ov000_02160130();
    struct Field021eb7fc* field = func_ov000_02160f14(work);
    field->slot = GetSlotPtr02160f20(work);
    SetFlagField_021eb00c_021eb00c((struct Obj021eb00c*)ctx);
    ClearFlagIfParityMismatch02163710_02163710(work, 0);
    func_ov025_021eb8e8(ctx);
    if (!(ctx->flags & 0x20)) {
        ClearBitsInField4_0203b4e8((unsigned int*)res, 0x400);
        if (ctx->flags & 0x80) {
            void* list = GetSlotPtr02160f20(work);
            struct Leader021eb7fc* leader = GetNodeAtIndex02160094((struct List02160094*)list, 0);
            struct Target021eb7fc* target = GetNodeAtIndex021600f8((struct List021600f8*)list, 0);
            if (leader != 0 && target != 0) {
                struct Actor021eb7fc* actor = (Actor021eb7fc*)gs->GetCombatantByIndex(leader->id);
                if (actor != 0) {
                    func_02033920(actor, target->id, 0);
                    SetVecYFromValue02033874((struct Obj02033874*)actor, actor->facing);
                }
            }
        }
        field->ready = 1;
    }
    ctx->flags |= 0x20;
}
