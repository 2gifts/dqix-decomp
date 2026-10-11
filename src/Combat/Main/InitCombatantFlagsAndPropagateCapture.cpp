#include <globaldefs.h>

struct Obj0208b4d4;
int ValidateCapturedValue0208b4d4(struct Obj0208b4d4* obj);

extern "C" void func_0208b0f8(void* obj);
extern "C" int func_0208ab34(void* ptr, int val);

struct Obj0208b088 {
    char pad0[0x20];
    int flag20;
    char pad1[0x9c - 0x24];
    unsigned char field9c;
};

// USA: func_0208b088
ARM int InitCombatantFlagsAndPropagateCapture(struct Obj0208b088* obj) {
    int captured;
    func_0208b0f8(obj);
    obj->flag20 = (obj->field9c == 0) ? 1 : 0;
    captured = ValidateCapturedValue0208b4d4((struct Obj0208b4d4*)obj);
    func_0208ab34((char*)obj + 0x4, captured);
    func_0208ab34((char*)obj + 0x24, captured);
    func_0208ab34((char*)obj + 0x40, captured);
    func_0208ab34((char*)obj + 0x5c, captured);
    func_0208ab34((char*)obj + 0x78, captured);
    return 1;
}
