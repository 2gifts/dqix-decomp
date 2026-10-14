#include <globaldefs.h>

struct List0207f6ac;
struct TableA68;

struct Entry02081010 {
    char pad[0xe];
    short key;
};

extern struct Entry02081010* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);
extern void* FindEntryByKey_02072a68(struct TableA68* table, int key);

// USA: func_02081010
ARM void* LookupValueByEntryKey02081010(void* obj, int id) {
    struct Entry02081010* e = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 0x4), id);
    if (e == NULL) {
        return NULL;
    }
    return FindEntryByKey_02072a68(*(struct TableA68**)obj, e->key);
}
