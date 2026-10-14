#include <globaldefs.h>

extern char data_020effbd;
int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041f24
ARM int AppendDbTag_02041f24(char* dst, int a, int b, int c) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020effbd, a, b, c)) - dst;
}
