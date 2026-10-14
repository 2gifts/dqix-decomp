#include <globaldefs.h>

void PushInterruptDisableState_020d8654(void);
struct Struct020db9a8;
void SyncSwapBitState020db360(struct Struct020db9a8* obj, int b);
int GetSwapBitIfFlag54Clear(struct Struct020db9a8* obj);
extern "C" void func_020d8694(void);

// USA: func_020db264
ARM void InitCombatantVisualState_020db264(void* obj, int arg1, int arg2, int arg3, int arg4) {
    char* p = (char*)obj;
    if (*(unsigned char*)(p + 0x50) != 0 && arg1 != 0) {
        return;
    }
    PushInterruptDisableState_020d8654();
    if (arg3 == 0) {
        *(short*)(p + 0x66) = 0;
    }
    *(unsigned char*)(p + 0x50) = (unsigned char)arg1;
    *(unsigned char*)(p + 0x52) = (unsigned char)arg2;
    int b = (arg1 == 0);
    unsigned char stackVal = (unsigned char)arg4;
    *(unsigned char*)(p + 0x53) = (unsigned char)arg3;
    *(unsigned char*)(p + 0x54) = stackVal;
    SyncSwapBitState020db360((struct Struct020db9a8*)obj, b);
    *(unsigned char*)(p + 0x3c) = GetSwapBitIfFlag54Clear((struct Struct020db9a8*)obj);
    func_020d8694();
}
