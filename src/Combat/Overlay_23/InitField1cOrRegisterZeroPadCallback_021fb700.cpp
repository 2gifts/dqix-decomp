#include <globaldefs.h>

#if defined(jpn)
#define data_ov023_021fef64 data_ov023_021fe210
#endif


#if defined(jpn)
#define func_ov023_021fb700 func_ov023_021faaa4
#endif
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);

extern char data_ov023_021fef64;

// USA: func_ov023_021fb700  (semantic: InitField1cOrRegisterZeroPadCallback_021fb700)
extern "C" ARM int func_ov023_021fb700(void* a, void* b) {
    void* sub = func_ov011_021849c8(b);
    if (func_ov023_021f6bb8(sub) >= 0) {
        return *(int*)((char*)a + 0x1c);
    }
    char buf[0x50];
    int builder = (int)BackgroundLoader::GetInstance();
    sprintf(buf, (const char*)&data_ov023_021fef64, *(int*)((char*)a + 0x10));
    int result = ((BackgroundLoader*)(builder))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    func_ov023_021f6bb0(sub, result);
    return 1;
}
