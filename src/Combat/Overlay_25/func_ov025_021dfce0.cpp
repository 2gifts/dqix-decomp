#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatantEntry_021e1048 {
    unsigned char index;
    unsigned char adjustedIndex;
    char pad2[6];
    GameObject* object;
};
struct CombatWork {
    char pad0[0x29c];
    void* battle;
    char pad2a0[0x55d8-0x2a0];
    int firstSlot;
};
struct Obj02048c90;
extern "C" void _Z23ResetInnerState02048c90P11Obj02048c90(Obj02048c90*);
int GetSubstructByte0x4c(unsigned char*);
int GetSubstructByte0x4d(unsigned char*);
int GetSubstructByte0x56(unsigned char*);
void SetSubstructByte0x4c(unsigned char*, unsigned char);
void SetSubstructByte0x4d(unsigned char*, unsigned char);
extern "C" int _Z28FindSlotIndexByShort02162864Pvi(void*, int);
extern "C" int _Z39CollectMappedValuesFromNodeList02162908PviPi(void*, int, int*);
extern "C" int func_ov025_021e1048(void*, CombatantEntry_021e1048*);

inline int IsPartyActor(int id) { return id >= 0 && id <= 3; }
inline int IsMonsterActor(int id) { return id >= 0xc0 && id <= 0xc7; }

// USA: func_ov025_021dfce0
extern "C" ARM void func_ov025_021dfce0(CombatWork* work) {
    GameState* state = GameState::GetInstance();
    CombatantEntry_021e1048 entries[12];
    int count = func_ov025_021e1048(work->battle, entries);
    for (int i = 0; i < count; i++) {
        GameObject* actor = entries[i].object;
        _Z23ResetInnerState02048c90P11Obj02048c90((Obj02048c90*)actor);
        if (GetSubstructByte0x4c((unsigned char*)actor) != 0xff) {
            GameObject* target = state->GetCombatantByIndex(GetSubstructByte0x4c((unsigned char*)actor));
            if (!target) SetSubstructByte0x4c((unsigned char*)actor, 0xff);
            else if (!GetSubstructByte0x56((unsigned char*)target)) SetSubstructByte0x4c((unsigned char*)actor, 0xff);
        }
        if (GetSubstructByte0x4d((unsigned char*)actor) != 0xff) {
            GameObject* target = state->GetCombatantByIndex(GetSubstructByte0x4d((unsigned char*)actor));
            if (!target) SetSubstructByte0x4d((unsigned char*)actor, 0xff);
            else if (!GetSubstructByte0x56((unsigned char*)target)) SetSubstructByte0x4d((unsigned char*)actor, 0xff);
        }
    }
    for (int i = 0; i < count; i++) {
        GameObject* actor = entries[i].object;
        int targetId = GetSubstructByte0x4c((unsigned char*)actor);
        if (targetId != 0xff) continue;
        int mappedIds[12];
        if (work->firstSlot <= _Z28FindSlotIndexByShort02162864Pvi(work, entries[i].index)) {
            if (_Z39CollectMappedValuesFromNodeList02162908PviPi(work, _Z28FindSlotIndexByShort02162864Pvi(work, entries[i].index), mappedIds) > 0) {
                targetId = mappedIds[0];
                SetSubstructByte0x4c((unsigned char*)actor, targetId);
            }
        }
        if (targetId != 0xff) continue;
        Vector3i position = actor->obj3D_.position_;
        targetId = 0xff;
        int nearestDistance = 0x400000;
        for (int j = 0; j < count; j++) {
            if (!GetSubstructByte0x56((unsigned char*)entries[j].object)) continue;
            int otherId = entries[j].index;
            int actorId = entries[i].index;
            int sameSide;
            if (IsPartyActor(actorId) && IsPartyActor(otherId)) sameSide = 1;
            else if (IsMonsterActor(actorId) && IsMonsterActor(otherId)) sameSide = 1;
            else sameSide = 0;
            if (sameSide) continue;
            Vector3i targetPosition = entries[j].object->obj3D_.position_;
            int distance = Vector3fix_Distance(&position, &targetPosition);
            if (distance < nearestDistance) {
                targetId = entries[j].index;
                nearestDistance = distance;
            }
        }
        SetSubstructByte0x4d((unsigned char*)actor, targetId);
    }
}
