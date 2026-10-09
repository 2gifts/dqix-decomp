#include <globaldefs.h>

struct LayoutTable0217fa14 {
    signed char indices[4];
    int labelY[2];
};

extern struct LayoutTable0217fa14 data_ov003_0217fa14;

extern "C" int func_020420e8(char* label, int extra);
extern "C" void func_0204f41c(void* obj, short x, short y, void* str, int d, int e, short* outA, short* outB, int zero);

// USA: func_ov003_02172618
extern "C" ARM void func_ov003_02172618(void* canvas, int y, char** labels) {
    short outA;
    short outB;
    int ys[2] = {data_ov003_0217fa14.labelY[0], y + 0x16};
    for (int i = 0; i < 2; i++) {
        char* label = labels[i];
        if (label == NULL) {
            continue;
        }
        int x = (0x100 - func_020420e8(label, 1)) >> 1;
        int ly = ys[i];
        func_0204f41c(canvas, x + 1, ly, label, 0xc, 0xe, &outA, &outB, 0);
        func_0204f41c(canvas, x, ly, label, 0xc, 0xf, &outA, &outB, 0);
    }
}
