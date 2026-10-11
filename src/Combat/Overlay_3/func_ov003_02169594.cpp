#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValueE8_E4 = 0xe4 };
enum { kRegionValue194_190 = 0x190 };
enum { kRegionValue188_184 = 0x184 };
enum { kRegionValue4ED_4E9 = 0x4e9 };
enum { kRegionValue195_191 = 0x191 };
#else
enum { kRegionValueE8_E4 = 0xe8 };
enum { kRegionValue194_190 = 0x194 };
enum { kRegionValue188_184 = 0x188 };
enum { kRegionValue4ED_4E9 = 0x4ed };
enum { kRegionValue195_191 = 0x195 };
#endif


struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205bcdc;

extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68* s, int a, int b, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* s, int val);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(struct Struct_0205bcdc* s, int index);
extern "C" void func_0205bb04(void* s, int n);

struct Grid02169594 {
    int field0;
    int field4;
    char pad8[0x3c - 0x8];
    unsigned char field3c;
    char pad3d[0x50 - 0x3d];
};

struct Ctx02169594 {
    char pad0[kRegionValueE8_E4];
    struct Grid02169594 grids[2];
    char pad188[kRegionValue194_190 - kRegionValue188_184];
    unsigned char layout;
    char pad195[kRegionValue4ED_4E9 - kRegionValue195_191];
    signed char indexA;
    signed char indexB;
};

static inline struct Grid02169594* GetGrid(struct Ctx02169594* ctx, int i) { return &ctx->grids[i]; }

// USA: func_ov003_02169594
// JPN: func_ov003_021693bc
extern "C" ARM void func_ov003_02169594(struct Ctx02169594* self) {
    int cols;
    int rows;
    int count;
    int field4;
    int index;

    switch (self->layout) {
    case 1:
        cols = 1;
        rows = 3;
        count = 3;
        field4 = 1;
        index = self->indexA;
        break;
    case 2:
        index = self->indexB;
        cols = 4;
        rows = 1;
        count = 4;
        field4 = 1;
        break;
    }

    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)GetGrid(self, 0), cols, rows, 0);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)GetGrid(self, 1), cols, rows, 0);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)GetGrid(self, 0), count);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)GetGrid(self, 1), count);
    GetGrid(self, 0)->field4 = field4;
    GetGrid(self, 1)->field4 = field4;
    _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((struct Struct_0205bcdc*)GetGrid(self, 0), index);
    func_0205bb04(GetGrid(self, 1), index);
    struct Grid02169594* grid = GetGrid(self, 1);
    grid->field3c = 0;
}
