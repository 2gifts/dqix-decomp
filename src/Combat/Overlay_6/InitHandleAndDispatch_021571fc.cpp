#include <globaldefs.h>

#if defined(jpn)
enum { kPendingNode = 0x109c, kEffectFlag = 0x10b8 };
#else
enum { kPendingNode = 0x12a0, kEffectFlag = 0x12bc };
#endif

#include "std_library_functions.h"

struct InitStruct02078484Struct;
extern void InitStruct02078484(struct InitStruct02078484Struct*);
struct Obj020dbfa4;
extern void ProcessPendingNode020dbfa4(struct Obj020dbfa4*, int);

extern char data_ov006_02160087[];

struct InitStruct02078484Struct_021571fc {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short f14;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; int f2c; int f30;
    int f34; int f38; int f3c; int f40;
    int f44; int f48; int f4c;
};

// USA: func_ov006_021571fc
ARM void InitHandleAndDispatch_021571fc(char* obj) {
    struct InitStruct02078484Struct_021571fc buf;
    InitStruct02078484((struct InitStruct02078484Struct*)&buf);
    buf.b2 = 0;
    buf.f12 = 0;
    strcpy((char*)&buf, data_ov006_02160087);
    buf.f44 = 0x10a;
    buf.f48 = 0x10a;
    buf.f4c = 0x10a;
    buf.f2c = 0xc9 - 0x10a;
    buf.f30 = (int)0xfffff554;
    buf.f34 = 0x4526;
    ProcessPendingNode020dbfa4((struct Obj020dbfa4*)(obj + kPendingNode), (int)&buf);
    *(unsigned char*)(obj + kEffectFlag) = 1;
}
