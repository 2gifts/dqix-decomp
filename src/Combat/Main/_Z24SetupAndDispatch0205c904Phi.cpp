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

unsigned char* GetGlobalField0x1c020421a0(void);
void SetField0x1e20_02042b10(void* obj, void* value);
void UpdateTimedState0202f380(void* obj, int amount);
void InitSelfPointer_02042b1c(unsigned char* base);
int CheckGlobalObjState2AndInit0205cde8(unsigned char* p);
extern "C" int func_0205c5b0(void* selfPtr, void* p1);

// USA: func_0205c904
// KEEP-NAME
ARM void SetupAndDispatch0205c904(unsigned char* obj, int flag) {
    if (obj[FIRST_FLAG] == 0) {
        return;
    }

    if (obj[SECOND_FLAG] == 0) {
        return;
    }

    unsigned char* ctx = GetGlobalField0x1c020421a0();
    SetField0x1e20_02042b10(ctx, obj + 0xb4);
    UpdateTimedState0202f380(ctx + TIMED_STATE, flag);
    InitSelfPointer_02042b1c(ctx);

    if (CheckGlobalObjState2AndInit0205cde8(obj) == 0) {
        return;
    }

    func_0205c5b0(obj + 0x1c, (void*)flag);
}
