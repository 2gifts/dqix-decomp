#if defined(jpn)
#define R(j,u) (j)
#define data_ov013_02187d98 data_ov013_02188ccc
#define func_ov013_02185424 func_ov013_02186468
#define func_ov013_02185be0 func_ov013_02186db0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);

extern "C" void func_0205bb04(void* s, int n);
extern "C" void func_ov013_02185424(void* obj, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

// USA: func_ov013_02185310
ARM void InitTag02185310(unsigned char* obj) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + R(0x34, 0x38)), 0, 2);

    *(unsigned short*)(obj + R(0xd4, 0xd8)) = 0x1e;
    *(unsigned short*)(obj + R(0xd6, 0xda)) = 0xd;
    *(unsigned short*)(obj + R(0xd8, 0xdc)) = 1;
    *(unsigned short*)(obj + R(0xda, 0xde)) = 0;
    *(unsigned short*)(obj + R(0xdc, 0xe0)) = 0;
    *(unsigned short*)(obj + R(0xde, 0xe2)) = 5;
    *(unsigned short*)(obj + R(0xe0, 0xe4)) = 0xa;
    *(unsigned short*)(obj + R(0xe2, 0xe6)) = 0xd;
    obj[R(0xe5, 0xe9)] = 0;

    if (obj[R(0x5cc, 0x640)] != 0) obj[R(0xe9, 0xed)] = 0;
    else obj[R(0xe9, 0xed)] = 1;

    memset(*(void**)(obj + R(0x5e0, 0x658)), 0, R(0x800, 0x960));

    func_ov013_02185424(obj, *(void**)(obj + R(0x5e0, 0x658)));

#if defined(jpn)
    func_0205d304(obj + R(0x34, 0x38), *(void**)(obj + R(0x5e0, 0x658)), 0, 0, 0, 1, 0);
#else
    func_0205d304(obj + R(0x34, 0x38), *(void**)(obj + R(0x5e0, 0x658)), 0, 0, 0, 1, 0, 0);
#endif

    obj[R(0xe5, 0xe9)] = 0;
    *(int*)(obj + R(0x3c, 0x40)) = 1;
    *(int*)(obj + R(0x8c, 0x90)) = 1;
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + R(0x38, 0x3c)), 1, 6, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + R(0x88, 0x8c)), 1, 6, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + R(0x38, 0x3c)), 6);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + R(0x88, 0x8c)), 6);
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(obj + R(0x38, 0x3c)), 1);
    func_0205bb04(obj + R(0x88, 0x8c), 1);
}
