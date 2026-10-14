#include <globaldefs.h>

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char*, int*, int*);
extern "C" int func_ov023_021e2c38(void* obj, int candidate);
extern "C" void* func_ov023_021e2418(void* obj, int candidate);
struct Obj021e2b5c;
extern "C" void func_ov023_021e2b5c(struct Obj021e2b5c* obj, int key, short* out1, short* out2);

// USA: func_ov023_021e29d0
extern "C" ARM int func_ov023_021e29d0(char* obj) {
    if (*((unsigned char*)&data_02114e54 + 0x55) == 0) return -1;

    int outX, outY;
    SelectCoordsByFlag0x24_02012a84(&data_02114e54, &outX, &outY);

    unsigned short count = *(unsigned short*)(obj + 0x14);
    char* arr = *(char**)(obj + 8);
    unsigned short i;
    for (i = 0; i < count; i++) {
        short candidate = *(short*)(arr + i * 0x18);
        if (!func_ov023_021e2c38(obj, candidate)) continue;

        candidate = *(short*)(arr + i * 0x18);
        void* e = func_ov023_021e2418(obj, candidate);
        if (e == 0 || *((unsigned char*)e + 2) == 0) continue;

        short val = *(short*)e;
        short a, b;
        func_ov023_021e2b5c((struct Obj021e2b5c*)obj, val, &a, &b);
        short eb = *(short*)((char*)e + 8);
        short ec = *(short*)((char*)e + 0xa);
        short sumA = a + eb;
        short sumB = b + ec;
        if (b > outY) continue;
        if (outY >= sumB) continue;
        if (a > outX) continue;
        if (outX < sumA) {
            return *(short*)(arr + i * 0x18);
        }
    }
    return -1;
}
