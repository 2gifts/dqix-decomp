#include <globaldefs.h>

extern "C" void func_ov000_02174b14(void* obj);

struct Entry02175258 {
    char pad0[0x18];
    signed char field18;
    char pad2[0x24 - 0x19];
    unsigned char field24;
    char pad3[0x4c - 0x25];
    int field4c;
#if defined(jpn)
    char pad4[0x488 - 0x50];
#else
    char pad4[0x448 - 0x50];
#endif
};

// USA: func_ov000_02175258  (semantic: SyncCombatantReadyFlags_02175258)
extern "C" ARM void func_ov000_02175258(char* obj) {
    for (int i = 0; i < 4; i++) {
        struct Entry02175258* table = (struct Entry02175258*)(obj + 0x958);
        signed char idx = *(signed char*)(obj + i + 0x6c);
        struct Entry02175258* entry = table + idx;
        entry->field24 = entry->field24 & ~4;
        func_ov000_02174b14(obj);
    }

    struct Entry02175258* table2 = (struct Entry02175258*)(obj + 0x958);
    for (int i = 0; i < 4; i++) {
        signed char idx = *(signed char*)(obj + i + 0x6c);
        struct Entry02175258* entry = table2 + idx;
        if (*(int*)(obj + 0x17c) != entry->field4c) continue;

        int hasBit4 = (entry->field24 & 4) != 0;
        signed char off = entry->field18;
        signed char v = *(signed char*)((char*)entry + off + 0x10);
        if (v >= 0x64) {
            if (hasBit4 == 0) return;
            unsigned char flags = *(volatile unsigned char*)&entry->field24;
            entry->field24 = flags & ~4;
            func_ov000_02174b14(obj);
            return;
        } else {
            if (hasBit4 != 0) return;
            unsigned char flags = *(volatile unsigned char*)&entry->field24;
            entry->field24 = flags | 4;
            func_ov000_02174b14(obj);
            return;
        }
    }
}
