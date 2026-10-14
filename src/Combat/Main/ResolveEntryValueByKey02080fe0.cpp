#include <globaldefs.h>

struct List0207f6ac;
struct TableA68;

struct Entry02080fe0 {
    void* result;
};

extern struct Entry02080fe0* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);
extern void* FindEntryByKey_02072a68(struct TableA68* table, int key);

// USA: func_02080fe0
ARM void ResolveEntryValueByKey02080fe0(void* obj, int id, int key) {
    struct Entry02080fe0* e = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 0x4), id);
    if (e == NULL) {
        return;
    }
    e->result = FindEntryByKey_02072a68(*(struct TableA68**)obj, key);
}
