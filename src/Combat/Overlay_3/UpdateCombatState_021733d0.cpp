#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValueEE_EA = 0xea };
enum { kRegionValueCC_CA = 0xca };
enum { kRegionValue840_860 = 0x860 };
enum { kRegionValueD5_D1 = 0xd1 };
enum { kRegionValueD0_CC = 0xcc };
enum { kRegionValue460_35C = 0x35c };
enum { kRegionValueEC_E8 = 0xe8 };
#else
enum { kRegionValueEE_EA = 0xee };
enum { kRegionValueCC_CA = 0xcc };
enum { kRegionValue840_860 = 0x840 };
enum { kRegionValueD5_D1 = 0xd5 };
enum { kRegionValueD0_CC = 0xd0 };
enum { kRegionValue460_35C = 0x460 };
enum { kRegionValueEC_E8 = 0xec };
#endif


extern "C" void* func_ov017_0218b5b0(unsigned char* self);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void* p, int a, int b);
extern "C" int func_02012fe4(void);
extern "C" void func_02098630(void* obj, void* addr, int a, int b);

extern "C" int _Z32IsMainBrightnessTransitionActiveP13GameResources(int* p);
void ResetFieldsB68AndB74_0216fb6c(char* obj);

// USA: func_ov003_021733d0  (semantic: UpdateCombatState_021733d0)
// JPN: func_ov003_02172218
extern "C" ARM void func_ov003_021733d0(unsigned char* self) {
    int* p = (int*)func_ov017_0218b5b0(self);
    if (self[kRegionValueEE_EA] == 0) {
        _Z17SetMainBrightnessP13GameResourcesii(p, -16, 24);
        self[kRegionValueEE_EA] = 1;
        return;
    }
    if (self[kRegionValueEE_EA] != 1) {
        return;
    }
    if (_Z32IsMainBrightnessTransitionActiveP13GameResources(p) != 0) {
        return;
    }
    int r4 = func_02012fe4();
    if (self[kRegionValueCC_CA] == 0) {
        ResetFieldsB68AndB74_0216fb6c((char*)r4 + kRegionValue840_860);
        for (int i = 0; i < self[kRegionValueD5_D1]; i++) {
            void* addr = (char*)*(int*)(self + kRegionValueD0_CC) + kRegionValue460_35C + (unsigned char)i * 0xe8;
            func_02098630((char*)r4 + kRegionValue840_860, addr, 1, 0);
        }
        ResetFieldsB68AndB74_0216fb6c((char*)r4 + kRegionValue840_860);
    }
    self[kRegionValueEC_E8] = 6;
    self[kRegionValueEE_EA] = 0;
}
