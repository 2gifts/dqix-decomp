#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

extern signed char data_020e8ed8[];

// USA: func_0209caf0
ARM int GetElementOverride0209caf0(int id) {
    void* obj;
    signed char v;
    if ((unsigned int)id >= 0x2f) {
        return -1;
    }
    obj = LightingManager::GetInstance();
    if (*(int*)((char*)obj + 0x98) == 0) {
        v = data_020e8ed8[id];
        if (v == 3) return 4;
        if (v == 5) return 6;
    }
    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())) {
        v = data_020e8ed8[id];
        if (v == 0xe) return 0x10;
    }
    return data_020e8ed8[id];
}
