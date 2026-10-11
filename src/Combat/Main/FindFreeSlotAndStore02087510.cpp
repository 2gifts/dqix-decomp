#include <globaldefs.h>
#include "std_library_functions.h"

struct Base02087510 {
    char pad[0xf2c];
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02087510
// USA: _Z28FindFreeSlotAndStore02087510P12Base02087510cPv
ARM int FindFreeSlotAndStore02087510(Base02087510* self, char c, void* out) {
    int i;
    for (i = 0; i < 3; i++) {
        if (*(signed char*)((char*)self + 0xf3c + i * 0x14) < 0) {
            memcpy((char*)self + 0xf2c + i * 0x14, out, 0x10);
            *(char*)((char*)self + 0xf3c + i * 0x14) = c;
            return 1;
        }
    }
    return 0;
}
