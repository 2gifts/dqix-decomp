#if defined(jpn)
#define CONTROLLER_OFFSET_LO 4
#define CONTROLLER_OFFSET_HI 0x1800
#else
#define CONTROLLER_OFFSET_LO 0x9e0
#define CONTROLLER_OFFSET_HI 0x1000
#endif
#include <globaldefs.h>

extern "C" unsigned int _Z14SetField0x1e20PvS_(unsigned int, unsigned int);
extern "C" unsigned int _Z15InitSelfPointerPh(unsigned int);
extern "C" unsigned int _Z18SetupField440Type1P19Field440Obj0202f6a4(unsigned int);
extern "C" unsigned int _Z21CheckField0x440State2Ph(unsigned int);
extern "C" unsigned int _Z26GetGlobalField0x1c020421a0v();

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_0205e058
// USA: func_0205cd28
extern "C" ARM unsigned int _Z37SetupGlobalObjType1AndInitSelfPointerPh(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r5 = r0;
    r0 = (unsigned int)_Z26GetGlobalField0x1c020421a0v();
    r4 = r0;
    r1 = r5 + 0xb4;
    r0 = (unsigned int)_Z14SetField0x1e20PvS_(r0, r1);
    r0 = r4 + CONTROLLER_OFFSET_LO;
    r0 = r0 + CONTROLLER_OFFSET_HI;
    r0 = (unsigned int)_Z21CheckField0x440State2Ph(r0);
    cc = (int)(r0) - (int)(0x0);
    if (cc != 0) { goto L38; }
    r0 = r4 + CONTROLLER_OFFSET_LO;
    r0 = r0 + CONTROLLER_OFFSET_HI;
    r0 = (unsigned int)_Z18SetupField440Type1P19Field440Obj0202f6a4(r0);
L38:;
    r0 = r4;
    r0 = (unsigned int)_Z15InitSelfPointerPh(r0);
    return r0;
}
