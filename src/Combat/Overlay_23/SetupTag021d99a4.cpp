#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);

struct Container020e0310;
extern int GetFieldByKey020e0434(struct Container020e0310*, int);

#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif


// JPN: func_ov023_021da1b4
// USA: func_ov023_021d99a4  (semantic: SetupTag021d99a4)
extern "C" ARM void func_ov023_021d99a4(void* objRaw) {
#if defined(jpn)
 enum {regionalOffset0=0x1bc};
#else
 enum {regionalOffset0=0x1f8};
#endif
    char* obj = (char*)objRaw;
#if defined(jpn)
    int fieldA4 = 0x18;

#else
    struct Struct0200fb08* bs = (struct Struct0200fb08*)GameState::GetInstance();
    int fieldA4 = 0x18;
    int norm = NormalizeField5_0200fb08(bs);
    if (norm == 4) fieldA4 = 0x19;

#endif
#if defined(jpn)
    char* tag = obj;
    enum { tagBias=0x1bc };
#else
    char* tag = obj + regionalOffset0;
    enum { tagBias=0 };
#endif
    *(unsigned short*)(tag + tagBias + 0xa0) = 7;
    *(unsigned short*)(tag + tagBias + 0xa2) = 0x11;
    *(unsigned short*)(tag + tagBias + 0xa4) = fieldA4;
    *(unsigned short*)(tag + tagBias + 0xa6) = 5;
    *(unsigned short*)(tag + tagBias + 0xa8) = 6;
    *(unsigned short*)(tag + tagBias + 0xaa) = 6;
    *(unsigned short*)(tag + tagBias + 0xac) = 0xa;
    *(unsigned short*)(tag + tagBias + 0xae) = 0x10;
    unsigned char zero = 0;
    tag[tagBias + 0xb1] = zero;
    tag[tagBias + 0xb5] = 1;
    tag[tagBias + 0xb6] = 1;
#if defined(jpn)
    memset(*(void**)(obj + 0xd8), zero, 0x800);
    int fmt = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xc0), 0x4274);
    sprintf(*(char**)(obj + 0xd8), (const char*)(long)fmt);
    func_0205d304(obj + 0x1bc, *(void**)(obj + 0xd8), 0, 0, 0, 0, 0);

#else
    void* buf = *(void**)(obj + 0xf8);
    memset(buf, zero, 0x960);
    int fmt = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xe0), 0x4274);
    sprintf((char*)buf, (const char*)(long)fmt);
    func_0205d304(tag, buf, 0, 0, 0, 0, 0, 0);

#endif
}
