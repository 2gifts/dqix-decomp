#include <globaldefs.h>
#include "std_library_functions.h"

inline void* operator new(unsigned long, void* storage) { return storage; }

struct Entry0218afbc { char str[5]; };
extern Entry0218afbc data_ov012_0218afbc[];
int FindEntryIndexByKey020424e4(int key, int tableIdx);

// Actual callers provide their initialized checker char[0x3c]. Representation
// writes do not create or access an unrelated Obj021845f8 object.
// USA: func_ov012_021845f8
extern "C" ARM void func_ov012_021845f8(void* checker) {
    unsigned char* bytes = static_cast<unsigned char*>(checker);
    memset(bytes + 0x18, 0, 0xc);
    int* word = new (bytes + 0x24) int;
    *word = 0;
    short* half = new (bytes + 0x28) short;
    *half = 0;
    unsigned char* out = bytes + 0x2a;
    int i;
    for (i = 0; i < 15; ++i)
        *out++ = (unsigned char)FindEntryIndexByKey020424e4((int)&data_ov012_0218afbc[i], 1);
}
