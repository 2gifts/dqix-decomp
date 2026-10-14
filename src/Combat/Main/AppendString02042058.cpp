#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* src);

// USA: func_02042058
ARM int AppendString02042058(char* dst, const char* src) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, src)) - dst;
}
