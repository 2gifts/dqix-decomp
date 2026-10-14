#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void* obj, int id);

struct Entry0217fe30 {
    char pad0[0x24];
    unsigned char flags0x24;
    char pad1[0x448 - 0x25];
};

// USA: func_ov000_0217fe30  (semantic: HasAnyFlaggedElement0217fe30)
extern "C" ARM int func_ov000_0217fe30(char* obj) {
    int result = 0;
    GameState* battle = GameState::GetInstance();
    char* ptr = (char*)GetPtrField0x2a04_02010828(battle);
    unsigned char limit = *(unsigned char*)(ptr + 0xf7c);
    unsigned char idx;
    for (idx = 0; idx < limit; idx++) {
        signed char id = *((signed char*)(ptr + idx + 0xf00) + 0x78);
        struct Entry0217fe30* entry = (struct Entry0217fe30*)func_ov000_02161318(obj, id);
        if (entry) {
            int bit = (entry->flags0x24 & 1) ? 1 : 0;
            result = (result | bit) ? 1 : 0;
        }
    }
    return result;
}
