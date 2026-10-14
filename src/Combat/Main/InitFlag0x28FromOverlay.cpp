#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
struct GameResources;
void Stub(GameResources*);
void UpdateBrightnessTransitions(GameResources*);
void ApplyBrightness(GameResources*);

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
    UpdateBrightnessTransitions((GameResources*)obj);
    ApplyBrightness((GameResources*)obj);
}
