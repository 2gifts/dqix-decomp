#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
struct Elem0207f018 {
    void* firstBuffer;
    void* secondBuffer;
    short field_0x8;
    short field_0xa;
    short field_0xc;
    short field_0xe;
    short field_0x10;
    unsigned char kind:4;
    unsigned char flag:4;
    unsigned char firstCount, secondCount, field_0x15;
};
struct Arr0207f018;
struct Context0207ed48 { SafeAllocator* allocator; Arr0207f018* array; };
extern Context0207ed48 data_02108ed8;
extern "C" void _Z27AppendCappedElement0207f018P11Arr0207f018P12Elem0207f018(Arr0207f018*, Elem0207f018*);
// USA: func_0207ed48
extern "C" ARM int func_0207ed48(Script::Parameter* params) {
    Elem0207f018 elem;
    elem.firstBuffer = 0;
    elem.secondBuffer = 0;
    elem.field_0x8 = -1;
    elem.field_0xc = 0;
    elem.field_0xa = 0;
    elem.field_0x10 = 0;
    elem.field_0xe = 0;
    elem.kind = 0;
    elem.flag = 0;
    elem.firstCount = 0;
    elem.secondCount = 0;
    elem.field_0x15 = 0;
    elem.field_0x8 = params[0].ToInt();
    elem.field_0xa = params[1].ToInt();
    elem.field_0xc = params[2].ToInt();
    elem.field_0xe = params[3].ToInt();
    elem.field_0x10 = params[4].ToInt();
    elem.kind = params[5].ToInt();
    elem.flag = (unsigned char)params[6].ToInt() == 0;
    elem.firstCount = params[7].ToInt();
    elem.secondCount = params[8].ToInt();
    if (elem.firstCount) elem.firstBuffer = data_02108ed8.allocator->Allocate(elem.firstCount * 4);
    if (elem.secondCount) elem.secondBuffer = data_02108ed8.allocator->Allocate(elem.secondCount * 4);
    _Z27AppendCappedElement0207f018P11Arr0207f018P12Elem0207f018(data_02108ed8.array, &elem);
    return 1;
}
