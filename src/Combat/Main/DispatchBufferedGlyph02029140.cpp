#include <globaldefs.h>

#if defined(jpn)
#define func_02029140 func_02028a20
#endif

extern "C" void func_0204c684(void*);
extern "C" int func_0204f41c(void* target, int a, int b, void* c, int d, int e, void* f, void* g, int h);

extern void* data_020fe9a4;
extern unsigned char data_020e7380;

struct LocalCtx02029140 {
    char pad0[0x8];
    void* field8;
    char pad10[0xa8 - 0xc];
    unsigned short halfA8;
    unsigned short halfAA;
    char padAC[0xc5 - 0xac];
    unsigned char flagsC5;
    char padC6[0xe0 - 0xc6];
};

// USA: func_02029140  (semantic: DispatchBufferedGlyph02029140)
extern "C" ARM void func_02029140(int x, int y, void* ptr) {
    if (data_020fe9a4 == 0) return;
    if (x >= 0x100 || y >= 0xc0) return;
    if (ptr == 0) return;

    LocalCtx02029140 local;
    func_0204c684(&local);

    unsigned char raw = local.flagsC5;
    local.halfA8 = 0x20;
    local.halfAA = 0x18;
    unsigned char t = raw & ~4;
    local.field8 = data_020fe9a4;
    local.flagsC5 = t & ~0x10;

    int mode = *(((int*)&data_020fe9a4) + 1);
    unsigned char lookup = (&data_020e7380)[mode];

    short paramF;
    short paramG;
    func_0204f41c(&local, (short)x, (short)y, ptr, 8, lookup, &paramF, &paramG, 1);
}
