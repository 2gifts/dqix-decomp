#include <globaldefs.h>

void* GetGlobal02109418_02094d6c(void);
void* GetGlobalManager0209dccc(void);

extern "C" int func_ov017_021d60f4(void*);
struct FindEntryById02096134Table;
struct FindEntryById02096134Elem;
struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table*, int);

struct Entry0209d1a4 { char pad[0xa]; unsigned short field_a; };
struct Manager0209d1a4 { char pad[0x98]; int field98; };

// USA: func_0209d1a4
ARM int AdvanceEntryFieldByManagerDelta0209d1a4(void* arg) {
    void* table = GetGlobal02109418_02094d6c();
    if (table == NULL) return 0;
    struct Manager0209d1a4* mgr = (struct Manager0209d1a4*)GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    struct Entry0209d1a4* entry = (struct Entry0209d1a4*)FindEntryById02096134((struct FindEntryById02096134Table*)table, func_ov017_021d60f4(arg));
    if (entry == NULL) return 0;
    if (entry->field_a + mgr->field98 >= 0xffff) return 0;
    entry->field_a = entry->field_a + mgr->field98;
    return 1;
}
