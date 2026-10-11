#include <globaldefs.h>

#if defined(jpn)
enum { stateLowOffset = 4, stateHighOffset = 0x1800 };
#else
enum { stateLowOffset = 0x9e0, stateHighOffset = 0x1000 };
#endif

extern "C" unsigned int _Z14SetField0x1e20PvS_(unsigned int, unsigned int);
extern "C" unsigned int _Z15InitSelfPointerPh(unsigned int);
extern "C" unsigned int _Z15IsField440EmptyP7CE28Obj(unsigned int);
extern "C" unsigned int _Z18SetupField440Type3P19Field440Obj0202f6d4(unsigned int);
extern "C" unsigned int _Z26GetGlobalField0x1c020421a0v();

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205ce50
extern "C" ARM unsigned int _Z37SetupGlobalObjType3AndInitSelfPointerPh(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r5 = r0;
    r0 = (unsigned int)_Z26GetGlobalField0x1c020421a0v();
    r4 = r0;
    r1 = r5 + 0xb4;
    r0 = (unsigned int)_Z14SetField0x1e20PvS_(r0, r1);
    r0 = r4 + stateLowOffset;
    r0 = r0 + stateHighOffset;
    r0 = (unsigned int)_Z15IsField440EmptyP7CE28Obj(r0);
    cc = (int)(r0) - (int)(0x0);
    if (cc != 0) { goto L38; }
    r0 = r4 + stateLowOffset;
    r0 = r0 + stateHighOffset;
    r0 = (unsigned int)_Z18SetupField440Type3P19Field440Obj0202f6d4(r0);
L38:;
    r0 = r4;
    r0 = (unsigned int)_Z15InitSelfPointerPh(r0);
    return r0;
}
