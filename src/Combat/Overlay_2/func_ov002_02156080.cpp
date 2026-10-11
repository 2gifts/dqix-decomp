#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" char *func_0205ec34(void);
extern "C" int func_ov002_02161920(void *self);
extern "C" int _Z18TestBitInByteArrayiPhi(char *unused, char *arr, int index);

struct List02156080 {
    short v[9];
};
extern "C" const struct List02156080 data_ov002_0216c9ae;

// USA: func_ov002_02156080
extern "C" ARM void func_ov002_02156080(void *self, short *out, short *outCount) {
    char *save               = func_0205ec34();
    int mode                 = func_ov002_02161920(self);
    struct List02156080 list = data_ov002_0216c9ae;
    short n                  = 0;
    for (short i = 0; i < 9; i++) {
        int ok = 1;
        switch (i) {
            case 2: ok = _Z18TestBitInByteArrayiPhi(save, save + 0x8c, 0x119c) != 0 ? 1 : 0; break;
            case 6: ok = 0; break;
            case 8:
                if (mode != 2) ok = 0;
                break;
        }
        if (ok) {
            list.v[n] = i;
            n++;
        }
    }
    memcpy(out, &list, 0x12);
    *outCount = n;
}
