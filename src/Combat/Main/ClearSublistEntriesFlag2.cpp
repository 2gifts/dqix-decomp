#include <globaldefs.h>

struct List0207f0ac;
struct List0207f6ac;

struct SubList0208065c {
    short* keys;
    char pad[0x13 - 0x4];
    unsigned char count;
};

extern struct SubList0208065c* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);
extern void ClearEntryFlagBits0207f7cc(struct List0207f6ac* list, int id, int mask);

#if defined(jpn)
#define ClearSublistEntriesFlag2 func_02081184
extern "C" ARM void func_02081184(void* obj, int id);
#endif

// USA: func_0208065c
ARM void ClearSublistEntriesFlag2(void* obj, int id) {
    struct SubList0208065c* sub;
    unsigned char i;
    sub = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (sub == NULL) return;
    for (i = 0; i < sub->count; i++) {
        ClearEntryFlagBits0207f7cc((struct List0207f6ac*)((char*)obj + 4), sub->keys[i], 2);
    }
}
