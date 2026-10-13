#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
int TestBitBySignedByteIndex(struct SearchStruct* obj, int value);
unsigned short GetGlobalHalf0x0(void);

// USA: func_0202bd68  (semantic: CheckBitFlagsAcrossEntries_0202bd68)
extern "C" ARM int func_0202bd68(struct SearchStruct* self, int bitIndex) {
    signed char* arr = (signed char*)((char*)self + 0x38);
    int i = 0;
    arr += 0x1000;
    for (; i < 4; i++) {
        if (i > 0) {
            signed char v = *(signed char*)((char*)self + i + 0x1038);
            if (v == 0) continue;
        }
        if (!TestBitBySignedByteIndex(self, arr[i])) continue;

        void* entry;
        if (i == GetGlobalHalf0x0()) {
            entry = (char*)self + 0x7c0;
        } else {
            entry = GetEntryBySignedByteIndex(self, arr[i]);
        }
        if (entry == 0) continue;

        unsigned int field2 = *(unsigned short*)((char*)entry + 2);
        unsigned int extracted = (field2 << 0x1b) >> 0x1c;
        if (extracted & (1 << bitIndex)) {
            return 0;
        }
    }
    return 1;
}
