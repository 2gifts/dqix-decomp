#include <globaldefs.h>

struct SearchStruct;
signed char FindSignedByteIndex_0202bcbc(struct SearchStruct* obj, int value);
extern "C" void func_0202c288(void* obj);

// USA: func_0202c1e8
ARM void SetSearchFlagBitAt0xc_0202c1e8(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex_0202bcbc(obj, value);
    if (idx < 0) return;
    *((unsigned char*)obj + 0x100c) |= (1 << idx);
    func_0202c288(obj);
}
