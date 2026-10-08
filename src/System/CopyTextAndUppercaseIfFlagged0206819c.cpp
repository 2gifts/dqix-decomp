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

Entry0204254c *FindEntryByKey0204254c(int key, int tableIdx);
void ToUpperBounded(signed char *text, int count);

// USA: func_0206819c
ARM void CopyTextAndUppercaseIfFlagged0206819c(const char *source, char *destination, int tableIndex) {
    if (source == NULL) return;
    sprintf(destination, source);
    if (*source == 0) return;
    Entry0204254c *entry = FindEntryByKey0204254c(reinterpret_cast<int>(source), tableIndex);
    if (entry == NULL || !reinterpret_cast<TextEntryFlagView *>(entry)->uppercase) return;
    ToUpperBounded(reinterpret_cast<signed char *>(destination), entry->field5);
}
