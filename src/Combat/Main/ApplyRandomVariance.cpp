#include <globaldefs.h>
#include "Util/Random.h"

// USA: func_02074838
ARM float ApplyRandomVariance_02074838(int value, int narrow, struct Random* random) {
    if (random == NULL) {
        random = &data_02108ddc;
    }
    if (narrow != 0) {
        return (float)value * NextRandomFloatBetween(random, 0.95f, 1.05f);
    }
    return (float)value * NextRandomFloatBetween(random, 1.5f, 2.0f);
}
