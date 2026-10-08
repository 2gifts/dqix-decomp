#include <globaldefs.h>

int DisableIRQInterrupts(void);
int SetIRQInterruptState(int);
int SendCommandToArm7(int, int, bool);

struct Ctx020cdae4 {
    char pad0[4];
    void (*fp4)(int, int, int);
    char pad8[0x10 - 8];
    unsigned short half10;
    unsigned short half12;
    int* ptr14;
    unsigned short half18;
    char pad1a[0x38 - 0x1a];
    unsigned short half38;
    unsigned short half3a;
};

struct Slot020cdae4 {
    int f0;
    unsigned short f4;
};

extern struct Ctx020cdae4 data_021117b0;

// USA: func_020cdae4
extern "C" ARM void func_020cdae4(int arg0, unsigned short arg1, int* arg2, unsigned short arg3) {
    unsigned int i;
    int state;
    int r;
    int r2;
    data_021117b0.ptr14 = arg2;
    data_021117b0.half10 = 0;
    data_021117b0.half12 = arg1;
    data_021117b0.half18 = arg3;
    i = 0;
    if (i < (unsigned int)arg3) {
        do {
            ((struct Slot020cdae4*)data_021117b0.ptr14)[i].f4 = 0;
            i++;
        } while (i < (unsigned int)arg3);
    }
    state = DisableIRQInterrupts();
    r = SendCommandToArm7(6, (arg1 & 0xff) | 0x2000100, 0);
    if (r < 0) {
        r = 0;
    } else {
        r2 = SendCommandToArm7(6, arg0 | 0x1010000, 0);
        if (r2 < 0) {
            r = 0;
        } else {
            r = 1;
        }
    }
    if (!(r & 0xff)) {
        SetIRQInterruptState(state);
        data_021117b0.half38 |= 2;
        if (data_021117b0.fp4) {
            data_021117b0.fp4(1, 4, 0);
        }
    } else {
        data_021117b0.half3a |= 2;
        data_021117b0.half38 &= ~2;
        SetIRQInterruptState(state);
    }
}