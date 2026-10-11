// JPN: func_ov017_021d2fa8
#if defined(jpn)
enum { RegionOffset7f60 = 0x7c8c, RegionOffset734 = 0x524, RegionOffset718 = 0x508, RegionOffsetff = 0xfb };
#else
enum { RegionOffset7f60 = 0x7f60, RegionOffset734 = 0x734, RegionOffset718 = 0x718, RegionOffsetff = 0xff };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_021c3f68 {
    int x;
    int y;
    int z;
};
void SetVec3_021c3f68(struct Vec3_021c3f68* obj, int x, int y, int z);
unsigned short GetField6b4_021b8480(void* obj);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* dst, int a, int b, int c);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Evt021d2b24 {
    char pad0[4];
    unsigned char id;
    unsigned char flag5;
    char pad6[2];
    int field8;
    int fieldc;
    int field10;
};

struct Entry021d2b24 {
    char pad0[3];
    unsigned char field3;
    char pad4[RegionOffsetff];
    unsigned char field103;
};

// USA: func_ov017_021d2b24
extern "C" ARM void func_ov017_021d2b24(void* unused0, struct Evt021d2b24* evt, int unused2, void* ctxRaw) {
    unsigned char* ctx = (unsigned char*)ctxRaw;
    GameState* battle = GameState::GetInstance();

    if (evt->id == 0xce) {
        SetVec3_021c3f68((struct Vec3_021c3f68*)((char*)battle + RegionOffset7f60), evt->field8, evt->fieldc, evt->field10);
    }

    GameObject* combatant = battle->GetPartyMemberByIndex(evt->id);
    if (combatant == NULL) {
        return;
    }

    struct Entry021d2b24* entryPtr = *(struct Entry021d2b24**)(ctx + 0x3000 + RegionOffset734);
    if (entryPtr->field3 != 0 && entryPtr->field103 != 0) {
        return;
    }

    void* ptr718 = *(void**)(ctx + 0x3000 + RegionOffset718);
    if (*(unsigned char*)((char*)ptr718 + 0x2) != 0 && GetField6b4_021b8480(ptr718) == 0) {
        return;
    }

    ClearBytesAndZeroBlock02039d24((unsigned char*)combatant);
    SetFields0x44((struct Fields020407b4*)combatant, evt->field8, evt->fieldc, evt->field10);

    if (evt->flag5 != 0) {
        struct Vec3_021c3f68 tmp;
        SetVec3_021c3f68(&tmp, evt->field8, evt->fieldc, evt->field10);
        _ZN8Vector3iaSERKS_((int*)((char*)combatant + 0xd4), (int*)&tmp);
        *(unsigned char*)((char*)combatant + 0xe0) |= 0x20;
    }

    *(unsigned short*)((char*)combatant + 0xac) = 0;

    if (evt->id == 0xce) {
        SetFields0x44((struct Fields020407b4*)combatant, evt->field8, evt->fieldc, evt->field10);
    }
}
