#include <globaldefs.h>
#include "std_library_functions.h"
extern "C" void __clear(void*, int);
extern "C" int func_020420e8(char*, int);
struct TextSurface0208d42c;
extern "C" void func_0204f41c(TextSurface0208d42c*, short, short, char*, int, unsigned char, short*, short*, int);
extern char data_020f120d, data_020f1212, data_020f1217;
#if defined(jpn)
extern char data_020f12e0[], data_020f12e5[], data_020f129b[];
int StringLength(const char*);
extern "C" void func_02050678(TextSurface0208d42c*, short, short, const char*, int, unsigned char, short*, short*);
#endif

// USA: func_0208d42c
extern "C" ARM void func_0208d42c(void*, TextSurface0208d42c* surface, short x, short y, int value, unsigned char style, unsigned char mode, unsigned char rightAlign, unsigned char special) {
    if (surface) {
        char text[8];
        short width, height;
        short offset = 0;
        __clear(text, 8);
#if defined(jpn)
        if (special) {
            if (mode == 2) sprintf(text, data_020f12e0, value);
            else sprintf(text, data_020f12e5, value);
        } else sprintf(text, data_020f129b, value);
        int length = StringLength(text);
        if (rightAlign) offset = (mode - length) * 8;
        func_02050678(surface, x + offset, y, text, 8, style, &width, &height);
#else
        if (special) {
            if (mode == 2) sprintf(text, &data_020f120d, value);
            else sprintf(text, &data_020f1212, value);
        } else sprintf(text, &data_020f1217, value);
        if (rightAlign) offset = -func_020420e8(text, 0);
        func_0204f41c(surface, x + offset, y, text, 8, style, &width, &height, 0);
#endif
    }
}
