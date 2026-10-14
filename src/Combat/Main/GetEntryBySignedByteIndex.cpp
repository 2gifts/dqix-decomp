#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
signed char FindSignedByteIndex_0202bcbc(struct SearchStruct* obj, int value);

// USA: func_0202c178
ARM SearchEntry0202c178* GetEntryBySignedByteIndex_0202c178(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex_0202bcbc(obj, value);
    if (idx < 0) return NULL;
    return (SearchEntry0202c178*)((char*)obj + 0xbc0 + idx * 0x74);
}
