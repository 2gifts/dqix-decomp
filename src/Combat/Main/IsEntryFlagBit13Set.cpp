#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
int TestBitBySignedByteIndex(struct SearchStruct* obj, int value);
unsigned short GetGlobalHalf0x0(void);

// USA: func_0202be70
ARM int IsEntryFlagBit13Set(struct SearchStruct* obj, int value) {
    void* entry;
    if (!TestBitBySignedByteIndex(obj, value)) {
        return 0;
    }
    if (value == *(signed char*)((char*)obj + GetGlobalHalf0x0() + 0x1000 + 0x38)) {
        entry = (char*)obj + 0x7c0;
    } else {
        entry = GetEntryBySignedByteIndex(obj, value);
    }
    if (entry == NULL) {
        return 0;
    }
    return (((unsigned int)*(unsigned short*)((char*)entry + 0x2) << 0x12) >> 31) != 0;
}
