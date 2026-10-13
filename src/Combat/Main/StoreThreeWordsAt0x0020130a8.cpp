#include <globaldefs.h>
#include "Graphics/Vector.h"

// USA: func_020130a8
ARM void StoreThreeWordsAt0x0020130a8(Vector3i* vector, int x, int y, int z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
