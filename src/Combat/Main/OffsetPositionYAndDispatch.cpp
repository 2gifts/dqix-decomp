#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vector3i;

struct Vec3i020a7eb8 {
    int x;
    int y;
    int z;
};

struct Obj020a7eb8 {
    char unk0[0x44];
    struct Vec3i020a7eb8 pos;
    char unk1[0x140 - 0x50];
    int field140;
};

extern "C" void func_02032fdc(struct Obj020a7eb8* obj, int a1, int a2);

// USA: func_020a7eb8
ARM void OffsetPositionYAndDispatch(struct Obj020a7eb8* obj) {
    GameState::GetInstance();
    struct Vec3i020a7eb8 tmp = obj->pos;
    tmp.y += obj->field140;
    *(Vector3i*)((int*)&obj->pos) = *(Vector3i const*)((int*)&tmp);
    func_02032fdc(obj, 1, 0);
    *(Vector3i*)((int*)&tmp) = *(Vector3i const*)((int*)&obj->pos);
    tmp.y -= obj->field140;
    *(Vector3i*)((int*)&obj->pos) = *(Vector3i const*)((int*)&tmp);
}
