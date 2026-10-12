#include <globaldefs.h>

#if defined(jpn)
#define data_020eff1b data_020eff23
#endif


int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020eff1b[];

#if defined(jpn)
#define AppendLineXTag02041cf4 func_02042380
extern "C" ARM int func_02042380(char* dst, int a1, int a2, int a3, int a4);
#endif

// USA: func_02041cf4
ARM int AppendLineXTag02041cf4(char* dst, int a1, int a2, int a3, int a4) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, data_020eff1b, a1, a2, a3, a4)) - dst;
}
