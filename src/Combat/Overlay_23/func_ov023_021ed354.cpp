#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
int GetGlobalField0x1c020421a0(void);
extern "C" ARM void func_02046608(void* a, int b, int c, void* d, int e, int f, int g);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
void AppendString02042058(char*, const char*);
#else
extern "C" ARM void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif


// JPN: func_ov023_021ed2d0
// USA: func_ov023_021ed354
extern "C" ARM void func_ov023_021ed354(char* obj) {
    struct Bits0205de24 { unsigned char low4 : 4; unsigned char high4 : 4; };
    unsigned char keyLow = ((Bits0205de24*)(obj + 0xa0))->low4;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xc4), keyLow, 3);

    *(unsigned short*)(obj + 0x164) = 0x1e;
#if defined(jpn)
    *(unsigned short*)(obj + 0x166) = 0xb;
#else
    *(unsigned short*)(obj + 0x166) = 0xa;
#endif

    *(unsigned short*)(obj + 0x168) = 0x1;
#if defined(jpn)
    *(unsigned short*)(obj + 0x16a) = 0xc;
#else
    *(unsigned short*)(obj + 0x16a) = 0xd;
#endif

#if defined(jpn)
    *(unsigned short*)(obj + 0x16c) = 0xa;
#else
    *(unsigned short*)(obj + 0x16c) = 0x7;
#endif

#if defined(jpn)
    *(unsigned short*)(obj + 0x16e) = 0xa;
#else
    *(unsigned short*)(obj + 0x16e) = 0x8;
#endif

    *(unsigned short*)(obj + 0x170) = 0xc;
#if defined(jpn)
    *(unsigned short*)(obj + 0x172) = 0x14;
#else
    *(unsigned short*)(obj + 0x172) = 0xc;
#endif

    *(unsigned char*)(obj + 0x17b) = 0xc;
    *(unsigned char*)(obj + 0x175) = 0x1;
    *(unsigned char*)(obj + 0x179) = 0;
    *(unsigned char*)(obj + 0x17a) = 0;

#if defined(jpn)
    char* elem = *(char**)(obj + 0x20) + *(unsigned char*)(obj + 0x28) * 0x15c;
    memset(*(void**)(obj + 0x1c), 0, 0x800);
    AppendString02042058(*(char**)(obj + 0x1c), *(char**)(elem + 4));

#else
    void* g = (void*)GetGlobalField0x1c020421a0();
    memset(*(void**)(obj + 0x1c), 0, 0x960);

    void* base = *(void**)(obj + 0x20);
    unsigned char idx = *(unsigned char*)(obj + 0x28);
    int c = *(int*)((char*)base + idx * 0x244 + 4);
    func_02046608(g, 1, c, *(void**)(obj + 0x1c), 0xe3, 0, 1);


#endif
#if defined(jpn)
    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0);
#else
    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
#endif

}
