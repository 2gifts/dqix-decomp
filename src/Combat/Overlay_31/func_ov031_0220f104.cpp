#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Mutex.h"
#include "System/Memory.h"
struct TransferState0220f104 {
    char pad[0xf00];
    char buffer[0x1360];
    int state;
    char pad2264[7];
    unsigned char busy;
};
struct TransferResult0220f104 { char pad[0x24]; int state; };
extern "C" TransferState0220f104* _Z24GetData0224e53c_0220d60cv();
extern "C" int _Z32SubmitBattleContextEntry020d5bfciPvS_j(int, void*, void*, unsigned int);
extern Mutex data_ov031_0224e54c;
extern BlockedContextList data_ov031_0224e544;
extern TransferResult0220f104 data_ov031_0224e540;
extern "C" void func_ov031_0220f28c();
// USA: func_ov031_0220f104
extern "C" ARM int func_ov031_0220f104(void* obj, void* first, unsigned int firstSize, void* second, int secondSize) {
    int irq = DisableIRQInterrupts();
    if (!_Z24GetData0224e53c_0220d60cv()) {
        SetIRQInterruptState(irq);
        return -1;
    }
    int total;
    LockMutex(&data_ov031_0224e54c);
    TransferState0220f104* state = _Z24GetData0224e53c_0220d60cv();
    if (!state) {
        UnlockMutex(&data_ov031_0224e54c);
        SetIRQInterruptState(irq);
        return -1;
    }
    if (state->state != 9 || state->busy == 1) {
        UnlockMutex(&data_ov031_0224e54c);
        SetIRQInterruptState(irq);
        return -4;
    }
    VectorizedInvertedMemcpy(first, state->buffer, firstSize);
    if (secondSize > 0) VectorizedInvertedMemcpy(second, state->buffer + firstSize, secondSize);
    total = firstSize + secondSize;
    switch (_Z32SubmitBattleContextEntry020d5bfciPvS_j((int)func_ov031_0220f28c, obj, state->buffer, (unsigned short)total)) {
    case 0: case 1: case 3: case 4: case 5: case 6: case 7: case 8: default:
        UnlockMutex(&data_ov031_0224e54c);
        SetIRQInterruptState(irq);
        return -5;
    case 2:
        break;
    }
    BlockCurrentContext(&data_ov031_0224e544);
    switch (data_ov031_0224e540.state) {
    case 0:
        break;
    case 1:
    default:
        UnlockMutex(&data_ov031_0224e54c);
        SetIRQInterruptState(irq);
        return -5;
    }
    UnlockMutex(&data_ov031_0224e54c);
    SetIRQInterruptState(irq);
    return total;
}
