#include <globaldefs.h>
#include "GameState/GameState.h"

struct BattleState;
struct PartyState;
struct Container_021dae60;
struct SearchStruct;
struct S_10088;
struct FlagObj_021dce1c;

struct SlotWork {
    char pad0[0x1c];
    signed char state;
};

struct StatusFlags {
    char pad0[0x14];
    unsigned int flags;
};

struct CombatantView {
    char pad0[0x138];
    StatusFlags* status;
};

struct Ids4 {
    short v[4];
};

struct BlkSub {
    char data[0x48];
};

struct BattleBlk {
    char data[0x68];
    BlkSub sub;
};

extern "C" const Ids4 data_ov026_021de6cc;
extern "C" const Ids4 data_ov026_021de6d4;

extern "C" SearchStruct* func_0202ae18();
int ClassifyField0x81fe(char*);
int CheckField0NonZero(int*);
extern "C" int _Z13TestBitAt0x34Phj(PartyState*, unsigned char);
GameObject* GetCombatantWithFlag0x1000(GameState*, int);
extern "C" SlotWork* _Z21FindSlotById_021dae60P18Container_021dae60i(Container_021dae60*, int);
int TestBitBySignedByteIndex(SearchStruct*, int);
int GetSignedByte0x2d0(void*);
int IsFlag10088Set(S_10088*);
extern "C" int _Z22IsFlagBit8Set_021dce1cP16FlagObj_021dce1c(FlagObj_021dce1c*);
int CheckFlag0x14Bit0x10Set(unsigned char*);
extern "C" int func_ov000_0215f7a8(BattleState*, short*, unsigned char);
extern "C" int func_ov000_0215e9fc(BattleState*, short*, int, int);
extern "C" void _Z23LoadBattleBlock020ac4c0Pv(void*);
void AddClamped24BitFieldAt0x34(struct S_a0780*, unsigned int);
void AddClampedLow16BitFieldAt0xc(struct S_a0068*, unsigned int);
void AddClamped24BitFieldAt0x38(struct S_a07b0*, unsigned int);
void AddClampedHigh16BitFieldAt0xc(struct S_a00a4*, unsigned int);
void CopyInBattleField0x7540(void*);

// USA: func_ov026_021dd3dc
extern "C" ARM int func_ov026_021dd3dc(BattleState* battle, PartyState* party, Container_021dae60* list) {
    Ids4 cands;
    Ids4 picks;
    short alive[4];
    int results[4];
    BattleBlk blk;
    GameState* gs = GameState::GetInstance();
    SearchStruct* link = func_0202ae18();
    int i;
    int result;
    int count = 0;
    if (ClassifyField0x81fe((char*)battle) != 0) {
        return 1;
    }
    if (CheckField0NonZero((int*)link) == 0 || _Z13TestBitAt0x34Phj(party, count)) {
        result = 0;
        for (i = 0; i < 4; i++) {
            if (!_Z13TestBitAt0x34Phj(party, i)) continue;
            if (i != 0 && !GetCombatantWithFlag0x1000(gs, i)) continue;
            SlotWork* slot = _Z21FindSlotById_021dae60P18Container_021dae60i(list, i);
            if (!slot) continue;
            if (slot->state == 6) {
                result = 1;
                break;
            }
        }
        if (result == 0) {
            for (i = 0; i < 4; i++) {
                if (!_Z13TestBitAt0x34Phj(party, i)) continue;
                if (i != 0 && !GetCombatantWithFlag0x1000(gs, i)) continue;
                GameObject* c = gs->GetCombatantByIndex(i);
                if (!c) continue;
                if ((((CombatantView*)c)->status->flags & 0x80019) == 0) {
                    result = 2;
                    break;
                }
            }
        }
        results[count] = result;
        count++;
    }
    if (CheckField0NonZero((int*)link)) {
        for (i = 1; i < 4; i++) {
            if (!_Z13TestBitAt0x34Phj(party, i)) continue;
            if (GetCombatantWithFlag0x1000(gs, i)) continue;
            GameObject* c = gs->GetCombatantByIndex(i);
            if (!c) continue;
            SlotWork* slot = _Z21FindSlotById_021dae60P18Container_021dae60i(list, i);
            if (!slot) continue;
            int r = 0;
            if (slot->state == 6) {
                r = 1;
            } else if ((((CombatantView*)c)->status->flags & 0x80019) == 0) {
                r = 2;
            }
            results[count] = r;
            count++;
        }
    }
    int any = 0;
    for (int j = 0; j < count; j++) {
        if (results[j] == 1) any = 1;
    }
    if (any) {
        for (int j = 0; j < count; j++) {
            if (results[j] == 2) return 4;
        }
    }
    result = 1;
    for (int j = 0; j < count; j++) {
        if (results[j] == 1) {
            cands = data_ov026_021de6cc;
            int n = 0;
            int k;
            for (k = 0; k < 4; k++) {
                if (!_Z13TestBitAt0x34Phj(party, k)) continue;
                if (TestBitBySignedByteIndex(link, k)) {
                    cands.v[n] = k;
                    n++;
                }
            }
            for (k = 0; k < 4; k++) {
                if (!_Z13TestBitAt0x34Phj(party, k)) continue;
                GameObject* m = GetCombatantWithFlag0x1000(gs, k);
                if (!m) continue;
                if (TestBitBySignedByteIndex(link, GetSignedByte0x2d0(m))) {
                    cands.v[n] = k;
                    n++;
                }
            }
            picks = data_ov026_021de6d4;
            int x;
            int picked = 0;
            for (x = 0; x < n; x++) {
                short id = cands.v[x];
                GameObject* c = gs->GetCombatantByIndex(id);
                if (!c) continue;
                if (IsFlag10088Set((S_10088*)c)) continue;
                if (_Z22IsFlagBit8Set_021dce1cP16FlagObj_021dce1c((FlagObj_021dce1c*)c)) continue;
                if (CheckFlag0x14Bit0x10Set((unsigned char*)((CombatantView*)c)->status)) continue;
                if ((((CombatantView*)c)->status->flags & 0x80000) == 0) {
                    picks.v[picked] = id;
                    picked++;
                }
            }
            if (func_ov000_0215f7a8(battle, picks.v, picked)) {
                result = 2;
            } else {
                result = 3;
            }
            break;
        }
    }
    if (result != 1) {
        _Z23LoadBattleBlock020ac4c0Pv(&blk);
        BlkSub* sub = &blk.sub;
        AddClamped24BitFieldAt0x34((S_a0780*)&blk, 1);
        AddClampedLow16BitFieldAt0xc((S_a0068*)sub, 1);
        if (result == 2) {
            int n = func_ov000_0215e9fc(battle, alive, 4, 0);
            int found = 0;
            for (int j = 0; j < n; j++) {
                GameObject* c = gs->GetCombatantByIndex(alive[j]);
                if (!c) continue;
                if (IsFlag10088Set((S_10088*)c)) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                AddClamped24BitFieldAt0x38((S_a07b0*)&blk, 1);
                AddClampedHigh16BitFieldAt0xc((S_a00a4*)sub, 1);
            }
        }
        CopyInBattleField0x7540(&blk);
    }
    return result;
}
