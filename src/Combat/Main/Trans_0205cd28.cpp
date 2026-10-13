#if defined(jpn)
#define CONTROLLER_OFFSET_LO 4
#define CONTROLLER_OFFSET_HI 0x1800
#else
#define CONTROLLER_OFFSET_LO 0x9e0
#define CONTROLLER_OFFSET_HI 0x1000
#endif
#include <globaldefs.h>

struct Field440Obj0202f6a4;

extern "C" void _Z14SetField0x1e20PvS_(void*, void*);
extern "C" void _Z15InitSelfPointerPh(unsigned char*);
extern "C" void _Z18SetupField440Type1P19Field440Obj0202f6a4(Field440Obj0202f6a4*);
extern "C" int _Z21CheckField0x440State2Ph(unsigned char*);
extern "C" unsigned char* _Z26GetGlobalField0x1c020421a0v();

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205cd28
extern "C" ARM void _Z37SetupGlobalObjType1AndInitSelfPointerPh(unsigned char* self) {
    unsigned char* global = _Z26GetGlobalField0x1c020421a0v();
    _Z14SetField0x1e20PvS_(global, self + 0xb4);
    if (_Z21CheckField0x440State2Ph(global + CONTROLLER_OFFSET_LO + CONTROLLER_OFFSET_HI) == 0) {
        _Z18SetupField440Type1P19Field440Obj0202f6a4((Field440Obj0202f6a4*)(global + CONTROLLER_OFFSET_LO + CONTROLLER_OFFSET_HI));
    }
    _Z15InitSelfPointerPh(global);
}
