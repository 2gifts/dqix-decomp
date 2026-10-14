#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
unsigned int GetBitsInField4_0203b4fc(unsigned int* obj, unsigned int mask);
struct ListNode0x2037a50;
extern "C" int _ZN8Object3D4DrawEb(void* obj, int flag);
struct Bits40_37464;

struct Vec3_37774 { int a[3]; };
struct Src_37774;
extern "C" void _ZNK8Object3D20MaybeGetShadowSourceEv(struct Vec3_37774* dst, struct Src_37774* src);
void SyncBattleState0208f87c(void* self, int b, int c, int d);

struct SyncLocal_021973e8 {
    int tag;
    struct Vec3_37774 vec;
};

#if defined(jpn)
enum { RegionOffset38 = 0x58, RegionOffset3c = 0x5c };
#else
enum { RegionOffset38 = 0x38, RegionOffset3c = 0x3c };
#endif

// USA: func_ov017_021973e8  (semantic: SyncCombatantsInRange_021973e8)
extern "C" ARM void func_ov017_021973e8(unsigned int* flagsObj) {
    GameState* bs = GameState::GetInstance();
    void* ctx = func_02012fe4();
    unsigned short field38 = *(unsigned short*)((char*)ctx + RegionOffset38);
    unsigned int field3c = *(unsigned int*)((char*)ctx + RegionOffset3c);

    if (GetBitsInField4_0203b4fc(flagsObj, 0x100) != 0) return;

    int flag9 = 1;
    if (GetBitsInField4_0203b4fc(flagsObj, 0x1000) != 0) {
        flag9 = 0;
    }

    int id;
    for (id = 0xa0; id < 0xc0; id++) {
        GameObject* c = bs->GetGameObjectByIndex(id);
        if (!c) continue;
        if (((Object3D*)((struct ListNode0x2037a50*)c))->IsChild()) continue;
        if (((Object3D*)c)->GetFlag(0x40000000) != 0) continue;
        ((Object3D*)((unsigned char*)c))->EnableFlag(4);
        if (!_ZN8Object3D4DrawEb(c, flag9)) continue;
        if (((Object3D*)c)->GetFlag(0x10) != 0) continue;

        int bits = ((Object3D*)((struct Bits40_37464*)c))->GetInheritedAlpha();
        int computed = (int)((float)field3c / 31.0f * (float)bits);

        struct SyncLocal_021973e8 local;
        _ZNK8Object3D20MaybeGetShadowSourceEv(&local.vec, (struct Src_37774*)c);
        int intAt64 = ((Object3D*)((unsigned char*)c))->GetRadius();
        local.tag = 8;
        SyncBattleState0208f87c(&local.vec, field38, intAt64, computed);
    }
}
