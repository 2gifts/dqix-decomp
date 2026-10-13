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
extern "C" ARM unsigned int _Z37SetupGlobalObjType3AndInitSelfPointerPh(unsigned int self) {
    unsigned int global = _Z26GetGlobalField0x1c020421a0v();
    _Z14SetField0x1e20PvS_(global, self + 0xb4);
    if (_Z15IsField440EmptyP7CE28Obj(global + stateLowOffset + stateHighOffset) == 0) {
        _Z18SetupField440Type3P19Field440Obj0202f6d4(global + stateLowOffset + stateHighOffset);
    }
    return _Z15InitSelfPointerPh(global);
}
