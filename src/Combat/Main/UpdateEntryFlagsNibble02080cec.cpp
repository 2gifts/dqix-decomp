#include <globaldefs.h>

struct List0207f0ac;
struct List0207f6ac;

struct SubList02080cec {
    short* keys;
    char pad[0x13 - 0x4];
    unsigned char count;
};

struct Entry02080cec { char pad[0x13]; unsigned char flags; };

extern "C" extern struct SubList02080cec* _Z26FindEntryByShortId0207f0acP12List0207f0aci(struct List0207f0ac* list, int id);
extern "C" extern struct Entry02080cec* _Z26FindEntryByShortId0207f6acP12List0207f6aci(struct List0207f6ac* list, int id);

// USA: func_02080cec
// KEEP-NAME
ARM void UpdateEntryFlagsNibble02080cec(void* obj, int id, int value) {
    struct SubList02080cec* sub;
    unsigned char i;
    sub = _Z26FindEntryByShortId0207f0acP12List0207f0aci((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (sub == NULL) return;
    for (i = 0; i < sub->count; i++) {
        struct Entry02080cec* e = _Z26FindEntryByShortId0207f6acP12List0207f6aci((struct List0207f6ac*)((char*)obj + 4), sub->keys[i]);
        if (e != NULL) {
            e->flags = (e->flags & ~0xf0) | ((value & 0xf) << 4);
        }
    }
}