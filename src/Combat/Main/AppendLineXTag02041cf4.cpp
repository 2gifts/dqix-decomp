#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020eff1b[];

// USA: func_02041cf4
ARM int AppendLineXTag02041cf4(char* dst, int a1, int a2, int a3, int a4) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, data_020eff1b, a1, a2, a3, a4)) - dst;
}
