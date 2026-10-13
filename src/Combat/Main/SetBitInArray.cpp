#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define SetBitInArray func_02011118
extern "C" ARM void func_02011118(void* owner, int floor, int containerSlot);
#endif


ARM void SetBitInArray(void* owner, int floor, int containerSlot) {
    GameState* state = static_cast<GameState*>(owner);
    unsigned int bitIndex = (floor - 1) * 5 + containerSlot;
    unsigned int byteIndex = bitIndex / 8;
    unsigned char* flags = reinterpret_cast<unsigned char*>(
        &state->unk_397d[0x5cd0 - 0x397d]);
    flags[byteIndex] |= static_cast<unsigned char>(1 << (bitIndex - byteIndex * 8));
}
