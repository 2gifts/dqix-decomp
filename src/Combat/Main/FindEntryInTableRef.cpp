#include <globaldefs.h>

struct TableA68;

void* FindEntryByKey_02072a68(struct TableA68* table, int key);

struct TableRef02081214 {
    struct TableA68* table;
};

// USA: func_02081214
ARM void* FindEntryInTableRef(struct TableRef02081214* ref, int key) {
    return FindEntryByKey_02072a68(ref->table, key);
}
