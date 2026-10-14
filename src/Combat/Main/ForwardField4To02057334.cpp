#include <globaldefs.h>

extern "C" int func_02057334(int);

// USA: func_02055774
ARM int ForwardField4To02057334_02055774(int* obj) {
    int x = obj[1];
    if (x == 0) return x;
    return func_02057334(x);
}
