#include <globaldefs.h>

// USA: func_0209372c
ARM int ClassifyByTenThousands_0209372c(int x) {
    if (x >= 0 && x < 10000) return 0;
    if (x >= 10000 && x < 20000) return 1;
    if (x >= 20000 && x < 30000) return 2;
    return 3;
}
