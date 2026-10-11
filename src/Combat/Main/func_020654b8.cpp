#include <globaldefs.h>

extern "C" unsigned char* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_0204f41c(void* obj, int x, int y, void* str, int d, int e, short* outA, short* outB, int zero);

extern const short data_020e7e44[];
extern const short data_020e7e4c[];

// USA: func_020654b8
extern "C" ARM void func_020654b8(unsigned char* self, void* obj, void* p2, int x, short a4, unsigned char a5) {
    short v0;
    short v1;
    void* q;
    void* str;
    int y;
    unsigned char g;
    q = *(void**)((char*)p2 + 0x18);
    if (q == 0) return;
    str = *(void**)q;
    y = (short)(a4 - (short)(*(short*)((char*)(*(void**)((char*)self + 0x34)) + 0xae) * 8));
    g = ((unsigned char*)_Z26GetGlobalField0x1c020421a0v() + 0x1000)[0x95b];
    if (g & 0x80) {
        for (unsigned char i = 0; i < 4; i++) {
            func_0204f41c(obj, (short)(x + data_020e7e4c[i]), (short)(y + data_020e7e44[i]), str, 10, 1, &v0, &v1,
                          (self + 0x1000)[0x9dc]);
        }
        func_0204f41c(obj, (short)(x + 1), (short)(y + 1), str, 10, a5, &v0, &v1, (self + 0x1000)[0x9dc]);
    } else if (g & 2) {
        func_0204f41c(obj, (short)(x + 1), (short)(y + 1), str, 10, 1, &v0, &v1, (self + 0x1000)[0x9dc]);
        func_0204f41c(obj, (short)x, (short)y, str, 10, a5, &v0, &v1, (self + 0x1000)[0x9dc]);
    } else {
        func_0204f41c(obj, x, y, str, 10, a5, &v0, &v1, (self + 0x1000)[0x9dc]);
    }
}
