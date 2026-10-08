#include <globaldefs.h>
#include "Combat/FormationPosition.h"

// USA: func_ov000_0216f74c  (semantic: ComputeFormationPosition_0216f74c)
extern "C" ARM struct Vec2_0216f74c func_ov000_0216f74c(int* in) {
    int a = *in;
    int q = a / 9;
    int rem = a % 9;
    float t = -42566.87890625f + 10641.7197265625f * (float)rem;
    struct Vec2_0216f74c result;
    result.x = (int)(t + 5320.85986328125f * (float)(q % 2));
    result.y = (int)(-36864.0f + 3.0f * (3072.0f * (float)q));
    return result;
}
