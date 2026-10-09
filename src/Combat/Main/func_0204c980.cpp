#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Cache.h"

struct WindowStyle0204c980 {
    char padding[0x1c];
    unsigned char uploadIndex : 4;
    unsigned char uploadBank : 4;
};

struct Window0204c980 {
    int field_0;
    WindowStyle0204c980* style;
    void* pixels;
    short regions[4][18];
    int dirty;
    unsigned int destination;
    unsigned int pixelBytes;
    short width;
    short height;
    short field_ac;
    short field_ae;
    short textX;
    char padding_b2[0xe];
    short cursorX;
    short cursorY;
    unsigned char field_c4;
    unsigned char flags;
    unsigned char field_c6;
    unsigned char fontHeight;
    short mapWidth;
    short mapHeight;
    int field_cc;
    int mapBytes;
    void* tileMap;
};

extern "C" void _Z24ClearFourRegions0204f0ecPc(char*);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z21GetTableEntry0204a5e4ii(int, int);
extern "C" void func_02046608(void*, unsigned char, const char*, char*, int, int, unsigned char);
extern "C" short func_0204e3e0(Window0204c980*, char*, int, unsigned char, unsigned char, unsigned char);
extern "C" void func_0204cd60(Window0204c980*, char*, short, short);
typedef void (*Upload0204c980)(const void*, unsigned int, unsigned int);

inline int GetUpload0204c980(int bank, int index) {
    int handler = _Z21GetTableEntry0204a5e4ii(index, bank);
    return handler;
}

inline int ReaduploadBank0204c980(WindowStyle0204c980* style) {
    int value = style->uploadBank;
    return value;
}

// USA: func_0204c980
extern "C" ARM void func_0204c980(Window0204c980* window, const char* text, unsigned int destination, int mode, unsigned char border, unsigned char fullWidth, unsigned char font) {
    if (window->style && window->pixels && text) {
        _Z24ClearFourRegions0204f0ecPc((char*)window);
        int width = window->width * 8;
        if (!(window->flags & 0x10)) width -= 4;
        if (fullWidth) width = 256;
        char buffer[0x800] = {};
        func_02046608(_Z26GetGlobalField0x1c020421a0v(), window->fontHeight, text, buffer, width, window->textX, font);
        short padding = func_0204e3e0(window, buffer, mode, border, fullWidth, font);
        func_0204cd60(window, buffer, padding, font);
        window->destination = destination;
        Upload0204c980 upload = (Upload0204c980)GetUpload0204c980(ReaduploadBank0204c980(window->style), window->style->uploadIndex);
        CleanInvalidateCacheRange(window->pixels, window->pixelBytes);
        upload(window->pixels, window->destination, window->pixelBytes);
        if (window->flags & 1) {
            window->cursorX = 0;
            short height = window->height;
            short width = window->width;
            int length = width * height * 2;
            window->mapWidth = width;
            window->mapHeight = height;
            window->mapBytes = length;
            window->cursorY = 0;
            window->dirty = 1;
        } else {
            window->flags |= 1;
            window->cursorX = 0;
            int length = window->width * window->height * 2;
            memset(window->tileMap, 0, length);
            short height = window->height;
            short width = window->width;
            window->mapWidth = width;
            window->mapHeight = height;
            window->mapBytes = length;
            window->cursorY = 0;
            window->dirty = 1;
        }
    }
}
