#include <globaldefs.h>

struct Vec3BA28 {
    int x;
    int y;
    int z;
};

#if defined(jpn)
#define GetVec3ByIndex func_0207c860
extern "C" ARM void GetVec3ByIndex(struct Vec3BA28* base, int i, int* outX, int* outY, int* outZ);
#endif

// USA: func_0207ba28
ARM void GetVec3ByIndex(struct Vec3BA28* base, int i, int* outX, int* outY, int* outZ) {
    *outX = base[i].x;
    *outY = base[i].y;
    *outZ = base[i].z;
}
