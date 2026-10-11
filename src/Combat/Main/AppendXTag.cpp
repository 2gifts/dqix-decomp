#include <globaldefs.h>

#if defined(jpn)
#define data_020efe78 data_020efe80
#endif

int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe78;

// USA: func_02041a28
ARM int AppendXTag(char* dst, int x) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020efe78, x)) - dst;
}
