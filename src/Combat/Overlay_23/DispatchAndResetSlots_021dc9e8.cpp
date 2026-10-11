#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
int DispatchByMode77c_021ddbb8(void* obj, int a, int b);
void ResetIfNonNeg_021db2e4(volatile int* p);
extern "C" int func_ov023_021dc354(void* obj);
extern "C" void func_ov023_021dc134(void* a, int key, int flag);
extern "C" void func_ov023_021dbfd0(void* a, void* b);

#if defined(jpn)
#define FIELD_OFFSET(value) ((value) - 0x84)
#else
#define FIELD_OFFSET(value) (value)
#endif

// JPN: 021dd2fc
// USA: func_ov023_021dc9e8  (semantic: DispatchAndResetSlots_021dc9e8)
extern "C" ARM void func_ov023_021dc9e8(void* obj, void* arg1, int arg2, int arg3, unsigned short arg5) {
    GetWord0x0((int*)GameState::GetInstance());
    DispatchByMode77c_021ddbb8(obj, -16, 1);

    ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + FIELD_OFFSET(0x734)));
    for (int i = 0; i < 7; i++) {
        ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + FIELD_OFFSET(0x738) + i * 4));
    }

    func_ov023_021dc354(obj);
    signed char flag = *(signed char*)((char*)obj + FIELD_OFFSET(0x77b));
    func_ov023_021dc134(obj, arg2, flag);

    unsigned short v = *(unsigned short*)((char*)obj + FIELD_OFFSET(0x774));
    *(unsigned short*)((char*)obj + FIELD_OFFSET(0x774)) = v | arg5;

    func_ov023_021dbfd0(obj, arg1);
    *(int*)((char*)obj + 0x48) = arg3;
}
