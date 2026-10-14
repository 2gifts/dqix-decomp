#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020efefb[];

// USA: func_02041c64
ARM int AppendWireTag02041c64(char* dst, int a1, int a2, int a3, int a4, int a5) {
    char* end = dst + StringLength_020d2ff0(dst);
    return (end + sprintf(end, data_020efefb, a1, a2, a3, a4, a5)) - dst;
}
