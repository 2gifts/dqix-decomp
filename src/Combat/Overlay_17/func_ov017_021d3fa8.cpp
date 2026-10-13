#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02033b68;
struct Bytes02033b88;
struct SubBlock02038508 {
    unsigned char enabled;
    unsigned char command;
};
struct AnimationPacket021d3fa8 {
    unsigned char padding_0[4];
    unsigned char command;
    unsigned char padding_5;
    unsigned char mode : 4;
    unsigned char reset : 4;
    unsigned char index;
    int time;
};
struct MemberState021d3fa8 {
    Object3D object;
    unsigned char padding_ac[0xc1 - 0xac];
    unsigned char flags : 2;
    unsigned char reserved : 6;
};
struct PartyOrder021d3fa8 { signed char members[4]; };
extern const PartyOrder021d3fa8 data_ov017_021d6cfc, data_ov017_021d6d08;
extern const char data_ov017_021d82b1[], data_ov017_021d82bb[], data_ov017_021d82c6[];
SubBlock02038508* GetFieldPtrAt0x26c(void*);
extern "C" void _Z17InitBlock02038508P16SubBlock02038508(SubBlock02038508*);
extern "C" void func_020dc548(signed char, PartyOrder021d3fa8*, signed char*);
void SetFlag0x1ceBit0x4(unsigned char*);
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(unsigned char*);
extern "C" int func_0202c540(void*);
extern "C" void _Z26CallHelperWithBuf_021907dciiiii(int, int, int, int, int);
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(Obj02033b68*, int);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);

// USA: func_ov017_021d3fa8
extern "C" ARM void func_ov017_021d3fa8(int unused, AnimationPacket021d3fa8* packet, GameState* game, void* globals, void* search) {
    GameObject* protagonist = game->GetUnknownGameObject();
    GameObject* member = game->GetPartyMemberByIndex(packet->index);
    SubBlock02038508* state = GetFieldPtrAt0x26c(member);
    unsigned short mode = packet->mode;
    int reset = packet->reset;
    int command = packet->command;
    int time = packet->time;
    if (member != 0 && reset != 0) {
        member->obj3D_.DisableFlag(0x1010);
        _Z17InitBlock02038508P16SubBlock02038508(state);
        PartyOrder021d3fa8 order = data_ov017_021d6cfc;
        signed char count = 0;
        func_020dc548((signed char)packet->index, &order, &count);
        for (int i = 0; i < count; i++) {
            if (order.members[i] == packet->index) continue;
            GameObject* other = game->GetPartyMemberByIndex(order.members[i]);
            if (other == 0) continue;
            unsigned int flags = ((MemberState021d3fa8*)other)->flags;
            if (!(flags & 2)) {
                other->obj3D_.position_ = member->obj3D_.position_;
                other->obj3D_.SetInheritedAlpha(31);
                SetFlag0x1ceBit0x4((unsigned char*)other);
            }
            _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)other);
        }
        if (func_0202c540(search)) _Z26CallHelperWithBuf_021907dciiiii((int)globals, 0, 1, 1, 1);
    }
    if (member == 0) return;
    unsigned int member_id = member->obj3D_.GetField06();
    if (member_id != protagonist->obj3D_.GetField06()) return;
    if (reset != 0 || (((MemberState021d3fa8*)member)->flags & 2)) {
        _Z17InitBlock02038508P16SubBlock02038508(state);
        if (reset != 0) {
            PartyOrder021d3fa8 order = data_ov017_021d6d08;
            signed char count = 0;
            func_020dc548((signed char)packet->index, &order, &count);
            for (int i = 0; i < count; i++) {
                if (order.members[i] == packet->index) continue;
                GameObject* other = game->GetPartyMemberByIndex(order.members[i]);
                if (other == 0) continue;
                unsigned int flags = ((MemberState021d3fa8*)other)->flags;
                if (!(flags & 2)) {
                    other->obj3D_.position_ = member->obj3D_.position_;
                    other->obj3D_.SetInheritedAlpha(31);
                    _Z24SetByteIfChanged02033b68P11Obj02033b68i((Obj02033b68*)other, 0);
                    SetFlag0x1ceBit0x4((unsigned char*)other);
                }
                _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)other);
            }
            if (func_0202c540(search)) _Z26CallHelperWithBuf_021907dciiiii((int)globals, 0, 1, 1, 1);
        }
    } else if (command == 0) {
        member->obj3D_.DisableFlag(0x1000);
        member->obj3D_.EnableFlag(0x10);
        member->obj3D_.MaybeSetRegularAnimation(data_ov017_021d82b1, 1);
        state->enabled = 1;
        state->command = 0;
    } else if (command == 1) {
        member->obj3D_.MaybeSetRegularAnimation(data_ov017_021d82b1, 1);
        state->enabled = 1;
        state->command = 1;
    } else if (command == 5) {
        member->obj3D_.DisableFlag(0x1010);
        SetByte0xbeShiftPrev((Bytes02033b88*)member, 1);
        state->enabled = 1;
        state->command = 5;
    } else if (command == 4) {
        member->obj3D_.DisableFlag(0x1010);
        member->obj3D_.MaybeSetRegularAnimation(data_ov017_021d82bb, 1);
        state->enabled = 1;
        state->command = 4;
    } else if (command == 2) {
        if (mode == 1) {
            member->obj3D_.DisableFlag(0x1000);
            member->obj3D_.EnableFlag(0x10);
            member->obj3D_.MaybeSetRegularAnimation(data_ov017_021d82c6, 0);
            if (time) member->obj3D_.SetCurrentAnimationTime(time);
            state->enabled = 1;
        } else if (mode == 2) {
            member->obj3D_.DisableFlag(0x1000);
            member->obj3D_.EnableFlag(0x10);
            member->obj3D_.MaybeSetRegularAnimation(data_ov017_021d82c6, 4);
            if (time) member->obj3D_.SetCurrentAnimationTime(time);
            state->enabled = 1;
        } else {
            member->obj3D_.EnableFlag(0x1010);
            member->obj3D_.MaybeSetRegularAnimation(data_ov017_021d82c6, 0);
            if (time) member->obj3D_.SetCurrentAnimationTime(time);
            state->enabled = 1;
        }
    }
}
