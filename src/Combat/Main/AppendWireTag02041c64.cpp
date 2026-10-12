#include <globaldefs.h>

#if defined(jpn)
#define data_020efefb data_020eff03
#endif


int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char data_020efefb[];

#if defined(jpn)
#define AppendWireTag02041c64 func_020422f0
extern "C" ARM int func_020422f0(char* dst, int a1, int a2, int a3, int a4, int a5);
#endif

// USA: func_02041c64
ARM int AppendWireTag02041c64(char* dst, int a1, int a2, int a3, int a4, int a5) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, data_020efefb, a1, a2, a3, a4, a5)) - dst;
}
