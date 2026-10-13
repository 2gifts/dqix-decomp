#include <globaldefs.h>

struct Table0221f7fc {
    int pad[11];
    int field2c;
};

extern Table0221f7fc data_ov031_0224f670;
extern "C" int func_ov031_0220cce4(void);
extern "C" int func_ov031_0221f630(void);
int DisableIRQInterrupts();
int SetIRQInterruptState(int);

// USA: func_ov031_0221f7fc
extern "C" THUMB int func_ov031_0221f7fc(void) {
    int oldState = DisableIRQInterrupts();
    if (data_ov031_0224f670.field2c == 3) {
        if (func_ov031_0220cce4() != 3) {
            SetIRQInterruptState(oldState);
            return 0;
        }
        data_ov031_0224f670.field2c = 2;
        SetIRQInterruptState(oldState);
        return 1;
    }
    if (func_ov031_0221f630() == 1) {
        data_ov031_0224f670.field2c = 2;
        SetIRQInterruptState(oldState);
        return 1;
    }
    SetIRQInterruptState(oldState);
    return 0;
}
