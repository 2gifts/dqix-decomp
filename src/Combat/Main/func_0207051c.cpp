#include <globaldefs.h>

void WriteReg040004A40207076c(int a1, int a2, int a3, int a4, int a5, int a6);
void WriteReg0400048C02070798(int a1, int a2, int a3);

struct Block02051c {
    int v[12];
};

extern struct Block02051c data_020e8804;

// USA: func_0207051c
extern "C" ARM void func_0207051c(int unused, int a2, int a3) {
    struct Block02051c b = data_020e8804;

    *(volatile int*)0x40004a8 = 0x900000;
    WriteReg040004A40207076c(0, 0, 3, 0x3a, a3, 0x8000);

    *(volatile int*)0x4000444 = 0;
    *(volatile int*)0x400046c = 0x100000;
    *(volatile int*)0x400046c = 0xc0000;
    *(volatile int*)0x400046c = 0;
    *(volatile int*)0x4000500 = 1;
    *(volatile int*)0x4000480 = a2;

    WriteReg0400048C02070798((short)b.v[0], (short)b.v[1], (short)b.v[2]);
    WriteReg0400048C02070798((short)b.v[3], (short)b.v[4], (short)b.v[5]);
    WriteReg0400048C02070798((short)b.v[6], (short)b.v[7], (short)b.v[8]);
    WriteReg0400048C02070798((short)b.v[9], (short)b.v[10], (short)b.v[11]);

    *(volatile int*)0x4000504 = 0;
    *(volatile int*)0x4000448 = 1;

    if (a3 != 0x1f) return;

    WriteReg040004A40207076c(0, 0, 3, 0x3a, 0, 0x8000);

    *(volatile int*)0x4000444 = 0;
    *(volatile int*)0x400046c = 0x100000;
    *(volatile int*)0x400046c = 0xc0000;
    *(volatile int*)0x400046c = 0;
    *(volatile int*)0x4000500 = 1;
    *(volatile int*)0x4000480 = a2;

    WriteReg0400048C02070798(b.v[0] << 16 >> 16, b.v[1] << 16 >> 16, b.v[2] << 16 >> 16);
    WriteReg0400048C02070798(b.v[3] << 16 >> 16, b.v[4] << 16 >> 16, b.v[5] << 16 >> 16);
    WriteReg0400048C02070798(b.v[6] << 16 >> 16, b.v[7] << 16 >> 16, b.v[8] << 16 >> 16);
    WriteReg0400048C02070798(b.v[9] << 16 >> 16, b.v[10] << 16 >> 16, b.v[11] << 16 >> 16);

    *(volatile int*)0x4000504 = 0;
    *(volatile int*)0x4000448 = 1;
}
