#include <globaldefs.h>

struct List0207f6ac;
extern void SetEntryFlagBits0207f7ac(struct List0207f6ac* list, int id, int mask);

#if defined(jpn)
#define AddSublistEntryFlag2_020806b0 func_020811d8
extern "C" ARM void func_020811d8(void* obj, int id);
#endif

// USA: func_020806b0
ARM void AddSublistEntryFlag2_020806b0(void* obj, int id) {
    SetEntryFlagBits0207f7ac((struct List0207f6ac*)((char*)obj + 4), id, 2);
}
