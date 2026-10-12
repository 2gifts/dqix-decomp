#include <globaldefs.h>

struct Vec3038500 {
    int x;
    int y;
    int z;
};

#if defined(jpn)
#define SetVec3038500 func_02037f58
extern "C" ARM void func_02037f58(struct Vec3038500* obj, int x, int y, int z);
#endif

// USA: func_02038500
ARM void SetVec3038500(struct Vec3038500* obj, int x, int y, int z) {
    obj->x = x;
    obj->y = y;
    obj->z = z;
}
