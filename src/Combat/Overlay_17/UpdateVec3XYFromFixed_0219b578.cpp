#include <globaldefs.h>

struct Vec3Target0203a46c;
void SetVec3At0x1c(struct Vec3Target0203a46c* obj, int x, int y, int z);

// USA: func_ov017_0219b578  (semantic: UpdateVec3XYFromFixed_0219b578)
extern "C" ARM void func_ov017_0219b578(char* self, int argY, int argZ) {
#if defined(jpn)
    struct Vec3Target0203a46c* obj = *(struct Vec3Target0203a46c**)(self + 0x3000 + 0x420);
#else
    struct Vec3Target0203a46c* obj = *(struct Vec3Target0203a46c**)(self + 0x3000 + 0x630);
#endif
    if (obj == 0) {
        return;
    }
    int fieldX = *(int*)((char*)obj + 0x1c);
    int newX = (int)(((float)fieldX / 4096.0f + (float)argY) * 4096.0f);
    int fieldY = *(int*)((char*)obj + 0x20);
    int newY = (int)(((float)fieldY / 4096.0f + (float)argZ) * 4096.0f);
    SetVec3At0x1c(obj, newX, newY, 0);
}
