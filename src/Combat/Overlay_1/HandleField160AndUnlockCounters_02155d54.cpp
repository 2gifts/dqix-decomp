#include <globaldefs.h>
#include "GameState/GameState.h"

class PMFClass021d8d40;
int DispatchHandlerTable_021d8d40(PMFClass021d8d40* obj1, unsigned short arg2);
int ReadByteAt17122_02156858(void*);
extern "C" void _Z22UnlockAndSetBrightnessP13GameResourcesii(unsigned char* obj, int value, int frames);
int InitAndCheckField3c_02153994(void);

// USA: func_ov001_02155d54  (semantic: HandleField160AndUnlockCounters_02155d54)
extern "C" ARM int func_ov001_02155d54(void* obj) {
    GameState::GetInstance();
    void* b = func_ov017_0218b5b0();
    int f160 = *(int*)((char*)obj + 0x160);
    if (f160 != 0) {
        int r = DispatchHandlerTable_021d8d40((PMFClass021d8d40*)f160, 2);
        *((unsigned char*)obj + 0x164) = (r != 0);
    }
    if (ReadByteAt17122_02156858(obj) != 0) {
        _Z22UnlockAndSetBrightnessP13GameResourcesii((unsigned char*)b, -16, 0x1e);
        *(int*)((char*)obj + 0x15c) = 1;
        return 0xe;
    }
    return (InitAndCheckField3c_02153994() != 1) ? *(unsigned short*)((char*)obj + 0xa) : 0xf;
}
