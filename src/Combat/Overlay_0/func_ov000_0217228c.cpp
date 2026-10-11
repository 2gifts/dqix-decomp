#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned char CopyOutRegion0x571d(char* obj, void* dst);
unsigned char CopyOutRegion0x5718(char* obj, void* dst);
extern "C" void __clear(void* dst, int count);
extern "C" void* func_ov000_02161318(void* obj, int index);
extern "C" int func_ov000_0217f5dc(void* entry);

struct Party0217228c {
    unsigned char pad0[0x6c];
    unsigned char order[4];
    signed char members[4];
    unsigned char pad74[5];
    unsigned char activeCount;
};

// USA: func_ov000_0217228c
extern "C" ARM void func_ov000_0217228c(struct Party0217228c* self) {
    GameState* state = GameState::GetInstance();
    unsigned char orderBuf[4];
    int count = CopyOutRegion0x571d((char*)state, orderBuf);
    unsigned char used[4];
    __clear(used, 4);
    for (int i = 0; i < count; i++) {
        self->order[i] = orderBuf[i];
        used[orderBuf[i]] = 1;
    }
    for (; count < 4; count++) {
        for (int j = 0; j < 4; j++) {
            if (used[j] == 0) {
                self->order[count] = j;
                used[j] = 1;
                break;
            }
        }
    }
#if defined(jpn)
    signed char memberBuf[4];
#else
    unsigned char memberBuf[4];
#endif
    unsigned char active = 0;
    int numMembers = CopyOutRegion0x5718((char*)state, memberBuf);
    for (int k = 0; k < 4; k++) {
#if defined(jpn)
        if (k < numMembers) {
            self->members[k] = memberBuf[k];
        } else {
            self->members[k] = -1;
        }
#else
        self->members[k] = -1;
        if (k < numMembers) {
            self->members[k] = memberBuf[k];
        }
#endif
        void* entry = func_ov000_02161318(self, self->members[k]);
        if (entry != NULL && func_ov000_0217f5dc(entry) != 0) {
            active++;
        }
    }
    self->activeCount = active;
}
