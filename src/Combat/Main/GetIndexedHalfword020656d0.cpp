#include <globaldefs.h>

#if defined(jpn)
enum { kInitialPad = 0x18 };
#else
enum { kInitialPad = 0x4c };
#endif

struct IndexedHalfword020656d0 {
    char pad0[kInitialPad];
    unsigned short* table;
    char pad1[0x78 - 0x50];
    int index;
};

// USA: func_020656d0
ARM unsigned short GetIndexedHalfword(struct IndexedHalfword020656d0* obj) {
    return obj->table[obj->index];
}
