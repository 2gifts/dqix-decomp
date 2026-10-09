#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Matrix.h"

struct PartyState;
struct Bytes02033b88;

struct BattleCamera {
    char pad0[0x4];
    Vector3i eye;
    Vector3i target;
    char pad1c[0x54];
    Vector3i offset;
};

struct BattleWork {
    char pad0[0x2a0];
    PartyState* party;
    char pad2a4[0x7470];
    short taskId7714;
    char pad7716[0x8];
    short taskId771e;
    short taskId7720;
    char pad7722[0x2a];
    SafeAllocator cmdAlloc;
};

extern "C" int _Z13TestBitAt0x34Phj(PartyState* party, unsigned char bit);
int SetByte0xbeShiftPrev(Bytes02033b88* p, int val);
BattleCamera* GetField0x3b0Value(GameState* gs);
void SetField0x3b0Value(GameState* gs, int value);
void ClearCombatantSlot(GameState* gs, int id);
void ApplyVec3Tail(void* obj, int* vec);

extern "C" {
void* func_02057924();
void func_02057f00(void*, int);
BattleCamera* func_ov000_02160f14(BattleWork*);
void func_ov000_0216d370(BattleCamera*, int, int, int);
}

// USA: func_ov026_021dbba8
extern "C" ARM void func_ov026_021dbba8(BattleWork* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    func_02057f00(func_02057924(), 0x12);
    func_02057f00(func_02057924(), 0x1d);
    func_02057f00(func_02057924(), 0x1e);

    for (int i = 0; i < 4; i++) {
        if (_Z13TestBitAt0x34Phj(self->party, i)) {
            GameObject* member = GetCombatantWithFlag0x100(gs, i);
            if (member != NULL) {
                member->obj3D_.RemoveAnimationPackageByID(3);
                SetByte0xbeShiftPrev((Bytes02033b88*)member, 0);
            }
        }
    }

    BattleCamera* saved = GetField0x3b0Value(gs);
    BattleCamera* cam = func_ov000_02160f14(self);
    Vector3i offset = saved->offset;
    func_ov000_0216d370(cam, 1, 1, 1);
    cam->target = saved->target;
    ApplyVec3Tail(cam, &offset.x);
    cam->eye = saved->eye;
    SetField0x3b0Value(gs, (int)func_ov000_02160f14(self));
    ClearCombatantSlot(gs, 0xcf);

    loader->RemoveTask(self->taskId7714);
    loader->RemoveTask(self->taskId771e);
    loader->RemoveTask(self->taskId7720);
    self->taskId7714 = self->taskId771e = self->taskId7720 = -1;
    self->cmdAlloc.Reset();
}
