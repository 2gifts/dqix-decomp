#include <globaldefs.h>

#if defined(jpn)
enum { stateOffset = 0x1804 };
#else
enum { stateOffset = 0x19e0 };
#endif
void SetField0x1e20(void*, void*);

int GetGlobalField0x1c020421a0();
int CheckField0x440State2(unsigned char* obj);
void InitSelfPointer(unsigned char* base);

// USA: func_0205cde8
ARM int CheckGlobalObjState2AndInit0205cde8(unsigned char* p) {
    unsigned char* base = (unsigned char*)GetGlobalField0x1c020421a0();
    SetField0x1e20((void*)(base), (void*)(p + 0xb4));
    int result = CheckField0x440State2(base + stateOffset) != 0;
    InitSelfPointer(base);
    return result;
}
