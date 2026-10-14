#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
int TestBitBySignedByteIndex_0202c1c0(struct SearchStruct* obj, int value);
unsigned short GetGlobalHalf0x0_0202df58(void);

// USA: func_0202be08
ARM int IsEntryFlagBit11Set_0202be08(struct SearchStruct* obj, int value) {
    void* entry;
    if (!TestBitBySignedByteIndex_0202c1c0(obj, value)) {
        return 0;
    }
    if (value == *(signed char*)((char*)obj + GetGlobalHalf0x0_0202df58() + 0x1000 + 0x38)) {
        entry = (char*)obj + 0x7c0;
    } else {
        entry = GetEntryBySignedByteIndex_0202c178(obj, value);
    }
    if (entry == NULL) {
        return 0;
    }
    return (((unsigned int)*(unsigned short*)((char*)entry + 0x2) << 0x14) >> 31) != 0;
}
