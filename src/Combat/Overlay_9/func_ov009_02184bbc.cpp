#include <globaldefs.h>

#if defined(jpn)
#define func_ov009_02184bbc func_ov009_02185ee8
#endif

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;

void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
void CallFunc0204b04cOverList0x98(Cont0205d274*);

extern "C" void data_ov029_021da274(void* obj);
extern "C" void func_ov023_021da770(void* obj);
extern "C" void func_ov023_021da9b4(void* obj);

// USA: func_ov009_02184bbc
extern "C" ARM void func_ov009_02184bbc(void* objRaw) {
    char* obj = (char*)objRaw;
    signed char id = *(signed char*)(obj + 0xc58);
    if (id == 0 || id == 0xc) {
        return;
    }

    data_ov029_021da274(obj);
    func_ov023_021da770(obj);
    func_ov023_021da9b4(obj);

    if (*(signed char*)(obj + 0xc58) != 0xa) {
        ClearBuffers0204b010OverList0x98((Cont0205d1e0*)(obj + 0x1f8));
        CallFunc0204c8f0OverList0x9c((Cont0205d228*)(obj + 0x1f8));
        CallFunc0204b04cOverList0x98((Cont0205d274*)(obj + 0x1f8));
    }

    ClearBuffers0204b010OverList0x98((Cont0205d1e0*)(obj + 0x2b4));
    CallFunc0204c8f0OverList0x9c((Cont0205d228*)(obj + 0x2b4));
    CallFunc0204b04cOverList0x98((Cont0205d274*)(obj + 0x2b4));
}
