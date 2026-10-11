#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue4EF_4EB = 0x4eb };
enum { kRegionValue4FC_4F8 = 0x4f8 };
enum { kRegionValue4F7_4F3 = 0x4f3 };
#else
enum { kRegionValue4EF_4EB = 0x4ef };
enum { kRegionValue4FC_4F8 = 0x4fc };
enum { kRegionValue4F7_4F3 = 0x4f7 };
#endif


struct Struct_0205bef8;
extern "C" void _Z12Init0205bef8P15Struct_0205bef8(struct Struct_0205bef8* s);

struct Struct_0205ba68;
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* s, int val);

extern "C" void func_0205bb04(void* s, int n);

struct PointerTable021696f4 {
    int field0;
    int field4;
};

struct Ctx021696f4 {
    char pad0[kRegionValue4EF_4EB];
    signed char values[4];
    signed char limits[4];
    char pad4f7[kRegionValue4FC_4F8 - kRegionValue4F7_4F3];
    struct PointerTable021696f4 table;
};

// USA: func_ov003_021696f4
// JPN: func_ov003_0216951c
extern "C" ARM void func_ov003_021696f4(struct Ctx021696f4* self, int index) {
    int base = self->values[index];
    int isLast = 0;
    for (int i = 0; i < index; i++) {
        if (self->values[i] < self->limits[i]) break;
        if (i == index - 1) isLast = 1;
    }
    if (index == 0) isLast = 1;

    int first = 3;
    for (int i = 0; i < 4; i++) {
        if (self->limits[i] > 0) {
            first = i;
            break;
        }
    }
    if (index <= first) isLast = 0;

    _Z12Init0205bef8P15Struct_0205bef8((struct Struct_0205bef8*)&self->table);
    if (isLast) {
        int limit = self->limits[index];
        _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)&self->table, 1, limit + 1, 0);
        self->table.field4 = 1;
        _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)&self->table, limit + 1);
        func_0205bb04(&self->table, limit - base);
    } else {
        _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)&self->table, 1, 10, 0);
        self->table.field4 = 1;
        _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)&self->table, 10);
        func_0205bb04(&self->table, 9 - base);
    }
}
