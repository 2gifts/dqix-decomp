#if defined(jpn)
#define R(j,u) (j)
#define _Z27ConfigureSubsystem_021889f8P11Obj021889f8 func_ov008_0218973c
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_ov017_021959b4(void);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
extern "C" void func_ov011_021848a8(void* obj);
struct Node02184a84;
void DispatchByFlagAOrB_02184a84(struct Node02184a84* obj);
extern "C" void func_ov011_02184ae4(void* obj);
extern "C" void func_ov023_021f68dc(void* list, void* obj);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);
extern "C" void func_ov011_02184770(void* obj);

struct Obj02184694 {
    char pad[0x1cc];
    unsigned char flag_1cc;
    unsigned char flag_1cd;
};

// USA: func_ov011_02184694  (semantic: InitOrRefreshNodeState_02184694)
extern "C" ARM int func_ov011_02184694(Obj02184694* obj) {
    int ctx = func_ov017_0218b5b0();
    func_0202ae18();
    if (obj->flag_1cd == 0) {
        int flag = func_ov017_021959b4();
        if (flag) {
            obj->flag_1cd = 1;
            if (ctx) {
                _Z13SetBrightnessP13GameResourcesii((void*)ctx, -16, 10);
            }
        }
        func_ov011_021848a8(obj);
        DispatchByFlagAOrB_02184a84((struct Node02184a84*)obj);
        func_ov011_02184ae4(obj);
        func_ov023_021f68dc((char*)obj + 0x118, obj);
    } else if (ctx != 0 && !_Z28IsBrightnessTransitionActiveP13GameResources((int*)ctx)) {
        func_ov011_02184770(obj);
        obj->flag_1cc = 1;
    }
    return obj->flag_1cc == 0;
}
