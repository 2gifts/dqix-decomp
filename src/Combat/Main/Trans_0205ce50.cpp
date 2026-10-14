#include <globaldefs.h>

#if defined(jpn)
enum { stateLowOffset = 4, stateHighOffset = 0x1800 };
#else
enum { stateLowOffset = 0x9e0, stateHighOffset = 0x1000 };
#endif

unsigned int SetField0x1e20(void*, void*);
unsigned int InitSelfPointer(unsigned char*);
struct CE28Obj;
unsigned int IsField440Empty(CE28Obj*);
struct Field440Obj0202f6d4;
unsigned int SetupField440Type3(Field440Obj0202f6d4*);
unsigned int GetGlobalField0x1c020421a0();

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205ce50
extern "C" ARM unsigned int _Z37SetupGlobalObjType3AndInitSelfPointerPh(unsigned int self) {
    unsigned int global = GetGlobalField0x1c020421a0();
    SetField0x1e20((void*)global, (void*)(self + 0xb4));
    if (IsField440Empty((CE28Obj*)(global + stateLowOffset + stateHighOffset)) == 0) {
        SetupField440Type3((Field440Obj0202f6d4*)(global + stateLowOffset + stateHighOffset));
    }
    return InitSelfPointer((unsigned char*)global);
}
