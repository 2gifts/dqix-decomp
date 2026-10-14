#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
int GetFieldIfFlag4_020100f8(char* obj);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
extern "C" short _Z22fix32ReduceAngle0To2Pii(int);
struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);
void SetHalf0xc6AndCopyVec3_02033e18(void* obj, int* src, short val);
struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

struct PosData_021bf628 {
    char pad0[8];
    int x, y, z;
    char pad1[0xc];
    short angle;
};

struct Vec3i_021bf628 { int x, y, z; };
struct CombatantPos_021bf628 { char pad[0x44]; struct Vec3i_021bf628 vec44; };

struct Obj_021bf628 {
    char pad0[0xc];
    struct PosData_021bf628* pos;
    char pad1[0x14 - 0x10];
    unsigned short field14;
    char pad2[0x28 - 0x16];
    int x28, x2c, x30;
};

// USA: func_ov017_021bf628  (semantic: RepositionCombatantFromPosData_021bf628)
extern "C" ARM int func_ov017_021bf628(struct Obj_021bf628* obj) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetUnknownGameObject();
    struct PosData_021bf628* pos = obj->pos;
    obj->x28 = pos->x;
    obj->x2c = pos->y;
    obj->x30 = pos->z;
    CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
    void* flagPtr = func_ov017_0218b5b0();
    int flagResult = GetFieldIfFlag4_020100f8((char*)battle);
    if (flagResult != 0) {
        ClearIntAt0x23c_020a27b8((unsigned char*)flagResult);
    }
    if (flagPtr != 0) {
        SetBitsInField4_0203b4d8((unsigned int*)flagPtr, 0x80);
    }
    SetVecYByMode02033834((struct Obj02033834*)combatant, _Z22fix32ReduceAngle0To2Pii(pos->angle));
    struct Vec3i_021bf628 vec = ((struct CombatantPos_021bf628*)combatant)->vec44;
    int* vecPtr = (int*)&vec;
    vec.x = pos->x;
    vec.z = pos->z;
    SetHalf0xc6AndCopyVec3_02033e18(combatant, vecPtr, 0xcc);
    SetByteIfChanged02033b68((struct Obj02033b68*)combatant, 1);
    obj->field14 = 5;
    return 1;
}
