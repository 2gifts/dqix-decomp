#include <globaldefs.h>
#include "System/Cache.h"

// USA: func_0203b97c
extern "C" ARM void func_0203b97c(void*, unsigned short* destination, int width, int height, int startX, int startY, const unsigned short* source, unsigned int copyWidth, unsigned int copyHeight, unsigned short adjustment) {
    int blockRow;
    unsigned int blockColumns;
    int y;
    if (width <= startX || height <= startY) return;
    blockColumns = (unsigned int)width >> 5;
    for (unsigned int row = 0; row < copyHeight; row++) {
        y = startY + row;
        for (unsigned int column = 0; column < copyWidth; column++) {
            blockRow = (y / 32) * blockColumns;
            int x = startX + column;
            if (x >= 0 && y >= 0 && width > x && height > y) {
                int block = blockRow + x / 32;
                unsigned int offset = x + (y << 5) + block * 0x3e0;
                unsigned short value = source[column + row * copyWidth];
                destination[offset] = value;
                destination[offset] += adjustment;
            }
        }
    }
    CleanInvalidateCacheRange(destination, height * (width << 1));
}
