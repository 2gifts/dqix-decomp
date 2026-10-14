#include <globaldefs.h>

#if defined(jpn)
enum { stateOffset = 0x1804, selfPointerOffset = 0x1c44 };
#else
enum { stateOffset = 0x19e0, selfPointerOffset = 0x1e20 };
#endif
void SetField0x1e20_02042b10(void*, void*);

int GetGlobalField0x1c020421a0();
int CheckField0x440State2_0205cd6c(unsigned char* obj);
void InitSelfPointer_02042b1c(unsigned char* base);

// USA: func_0205cd94
ARM void InitGlobalObjAndSelfPointer0205cd94(unsigned char* p) {
    unsigned char* base = (unsigned char*)GetGlobalField0x1c020421a0();
    SetField0x1e20_02042b10((void*)(base), (void*)(p + 0xb4));
    if (CheckField0x440State2_0205cd6c(base + stateOffset) == 0) {
        *(int*)((char*)*(int**)(base + selfPointerOffset) + 0x8) = 2;
        *(int*)((char*)*(int**)(base + selfPointerOffset) + 0x14) = 0x1000;
    }
    InitSelfPointer_02042b1c(base);
}
