#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov023_021e7cec(void* obj, int a, int b, int c);
#if defined(jpn)
extern "C" void func_0205d304(void* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void func_0205d304(void* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif


struct Container021e8cc0;
extern "C" void _Z30CallAppendStringIfSet_021e8cc0P17Container021e8cc0(struct Container021e8cc0* obj);
extern "C" void func_ov023_021e8cdc(void* obj);
extern "C" void func_ov023_021e8e34(void* obj);
extern "C" void _Z34AppendEntryByKey_021e8ef8_021e8ef8Pv(void* obj);

struct Struct_0205d81c;
void SetElementFieldC2(struct Struct_0205d81c* s, int key, int value);

struct Obj021e802c {
    char pad[0x5d8];
    void* field5d8;
};

// JPN: func_ov023_021e81f4
// USA: func_ov023_021e802c
extern "C" ARM void func_ov023_021e802c(struct Obj021e802c* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x800};
#else
 enum {regionalOffset0=0x960};
#endif
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)((char*)obj + 0x78), 1);
    func_ov023_021e7cec(obj, 0xc, 0, 5);
    memset(obj->field5d8, 0, regionalOffset0);
    _Z30CallAppendStringIfSet_021e8cc0P17Container021e8cc0((struct Container021e8cc0*)obj);
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 1, 0);
#else
    func_0205d304((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 0, 0, 1);
#endif

#endif


    func_ov023_021e7cec(obj, 0xd, 0, 0x10);
    memset(obj->field5d8, 0, regionalOffset0);
    func_ov023_021e8cdc(obj);
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 1, 0);
#else
    func_0205d304((char*)obj + 0x78, obj->field5d8, 0, 0, 0, 0, 0, 1);
#endif

#endif


    func_ov023_021e7cec(obj, 0xe, 0, 2);
    memset(obj->field5d8, 0, regionalOffset0);
    func_ov023_021e8e34(obj);
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0);
#else
    func_0205d304((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0, 0);
#endif

#endif


    func_ov023_021e7cec(obj, 0xf, 0, 0xd);
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0);
#else
    func_0205d304((char*)obj + 0x78, obj->field5d8, 1, 0, 0, 1, 0, 0);
#endif

#endif


    func_ov023_021e7cec(obj, 0x10, 0xf, 0xd);
    memset(obj->field5d8, 0, regionalOffset0);
    _Z34AppendEntryByKey_021e8ef8_021e8ef8Pv(obj);
#if defined(jpn)
    func_0205d304((char*)obj + 0x78, obj->field5d8, 1, 1, 0, 1, 0);
#else
    func_0205d304((char*)obj + 0x78, obj->field5d8, 1, 1, 0, 1, 0, 1);
#endif


    for (int i = 0; i < 5; i++) {
        SetElementFieldC2((struct Struct_0205d81c*)((char*)obj + 0x78), (unsigned char)(i + 0xc), 0);
    }
}
