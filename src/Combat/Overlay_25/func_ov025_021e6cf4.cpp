#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct List02160094;
struct List021600f8;
struct Struct020338d4;
struct Vec3;

struct ListNode02160094 {
    char pad0[0x20];
    unsigned short combatantIndex;
};

struct ListNode021600f8 {
    char pad0[0xe];
    short combatantIndex;
};

struct PairTask021e6cf4 {
    char pad0[8];
    unsigned char kind : 7;
    unsigned char faceEachOther : 1;
    unsigned char arg;
};

unsigned char* GetActiveCombatWork(void);
void RunFlaglearAndSetMode02167e6c_02167e6c(unsigned char* work);
void RunFlagPassAndSetMode02167dd8_02167dd8(unsigned char* work);
extern "C" void func_ov000_02167f10(unsigned char* work);
extern "C" void func_ov025_021def64(unsigned char* work, void* list, int arg);
ListNode02160094* GetNodeAtIndex02160094(List02160094* list, int index);
ListNode021600f8* GetNodeAtIndex021600f8(List021600f8* list, int index);
void SetThreeWords_021e4448(int* out, int x, int y, int z);
void AimAndSetVecY020338d4(Struct020338d4* obj, Vec3* target);

// USA: func_ov025_021e6cf4
extern "C" ARM int func_ov025_021e6cf4(PairTask021e6cf4* task, void* list) {
    unsigned char* work = GetActiveCombatWork();
    if (task->kind == 0) {
        RunFlaglearAndSetMode02167e6c_02167e6c(work);
    } else if (task->kind == 1) {
        RunFlagPassAndSetMode02167dd8_02167dd8(work);
    } else if (task->kind == 2) {
        GameState* gs = GameState::GetInstance();
        ListNode02160094* first = GetNodeAtIndex02160094((List02160094*)list, 0);
        ListNode021600f8* second = GetNodeAtIndex021600f8((List021600f8*)list, 0);
        if (first == NULL || second == NULL) {
            return 1;
        }
        GameObject* a = gs->GetCombatantByIndex(first->combatantIndex);
        GameObject* b = gs->GetCombatantByIndex(second->combatantIndex);
        if (a == NULL || b == NULL) {
            return 1;
        }
        Vector3fix posA;
        posA = a->obj3D_.position_;
        Vector3fix posB;
        posB = b->obj3D_.position_;
        posA.y = 0xcc;
        posB.y = 0xcc;
        Vector3fix delta;
        Vector3fix dir;
        if (Vector3fixSquaredDistance(&posA, &posB) > 0) {
            Vector3fix_Subtract(&posB, &posA, &delta);
            Vector3fix_Normalize(&delta, &dir);
        } else {
            SetThreeWords_021e4448(&delta.x, 0, 0, 0x1000);
            SetThreeWords_021e4448(&dir.x, 0, 0, 0x1000);
        }
        int dist = a->obj3D_.GetRadius() / 2 + 0x6000 + b->obj3D_.GetRadius() / 2;
        Vector3fix offA;
        Vector3fix offB;
        Vector3fixMultiplyScalar(&dir, -dist / 2, &offA);
        Vector3fixMultiplyScalar(&dir, dist / 2, &offB);
        func_ov000_02167f10(work);
        offA.y = 0xcc;
        offB.y = 0xcc;
        a->obj3D_.position_ = offA;
        b->obj3D_.position_ = offB;
        if (task->faceEachOther) {
            AimAndSetVecY020338d4((Struct020338d4*)a, (Vec3*)&offB);
            AimAndSetVecY020338d4((Struct020338d4*)b, (Vec3*)&offA);
        }
    } else if (task->kind == 3) {
        func_ov000_02167f10(work);
        func_ov025_021def64(work, list, task->arg);
    }
    return 1;
}
