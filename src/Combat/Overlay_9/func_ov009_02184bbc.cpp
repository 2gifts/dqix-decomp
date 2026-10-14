#include <globaldefs.h>
#if defined(jpn)
#include "Resource/CharacterCreationUI.h"
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif

#if defined(jpn)
#define func_ov009_02184bbc func_ov009_02185ee8
#endif


struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;

void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
void CallFunc0204b04cOverList0x98(Cont0205d274*);

#if defined(jpn)
extern "C" void func_ov023_021da274(CharacterCreationUI* obj);
#else
extern "C" void func_ov023_021da274(void* obj);
#endif
#if defined(jpn)
extern "C" void func_ov023_021da770(CharacterCreationUI* obj);
#else
extern "C" void func_ov023_021da770(void* obj);
#endif
#if defined(jpn)
extern "C" void func_ov023_021da9b4(CharacterCreationUI* obj);
#else
extern "C" void func_ov023_021da9b4(void* obj);
#endif

// USA: func_ov009_02184bbc
extern "C" ARM void func_ov009_02184bbc(void* objRaw) {
    char* obj = (char*)objRaw;
    signed char id = *(signed char*)(obj + R(0xc1c, 0xc58));
    if (id == 0 || id == 0xc) {
        return;
    }

#if defined(jpn)
    func_ov023_021da274((CharacterCreationUI*)objRaw);
#else
    func_ov023_021da274(obj);
#endif
#if defined(jpn)
    func_ov023_021da770((CharacterCreationUI*)objRaw);
#else
    func_ov023_021da770(obj);
#endif
#if defined(jpn)
    func_ov023_021da9b4((CharacterCreationUI*)objRaw);
#else
    func_ov023_021da9b4(obj);
#endif

    if (*(signed char*)(obj + R(0xc1c, 0xc58)) != 0xa) {
        ClearBuffers0204b010OverList0x98((Cont0205d1e0*)(obj + R(0x1bc, 0x1f8)));
        CallFunc0204c8f0OverList0x9c((Cont0205d228*)(obj + R(0x1bc, 0x1f8)));
        CallFunc0204b04cOverList0x98((Cont0205d274*)(obj + R(0x1bc, 0x1f8)));
    }

    ClearBuffers0204b010OverList0x98((Cont0205d1e0*)(obj + R(0x278, 0x2b4)));
    CallFunc0204c8f0OverList0x9c((Cont0205d228*)(obj + R(0x278, 0x2b4)));
    CallFunc0204b04cOverList0x98((Cont0205d274*)(obj + R(0x278, 0x2b4)));
}
