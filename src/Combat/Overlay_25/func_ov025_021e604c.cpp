#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02049b54;
struct Obj02033874;

struct Vec3 {
    fix32_t v[3];
};

void* GetActiveCombatWork();
extern "C" int _Z23DispatchByIndex021820bcPviii(void* obj, int unused, int index, int arg);
void SetSubstructByte0x56(unsigned char* obj);
int GetWord0x0(int* obj);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
extern "C" void _Z20GetSubTriple02049b54P11Obj02049b54(struct Vec3* out, struct Obj02049b54* obj);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int arg);
void SetSubstructField0x8ClearFlag0x2(unsigned char* obj, int* src);
extern "C" void func_ov000_02161c0c(void* work, int id);
extern "C" void func_ov000_02167fb0(void* work, GameObject* obj);
extern "C" void func_ov000_021677fc(void* work);
extern "C" void* func_ov000_02160f14(void* work);
extern "C" int func_ov000_0215eb1c(void* obj, short* ids, int count, int flag);
extern "C" void __clear(void* dst, int size);

extern char data_ov025_021ef802[];

struct Formation021e604c {
    char pad[0x240];
    struct Vec3 center;
};

// JPN: func_ov025_021e64fc
// USA: func_ov025_021e604c
extern "C" ARM int func_ov025_021e604c(void* unused0, int b, int unused2, void* c) {
    int ids[8];
    struct Vec3 pos;
    Vector3fix rot;
    Vector3fix dir;
    struct Vec3 from;
    Vector3fix target;
    struct Vec3 center;
    short enemyIds[8];
    int j;
    int centerZ;
    int enemyCount;
    GameState* battle;
    GameState* bs = GameState::GetInstance();
    void* work = GetActiveCombatWork();
    if (work == NULL) {
        return 1;
    }
    int count = _Z23DispatchByIndex021820bcPviii(c, b, 0x18, (int)ids);
    for (int i = 0; i < count; i++) {
        GameObject* obj = bs->GetCombatantByIndex(ids[i]);
        if (obj != NULL) {
            func_ov000_02161c0c(work, ids[i]);
            SetSubstructByte0x56((unsigned char*)obj);
            func_ov000_02167fb0(work, obj);
            obj->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef802, 1);
        }
    }
    func_ov000_021677fc(work);
    struct Formation021e604c* formation = (struct Formation021e604c*)func_ov000_02160f14(work);
    battle = GameState::GetInstance();
    GetWord0x0((int*)battle);
    enemyCount = func_ov000_0215eb1c(c, enemyIds, 8, 0);
    center = formation->center;
    centerZ = center.v[2];
    for (j = 0; j < enemyCount; j++) {
        GameObject* enemy = GetCombatantWithFlag0x400(battle, enemyIds[j]);
        if (enemy != NULL) {
            __clear(&target, 0xc);
            target.z = centerZ;
            _Z20GetSubTriple02049b54P11Obj02049b54(&pos, (struct Obj02049b54*)enemy);
            from = pos;
            from.v[1] = 0;
            Vector3fix_Subtract(&target, (Vector3fix*)&from, &dir);
            dir.y = 0;
            Vector3fix_Normalize(&dir, &dir);
            int angle = fix32_Atan2(dir.x, dir.z);
            _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)enemy, angle);
            __clear(&rot, 0xc);
            rot.y = angle;
            SetSubstructField0x8ClearFlag0x2((unsigned char*)enemy, (int*)&rot);
        }
    }
    return 1;
}
