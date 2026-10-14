#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
int GetBattleStateCode_020d41e8(void);
unsigned int SetIRQInterruptState(int mask);
void* GetBattleContext_020d41d8(void);

// USA: func_020d472c
ARM int SetBattleContextField0xc8IfIdle_020d472c(void* param) {
    unsigned int mask = DisableIRQInterrupts();
    int state = GetBattleStateCode_020d41e8();
    if (state != 0) {
        SetIRQInterruptState(mask);
        return state;
    }
    void* ctx = GetBattleContext_020d41d8();
    *(void**)((char*)ctx + 0xc8) = param;
    SetIRQInterruptState(mask);
    return 0;
}
