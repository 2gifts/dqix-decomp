#include <globaldefs.h>
#if defined(jpn)
#define FIRST_FLAG 0x1c3
#define SECOND_FLAG 0x1c4
#define TIMED_STATE 0x1804
#else
#define FIRST_FLAG 0x233
#define SECOND_FLAG 0x234
#define TIMED_STATE 0x19e0
#endif

extern "C" unsigned char* _Z26GetGlobalField0x1c020421a0v(void);
void SetField0x1e20(void* obj, void* value);
extern "C" void _Z24UpdateTimedState0202f380Pvi(void* obj, int amount);
void InitSelfPointer(unsigned char* base);
extern "C" int _Z35CheckGlobalObjState2AndInit0205cde8Ph(unsigned char* p);
extern "C" int func_0205c5b0(void* selfPtr, void* p1);

// USA: func_0205c904
// KEEP-NAME
extern "C" ARM void _Z24SetupAndDispatch0205c904Phi(unsigned char* obj, int flag) {
    if (obj[FIRST_FLAG] == 0) {
        return;
    }

    if (obj[SECOND_FLAG] == 0) {
        return;
    }

    unsigned char* ctx = _Z26GetGlobalField0x1c020421a0v();
    SetField0x1e20(ctx, obj + 0xb4);
    _Z24UpdateTimedState0202f380Pvi(ctx + TIMED_STATE, flag);
    InitSelfPointer(ctx);

    if (_Z35CheckGlobalObjState2AndInit0205cde8Ph(obj) == 0) {
        return;
    }

    func_0205c5b0(obj + 0x1c, (void*)flag);
}
// JPN: 0x0205dc6c
