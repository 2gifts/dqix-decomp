#include <globaldefs.h>

extern "C" void* func_0202ae18(void*);
extern "C" void func_ov017_021d6134(void*, int);
int CheckField0NonZero_0202b7d8(int* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

// USA: func_ov001_02160a00
ARM int SetFlagFromSearchState_02160a00(void* ctx) {
    void* obj = func_0202ae18(ctx);
    int result;
    if (!CheckField0NonZero_0202b7d8((int*)obj)) {
        goto setOne;
    }
    if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)obj) != 0) {
        goto setZero;
    }
setOne:
    result = 1;
    goto call;
setZero:
    result = 0;
call:
    func_ov017_021d6134(ctx, result);
    return 1;
}
