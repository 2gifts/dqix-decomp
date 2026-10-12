#include <globaldefs.h>
#include <System/Cache.h>

struct WindowReference0204cb20 {
    char pad0[0x1c];
    unsigned char low : 4;
    unsigned char high : 4;
    inline int GetHigh() { int value = high; return value; }
};
struct Window0204cb20 {
    int field0;
    WindowReference0204cb20* reference;
    void* buffer;
    char pad0c[0xa0 - 0xc];
    int offset;
    int bufferSize;
    short width, height;
    short fieldAC, fieldAE;
    short x, y, fieldB4, lineHeight;
    char padB8[0xc7 - 0xb8];
    unsigned char font;
};
extern "C" void __clear(void*, unsigned int);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046608(void*, int, const char*, char*, int, int, int);
extern "C" int func_0204e3e0(Window0204cb20*, char*, int, int, int, int);
extern "C" void func_0204cd60(Window0204cb20*, char*, int, int);
extern "C" void func_02050100(Window0204cb20*, int);
typedef void (*WindowUpload0204cb20)(void*, int, unsigned int);
extern "C" WindowUpload0204cb20 _Z21GetTableEntry0204a5e4ii(int, int);

// USA: func_0204cb20
extern "C" ARM void func_0204cb20(Window0204cb20* self, const char* text, int mode, int font) {
    char formatted[0x800];
    short height;
    short y;
    short fieldB4;
    short lineHeight;
    short x;
    int limit;
    int bufferSize;
    short width;
    if (self->reference && self->buffer && text) {
        width = self->width;
        height = self->height;
        limit = (width << 3) - 4;
        x = self->x;
        y = self->y;
        if (mode) limit = 0x100;
        fieldB4 = self->fieldB4;
        lineHeight = self->lineHeight;
        bufferSize = self->bufferSize;
        __clear(formatted, sizeof(formatted));
        func_02046608(_Z26GetGlobalField0x1c020421a0v(), self->font, text, formatted, limit, x, font);
        int border = func_0204e3e0(self, formatted, 0, 0, mode, font);
        self->width = width;
        self->height = height;
        self->x = x;
        self->y = y;
        self->fieldB4 = fieldB4;
        self->lineHeight = lineHeight;
        self->bufferSize = bufferSize;
        func_0204cd60(self, formatted, border, font);
        func_02050100(self, 0);
        int high = self->reference->GetHigh();
        int low = self->reference->low;
        WindowUpload0204cb20 upload = _Z21GetTableEntry0204a5e4ii(low, high);
        CleanInvalidateCacheRange(self->buffer, self->bufferSize);
        upload(self->buffer, self->offset, self->bufferSize);
    }
}
