#include <globaldefs.h>
#include "GameState/GameState.h"

struct Fields020407b4;

struct CombatantInfo150 {
    char unk_0[0x29c];
    unsigned int unk_29c_0 : 4;
    unsigned int poseIndex : 5;
};

struct PoseEntry02109a54 {
    unsigned char unk_0;
    unsigned char boneB;
    short posB[3];
    short rotB[3];
    unsigned char boneA;
    unsigned char unk_f;
    short posA[3];
    short rotA[3];
};

GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
CombatantInfo150* GetFieldAt0x150_02053c6c(unsigned char* obj);
PoseEntry02109a54* GetGlobal02109a54_02099f60(void);
int GetByteFieldAt0x1a0_02053eb4(void*, int);
void SetByteFieldAt0x1a7_02053ec0(unsigned char*, int);
void SetFields0x44(Fields020407b4* dst, int a, int b, int c);
void StoreVec3AtField0x50_0203db34(unsigned char* obj, int a, int b, int c);

// USA: func_ov017_021917f0
extern "C" ARM void func_ov017_021917f0(int idx, int mode) {
#if defined(jpn)
 enum { regionalOffset = 0x180 };
#else
 enum { regionalOffset = 0x18c };
#endif
    GameState* gs = GameState::GetInstance();
    CombatantInfo150* info;
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(gs, idx);
    GameObject* obj = gs->GetGameObjectByIndex(idx * 12 + 0x1c);
    if (combatant == NULL || obj == NULL) return;
    info = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (info == NULL) return;
    PoseEntry02109a54* entry = &GetGlobal02109a54_02099f60()[info->poseIndex];
    if (mode == 1) {
        int bone = GetByteFieldAt0x1a0_02053eb4(combatant, entry->boneA);
        SetByteFieldAt0x1a7_02053ec0((unsigned char*)combatant, bone);
        SetFields0x44((Fields020407b4*)obj, entry->posA[0], entry->posA[1], entry->posA[2]);
        StoreVec3AtField0x50_0203db34((unsigned char*)obj, entry->rotA[0], entry->rotA[1], entry->rotA[2]);
        obj->obj3D_.Detach();
        obj->obj3D_.Attach(&combatant->obj3D_, bone);
        if (entry->rotA[0] != 0 || entry->rotA[1] != 0 || entry->rotA[2] != 0) {
            obj->obj3D_.SetFlag16();
        } else {
            obj->obj3D_.ClearFlag16();
        }
    } else if (mode == 0) {
        int bone = GetByteFieldAt0x1a0_02053eb4(combatant, entry->boneB);
        SetByteFieldAt0x1a7_02053ec0((unsigned char*)combatant, bone);
        SetFields0x44((Fields020407b4*)obj, entry->posB[0], entry->posB[1], entry->posB[2]);
        StoreVec3AtField0x50_0203db34((unsigned char*)obj, entry->rotB[0], entry->rotB[1], entry->rotB[2]);
        obj->obj3D_.Detach();
        obj->obj3D_.Attach(&combatant->obj3D_, bone);
        if (entry->rotB[0] != 0 || entry->rotB[1] != 0 || entry->rotB[2] != 0) {
            obj->obj3D_.SetFlag16();
        } else {
            obj->obj3D_.ClearFlag16();
        }
    }
    unsigned int* flags = (unsigned int*)((char*)combatant + regionalOffset);
    if (info->poseIndex == 6) {
        *flags |= 0x20;
    } else {
        *flags &= ~0x20;
    }
    if (obj->obj3D_.unknown_2_ < 0) {
        obj->obj3D_.MakeHidden();
    } else {
        obj->obj3D_.MakeVisible();
    }
}
