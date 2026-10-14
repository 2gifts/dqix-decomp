#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetFieldAt0x188_02053ccc(unsigned char*);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);

// USA: func_02064a9c
ARM int SetTargetFieldAndForEach02064a9c(void* param0, void* param1) {
    void* x = GetFieldAt0x188_02053ccc((unsigned char*)(GameState::GetInstance()->GetUnknownGameObject()));
    if (x != NULL) {
        if (*(int*)((char*)x + 4) == 3) {
            *(int*)((char*)param1 + 4) = *(unsigned char*)((char*)x + 0x2c);
        }
    } else {
        signed char b = *(signed char*)((char*)param0 + 0x491);
        if (b > -1) {
            *(int*)((char*)param1 + 4) = b;
        }
    }
    return LookupAndForEachNode020649b0(param0, 0x13, param1);
}
