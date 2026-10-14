#include <globaldefs.h>

extern "C" int func_020d424c(int a, int b, int c);
extern "C" int func_020d40bc(int a, int b, const void* buf, unsigned int size,
                             unsigned short e0, unsigned short e1, unsigned short e2,
                             int f, int g);
void* GetBattleContext_020d41d8(void);
void InvalidateDataCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

struct Comm020d59bc {
    char pad0[0x7c];
    const void* field7c;
    char pad80[6];
    unsigned short field86;
    char pad88[0xfa];
    unsigned short field182;
    char pad184[4];
    unsigned short field188;
};

struct BattleContext020d59bc {
    char pad0[4];
    struct Comm020d59bc* field4;
};

// USA: func_020d59bc
#pragma optimize_for_size off
extern "C" ARM int func_020d59bc(int a, int b, const void* buf, unsigned int size,
                                 unsigned short e0, unsigned short e1, unsigned short e2) {
    int count = 1;
    struct Comm020d59bc* comm = ((struct BattleContext020d59bc*)GetBattleContext_020d41d8())->field4;
    int r = func_020d424c(2, 9, 0xa);
    if (r != 0) {
        return r;
    }
    InvalidateDataCacheRange(&comm->field188, 2);
    if (comm->field188 == 0) {
        InvalidateDataCacheRange(&comm->field182, 2);
        count = comm->field182;
        InvalidateDataCacheRange(&comm->field86, 2);
    }
    if (buf == 0) {
        return 6;
    }
    if (count == 0) {
        return 7;
    }
    InvalidateDataCacheRange(&comm->field7c, 2);
    if (buf == comm->field7c) {
        return 6;
    }
    if (size > 0x200) {
        return 6;
    }
    if (size == 0) {
        return 6;
    }
    CleanCacheRange(buf, size);
    r = func_020d40bc(0xf, 7, buf, size, e0, e1, e2, a, b);
    if (r == 0) {
        r = 2;
    }
    return r;
}
