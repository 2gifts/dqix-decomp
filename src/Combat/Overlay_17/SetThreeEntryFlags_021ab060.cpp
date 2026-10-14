#include <globaldefs.h>

void SetSublistEntriesFlag1_02080b54(void* obj, int id);
int SetEntryFlagById02080b40(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);

struct Obj021ab060 {
    char pad0[0x18];
    void* p18;
    char pad1[0x4c - 0x1c];
    short s4c;
};

// USA: func_ov017_021ab060
ARM void SetThreeEntryFlags_021ab060(Obj021ab060* self) {
    int startId = 2;
    if (self->s4c == 1) {
        startId = 5;
    }
    void* p = self->p18;
    int i;
    SetSublistEntriesFlag1_02080b54(p, 1);
    for (i = 0; i < 3; i++) {
        SetEntryFlagById02080b40(p, startId);
        startId = (short)(startId + 1);
    }
    func_020813ec(p, 1);
}
