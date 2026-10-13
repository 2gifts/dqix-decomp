#include <globaldefs.h>
#include <System/Cache.h>
#include <std_library_functions.h>

struct WindowReference02050100 {
    char padding[0x1c];
    unsigned char low : 4;
    unsigned char high : 4;
};
struct Window02050100 {
    int field_0;
    WindowReference02050100* reference;
    char* buffer;
    char padding_0c[0xa0 - 0xc];
    int offset;
    int bufferSize;
    short width, height;
    char padding_ac[0xc5 - 0xac];
    unsigned char options;
    char padding_c6[0xd8 - 0xc6];
    unsigned char enabled : 1;
    unsigned char dirty : 1;
    unsigned char unused : 6;
    unsigned char currentValue;
    unsigned char lastValue;
};
struct Glyph02050100 { int field_0; signed char width; };
Glyph02050100* FindEntryByKey0204254c(int, int);
extern char data_020e7bda[];
extern "C" char* func_02050064(Window02050100*);
extern "C" void func_0204f41c(Window02050100*, short, short, char*, int, int, short*, short*, int);
extern "C" void func_0204f914(Window02050100*, int, short, short, short, short);
extern "C" void func_0204f7e8(Window02050100*, short, short, int, unsigned char, unsigned char, short*, short*, unsigned char, unsigned char, unsigned char, unsigned char);
typedef void (*WindowUpload02050100)(void*, int, unsigned int);
WindowUpload02050100 GetTableEntry0204a5e4(int, int);

// USA: func_02050100
extern "C" ARM void func_02050100(Window02050100* self, int upload) {
    if (!self->enabled) return;
    if (!self->dirty && upload) return;
    if (!self->reference || !self->buffer) return;
    int low = self->reference->low;
    int high = self->reference->high;
    if (upload) {
        char* source = func_02050064(self);
        if (!source) return;
        if (source) memcpy(self->buffer, source + self->offset, self->bufferSize);
    }
    short y = (short)((short)(self->height << 3) - 13);
    short center = (short)((short)(self->width << 3) / 2);
    if (self->options & 0x10) y -= 3;
    short outWidth = 0, outHeight = 0;
    short left;
    int style;
    int glyphWidth;
    signed char counter = (signed char)self->lastValue;
    int digits = 2;
    while (counter != 0) { counter = (signed char)(counter + 1) / 10; }
    if (counter > 2) digits = counter;
    style = 1;
    if (self->options & 4) style = 0;
    glyphWidth = 0;
    Glyph02050100* glyph = FindEntryByKey0204254c((int)data_020e7bda, glyphWidth);
    if (glyph) glyphWidth = glyph->width;
    short labelX = center - (glyphWidth >> 1);
    func_0204f41c(self, labelX, y, data_020e7bda, 8, 15, &outWidth, &outHeight, 0);
    left = center - glyphWidth;
    int bottom = y + 9;
    func_0204f914(self, style, left - 14, y, left, bottom);
    unsigned char displayDigits = digits;
    func_0204f7e8(self, left, y, self->currentValue + 1, 8, 15, &outWidth, &outHeight, 1, displayDigits, 0, 0);
    short right = center + glyphWidth;
    func_0204f914(self, style, right, y, right + 14, bottom);
    func_0204f7e8(self, right + 1, y, self->lastValue, 8, 15, &outWidth, &outHeight, 0, displayDigits, 0, 0);
    if (upload) {
        WindowUpload02050100 uploader = GetTableEntry0204a5e4(low, high);
        CleanInvalidateCacheRange(self->buffer, self->bufferSize);
        uploader(self->buffer, self->offset, self->bufferSize);
    }
    self->dirty = 0;
}
