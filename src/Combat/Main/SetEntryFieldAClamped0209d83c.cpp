#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);

int* GetGlobal02109418_02094d6c(void);
void* GetGlobalManager0209dccc(void);

struct FindEntryById02096134Table;
void* FindEntryById02096134(struct FindEntryById02096134Table* t, int id);

// USA: func_0209d83c
ARM int SetEntryFieldAClamped0209d83c(void* obj) {
    struct FindEntryById02096134Table* table;
    void* entry;
    int id;
    int val;

    table = (struct FindEntryById02096134Table*)GetGlobal02109418_02094d6c();
    if (table == NULL) return 0;

    if (GetGlobalManager0209dccc() == NULL) return 0;

    id = func_ov017_021d60f4(obj);
    entry = FindEntryById02096134(table, id);
    if (entry == NULL) return 0;

    val = func_ov017_021d60f4((char*)obj + 8);
    if (val > 0xffff) val = 0xffff;
    *(unsigned short*)((char*)entry + 0xa) = (unsigned short)val;
    return 1;
}
