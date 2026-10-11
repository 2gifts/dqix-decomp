#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_02012fe4(void* obj);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void _ZN6Zone3D10SwitchZoneEt(void* g, int val, int flag);

// USA: func_ov001_021622a0
ARM int Function_021622a0(void* ctx) {
    void* g = func_02012fe4(ctx);
    int v = func_ov017_021d60f4(ctx);
    _ZN6Zone3D10SwitchZoneEt(g, v, 0);
    return 1;
}
