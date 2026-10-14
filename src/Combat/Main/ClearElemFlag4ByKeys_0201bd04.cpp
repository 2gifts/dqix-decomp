#include <globaldefs.h>

struct Obj0201b600;
struct Elem0201b600;
struct Struct02013380 { unsigned short unk0; unsigned short flags; };

Elem0201b600* FindElemByKeys(Obj0201b600*, int, unsigned short);
void SetFlag0x40AndToggle0x4(Struct02013380* obj, int unused, int clear4);

// USA: func_0201bd04  (semantic: ClearElemFlag4ByKeys_0201bd04)
extern "C" ARM void func_0201bd04(Obj0201b600* obj, unsigned int argA, int argB) {
    Elem0201b600* elem = FindElemByKeys(obj, argB, argA);
    int flag = 0;
    if (argB >= 0) flag = argB & 0xff;
    if (elem == 0) return;
    SetFlag0x40AndToggle0x4((Struct02013380*)elem, flag, 1);
}
