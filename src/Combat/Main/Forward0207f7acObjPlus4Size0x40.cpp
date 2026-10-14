#include <globaldefs.h>

struct List0207f6ac;
void SetEntryFlagBits0207f7ac(struct List0207f6ac*, int, int);

// USA: func_020805f4
ARM void Forward0207f7acObjPlus4Size0x40_020805f4(void* obj, int value) {
    SetEntryFlagBits0207f7ac((struct List0207f6ac*)((char*)obj + 4), value, 0x40);
}
