#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe9f;

// USA: func_02041b34
ARM int AppendWidthHeightTag_02041b34(char* dst, int w, int h) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020efe9f, w, h)) - dst;
}
