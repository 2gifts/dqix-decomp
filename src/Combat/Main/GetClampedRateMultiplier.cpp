#include <globaldefs.h>

extern float data_020e88f8[][2];

// USA: func_02074738
ARM float GetClampedRateMultiplier_02074738(int row, int col) {
    float v = data_020e88f8[row][col];
    if (v < 1.0f) {
        v = 1.0f;
    }
    return v;
}
