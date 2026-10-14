#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov003_02160bf8  (semantic: FindEntryByKey_02160bf8)
extern "C" ARM void* func_ov003_02160bf8(void* obj, int key) {
    signed char* arr;
    unsigned char* p2000;
    unsigned char i;
    if (key < 0) {
        return 0;
    }
    p2000 = (unsigned char*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    arr = (signed char*)p2000 + 0xf80;
    p2000 += 0x2000;
    i = 0;
    while (i < p2000[0xc8c]) {
        signed char* elem = arr + i * 0x23c;
        int v = (*elem << 26) >> 26;
        if (key == v) {
            return elem;
        }
        i = (unsigned char)(i + 1);
    }
    return 0;
}
