#include <globaldefs.h>

extern "C" ARM double func_0200ab28(double a, double b);
extern "C" ARM double func_0200b608(double a, double b);
extern "C" ARM double _ddiv(double a, double b);
extern "C" ARM double func_02008f3c(double x);
extern "C" ARM double func_02008848(double x);

// USA: func_02005ac4
#pragma optimize_for_size off
extern "C" ARM double func_02005ac4(double y, double x) {
    int hx = ((int*)&x)[1];
    int hy = ((int*)&y)[1];
    int iy = hy & 0x7fffffff;
    unsigned lx = ((unsigned*)&x)[0];
    int ix = hx & 0x7fffffff;
    unsigned ly = ((int*)&y)[0];

    if (((ix | ((lx | -lx) >> 31)) > 0x7ff00000) ||
        ((iy | ((ly | -ly) >> 31)) > 0x7ff00000)) {
        return func_0200ab28(x, y);
    }
    if (((hx - 0x3ff00000) | (int)lx) == 0) return func_02008848(y);

    int m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

    if ((iy | ly) == 0) {
        switch (m) {
            case 0:
            case 1: return y;
            case 2: return 3.1415926535897931160e+00 + 1.0e-300;
            case 3: return -3.1415926535897931160e+00 - 1.0e-300;
        }
    }
    if ((ix | lx) == 0) {
        return (hy < 0) ? -1.5707963267948965580e+00 - 1.0e-300
                         : 1.5707963267948965580e+00 + 1.0e-300;
    }

    if (ix == 0x7ff00000) {
        if (iy == 0x7ff00000) {
            switch (m) {
                case 0: return 7.8539816339744827900e-01 + 1.0e-300;
                case 1: return -7.8539816339744827900e-01 - 1.0e-300;
                case 2: return 3.0 * 7.8539816339744827900e-01 + 1.0e-300;
                case 3: return -3.0 * 7.8539816339744827900e-01 - 1.0e-300;
            }
        } else {
            switch (m) {
                case 0: return 0.0;
                case 1: return -0.0;
                case 2: return 3.1415926535897931160e+00 + 1.0e-300;
                case 3: return -3.1415926535897931160e+00 - 1.0e-300;
            }
        }
    }
    if (iy == 0x7ff00000) {
        return (hy < 0) ? -1.5707963267948965580e+00 - 1.0e-300
                         : 1.5707963267948965580e+00 + 1.0e-300;
    }

    int k = (iy - ix) >> 20;
    double z;
    if (k > 60) {
        z = 1.5707963267948965580e+00 + 0.5 * 1.2246467991473531772e-16;
    } else if (hx < 0 && k < -60) {
        z = 0.0;
    } else {
        z = func_02008848(func_02008f3c(_ddiv(y, x)));
    }

    switch (m) {
        case 0: return z;
        case 1: {
            int *hzp = (int*)&z + 1;
            *hzp = *hzp ^ 0x80000000;
            return z;
        }
        case 2: return func_0200b608(3.1415926535897931160e+00,
                                      func_0200b608(z, 1.2246467991473531772e-16));
        default: return func_0200b608(func_0200b608(z, 1.2246467991473531772e-16),
                                       3.1415926535897931160e+00);
    }
}
#pragma optimize_for_size reset
