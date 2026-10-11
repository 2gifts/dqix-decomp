#include <globaldefs.h>
#include <GameState/GameState.h>

struct PackedStatus {
    int field0;
    unsigned short battleId;
    unsigned short entryId;
    unsigned int value0 : 3;
    unsigned int value1 : 3;
    unsigned int value2 : 3;
    unsigned int value3 : 3;
    unsigned int value4 : 3;
    unsigned int value5 : 3;
    unsigned int value6 : 3;
    unsigned int value7 : 3;
    unsigned int value8 : 3;
    unsigned int value9 : 3;
    unsigned int unused0 : 2;
    unsigned int value10 : 3;
    unsigned int value11 : 3;
    unsigned int value12 : 3;
    unsigned int value13 : 3;
    unsigned int value14 : 4;
    unsigned int unused1 : 16;
    unsigned char mode;
};
struct StatusEntry { char pad0[0x70]; unsigned char current[15]; char pad1[0x14]; unsigned char previous[15]; char pad2[2]; };
struct StatusOwner { char pad0[8]; unsigned short battleId; char pad1[0x20]; signed char owner; char pad2[0x12d]; StatusEntry entries[8]; };
struct BattleStatus { char pad[0x8e18]; StatusOwner* owner; };
struct BattleContext {
#if defined(jpn)
 char pad[0x3508];
#else
 char pad[0x3718];
#endif
 void* table; };
extern "C" void* _Z20GetField6b0_021b8470Pv(void*);
int GetField0x3acValue(GameState*);

// JPN: func_ov017_021cbe24
// USA: func_ov017_021cb974
extern "C" ARM void func_ov017_021cb974(int, PackedStatus* packet, GameState* game, BattleContext* context) {
    BattleStatus* status = (BattleStatus*)_Z20GetField6b0_021b8470Pv(context->table);
    StatusOwner* owner;
    if (!status || !(owner = status->owner)) return;
    if (owner->owner == GetField0x3acValue(game)) return;
    if (owner->battleId != packet->battleId) return;
    int index = packet->entryId - 0xc0;
    if (index < 0 || index >= 8) return;
    StatusEntry* target = &owner->entries[index];
    if (packet->mode == 1) {
        target->current[0] = packet->value0;
        target->current[1] = packet->value1;
        target->current[2] = packet->value2;
        target->current[3] = packet->value3;
        target->current[4] = packet->value4;
        target->current[5] = packet->value5;
        target->current[6] = packet->value6;
        target->current[7] = packet->value7;
        target->current[8] = packet->value8;
        target->current[9] = packet->value9;
        target->current[10] = packet->value10;
        target->current[11] = packet->value11;
        target->current[12] = packet->value12;
        target->current[13] = packet->value13;
        target->current[14] = packet->value14;
    } else {
        target->previous[0] = packet->value0;
        target->previous[1] = packet->value1;
        target->previous[2] = packet->value2;
        target->previous[3] = packet->value3;
        target->previous[4] = packet->value4;
        target->previous[5] = packet->value5;
        target->previous[6] = packet->value6;
        target->previous[7] = packet->value7;
        target->previous[8] = packet->value8;
        target->previous[9] = packet->value9;
        target->previous[10] = packet->value10;
        target->previous[11] = packet->value11;
        target->previous[12] = packet->value12;
        target->previous[13] = packet->value13;
        target->previous[14] = packet->value14;
    }
}
