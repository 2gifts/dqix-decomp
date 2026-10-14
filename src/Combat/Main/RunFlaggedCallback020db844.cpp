#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(int a, int b, int c);

struct Actor020db844 {
    unsigned char pad[0x6c];
    unsigned char f6c;
};

// USA: func_020db844
ARM void RunFlaggedCallback020db844(struct Actor020db844* a, int b, int c, int d) {
    int base = func_ov017_0218b5b0();
    if (base == 0) return;
    a->f6c = 0;
    if (b == 0) SetMainBrightness((GameResources*)base, c, d);
    else _Z16SetSubBrightnessP13GameResourcesii(base, c, d);
    a->f6c = 1;
}
