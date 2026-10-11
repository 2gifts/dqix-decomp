// JPN: func_ov017_021a9c34
#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { TextBufferPointer = 0x28, MessageStatus = 0x868, PendingMessage = 0x870, MessageFlag = 0x7e2 };
#else
enum { TextBufferPointer = 0x5c, MessageStatus = 0x998, PendingMessage = 0x9a0, MessageFlag = 0x9b2 };
#endif

struct PointerField32c_ffc0;
struct ResetObj020d7a5c;
struct Obj020d7aa0;

int GetGlobalField0x1c020421a0(void);
extern "C" void* func_02012fe4(void);
int GetFieldIfFlag4(char* obj);
struct ResetObj020d7a5c* GetGlobalResetObj020d7a50(void);
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);
void* GetPointerAt0x32c(struct PointerField32c_ffc0* obj);
void ClearByteFlagAt0x154(unsigned char* obj);
int CallFunc020e0434With02153694(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
#if defined(jpn)
extern "C" void func_02045d88(void*, const char*, int);
extern char data_ov017_021d7c28;
extern char data_ov017_021d7c49;
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void ClearFlagBits(unsigned char* obj, int mask);
extern "C" int func_020457e0(void* obj);
void* GetField0x3f8Address(GameState* battleStruct);
extern "C" void VectorizedMemset(void*, int, int);
void ReinitController02043204(char* obj);
void SetByteFlagAt0x154(unsigned char* obj);

// USA: func_ov017_021a9454  (semantic: HandleFieldStatusTransition_021a9454)
extern "C" ARM void func_ov017_021a9454(char* obj) {
    GameState* battleStruct = GameState::GetInstance();
    char* g = (char*)GetGlobalField0x1c020421a0();
    func_02012fe4();
    int field = GetFieldIfFlag4((char*)battleStruct);
    int status = *(int*)(obj + 0x8);

    if (status == 0) {
        struct ResetObj020d7a5c* reset = GetGlobalResetObj020d7a50();
        TeardownAndResetState020d7aa0((struct Obj020d7aa0*)reset);
        void* p = GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct);
        ClearByteFlagAt0x154((unsigned char*)p);

        int flag10 = *(int*)(obj + 0x10);
        char* buf = *(char**)(g + TextBufferPointer);
        if (flag10 == 0) {
#if defined(jpn)
            sprintf(buf, &data_ov017_021d7c28);
#else
            sprintf(buf, (const char*)CallFunc020e0434With02153694(0x3a));
#endif
        } else {
#if defined(jpn)
            sprintf(buf, &data_ov017_021d7c49);
#else
            sprintf(buf, (const char*)CallFunc020e0434With02153694(0x3b));
#endif
            *(int*)(obj + 0xc) = 0x170c;
        }
#if defined(jpn)
        func_02045d88(g, buf, 0);
#else
        func_0204500c(g, buf, 0, 0xe3);
#endif
        *(unsigned char*)(g + 0x1000 + MessageFlag) = 0;
        *(int*)(g + MessageStatus) = 1;
        SetFlagsAt0x244((unsigned char*)field, 2);
        *(int*)(obj + 0x8) = 1;
        return;
    }

    if (status != 1 || *(int*)(g + PendingMessage) != 0) return;

    ClearFlagBits((unsigned char*)field, 2);
    if (func_020457e0(g) == 0) {
        GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct);
        char* p3 = (char*)GetField0x3f8Address(battleStruct);
        VectorizedMemset(p3, 0, 0x70);
        p3[4] = 1;
        p3[8] = 1;
        p3[9] = 1;
        p3[0xb] = -1;
        *(int*)(p3 + 0x20) = -1;
        *(int*)(p3 + 0x24) = -1;
        *(int*)(p3 + 0x28) = -1;
        *(int*)(p3 + 0x2c) = -1;
        *(short*)(p3 + 0x1e) = -1;
        p3[0xc] = 0;
        *(short*)(p3 + 0x6c) = -1;
        *(short*)(p3 + 0x0) = (short)(*(int*)(obj + 0xc));
        p3[2] = 1;
        p3[7] = 1;

        if (*(int*)(obj + 0x10) == 0) {
            *(int*)(p3 + 0x10) = 0x100000;
            *(int*)(p3 + 0x14) = 0;
            *(int*)(p3 + 0x18) = 0x100000;
            *(short*)(p3 + 0x1c) = 0;
        } else {
            *(int*)(p3 + 0x10) = 0x5f0a;
            *(int*)(p3 + 0x14) = 0x3614;
            *(int*)(p3 + 0x18) = 0x570;
            *(short*)(p3 + 0x1c) = 0x4b66;
        }
        ReinitController02043204(g);
        obj[1] = 1;
        return;
    }

    ReinitController02043204(g);
    void* p = GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct);
    SetByteFlagAt0x154((unsigned char*)p);
    obj[1] = 1;
}
