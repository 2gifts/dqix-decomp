#include <globaldefs.h>

extern "C" void func_0204b088(void* p, int flag);

struct Elem0207fd88 { char b[0x20]; };

struct Cont0207fd88 {
    #if defined(jpn)
    char pad0[0x20];
#else
    char pad0[0x2c];
#endif
    Elem0207fd88* list2c;
    char pad30[0x38 - 0x30];
    unsigned char count38;
};

// JPN: func_020808c4
// USA: func_0207fd88
ARM void CallFunc0204b088OverList0x2c(Cont0207fd88* obj) {
    unsigned char count;
    Elem0207fd88* p = obj->list2c;
    unsigned char i;
    if (p == NULL) return;
    count = obj->count38;
    for (i = 0; i < count; i++) {
        func_0204b088(p, 0);
        p++;
    }
}
