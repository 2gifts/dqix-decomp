#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
extern "C" int func_0202c508(struct SearchStruct* obj);
unsigned short GetField0xa_0202d698(void);

// USA: func_0202bc8c
ARM unsigned short GetEntryField0x4OrFieldA0202bc8c(struct SearchStruct* obj) {
    if (func_0202c508(obj)) {
        return GetField0xa_0202d698();
    }
    return GetEntryBySignedByteIndex_0202c178(obj, 0)->mask;
}
