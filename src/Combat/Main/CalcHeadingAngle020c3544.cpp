#include <globaldefs.h>

extern "C" int fix32_Divide(unsigned int numerHi, unsigned int denomLo);
extern short data_020ed554[];

// USA: func_020c3544
#pragma optimize_for_size off
extern "C" ARM int fix32_Atan2_Rescaled_020c3544(int dx, int dy) {
    int num, denom, base, add;

    if (dx > 0) {
        if (dy > 0) {
            if (dy > dx) {
                num = dx; denom = dy; base = 0; add = 1;
            } else {
                if (dy < dx) {
                    num = dy; denom = dx; base = 0x4000; add = 0;
                } else {
                    return 0x2000;
                }
            }
        } else {
            if (dy < 0) {
                int ady = -dy;
                if (ady < dx) {
                    num = ady; denom = dx; base = 0x4000; add = 1;
                } else {
                    if (ady > dx) {
                        num = dx; denom = ady; base = 0x8000; add = 0;
                    } else {
                        return 0x6000;
                    }
                }
            } else {
                return 0x4000;
            }
        }
    } else {
        if (dx < 0) {
            int adx = -dx;
            if (dy < 0) {
                int ady = -dy;
                if (ady > adx) {
                    num = adx; denom = ady; base = -0x8000; add = 1;
                } else {
                    if (ady < adx) {
                        num = ady; denom = adx; base = -0x4000; add = 0;
                    } else {
                        return 0xa000;
                    }
                }
            } else {
                if (dy > 0) {
                    if (dy < adx) {
                        num = dy; denom = adx; base = -0x4000; add = 1;
                    } else {
                        if (dy > adx) {
                            num = adx; denom = dy; base = 0; add = 0;
                        } else {
                            return 0xe000;
                        }
                    }
                } else {
                    return 0xc000;
                }
            }
        } else {
            return (dy >= 0) ? 0 : 0x8000;
        }
    }

    if (denom == 0) {
        return 0;
    }
    if (add) {
        int val = data_020ed554[fix32_Divide(num, denom) >> 5];
        return (unsigned short)(base + val);
    } else {
        int val = data_020ed554[fix32_Divide(num, denom) >> 5];
        return (unsigned short)(base - val);
    }
}
