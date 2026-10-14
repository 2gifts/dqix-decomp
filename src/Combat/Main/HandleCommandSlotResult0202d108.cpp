#include <globaldefs.h>

void SetField0x48UnlessState9Or10_0202c848(int arg);
extern char data_021015a0;
int SetState3AndInvokeHandler0202d180(void);
int TryTransitionState0202d224(void);

struct Struct0202d108 {
    char pad0[2];
    unsigned short field2;
};

// USA: func_0202d108  (semantic: HandleCommandSlotResult0202d108)
extern "C" ARM void func_0202d108(struct Struct0202d108* p) {
    unsigned short v = p->field2;
    if (v != 0) {
        SetField0x48UnlessState9Or10_0202c848(v);
        return;
    }
    *(int*)(&data_021015a0 + 0x10) = 1;
    if (*(unsigned short*)(&data_021015a0 + 0x4) == 0) {
        return;
    }
    *(unsigned short*)(&data_021015a0 + 0x4) = 0;
    if (*(int*)(&data_021015a0 + 0x30) != 0) {
        int r = SetState3AndInvokeHandler0202d180();
        if (r == 0) {
            *(int*)(&data_021015a0 + 0x10) = 9;
        }
        return;
    }
    {
        int r = TryTransitionState0202d224();
        if (r == 0) {
            *(int*)(&data_021015a0 + 0x10) = 9;
        }
    }
}
