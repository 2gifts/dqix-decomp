#if defined(jpn)
enum { RegionOffset36fc = 0x34ec, RegionOffset38 = 0x58, RegionOffset3c = 0x5c };
#else
enum { RegionOffset36fc = 0x36fc, RegionOffset38 = 0x38, RegionOffset3c = 0x3c };
#endif

#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "Graphics/NSBXX/RenderConfig.h"

extern "C" void* func_02012fe4(void);

struct BitField0203402c;
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);

void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

struct S02037484;

void SyncBattleState0208f87c(void* self, int b, int c, int d);

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

    Vector3fix selfVec = ((Object3D*)combatant)->MaybeGetShadowSource();

    int mulResult = ((Object3D*)((struct S02037484*)combatant))->GetCombinedAlpha();
    float t = (float)f8c / 31.0f;
    int d = (int)(t * (float)mulResult);

    if (combatant != 0) {
        SubBlock02038508* base = GetFieldPtrAt0x26c_020399a8(combatant);
        if (base->active != 0) {
            base = GetFieldPtrAt0x26c_020399a8(combatant);
            unsigned char mode = base->command;
            if (mode == 1 || mode == 4) {
                d = base->unknown50;
            }
            if (mode == 2 || mode == 6) {
                d = base->unknown50;
                selfVec.y = base->unknown4c;
            }
        }
    }

    if (*(short*)((char*)GetField0x3f8Address_0200fd0c(battle) + 0x6c) == 0x270f) {
        if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)headArr) == 3) {
            d = 0;
        }
    }

    if (((Object3D*)combatant)->GetFlag(0x10) == 0) {
        int c = (int)(0.9f * (float)((Object3D*)((unsigned char*)combatant))->GetRadius());
        volatile int pad8 = 8;
        SyncBattleState0208f87c(&selfVec, tag, c, d);
    } else {
        RenderConfig::SubmitToFifo();
    }
}
