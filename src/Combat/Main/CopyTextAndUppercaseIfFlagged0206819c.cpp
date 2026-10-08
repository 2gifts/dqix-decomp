#include <globaldefs.h>

#include "std_library_functions.h"

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

struct TextEntryFlagView {
    unsigned char unknown0[5];
    signed char unknown5 : 7;
    signed char uppercase : 1;
};

extern "C" Entry0204254c *_Z22FindEntryByKey0204254cii(int key, int tableIdx);
void ToUpperBounded(signed char *text, int count);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0206819c
ARM void CopyTextAndUppercaseIfFlagged0206819c(const char *source, char *destination, int tableIndex) {
    if (source == NULL) return;
    sprintf(destination, source);
    if (*source == 0) return;
    Entry0204254c *entry = _Z22FindEntryByKey0204254cii(reinterpret_cast<int>(source), tableIndex);
    if (entry == NULL || !reinterpret_cast<TextEntryFlagView *>(entry)->uppercase) return;
    ToUpperBounded(reinterpret_cast<signed char *>(destination), entry->field5);
}
