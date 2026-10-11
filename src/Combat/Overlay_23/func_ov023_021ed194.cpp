#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov023_021ed254(void* obj, void* buf);
#if defined(jpn)
extern "C" ARM void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" ARM void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif


// JPN: func_ov023_021ed0e8
// USA: func_ov023_021ed194
extern "C" ARM void func_ov023_021ed194(char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x800};
#else
 enum {regionalOffset0=0x960};
#endif
    struct Bits0205de24_021ed194 { unsigned char low4 : 4; unsigned char high4 : 4; };
    unsigned char keyLow = ((struct Bits0205de24_021ed194*)(obj + 0xa0))->low4;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xc4), keyLow, 3);

#if defined(jpn)
    *(unsigned short*)(obj + 0x164) = 0x10;
#else
    *(unsigned short*)(obj + 0x164) = 0x14;
#endif

    *(unsigned short*)(obj + 0x166) = 3;
#if defined(jpn)
    *(unsigned short*)(obj + 0x168) = 8;
#else
    *(unsigned short*)(obj + 0x168) = 6;
#endif

    *(unsigned short*)(obj + 0x16a) = 5;
    *(unsigned short*)(obj + 0x16c) = 0;
#if defined(jpn)
    *(unsigned short*)(obj + 0x16e) = 5;
#else
    *(unsigned short*)(obj + 0x16e) = 6;
#endif
    *(unsigned short*)(obj + 0x170) = 0xc;
    *(unsigned short*)(obj + 0x172) = 0xe;
    *(unsigned char*)(obj + 0x17b) = 0xc;
    *(unsigned char*)(obj + 0x175) = 0;
    *(unsigned char*)(obj + 0x179) = 1;
    *(unsigned char*)(obj + 0x17a) = 1;

    memset(*(void**)(obj + 0x1c), 0, regionalOffset0);

    func_ov023_021ed254(obj, *(void**)(obj + 0x1c));

#if defined(jpn)
    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0);
#else
    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
#endif

}
