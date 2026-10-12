#include <globaldefs.h>

#if defined(jpn)
#define data_020effbd data_020effbc
#endif


extern char data_020effbd;
int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

#if defined(jpn)
#define AppendDbTag func_020425b0
extern "C" ARM int func_020425b0(char* dst, int a, int b, int c);
#endif

// USA: func_02041f24
ARM int AppendDbTag(char* dst, int a, int b, int c) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020effbd, a, b, c)) - dst;
}
