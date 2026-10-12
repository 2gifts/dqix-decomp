#include <globaldefs.h>

#if defined(jpn)
#define data_020eff93 data_020eff92
#endif


extern char data_020eff93;
int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

#if defined(jpn)
#define AppendUaTag func_02042564
extern "C" ARM int func_02042564(char* dst, int a, int b, int c);
#endif

// USA: func_02041ed8
ARM int AppendUaTag(char* dst, int a, int b, int c) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020eff93, a, b, c)) - dst;
}
