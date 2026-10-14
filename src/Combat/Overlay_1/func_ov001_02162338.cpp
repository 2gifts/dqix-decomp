#include <globaldefs.h>
#include "System/OverlayId.h"

extern "C" void func_ov017_021d6134(void* obj, int enable);
extern "C" void func_020a1940(unsigned int id);
extern "C" int func_020a1bb4(unsigned int id);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" int func_ov029_021d8e94(void* invoker, void* callback, int arg);
extern "C" int func_ov029_021d8f84(void* invoker, void* callback, int arg);
extern "C" int func_ov029_021d9074(void* invoker, void* callback, int arg);
int InvokeCallbackReturn1bf27f_0215a6fc(void (*callback)());
int InvokeCallbackReturn1befcb_0215a718(void (*callback)());
int InvokeCallbackReturn1beb10_0215a734(void (*callback)());
void IncrementCounterBy1_021622f0();
void IncrementCounterBy2_02162308();
void IncrementCounterBy3_02162320();
extern char data_ov001_02165880;

static inline int Passes(int result, int expected) {
    return result == expected;
}

// USA: func_ov001_02162338
extern "C" ARM int func_ov001_02162338(void* obj, int count) {
    func_ov017_021d6134(obj, 1);
    unsigned int id = OVERLAY_ID(29);
    func_020a1940(id);
    *(unsigned int*)(&data_ov001_02165880 + 0x28) = 0;
    if (count > 1 && func_ov017_021d60f4((char*)obj + 8) == 1) {
        if (Passes(func_ov029_021d8e94(InvokeCallbackReturn1bf27f_0215a6fc, IncrementCounterBy1_021622f0, 0), 0x1bf27f)
            && Passes(func_ov029_021d8f84(InvokeCallbackReturn1befcb_0215a718, IncrementCounterBy2_02162308, 0), 0x1befcb)
            && Passes(func_ov029_021d9074(InvokeCallbackReturn1beb10_0215a734, IncrementCounterBy3_02162320, 0), 0x1beb10)
            && *(unsigned int*)(&data_ov001_02165880 + 0x28) >= 6) {
            func_ov017_021d6134(obj, 0);
        }
    } else {
        func_ov017_021d6134(obj, 0);
    }
    *(unsigned int*)(&data_ov001_02165880 + 0x28) = 0;
    func_020a1bb4(id);
    return 1;
}
