#include <globaldefs.h>

struct Entry0208103c {
    char unk0[0xe];
    short field_e;
    char unk10[0x30 - 0x10];
};

struct List0207f6ac;

extern struct Entry0208103c* FindEntryByShortId0207f6ac(struct List0207f6ac*, int);

// USA: func_0208103c
ARM void SetEntryHalfword0xe_0208103c(void* obj, int id, int value) {
    struct Entry0208103c* e = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 4), id);
    if (e != NULL) {
        e->field_e = (short)value;
    }
}
