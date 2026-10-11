#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
int IsField0Null(void** obj);
struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
struct Vec3s32_020c3030 { int x; int y; int z; };
void Something_021a6b9c(int unused0, unsigned char byteVal);

// JPN: func_ov017_021d2184
// USA: func_ov017_021d1d00  (semantic: CheckProximityAndEnqueue_021d1d00)
extern "C" ARM void func_ov017_021d1d00(int unused0, int unused1, GameState* battleStruct, unsigned char* ov, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec};
#else
 enum {regionalOffset0=0x6fc};
#endif
    if (!GetSearchStructCurrentArrEntry(search)) return;
    void** list = *(void***)(ov + 0x3000 + regionalOffset0);
    if (!IsField0Null(list)) return;

    GameObject* c1 = battleStruct->GetPartyMemberByIndex(0);
    GameObject* c2 = battleStruct->GetUnknownGameObject();
    if (!c1 || !c2) return;
    if (_ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)c1) != _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)c2)) return;

    struct Vec3s32_020c3030 v1 = *(struct Vec3s32_020c3030*)((char*)c1 + 0x44);
    struct Vec3s32_020c3030 v2 = *(struct Vec3s32_020c3030*)((char*)c2 + 0x44);
    if (Vector3fix_Distance((const Vector3fix*)&v1, (const Vector3fix*)&v2) >= 0x7800) return;
    Something_021a6b9c((int)ov, 0);
}
