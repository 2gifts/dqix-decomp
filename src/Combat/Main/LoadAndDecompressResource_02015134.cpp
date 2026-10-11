#include "World/ZoneResourceInitialization.h"
#include <globaldefs.h>

#if defined(jpn)
enum { kOffset68 = 0x88 };
#else
enum { kOffset68 = 0x68 };
#endif


extern "C" void _Z37FormatFilenameAndSetExtension02014d18iPcS_(int id, char* ext, char* outBuf);
extern "C" void* _Z23GetFileFromNARCInMemoryPKc(const char* path);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* self, unsigned int size);
extern "C" void* _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(void* allocator, const void* src, unsigned int* outSize);
extern "C" void _Z22Clear0x4cBytes0204bf30Pv(void* p);
extern "C" void _Z24InitRenderParams0204bf44P20RenderParams0204bf44iP20RenderSource0204bf44(void* params, void* allocator, void* src, unsigned int size);

extern char data_020ef1ee;


// USA: func_02015134  (semantic: LoadAndDecompressResource_02015134)
extern "C" ARM int func_02015134(Ctx02015134* ctx, Out02015134* out, Src02015134* src) {
    void* allocator = *(void**)((char*)ctx + kOffset68);
    char buf[0x50];
    unsigned int size;
    _Z37FormatFilenameAndSetExtension02014d18iPcS_(src->id, &data_020ef1ee, buf);
    void* fileData = _Z23GetFileFromNARCInMemoryPKc(buf);
    if (fileData) {
        out->field4 = _ZN13SafeAllocator8AllocateEj(allocator, 0x4c);
        if (out->field4 == 0) return 0;
        void* decompressed = _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(allocator, fileData, &size);
        if (decompressed == 0) return 0;
        _Z22Clear0x4cBytes0204bf30Pv(out->field4);
        _Z24InitRenderParams0204bf44P20RenderParams0204bf44iP20RenderSource0204bf44(out->field4, allocator, decompressed, size);
    }
    out->flag = 1;
    return 1;
}
