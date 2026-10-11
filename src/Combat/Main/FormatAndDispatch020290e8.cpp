#include <globaldefs.h>
#if defined(jpn)
#define func_02029140 func_02028a20
#endif

typedef char* va_list;

extern "C" int func_02003c80(char* buf, int size, const char* fmt, va_list ap);
extern "C" void func_02029140(int a, int b, char* buf);

// USA: func_020290e8
ARM void FormatAndDispatch020290e8(int a, int b, const char* fmt, ...) {
    char buf[0x100];
    va_list ap = (va_list)(((unsigned int)&fmt & ~3u) + 4);
    func_02003c80(buf, 0x100, fmt, ap);
    buf[0xff] = 0;
    func_02029140(a, b, buf);
}
