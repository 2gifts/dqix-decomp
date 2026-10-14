#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

extern char data_021142e0;

struct BattleContext020d46fc { unsigned char pad[0x14c]; int field_0x14c; };

// USA: func_020d46fc
ARM unsigned short GetBattleContextField0x14cLow16_020d46fc(void) {
    unsigned int mask = DisableIRQInterrupts();
    struct BattleContext020d46fc* ctx = *(struct BattleContext020d46fc**)(&data_021142e0 + 4);
    int value = ctx ? ctx->field_0x14c : 0;
    SetIRQInterruptState(mask);
    return (unsigned short)value;
}
