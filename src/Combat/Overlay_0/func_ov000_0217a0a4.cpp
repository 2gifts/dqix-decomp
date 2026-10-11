#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#define REGION_OFFSET_2 0x1faa
#define REGION_OFFSET_3 0x1fb1
#define REGION_OFFSET_4 0x1fac
#define REGION_OFFSET_5 0x1fb9
#define REGION_OFFSET_6 0x1fb2
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#define REGION_OFFSET_2 0x1d72
#define REGION_OFFSET_3 0x1d79
#define REGION_OFFSET_4 0x1d74
#define REGION_OFFSET_5 0x1d81
#define REGION_OFFSET_6 0x1d7a
#endif

#include "std_library_functions.h"

struct StructA0205d5d0;
struct Struct_0205def8;
struct Struct_0205d81c;

struct Elem_0205d81c {
    char pad0[0xc2];
    short fieldC2;
    unsigned char fieldC4;
    unsigned char fieldC5;
};

struct BattleField0217a0a4 {
    char pad0[0x188];
    char elements[REGION_OFFSET_2 - 0x188];
    unsigned short flags;
    char pad1D74[REGION_OFFSET_3 - REGION_OFFSET_4];
    unsigned char field1D79;
    char pad1D7A[REGION_OFFSET_5 - REGION_OFFSET_6];
    unsigned char field1D81;
};

extern "C" int _Z26GetGlobalField0x1c020421a0v();
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0*, int, int, int);
#else
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0*, int, int, int, unsigned char);
#endif
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8*, int, int);
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c*, int);
extern "C" void func_ov000_0217a2dc(struct BattleField0217a0a4*, int, void*);
extern "C" void func_ov000_0217a19c(struct BattleField0217a0a4*, int);

// USA: func_ov000_0217a0a4
extern "C" ARM void func_ov000_0217a0a4(struct BattleField0217a0a4* field) {
    void* buf = *(void**)(_Z26GetGlobalField0x1c020421a0v() + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_0217a2dc(field, 0, buf);
#if defined(jpn)
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)field->elements, 0x17, (int)buf, 1);
#else
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)field->elements, 0x17, (int)buf, 1, 0);
#endif
    if (field->field1D81) {
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)field->elements, 0, 0x18);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)field->elements, 0, 0x19);
        struct Elem_0205d81c* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)field->elements, 0x17);
        if (elem) {
            elem->fieldC5 &= ~0x40;
            elem->fieldC2 = 0;
        }
        field->flags &= ~0x100;
    }
    if (field->field1D79) {
        func_ov000_0217a19c(field, 0);
    } else {
        struct Elem_0205d81c* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)field->elements, 0x18);
        if (elem) {
            elem->fieldC2 = 0;
        }
        field->field1D79 = 1;
    }
}
