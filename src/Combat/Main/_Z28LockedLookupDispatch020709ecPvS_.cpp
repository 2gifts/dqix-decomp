#include <globaldefs.h>

#if defined(jpn)
#define data_020f0b64 data_020f0cb0
#endif


extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*, void*, unsigned int*);
extern "C" void _Z23InitListBuffers02070a30P14Struct02070a30P13SafeAllocatorPv(void*, void*, void*);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();

extern char data_020f0b64;
extern char data_0211e33c;

#if defined(jpn)
#define _Z28LockedLookupDispatch020709ecPvS_ func_02071a58
extern "C" ARM void func_02071a58(void* p0, void* p1);
#endif

// USA: func_020709ec
// KEEP-NAME
extern "C" ARM void _Z28LockedLookupDispatch020709ecPvS_(void* p0, void* p1) {
    volatile unsigned int size;
    _ZN16BackgroundLoader13AddLockGlobalEv();
    void* buf = _Z18LoadFileIntoMemoryPKcPvPj((const char*)&data_020f0b64, (void*)&data_0211e33c, (unsigned int*)&size);
    (void)size;
    _Z23InitListBuffers02070a30P14Struct02070a30P13SafeAllocatorPv(p0, p1, buf);
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
}
