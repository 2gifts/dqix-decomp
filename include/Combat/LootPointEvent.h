#pragma once

union LootPointState {
    unsigned int word;
    struct {
        unsigned int timer : 9;
        unsigned int unknown9Low : 4;
        unsigned int unknown9High : 4;
        unsigned int flags : 8;
        unsigned int count : 4;
        unsigned int kind : 2;
        unsigned int active : 1;
    } fields;
};

typedef char LootPointStateSizeCheck[sizeof(LootPointState) == 4 ? 1 : -1];

void EnqueueEventTag183_021d38f8(unsigned char mode, signed char partySlot,
                               unsigned char mask, unsigned char pointId,
                               const LootPointState* packedState);
