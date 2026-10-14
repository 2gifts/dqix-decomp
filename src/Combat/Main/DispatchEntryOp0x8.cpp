#include <globaldefs.h>

struct List0207f6ac;
void SetEntryFlagBits0207f7ac(struct List0207f6ac*, int, int);

// USA: func_0208108c
ARM void DispatchEntryOp0x8_0208108c(void* obj, int id) {
    SetEntryFlagBits0207f7ac((struct List0207f6ac*)((char*)obj + 4), id, 8);
}
