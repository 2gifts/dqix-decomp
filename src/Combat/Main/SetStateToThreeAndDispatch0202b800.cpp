#include <globaldefs.h>

#if defined(jpn)
#define data_020e73b4 data_020e7cf8
#endif

extern "C" int func_0202cd50(int (*cb)(void), void* data, int c);
extern "C" int func_0202ae4c(void);
extern char data_020e73b4;

// USA: func_0202b800
// JPN: func_0202b3b0
ARM int SetStateToThreeAndDispatch0202b800(int* p) {
    *p = 3;
    return func_0202cd50(func_0202ae4c, &data_020e73b4, 0);
}
