#include <globaldefs.h>

struct List0207f6ac;
extern void ClearEntryFlagBits0207f7cc(struct List0207f6ac* list, int id, int mask);

// USA: func_020806c4
ARM void ClearSublistEntryFlag2_020806c4(void* obj, int id) {
    ClearEntryFlagBits0207f7cc((struct List0207f6ac*)((char*)obj + 4), id, 2);
}
