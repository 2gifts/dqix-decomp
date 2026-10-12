#include <globaldefs.h>

struct Struct_0205def8;
struct Struct_0205d81c;
struct Elem_0205d81c;

extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8* s, int clear, int key);
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
int IsField0x9cEqual3(unsigned char* obj);
extern "C" void _Z22SetEntryFields02154bcciiPvihh(int a, int b, void* obj, int idx, unsigned char arg5, unsigned char arg6);

// USA: func_ov002_0215b138
extern "C" ARM void func_ov002_0215b138(unsigned char* obj) {
    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)(obj + 0x2c8 + 0xc00), 0, 0x28);

    if (*(int*)(obj + 0x1000 + 0xbb8) != 4 && *(int*)(obj + 0x1000 + 0xbb8) != 5) {
        return;
    }
    if (*(signed char*)(obj + 0x1c00 + 0x20) != 4) {
        return;
    }

    struct Elem_0205d81c* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)(obj + 0x2c8 + 0xc00), 0x28);
    if (elem == 0) {
        return;
    }
    if (!IsField0x9cEqual3((unsigned char*)elem)) {
        return;
    }

    int b;
    int a = *(short*)((char*)elem + 0xac);
    b = *(short*)((char*)elem + 0xae);
    b = (short)(b * 8);
    a = (short)(a * 8);

    _Z22SetEntryFields02154bcciiPvihh(a, b, *(void**)(obj + 0x1000 + 0xa68), 0x26, 0x55, 0xff);

    unsigned char byteVal = *(unsigned char*)(obj + 0x2000 + 0x48d);
    unsigned short idx2 = (unsigned short)(byteVal + 0x27);
    _Z22SetEntryFields02154bcciiPvihh(a, b, *(void**)(obj + 0x1000 + 0xa68), idx2, 0x58, 0xff);

    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)(obj + 0x2c8 + 0xc00), 1, 0x28);
}
