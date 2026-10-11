#include <globaldefs.h>
#if defined(jpn)
enum { kRegion960 = 0x800 };
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
enum { kRegion4ee = 0x4ea };
#else
enum { kRegion960 = 0x960 };
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
enum { kRegion4ee = 0x4ee };
#endif

#if defined(jpn)
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#endif
#include "std_library_functions.h"

struct Struct0205de24;
extern void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Elem_0205d81c;
struct Struct_0205d81c;
extern struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

extern "C" void func_ov003_02169d10(void* obj, void* ptr7c, int flag);
#if !defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// JPN: func_ov003_02169a1c
// USA: func_ov003_02169c3c
extern "C" ARM void func_ov003_02169c3c(char* obj) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + kRegione4), 0, 2);

    *(short*)(obj + kRegion184) = 0xe;
    *(short*)(obj + kRegion186) = 7;
    *(short*)(obj + kRegion188) = 0x11;
    *(short*)(obj + kRegion18a) = 7;
    *(short*)(obj + kRegion18c) = 8;
    *(short*)(obj + kRegion18e) = 0x10;
    *(short*)(obj + kRegion190) = 0xc;
    *(short*)(obj + kRegion192) = 0xe;

    obj[kRegion195] = 2;
    obj[kRegion199] = 1;
    obj[kRegion4ee] = 3;

    memset(*(void**)(obj + 0x7c), 0, kRegion960);
    func_ov003_02169d10(obj, *(void**)(obj + 0x7c), 0);
#if defined(jpn)
    func_0205d304(obj + kRegione4, *(void**)(obj + 0x7c), 0, 0, 0, 1, 0);
#else
    func_0205d304(obj + kRegione4, *(void**)(obj + 0x7c), 0, 0, 0, 0, 0, 1);
#endif

    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + kRegione4), 2);
    *((unsigned char*)e + 0xc6) = 0;
}
