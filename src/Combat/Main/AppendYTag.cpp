#include <globaldefs.h>

#if defined(jpn)
#define data_020efe7f data_020efe87
#endif


int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe7f;

#if defined(jpn)
#define AppendYTag func_020420e8
extern "C" ARM int func_020420e8(char* dst, int y);
#endif

// USA: func_02041a5c
ARM int AppendYTag(char* dst, int y) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020efe7f, y)) - dst;
}
