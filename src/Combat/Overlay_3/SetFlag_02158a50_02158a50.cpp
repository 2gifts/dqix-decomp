// JPN: func_ov003_02159f3c
// USA: func_ov003_02158a50
#include <globaldefs.h>
#if defined(jpn)
enum { kRegion280 = 0x27c };
enum { kRegion32c = 0x328 };
#else
enum { kRegion280 = 0x280 };
enum { kRegion32c = 0x32c };
#endif

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);
extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);
extern unsigned char data_ov003_0217fe16;

ARM void SetFlag_02158a50_02158a50(unsigned char* obj) {
    _ZN8Object3D24MaybeSetRegularAnimationEPKci(obj + kRegion280, &data_ov003_0217fe16, 9);
    _ZN8Object3D11DisableFlagEi(obj + kRegion280, 0x40000);
    *(int*)(obj + kRegion32c) = 1;
}
