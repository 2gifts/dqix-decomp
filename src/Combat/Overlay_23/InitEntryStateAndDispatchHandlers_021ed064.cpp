#include <globaldefs.h>

ARM int DispatchIfFlagsOrByteSet_021ed014(void);

struct Elem_0205d81c;
struct Struct_0205d81c;
ARM struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
ARM int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);
ARM void SetElementFieldC2(struct Struct_0205d81c* s, int key, int value);

extern "C" void func_ov023_021ed194(char* obj);
extern "C" void func_ov023_021ed354(char* obj);
extern "C" void func_ov023_021ed4b8(void* obj);

extern unsigned char data_ov023_021fd844[];

// USA: func_ov023_021ed064  (semantic: InitEntryStateAndDispatchHandlers_021ed064)
extern "C" ARM int func_ov023_021ed064(void* obj) {
    if (DispatchIfFlagsOrByteSet_021ed014() == 0) {
        return 0;
    }

    *(unsigned short*)((char*)obj + 0x43e) = 0;
    *(unsigned short*)((char*)obj + 0x43a) = 0;
    *((unsigned char*)obj + 0x433) = 0;
    *(short*)((char*)obj + 0x448) = -0x24;
    *((unsigned char*)obj + 0x43c) = 0;
    *(unsigned short*)((char*)obj + 0x438) &= ~0x40;
    *(unsigned short*)((char*)obj + 0x438) &= ~0x80;
    *(unsigned short*)((char*)obj + 0x438) |= 0x200;
    *(unsigned short*)((char*)obj + 0x438) |= 0x2;

    struct Elem_0205d81c* elem = FindElementByC40205d81c((struct Struct_0205d81c*)((char*)obj + 0xc4), 0);
    if (elem != 0 && CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem) != 0) {
        *(unsigned short*)((char*)obj + 0x438) |= 0x1;
    } else {
        func_ov023_021ed194((char*)obj);
    }

    if (FindElementByC40205d81c((struct Struct_0205d81c*)((char*)obj + 0xc4), 1) == 0) {
        func_ov023_021ed354((char*)obj);
    }
    if (FindElementByC40205d81c((struct Struct_0205d81c*)((char*)obj + 0xc4), 2) == 0) {
        func_ov023_021ed4b8(obj);
    }

    unsigned char buf[2];
    buf[0] = data_ov023_021fd844[2];
    buf[1] = data_ov023_021fd844[3];
    for (int i = 0; i < 2; i++) {
        SetElementFieldC2((struct Struct_0205d81c*)((char*)obj + 0xc4), buf[i], 0);
    }

    *(unsigned short*)((char*)obj + 0x438) |= 0x100;
    return 1;
}
