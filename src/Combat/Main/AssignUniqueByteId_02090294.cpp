#include <globaldefs.h>

struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
struct Element0x318_02028bac;
struct Element0x318_02028bac* GetElementStride0x318(struct Element0x318_02028bac* base, int index);

struct Obj02090294 {
#if defined(jpn)
    char pad0[0x296];
#else
    char pad0[0x276];
#endif
    signed char field276; // 0x276
};

#if defined(jpn)
#define func_02090294 func_02090bb4
#endif

// USA: func_02090294  (semantic: AssignUniqueByteId_02090294)
extern "C" ARM int func_02090294(struct Obj02090294* obj) {
    struct Element0x318_02028bac* table = (struct Element0x318_02028bac*)GetEntryTableBase();
    int i = 0;
    int j;
retry:
    if (obj->field276 > 4) {
        obj->field276 = 0;
    }
    for (j = i; j < 4; j++) {
        struct Element0x318_02028bac* entry = GetElementStride0x318(table, j);
        if (entry != 0) {
            if (*((signed char*)entry + 0xd) == obj->field276) {
                obj->field276++;
                goto retry;
            }
        }
    }
    int k;
    for (k = 0; k < 4; k++) {
        GetElementStride0x318(table, k);
    }
    signed char old = obj->field276;
    obj->field276 = old + 1;
    return old;
}
