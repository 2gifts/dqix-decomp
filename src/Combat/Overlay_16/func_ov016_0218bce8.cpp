#include <globaldefs.h>

extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);
void CleanCacheRange(const void* addr, unsigned int size);
int EnqueueEvent0x1A_020d1fb0(int a, int b);
void PostEvent0x0E_020d2038(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
int EnqueueEvent0x12_020d1f70(int a, int b, int c, int d, int e);
int EnqueueEvent0x0C_020d1ee4(int a, int b, int c, int d);
extern "C" void func_020d24c4(int);
void IncCounter_0218bcc4(void);

struct StateBlock_0219d0c0 {
    #if defined(jpn)
    unsigned char pad[0x20];
#else
    unsigned char pad[0x24];
#endif
    int f24;
    unsigned char pad2[4];
    void* f2c;
    void* f30;
};
extern StateBlock_0219d0c0 data_ov016_0219d0c0;

// USA: func_ov016_0218bce8
extern "C" ARM void func_ov016_0218bce8(unsigned int id, unsigned int count) {
    unsigned int divResult = _u32_div_f(0x00ffb0ff, id);
    StateBlock_0219d0c0* g = &data_ov016_0219d0c0;

    unsigned int prodShifted = (g->f24 * count) << 1;
    unsigned int scaled = (count >> 6) * (divResult << 1);

    CleanCacheRange(g->f30, prodShifted);
    CleanCacheRange(g->f2c, (g->f24 * count) << 1);
    EnqueueEvent0x1A_020d1fb0(3, 0);

    PostEvent0x0E_020d2038(0, 1, (int)g->f30, 1,
        0, (g->f24 * count) >> 1, 0x7f, 0, divResult, 0);

    PostEvent0x0E_020d2038(1, 1, (int)g->f2c, 1,
        0, (g->f24 * count) >> 1, 0x7f, 0, divResult, 0x7f);

    EnqueueEvent0x12_020d1f70(0, scaled, scaled, (int)IncCounter_0218bcc4, 0);
    EnqueueEvent0x0C_020d1ee4(3, 0, 1, 0);
    func_020d24c4(1);
}
