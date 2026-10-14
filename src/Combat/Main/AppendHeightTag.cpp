#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe98;

// USA: func_02041b00
ARM int AppendHeightTag_02041b00(char* dst, int h) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020efe98, h)) - dst;
}
