#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
struct GameResources;
void Stub(GameResources*);
extern "C" void _Z27UpdateBrightnessTransitionsP13GameResources(void*);
extern "C" void _Z15ApplyBrightnessP13GameResources(void*);

struct Struct020db814 {
    char pad[0x28];
    unsigned char field0x28;
};

// USA: func_020db814
ARM void InitFlag0x28FromOverlay(void*) {
    struct Struct020db814* obj = (struct Struct020db814*)func_ov017_0218b5b0();
    if (obj == NULL) {
        return;
    }
    obj->field0x28 = 1;
    Stub((GameResources*)obj);
    _Z27UpdateBrightnessTransitionsP13GameResources(obj);
    _Z15ApplyBrightnessP13GameResources(obj);
}
