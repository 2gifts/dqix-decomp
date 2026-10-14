#include <globaldefs.h>

#if defined(jpn)
#define data_020efeb3 data_020efebb
#endif

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efeb3;

// USA: func_02041b70
ARM int AppendNameTag_02041b70(char* dst, int n, const char* name) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020efeb3, n, name)) - dst;
}
