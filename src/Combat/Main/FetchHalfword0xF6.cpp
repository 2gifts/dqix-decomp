#include <globaldefs.h>
int RunHandlerWithFallbackDispatch020ce56c(int, int, int);

#pragma optimize_for_size off
// USA: func_020cee18
ARM int FetchHalfword0xF6_020cee18(int* out) {
    unsigned short v;
    int result = RunHandlerWithFallbackDispatch020ce56c((int)(0xf), (int)(6), (int)(&v));
    if (result != 0) {
        return result;
    }
    if (out != NULL) {
        *out = v;
    }
    return result;
}
