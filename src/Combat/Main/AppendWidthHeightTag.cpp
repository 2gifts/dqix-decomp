#include <globaldefs.h>

#if defined(jpn)
#define data_020efe9f data_020efea7
#endif


int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe9f;

#if defined(jpn)
#define AppendWidthHeightTag func_020421c0
extern "C" ARM int func_020421c0(char* dst, int w, int h);
#endif

// USA: func_02041b34
ARM int AppendWidthHeightTag(char* dst, int w, int h) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020efe9f, w, h)) - dst;
}
