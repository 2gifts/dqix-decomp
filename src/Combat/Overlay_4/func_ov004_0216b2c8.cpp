#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Grid021f9b30;

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid021f9b30* self, unsigned short val, unsigned int x, unsigned int y);

// USA: func_ov004_0216b2c8
extern "C" ARM void func_ov004_0216b2c8(void* ctx, int id, int id2, int val) {
    void* objects = func_ov011_021849c8(ctx);
    void* object = func_ov023_021f6880(objects, id);
    void* object2 = func_ov023_021f6880(objects, id2);
    if (object == NULL || object2 == NULL) {
        return;
    }
    if (func_ov023_021f6f10(object) != 7) {
        return;
    }
    if (!_Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((struct Grid021f9b30*)object, id2, (unsigned short)val, 0)) {
        return;
    }
}
