#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
int EnqueueEvent0x0C_020d1ee4(int a, int b, int c, int d);
extern "C" void func_020bcd30(void* obj, int flag);

struct Actor020bce2c {
    char pad0[0x24];
    int field24;
    char pad28[0x10];
    int field38;
    char pad3c[4];
    int field40;
    int field44;
};

// USA: func_020bce2c
ARM void ProcessPendingQueueIfRegistered(struct Actor020bce2c* obj) {
    if (!((obj->field24 << 30) >> 31)) {
        return;
    }
    if (obj->field38 != 0) {
        int flag = 1;
        do {
            unsigned int mask = DisableIRQInterrupts();
            func_020bcd30(obj, flag);
            SetIRQInterruptState(mask);
        } while (obj->field38 != 0);
    }
    EnqueueEvent0x0C_020d1ee4(obj->field44, 0, 1 << obj->field40, 0);
}
