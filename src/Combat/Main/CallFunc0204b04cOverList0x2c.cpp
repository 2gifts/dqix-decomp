#include <globaldefs.h>
#if defined(jpn)
enum { kPrefix = 0x20 };
#else
enum { kPrefix = 0x2c };
#endif

extern "C" void func_0204b04c(void* p, int flag);

struct Elem0207fd44 { char b[0x20]; };

struct Cont0207fd44 {
    char pad0[kPrefix];
    Elem0207fd44* list2c;
    char pad30[0x38 - 0x30];
    unsigned char count38;
};

// USA: func_0207fd44
ARM void CallFunc0204b04cOverList0x2c(Cont0207fd44* obj) {
    unsigned char count;
    Elem0207fd44* p = obj->list2c;
    unsigned char i;
    if (p == NULL) return;
    count = obj->count38;
    for (i = 0; i < count; i++) {
        func_0204b04c(p, 0);
        p++;
    }
}
