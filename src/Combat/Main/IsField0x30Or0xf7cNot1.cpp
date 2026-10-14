#include <globaldefs.h>
#include "GameState/GameState.h"
void* GetPtrField0x2a04_02010828(GameState*);

// USA: func_02068650
ARM int IsField0x30Or0xf7cNot1_02068650(GameState* battleStruct, void* arg2) {
    signed char v = *(signed char*)((char*)arg2 + 0x30);
    if (v < 0) {
        v = *(signed char*)((char*)GetPtrField0x2a04_02010828((GameState*)(battleStruct)) + 0xf7c);
    }
    return v != 1;
}
