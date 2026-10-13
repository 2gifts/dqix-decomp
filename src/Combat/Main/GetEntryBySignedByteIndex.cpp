#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
signed char FindSignedByteIndex(struct SearchStruct* obj, int value);

// USA: func_0202c178
ARM SearchEntry0202c178* GetEntryBySignedByteIndex(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex(obj, value);
    if (idx < 0) return NULL;
    return (SearchEntry0202c178*)((char*)obj + 0xbc0 + idx * 0x74);
}
