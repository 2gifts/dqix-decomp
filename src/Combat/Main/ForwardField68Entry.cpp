#include <globaldefs.h>

#if defined(jpn)
#define _ZN6Zone3D15ProcessBPOSFileEPKvj func_020141a4
enum { AllocatorOffset = 0x88, SubobjectOffset = 0x8c };
#else
enum { AllocatorOffset = 0x68, SubobjectOffset = 0x6c };
#endif

struct SafeAllocator;
void* DecompressLZ77FileIntoScratchSpace(struct SafeAllocator&, const void*, unsigned int&);
extern "C" void _ZN12ZoneFeatures14LoadFromScriptEP13SafeAllocatorPKvj(int, int, int, int);

// USA: func_020143d8
extern "C" ARM int _ZN6Zone3D15ProcessBPOSFileEPKvj(char* obj, int arg1) {
    int f68 = *(int*)(obj + AllocatorOffset);
    int out;
    int r = (int)DecompressLZ77FileIntoScratchSpace(*(struct SafeAllocator*)f68, (const void*)arg1, *(unsigned int*)&out);
    int saved = *(int*)(obj + 0x8);
    _ZN12ZoneFeatures14LoadFromScriptEP13SafeAllocatorPKvj((int)(obj + SubobjectOffset), f68, r, out);
    *(int*)(obj + 0x8) = saved;
    return 1;
}
