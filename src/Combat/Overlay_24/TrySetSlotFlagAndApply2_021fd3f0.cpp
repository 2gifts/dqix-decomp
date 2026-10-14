#include <globaldefs.h>

struct S88514;
int CheckFlag0x2AndState2_02088514(struct S88514* obj);

struct Ptr668Obj_021fd3f0 {
    char unk[0x138];
    struct S88514* inner138;
};

struct Obj_021fd3f0 {
    char unk[0x661];
    unsigned char flag661;
    char unk2[0x668 - 0x661 - 1];
    struct Ptr668Obj_021fd3f0* ptr668;
};

extern "C" void func_ov024_021fd160(void* obj, int mode);

// USA: func_ov024_021fd3f0
ARM void TrySetSlotFlagAndApply2_021fd3f0(struct Obj_021fd3f0* obj) {
    if (CheckFlag0x2AndState2_02088514(obj->ptr668->inner138)) {
        if (!obj->flag661) {
            func_ov024_021fd160(obj, 2);
        }
    }
}
