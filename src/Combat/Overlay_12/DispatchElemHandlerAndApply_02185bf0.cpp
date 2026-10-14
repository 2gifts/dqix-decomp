#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185bf0 func_ov012_02186248
enum { kElemOffset = 0x90, kDestOffset = 0x344, kDestSize = 0x800 };
#else
enum { kElemOffset = 0xac, kDestOffset = 0x374, kDestSize = 0x960 };
#endif
#include "std_library_functions.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

struct StructA0205d5d0;
struct Obj02185bf0;
typedef void (Obj02185bf0::*Handler02185bf0)(void* dest, int alt);
extern Handler02185bf0 data_020e6d5c;

struct Table02185bf0 { Handler02185bf0 e[16]; };
extern struct Table02185bf0 data_ov012_0218b088;

// USA: func_ov012_02185bf0  (semantic: DispatchElemHandlerAndApply_02185bf0)
extern "C" ARM void func_ov012_02185bf0(char* obj, int id, int flag) {
    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + kElemOffset), id);
    if (e == 0) return;

    unsigned char* c5p = (unsigned char*)e + 0xc5;
    if (flag) *c5p |= 0x40;
    else *c5p &= ~0x40;
    flag = 0;

    if (*c5p & 2) flag = 1;
    void* dest = *(void**)(obj + 0x1000 + kDestOffset);
    memset(dest, 0, kDestSize);

    struct Table02185bf0 table = data_ov012_0218b088;
    Handler02185bf0 none = data_020e6d5c;
    table.e[0] = none;
    table.e[15] = none;

    if (table.e[id] != 0)
        (((Obj02185bf0*)obj)->*table.e[id])(*(void**)(obj + 0x1000 + kDestOffset), flag);

#if defined(jpn)
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(obj + kElemOffset), id, *(int*)(obj + 0x1000 + kDestOffset), 0);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(obj + kElemOffset), id, *(int*)(obj + 0x1000 + kDestOffset), 0, 0);
#endif
}
