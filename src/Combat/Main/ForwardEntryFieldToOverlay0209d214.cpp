#include <globaldefs.h>
void* GetGlobal02109418_02094d6c(void);

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
struct FindEntryById02096134Table;
struct FindEntryById02096134Elem;
struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table*, int);

struct Entry0209d214 { char pad[0xa]; unsigned short field_a; };

// USA: func_0209d214
ARM int ForwardEntryFieldToOverlay0209d214(char* arg) {
    void* table = GetGlobal02109418_02094d6c();
    if (table == NULL) return 0;
    struct Entry0209d214* entry = (struct Entry0209d214*)FindEntryById02096134(
        (struct FindEntryById02096134Table*)table, func_ov017_021d60f4(arg));
    if (entry == NULL) return 0;
    func_ov017_021d6134(arg + 8, entry->field_a);
    return 1;
}
