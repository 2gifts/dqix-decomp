#include <globaldefs.h>

extern "C" unsigned char* _Z26GetGlobalField0x1c020421a0v(void);
void SetField0x1e20(void* obj, void* value);
extern "C" void _Z24UpdateTimedState0202f380Pvi(void* obj, int amount);
void InitSelfPointer(unsigned char* base);
extern "C" int _Z35CheckGlobalObjState2AndInit0205cde8Ph(unsigned char* p);
extern "C" int func_0205c5b0(void* selfPtr, void* p1);

// USA: func_0205c904
// KEEP-NAME
extern "C" ARM void _Z24SetupAndDispatch0205c904Phi(unsigned char* obj, int flag) {
    if (obj[0x233] == 0) {
        return;
    }

    if (obj[0x234] == 0) {
        return;
    }

    unsigned char* ctx = _Z26GetGlobalField0x1c020421a0v();
    SetField0x1e20(ctx, obj + 0xb4);
    _Z24UpdateTimedState0202f380Pvi(ctx + 0x19e0, flag);
    InitSelfPointer(ctx);

    if (_Z35CheckGlobalObjState2AndInit0205cde8Ph(obj) == 0) {
        return;
    }

    func_0205c5b0(obj + 0x1c, (void*)flag);
}