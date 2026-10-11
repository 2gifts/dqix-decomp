#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
extern "C" void func_ov017_021a2fa0(void* ov);

struct Obj021c16cc {
    unsigned char pad0[0x1];
    unsigned char field1;
    unsigned char pad1[0x6];
    signed char field8;
    unsigned char field9;
};

// JPN: func_ov017_021c1c74
// USA: func_ov017_021c16cc  (semantic: UpdateFieldsAndCounters_021c16cc)
extern "C" ARM void func_ov017_021c16cc(Obj021c16cc* self) {
#if defined(jpn)
 enum {regionalOffset=0x524};
#else
 enum {regionalOffset=0x734};
#endif
    GameResources* ov = func_ov017_0218b5b0();
    int data = (int)BackgroundLoader::GetInstance();
    signed char state = self->field8;
    if (state == 0) {
        _Z13SetBrightnessP13GameResourcesii(ov, -0x10, 0xf);
        self->field8 = self->field8 + 1;
        return;
    }
    if (state != 1) {
        return;
    }
    if (_Z28IsBrightnessTransitionActiveP13GameResources((int*)ov) != 0) {
        return;
    }
    if (((BackgroundLoader*)((void*)data))->GetNumQueuedTasks() > 0) {
        return;
    }
    func_ov017_021a2fa0(ov);
    void* p = *(void**)((char*)ov + 0x3000 + regionalOffset);
    if (((unsigned char*)p)[2] == 0) {
        _Z13SetBrightnessP13GameResourcesii(ov, 0, 0xf);
    }
    if (self->field9 != 0) {
        _Z13SetBrightnessP13GameResourcesii(ov, -0x10, 0);
    }
    self->field1 = 1;
}
