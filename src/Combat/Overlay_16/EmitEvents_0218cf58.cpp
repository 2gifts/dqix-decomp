#include <globaldefs.h>

extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);
void CleanCacheRange(const void* addr, unsigned int size);
int EnqueueEvent0x1A(int a, int b);
void PostEvent0x0E(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
int EnqueueEvent0x12(int a, int b, int c, int d, int e);
int EnqueueEvent0x0C(int a, int b, int c, int d);
extern "C" void func_020d24c4(int);
extern "C" void _Z19IncCounter_0218cf34v(void);

struct StateBlock_0219d144 {
    #if defined(jpn)
    unsigned char pad[0x20];
#else
    unsigned char pad[0x24];
#endif
    int f24;
    unsigned char pad2[4];
    void* f2c;
};
extern StateBlock_0219d144 data_ov016_0219d144;

// USA: func_ov016_0218cf58  (semantic: EmitEvents_0218cf58)
extern "C" ARM void func_ov016_0218cf58(unsigned int id, unsigned int count) {
    unsigned int divResult = _u32_div_f(0x00ffb0ff, id);
    StateBlock_0219d144* g = &data_ov016_0219d144;

    unsigned int prodShifted = (g->f24 * count) << 1;
    unsigned int scaled = (count >> 6) * (divResult << 1);

    CleanCacheRange(g->f2c, prodShifted);
    EnqueueEvent0x1A(1, 0);

    PostEvent0x0E(0, 1, (int)g->f2c, 1,
        0, (g->f24 * count) >> 1, 0x7f, 0, divResult, 0x40);

    EnqueueEvent0x12(0, scaled, scaled, (int)_Z19IncCounter_0218cf34v, 0);
    EnqueueEvent0x0C(1, 0, 1, 0);
    func_020d24c4(1);
}
