#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

class StateMachine021bb1a4 {
public:
    char unk_0[0xa];
    unsigned short state_;
    char unk_c[0xff - 0xc];
    unsigned char checkExit_;
    char unk_100[0x120 - 0x100];
    void* timer_;
};

typedef unsigned short (StateMachine021bb1a4::*StateFn021bb1a4)(int);

extern StateFn021bb1a4 data_ov017_021d7ccc[20];
extern unsigned int data_ov017_021d845c;
extern StateFn021bb1a4 data_020e6d5c;

extern "C" void func_0208bb78(void* timer, unsigned int ticks);
unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
int PopStack0AndTrigger(int flag);
extern "C" void func_020a0c0c(void);

// USA: func_ov017_021bb1a4
extern "C" ARM void func_ov017_021bb1a4(StateMachine021bb1a4* self, int arg) {
    if (!(data_ov017_021d845c & 1)) {
        data_ov017_021d7ccc[19] = data_020e6d5c;
        data_ov017_021d845c |= 1;
    }

    if (self->timer_ != 0) {
        func_0208bb78(self->timer_, GameState::GetInstance()->GetTickCount());
    }

    if (data_ov017_021d7ccc[self->state_] != 0) {
        self->state_ = (self->*data_ov017_021d7ccc[self->state_])(arg);
    }

    if (self->checkExit_ != 0) {
        if (GetBitsInField0(&func_ov017_0218b5b0()->brightnessFlags_0, 0x1000) == 0) {
            PopStack0AndTrigger(1);
            func_020a0c0c();
        }
    }
}
