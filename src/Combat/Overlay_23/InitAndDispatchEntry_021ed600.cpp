#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

int AppendString02042058(char* dst, const char* src);

#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov023_021ed600  (semantic: InitAndDispatchEntry_021ed600)
extern "C" ARM void func_ov023_021ed600(char* obj) {
    struct Bits0205de24_021ed600 { unsigned char low4 : 4; unsigned char high4 : 4; };
    unsigned char keyLow = ((struct Bits0205de24_021ed600*)(obj + 0xc0))->low4;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xc4), keyLow, 3);

    *(unsigned short*)(obj + 0x164) = 0x20;
    *(unsigned short*)(obj + 0x166) = 0x9;
    *(unsigned short*)(obj + 0x168) = 0;
    *(unsigned short*)(obj + 0x16a) = 0xf;
    *(unsigned short*)(obj + 0x16c) = 0xa;
    *(unsigned short*)(obj + 0x16e) = 0xa;
    *(unsigned short*)(obj + 0x170) = 0xc;
    *(unsigned short*)(obj + 0x172) = 0x14;
    *(unsigned char*)(obj + 0x17b) = 0xc;
    *(unsigned char*)(obj + 0x175) = 2;
    unsigned char zero = 0;
    *(unsigned char*)(obj + 0x179) = zero;
    *(unsigned char*)(obj + 0x17a) = zero;

#if defined(jpn)
    memset(*(void**)(obj + 0x1c), zero, 0x800);
#else
    memset(*(void**)(obj + 0x1c), zero, 0x960);
#endif

    int key = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0x4), 0x3e8);
    AppendString02042058(*(char**)(obj + 0x1c), (const char*)(long)key);

#if defined(jpn)
    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 1, 0);
#else
    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
#endif
}
