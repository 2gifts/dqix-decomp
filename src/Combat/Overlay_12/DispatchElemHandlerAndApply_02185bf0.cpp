#if defined(jpn)
#define data_ov012_0218b088 data_ov012_0218bda8
#define TryApplyElemFields0205d5d0 _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185bf0 func_ov012_02186248
#endif
#include "std_library_functions.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int);
#else
extern int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif

struct Obj02185bf0;
typedef void (Obj02185bf0::*Handler02185bf0)(void* dest, int alt);
extern Handler02185bf0 data_020e6d5c;

struct Table02185bf0 { Handler02185bf0 e[16]; };
extern struct Table02185bf0 data_ov012_0218b088;

// USA: func_ov012_02185bf0  (semantic: DispatchElemHandlerAndApply_02185bf0)
extern "C" ARM void func_ov012_02185bf0(char* obj, int id, int flag) {
    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + LOW_REGION(0x90, 0xac)), id);
    if (e == 0) return;

    unsigned char* c5p = (unsigned char*)e + 0xc5;
    if (flag) *c5p |= 0x40;
    else *c5p &= ~0x40;
    flag = 0;

    if (*c5p & 2) flag = 1;
    void* dest = *(void**)(obj + LOW_REGION(0x1344, 0x1374));
    memset(dest, 0, LOW_REGION(0x800, 0x960));

    struct Table02185bf0 table = data_ov012_0218b088;
    Handler02185bf0 none = data_020e6d5c;
    table.e[0] = none;
    table.e[15] = none;

    if (table.e[id] != 0)
        (((Obj02185bf0*)obj)->*table.e[id])(*(void**)(obj + LOW_REGION(0x1344, 0x1374)), flag);

#if defined(jpn)
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(obj + LOW_REGION(0x90, 0xac)), id, *(int*)(obj + LOW_REGION(0x1344, 0x1374)), 0);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(obj + LOW_REGION(0x90, 0xac)), id, *(int*)(obj + LOW_REGION(0x1344, 0x1374)), 0, 0);
#endif
}
