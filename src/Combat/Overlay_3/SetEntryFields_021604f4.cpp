#include <globaldefs.h>
#if defined(jpn)
enum { kRegion388 = 0x270 };
enum { kRegion334 = 0x21c };
#else
enum { kRegion388 = 0x388 };
enum { kRegion334 = 0x334 };
#endif

struct Entry021604f4 {
    char pad0[0x14];
    int field14;
    int field18;
    char pad1c[0x22 - 0x1c];
    unsigned char field22;
};

extern "C" void func_0205ac40(void* a, struct Entry021604f4* entry);

// JPN: func_ov003_021606ac
// USA: func_ov003_021604f4
ARM void SetEntryFields_021604f4(char* obj, int valA, int valB, short index, unsigned char flag) {
    struct Entry021604f4* entry = (struct Entry021604f4*)(*(char**)(obj + kRegion388) + index * 0x28);
    entry->field14 = valA << 12;
    entry->field18 = valB << 12;
    entry->field22 = flag;
    func_0205ac40((void*)(obj + kRegion334), entry);
}
