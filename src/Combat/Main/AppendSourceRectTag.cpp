#include <globaldefs.h>

#if defined(jpn)
#define data_020efec0 data_020efec8
#endif

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efec0;

// USA: func_02041bac
ARM int AppendSourceRectTag_02041bac(char* dst, int a, int b, int c, int d, int e) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020efec0, a, b, c, d, e)) - dst;
}
