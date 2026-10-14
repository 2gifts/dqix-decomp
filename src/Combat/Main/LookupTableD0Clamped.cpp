#include <globaldefs.h>

extern float data_020e88d0[];

// USA: func_02074948
ARM float LookupTableD0Clamped_02074948(int i) {
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return data_020e88d0[i];
}
