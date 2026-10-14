#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_021e75a4 { int x; int y; int z; };
struct Vec3;
struct Vec3_02030ef0;

extern "C" void* __clear(void* dst, int count);
struct Vector3i;
void Vector3fixDivideScalar(Vector3i const*, int, Vector3i*);
void ResetFields_021de110(void* obj);
struct Obj021eee48;
struct Rec021eee48;
void PushNodeFromFreeList_021eee48(struct Obj021eee48* obj, struct Rec021eee48* src);
extern char data_ov025_021ef834[];

struct Entry021e75a4 {
    int f0;
    int f4;
    short id;
    short val;
    int rel[3];
    void* next;
};

// USA: func_ov025_021e75a4  (semantic: RebaseAndQueueCombatantPositions_021e75a4)
extern "C" ARM int func_ov025_021e75a4(void* unused0, void* unused1, struct Obj021eee48* obj) {
    GameState* battle = GameState::GetInstance();
    void* arr[8];
    int validCount;
    void** slot;
    int i;

    slot = arr;
    validCount = 0;
    struct Vec3_021e75a4 accum;
    __clear(&accum, 0xc);
    for (int j = validCount; j < 8; slot++, j++) {
        GameObject* c = battle->GetGameObjectByIndex(j + 0xc0);
        *slot = c;
        if (c) {
            struct Vec3_021e75a4 tmp = *(struct Vec3_021e75a4*)((char*)c + 0x44);
            Vector3fix_Add((const Vector3fix*)((struct Vec3*)&accum), (const Vector3fix*)((struct Vec3*)&tmp), (Vector3fix*)((struct Vec3*)&accum));
            validCount++;
        }
    }
    Vector3fixDivideScalar((Vector3i const*)&accum, validCount << 0xc, (Vector3i*)&accum);

    slot = arr;
    for (i = 0; i < validCount; slot++, i++) {
        void* c = *slot;
        if (c) {
            struct Vec3_021e75a4* cv = (struct Vec3_021e75a4*)((char*)c + 0x44);
            struct Vec3_021e75a4 rel = *cv;
            rel.x = rel.x - accum.x;
            *(Vector3i*)((int*)cv) = *(Vector3i const*)((int*)&rel);
        }
    }

    accum.x = 0;
    struct Entry021e75a4 entry;
    for (i = 0; i < 8; i++) {
        short id = (short)(i + 0xc0);
        void* c = battle->GetGameObjectByIndex(id);
        if (!c) {
            continue;
        }
        ResetFields_021de110(&entry);
        entry.f0 = 0;
        entry.f4 = 0x12c;
        entry.id = id;
        entry.val = 0x12c;
        *(Vector3i*)((int*)entry.rel) = *(Vector3i const*)((int*)&accum);
        PushNodeFromFreeList_021eee48(obj, (struct Rec021eee48*)&entry);
        ((Object3D*)c)->MaybeSetRegularAnimation((char const*)data_ov025_021ef834, 0);
    }
    return 1;
}
