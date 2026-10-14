#include <globaldefs.h>
#include "GameState/GameState.h"

struct Elem0217fb98 { char pad[0xf78]; unsigned char val; };

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
extern "C" void* func_ov000_02161318(void*, unsigned char);
int IsTurnCounterUnder100_ov000_0217f464(void* obj);

// USA: func_ov000_0217fb98
ARM int CountUnder100Flags0217fb98(void* obj) {
    int result = 0;
    unsigned char* base = (unsigned char*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    unsigned char count = base[0xf7c];
    unsigned char i;
    for (i = 0; i < count; i++) {
        struct Elem0217fb98* e = (struct Elem0217fb98*)(base + i);
        void* found = func_ov000_02161318(obj, e->val);
        if (found != NULL) {
            result |= IsTurnCounterUnder100_ov000_0217f464(found);
        }
    }
    return result;
}
