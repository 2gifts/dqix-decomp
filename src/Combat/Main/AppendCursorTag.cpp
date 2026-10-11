#include <globaldefs.h>

#if defined(jpn)
#define data_020eff87 data_020eff86
#endif

extern char data_020eff87;
int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041ea4
ARM int AppendCursorTag(char* dst, int cursor) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020eff87, cursor)) - dst;
}
