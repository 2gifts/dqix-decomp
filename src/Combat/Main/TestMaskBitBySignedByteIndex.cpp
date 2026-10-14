#include <globaldefs.h>

struct SearchStruct;
signed char FindSignedByteIndex_0202bcbc(struct SearchStruct* obj, int value);
struct SearchStruct;
int GetEntryField0x4OrFieldA0202bc8c(struct SearchStruct*);

// USA: func_0202bd34
ARM int TestMaskBitBySignedByteIndex_0202bd34(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex_0202bcbc(obj, value);
    if (idx < 0) return 0;
    return (GetEntryField0x4OrFieldA0202bc8c((struct SearchStruct*)obj) & (1 << idx)) != 0;
}
