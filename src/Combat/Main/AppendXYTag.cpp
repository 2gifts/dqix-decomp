#include <globaldefs.h>

#if defined(jpn)
#define data_020efe86 data_020efe8e
#endif

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe86;

// USA: func_02041a90
ARM int AppendXYTag_02041a90(char* dst, int x, int y) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020efe86, x, y)) - dst;
}
