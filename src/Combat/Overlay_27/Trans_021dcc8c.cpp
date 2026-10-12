#include <globaldefs.h>

extern int _Z25TailCallDispatch_021dcc80v;
extern int data_ov027_021e33e0;
extern "C" unsigned int _Z20DisableIRQInterruptsv();
extern "C" unsigned int _Z20SetIRQInterruptStatei(unsigned int);
extern "C" unsigned int _Z24UpdateEntryFlag_021dd55ci(unsigned int);
extern "C" unsigned int func_ov027_021db4e0(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov027_021dcc48();
extern "C" unsigned int func_ov027_021dd3b0(unsigned int, unsigned int);

// USA: func_ov027_021dcc8c  (semantic: Trans_021dcc8c)
extern "C" ARM unsigned int func_ov027_021dcc8c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r5 = 0x1;
    r0 = (unsigned int)_Z20DisableIRQInterruptsv();
    r1 = (unsigned int)&data_ov027_021e33e0;
    r4 = r0;
    r2 = *(unsigned int*)((char*)r1 + 0x8);
    if (*(unsigned char*)((char*)r2 + 0x50d) == 0) {
        r0 = 0x0;
        r0 = (unsigned int)func_ov027_021db4e0(r0, r1, r2);
    } else {
        r0 = r2 + 0x500;
        if (*(unsigned short*)((char*)r0 + 0x26) == 0) {
            r0 = 0x0;
            *(unsigned int*)((char*)r2 + 0x5e4) = (unsigned int)r0;
            r0 = *(unsigned int*)((char*)r1 + 0x8);
            r1 = r5;
            r0 = r0 + 0x500;
            *(unsigned short*)((char*)r0 + 0x26) = (unsigned short)r1;
            r0 = (unsigned int)func_ov027_021dd3b0(r0, r1);
            if (r0 != 0) {
                r0 = (unsigned int)&_Z25TailCallDispatch_021dcc80v;
                r0 = (unsigned int)_Z24UpdateEntryFlag_021dd55ci(r0);
                r5 = 0x0;
            } else {
                r0 = (unsigned int)func_ov027_021dcc48();
                r5 = r0;
            }
        }
    }
    r0 = r4;
    r0 = (unsigned int)_Z20SetIRQInterruptStatei(r0);
    r0 = r5;
    return r0;
}
