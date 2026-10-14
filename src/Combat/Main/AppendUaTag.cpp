#include <globaldefs.h>

extern char data_020eff93;
int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041ed8
ARM int AppendUaTag_02041ed8(char* dst, int a, int b, int c) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020eff93, a, b, c)) - dst;
}
