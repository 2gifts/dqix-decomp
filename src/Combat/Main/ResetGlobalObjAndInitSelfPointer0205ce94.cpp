#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
void SetField0x1e20_02042b10(void*, void*);
void InitSelfPointer_02042b1c(unsigned char* base);

// USA: func_0205ce94
ARM void ResetGlobalObjAndInitSelfPointer0205ce94(unsigned char* p) {
    unsigned char* base = (unsigned char*)GetGlobalField0x1c020421a0();
    SetField0x1e20_02042b10(base, p + 0xb4);
#if defined(jpn)
    void* q = *(void**)(base + 0x1c44);
#else
    void* q = *(void**)(base + 0x1e20);
#endif
    if (q != NULL) {
        *(int*)((char*)q + 8) = 0;
    }
    InitSelfPointer_02042b1c(base);
}
