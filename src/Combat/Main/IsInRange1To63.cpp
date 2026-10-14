#include <globaldefs.h>

// USA: func_02098268
ARM int IsInRange1To63_02098268(int a, int x) {
    if (x >= 1 && x <= 0x3f) {
        return 1;
    }
    return 0;
}
