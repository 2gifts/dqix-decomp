#include <globaldefs.h>
#if defined(jpn)
enum { kRegion400 = 0x200 };
enum { kRegion8c = 0xb4 };
enum { kRegion9f = 0xc7 };
enum { kRegion318 = 0x200 };
#else
enum { kRegion400 = 0x400 };
enum { kRegion8c = 0x8c };
enum { kRegion9f = 0x9f };
enum { kRegion318 = 0x318 };
#endif

void* GetElementAtIndex_02160bd0_02160bd0(void* unused, int index);
extern "C" void func_ov003_02167a5c(void* p, int type, int val);

// JPN: func_ov003_02161520
// USA: func_ov003_02161438
ARM void ApplyElementEffect02161438(void* obj) {
    char* p = (char*)obj + kRegion400;
    short v = *(short*)(p + kRegion8c);
    signed char b = *(signed char*)(p + kRegion9f);
    int idx = (v - 0x15) + (b << 2);
    int val = -1;
    void* e = GetElementAtIndex_02160bd0_02160bd0(obj, idx);
    if (e != NULL) {
        signed char c = *(signed char*)e;
        val = (c << 26) >> 26;
    }
    func_ov003_02167a5c(*(void**)((char*)obj + kRegion318), 6, val);
}
