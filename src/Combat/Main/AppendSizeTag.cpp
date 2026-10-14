#include <globaldefs.h>

#if defined(jpn)
extern "C" int func_02042428(char*, int);
#define AppendSizeTag_02041d9c func_02042428
#endif

extern char data_020eff43;
int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041d9c
ARM int AppendSizeTag_02041d9c(char* dst, int size) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, &data_020eff43, size)) - dst;
}
