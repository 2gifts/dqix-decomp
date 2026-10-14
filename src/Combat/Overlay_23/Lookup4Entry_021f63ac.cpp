#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int key);
extern "C" short func_ov023_021f6f10(void* obj);
extern "C" void* func_ov023_021fa598(void* obj);

struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey_02072a68(struct TableA68* table, int key);

// USA: func_ov023_021f63ac
ARM void* Lookup4Entry_021f63ac(void* a, int b, int c) {
    void* h = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880(h, b);
    if (node == NULL) return NULL;
    if (func_ov023_021f6f10(node) != 4) return NULL;
    struct TableA68* table = (struct TableA68*)func_ov023_021fa598(node);
    return FindEntryByKey_02072a68(table, (short)c);
}
