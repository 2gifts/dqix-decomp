#include <globaldefs.h>

#if defined(jpn)
#define data_020efe98 data_020efea0
#endif


int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe98;

#if defined(jpn)
#define AppendHeightTag func_0204218c
extern "C" ARM int func_0204218c(char* dst, int h);
#endif

// USA: func_02041b00
ARM int AppendHeightTag(char* dst, int h) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020efe98, h)) - dst;
}
