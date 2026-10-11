#include <globaldefs.h>
#if defined(jpn)
enum { flagsOffset = 0x1faa };
#else
enum { flagsOffset = 0x1d72 };
#endif

extern "C" int func_ov000_0217f62c(void* obj);
extern "C" void func_ov000_02180594(void* obj, int param, int flag);

struct Entry0218099c {
    char pad0[0x24];
    unsigned char field24;
    char pad1[0x4c - 0x25];
    int field4c;
#if defined(jpn)
    char pad2[0x488 - 0x50];
#else
    char pad2[0x448 - 0x50];
#endif
};

// USA: func_ov000_0218099c
extern "C" ARM void func_ov000_0218099c(void* objRaw, int param) {
    char* obj = (char*)objRaw;
    for (int i = 0; i < 4; i++) {
        struct Entry0218099c* entry = (struct Entry0218099c*)(obj + 0x958) + *(signed char*)(obj + i + 0x6c);
        if (*(int*)(obj + 0x17c) == entry->field4c) {
            if (!(entry->field24 & 0x4)) {
                if (!func_ov000_0217f62c(obj)) {
                    return;
                }
                func_ov000_02180594(obj, param, 0);
                *(unsigned short*)(obj + flagsOffset) &= ~0x8;
                *(unsigned short*)(obj + flagsOffset) = (*(unsigned short*)(obj + flagsOffset) | 0x10) & ~0x20;
                return;
            }
            *(int*)(obj + 0x910) = 0;
            *(int*)(obj + 0x914) = 0;
            *(int*)(obj + 0x918) = 0;
            *(int*)(obj + 0x91c) = 0;
            *(unsigned short*)(obj + flagsOffset) &= ~0x38;
            return;
        }
    }
}
