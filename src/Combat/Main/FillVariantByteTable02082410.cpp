#include <globaldefs.h>

#include "Combat/ResourceScriptEntry.h"

struct Variant02030b0c;

// USA: func_02082410
ARM int FillVariantByteTable02082410(Variant02030b0c *elem) {
    int i;
    for (i = 0; i < 0x11; i++) {
        ((ResourceScriptEntry *) data_02108ee8.fieldC)->variants[i] = (unsigned char) ((Script::Parameter *) elem)->ToInt();
        elem = (Variant02030b0c *) ((char *) elem + sizeof(Script::Parameter));
    }
    int j;
    for (j = 0x11; j < 0x16; j++) {
        ((ResourceScriptEntry *) data_02108ee8.fieldC)->variants[j] = 0x64;
    }
    return 1;
}
