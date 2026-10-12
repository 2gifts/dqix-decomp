#include <globaldefs.h>
#include "GameState/GameState.h"

struct Bytes02033b88;
struct PartyView0219cdc0 {
    Object3D object;
    char pad_ac[0x84];
    unsigned int* conditions;
    char pad_134[0x58];
    unsigned int flags;
};
struct GrottoIds0219cdc0 {
    char pad_00[0xf78];
    unsigned char ids[4];
    unsigned char count;
};
extern "C" void* func_0202ae18();
int GetField0x3acValue(GameState*);
extern "C" void func_02048150(GameObject*, int, int);
int SetByte0xbeShiftPrev(Bytes02033b88*, int);
extern "C" void func_ov017_021cedf4(int, int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);
GameObject* GetCombatantWithFlag0x1000(GameState*, int);
int GetSignedByte0x2d0(void*);
void CallHelperWithBuf_021907dc(int, int, int, int, int);
void ClearFlag0x1ceBit0x4(unsigned char*);
extern "C" int func_0202c508(void*);
void* GetPtrField0x2a04(GameState*);

static inline int Equal(unsigned short value, unsigned short key) { return value == key; }
static inline int NotEqual(unsigned short value, unsigned short key) { return !Equal(value, key); }

// USA: func_ov017_0219cdc0
extern "C" ARM void func_ov017_0219cdc0(unsigned short value, int wholeParty, signed char memberId) {
    GameState* state = GameState::GetInstance();
    void* search = func_0202ae18();
    GameResources* resources = func_ov017_0218b5b0();
    int special = !NotEqual(value, 10100);
    unsigned short category = (value / 100) * 100;
    int recover = (special | (category == 4100)) != 0;
    recover = (recover | (category == 4300)) != 0;
    recover = (recover | (category == 4500)) != 0;
    recover = (recover | (category == 6400)) != 0;
    int fullRecovery = (special | (category == 4300)) != 0;
    fullRecovery = (fullRecovery | (category == 6400)) != 0;
    int reviveParty = Equal(value, 50101) != 0;
    reviveParty = (reviveParty | (value == 50201)) != 0;
    reviveParty = (reviveParty | (value == 50301)) != 0;
    reviveParty = (reviveParty | (value == 50401)) != 0;
    if (recover) {
        int id = GetField0x3acValue(state);
        if (!wholeParty) id = memberId;
        PartyView0219cdc0* member = (PartyView0219cdc0*)state->GetPartyMemberByIndex(id);
        if (member && (*member->conditions & 1)) {
            if (fullRecovery) func_02048150((GameObject*)member, 1, 1);
            else func_02048150((GameObject*)member, 0, 1);
            member->flags &= ~1;
            SetByte0xbeShiftPrev((Bytes02033b88*)member, 0);
            if (wholeParty) {
                func_ov017_021cedf4(id, 1, 0);
                func_ov017_021c9e00(id, 0, 0, 1);
                func_ov017_02191108(resources, 1, 1, 1, 1);
            } else {
                if (state->GetPartyMemberByIndex(id)) {
                    GameObject* combatant = GetCombatantWithFlag0x1000(state, memberId);
                    if (combatant) id = GetSignedByte0x2d0(combatant);
                    CallHelperWithBuf_021907dc((int)resources, id, 1, 1, 1);
                    PartyView0219cdc0* linked = (PartyView0219cdc0*)state->GetPartyMemberByIndex(id);
                    if (linked) {
                        linked->object.SetInheritedAlpha(31);
                        ClearFlag0x1ceBit0x4((unsigned char*)linked);
                    }
                }
            }
        }
    }
    if (reviveParty && func_0202c508(search) && wholeParty) {
        GrottoIds0219cdc0* party = (GrottoIds0219cdc0*)GetPtrField0x2a04(state);
        PartyView0219cdc0* member;
        int allRevived;
        int i;
        int id;
        allRevived = 1;
        for (i = 0; i < party->count; i++) {
            id = party->ids[i];
            member = (PartyView0219cdc0*)state->GetPartyMemberByIndex(id);
            if (!member) continue;
            GameObject* object = state->GetGameObjectByIndex(id * 12 + 20);
            if (object && (object->obj3D_.unknown_2_ == 9031 || object->obj3D_.unknown_2_ == 9032 || object->obj3D_.unknown_2_ == 9033)) {
                if (*member->conditions & 1) {
                    func_02048150((GameObject*)member, 0, 1);
                    member->flags &= ~1;
                    SetByte0xbeShiftPrev((Bytes02033b88*)member, 0);
                    func_ov017_021cedf4(id, 1, 0);
                    func_ov017_021c9e00(id, 0, 0, 1);
                    func_ov017_02191108(resources, 1, 1, 1, 1);
                }
            } else if (id && !(*member->conditions & 1)) allRevived = 0;
        }
        if (allRevived && wholeParty) {
            PartyView0219cdc0* protagonist = (PartyView0219cdc0*)state->GetProtagonist();
            if (protagonist && (*protagonist->conditions & 1)) {
                func_02048150((GameObject*)protagonist, 0, 1);
                protagonist->flags &= ~1;
                SetByte0xbeShiftPrev((Bytes02033b88*)protagonist, 0);
                func_ov017_021cedf4(0, 1, 0);
                func_ov017_021c9e00(0, 0, 0, 1);
                func_ov017_02191108(resources, 1, 1, 1, 1);
            }
        }
    }
}
