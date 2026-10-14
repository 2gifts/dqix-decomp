#include <globaldefs.h>

struct List0207f6ac;
void SetEntryFlagBits0207f7ac(struct List0207f6ac*, int, int);

// USA: func_020810a0
ARM void DispatchEntryOp0x10_020810a0(void* obj, int id) {
    SetEntryFlagBits0207f7ac((struct List0207f6ac*)((char*)obj + 4), id, 0x10);
}
