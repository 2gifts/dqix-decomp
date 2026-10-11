#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj_021588bc { int f0; int f4; };
#if defined(jpn)
#define InitObjFields_021588bc _Z22InitObjFields_021588bcP12Obj_021588bcii
extern "C" int InitObjFields_021588bc(Obj_021588bc* obj, int a, int b);
#else
int InitObjFields_021588bc(Obj_021588bc* obj, int a, int b);
#endif

struct Data02165880_a954 { char pad0[8]; int field8; char pad1[0x18]; Obj_021588bc* field24; };
extern Data02165880_a954 data_ov001_02165880;

struct Data021658b8_a954 { char pad0[0xe4]; int field_e4; char pad1[4]; int field_ec; };
extern Data021658b8_a954 data_ov001_021658b8;

// USA: func_ov001_0215a954  (semantic: Func_0215a954)
extern "C" ARM void func_ov001_0215a954(void) {
    *(unsigned short*)0x4000060 = (*(unsigned short*)0x4000060 & ~0x3000) | 4;
    *(unsigned short*)0x4000340 = 0;
    InitObjFields_021588bc(data_ov001_02165880.field24, data_ov001_02165880.field8, 8);
    data_ov001_021658b8.field_ec = 0;
    if (data_ov001_021658b8.field_e4) data_ov001_021658b8.field_e4 = 0;
}
