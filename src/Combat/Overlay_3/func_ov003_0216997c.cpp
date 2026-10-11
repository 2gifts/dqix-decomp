#include <globaldefs.h>
#if defined(jpn)
enum { kRegione4 = 0xe0 };
enum { kRegion184 = 0x180 };
enum { kRegion186 = 0x182 };
enum { kRegion188 = 0x184 };
enum { kRegion18a = 0x186 };
enum { kRegion18c = 0x188 };
enum { kRegion18e = 0x18a };
enum { kRegion190 = 0x18c };
enum { kRegion192 = 0x18e };
enum { kRegion195 = 0x191 };
enum { kRegion199 = 0x195 };
enum { kRegion4ed = 0x4e9 };
enum { kRegion960 = 0x800 };
#else
enum { kRegione4 = 0xe4 };
enum { kRegion184 = 0x184 };
enum { kRegion186 = 0x186 };
enum { kRegion188 = 0x188 };
enum { kRegion18a = 0x18a };
enum { kRegion18c = 0x18c };
enum { kRegion18e = 0x18e };
enum { kRegion190 = 0x190 };
enum { kRegion192 = 0x192 };
enum { kRegion195 = 0x195 };
enum { kRegion199 = 0x199 };
enum { kRegion4ed = 0x4ed };
enum { kRegion960 = 0x960 };
#endif

#if defined(jpn)
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#endif
#include "std_library_functions.h"

struct Struct0205de24;
ARM void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" int func_020420e8(char* str, int id);
extern "C" void func_ov003_02169a84(char* base, char* dst, int flag);
#if !defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// JPN: func_ov003_021697b0
// USA: func_ov003_0216997c
extern "C" ARM void func_ov003_0216997c(void* objRaw) {
    char* obj = (char*)objRaw;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + kRegione4), 0, 2);

#if defined(jpn)
    int v = 8;
#else
    struct Container020e0310* c = (struct Container020e0310*)(obj + 0x64);
    short maxLen = 0;
    for (int i = 0; i < 3; i++) {
        int name = GetFieldByKey020e0434(c, (short)i);
        short len = (short)func_020420e8((char*)name, 0);
        if (maxLen < len) maxLen = len;
    }

    int v = ((maxLen + 0x18) << 13) >> 16;
#endif
    *(short*)(obj + kRegion184) = v;
    *(short*)(obj + kRegion186) = 6;
    *(short*)(obj + kRegion188) = 0x1f - v;
    *(short*)(obj + kRegion18a) = 2;
    *(short*)(obj + kRegion18c) = 0xc;
    *(short*)(obj + kRegion18e) = 8;
    *(short*)(obj + kRegion190) = 0xa;
    *(short*)(obj + kRegion192) = 0xe;

    *(unsigned char*)(obj + kRegion195) = 1;
    *(unsigned char*)(obj + kRegion199) = 1;
    *(unsigned char*)(obj + kRegion4ed) = 0;

    memset(*(char**)(obj + 0x7c), 0, kRegion960);
    func_ov003_02169a84(obj, *(char**)(obj + 0x7c), 0);
#if defined(jpn)
    func_0205d304(obj + kRegione4, *(char**)(obj + 0x7c), 0, 1, 0, 1, 0);
#else
    func_0205d304(obj + kRegione4, *(char**)(obj + 0x7c), 0, 1, 0, 1, 0, 0);
#endif
}
