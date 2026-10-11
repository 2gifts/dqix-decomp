#include <globaldefs.h>

extern char* data_ov004_02171010;
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned int func_ov023_021f6f10(void* self);
#if defined(jpn)
enum { fieldBase = 0x1900 };
#else
enum { fieldBase = 0x1800 };
#endif

struct ShortPair02163530 { char pad[0x5c]; short a; short b; };

// USA: func_ov004_02163530
extern "C" ARM int func_ov004_02163530(void* param0) {
    *(short*)(data_ov004_02171010 + fieldBase + 0xf8) = 1;
    while (*(short*)(data_ov004_02171010 + fieldBase + 0xf8) * 8 < *(unsigned char*)(data_ov004_02171010 + fieldBase + 0xf4)) {
        (*(short*)(data_ov004_02171010 + fieldBase + 0xf8))++;
    }

    void* obj = func_ov023_021f6880(func_ov011_021849c8(param0), 0xa);
    if (obj == NULL) {
        return (int)obj;
    }

    int t = func_ov023_021f6f10(obj);
    if (t != 7) {
        return t;
    }

    struct ShortPair02163530* p = (struct ShortPair02163530*)obj;
    *(short*)(data_ov004_02171010 + fieldBase + 0xf6) = p->a;

    short f8 = *(short*)(data_ov004_02171010 + fieldBase + 0xf8);
    short f6 = *(short*)(data_ov004_02171010 + fieldBase + 0xf6);
    p->a = f6;
    p->b = f8;
    return f6;
}
