#include <globaldefs.h>

#if defined(jpn)
#define AllocateNameBuffer02026b0c func_02026470
#endif
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_0218b5b0(void);

struct Obj02026b0c {
    #if defined(jpn)
    char pad[0x6ce];
#else
    char pad[0x77a];
#endif
    unsigned char count;
    unsigned char pad2;
    void* buffer;
};

#if defined(jpn)
extern "C" ARM void func_02026470(struct Obj02026b0c* p, int n);
#endif

// USA: func_02026b0c
ARM void AllocateNameBuffer02026b0c(struct Obj02026b0c* p, int n) {
    int base = func_ov017_0218b5b0();
    SafeAllocator* alloc = (SafeAllocator*)(base + 0x128);
    p->count = n;
    p->buffer = alloc->Allocate((n & 0xff) * 0x1a);
}
