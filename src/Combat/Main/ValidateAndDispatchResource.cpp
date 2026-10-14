#include <globaldefs.h>

void Fill3WordsWithFF_020b0318(int* p);
int ValidateResourceLookup0205a1f0(void* a, void* b, int c);
extern "C" void func_020b0594(int local, int zero, int tier, void* obj);
extern "C" void func_020b0368(int local, int val44, int tier, void* obj);

struct Obj0205aaf8 {
    int words[3];
    char pad0xc[0x38 - 0xc];
    int field0x38;
    char pad0x3c[0x44 - 0x3c];
    int field0x44;
    char pad0x48[0x50 - 0x48];
    unsigned char field0x50;
};

// USA: func_0205aaf8
ARM int ValidateAndDispatchResource(struct Obj0205aaf8* obj, void* param2, int param3) {
    int local;
    int tier;
    Fill3WordsWithFF_020b0318((int*)obj);
    if (ValidateResourceLookup0205a1f0(&local, param2, param3) != 0) {
        return 1;
    }
    tier = (obj->field0x50 == 0) ? 1 : 2;
    if (obj->field0x38 == 4) {
        func_020b0594(local, 0, tier, obj);
    } else {
        func_020b0368(local, obj->field0x44, tier, obj);
    }
    return 0;
}
