#include <globaldefs.h>

// USA: func_020b1ff8
extern "C" ARM void func_020b1ff8(unsigned short* dst, int cols, int rows, int rowPitch, unsigned int idx, unsigned int color) {
    unsigned short hi = (unsigned short)(color << 12);
    int col;
    int row = 0;
    if (rows > 0) {
        do {
            unsigned short* p = dst;
            col = 0;
            if (cols > 0) {
                do {
                    unsigned short v = (unsigned short)(idx | hi);
                    idx++;
                    *p++ = v;
                    col++;
                } while (col < cols);
            }
            row++;
            dst += rowPitch;
        } while (row < rows);
    }
}
