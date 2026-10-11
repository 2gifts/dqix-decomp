// JPN: func_ov017_0218e780
#if defined(jpn)
enum { RegionOffset36fc = 0x34ec, RegionOffset38 = 0x58, RegionOffset3c = 0x5c };
#else
enum { RegionOffset36fc = 0x36fc, RegionOffset38 = 0x38, RegionOffset3c = 0x3c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);


struct BitField0203402c;
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);

void* GetFieldPtrAt0x26c(void* obj);
void* GetField0x3f8Address(GameState* battleStruct);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

extern "C" int _ZNK8Object3D7GetFlagEi(void* obj, int mask);
extern "C" int _ZNK8Object3D9GetRadiusEv(unsigned char* obj);

struct Vec3_37774;
struct Src_37774;
extern "C" void _ZNK8Object3D20MaybeGetShadowSourceEv(struct Vec3_37774* dst, struct Src_37774* src);

struct S02037484;
extern "C" int _ZNK8Object3D16GetCombinedAlphaEv(struct S02037484* obj);

void SyncBattleState0208f87c(void* self, int b, int c, int d);
extern "C" void _ZN12RenderConfig12SubmitToFifoEv(void);

struct Vec3Local_0218dba0 { unsigned int v[3]; };

// USA: func_ov017_0218dba0  (semantic: SyncFlaggedCombatantState_0218dba0)
extern "C" ARM void func_ov017_0218dba0(int combatantId) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetPartyMemberByIndex(combatantId);
    if (combatant == 0) {
        return;
    }
    if (CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)combatant) != 0) {
        return;
    }

    unsigned short tag;
    int f8c;
    void* headArr;

    void* ovBase = func_ov017_0218b5b0();
    headArr = *(void**)((char*)ovBase + RegionOffset36fc);
    void* misc = func_02012fe4();
    tag = *(unsigned short*)((char*)misc + RegionOffset38);
    f8c = *(int*)((char*)misc + RegionOffset3c);

    struct Vec3Local_0218dba0 selfVec;
    struct Vec3Local_0218dba0 tmp;
    _ZNK8Object3D20MaybeGetShadowSourceEv((struct Vec3_37774*)&tmp, (struct Src_37774*)combatant);
    selfVec = tmp;

    int mulResult = _ZNK8Object3D16GetCombinedAlphaEv((struct S02037484*)combatant);
    float t = (float)f8c / 31.0f;
    int d = (int)(t * (float)mulResult);

    if (combatant != 0) {
        unsigned char* base = (unsigned char*)GetFieldPtrAt0x26c(combatant);
        if (base[0] != 0) {
            base = (unsigned char*)GetFieldPtrAt0x26c(combatant);
            unsigned char mode = base[1];
            if (mode == 1 || mode == 4) {
                d = *(short*)(base + 0x50);
            }
            if (mode == 2 || mode == 6) {
                d = *(short*)(base + 0x50);
                selfVec.v[1] = *(unsigned int*)(base + 0x4c);
            }
        }
    }

    if (*(short*)((char*)GetField0x3f8Address(battle) + 0x6c) == 0x270f) {
        if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)headArr) == 3) {
            d = 0;
        }
    }

    if (_ZNK8Object3D7GetFlagEi(combatant, 0x10) == 0) {
        int c = (int)(0.9f * (float)_ZNK8Object3D9GetRadiusEv((unsigned char*)combatant));
        volatile int pad8 = 8;
        SyncBattleState0208f87c(&selfVec, tag, c, d);
    } else {
        _ZN12RenderConfig12SubmitToFifoEv();
    }
}
