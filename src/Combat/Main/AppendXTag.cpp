#include <globaldefs.h>

#if defined(jpn)
#define data_020efe78 data_020efe80
#endif

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe78;

// USA: func_02041a28
ARM int AppendXTag_02041a28(char* dst, int x) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020efe78, x)) - dst;
}
