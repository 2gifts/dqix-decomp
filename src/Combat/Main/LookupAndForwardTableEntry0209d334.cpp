#include <globaldefs.h>
void* GetGlobal02109418_02094d6c(void);

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
struct FindEntryById02096134Table;
struct FindEntryById02096134Elem;
struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table*, int);

struct Entry0209d334 { char pad[0xa]; unsigned short table[1]; };

// USA: func_0209d334
ARM int LookupAndForwardTableEntry0209d334(char* a0) {
    void* table = GetGlobal02109418_02094d6c();
    if (table == NULL) return 0;
    struct Entry0209d334* entry = (struct Entry0209d334*)FindEntryById02096134(
        (struct FindEntryById02096134Table*)table, func_ov017_021d60f4(a0));
    if (entry == NULL) return 0;
    int idx = func_ov017_021d60f4(a0 + 8);
    func_ov017_021d6134(a0 + 0x10, entry->table[idx]);
    return 1;
}
