#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020696bc(int a, int* out, int c);
int GetGlobalField0x1c020421a0();

struct RingBuffer020457e8 {
    char unk0[0x186c];
    int slots[4];
    char unk187c[0x131];
    signed char cursor;
};
void PushToRingBuffer020457e8(struct RingBuffer020457e8* rb, int value);

struct Struct02069834 { void* ptr; };

// KEEP-NAME
// USA: func_02069834
ARM int StoreInputEmitFF1A02069834(Struct02069834* obj, int input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    PushToRingBuffer020457e8((struct RingBuffer020457e8*)GetGlobalField0x1c020421a0(), val);
    dst = obj->ptr;
    buf = 0xff1a;
    memcpy(dst, &buf, 2);
    return 2;
}
