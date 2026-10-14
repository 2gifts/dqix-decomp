#include <globaldefs.h>

extern char data_020effd7;

extern "C" int sprintf(char* dst, const char* fmt, ...);
ARM int StringLength_020d2ff0(const char* s);

#if defined(jpn)
#define AppendFormatted02041fac func_02042638
extern "C" ARM int func_02042638(char* buf, int a, int b);
#endif

// USA: func_02041fac
ARM int AppendFormatted02041fac(char* buf, int a, int b) {
    char* end = buf + StringLength_020d2ff0(buf);
    return (end + sprintf(end, &data_020effd7, b, a)) - buf;
}
