#include <globaldefs.h>

struct TileSource0204b620 {
    short width;
    short height;
    char pad_4[8];
    unsigned short* tiles;
};

// USA: func_0204b620
extern "C" ARM void func_0204b620(void* unused, unsigned short* destination, TileSource0204b620* source,
    short sourceX, short sourceY, short destX, short destY, short width, short height, unsigned short palette) {
    if (!destination || !source) return;
    if (destX >= 32 || destY >= 25) return;
    if (destX + width <= 0 || destY + height <= 0) return;
    if (width <= 0 || height <= 0) return;
    short sourceWidth = source->width;
    short sourceHeight = source->height;
    if (sourceWidth <= sourceX || sourceHeight <= sourceY || sourceX + width <= 0 || sourceY + height <= 0) return;
    if (sourceX < 0) {
        destX = (short)(destX - sourceX);
        width = (short)(width + sourceX);
        sourceX = 0;
    } else if (sourceWidth < sourceX + width) width = (short)(sourceWidth - sourceX);
    if (sourceY < 0) {
        destY = (short)(destY - sourceY);
        height += sourceY;
        sourceY = 0;
    } else if (sourceHeight < sourceY + height) height = (short)(sourceHeight - sourceY);
    if (sourceWidth < width) width = sourceWidth;
    if (sourceHeight < height) height = sourceHeight;
    if (destX < 0) {
        sourceX = (short)(sourceX - destX);
        width = (short)(width + destX);
        destX = 0;
    } else if (destX + width > 32) width = (short)(32 - destX);
    if (destY < 0) {
        sourceY = (short)(sourceY - destY);
        height = (short)(height + destY);
        destY = 0;
    } else if (destY + height > 25) height = (short)(25 - destY);
    unsigned short* input = source->tiles;
    if (!input) return;
    input += sourceWidth * sourceY + sourceX;
    unsigned short* output = destination + destY * 32 + destX;
    if (palette != 0xffff) {
        for (unsigned short row = 0; row < height; row++) {
            for (unsigned short column = 0; column < width; column++) {
                output[column] = input[column] & 0xfff;
                output[column] |= (unsigned short)(palette << 12);
            }
            input += sourceWidth;
            output += 32;
        }
    } else {
        for (unsigned short row = 0; row < height; row++) {
            for (unsigned short column = 0; column < width; column++) output[column] = input[column];
            input += sourceWidth;
            output += 32;
        }
    }
}
