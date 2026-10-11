#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int _s32_div_f(int num, int den);

// USA: func_0203232c
extern "C" ARM void func_0203232c(int *array, int count) {
    for (int i = 0; i < count / 2; i++) {
        int j = rand() % count;
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}
