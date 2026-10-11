#include <globaldefs.h>

extern "C" void func_ov000_0217f518(char* obj);

struct TableEntry0217f8c0 {
    char pad0[0x4c];
    int field0x4c;
#if defined(jpn)
    char pad1[0x488 - 0x50];
#else
    char pad1[0x448 - 0x50];
#endif
};
struct Struct0217f8c0 {
    char pad[0x6c];
    signed char idx[4];
    char pad2[0x17c - 0x70];
    int field0x17c;
};
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);

struct Entry02180404 {
    char pad0[0x4c];
    int field4c;
#if defined(jpn)
    char pad1[0xc7 - 0x50];
#else
    char pad1[0x87 - 0x50];
#endif
    unsigned char field87;
    char pad2[0x448 - 0x88];
};

// USA: func_ov000_02180404  (semantic: ProcessReadyEntries02180404)
extern "C" ARM void func_ov000_02180404(char* obj) {
    int i;
    for (i = 0; i < 4; i++) {
        struct Entry02180404* entry = (struct Entry02180404*)(obj + 0x958) + *(signed char*)(obj + i + 0x6c);
        int inRange = (entry->field4c >= 0 && entry->field4c <= 3) ? 1 : 0;
        if (inRange && entry->field87 != 0) {
            func_ov000_0217f518((char*)entry);
        }
    }
    struct TableEntry0217f8c0* e = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
    if (e) {
        *((unsigned char*)e + 0x24) |= 4;
    }
}
