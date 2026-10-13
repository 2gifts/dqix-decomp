#include <globaldefs.h>
#include "Combat/SearchEntry.h"

extern "C" void* func_0202ae18(void* obj);
extern "C" void* func_ov017_0218b5b0(void);
int CheckField0NonZero(int* obj);
struct SearchStruct;

// USA: func_02034340
ARM int HasHighBit14SetForField4Entry02034340(void* obj) {
    void* thing = func_0202ae18(obj);
    func_ov017_0218b5b0();
    int result = 0;
    if (CheckField0NonZero((int*)thing)) {
        short field4 = *(short*)((char*)obj + 4);
        if (GetEntryBySignedByteIndex((struct SearchStruct*)thing, field4)) {
            field4 = *(short*)((char*)obj + 4);
            void* p = GetEntryBySignedByteIndex((struct SearchStruct*)thing, field4);
            unsigned int v = *(unsigned short*)((char*)p + 2);
            if ((v << 17) >> 31) result = 1;
        }
    }
    return result;
}
