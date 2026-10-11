#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" unsigned short func_ov017_021bbc04(void* obj);
extern "C" void func_ov017_021bbbec(void* obj, unsigned short v);
void SetField11c_021bbbf8(void* obj, unsigned short v);

// USA: func_ov001_02162210  (semantic: SyncField11cFromField284_02162210)
extern "C" ARM int func_ov001_02162210(void) {
#if defined(jpn)
    enum { queueOffset = 0x524 };
#else
    enum { queueOffset = 0x734 };
#endif
    unsigned char* self = (unsigned char*)func_ov017_0218b5b0();
    void* work = *(void**)(self + 0x3000 + queueOffset);
    unsigned short val = func_ov017_021bbc04(work);
    if (val != 0) {
        func_ov017_021bbbec(work, val);
        SetField11c_021bbbf8(work, 0);
    }
    return 1;
}
