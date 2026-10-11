#include <globaldefs.h>

#if defined(jpn)
#define func_ov014_02188c34 func_ov014_02189a78
#endif
#include "Filesystem/BackgroundLoader.h"

struct HandleState_02188d10;
int ResetHandle_02188d10(struct HandleState_02188d10* s);
extern "C" void func_ov014_02188d48(void* self, int p1, void* out1, unsigned int out2, short p5);
extern "C" int func_ov014_02188c34(void* self);

extern int data_ov014_021897c4;

// USA: func_ov014_02188c34
extern "C" ARM int func_ov014_02188c34(void* selfRaw) {
    char* self = (char*)selfRaw;
    int r = (int)BackgroundLoader::GetInstance();
    short state = *(short*)(self + 0x16);
    switch (state) {
    case 1:
        *(int*)(self + 0x18) = ((BackgroundLoader*)(r))->QueueLoadFileInGP2((const char*)(*(int*)((char*)&data_ov014_021897c4 + 4)), (const char*)(*(int*)&data_ov014_021897c4), (SafeAllocator*)(0));
        *(short*)(self + 0x16) = 2;
        return func_ov014_02188c34(self);
    case 2:
        if (((BackgroundLoader*)(r))->GetTaskStatus((int)(*(int*)(self + 0x18))) == 0) return 0;
        *(short*)(self + 0x16) = 3;
        return func_ov014_02188c34(self);
    case 3: {
        int out1 = 0, out2 = 0;
        ((BackgroundLoader*)(r))->GetLoadedFileByID((int)(*(int*)(self + 0x18)), (void**)(&out1), (unsigned int*)(&out2));
        func_ov014_02188d48(self, *(int*)(self + 0x1c), (void*)out1, (unsigned int)out2, *(short*)(self + 0x14));
        ResetHandle_02188d10((struct HandleState_02188d10*)self);
        return 1;
    }
    default:
        return 1;
    }
}
