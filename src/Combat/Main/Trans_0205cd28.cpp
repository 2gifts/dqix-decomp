#if defined(jpn)
#define CONTROLLER_OFFSET_LO 4
#define CONTROLLER_OFFSET_HI 0x1800
#else
#define CONTROLLER_OFFSET_LO 0x9e0
#define CONTROLLER_OFFSET_HI 0x1000
#endif
#include <globaldefs.h>

struct Field440Obj0202f6a4;

void SetField0x1e20(void*, void*);
void InitSelfPointer(unsigned char*);
void SetupField440Type1(Field440Obj0202f6a4*);
int CheckField0x440State2(unsigned char*);
unsigned char* GetGlobalField0x1c020421a0();

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205cd28
ARM void SetupGlobalObjType1AndInitSelfPointer(unsigned char* self) {
    unsigned char* global = GetGlobalField0x1c020421a0();
    SetField0x1e20(global, self + 0xb4);
    if (CheckField0x440State2(global + CONTROLLER_OFFSET_LO + CONTROLLER_OFFSET_HI) == 0) {
        SetupField440Type1((Field440Obj0202f6a4*)(global + CONTROLLER_OFFSET_LO + CONTROLLER_OFFSET_HI));
    }
    InitSelfPointer(global);
}
