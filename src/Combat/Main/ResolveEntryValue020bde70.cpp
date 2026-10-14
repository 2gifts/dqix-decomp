#include <globaldefs.h>
int PostEvent0x1EForIndex020be1a8(unsigned int, int, int);
int* GetOffsetEntry0xc_020bd4b8(int);

int GetListEntryWord8020bd8ac(unsigned int);

// USA: func_020bde70
ARM int ResolveEntryValue020bde70(int id, int flags, int b, int c, int* out) {
    int* entry = GetOffsetEntry0xc_020bd4b8((int)(id));
    if (entry == NULL) return 3;
    int val = *entry;
    int result;
    if (flags & 8) {
        result = PostEvent0x1EForIndex020be1a8((unsigned int)(val), (int)(b), (int)(c));
        if (result == 0) return 7;
    } else {
        result = GetListEntryWord8020bd8ac(val);
    }
    if (out != NULL) *out = result;
    return 0;
}
