#include <globaldefs.h>

struct Obj020415b0 {
    char pad_00[0xcc];
    const char* animName;
    int animFlags;
};

struct Obj02040b2c {
    char pad_00[0x18];
    struct Obj020415b0* model;
};

void* GetGlobalPtr021075f4(void);
extern "C" void* _Z29FindEntryPointerByKey0203df78Pvi(void* base, int key);
extern "C" void _Z34PropagateValueToActiveSlot02040b2cP11Obj02040b2ci(struct Obj02040b2c* self, int value);
extern "C" int _Z28SetWordCCAndDispatch020415b0P11Obj020415b0i(struct Obj020415b0* obj, const char* name, int flags);

extern char data_ov004_021706f4[];

// USA: func_ov004_02168528
extern "C" ARM int func_ov004_02168528(void) {
    struct Obj02040b2c* entry = (struct Obj02040b2c*)_Z29FindEntryPointerByKey0203df78Pvi(GetGlobalPtr021075f4(), 0x67);
    if (entry) {
        _Z34PropagateValueToActiveSlot02040b2cP11Obj02040b2ci(entry, 0);
        entry->model->animFlags = 5;
        _Z28SetWordCCAndDispatch020415b0P11Obj020415b0i(entry->model, data_ov004_021706f4, 5);
    }
    return 0;
}
