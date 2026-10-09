#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/CopyRecord0200fbb4.h"

struct Combatant02048260;
struct Combatant020482bc;
struct Bytes02033b88;
struct TailList020469b4;
struct TailNode020469b4;

struct Warp0219ff58 {
    short mapId;
    char field2;
    char pad3[4];
    char field7;
    char pad8[8];
    int pos[3];
    short angle;
    char pad1e[0x70 - 0x1e];
};

struct Status0219ff58 {
    unsigned int flags;
};

struct Combatant0219ff58 {
    unsigned char pad0[0x130];
    Status0219ff58* status;
    unsigned char pad134[0x18c - 0x134];
    unsigned int flags18c;
};

int CheckBitsInField0x63dc(void* obj, int mask);
void SetBitsInField0x63dc(void* obj, unsigned char mask);
int GetField0x3acValue(GameState* battleStruct);
extern "C" void func_02048150(void* combatant, int a, int b);
int RestoreMaxHpToFull(struct Combatant02048260* c);
int RestoreMaxMpToFull(struct Combatant020482bc* c);
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
extern "C" void _Z12SetByte0x1c8Phh(void* obj, int value);
void SetByte0x1c9(unsigned char* obj, unsigned char value);
void SetByteField0x253(void* obj);
extern "C" void func_ov017_021cedf4(int a, int b, int c);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0(void* obj);
void InitStruct02070378(char* obj);
void InitAndResetHeader_0219e310(unsigned char* obj, int flag);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_0219ff58
extern "C" ARM int func_ov017_0219ff58(unsigned char* ov, int flagA, int flagB, int revive) {
    GameState* battle = GameState::GetInstance();
    if (CheckBitsInField0x63dc(battle, 1) != 0) {
        if (revive != 0) {
            func_ov017_0218b5b0();
            signed char leader = GetField0x3acValue(battle);
            Combatant0219ff58* c = (Combatant0219ff58*)battle->GetPartyMemberByIndex(leader);
            if (c != NULL) {
                func_02048150(c, 0, 1);
                RestoreMaxHpToFull((struct Combatant02048260*)c);
                RestoreMaxMpToFull((struct Combatant020482bc*)c);
                c->flags18c &= ~1;
                SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
                if (c->status->flags & 1) {
                    _Z12SetByte0x1c8Phh(c, -1);
                    SetByte0x1c9((unsigned char*)c, 0);
                    SetByteField0x253(c);
                }
                func_ov017_021cedf4(leader, 1, 0);
                func_ov017_021c9e00(leader, 0, 0, 1);
            }
            for (signed char i = 0; i < 4; i++) {
                Combatant0219ff58* m = (Combatant0219ff58*)GetCombatantWithFlag0x1000(battle, i);
                if (m != NULL && leader == GetSignedByte0x2d0(m)) {
                    func_02048150(m, 0, 1);
                    RestoreMaxHpToFull((struct Combatant02048260*)m);
                    RestoreMaxMpToFull((struct Combatant020482bc*)m);
                    m->flags18c &= ~1;
                    SetByte0xbeShiftPrev((struct Bytes02033b88*)m, 0);
                    func_ov017_021cedf4(i, 1, 0);
                    func_ov017_021c9e00(i, 0, 0, 1);
                }
            }
        }

        if (flagA != 0) SetBitsInField0x63dc(battle, 2);
        if (flagB != 0) SetBitsInField0x63dc(battle, 4);
        if (revive != 0) SetBitsInField0x63dc(battle, 8);

        Warp0219ff58 warp;
        InitStruct02070378((char*)&warp);
        warp.mapId = 0x10d0;
        warp.field2 = revive == 0;
        warp.field7 = 1;
        warp.pos[0] = -0xf5;
        warp.pos[1] = 0x1199;
        warp.pos[2] = -0x30a3;
        warp.angle = 0x323d;
        _Z37CallFunc0200fbb4AtField0x3f8_0200fba4Pv(battle, &warp);

        if (flagB != 0) {
            InitAndResetHeader_0219e310(*(unsigned char**)(ov + 0x3000 + 0x70c), 0);
            AppendNodeToTail(*(struct TailList020469b4**)(ov + 0x3000 + 0x6fc),
                             *(struct TailNode020469b4**)(ov + 0x3000 + 0x70c));
        }
        return 1;
    }
    return 0;
}
