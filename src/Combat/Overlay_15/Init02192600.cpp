#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

extern "C" void func_0207de48(void* dst, int a, int b);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);

extern AllocatorUnion data_02114e20;

struct RowEntry02192600 { int f0; int f1; int f2; int f3; };
struct RowTable02192600 { struct RowEntry02192600 rows[10]; };
extern struct RowTable02192600 data_ov015_02193e48;

struct Ptr8_02192600 { void* p; int pad4; };

struct Obj02192600 {
    char pad0[0xc4];
    struct Ptr8_02192600 arrC4[4];
    struct Ptr8_02192600 arrE4[4];
    struct Ptr8_02192600 arr104[4];
};

// USA: func_ov015_02192600
ARM void Init02192600(struct Obj02192600* obj) {
    struct RowTable02192600 local = data_ov015_02193e48;
    int k;
    for (k = 0; k < 4; k++) {
        obj->arrC4[k].p = AllocateAligned4_02012d88(&data_02114e20, 0x460);
        obj->arrE4[k].p = AllocateAligned4_02012d88(&data_02114e20, 0x460);
        obj->arr104[k].p = AllocateAligned4_02012d88(&data_02114e20, 0x70);
        int j;
        for (j = 0; j < 10; j++) {
            func_0207de48((char*)obj->arrC4[k].p + j * 0x70, local.rows[j].f0, local.rows[j].f1);
            func_0207de48((char*)obj->arrE4[k].p + j * 0x70, local.rows[j].f2, local.rows[j].f3);
        }
        func_0207de48(obj->arr104[k].p, 0x4000, 0x400);
    }
    func_0207de48((char*)obj + 0x124, 0x4000, 0x40);
}
