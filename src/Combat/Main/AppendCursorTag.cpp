#include <globaldefs.h>

#if defined(jpn)
#define data_020eff87 data_020eff86
#endif

extern char data_020eff87;
int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041ea4
ARM int AppendCursorTag_02041ea4(char* dst, int cursor) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020eff87, cursor)) - dst;
}
