#include <globaldefs.h>
#include "System/OverlayId.h"

struct Obj020db964;
struct Struct020db9a8;
struct Actor020db844;
struct DisplayDispatchObj020db5ec;
struct Obj020db3f4;

void RefreshSlots0x5cFromCallbacks(Obj020db964* obj);
int IsIndexMappedToSelf020a18f4(unsigned int idx);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_020db894(void* obj);
int GetSwapBitIfFlag54Clear(Struct020db9a8* obj);
extern "C" void func_020db3f4(Obj020db3f4* obj);
void PushInterruptDisableState_020d8654(void);
void RunFlaggedCallback020db844(Actor020db844* a, int b, int c, int d);
void InitCombatantVisualState_020db264(void* obj, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_020d8694(void);
void ProcessDisplayDispatch020db5ec(DisplayDispatchObj020db5ec* obj);
void InitFlag0x28FromOverlay_020db814(void*);

// USA: func_020dbae0
extern "C" ARM void func_020dbae0(void* obj) {
    char* p = (char*)obj;
    RefreshSlots0x5cFromCallbacks((Obj020db964*)obj);
    if (!IsIndexMappedToSelf020a18f4(OVERLAY_ID(17))) {
        return;
    }
    void* resources = func_ov017_0218b5b0();
    if (*(unsigned char*)(p + 0x50) == 0 || resources == NULL) {
        func_020db894(obj);
        return;
    }
    if (*(unsigned char*)(p + 0x52) == 0) {
        short delay = *(short*)(p + 0x68);
        if (delay < 0) {
            return;
        }
        if (delay > 0) {
            *(short*)(p + 0x68) = delay - 1;
            func_020db894(obj);
            return;
        }
    }
    int swapBit = GetSwapBitIfFlag54Clear((Struct020db9a8*)obj);
    if (*(unsigned char*)(p + 0x51) == 0) {
        *(short*)(p + 0x6a) = *(short*)(p + 0x66);
        func_020db3f4((Obj020db3f4*)obj);
    } else {
        if (swapBit != *(unsigned char*)(p + 0x3c)) {
            PushInterruptDisableState_020d8654();
            RunFlaggedCallback020db844((Actor020db844*)obj, *(unsigned char*)(p + 0x3c), *(short*)(p + 0x66), 0);
            short target = *(short*)(p + 0x6a);
            unsigned char a = *(unsigned char*)(p + 0x50);
            unsigned char b = *(unsigned char*)(p + 0x52);
            unsigned char c = *(unsigned char*)(p + 0x53);
            unsigned char d = *(unsigned char*)(p + 0x54);
            func_020db894(obj);
            *(short*)(p + 0x68) = 0;
            *(unsigned char*)(p + 0x3c) = swapBit;
            *(short*)(p + 0x6a) = *(short*)(p + 0x66) = target;
            InitCombatantVisualState_020db264(obj, a, b, c, d);
            func_020d8694();
            return;
        }
        ProcessDisplayDispatch020db5ec((DisplayDispatchObj020db5ec*)obj);
    }
    InitFlag0x28FromOverlay_020db814(obj);
}
