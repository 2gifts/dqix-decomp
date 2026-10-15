#include <globaldefs.h>

struct Obj020415b0 {
    char pad[0xd0];
    int field_d0;
};

struct Obj02040b2c {
    char pad[0x18];
    struct Obj020415b0* field18;
};

void* GetGlobalPtr021075f4_0203cf4c(void);
void* FindEntryPointerByKey0203df78(void* base, int key);
void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c* self, int value);
int SetWordCCAndDispatch020415b0(Obj020415b0*, int, int);

extern char data_ov004_021706f7[];

// USA: func_ov004_0216856c
extern "C" ARM int func_ov004_0216856c(void) {
    struct Obj02040b2c* entry = (struct Obj02040b2c*)FindEntryPointerByKey0203df78(GetGlobalPtr021075f4_0203cf4c(), 0x67);
    if (entry) {
        PropagateValueToActiveSlot02040b2c(entry, 0x3244);
        entry->field18->field_d0 = 0;
        SetWordCCAndDispatch020415b0(entry->field18, (int)data_ov004_021706f7, 0);
    }
    return 0;
}
