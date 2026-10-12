#include <globaldefs.h>

extern "C" int func_0208a370(int, int, int, int, int);

#if defined(jpn)
#define Forward0208a370Arg3 func_0208ae00
extern "C" ARM int Forward0208a370Arg3(int a, int b, int c, int d);
#endif

// USA: func_0208a50c
ARM int Forward0208a370Arg3(int a, int b, int c, int d) {
    return func_0208a370(a, 3, b, c, d);
}
