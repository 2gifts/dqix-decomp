#include <globaldefs.h>

void* GetOffsetEntry0x8_020bd454(int index);
extern "C" int func_020bded0(unsigned short a, int flags, int b, int c, int zero);
int PostEvent0x1EForIndex_020be13c(unsigned int index, int b, int c);
int GetListEntryWord8020bd8ac(unsigned int index);

struct Entry020bddec {
    int val;
    unsigned short field4;
};

// USA: func_020bddec  (semantic: ResolveAndDispatchListEntry020bddec)
extern "C" ARM int func_020bddec(int id, int flags, int b, int c, int* out) {
    struct Entry020bddec* entry = (struct Entry020bddec*)GetOffsetEntry0x8_020bd454(id);
    if (entry == NULL) return 2;
    int result = func_020bded0(entry->field4, flags, b, c, 0);
    if (result != 0) return result;
    if (flags & 1) {
        result = PostEvent0x1EForIndex_020be13c((unsigned int)entry->val, b, c);
        if (result == 0) return 6;
    } else {
        result = GetListEntryWord8020bd8ac((unsigned int)entry->val);
    }
    if (out != NULL) *out = result;
    return 0;
}
