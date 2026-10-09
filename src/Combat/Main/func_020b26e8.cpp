#include <globaldefs.h>

struct TextMeasurer020b0fac {
    void* field0;
    int (*getChar)(const char** cursor);
};
struct TextContext020b26e8 {
    int field_0x0;
    TextMeasurer020b0fac* measurer;
    int field_0x8;
    int lineSpacing;
};
struct TextDirection020b26e8 { signed char x, y; };
extern "C" int _Z22CountTextLines020b0facP20TextMeasurer020b0faciPKc(TextMeasurer020b0fac*, int, const char*);
extern "C" void func_020b245c(TextContext020b26e8*, int, int, int, int, int, const char*, TextDirection020b26e8);

// USA: func_020b26e8
extern "C" ARM void func_020b26e8(TextContext020b26e8* obj, int x, int y, int arg3, int available, int arg5, int flags, const char* text, TextDirection020b26e8 direction) {
    if (flags & 0x100) {
        int lines = _Z22CountTextLines020b0facP20TextMeasurer020b0faciPKc(obj->measurer, obj->lineSpacing, text);
        int offset = available - lines;
        x += offset * -direction.y;
        y += offset * direction.x;
    } else if (flags & 0x80) {
        int lines = _Z22CountTextLines020b0facP20TextMeasurer020b0faciPKc(obj->measurer, obj->lineSpacing, text);
        int offset = (available + 1) / 2 - (lines + 1) / 2;
        x += offset * -direction.y;
        y += offset * direction.x;
    }
    func_020b245c(obj, x, y, arg3, arg5, flags, text, direction);
}
