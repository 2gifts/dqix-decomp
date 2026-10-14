#include <globaldefs.h>
#include "GameState/GameState.h"
int GetByteField0x5721_02011538(GameState*);
void* GetPtrField0x2a04_02010828(GameState*);

// USA: func_0206852c
ARM int IsField0xf7cNotByteAt0x5721_0206852c(void* arg) {
    unsigned char* p = (unsigned char*)GetPtrField0x2a04_02010828((GameState*)(arg));
    int v = GetByteField0x5721_02011538((GameState*)(arg));
    return p[0xf7c] != v;
}
