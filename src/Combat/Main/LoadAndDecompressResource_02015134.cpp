#include "World/ZoneResourceInitialization.h"
#include "Filesystem/FileIO.h"
#include <globaldefs.h>

#if defined(jpn)
enum { kOffset68 = 0x88 };
#else
enum { kOffset68 = 0x68 };
#endif

void FormatFilenameAndSetExtension02014d18(int id, char* ext, char* outBuf);
void* GetFileFromNARCInMemory(const char* path);
void Clear0x4cBytes0204bf30(void* p);
struct RenderParams0204bf44;
struct RenderSource0204bf44;
void InitRenderParams0204bf44(RenderParams0204bf44*, void*, RenderSource0204bf44*, unsigned int);

extern char data_020ef1ee;

// USA: func_02015134  (semantic: LoadAndDecompressResource_02015134)
extern "C" ARM int func_02015134(Ctx02015134* ctx, Out02015134* out, Src02015134* src) {
    void* allocator = *(void**)((char*)ctx + kOffset68);
    char buf[0x50];
    unsigned int size;
    FormatFilenameAndSetExtension02014d18(src->id, &data_020ef1ee, buf);
    void* fileData = GetFileFromNARCInMemory(buf);
    if (fileData) {
        out->field4 = ((SafeAllocator*)allocator)->Allocate(0x4c);
        if (out->field4 == 0) return 0;
        void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*(SafeAllocator*)allocator, fileData, size);
        if (decompressed == 0) return 0;
        Clear0x4cBytes0204bf30(out->field4);
        InitRenderParams0204bf44((RenderParams0204bf44*)out->field4, allocator, (RenderSource0204bf44*)decompressed, size);
    }
    out->flag = 1;
    return 1;
}
