#if defined(jpn)
enum {regionalOffset0=0x124, regionalOffset1=0x12c, regionalOffset2=0x4e0};
#else
enum {regionalOffset0=0x128, regionalOffset1=0x130, regionalOffset2=0x4e4};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);

extern "C" void func_ov023_021e5020(void* p);
extern "C" void func_ov023_021e4c18(void* obj);
extern "C" void func_ov023_021e463c(void* obj, int scaleCount);
extern "C" void func_ov023_021e447c(void* obj);
extern "C" void func_ov023_021e456c(void* obj);
extern "C" void func_ov023_021e3e98(void* obj);
extern "C" void func_ov005_02154de8(void* arg);

struct Obj021e3db0 {
    void* field0;
    char pad4[regionalOffset0 - 0x4];
    void* field128;
    void* field12c;
    char pad130[regionalOffset2 - regionalOffset1];
    unsigned char field4e4;
};

// JPN: func_ov023_021e400c
// USA: func_ov023_021e3db0
extern "C" ARM void func_ov023_021e3db0(struct Obj021e3db0* obj) {
    int val = GetWord0x0((int*)GameState::GetInstance());

    if (obj->field128 != 0) {
        func_ov023_021e5020(obj->field128);
    }
    if (obj->field12c != 0) {
        func_ov023_021e5020(obj->field12c);
    }

    if (obj->field4e4 == 0) {
        if (obj->field128 != 0 && *((unsigned char*)obj->field128 + 0xc12) != 0) {
            return;
        }
        _Z13SetBrightnessP13GameResourcesii((void*)val, 0, 15);
        obj->field4e4++;
    } else if (obj->field4e4 == 1) {
        if (!_Z28IsBrightnessTransitionActiveP13GameResources((int*)val)) {
            obj->field4e4++;
        }
    } else if (obj->field4e4 == 2) {
        func_ov023_021e4c18(obj);
        int scaleCount = GameState::GetInstance()->GetTickCount();
        func_ov023_021e463c(obj, scaleCount);
        func_ov023_021e447c(obj);
        func_ov023_021e456c(obj);
        func_ov023_021e3e98(obj);
    }

    if (obj->field0 == 0) {
        return;
    }
    func_ov005_02154de8(obj->field0);
}
