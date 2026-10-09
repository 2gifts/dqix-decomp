#include <globaldefs.h>

struct Font0218e17c {
    char pad0[4];
    unsigned short strideBits;
    char pad6[6];
    unsigned char* bitmap;
};

struct Glyph0218e17c {
    char pad0[4];
    signed char width;
    char pad5;
    short bitOffset;
};

extern "C" int _Z24GetWordFromTable02042638i(int idx);

// USA: func_ov016_0218e17c
extern "C" ARM void func_ov016_0218e17c(unsigned short* dst, int x, int y, struct Glyph0218e17c* glyph, unsigned short color, unsigned char fontId) {
    struct Font0218e17c* font = (struct Font0218e17c*)_Z24GetWordFromTable02042638i(fontId);
    short bitOffset = glyph->bitOffset;
    int stride = font->strideBits >> 3;
    signed char startBit = 7 - (bitOffset & 7);
    for (int row = 0; row < 12; row++) {
        signed char bit;
        unsigned char* src = font->bitmap + stride * row + (bitOffset >> 3);
        int line = (y + row) << 8;
        bit = startBit;
        for (int col = 0; col < glyph->width; col++) {
            if (*src & (1 << bit)) {
                (dst + line + x)[col] = color;
            }
            bit--;
            if (bit < 0) {
                bit = 7;
                src++;
            }
        }
    }
}
