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

void* GetGlobalPtr021075f4_0203cf4c(void);
void* FindEntryPointerByKey0203df78(void* base, int key);
void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c* self, int value);
int SetWordCCAndDispatch020415b0(Obj020415b0*, int, int);

extern char data_ov004_021706fd[];

// USA: func_ov004_021685b4
extern "C" ARM int func_ov004_021685b4(void) {
    struct Obj02040b2c* entry = (struct Obj02040b2c*)FindEntryPointerByKey0203df78(GetGlobalPtr021075f4_0203cf4c(), 0x67);
    if (entry) {
        PropagateValueToActiveSlot02040b2c(entry, 0);
        entry->model->animFlags = 1;
        SetWordCCAndDispatch020415b0(entry->model, (int)data_ov004_021706fd, 1);
    }
    return 0;
}
