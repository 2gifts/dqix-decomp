#include <globaldefs.h>

struct Vec3BA28 {
    int x;
    int y;
    int z;
};

// USA: func_0207ba28
ARM void GetVec3ByIndex_0207ba28(struct Vec3BA28* base, int i, int* outX, int* outY, int* outZ) {
    *outX = base[i].x;
    *outY = base[i].y;
    *outZ = base[i].z;
}
