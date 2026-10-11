#include <globaldefs.h>
#if defined(jpn)
enum { flagsOffset = 0x1faa };
#else
enum { flagsOffset = 0x1d72 };
#endif

struct TableEntry0217f8c0 {
    char pad0[0x4c];
    int field0x4c;
    char pad1[0x448 - 0x50];
};

struct Struct0217f8c0 {
    char pad[0x6c];
    signed char idx[4];
    char pad2[0x17c - 0x70];
    int field0x17c;
};

struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);

struct Data02184288 { int field0; int field4; int field8; };
extern int data_ov000_02183ff0;
extern struct Data02184288 data_ov000_02184288;

extern "C" void func_ov000_02177184(void* obj, void* entry, int a, int b);
extern "C" void func_ov000_0217f518(void* obj);
extern "C" void func_ov000_0217636c(void* obj, int mode);

struct Obj02174d08 {
    char pad[0x118];
    int field0x118;
};

// USA: func_ov000_02174d08  (semantic: HandleTableFlags_02174d08)
extern "C" ARM void func_ov000_02174d08(void* obj) {
    unsigned short flags = *(unsigned short*)((char*)obj + flagsOffset);
    if (flags & 2) {
        struct TableEntry0217f8c0* e = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
        func_ov000_02177184(obj, e, data_ov000_02183ff0, data_ov000_02184288.field4);
        return;
    }
    if (!(flags & 4)) {
        return;
    }
    struct TableEntry0217f8c0* e = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
    if (e == 0) {
        return;
    }
    int mode = (((struct Obj02174d08*)obj)->field0x118 == 2) ? 1 : 0;
    func_ov000_0217f518(e);
    if (*(int*)((char*)e + 0x38) != 0) {
        func_ov000_0217636c(e, mode);
    }
    unsigned short newFlags = *(unsigned short*)((char*)obj + flagsOffset);
    newFlags &= ~4;
    *(unsigned short*)((char*)obj + flagsOffset) = newFlags;
}
