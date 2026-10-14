#include <globaldefs.h>

struct Ov027Work {
    char pad[0x1320];
    void *pending;
};

struct Ov027State {
    char pad[0xc];
    Ov027Work *work;
};

extern Ov027State data_ov027_021e33e0;
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int);
extern "C" void func_020c9be0(void);
extern "C" void func_ov027_021dcc8c(void);

// USA: func_ov027_021dcd20  (semantic: Trans_021dcd20)
extern "C" ARM void func_ov027_021dcd20(void) {
    unsigned int irq = DisableIRQInterrupts();
    if (data_ov027_021e33e0.work->pending == 0) {
        func_020c9be0();
    }
    func_ov027_021dcc8c();
    SetIRQInterruptState(irq);
}
