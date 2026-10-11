#include <globaldefs.h>
#if defined(jpn)
enum { kRegion4e8 = 0x4e4 };
enum { kRegione4 = 0xe0 };
enum { kRegion960 = 0x800 };
enum { kRegion998 = 0x868 };
enum { kRegion4ec = 0x4e8 };
#else
enum { kRegion4e8 = 0x4e8 };
enum { kRegione4 = 0xe4 };
enum { kRegion960 = 0x960 };
enum { kRegion998 = 0x998 };
enum { kRegion4ec = 0x4ec };
#endif

#if defined(jpn)
extern "C" void func_02045d88(void*, void*, int);
#endif
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0(void);
extern "C" int func_0205d6e4(void* obj, int flag);
extern "C" void func_ov003_0216abd8(void* obj, void* buf);
extern "C" void func_0204500c(void* dst, void* src, int a, int b);

// JPN: func_ov003_0216925c
// USA: func_ov003_02169430  (semantic: InitOrClearEntry_02169430)
extern "C" ARM void func_ov003_02169430(void* p) {
    char* obj = (char*)p;
    int g = GetGlobalField0x1c020421a0();
    unsigned char state = *(unsigned char*)(obj + kRegion4e8);
    if (state == 0) {
        func_0205d6e4(obj + kRegione4, 1);
        memset(*(void**)(obj + 0x7c), 0, kRegion960);
        func_ov003_0216abd8(obj, *(void**)(obj + 0x7c));
#if defined(jpn)
        func_02045d88((void*)g, *(void**)(obj + 0x7c), 0);
#else
        func_0204500c((void*)g, *(void**)(obj + 0x7c), 0, 0xe3);
#endif
        *(unsigned char*)(obj + kRegion4e8) = *(unsigned char*)(obj + kRegion4e8) + 1;
    } else if (state == 1) {
        if (*(int*)((char*)g + kRegion998) == 0) {
            *(unsigned char*)(obj + kRegion4ec) = 6;
            *(unsigned char*)(obj + kRegion4e8) = 0;
        }
    }
}
