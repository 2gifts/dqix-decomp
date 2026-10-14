#include <globaldefs.h>

struct Obj020415b0 {
    char pad[0xd0];
    int field_d0;
};

struct Obj02040b2c {
    char pad[0x18];
    struct Obj020415b0* field18;
};

void* GetGlobalPtr021075f4(void);
void* FindEntryPointerByKey0203df78(void* base, int key);
void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c* self, int value);
extern "C" int _Z28SetWordCCAndDispatch020415b0P11Obj020415b0i(struct Obj020415b0* obj, const char* name, int flags);

extern char data_ov004_021706f4[];

// USA: func_ov004_021684d4
extern "C" ARM int func_ov004_021684d4(void) {
    struct Obj02040b2c* entry = (struct Obj02040b2c*)FindEntryPointerByKey0203df78(GetGlobalPtr021075f4(), 0x67);
    if (!entry) {
        return 0;
    }
    if (entry->field18) {
        PropagateValueToActiveSlot02040b2c(entry, 0);
        entry->field18->field_d0 = 1;
        _Z28SetWordCCAndDispatch020415b0P11Obj020415b0i(entry->field18, data_ov004_021706f4, 1);
    }
    return 0;
}
