#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_02011430;

ARM int GetBit5cd0(S_02011430* owner, int floor, int containerSlot) {
    GameState* state = reinterpret_cast<GameState*>(owner);
    const unsigned char* flags = reinterpret_cast<const unsigned char*>(
        &state->unk_397d[0x5cd0 - 0x397d]);
    unsigned int bitIndex = containerSlot + (floor - 1) * 5;
    unsigned int byteIndex = bitIndex / 8;
    unsigned char mask = 1 << (bitIndex - byteIndex * 8);
    return (flags[byteIndex] & mask) != 0;
}
