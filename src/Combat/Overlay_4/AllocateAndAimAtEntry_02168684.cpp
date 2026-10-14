#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Block0x88_02168684 { unsigned int w[0x88 / 4]; };
extern struct Block0x88_02168684 data_ov004_02170038;
extern "C" void func_ov011_02184a24(void* target, void* buf, int kind);

void* GetGlobalPtr021075f4_0203cf4c(void);
void* FindEntryPointerByKey0203df78(void* base, int key);

struct Vec3_020406f8 { unsigned int v[3]; };
struct Node020406f8;
void SelectVec3FromSources020406f8(struct Vec3_020406f8* dst, struct Node020406f8* n);

struct Vec3 { int x; int y; int z; };
struct Vector3i;
int Vector3fixAngleToPoint(Vector3i const*, Vector3i const*);
struct Vec3w0216 { unsigned int w[3]; };

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

// USA: func_ov004_02168684  (semantic: AllocateAndAimAtEntry_02168684)
extern "C" ARM void func_ov004_02168684(SafeAllocator* a, void* target) {
    struct Block0x88_02168684 tmp = data_ov004_02170038;
    void* buf = a->Allocate(0x88);
    memcpy(buf, &tmp, 0x88);
    func_ov011_02184a24(target, buf, 0x22);

    GameState* bs = GameState::GetInstance();
    void* entry = FindEntryPointerByKey0203df78(GetGlobalPtr021075f4_0203cf4c(), 0x67);
    if (!entry) return;
    GameObject* combatant = bs->GetUnknownGameObject();
    if (!combatant) return;

    struct Vec3_020406f8 tempVec;
    SelectVec3FromSources020406f8(&tempVec, (struct Node020406f8*)entry);
    struct Vec3w0216 selfPos;
    struct Vec3w0216 targetPos;
    targetPos = *(struct Vec3w0216*)&tempVec;
    selfPos = *(struct Vec3w0216*)((char*)combatant + 0x44);
    int angle = Vector3fixAngleToPoint((Vector3i const*)&selfPos, (Vector3i const*)&targetPos);
    SetVecYByMode02033834((struct Obj02033834*)combatant, angle);
}
