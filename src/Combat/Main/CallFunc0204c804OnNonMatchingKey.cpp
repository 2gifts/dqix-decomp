#include <globaldefs.h>
#if defined(jpn)
enum { kEntriesOffset = 0x24 };
#else
enum { kEntriesOffset = 0x30 };
#endif

void ResetElem2081Entry(void*);


struct Elem0207fdf0 { char pad[0xc4]; unsigned char key; char pad2[0x1b]; };

struct Cont0207fdf0 {
    char pad0[kEntriesOffset];
    Elem0207fdf0* elems;
    char pad34[0x39 - 0x34];
    unsigned char count39;
};

// USA: func_0207fdf0
ARM void CallFunc0204c804OnNonMatchingKey(Cont0207fdf0* obj, int key) {
    unsigned char count;
    unsigned char i;
    if (obj->elems == NULL) return;
    count = obj->count39;
    for (i = 0; i < count; i++) {
        if (key != obj->elems[i].key) {
            ResetElem2081Entry((void*)(&obj->elems[i]));
        }
    }
}
