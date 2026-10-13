#include <globaldefs.h>

struct Ov027Work {
    char pad0[0x50d];
    unsigned char f50d;
    char pad1[0x526 - 0x50e];
    unsigned short f526;
    char pad2[0x5e4 - 0x528];
    unsigned int f5e4;
};

struct Ov027State {
    char pad[0x8];
    Ov027Work *work;
};

extern "C" void _Z25TailCallDispatch_021dcc80v(void);
extern Ov027State data_ov027_021e33e0;
extern "C" unsigned int _Z20DisableIRQInterruptsv();
extern "C" unsigned int _Z20SetIRQInterruptStatei(unsigned int);
extern "C" unsigned int _Z24UpdateEntryFlag_021dd55ci(unsigned int);
extern "C" void func_ov027_021db4e0(int a);
extern "C" int func_ov027_021dcc48(void);
extern "C" int func_ov027_021dd3b0(void);

// USA: func_ov027_021dcc8c  (semantic: Trans_021dcc8c)
extern "C" ARM int func_ov027_021dcc8c(void) {
    int result = 1;
    unsigned int irq = _Z20DisableIRQInterruptsv();
    Ov027Work *work = data_ov027_021e33e0.work;
    if (work->f50d == 0) {
        func_ov027_021db4e0(0);
    } else if (work->f526 == 0) {
        work->f5e4 = 0;
        data_ov027_021e33e0.work->f526 = 1;
        if (func_ov027_021dd3b0()) {
            _Z24UpdateEntryFlag_021dd55ci((unsigned int)_Z25TailCallDispatch_021dcc80v);
            result = 0;
        } else {
            result = func_ov027_021dcc48();
        }
    }
    _Z20SetIRQInterruptStatei(irq);
    return result;
}
