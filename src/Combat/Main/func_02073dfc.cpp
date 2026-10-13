#include <globaldefs.h>

#if defined(jpn)
enum { TargetIdOffset = 0x150, TargetPositionOffset = 0x154 };
#else
enum { TargetIdOffset = 0x15c, TargetPositionOffset = 0x160 };
#endif
#include "GameState/GameState.h"

struct Vec3_02073dfc { int x; int y; int z; };
struct Vec3s32_020c3030 { int x; int y; int z; };
struct U16Field0x6_020375f8 { char unk[0x6]; unsigned short field; };

extern "C" struct Vec3_02073dfc func_02034104(GameObject* combatant);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

// USA: func_02073dfc
extern "C" ARM int func_02073dfc(unsigned short* idPtr, struct Vec3s32_020c3030* distArg) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant;
    for (int i = 0; i < 4; i++) {
        combatant = battleStruct->GetPartyMemberByIndex(i);
        if (combatant == 0) continue;
        int targetId = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant);
        struct Vec3_02073dfc local = func_02034104(combatant);
        if (*(int*)((char*)combatant + TargetIdOffset) != -1) {
            targetId = *(int*)((char*)combatant + TargetIdOffset);
            if (i == 0 || (combatant->obj3D_.unknown_0_ & 0x1000)) {
                _ZN8Vector3iaSERKS_((int*)&local, (int*)((char*)combatant + TargetPositionOffset));
            }
        }
        if (*idPtr == targetId) {
            int dist = Vector3fix_Distance((const Vector3fix*)distArg, (const Vector3fix*)((struct Vec3s32_020c3030*)&local));
            if (dist < 0x3800) {
                return 1;
            }
        }
    }
    return 0;
}
