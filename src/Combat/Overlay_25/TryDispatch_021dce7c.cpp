#if defined(jpn)
enum {regionalOffset0=0xb94};
#else
enum {regionalOffset0=0xc18};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_02167f10(void* obj);
extern "C" void func_ov025_021def64(void* obj, void* ptr, int n);
extern "C" void func_ov000_0216dbf0(void* ptr, int* out, int a, int b);
void StoreFields0x1e4And0x1e8IfNonZero(unsigned char* obj, int a, int b);

struct In021dce7c {
    unsigned short field0;
};

// JPN: func_ov025_021dd770
// USA: func_ov025_021dce7c
ARM int TryDispatch_021dce7c(unsigned char* obj, struct In021dce7c* ptr, int arg3) {
    if (ptr) {
        GameState::GetInstance();
        if (ptr->field0 == 781 || ptr->field0 == 582) {
            int local = arg3;
            func_ov000_02167f10(obj);
            func_ov025_021def64(obj, ptr, 0x18);
            func_ov000_0216dbf0(obj + regionalOffset0, &local, 1, 1);
            StoreFields0x1e4And0x1e8IfNonZero(obj + regionalOffset0, 409, 2000);
            return 1;
        }
    }
    return 0;
}
